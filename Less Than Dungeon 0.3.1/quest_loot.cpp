#include "Header_game.h"
template <typename T>
void new_item(MyHero& Hero, T& new_item)
{
	MyItem item;
	item.create_item(new_item);
	cout << "Вы нашли предмет: " << endl;
	item.item_info();
	_getch();
}

void Quest_loot(MyHero& Hero, int loot_level, int loot_type)
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
							MyWeapon weapon("Дубина  ",      1, 4, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("Посох   ",      2, 4, 1, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("Вилы    ",      2, 5, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("Нож     ",      1, 3, 2, 0, 10, 5); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("Кинжал  ",      1, 5, 2, 5, 10, 5); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("Ржавый меч",    1, 7, 1, -5, -15, 5); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("Старое копьё",  2, 7, 2, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("Ржавая булава", 1, 8, 1, -10, -15, 5); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("Ржавый топор",  1, 8,  2, -5,  -10, 5); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("Кайло   ",      2, 14, 4, -30, -30, 10); new_item(Hero, weapon); break;
						}
					}
					break;
				}	
				case 2: 
				{
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
					int chance = rand() % 10;
					switch (chance)
					{
						case 0: break;
						case 1: break;
						case 2: break;
						case 3: break;
						case 4: break;
						case 5: break;
						case 6: break;
						case 7: break;
						case 8: break;
						case 9: break;
					}

				}
				case 2: 
				{
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
							MyArmor armor("Жилетка         ",   1, 0, 4); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("Куртка          ",   2, 0, 6); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("Плотная рубаха  ",   2, -5, 4); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("Деревянные обвески", 4, -15, 4); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("Бочёнок         ",   6, -30, 2); new_item(Hero, armor); break;
						}

					}
				}
				case 2: 
				{
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
			cout << "Вы нашли мешочек с монетами: " << endl;
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
					chance = 50 + rand() % 40;
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
