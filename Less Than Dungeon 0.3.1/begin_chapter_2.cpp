#include "Header_game.h"

bool ammunition_check(MyHero& Hero, bool in_fight);
void items_check(MyHero& Hero);

void area_general_view(int event, int terrain);
void area_look_around(MyHero& Hero, int event, int terrain);
void area_action(MyHero& Hero, int event, int terrain);

void random_ivent(MyHero& Hero, int event, int terrain);
void quest_enemy(MyHero& Hero, int enemy_type, int enemy_ind);

const unsigned int MAP_SIZE_X = 20;
const unsigned int MAP_SIZE_Y = 20;
const unsigned int START_POSITION_X = 10;
const unsigned int START_POSITION_Y = 13;

inline void location(int loc)
{
	switch (loc)
	{
	case 80:  cout << "������" << endl; break;
	case 84:  cout << "�����" << endl; break;
	case 86:  cout << "�������" << endl; break;
	case 77:  cout << "����" << endl; break;
	case 70:  cout << "���" << endl; break;
	case 82:  cout << "������" << endl; break;
	case 66:  cout << "����" << endl; break;
	case 114: cout << "����" << endl; break;
	case 67:  cout << "������" << endl; break;
	case 83:  cout << "����" << endl; break;
	case 75:  cout << "������" << endl; break;
	case 102: cout << "����" << endl; break;
	case 72:  cout << "�������" << endl; break;
	case 87:  cout << "�������" << endl; break;
	case 115: cout << "������" << endl; break;
	case 119: cout << "��������� �����" << endl; break;
	case 103: cout << "��������� ������" << endl; break;
	default:  cout << "����������� �����!" << endl;
	}
}




