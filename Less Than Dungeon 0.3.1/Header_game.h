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
	int weapon_type; // 1 - одноручное, 2 - двуручное
	int weapon_damage;
	int weapon_damage_dif;
	int weapon_dodge;  //настройка шанса увернуться
	int weapon_spead;  //настройка шанса нанесения удара
	int weapon_cost;

	/*MyWeapon()
	{
		weapon_name = "Кулак";
		weapon_damage = weapon_damage_dif = weapon_dodge = weapon_spead = weapon_cost = 0;
	}*/

	MyWeapon(string name = "Кулак", int type = 0, int damage = 0, int damage_dif = 0, int dodge = 0, int spead = 0, int cost = 0)
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

	MyArmor(string name = "Лохмотья", int block = 0, int dodge = 0, int cost = 0)
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

	MyShield(string name = "Отсутствует", int block = 0, int dodge = 0, int cost = 0)
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
	int inventory_position;
	MyItem()
	{
		item_type = 0;
		in_use = 0;
	}

	void clear_item()
	{
		item_type = inventory_position = in_use = 0;
		weapon_name = "Кулак";
		weapon_damage = weapon_damage_dif = weapon_dodge = weapon_spead = weapon_cost = 0;
		armor_name = "Лохмотья";
		armor_block = armor_dodge = armor_cost = 0;
		shield_name = "Отсутствует";
		shield_block = shield_dodge = shield_cost = 0;
	}

	void create_item(MyWeapon &weapon)
	{
		item_type = weapon.weapon_type; // 1 - одноручное, 2 - двуручное
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
	string name;			//Имя героя
	string class_name;		//Наименование класса

	int HP;					//Текущее здоровье
	int Level;				//Текущий уровень 
	int EXP;				//Текущий опыт
	int next_lvl_exp;  


	//базовые значения
	int max_HP;             //Максимальное здоровье
	int base_armor;         //Параметр защиты
	int base_shield;        //Параметр добавочной защиты щита 
	int base_dodge;         //Параметр шанса уклонения
	int base_spead;         //Параметр шанса попадания
	int base_magic;         //Уровень магической силы
	int base_damage;        //Значение урона
	int base_damage_dif;    //Разброс урона
	int base_chest_unlock;  //Шанс открытия замка

	//Текущие значения 
	int armor;
	int shield;
	int dodge;
	int spead;
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


	void refresh() //Обновление параметров
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
				class_name = "Странник";
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
				class_name = "Воин"; 
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
				class_name = "Берсерк";
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
				class_name = "Вор";
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
				class_name = "Дворянин";
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
				class_name = "Нищий";
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

struct Leaderboard {
	string name;
	int score;
};