#include "Header_game.h"

void ammunition_check(MyHero& Hero)
{
	int choice;

	while (true) {
		system("cls");
		cout << Hero.name << endl;
		cout << "Класс : " << Hero.class_name << endl;
		cout << "Здоровье : " << Hero.HP << "/" << Hero.max_HP << endl << endl;
		cout << "Золото   : " << Hero.gold << endl;

		cout << "Урон : " << Hero.damage << endl;
		cout << "Броня : " << Hero.armor << endl;
		cout << "Щит : " << Hero.shield << endl;
		cout << "Уклонение : " << Hero.dodge << endl;
		cout << "Скорость : " << endl << endl;

		if (Hero.current_item_right_hand.item_type == 1)
		{
			cout << "Оружие в правой руке : " << Hero.current_item_right_hand.weapon_name << endl;
			cout << "Урон оружием : " << (Hero.current_item_right_hand.weapon_damage - Hero.current_item_right_hand.weapon_damage_dif) << "-" << (Hero.current_item_right_hand.weapon_damage + Hero.current_item_right_hand.weapon_damage_dif) << endl;
			cout << "Уклонение : "; if (Hero.current_item_right_hand.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_right_hand.weapon_dodge << endl;
			cout << "Скорость : "; if (Hero.current_item_right_hand.weapon_spead >= 0) { cout << "+"; } cout << Hero.current_item_right_hand.weapon_spead << endl << endl;
		}
		if (Hero.current_item_left_hand.item_type == 1)
		{
			cout << "Оружие в левой руке : " << Hero.current_item_left_hand.weapon_name << endl;
			cout << "Урон оружием : " << (Hero.current_item_left_hand.weapon_damage - Hero.current_item_left_hand.weapon_damage_dif) << "-" << (Hero.current_item_left_hand.weapon_damage + Hero.current_item_left_hand.weapon_damage_dif) << endl;
			cout << "Уклонение : "; if (Hero.current_item_left_hand.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.weapon_dodge << endl;
			cout << "Скорость : "; if (Hero.current_item_left_hand.weapon_spead >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.weapon_spead << endl << endl;
		}
		else if (Hero.current_item_left_hand.item_type == 2)
		{
			cout << "Щит : " << Hero.current_item_left_hand.shield_name << endl;
			cout << "Защита щита : " << Hero.current_item_left_hand.shield_block << endl;
			cout << "Уклонение : "; if (Hero.current_item_left_hand.shield_dodge >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.shield_dodge << endl << endl;
		}
		if (Hero.current_item_two_handed.item_type == 3)
		{
			cout << "Оружие в двух руках : " << Hero.current_item_two_handed.weapon_name << endl;
			cout << "Урон оружием : " << (Hero.current_item_two_handed.weapon_damage - Hero.current_item_two_handed.weapon_damage_dif) << "-" << (Hero.current_item_two_handed.weapon_damage + Hero.current_item_two_handed.weapon_damage_dif) << endl;
			cout << "Уклонение : "; if (Hero.current_item_two_handed.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_two_handed.weapon_dodge << endl;
			cout << "Скорость : "; if (Hero.current_item_two_handed.weapon_spead >= 0) { cout << "+"; } cout << Hero.current_item_two_handed.weapon_spead << endl << endl;
		}
		if (Hero.current_armor.item_type == 4)
		{
			cout << "Броня : " << Hero.current_armor.armor_name << endl;
			cout << "Защита брони : " << Hero.current_armor.armor_block << endl;
			cout << "Уклонение : "; if (Hero.current_item_two_handed.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_two_handed.weapon_dodge << endl << endl;
		}

		cout << "1)Поменять предмет в правой руке." << endl;
		cout << "2)Поменять предмет в левой руке." << endl;
		cout << "3)Взять двуручный предмет." << endl;
		cout << "4)Поменять броню." << endl;
		cout << "0)Назад." << endl;
		cout << Hero.name << ": ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				int item_amount = 0;
				int *position = new int[Hero.inventory_size];

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Одноручное оружие в рюкзаке в рюкзаке :" << endl;
					for (int i = 0; i < item_amount; i++)
					{
						cout << i + 1 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount))
					{
						cout << Hero.name << "Я всё выгреб из рюкзака, честно" <<  endl;
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					Hero.current_item_right_hand = Hero.item[position[choice-1]];
					Hero.refresh();
					break;
				}
				

				delete[] position;
				continue;
			}
			case 2:
			{

				int item_amount = Hero.item_amount();
				int *position = new int[Hero.inventory_size];

				while (true)
				{
					system("cls");
					cout << "Одноручное оружие в рюкзаке в рюкзаке :" << endl << endl;
					for (int i = 0; i < item_amount; i++)
					{
						cout << i + 1 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount))
					{
						cout << Hero.name << "Я всё выгреб из рюкзака, честно" << endl;
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					Hero.current_item_right_hand = Hero.item[position[choice - 1]];
					Hero.refresh();
					break;
				}


				delete[] position;
				continue;
			}
			case 3:
			{

				continue;
			}
			case 4:
			{

				continue;
			}
			case 0:
			{
				break;
			}
		}

		break;
	}

}

void items_check(MyHero& Hero)
{
	system("cls");
	cout << Hero.name << endl;
	cout << "Класс : " << Hero.class_name << endl;
	cout << "Здоровье : " << Hero.HP << "/" << Hero.max_HP << endl << endl;	

	cout << "Золото   : " << Hero.gold << endl;
	cout << "Зелья лечения : " << Hero.potion << endl;
	cout << "Отмычки       : " << Hero.picklock << endl << endl;

	cout << "Слоты для предметов : " << "( " << Hero.item_amount(); cout << "/" << Hero.inventory_size << " )" << endl << endl;;
	cout << "Оружие :" << endl;
	cout << "Название :\t" << "Тип :\t\t" << "Урон :\t" << "Скорость :\t" << "Уклонение :\t" << "Цена :\t" << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if ((Hero.item[i].item_type == 1) || (Hero.item[i].item_type == 2))
		{
			cout << Hero.item[i].weapon_name << "\t\t";
			if (Hero.item[i].item_type == 1)
			{
				cout << "Одноручное\t";
			}
			else
			{
				cout << "Двуручное\t";
			}
			cout << (Hero.item[i].weapon_damage - Hero.item[i].weapon_damage_dif) << "-" << (Hero.item[i].weapon_damage + Hero.item[i].weapon_damage_dif) << "\t";
			if (Hero.item[i].weapon_spead > 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_spead << "\t\t";
			if (Hero.item[i].weapon_dodge > 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_dodge << "\t\t";
			cout << Hero.item[i].weapon_cost  << "\t" << endl << endl;
		}
		
	}
	cout << endl;
	cout << "Одежда/Доспехи :" << endl;
	cout << "Название :\t" << "Защита :\t" << "Уклонение :\t" << "Цена :\t" << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 4)
		{
			cout << Hero.item[i].armor_name << "\t";
			cout << Hero.item[i].armor_block << "\t\t";
			cout << "+" << Hero.item[i].armor_dodge << "\t\t";
			cout << Hero.item[i].armor_cost << "\t" << endl << endl;
		}
		
	}
	cout << endl;
	cout << "Щиты :" << endl;
	cout << "Название :\t" << "Защита :\t" << "Уклонение :\t" << "Цена :\t" << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 3)
		{
			cout << Hero.item[i].shield_name << "\t";
			cout << Hero.item[i].shield_block << "\t\t";
			cout << "+" << Hero.item[i].shield_dodge << "\t\t";
			cout << Hero.item[i].shield_cost << "\t" << endl << endl;
		}
	}
	


	_getch();
	system("cls");
}