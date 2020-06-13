#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <list>
#include <msxml.h>
using namespace std;


class MyWeapon
{
public:
	string weapon_name;
	int weapon_type; // 1 - ����������, 2 - ���������
	int weapon_style; // 0 - �������, 1 - �������, 2 - ������
	int weapon_damage;
	int weapon_damage_dif;
	int weapon_dodge;  //��������� ����� ����������
	int weapon_speed;  //��������� ����� ��������� �����
	int weapon_cost;

	MyWeapon(string name = "�����", int type = 0, int style = 0, int damage = 0, int damage_dif = 0, int dodge = 0, int speed = 0, int cost = 0)
	{
		weapon_type = type;
		weapon_style = style;
		weapon_name = name;
		weapon_damage = damage;
		weapon_damage_dif = damage_dif;
		weapon_dodge = dodge;
		weapon_speed = speed;
		weapon_cost = cost;
	}
};

class MyArmor
{
public:
	string armor_name;
	int armor_block;
	int armor_dodge;
	int armor_speed;
	int armor_cost;

	MyArmor(string name = "��������", int block = 0, int dodge = 0, int speed = 0, int cost = 0)
	{
		armor_name = name;
		armor_block = block;
		armor_dodge = dodge;
		armor_speed = speed;
		armor_cost = cost;
	}
};

class MyShield
{
public:
	string shield_name;
	int shield_block;
	int shield_dodge;
	int shield_speed;
	int shield_cost;

	MyShield(string name = "�����������", int block = 0, int dodge = 0, int speed = 0, int cost = 0)
	{
		shield_name = name;
		shield_block = block;
		shield_dodge = dodge;
		shield_speed = speed;
		shield_cost = cost;
	}
};


class MyItem :public MyWeapon, public MyArmor, public MyShield
{
public:
	string item_name;
	bool in_use;
	int item_type;
	int inventory_position;
	MyItem()
	{
		item_type = 0;
		in_use = 0;
	}

	void clear_item()
	{
		item_type = inventory_position = in_use = 0;
		weapon_name = "�����";
		weapon_damage = weapon_damage_dif = weapon_dodge = weapon_speed = weapon_cost = weapon_style = 0;
		armor_name = "��������";
		armor_block = armor_dodge = armor_speed = armor_cost = 0;
		shield_name = "�����������";
		shield_block = shield_dodge = shield_speed = shield_cost = 0;
	}

	void create_item(MyWeapon &weapon)
	{
		item_type = weapon.weapon_type; // 1 - ����������, 2 - ���������
		weapon_style = weapon.weapon_style;
		weapon_name = weapon.weapon_name;
		weapon_damage = weapon.weapon_damage;
		weapon_damage_dif = weapon.weapon_damage_dif;
		weapon_dodge = weapon.weapon_dodge;
		weapon_speed = weapon.weapon_speed;
		weapon_cost = weapon.weapon_cost;
	}

	void create_item(MyShield &shield)
	{
		item_type = 3;
		shield_name = shield.shield_name;
		shield_block = shield.shield_block;
		shield_dodge = shield.shield_dodge;
		shield_speed = shield.shield_speed;
		shield_cost = shield.shield_cost;
	}

	void create_item(MyArmor &armor)
	{
		item_type = 4;
		armor_name = armor.armor_name;
		armor_block = armor.armor_block;
		armor_dodge = armor.armor_dodge;
		armor_speed = armor.armor_speed;
		armor_cost = armor.armor_cost;
	}

