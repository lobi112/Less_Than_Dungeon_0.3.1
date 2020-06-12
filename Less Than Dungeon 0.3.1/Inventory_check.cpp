#include "Header_game.h"

void ammunition_check(MyHero& Hero)
{
	int choice;

	while (true) {
		system("cls");
		cout << "Здоровье : " << Hero.HP << "/" << Hero.max_HP << endl;
		cout << "Урон      : " << Hero.damage - Hero.base_damage_dif << "-"<< Hero.damage + Hero.base_damage_dif << endl;
		cout << "Броня     : " << Hero.armor << endl;
		cout << "Щит       : " << Hero.shield << endl;
		cout << "Уклонение : " << Hero.dodge << endl;
		cout << "Скорость  : " << Hero.spead << endl << endl;

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
		else if (Hero.current_item_left_hand.item_type == 3)
		{
			cout << "Щит : " << Hero.current_item_left_hand.shield_name << endl;
			cout << "Защита щита : " << Hero.current_item_left_hand.shield_block << endl;
			cout << "Уклонение : "; if (Hero.current_item_left_hand.shield_dodge >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.shield_dodge << endl << endl;
		}
		if (Hero.current_item_two_handed.item_type == 2)
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
			cout << "Уклонение : "; if (Hero.current_armor.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_armor.weapon_dodge << endl << endl;
		}

		cout << "1)Поменять предмет в правой руке." << endl;
		cout << "2)Поменять предмет в левой руке." << endl;
		cout << "3)Взять двуручный предмет." << endl;
		cout << "4)Поменять броню." << endl;
		cout << "5)Выбросить предмет." << endl;
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
					if (Hero.item[i].item_type == 1 && !Hero.item[i].in_use)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Одноручное оружие в рюкзаке в рюкзаке :" << endl;
					cout << "1)Снять текущий предмет" << endl;

					for (int i = 0; i < item_amount; i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount+1))
					{
						cout << Hero.name << "Я всё выгреб из рюкзака, честно" <<  endl;
						_getch();
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					if (choice == 1)
					{
						if (Hero.current_item_right_hand.in_use)
						{
							Hero.item[Hero.current_item_right_hand.inventory_position].in_use = false;
							Hero.current_item_right_hand.clear_item();
							Hero.refresh();
							break;
						}
						else
						{
							cout << Hero.name << ": В голых руках правды нет!" << endl;
							_getch();
							continue;
						}
					}

					if (Hero.current_item_two_handed.in_use)
					{
						Hero.item[Hero.current_item_two_handed.inventory_position].in_use = false;
						Hero.current_item_two_handed.clear_item();
					}

					if (Hero.current_item_right_hand.in_use)
					{
						Hero.item[Hero.current_item_right_hand.inventory_position].in_use = false;
						Hero.current_item_right_hand.clear_item();
					}
					Hero.item[position[choice - 2]].in_use = true;
					Hero.current_item_right_hand = Hero.item[position[choice - 2]];
					
					Hero.refresh();
					break;
				}

				delete[] position;
				continue;
			}
			case 2:
			{

				int item_amount = 0;
				int *position = new int[Hero.inventory_size];

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1 && !Hero.item[i].in_use)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 3 && !Hero.item[i].in_use)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Предметы в рюкзаке :" << endl << endl;
					cout << "1)Снять текущий предмет" << endl;
					for (int i = 0; i < item_amount; i++)
					{
						switch (Hero.item[position[i]].item_type)
						{
							case 1: cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl; break;
							case 3: cout << i + 2 << ")" << Hero.item[position[i]].shield_name << endl; break;
						}
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount+1))
					{
						cout << Hero.name << "Я всё выгреб, честно" << endl;
						_getch();
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					if (choice == 1)
					{
						if (Hero.current_item_left_hand.in_use)
						{
							Hero.item[Hero.current_item_left_hand.inventory_position].in_use = false;
							Hero.current_item_left_hand.clear_item();
							Hero.refresh();
							break;
						}
						else
						{
							cout << Hero.name << ": В голых руках правды нет!" << endl;
							_getch();
							continue;
						}
					}

					if (Hero.current_item_two_handed.in_use)
					{
						Hero.item[Hero.current_item_two_handed.inventory_position].in_use = false;
						Hero.current_item_two_handed.clear_item();
					}
					if (Hero.current_item_left_hand.in_use)
					{
						Hero.item[Hero.current_item_left_hand.inventory_position].in_use = false;
						Hero.current_item_left_hand.clear_item();
					}

					Hero.item[position[choice - 2]].in_use = true;
					Hero.current_item_left_hand = Hero.item[position[choice - 2]];
					

					Hero.refresh();
					break;
				}


				delete[] position;
				continue;
			}

			case 3:
			{

				int item_amount = 0;
				int *position = new int[Hero.inventory_size];

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 2 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Двуручное оружие в рюкзаке :" << endl;
					cout << "1)Снять текущий предмет" << endl;
					for (int i = 0; i < item_amount; i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount+1))
					{
						cout << Hero.name << "Я всё выгреб из рюкзака, честно" << endl;
						_getch();
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					if (choice == 1)
					{
						if (Hero.current_item_two_handed.in_use)
						{
							Hero.item[Hero.current_item_two_handed.inventory_position].in_use = false;
							Hero.current_item_two_handed.clear_item();
							Hero.refresh();
							break;
						}
						else
						{
							cout << Hero.name << ": В голых руках правды нет!" << endl;
							_getch();
							continue;
						}
					}


					if (Hero.current_item_two_handed.in_use)
					{
						Hero.item[Hero.current_item_two_handed.inventory_position].in_use = false;
						Hero.current_item_two_handed.clear_item();
					}
					if (Hero.current_item_left_hand.in_use)
					{
						Hero.item[Hero.current_item_left_hand.inventory_position].in_use = false;
						Hero.current_item_left_hand.clear_item();
					}
					if (Hero.current_item_right_hand.in_use)
					{
						Hero.item[Hero.current_item_right_hand.inventory_position].in_use = false;
						Hero.current_item_right_hand.clear_item();
					}

					Hero.item[position[choice - 2]].in_use = true;
					Hero.current_item_two_handed = Hero.item[position[choice - 2]];
					
					Hero.refresh();
					break;
				}


				delete[] position;
				continue;
			}
			case 4:
			{
				int item_amount = 0;
				int *position = new int[Hero.inventory_size];

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 4 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Одежда/броня в рюкзаке :" << endl;
					cout << "1)Снять текущий предмет" << endl;
					for (int i = 0; i < item_amount; i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].armor_name << endl;
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > item_amount+1))
					{
						cout << Hero.name << "Я всё выгреб из рюкзака, честно" << endl;
						_getch();
						continue;
					}

					if (choice == 0)
					{
						break;
					}

					if (choice == 1)
					{
						if (Hero.current_armor.in_use)
						{
							Hero.item[Hero.current_armor.inventory_position].in_use = false;
							Hero.current_armor.clear_item();
							Hero.refresh();
							break;
						}
						else
						{
							cout << Hero.name << ": В голых руках правды нет!" << endl;
							_getch();
							continue;
						}
					}

					if (Hero.current_armor.in_use)
					{
						Hero.item[Hero.current_armor.inventory_position].in_use = false;
						Hero.current_armor.clear_item();
					}

					Hero.item[position[choice - 2]].in_use = true;
					Hero.current_armor = Hero.item[position[choice - 2]];
					Hero.refresh();
					break;
				}

				delete[] position;
				continue;
			}
			case 5:
			{
				int item_amount = 0;
				int *position = new int[Hero.inventory_size];

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 2 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 3 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 4 && Hero.item[i].in_use == 0)
					{
						position[item_amount] = i;
						item_amount++;
					}
				}

				while (true)
				{
					system("cls");
					cout << "Предметы в рюкзаке :" << endl << endl;
					for (int i = 0; i < item_amount; i++)
					{
						switch (Hero.item[position[i]].item_type)
						{
						case 1: case 2: cout << i + 1 << ")" << Hero.item[position[i]].weapon_name << endl; break;
						case 3:			cout << i + 1 << ")" << Hero.item[position[i]].shield_name << endl; break;
						case 4:			cout << i + 1 << ")" << Hero.item[position[i]].armor_name  << endl; break;
						}
					}

					cout << "0)Назад" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice >= item_amount + 1))
					{
						cout << Hero.name << "Я всё выгреб, честно" << endl;
						_getch();
						continue;
					}

					if (choice == 0)
					{
						break;
					}
					Hero.item[position[choice - 1]].clear_item();
					break;
				}
				delete[] position;
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

	cout << "Слоты для предметов : " << "( " << Hero.item_amount(); cout << "/" << Hero.inventory_size << " )" << endl << endl;
	cout << "Оружие :" << endl;
	cout << "Название :\t" << "Тип :\t\t" << "Урон :\t" << "Скорость :\t" << "Уклонение :\t" << "Цена :" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if ((Hero.item[i].item_type == 1) || (Hero.item[i].item_type == 2))
		{
			cout << Hero.item[i].weapon_name << "\t";
			(Hero.item[i].item_type == 1) ? cout << "Одноручное\t" : cout << "Двуручное\t";
			cout << (Hero.item[i].weapon_damage - Hero.item[i].weapon_damage_dif) << "-" << (Hero.item[i].weapon_damage + Hero.item[i].weapon_damage_dif) << "\t";
			if (Hero.item[i].weapon_spead >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_spead << "\t\t";
			if (Hero.item[i].weapon_dodge >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_dodge << "\t\t";
			cout << Hero.item[i].weapon_cost  << "\t" << endl << endl;
		}
		
	}
	cout << endl;
	cout << "Одежда/Доспехи :" << endl;
	cout << "Название :\t\t" << "Защита :\t" << "Уклонение :\t" << "Цена :\t" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 4)
		{
			cout << Hero.item[i].armor_name << "\t";
			cout << Hero.item[i].armor_block << "\t\t";
			if (Hero.item[i].armor_dodge >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].armor_dodge << "\t\t";
			cout << Hero.item[i].armor_cost << "\t" << endl << endl;
		}
	}
	cout << endl;
	cout << "Щиты :" << endl;
	cout << "Название :\t\t" << "Защита :\t" << "Уклонение :\t" << "Цена :\t" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 3)
		{
			cout << Hero.item[i].shield_name << "\t";
			cout << Hero.item[i].shield_block << "\t\t";
			if (Hero.item[i].shield_dodge >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].shield_dodge << "\t\t";
			cout << Hero.item[i].shield_cost << "\t" << endl << endl;
		}
	}

	_getch();
	system("cls");
}