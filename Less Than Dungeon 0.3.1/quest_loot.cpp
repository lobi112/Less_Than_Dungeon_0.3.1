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
		cout << "�� ����� �������: " << endl;
		item.item_info();
		cout << "1)�����" << endl;
		cout << "2)���������" << endl;
		cout << "3)����������" << endl;
		cout << "0)��������" << endl;
		cout << Hero.name << " :";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				if (Hero.item_amount() >= Hero.inventory_size)
				{
					cout << Hero.name << ": � ������ �� �����!" << endl;
					_getch();
					continue;
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 0)
					{
						Hero.item[i].create_item(new_item);
						cout << "������� �������� � ���������." << endl;
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
				cout << Hero.name << ": ���� ��� ������, ��� � ���� ������..." << endl;
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
							MyWeapon weapon("������  ",      1, 0, 4, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("�����   ",      2, 1, 4, 1, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("����    ",      2, 0, 5, 1, 5, -10, 5); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("���     ",      1, 1, 3, 2, 0, 10, 5); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("������  ",      1, 1, 5, 2, 5, 10, 5); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("������ ���",    1, 0, 7, 1, -5, -15, 5); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("������ �����",  2, 1, 7, 2, 0, 0, 5); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("������ ������", 1, 2, 8, 1, -10, -15, 5); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("������ �����",  1, 2, 8,  2, -5,  -10, 5); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("�����   ",      2, 2, 14, 4, -30, -30, 10); new_item(Hero, weapon); break;
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
							MyWeapon weapon("����� �������", 1, 0, 7, 1, 0, 10, 15); new_item(Hero, weapon); break;
						}
						case 1:
						{
							MyWeapon weapon("����� ������", 1, 2, 11, 2, -10, -15, 18); new_item(Hero, weapon); break;
						}
						case 2:
						{
							MyWeapon weapon("����� ��������", 2, 2, 18, 2, -5, -15, 25); new_item(Hero, weapon); break;
						}
						case 3:
						{
							MyWeapon weapon("�������� ���", 1, 0, 9, 1, 0, 5, 20); new_item(Hero, weapon); break;
						}
						case 4:
						{
							MyWeapon weapon("������ �����", 2, 1, 10, 2, 10, 10, 30); new_item(Hero, weapon); break;
						}
						case 5:
						{
							MyWeapon weapon("�������� ��������", 1, 0, 9, 2, 0, 0, 16); new_item(Hero, weapon); break;
						}
						case 6:
						{
							MyWeapon weapon("����������� ���", 1, 1, 6, 1, 5, 10, 14); new_item(Hero, weapon); break;
						}
						case 7:
						{
							MyWeapon weapon("���������� ���", 1, 1, 6, 1, 10, 30, 30); new_item(Hero, weapon); break;
						}
						case 8:
						{
							MyWeapon weapon("������ ���", 1, 2, 10, 5, -10, -5, 12); new_item(Hero, weapon); break;
						}
						case 9:
						{
							MyWeapon weapon("����� �������", 2, 2, 24, 4, -40, -40, 10); new_item(Hero, weapon); break;
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
		//���
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
							MyShield shield("������ ������   ", 4, -5, 0, 8); new_item(Hero, shield); break;
						}
						case 1:
						{
							MyShield shield("�������� �����. ���", 6, -15, -10, 6); new_item(Hero, shield); break;
						}
						case 2:
						{
							MyShield shield("�������� �����. ���", 6, -10, -5, 10); new_item(Hero, shield); break;
						}
						case 3:
						{
							MyShield shield("������ �����. ���", 8, -20, -10, 12); new_item(Hero, shield); break;
						}
						case 4:
						{
							MyShield shield("������� �����   ", 5, -5, 0, 1); new_item(Hero, shield); break;
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
							MyShield shield("������� ������   ", 5, 5, 0, 10); new_item(Hero, shield); break;
						}
						case 1:
						{
							MyShield shield("����� ������ ��� ", 10, -5, 0, 20); new_item(Hero, shield); break;
						}
						case 2:
						{
							MyShield shield("������� ���      ", 8, 0, 5, 25); new_item(Hero, shield); break;
						}
						case 3:
						{
							MyShield shield("������� �����. ���", 14, -15, -20, 22); new_item(Hero, shield); break;
						}
						case 4:
						{
							MyShield shield("������ ������    ", 12, -10, -10, 20); new_item(Hero, shield); break;
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
							MyArmor armor("�������         ",   1, 0, 0, 4); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("������          ",   2, 0, 0, 6); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("������� ������  ",   2, -5, 0, 4); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("���������� �������", 4, -15, -10, 4); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("�������         ",   6, -30, -15, 2); new_item(Hero, armor); break;
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
							MyArmor armor("������� ��������", 4, -5, -5, 14); new_item(Hero, armor); break;
						}
						case 1:
						{
							MyArmor armor("������ ���. �����", 3, 0, 0, 15); new_item(Hero, armor); break;
						}
						case 2:
						{
							MyArmor armor("���� ����       ", 1, 10, 10, 10); new_item(Hero, armor); break;
						}
						case 3:
						{
							MyArmor armor("�������� �������", 6, -15, -5, 25); new_item(Hero, armor); break;
						}
						case 4:
						{
							MyArmor armor("������ �����. �����", 7, -10, -5, 30); new_item(Hero, armor); break;
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
		//������
		case 4:
		{
			cout << "�� ����� ������� � ��������." << endl;
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
