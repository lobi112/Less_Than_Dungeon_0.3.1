#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;


class MyWeapon
{
public:
	string weapon_name;
	int weapon_type; // 1 - ����������, 2 - ���������
	int weapon_damage;
	int weapon_damage_dif;
	int weapon_dodge;  //��������� ����� ����������
	int weapon_spead;  //��������� ����� ��������� �����
	int weapon_cost;

	/*MyWeapon()
	{
		weapon_name = "�����";
		weapon_damage = weapon_damage_dif = weapon_dodge = weapon_spead = weapon_cost = 0;
	}*/

	MyWeapon(string name = "�����", int type = 0, int damage = 0, int damage_dif = 0, int dodge = 0, int spead = 0, int cost = 0)
	{
		weapon_type = type;
		weapon_name = name;
		weapon_damage = damage;
		weapon_damage_dif = damage_dif;
		weapon_dodge = dodge;
		weapon_spead = spead;
		weapon_cost = cost;
	}

};

class MyArmor
{
public:
	string armor_name;
	int armor_block;
	int armor_dodge;
	int armor_cost;

	MyArmor()
	{
		armor_name = "��������";
		armor_block = armor_dodge = armor_cost  = 0;
	}
	MyArmor(string name, int block, int dodge, int cost)
	{
		armor_name = name;
		armor_block = block;
		armor_dodge = dodge;
		armor_cost = cost;
	}
};

class MyShield
{
public:
	string shield_name;
	int shield_block;
	int shield_dodge;
	int shield_cost;

	MyShield()
	{
		shield_name = "�����������";
		shield_block = shield_dodge = shield_cost = 0;
	}

	MyShield(string name, int block, int dodge, int cost)
	{
		shield_name = name;
		shield_block = block;
		shield_dodge = dodge;
		shield_cost = cost;
	}
};


class MyItem :public MyWeapon, public MyArmor, public MyShield
{
public:
	string item_name;
	bool in_use;
	int item_type;
	MyItem()
	{
		in_use = 0;
	}

	void clear_item()
	{
		weapon_name = "�����";
		weapon_damage = weapon_damage_dif = weapon_dodge = weapon_spead = weapon_cost = 0;
		armor_name = "��������";
		armor_block = armor_dodge = armor_cost = 0;
		shield_name = "�����������";
		shield_block = shield_dodge = shield_cost = 0;
	}

	void create_item(MyWeapon &weapon)
	{
		item_type = weapon.weapon_type;
		weapon_name = weapon.weapon_name;
		weapon_damage = weapon.weapon_damage;
		weapon_damage_dif = weapon.weapon_damage_dif;
		weapon_dodge = weapon.weapon_dodge;
		weapon_spead = weapon.weapon_spead;
		weapon_cost = weapon.weapon_cost;
	}

	void create_item(MyShield &shield)
	{
		item_type = 3;
		shield_name = shield.shield_name;
		shield_block = shield.shield_block;
		shield_dodge = shield.shield_dodge;
		shield_cost = shield.shield_cost;
	}

	void create_item(MyArmor &armor)
	{
		item_type = 4;
		armor_name = armor.armor_name;
		armor_block = armor.armor_block;
		armor_dodge = armor.armor_dodge;
		armor_cost = armor.armor_cost;
	}
};


class MyHero: public  MyItem
{
 public:
	string name;       //��� �����
	string class_name; //������������ ������

	int HP;            //������� ��������
	int Level;         //������� ������� 
	int EXP;           //������� ����
	int next_lvl_exp;  


	//������� ��������
	int max_HP;             //������������ ��������
	int base_armor;         //�������� ������
	int base_shield;        //�������� ���������� ������ ���� 
	int base_dodge;         //�������� ����� ���������
	int base_spead;         //�������� ����� ���������
	int base_magic;         //������� ���������� ����
	int base_damage;        //�������� �����
	int base_damage_dif;    //������� �����
	int base_chest_unlock;  //���� �������� �����

	//������� �������� 
	int armor;
	int shield;
	int dodge;
	int spead;
	int magic;
	int damage;
	int damage_dif;
	int chest_unlock;


	int position_x, position_y;
	int weapon_hold_tupe = 1;

	int potion = 0;
	int gold = 0;
	int picklock = 0;

	int inventory_size = 10;
	int *i = &inventory_size;
	MyItem *item = new MyItem[inventory_size];

	MyItem current_item_right_hand;
	MyItem current_item_left_hand;
	MyItem current_item_two_handed;
	MyItem current_armor;


	MyHero(string p_name, int P_X, int P_Y)
	{

		name = p_name;
		position_x = P_X;
		position_y = P_Y;

		EXP = 0;
		next_lvl_exp = 100;
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
		dodge  = base_dodge + current_armor.armor_dodge + current_item_left_hand.weapon_dodge + current_item_left_hand.shield_dodge + current_item_right_hand.weapon_dodge + current_item_two_handed.weapon_dodge;
		spead = base_spead + current_item_left_hand.weapon_spead + current_item_right_hand.weapon_spead + current_item_two_handed.weapon_spead;
		damage = base_damage + current_item_left_hand.weapon_damage + current_item_right_hand.weapon_damage;
		damage_dif = current_item_left_hand.weapon_damage_dif + current_item_right_hand.weapon_damage_dif + current_item_two_handed.weapon_damage_dif;
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
				base_spead = 80;
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
				base_spead = 80;
				base_magic = 2;
				base_damage = 5;
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
				base_spead = 80;
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
				base_spead = 80;
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
				base_spead = 80;
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
				base_spead = 80;
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
