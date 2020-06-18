#include "Header_game.h"
bool ammunition_check(MyHero& Hero, bool in_fight);
void items_check(MyHero& Hero);

void buy_consumables(MyHero& Hero, int traider_type, int choice, int cost)
{
	int amount = 0;
	system("cls");
	switch (traider_type)
	{
		case 0:
		case 1:
		{
			cout << "�� ���������: ";
			switch (choice)
			{
				case 1: cout << "����� ������� (�)" << endl << endl; break;
				case 2: cout << "����� ������� (�)" << endl << endl;  break;
				case 3: cout << "�������" << endl << endl;  break;
			}
			cout << "� ��� �� ������ ������: ";
			switch (choice)
			{
				case 1: cout << Hero.heal_potion_s << endl << endl;  break;
				case 2: cout << Hero.heal_potion_l << endl << endl;  break;
				case 3: cout << Hero.picklock << endl << endl;  break;
			}
			cout << "��������� ������� : " << cost << endl;
			cout << "���� ������       : " << Hero.gold << endl << endl;
			cout << "N)������ (������� ����������)" << endl;
			cout << "0)�����" << endl;
			cout << Hero.name << ": "; cin >> amount;
			if (amount == 0)
			{
				break;
			}
			if (amount > 0 && amount*cost <= Hero.gold)
			{
				Hero.gold -= cost * amount;
				switch (choice)
				{
					case 1:
					{
						Hero.heal_potion_s += amount;
						break;
					}
					case 2:
					{
						Hero.heal_potion_l += amount;
						break;
					}
					case 3:
					{
						Hero.picklock += amount;
						break;
					}
				}
				cout << "�� ��������� " << amount;
				switch (choice)
				{
					case 1: cout << " ����� ������� (�)"; break;
					case 2: cout << " ����� ������� (�)";  break;
					case 3: cout << " �������";  break;
				}
				cout << " �� " << amount * cost << " �����." << endl;
				_getch();
				break;
			}
			else
			{
				cout << "��������: ���, ����, ���� �� ������� �� ��� �����." << endl;
				_getch();
				break;
			}
			break;
		}
	}
}

template <typename T>
void buy_item(MyHero& Hero, T& new_item, int cost)
{
	int choice = 0;
	MyItem item;
	item.create_item(new_item);

	while (true)
	{
		system("cls");
		cout << "�������: " << endl << endl;
		item.item_info();
		cout << "���� ������: " << Hero.gold << endl << endl;
		cout << "1)������ �� " << cost << endl;
		cout << "2)���������" << endl;
		cout << "3)����������" << endl;
		cout << "0)�����" << endl;
		cout << Hero.name << " :"; cin >> choice;
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
				if (Hero.gold < cost)
				{
					cout << "��������: ���, ����, ���� �� ������� �� ��� �����." << endl;
					_getch();
					continue;
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 0 && Hero.gold >= cost)
					{
						Hero.gold -= cost;
						Hero.item[i].create_item(new_item);
						cout << "�� ��������� ������� �� " << cost << " �����." << endl;
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
				cout << "��������: ��, �� ���-�� �������?" << endl;
				_getch();
				continue;
			}
		}
		break;
	}

	
}