	void item_info()
	{
		switch (item_type)
		{
			case 1:
			case 2:
			{
				cout << "�������� :\t" << "��� :\t\t" << "���� :\t" << "�������� :\t" << "��������� :\t" << "���� :" << endl << endl;
				cout << weapon_name << "\t";
				(item_type == 1) ? cout << "����������\t" : cout << "���������\t";
				cout << (weapon_damage - weapon_damage_dif) << "-" << (weapon_damage + weapon_damage_dif) << "\t";
				if (weapon_speed > 0)
				{
					cout << "+";
				}
				cout << weapon_speed << "\t\t";
				if (weapon_dodge > 0)
				{
					cout << "+";
				}
				cout << weapon_dodge << "\t\t";
				cout << weapon_cost << "\t" << endl << endl;
				break;
			}
			case 3:
			{
				cout << "�������� :\t\t" << "������ :\t" << "�������� :\t" << "��������� :\t" << "���� :\t" << endl << endl;
				cout << shield_name << "\t";
				cout << shield_block << "\t\t";
				if (shield_speed >= 0)
				{
					cout << "+";
				}
				cout << shield_speed << "\t\t";
				if (shield_dodge >= 0)
				{
					cout << "+";
				}
				cout << shield_dodge << "\t\t";
				cout << shield_cost << "\t" << endl << endl;
				break;
			}
			case 4:
			{
				cout << "�������� :\t\t" << "������ :\t" << "�������� :\t" << "��������� :\t" << "���� :\t" << endl << endl;
				cout << armor_name << "\t";
				cout << armor_block << "\t\t";
				if (armor_speed >= 0)
				{
					cout << "+";
				}
				cout << armor_speed << "\t\t";
				if (armor_dodge >= 0)
				{
					cout << "+";
				}
				cout << armor_dodge << "\t\t";
				cout << armor_cost << "\t" << endl << endl;
				break;
			}
		}
	}
};


class MyHero: public  MyItem
{
 public:
	string name;			//��� �����
	string class_name;		//������������ ������

	int HP;					//������� ��������
	int Level;				//������� ������� 
	int EXP;				//������� ����
	int next_lvl_exp;  


	//������� ��������
	int max_HP;             //������������ ��������
	int base_armor;         //�������� ������
	int base_shield;        //�������� ���������� ������ ���� 
	int base_dodge;         //�������� ����� ���������
	int base_speed;         //�������� ����� ���������
	int base_magic;         //������� ���������� ����
	int base_damage;        //�������� �����
	int base_damage_dif;    //������� �����
	int base_chest_unlock;  //���� �������� �����

	//������� �������� 
	int armor;
	int shield;
	int dodge;
	int speed;
	int magic;
	int damage;
	int damage_dif;
	int chest_unlock;


	int position_x, position_y;
	int weapon_hold_type = 1;

	int potion = 0;
	int gold = 0;
	int picklock = 0;

	int inventory_size = 10;
	//vector<MyItem> item = vector<MyItem>(4);
	MyItem *item = new MyItem[inventory_size];

	MyItem current_item_right_hand;
	MyItem current_item_left_hand;
	MyItem current_item_two_handed;
	MyItem current_armor;


	MyHero(string p_name, int P_X, int P_Y)
	{
		//vector<MyItem> item(4);
		//item.reserve(10);
		name = p_name;
		position_x = P_X;
		position_y = P_Y;

		EXP = 0;
		next_lvl_exp = 100;

		for (int i = 0; i < inventory_size; i++)
		{
			item[i].inventory_position = i;
		}
	}

	int item_amount()
	{
		int item_amount = 0;
		for (int i = 0; i < inventory_size; i++)
		{
			if (item[i].item_type > 0)
			{
				item_amount++;
			}
		}
		return item_amount;
	}

	void take_of_item(int position)
	{
		switch (position)
		{
		case 1:
		{
			current_item_right_hand.clear_item();
			break;
		}
		case 2: 
		{
			current_item_left_hand.clear_item();
			break;
		}
		case 3:
		{
			current_item_two_handed.clear_item();
			break;
		}
		case 4:
		{
			current_armor.clear_item();
			break;
		}
		}
	}


