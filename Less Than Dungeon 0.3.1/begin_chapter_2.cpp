#include "Header_game.h"

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

	//���������� ��������� (���������)
	string inventory_file_path = "inventory.txt";
	
	ofstream inventory_out;
	inventory_out.open(inventory_file_path);

	inventory_out << "w " << 5 << "\n";

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

			cout << map_terrain[j][i] << "  ";

		}
		cout << endl;
	}
	_getch();
	map_terrain_out.close();
	map_event_out.close();


	//�������� �����
	while (true)
	{
		if (Hero.HP < 0)
		{
			cout << "�������� �������� ���, �� ���� �� ����..." << endl;
			system("pause");
			break;
		}
		
		while (true)
		{
			system("cls");

			switch (static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]))
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


			cout << endl;
			cout << "�����:  ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]));
			cout << "��c���: ";	location(static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]));
			cout << "�����:  ";	location(static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]));
			cout << "��:     ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]));
			cout << endl;
			cout << Hero.name << ": ��� ������?" << endl << endl;
			cout << "1)��������" << endl;
			cout << "2)���������" << endl;
			cout << "3)����������" << endl;
			cout << "4)�����" << endl;
			cout << "5)�����������" <<endl;
			cout << "0)�������" << endl;
			cout << Hero.name << ": ";
			cin >> choice;
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

					continue;
				}

				//�������� ���������
				case 2:
				{
				
				}

				//��������� ����������
				case 3:
				{

				}

				//������������� �����
				case 4:
				{

				}

				default: 
				{
					cout << Hero.name << "���� �� ��� ���-�� ������." << endl;
					_getch();
					continue;
				}
			}

		}

	}




	system("pause");
}