#include "Header_game.h"
bool ammunition_check(MyHero& Hero, bool in_fight);
void items_check(MyHero& Hero);

template <typename T>
void new_item(MyHero& Hero, T& new_item)
{
	int choice=0;
	MyItem item;
	item.create_item(new_item);
	while (true)
	{
		system("cls");
		cout << "Вы нашли предмет: " << endl;
		item.item_info();
		cout << "1)Взять" << endl;
		cout << "2)Инвентарь" << endl;
		cout << "3)Экипировка" << endl;
		cout << "0)Оставить" << endl;
		cout << Hero.name << " :";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				if (Hero.item_amount() >= Hero.inventory_size)
				{
					cout << Hero.name << ": я больше не унесу!" << endl;
					_getch();
					continue;
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 0)
					{
						Hero.item[i].create_item(new_item);
						cout << "Предмет добавлен в инвентарь." << endl;
						_getch();
						break;
					}

				}
				break;
			}
			case 2:
			{
				items_check(Hero);
				continue;
			}
			case 3:
			{
				ammunition_check(Hero, 0);
				continue;
			}
			case 0:
			{
				break;
			}
			default:
			{
				cout << Hero.name << ": Надо уже решить, что с этим делать..." << endl;
				_getch();
				continue;
			}
		}
		break;
	}
}

void quest_loot(MyHero& Hero, int loot_level, int loot_type)
{
	int chance = rand() % 100;
	switch (loot_type)
	{
		//оружие
		case 1: 
		{
			switch (loot_level)
			{
				case 1:
				{
					int chance = rand() % 10;
					switch (chance)
					{
						case 0:
						{
							MyWeapon weapon("Дубина  ",      1, 0, 4, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("Посох   ",      2, 1, 4, 1, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("Вилы    ",      2, 0, 5, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("Нож     ",      1, 1, 3, 2, 0, 10, 5); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("Кинжал  ",      1, 1, 5, 2, 5, 10, 5); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("Ржавый меч",    1, 0, 7, 1, -5, -15, 5); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("Старое копьё",  2, 1, 7, 2, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("Ржавая булава", 1, 2, 8, 1, -10, -15, 5); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("Ржавый топор",  1, 2, 8,  2, -5,  -10, 5); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("Кайло   ",      2, 2, 14, 4, -30, -30, 10); new_item(Hero, weapon); break;
						}
					}
					break;
				}	
				case 2: 
				{
					int chance = rand() % 10;
					switch (chance)
					{
						case 0:
						{
							MyWeapon weapon("Малый топорик", 1, 0, 7, 1, 0, 10, 15); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("Тупая булаба", 1, 2, 11, 2, -10, -15, 18); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("Топор лесоруба", 2, 2, 18, 2, -5, -15, 25); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("Короткий меч", 1, 0, 9, 1, 0, 5, 20); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("Старая глефа", 2, 1, 10, 2, 10, 10, 30); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("Короткий Фальшион", 1, 0, 9, 2, 0, 0, 16); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("Зазубренный нож", 1, 1, 6, 1, 5, 10, 14); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("Эльфийский нож", 1, 1, 6, 1, 10, 30, 30); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("Орочий меч", 1, 2, 10, 5, -10, -5, 12); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("Молот кузнеца", 2, 2, 24, 4, -40, -40, 10); new_item(Hero, weapon); break;
						}
					}
					break;
				}
				case 3:
				{
					break;
				}
				case 4: 
				{
					break;
				}
				case 5: 
				{
					break;
				}
			}
			break;
		}

		 break;
		//шит
		case 2:
		{
			switch (loot_level)
			{
				case 1:
				{
					int chance = rand() % 5;
					switch (chance)
					{
						case 0:
						{
							MyShield shield("Старый баклер   ", 4, -5, 0, 8); new_item(Hero, shield); break;
						}
						case 1:
						{
							MyShield shield("Разбитый дерев. щит", 6, -15, -10, 6); new_item(Hero, shield); break;
						}
						case 2:
						{
							MyShield shield("Погнутый бронз. щит", 6, -10, -5, 10); new_item(Hero, shield); break;
						}
						case 3:
						{
							MyShield shield("Орочий дерев. щит", 8, -20, -10, 12); new_item(Hero, shield); break;
						}
						case 4:
						{
							MyShield shield("Дубовая ветвь   ", 5, -5, 0, 1); new_item(Hero, shield); break;
						}
					}
					break;

				}
				case 2: 
				{
					int chance = rand() % 5;
					switch (chance)
					{
						case 0:
						{
							MyShield shield("Простой баклер   ", 5, 5, 0, 10); new_item(Hero, shield); break;
						}
						case 1:
						{
							MyShield shield("Малый гномий щит ", 10, -5, 0, 20); new_item(Hero, shield); break;
						}
						case 2:
						{
							MyShield shield("Кожаный щит      ", 8, 0, 5, 25); new_item(Hero, shield); break;
						}
						case 3:
						{
							MyShield shield("Большой дерев. щит", 14, -15, -20, 22); new_item(Hero, shield); break;
						}
						case 4:
						{
							MyShield shield("Старый скутум    ", 12, -10, -10, 20); new_item(Hero, shield); break;
						}
					}
					break;
				}
				case 3: 
				{
					break;
				}
				case 4: 
				{
					break;
				}
				case 5: 
				{
					break;
				}
			}
			break;
		}
		//броня
		case 3: 
		{
			switch (loot_level)
			{
				case 1:
				{
					int chance = rand() % 5;
					switch (chance)
					{
						case 0:
						{
							MyArmor armor("Жилетка         ",   1, 0, 0, 4); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("Куртка          ",   2, 0, 0, 6); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("Плотная рубаха  ",   2, -5, 0, 4); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("Деревянные обвески", 4, -15, -10, 4); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("Бочёнок         ",   6, -30, -15, 2); new_item(Hero, armor); break;
						}
					}
					break;
				}
				case 2: 
				{
					int chance = rand() % 5;
					switch (chance)
					{
						case 0:
						{
							MyArmor armor("Дешёвая кальчуга", 4, -5, -5, 14); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("Тонкая кож. Броня", 3, 0, 0, 15); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("Плащ вора       ", 1, 10, 10, 10); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("Железные обвески", 6, -15, -5, 25); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("Старая бронз. броня", 7, -10, -5, 30); new_item(Hero, armor); break;
						}
					}
					break;
				}
				case 3: 
				{
					break;
				}
				case 4: 
				{
					break;
				}
				case 5: 
				{
					break;
				}
			}
			break;
		}
		//монеты
		case 4:
		{
			cout << "Вы нашли мешочек с монетами." << endl;
			switch (loot_level)
			{
				case 1:
				{
					chance = 1 + rand() % 5;
					break;
				}
				case 2:
				{
					chance = 6 + rand() % 10;
					break;
				}
				case 3:
				{
					chance = 15 + rand() % 15;
					break;
				}
				case 4:
				{
					chance = 35 + rand() % 20;
					break;
				}
				case 5:
				{
					chance = 65 + rand() % 40;
					break;
				}
			}
			cout << "+" << chance << " золота" << endl;
			_getch();
			break;
		}
		//зелья
		case 5:
		//отмычки
		case 6: break;
	}
}