	void refresh() //���������� ����������
	{
		armor  = base_armor + current_armor.armor_block;
		shield = base_shield + current_item_left_hand.shield_block;
		dodge  = base_dodge  + current_armor.armor_dodge + current_item_left_hand.weapon_dodge + current_item_left_hand.shield_dodge + current_item_right_hand.weapon_dodge + current_item_two_handed.weapon_dodge;
		speed =  base_speed  + current_armor.armor_speed + current_item_left_hand.weapon_speed + current_item_left_hand.shield_speed + current_item_right_hand.weapon_speed + current_item_two_handed.weapon_speed;
		damage = base_damage + current_item_left_hand.weapon_damage + current_item_right_hand.weapon_damage + current_item_two_handed.weapon_damage;
		damage_dif = current_item_left_hand.weapon_damage_dif + current_item_right_hand.weapon_damage_dif + current_item_two_handed.weapon_damage_dif;
		if (current_item_left_hand.weapon_type + current_item_right_hand.weapon_type + current_item_two_handed.weapon_type == 0)
		{
			damage_dif = base_damage_dif;
		}
		chest_unlock = base_chest_unlock;
	}

	void Class_choice(int choice)
	{
		switch (choice)
		{
			case 1:
			{
				class_name = "��������";
				HP = 25;
				max_HP = 100;
				chest_unlock = 30;
				base_armor = 0;
				base_shield = 1;               
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 5;
				base_damage_dif = 2;
				break;
			}

			case 2:
			{
				class_name = "����"; 
				HP = 40;
				max_HP = 120;
				chest_unlock = 20;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 3;
				base_damage_dif = 2;
				break;
			}

			case 3:
			{
				class_name = "�������";
				HP = 60;
				max_HP = 150;
				chest_unlock = 10;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 5;
				base_damage_dif = 2;
				break;
			}

			case 4:
			{
				class_name = "���";
				HP = 20;
				max_HP = 80;
				chest_unlock = 50;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 5;
				base_damage_dif = 2;
			break;
			}

			case 5:
			{
				class_name = "��������";
				HP = 25;
				max_HP = 100;
				chest_unlock = 15;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 5;
				base_damage_dif = 2;
			break;
			}

			case 6:
			{
				class_name = "�����";
				HP = 20;
				max_HP = 70;
				chest_unlock = 20;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 30;
				base_speed = 80;
				base_magic = 2;
				base_damage = 5;
				base_damage_dif = 2;
			break;
			}
		}
	}

	~MyHero()
	{
		delete[] item;
	}

};

class MyEnemy
{
public:

	int type;
	string name;

	int HP;
	int armor;
	int shield;
	int dodge; //���� �������
	int block; //���� �����
	int speed; //���� ��������� (������� �����), ������ ����� ����� ���� �����, ������� ����������� �����;
	int damage;
	int damage_dif;
	int attack_tactic;
	int defense_tactic;

	int pay_off_cost;

	bool run_away_possibility;
	bool pay_off_possibility;
	MyEnemy(int enemy_type, int enemy_ind)
	{
		switch (enemy_type)
		{
			case 0:
			{
				switch (enemy_ind)
				{
					case 0:
					{
						name = "����";
						HP = 15+ rand()%6;
						armor = 0;
						shield = 2;
						dodge = 40;
						speed = 90;
						damage = 6;
						damage_dif = 2;
						attack_tactic = 1;
						defense_tactic = 1;
					}
					case 1:
					{
						name = "����";
						HP = 30 + rand() % 6;
						armor = 0;
						shield = 2;
						dodge = 20;
						speed = 80;
						damage = 10;
						damage_dif = 3;
						attack_tactic = 2;
						defense_tactic = 2;
					}
				}
			}
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
		}
	}


	void take_damage(int damage, bool block)
	{
		(damage - armor < 0) ? damage = 0 : damage -= armor;
		switch (block)
		{
			case 0:
			{
				(damage - armor < 0) ? damage = 0 : damage -= armor;
			}
			case 1: 
			{
				(damage - armor - block < 0) ? damage = 0 : damage -= (armor + block);
			}
		}
		cout << "�� ������� " << damage << " �����." << endl;
		(HP - damage < 0) ? HP = 0 : HP -= armor;
	}
};

class Enemy_Basic
{

};

struct Leaderboard {
	string name;
	int score;
};