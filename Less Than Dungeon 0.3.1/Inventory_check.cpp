#include "Header_game.h"

bool ammunition_check(MyHero& Hero, bool in_fight)
{
	int choice;
	bool change = false;

	while (true) {
		system("cls");
		cout << "��������  : " << Hero.HP << "/" << Hero.max_HP << endl << endl;
		cout << "����      : " << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif; if (Hero.damage != Hero.base_damage) cout << " (������� ��������: " << Hero.base_damage - Hero.base_damage_dif << "-" << Hero.base_damage + Hero.base_damage_dif << " )"; cout << endl << endl;
		cout << "����      : " << Hero.shield; if (Hero.shield != Hero.base_shield) cout << " (������� �������� : " << Hero.base_shield << " )"; cout << endl << endl;
		cout << "��������� : " << Hero.dodge;  if (Hero.dodge != Hero.base_dodge) cout << " (������� �������� : " << Hero.base_dodge << " )"; cout << endl << endl;
		cout << "��������  : " << Hero.speed;  if (Hero.speed != Hero.base_speed) cout << " (������� �������� : " << Hero.base_speed << " )"; cout << endl << endl;

		if (Hero.current_item_right_hand.item_type == 1)
		{
			cout << "������ � ������ ���� : " << Hero.current_item_right_hand.weapon_name << endl;
			cout << "���� ������� : " << (Hero.current_item_right_hand.weapon_damage - Hero.current_item_right_hand.weapon_damage_dif) << "-" << (Hero.current_item_right_hand.weapon_damage + Hero.current_item_right_hand.weapon_damage_dif) << endl;
			cout << "��������� : "; if (Hero.current_item_right_hand.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_right_hand.weapon_dodge << endl;
			cout << "�������� : "; if (Hero.current_item_right_hand.weapon_speed >= 0) { cout << "+"; } cout << Hero.current_item_right_hand.weapon_speed << endl << endl;
		}
		if (Hero.current_item_left_hand.item_type == 1)
		{
			cout << "������ � ����� ���� : " << Hero.current_item_left_hand.weapon_name << endl;
			cout << "���� ������� : " << (Hero.current_item_left_hand.weapon_damage - Hero.current_item_left_hand.weapon_damage_dif) << "-" << (Hero.current_item_left_hand.weapon_damage + Hero.current_item_left_hand.weapon_damage_dif) << endl;
			cout << "��������� : "; if (Hero.current_item_left_hand.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.weapon_dodge << endl;
			cout << "�������� : "; if (Hero.current_item_left_hand.weapon_speed >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.weapon_speed << endl << endl;
		}
		else if (Hero.current_item_left_hand.item_type == 3)
		{
			cout << "��� : " << Hero.current_item_left_hand.shield_name << endl;
			cout << "������ ���� : " << Hero.current_item_left_hand.shield_block << endl;
			cout << "��������� : "; if (Hero.current_item_left_hand.shield_dodge >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.shield_dodge << endl;
			cout << "�������� : "; if (Hero.current_item_left_hand.shield_speed >= 0) { cout << "+"; } cout << Hero.current_item_left_hand.shield_speed << endl << endl;
		}
		if (Hero.current_item_two_handed.item_type == 2)
		{
			cout << "������ � ���� ����� : " << Hero.current_item_two_handed.weapon_name << endl;
			cout << "���� ������� : " << (Hero.current_item_two_handed.weapon_damage - Hero.current_item_two_handed.weapon_damage_dif) << "-" << (Hero.current_item_two_handed.weapon_damage + Hero.current_item_two_handed.weapon_damage_dif) << endl;
			cout << "��������� : "; if (Hero.current_item_two_handed.weapon_dodge >= 0) { cout << "+"; } cout << Hero.current_item_two_handed.weapon_dodge << endl;
			cout << "�������� : "; if (Hero.current_item_two_handed.weapon_speed >= 0) { cout << "+"; } cout << Hero.current_item_two_handed.weapon_speed << endl << endl;
		}
		if (Hero.current_armor.item_type == 4)
		{
			cout << "����� : " << Hero.current_armor.armor_name << endl;
			cout << "������ ����� : " << Hero.current_armor.armor_block << endl;
			cout << "��������� : "; if (Hero.current_armor.armor_dodge >= 0) { cout << "+"; } cout << Hero.current_armor.armor_dodge << endl << endl;
			cout << "�������� : "; if (Hero.current_armor.armor_speed >= 0) { cout << "+"; } cout << Hero.current_armor.armor_speed << endl << endl;
		}

		cout << "1)�������� ������� � ������ ����." << endl;
		cout << "2)�������� ������� � ����� ����." << endl;
		cout << "3)����� ��������� �������." << endl;
		cout << "4)�������� �����." << endl;
		cout << "5)��������� �������." << endl;
		cout << "0)�����." << endl;
		cout << Hero.name << ": ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				vector <int> position;

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1 && !Hero.item[i].in_use)
					{
						position.push_back(i);
					}
				}

				while (true)
				{
					system("cls");
					cout << "���������� ������ � ������� � ������� :" << endl;
					cout << "1)����� ������� �������" << endl;

					for (int i = 0; i < position.size(); i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)�����" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > position.size() + 1))
					{
						cout << Hero.name << "� �� ������ �� �������, ������" <<  endl;
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
							change = true;
							break;
						}
						else
						{
							cout << Hero.name << ": � ����� ����� ������ ���!" << endl;
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
					change = true;
					break;
				}

				continue;
			}
			case 2:
			{

				vector <int> position;

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1 && !Hero.item[i].in_use)
					{
						position.push_back(i);
					}
				}

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 3 && !Hero.item[i].in_use)
					{
						position.push_back(i);
					}
				}

				while (true)
				{
					system("cls");
					cout << "�������� � ������� :" << endl << endl;
					cout << "1)����� ������� �������" << endl;
					for (int i = 0; i < position.size(); i++)
					{
						switch (Hero.item[position[i]].item_type)
						{
							case 1: cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl; break;
							case 3: cout << i + 2 << ")" << Hero.item[position[i]].shield_name << endl; break;
						}
					}

					cout << "0)�����" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > position.size() +1))
					{
						cout << Hero.name << "� �� ������, ������" << endl;
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
							change = true;
							break;
						}
						else
						{
							cout << Hero.name << ": � ����� ����� ������ ���!" << endl;
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
					change = true;
					break;
				}

				continue;
			}

			case 3:
			{

				vector <int> position;

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 2 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}

				while (true)
				{
					system("cls");
					cout << "��������� ������ � ������� :" << endl;
					cout << "1)����� ������� �������" << endl;
					for (int i = 0; i < position.size(); i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].weapon_name << endl;
					}

					cout << "0)�����" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > position.size() + 1))
					{
						cout << Hero.name << "� �� ������ �� �������, ������" << endl;
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
							change = true;
							break;
						}
						else
						{
							cout << Hero.name << ": � ����� ����� ������ ���!" << endl;
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
					change = true;
					break;
				}

				continue;
			}
			case 4:
			{
				if (in_fight)
				{
					cout << "�� ����� ��� ������ �������� �����." << endl;
					_getch();
					continue;
				}

				vector <int> position;

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 4 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}

				while (true)
				{
					system("cls");
					cout << "������/����� � ������� :" << endl;
					cout << "1)����� ������� �������" << endl;
					for (int i = 0; i < position.size(); i++)
					{
						cout << i + 2 << ")" << Hero.item[position[i]].armor_name << endl;
					}

					cout << "0)�����" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice > position.size() + 1))
					{
						cout << Hero.name << "� �� ������ �� �������, ������" << endl;
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
							cout << Hero.name << ": � ����� ����� ������ ���!" << endl;
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

				continue;
			}
			case 5:
			{
				if (in_fight)
				{
					cout << "�� ����� ��� ������ ����������� ��������." << endl;
					_getch();
					continue;
				}

				vector <int> position;

				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 1 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 2 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 3 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}
				for (int i = 0; i < Hero.inventory_size; i++)
				{
					if (Hero.item[i].item_type == 4 && Hero.item[i].in_use == 0)
					{
						position.push_back(i);
					}
				}

				while (true)
				{
					system("cls");
					cout << "�������� � ������� :" << endl << endl;
					for (int i = 0; i < position.size(); i++)
					{
						switch (Hero.item[position[i]].item_type)
						{
						case 1: case 2: cout << i + 1 << ")" << Hero.item[position[i]].weapon_name << endl; break;
						case 3:			cout << i + 1 << ")" << Hero.item[position[i]].shield_name << endl; break;
						case 4:			cout << i + 1 << ")" << Hero.item[position[i]].armor_name  << endl; break;
						}
					}

					cout << "0)�����" << endl;
					cout << Hero.name << ": ";
					cin >> choice;
					if ((choice < 0) || (choice >= position.size() + 1))
					{
						cout << Hero.name << "� �� ������, ������" << endl;
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
				continue;
			}
			case 0:
			{
				break;
			}
		}
		break;
	}

	return change;
}