void quest_trader(MyHero& Hero, int trader_type, int trader_level)
{
	double buy_factor = 1, sale_factor = 0.8;
	int choice = 0;

	int heel_potion_s_cost = 0;
	int heel_potion_l_cost = 0;
	int picklock_cost = 0;

	vector<MyWeapon> weapon_list;
	vector<MyShield> shield_list;
	vector<MyArmor>  armor_list;

	switch (trader_type)
	{
		case 0:
		{
			heel_potion_s_cost = 12 + rand() % 9;
			heel_potion_l_cost = 27 + rand() % 9;;
			picklock_cost = 10 + rand() % 9;
			break;
		}
		case 1:
		{
			heel_potion_s_cost = 10;
			heel_potion_l_cost = 25;
			picklock_cost = 8;
			break;
		}


	}

	while (true)
	{
		
		system("cls");
		switch (trader_type)
		{
			case 0: 
			{
				cout << "�� ���������� ��������� ��������." << endl;
				cout << "��������: ����������� ����, ������! �� ������� ���� ���������?" << endl << endl;
				break;
			}
			case 1:
			{
				cout << "�� ����������� � ����� � ������ �� ���������." << endl;
				cout << "��������: ����������, ��� ���� ����������?" << endl << endl;
				break;
			}
			case 2:
			{
				cout << "�� �������� � ����� ����������." << endl;
				cout << "��������: ������ ����, ����! �������, ����, ������, � ���� ����� ���� �������!" << endl << endl;
				break;
			}
			case 3:
			{
				cout << "�� ������������ � ����� ��������." << endl;
				cout << "��������: ������ ����! ���-������ ����������?" << endl << endl;
				break;
			}
		}

		cout << "1)������ ���� ������" << endl;
		cout << "2)� �� ����� ���-��� ������� (N/A)" << endl;
		cout << "3)���������" << endl;
		cout << "4)���������" << endl;
		cout << "0)����" << endl;
		cout << Hero.name << ": "; cin >> choice;
		switch (choice)
		{
			case 1:
			{
				switch (trader_type)
				{
					case 0:
					case 1:
					{
						while (true)
						{
							system("cls");
							cout << "��������: �������!" << endl << endl;
							cout << "1)����� ������� (�) : " << heel_potion_s_cost << " �����" << endl;
							cout << "2)����� ������� (�) : " << heel_potion_l_cost << " �����" << endl;
							cout << "3)�������           : " << picklock_cost << " �����" << endl;
							cout << "0)�����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							if (choice == 0) break;
							switch (choice)
							{
								case 1: buy_consumables(Hero, trader_type, choice, heel_potion_s_cost); break;
								case 2: buy_consumables(Hero, trader_type, choice, heel_potion_l_cost); break;
								case 3: buy_consumables(Hero, trader_type, choice, picklock_cost); break;
								default: cout << "��������: ��, �� ���-�� �������?" << endl; 
							}
						}
						continue;
					}
					case 2:
					{
						while (true)
						{
							system("cls");
							cout << "��������: ����� ���-�� ����������?" << endl << endl;
							cout << "1)������" << endl;
							cout << "2)����" << endl;
							cout << "0)�����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							if (choice == 0)
							{
								break;
							}
							switch (choice)
							{
								case 1:
								{
									switch (trader_level)
									{
										case 0:
										{	
											MyWeapon weapon0("������\t", 1, 0, 4, 1, 5, -10, 5);            weapon_list.push_back(weapon0);
											MyWeapon weapon1("���   \t", 1, 1, 3, 2, 0, 10, 5);             weapon_list.push_back(weapon1);
											MyWeapon weapon2("����� \t", 2, 1, 4, 1, 0, 0, 7);              weapon_list.push_back(weapon2);
											MyWeapon weapon3("������\t", 1, 1, 5, 2, 5, 10, 10);            weapon_list.push_back(weapon3);
											MyWeapon weapon4("������ ���    ",    1, 0, 7, 1, -5, -15, 12); weapon_list.push_back(weapon4);
											MyWeapon weapon5("������ ������ ", 1, 2, 8, 1, -10, -15, 12);   weapon_list.push_back(weapon5); 
											break;
										}
										case 1:
										{
											MyWeapon weapon0("���   \t", 1, 1, 3, 2, 0, 10, 5);             weapon_list.push_back(weapon0);
											MyWeapon weapon1("����� \t", 2, 1, 4, 1, 0, 0, 7);              weapon_list.push_back(weapon1); 
											MyWeapon weapon2("������\t", 1, 1, 5, 2, 5, 10, 10);            weapon_list.push_back(weapon2); 
											MyWeapon weapon3("����� ������� ", 1, 0, 7, 1, 0, 10, 15);      weapon_list.push_back(weapon3);
											MyWeapon weapon4("�������� ���  ", 1, 0, 9, 1, 0, 5, 20);         weapon_list.push_back(weapon4);
											MyWeapon weapon5("�������� ��������", 1, 0, 9, 2, 0, 0, 16);    weapon_list.push_back(weapon5);
											MyWeapon weapon6("������ �����  ", 2, 1, 10, 2, 10, 10, 30);      weapon_list.push_back(weapon6); 
											MyWeapon weapon7("����� ��������", 2, 2, 18, 2, -5, -15, 25);   weapon_list.push_back(weapon7);
											MyWeapon weapon8("����� ������� ", 2, 2, 24, 4, -40, -40, 18);   weapon_list.push_back(weapon8);
											break;
										}
									}
									break;
								}
								case 2:
								{
									switch (trader_level)
									{
									case 0:
										{
											MyShield shield0("������ ������    ", 4, -5, 0, 8);      shield_list.push_back(shield0); shield0.~MyShield();
											MyShield shield1("�������� �����. ���", 6, -10, -5, 10); shield_list.push_back(shield1); shield1.~MyShield();
											MyShield shield2("������ �����. ���", 8, -20, -10, 12);  shield_list.push_back(shield2); shield2.~MyShield();
											break;
										}
										case 1:
										{
											MyShield shield0("������ ������   ", 4, -5, 0, 8);        shield_list.push_back(shield0); shield0.~MyShield();
											MyShield shield1("������ �����. ���", 8, -20, -10, 12);  shield_list.push_back(shield1); shield1.~MyShield();
											MyShield shield2("������� ������  ", 5, 5, 0, 10);       shield_list.push_back(shield2); shield2.~MyShield();
											MyShield shield3("����� ������ ���", 10, -5, 0, 20);     shield_list.push_back(shield3); shield3.~MyShield();
											MyShield shield4("������� ���     ", 8, 0, 5, 25);       shield_list.push_back(shield4); shield4.~MyShield();

											break;
										}
									}
									break;
								}
								case 0:
								{
									shield_list.clear();
									weapon_list.clear();
									break;
								}
								default: cout << "��������: ��, �� ���-�� �������?" << endl; _getch(); continue;
							}

							
							while (true)
							{
								system("cls");
								cout << "�������� �������, ������� ������ ���������: " << endl << endl;
								switch (choice)
								{
									case 1:
									{
										for (int i = 0; i < weapon_list.size(); i++)
										{
											cout << i + 1 << ")" << weapon_list[i].weapon_name << "\t-- ���������: " << weapon_list[i].weapon_cost * 3 << endl;
										}
										break;
									}
									case 2:
									{
										for (int i = 0; i < shield_list.size(); i++)
										{
											cout << i + 1 << ")" << shield_list[i].shield_name << "\t-- ���������: " << shield_list[i].shield_cost * 3 << endl;
										}
										break;
									}
								}
								
								cout << "0)�����" << endl;
								int choice_ext;
								cout << Hero.name << ": "; cin >> choice_ext;

								if (choice_ext == 0)
								{
									shield_list.clear();
									weapon_list.clear();
									break;
								}

								switch (choice)
								{
									case 1:
									{
										if (choice_ext == 0)
										{
											break;
										}
										else if (choice_ext <= weapon_list.size())
										{
											buy_item(Hero, weapon_list[choice_ext - 1], weapon_list[choice_ext - 1].weapon_cost * 3);
										}
										break;
									}
									case 2:
									{
										if (choice_ext == 0)
										{
											break;
										}
										else if (choice_ext <= shield_list.size())
										{
											buy_item(Hero, shield_list[choice_ext - 1], shield_list[choice_ext - 1].shield_cost * 3);
										}
										break;
									}
								}


							}
							break;
						}
						continue;
					}
					case 3:
					{
						while (true)
						{
							system("cls");
							cout << "1)�������" << endl;
							cout << "2)������" << endl;
							cout << "0)�����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							if (choice == 0)
							{
								break;
							}
							switch (choice)
							{
								case 1:
								{
									switch (trader_level)
									{
										case 0:
										{
											MyArmor armor0("���������� �������", 4, -15, -10, 4);	armor_list.push_back(armor0);
											MyArmor armor1("������� \t", 6, -30, -15, 2);			armor_list.push_back(armor1);
											break;
										}
										case 1:
										{
											MyArmor armor0("������� ��������", 4, -5, -5, 14);		armor_list.push_back(armor0);
											MyArmor armor1("������ ���. �����", 3, 0, 0, 15);		armor_list.push_back(armor1);
											MyArmor armor2("������ �����. �����", 7, -10, -5, 30);	armor_list.push_back(armor2);
											break;
										}
									}
									break;
								}
								case 2:
								{
									switch (trader_level)
									{
										case 0:
										{
											MyArmor armor0("������� \t", 1, 0, 0, 4);			armor_list.push_back(armor0);
											MyArmor armor1("������� ������\t", 2, -5, 0, 4);	armor_list.push_back(armor1);
											break;
										}
										case 1:
										{
											MyArmor armor0("������� \t", 1, 0, 0, 4);			armor_list.push_back(armor0);
											MyArmor armor1("������  \t", 2, 0, 0, 6);			armor_list.push_back(armor1);
											MyArmor armor2("���� ����\t", 1, 10, 10, 15);		armor_list.push_back(armor2);
											break;
										}
									}
									break;
								}
								case 0:
								{
									armor_list.clear();
									break;
								}
								default: cout << "��������: ��, �� ���-�� �������?" << endl; _getch(); continue;
							}


							while (true)
							{
								system("cls");
								cout << "�������� �������, ������� ������ ���������: " << endl << endl;
								for (int i = 0; i < armor_list.size(); i++)
								{
									cout << i + 1 << ")" << armor_list[i].armor_name << "\t-- ���������: " << armor_list[i].armor_cost * 3 << endl;
								}
								cout << "0)�����" << endl;
								cout << Hero.name << ": "; cin >> choice;

								if (choice == 0)
								{
									armor_list.clear();
									break;
								}

								if (choice>0 && choice <= armor_list.size())
								{
									buy_item(Hero, armor_list[choice - 1], armor_list[choice - 1].armor_cost * 3);
								}
							}
							break;
						}
						continue;
					}
				}
			}
			case 2:
			{
				continue;
			}
			case 3:
			{
				items_check(Hero);
				continue;
			}
			case 4:
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
				cout << "��������: ��-��, ��� �� ������������? � �� �������!" << endl;
				_getch();
			}
		}
		break;
	}
}