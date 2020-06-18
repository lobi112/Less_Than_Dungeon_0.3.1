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

	~MyWeapon(){}
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
	~MyArmor() {}
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
	~MyShield() {}
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
				cout << "�������� :\t\t" << "��� :\t\t" << "����� : \t" << "���� :\t" << "�������� :\t" << "��������� :\t" << "���� :" << endl << endl;
				cout << weapon_name << "\t\t";
				(item_type == 1) ? cout << "����������\t" : cout << "���������\t";
				switch (weapon_style)
				{
				case 0: cout << "������� \t"; break;
				case 1: cout << "������� \t"; break;
				case 2: cout << "������ \t"; break;
				}
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
	int damage;
	int damage_dif;
	int chest_unlock;


	int position_x, position_y;
	int weapon_hold_type = 1;

	int heal_potion_s = 0;
	int heal_potion_l = 0;
	int gold = 0;
	int picklock = 0;

	int inventory_size = 10;
	vector<MyItem> item = vector<MyItem>(inventory_size);
	//MyItem *item = new MyItem[inventory_size];

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
				max_HP = 50;
				chest_unlock = 40;
				base_armor = 0;
				base_shield = 1;               
				base_dodge = 30;
				base_speed = 80;
				base_damage = 4;
				base_damage_dif = 2;
				break;
			}

			case 2:
			{
				class_name = "����"; 
				HP = 35;
				max_HP = 60;
				chest_unlock = 25;
				base_armor = 1;
				base_shield = 2;
				base_dodge = 20;
				base_speed = 80;
				base_damage = 6;
				base_damage_dif = 2;
				break;
			}

			case 3:
			{
				class_name = "�������";
				HP = 45;
				max_HP = 70;
				chest_unlock = 10;
				base_armor = 0;
				base_shield = 2;
				base_dodge = 0;
				base_speed = 80;
				base_damage = 8;
				base_damage_dif = 2;
				break;
			}

			case 4:
			{
				class_name = "���";
				HP = 20;
				max_HP = 40;
				chest_unlock = 60;
				base_armor = 0;
				base_shield = 1;
				base_dodge = 35;
				base_speed = 90;
				base_damage = 4;
				base_damage_dif = 2;
				picklock = 10;
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
				base_damage = 5;
				base_damage_dif = 2;
			break;
			}
		}
	}

	void take_damage(int damage, bool block)
	{
		switch (block)
		{
			case 0:
			{
				(damage - armor < 0) ? damage = 0 : damage -= armor;
				break;
			}
			case 1:
			{	cout << "�� ���������� �����." << endl;
				_getch();
				(damage - armor - block < 0) ? damage = 0 : damage -= (armor + block);
				break;
			}
		}
		cout << "��������� ���� ��� " << damage;
		switch (damage)
		{
			case 1: cout << " ����." << endl; break;
			default: cout << " �����." << endl; break;
		}
		_getch();
		(HP - damage < 0) ? HP = 0 : HP -= damage;
	}

	~MyHero()
	{
		//delete[] item;
	}

};

class MyEnemy
{
public:

	int type;
	string name;

	int HP;
	int max_HP;
	int armor;
	int shield;
	int dodge; //���� �������
	int speed; //���� ��������� (������� �����), ������ ����� ����� ���� �����, ������� ����������� �����;
	int damage;
	int damage_dif;
	int attack_tactic;
	int defense_tactic;
	
	bool pay_off_possibility;
	int  pay_off_chance;
	int  pay_off_cost;
	

	bool run_away_possibility;
	int  run_away_chance;
	