void items_check(MyHero& Hero)
{
	system("cls");
	cout << Hero.name << endl;
	cout << "����� : " << Hero.class_name << endl;
	cout << "�������� : " << Hero.HP << "/" << Hero.max_HP << endl << endl;	

	cout << "������            : " << Hero.gold << endl;
	cout << "����� ������� (�) : " << Hero.heal_potion_s << endl;
	cout << "����� ������� (�) : " << Hero.heal_potion_l << endl;
	cout << "�������           : " << Hero.picklock << endl << endl;

	cout << "����� ��� ��������� : " << "( " << Hero.item_amount(); cout << "/" << Hero.inventory_size << " )" << endl << endl;
	cout << "������ :" << endl;
	cout << "�������� :\t\t" << "��� :\t\t" <<"����� : \t" << "���� :\t" << "�������� :\t" << "��������� :\t" << "���� :" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if ((Hero.item[i].item_type == 1) || (Hero.item[i].item_type == 2))
		{
			cout << Hero.item[i].weapon_name << "\t";
			(Hero.item[i].item_type == 1) ? cout << "����������\t" : cout << "���������\t";
			switch (Hero.item[i].weapon_style)
			{
				case 0: cout << "������� \t"; break;
				case 1: cout << "������� \t"; break;
				case 2: cout << "������ \t"; break;
			}
			
			cout << (Hero.item[i].weapon_damage - Hero.item[i].weapon_damage_dif) << "-" << (Hero.item[i].weapon_damage + Hero.item[i].weapon_damage_dif) << "\t";
			if (Hero.item[i].weapon_speed >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_speed << "\t\t";
			if (Hero.item[i].weapon_dodge >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].weapon_dodge << "\t\t";
			cout << Hero.item[i].weapon_cost  << "\t" << endl << endl;
		}
		
	}
	cout << endl;
	cout << "������/������� :" << endl;
	cout << "�������� :\t\t" << "������ :\t" << "�������� :\t" << "��������� :\t" << "���� :\t" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 4)
		{
			cout << Hero.item[i].armor_name << "\t";
			cout << Hero.item[i].armor_block << "\t\t";
			if (Hero.item[i].armor_speed >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].armor_speed << "\t\t";
			if (Hero.item[i].armor_dodge >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].armor_dodge << "\t\t";
			cout << Hero.item[i].armor_cost << "\t" << endl << endl;
		}
	}
	cout << endl;
	cout << "���� :" << endl;
	cout << "�������� :\t\t" << "���� :\t\t" << "�������� :\t" << "��������� :\t" << "���� :\t" << endl << endl;
	for (int i = 0; i < Hero.inventory_size; i++)
	{
		if (Hero.item[i].item_type == 3)
		{
			cout << Hero.item[i].shield_name << "\t";
			cout << Hero.item[i].shield_block << "\t\t";
			if (Hero.item[i].shield_speed >= 0)
			{
				cout << "+";
			}
			cout << Hero.item[i].shield_speed << "\t\t";
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