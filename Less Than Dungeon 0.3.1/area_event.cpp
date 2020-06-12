#include "Header_game.h"
void area_general_view(int event, int terrain)
{
	switch (terrain)
	{
		case 80:  cout << "�� ���������� ������ �������." << endl; break;
		case 84:  cout << "�� ���������� � ������." << endl; break;
		case 86:  cout << "�� ���������� � �������." << endl; break;
		case 70:  cout << "�� ���������� � ����." << endl; break;
		case 82:  cout << "�� ���������� �� ������." << endl; break;
		case 66:  cout << "�� ���������� �� �����." << endl; break;
		case 114: cout << "�� ���������� � ����." << endl; break;
		case 67:  cout << "�� ���������� � ������." << endl; break;
		case 102: cout << "�� ���������� � �������� ����." << endl; break;
		case 87:  cout << "�� ���������� � ��������� ������ �����." << endl; break;
		case 72:  cout << "�� ���������� � ��������� �������." << endl; break;
		case 115: cout << "�� ���������� ����� �������� �����." << endl; break;
		default:  cout << "�� ���������� � ����������� �����." << endl;
	}
	switch (event%100)
	{
		case 01: cout << "�� ����� ����� ������ ����� � ����� ���� ������." << endl; break;
		case 02: cout << "� ������ ����� ������ ���������." << endl; break;
	}
}

void area_look_around(MyHero& Hero, int event, int terrain)
{
	switch (event % 100)
	{
		case 01:
		{
			cout << "�� ��������� � ������ ��������� ���������." << endl << endl;
		}

	}
}

void area_action(MyHero& Hero, int event, int terrain)
{
	switch (event % 100)
	{
		case 01:
		{
			while (true)
			{
				bool trig_1 = false, trig_2 = false;
				int choice;
				system("cls");
				cout << "1)���������� c �������" << endl;
				cout << "2)��������� ������" << endl;
				cout << "0)�����" << endl;
				cout << Hero.name << ": "; cin >> choice;
				cout << endl;
				switch (choice)
				{
					case 1:
					{
						while (true)
						{
							system("cls");
							cout << "1)�� �� ��� ��������!" << endl;
							cout << "2)����� �����?" << endl;
							if (trig_1) cout << "3)��� �����������?" << endl;
							if (trig_2) cout << "4)�������, ����������, ��� ��� �� �����? ��� ��� ���������?" << endl;
							cout << "0)�����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							cout << endl;
							switch (choice)
							{
								case 1:
								{
									cout << Hero.name << ": " << "�� �� ������� ����������� ��������, ���������." << endl;
									_getch();
									cout << "�����: ��, �������� ������������, ������, ���� �� ����, ��� �� ���������������." << endl;
									cout << "�����: ����� ��� ����������� ?" << endl;
									_getch();
									cout << Hero.name << ": " << "���, ���� �� ����..." << endl;
									_getch();
									cout << Hero.name << ": " << "��, ��� �� �� �� ������, ������ ����� ����������." << endl;
									_getch();
									continue;
								}
								case 2:
								{
									cout << "�����: ����, ��������, ����� �����, ���� �� �������� ������� �������." << endl;
									_getch();
									cout << "��� ���� �� ������������." << endl;
									_getch();
									cout << "� �� ��� ���...\n *������������*" << endl;
									cout << "...��� ��������� �� ����, ���� ���� �����!" << endl;
									_getch();
									trig_1++;
									continue;
								}
								case 3:
								{
									if (trig_1)
									{
										cout << Hero.name << ": " << "��� ��� �� �����?" << endl;
										_getch();
										cout << "�����: ��� ������� ��� �����, ��� �������� ������������� ���������." << endl;
										_getch();
										cout << "���� ����� � �� ����������� ����������� � �������� ����� �� ������, ��� ���������� �����, ��� ��." << endl;
										_getch();
										cout << "����� ���� �������, ��� �� ������ �� �����, ������� ���� ����� �� ����� � ���������." << endl;
										_getch();
										cout << "�� ������, ��� ��� ����������, �� ��� ���� �� ������������ ����������, � ��� ������ ��������� ���� �� ����� ����� �� ��������." << endl;
										_getch();
										trig_2++;
									}
									continue;
								}
								case 4:
								{
									if (trig_2)
									{
										cout << Hero.name << ": " << "���, �������, � ������� ���� ������. ��� �� ���������? ��� ���������� ��� �����?" << endl;
										_getch();
										cout << "�����: � ������� � �� �����������, ��� ����� ����� ���-�� ����������." << endl;
										_getch();
										cout << Hero.name << ": " << "����� ��� ��� �������� ����?" << endl;
										_getch();
										cout << "�����: � ������� �� ���������, �� � ������ �� ���� ������� �� �������������." << endl;
										cout << "������ ���� � ���� ��� �� ����. \n*����������� ������*" << endl;
										_getch();
									}
									continue;
								}
								case 0: 
								{
									break;
								}
								default: cout << Hero.name << ": " << "����� �� ��� ��� �������������?" << endl; _getch(); continue;
							}
							break;
						}
						continue;
					}
					case 2:
					{
						cout << Hero.name << ": " << "��, ��� ��������� ��� �������� �������� �� ������������." << endl;
						cout << "�����������, ��� ��� ������ ������ ���� ���������������." << endl;
						_getch();
						cout << Hero.name << ": " << "������ ���� � ����� ��������..." << endl;
						_getch();
						continue;
					}
					case 0:
					{
						break;
					}
					default: cout << Hero.name << ": " << "����� �� ��� ��� �������������?" << endl; _getch(); continue;
				}
			}
		}

	}
}