void Begin_chapter_2()
{
	system("cls");
	string choice_str; //��� ���������� �������
	int choice;        //��� �������� �������
	int chance = 99;

	//�������� ����� (���������)
	cout << "������� ��� �����: ";
	cin >> choice_str;
	MyHero Hero(choice_str, START_POSITION_X, START_POSITION_Y);

	while (1)
	{
		system("cls");
		cout << "�������� ����� �����: " << endl;
		cout << "1)�������� " << endl;
		cout << "2)���� " << endl;
		cout << "3)������� " << endl;
		cout << "4)��� " << endl;
		cout << "5)�������� " << endl;
		cout << "6)����� " << endl;
		cout << "�����: ";
		cin >> choice;

		if ((choice > 6) or (choice < 1))
		{
			cout << "����� ��-���� �������� �����?" << endl;
			_getch();
			continue;
		}
		Hero.Class_choice(choice);
		break;
	}
	Hero.refresh();

	MyWeapon weapon1("���     \t", 1, 0, 10, 2, 5, 5, 20);
	MyWeapon weapon2("������  \t", 2, 2, 25, 5,-10,-10, 15);
	MyShield shield1("������  \t", 8, 5, 0, 10);
	MyShield shield2("������  \t", 14, -10, -5, 50);
	MyArmor  armor1 ("���. �����      ", 6, 0, 5, 30);
	MyArmor  armor2 ("������  \t", 2, 0, 5, 10);

	Hero.item[0].create_item(weapon1);
	Hero.item[1].create_item(weapon2);
	Hero.item[2].create_item(shield1);
	Hero.item[3].create_item(shield2);
	Hero.item[4].create_item(armor1);
	Hero.item[5].create_item(armor2);

	quest_enemy(Hero, 0, 2);


	//�������� �����
	char map_terrain[MAP_SIZE_X][MAP_SIZE_Y];
	int  map_event[MAP_SIZE_X][MAP_SIZE_Y];

	string map_event_file_path = "map_event.txt";
	string map_terrain_file_path = "map_terrain.txt";
	

	ifstream map_terrain_out;
	ifstream map_event_out;

	map_terrain_out.open(map_terrain_file_path);
	map_event_out.open(map_event_file_path);

	if (!map_terrain_out.is_open())
	{
		cout << "Error map_terrain opening!" << endl;
	}

	if (!map_event_out.is_open())
	{
		cout << "Error map_event opening!" << endl;
	}

	for (int i = 0; i < MAP_SIZE_Y; i++)
	{
		for (int j = 0; j < MAP_SIZE_Y; j++)
		{
			map_terrain_out >> map_terrain[j][i];
			map_event_out >> map_event[j][i];
		}
		cout << endl;
	}
	map_terrain_out.close();
	map_event_out.close();


	//�������� �����
	while (true)
	{
		chance = rand() % 100;
		switch (map_event[Hero.position_x][Hero.position_y] / 100)
		{
			case 1: if (chance > 5)  break;
			case 2: if (chance > 10) break;
			case 3: if (chance > 20) break;
			case 4: if (chance > 40) break;
			case 5: if (chance > 60) break;
			case 6: if (chance > 80) break;
			default : random_ivent(	Hero, map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y])); break;
		}

		if (Hero.HP < 0)
		{
			cout << "�������� �������� ���, �� ���� �� ����..." << endl;
			system("pause");
			break;
		}
		
		while (true)
		{
			system("cls");

			//������ ���������� � �����
			area_general_view(map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));

			cout << endl;
			cout << "�����:  ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]));
			cout << "��c���: ";	location(static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]));
			cout << "�����:  ";	location(static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]));
			cout << "��:     ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]));
			cout << endl;
			cout << Hero.name << ": ��� ������?" << endl << endl;
			cout << "1)��������" << endl;
			cout << "2)�����������" <<endl;
			cout << "3)��������" << endl;
			cout << "4)���������" << endl;
			cout << "5)����������" << endl;	
			cout << "0)�������" << endl;
			cout << Hero.name << ": "; cin >> choice;
			switch (choice)
			{
				//��������
				case 1: 
				{
					while (true) 
					{
						system("cls");
						cout << Hero.name << ": � ����� �����������?" << endl << endl;
						cout << "1)�����:  "; location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]));
						cout << "2)������: "; location(static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]));
						cout << "3)�����:  "; location(static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]));
						cout << "4)��:     "; location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]));
						cout << "0)������" << endl;
						cout << Hero.name << ": ";
						cin >> choice;
						int path_location=0;
						switch(choice)
						{
							case 1: path_location = static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]); break;
							case 2: path_location = static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]); break;
							case 3: path_location = static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]); break;
							case 4: path_location = static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]); break;
						}

						switch (path_location)
						{
							case 77: cout << Hero.name << ": ����� ��� ���� ��� �� �����������." << endl;                      _getch(); continue;
							case 83: cout << Hero.name << ": � ������ ������� � � �� 10 ������ �� ������ �� �������!" << endl; _getch(); continue;
							case 114:cout << Hero.name << ": � ���� ����� �� �����, ������� ����� �������." << endl;           _getch(); continue;
							default:
								switch (choice)
								{
									case 0:	break;
									case 1: Hero.position_y -= 1; break;
									case 2: Hero.position_x += 1; break;
									case 3: Hero.position_x -= 1; break;
									case 4: Hero.position_y += 1; break;
									default: cout << Hero.name << "���� ������ ��� �����, � ���������� ����..." << endl; _getch(); continue;
								}
						}
						break;
					}

					break;
				}

				//�����������
				case 2:
				{
					area_look_around(Hero, map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));
					continue;
				}

				//�������� � ������ �����
				case 3:
				{
					area_action(Hero, map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));
					continue;
				}

				//���������
				case 4:
				{
					items_check(Hero);
					continue;
				}
				//�������� � �������� ���������
				case 5:
				{
					ammunition_check(Hero, 0);
					continue;
				}

				default: 
				{
					cout << Hero.name << "���� �� ��� ���-�� ������." << endl;
					_getch();
					continue;
				}
			}
			break;

		}

	}




	system("pause");
}