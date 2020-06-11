#include "Header_game.h"
template <typename T>
void new_item(MyHero& Hero, T& new_item)
{
	MyItem item;
	item.create_item(new_item);
	cout << "�� ����� �������: " << endl;
	item.item_info();
	_getch();
}

void Quest_loot(MyHero& Hero, int loot_level, int loot_type)
{
	int chance = rand() % 100;
	switch (loot_type)
	{
		//������
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
							MyWeapon weapon("������  ",      1, 4, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("�����   ",      2, 4, 1, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("����    ",      2, 5, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("���     ",      1, 3, 2, 0, 10, 5); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("������  ",      1, 5, 2, 5, 10, 5); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("������ ���",    1, 7, 1, -5, -15, 5); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("������ �����",  2, 7, 2, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("������ ������", 1, 8, 1, -10, -15, 5); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("������ �����",  1, 8,  2, -5,  -10, 5); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("�����   ",      2, 14, 4, -30, -30, 10); new_item(Hero, weapon); break;
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
		//���
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
		//�����
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
							MyArmor armor("�������         ",   1, 0, 4); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("������          ",   2, 0, 6); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("������� ������  ",   2, -5, 4); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("���������� �������", 4, -15, 4); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("�������         ",   6, -30, 2); new_item(Hero, armor); break;
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
		//������
		case 4:
		{
			cout << "�� ����� ������� � ��������: " << endl;
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
			cout << "+" << chance << " ������" << endl;
			_getch();
			break;
		}
		//�����
		case 5:
		//�������
		case 6: break;
	}
}