	MyEnemy(int enemy_type, int enemy_ind)
	{
		type = enemy_type;
		switch (enemy_type)
		{
			case 0:
			{
				switch (enemy_ind)
				{
					case 0:
					{
						name = "�������� ��";
						HP = max_HP = 6 + rand() % 5;
						armor = 0;
						shield = 1;
						dodge = 25;
						speed = 80;
						damage = 3;
						damage_dif = 1;
						attack_tactic = 0;
						defense_tactic = 0;

						pay_off_possibility = false;

						run_away_possibility = true;
						run_away_chance = 50;
						break;
					}
					case 1:
					{
						name = "�����";
						HP = max_HP = 20 + rand() % 6;
						armor = 0;
						shield = 3;
						dodge = 20;
						speed = 60;
						damage = 5;
						damage_dif = 2;
						attack_tactic = 2;
						defense_tactic = 0;

						pay_off_possibility = false;

						run_away_possibility = true;
						run_away_chance = 50;
						break;
					}
					case 2:
					{
						name = "����";
						HP = max_HP = 15+ rand()%6;
						armor = 0;
						shield = 2;
						dodge = 60;
						speed = 90;
						damage = 6;
						damage_dif = 2;
						attack_tactic = 1;
						defense_tactic = 1;

						pay_off_possibility = false;

						run_away_possibility = false;
						break;
					}
					case 3:
					{
						name = "�������";
						HP = max_HP = 35 + rand() % 11;
						armor = 0;
						shield = 2;
						dodge = 20;
						speed = 80;
						damage = 10;
						damage_dif = 3;
						attack_tactic = 2;
						defense_tactic = 2;

						pay_off_possibility = false;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
				}
			}
			case 1:
			{
				switch (enemy_ind)
				{
					case 0:
					{
						name = "������";
						HP = max_HP = 15 + rand() % 6;
						damage = 5;
						damage_dif = 1;
						speed = 90;
						dodge = 30;
						armor = 0;
						shield = 1;
						
						attack_tactic = 1;
						defense_tactic = 1;

						pay_off_possibility = true;
						pay_off_chance = 40;
						pay_off_cost = 10 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
					case 1:
					{
						name = "������ ����";
						HP = max_HP = 15 + rand() % 6;
						damage = 7 + rand() % 3;
						damage_dif = 1 + rand() % 2;
						speed = 80;
						dodge = 20;
						armor = 2 +rand() % 2;
						shield = 2 + rand() % 2;

						attack_tactic = 1;
						defense_tactic = 1;

						pay_off_possibility = true;
						pay_off_chance = 40;
						pay_off_cost = 10 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
					case 2:
					{
						name = "������ ������";
						HP = max_HP = 15 + rand() % 6;
						damage = 7 + rand() % 3;
						damage_dif = 1;
						speed = 90;
						dodge = 35;
						armor = 1;
						shield = 1;

						attack_tactic = 1;
						defense_tactic = 1;

						pay_off_possibility = true;
						pay_off_chance = 40;
						pay_off_cost = 10 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
					case 3:
					{
						name = "������ ���������";
						HP = max_HP = 15 + rand() % 6;
						damage = 5 + rand() % 2;
						damage_dif = 1;
						speed = 90;
						dodge = 35;
						armor = 1;
						shield = 1;

						attack_tactic = 1;
						defense_tactic = 1;

						pay_off_possibility = true;
						pay_off_chance = 40;
						pay_off_cost = 10 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
				}
				break;
			}
			case 2:
			{
				switch (enemy_ind)
				{
					case 0:
					{
						name = "���";
						HP = max_HP = 35 + rand() % 6;
						damage = 8;
						damage_dif = 2;
						speed = 70;
						dodge = 20;
						armor = 1;
						shield = 3;

						attack_tactic = 2;
						defense_tactic = 0;

						pay_off_possibility = true;
						pay_off_chance = 30;
						pay_off_cost = 15 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 30;
						break;
					}
					case 1:
					{
						name = "��� �������";
						HP = max_HP = 35 + rand() % 6;
						damage = 9 + rand()%3;
						damage_dif = 2;
						speed = 90;
						dodge = 30;
						armor = 2;
						shield = 2;

						attack_tactic = 1;
						defense_tactic = 0;

						pay_off_possibility = true;
						pay_off_chance = 40;
						pay_off_cost = 10 + rand() % 21;

						run_away_possibility = true;
						run_away_chance = 30;
						break;
					}
					case 2:
					{
						name = "��� �������";
						HP = max_HP = 35 + rand() % 6;
						damage = 11+rand()%4;
						damage_dif = 3;
						speed = 80;
						dodge = 0;
						armor = 0;
						shield = 4;

						attack_tactic = 3;
						defense_tactic = 3;

						pay_off_possibility = false;

						run_away_possibility = true;
						run_away_chance = 20;
						break;
					}
					case 3:
					{
						name = "��� ����";
						HP = max_HP = 40 + rand() % 6;
						damage = 8 + rand() % 3;
						damage_dif = 2;
						speed = 70;
						dodge = 20;
						armor = 3+rand()%3;
						shield = 4+rand()%3;

						attack_tactic = 2;
						defense_tactic = 3;

						pay_off_possibility = true;
						pay_off_chance = 20;
						pay_off_cost = 25 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
				}
				break;
			}
			case 3:
			{
				switch (enemy_ind)
				{
					case 0:
					{
						name = "���������";
						HP = max_HP = 25 + rand() % 6;
						damage = 5;
						damage_dif = 1;
						speed = 90;
						dodge = 30;
						armor = rand() % 2;
						shield = 2;

						attack_tactic = 1;
						defense_tactic = 0;

						pay_off_possibility = true;
						pay_off_chance = 100;
						pay_off_cost = 20 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 30;
						break;
					}
					case 1:
					{
						name = "������";
						HP = max_HP = 35 + rand() % 6;
						damage = 5 + rand() % 3;
						damage_dif = 1;
						speed = 80;
						dodge = 30;
						armor = rand() % 2;
						shield = 2;

						attack_tactic = 1;
						defense_tactic = 3;

						pay_off_possibility = true;
						pay_off_chance = 100;
						pay_off_cost = 30 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 35;
						break;
					}
					case 2:
					{
						name = "������-��������";
						HP = max_HP = 40 + rand() % 6;
						damage = 7+rand() % 3;
						damage_dif = 2;
						speed = 70;
						dodge = 25;
						armor = 3 + rand() % 3;
						shield = 4 + rand() % 4;

						attack_tactic = 2;
						defense_tactic = 3;

						pay_off_possibility = true;
						pay_off_chance = 100;
						pay_off_cost = 30 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 40;
						break;
					}
					case 3:
					{
						name = "������ ������";
						HP = max_HP = 35 + rand() % 6;
						damage = 7 + rand() % 3;
						damage_dif = 1;
						speed = 90;
						dodge = 35;
						armor = 1 + rand() % 3;
						shield = 2 + rand() % 2;

						attack_tactic = 1;
						defense_tactic = 3;

						pay_off_possibility = true;
						pay_off_chance = 0;
						pay_off_cost = 5 + rand() % 11;

						run_away_possibility = true;
						run_away_chance = 20;
						break;
					}
					case 4:
					{
						name = "������ ���������";
						HP = max_HP = 30 + rand() % 6;
						damage = 9 + rand() % 3;
						damage_dif = 2;
						speed = 90;
						dodge = 35;
						armor = 0;
						shield = 4 + rand() % 4;

						attack_tactic = 3;
						defense_tactic = 3;

						pay_off_possibility = false;

						run_away_possibility = true;
						run_away_chance = 20;
						break;
					}
				}
				break;
			}
			case 4: break;
		}
	}


	void take_damage(int damage, bool block)
	{
		switch (block)
		{
			case 0:
			{
				(damage - armor < 0) ? damage = 0 : damage -= armor;
				break;
			}
			case 1: 
			{
				cout << "��������� ��������� �����." << endl;
				_getch();
				(damage - armor - block < 0) ? damage = 0 : damage -= (armor + block);
				break;
			}
		}
		cout << "�� ������� " << damage;
		switch (damage)
		{
			case 1: cout << " ����." << endl; break;
			default: cout << " �����." << endl; break;
		}
		_getch();
		(HP - damage < 0) ? HP = 0 : HP -= damage;
	}
};

struct Leaderboard {
	string name;
	int score;
};