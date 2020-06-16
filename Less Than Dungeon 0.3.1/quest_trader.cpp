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
			if (amount*cost >= Hero.gold)
			{
				cout << "��������: ���, ����, ���� �� ������� �� ��� �����." << endl;
				_getch();
				break;
			}
			if (amount > 0)
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
				break;
			}
			break;
		}
	}
}

void buy_item(int traider_type, int trairer_level, int choice)
{

}


void quest_traider(MyHero& Hero, int traider_type, int trairer_level)
{
	double buy_factor = 1, sale_factor = 0.8;
	int choice = 0;

	int heel_potion_s_cost = 0;
	int heel_potion_l_cost = 0;
	int picklock_cost = 0;

	switch (traider_type)
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
		switch (traider_type)
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
		cout << "2)� �� ����� ���-��� �������" << endl;
		cout << "3)���������" << endl;
		cout << "4)���������" << endl;
		cout << "0)����" << endl;
		cout << Hero.name << ": "; cin >> choice;
		switch (choice)
		{
			case 1:
			{
				switch (traider_type)
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
								case 1: buy_consumables(Hero, traider_type, choice, heel_potion_s_cost); break;
								case 2: buy_consumables(Hero, traider_type, choice, heel_potion_l_cost); break;
								case 3: buy_consumables(Hero, traider_type, choice, picklock_cost); break;
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
							cout << "1)������" << endl;
							cout << "2)����" << endl;
							cout << "0)�����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							if (choice == 0) break;

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
							if(choice == 0) break;
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