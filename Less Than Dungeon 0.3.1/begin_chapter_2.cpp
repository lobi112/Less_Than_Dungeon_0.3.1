#include "Header_game.h"

void ammunition_check(MyHero& Hero);
void items_check(MyHero& Hero);

void area_general_view(int event, int terrain);
void area_look_around(MyHero& Hero, int event, int terrain);
void area_action(MyHero& Hero, int event, int terrain);

void random_ivent(MyHero& Hero, int event, int terrain);

const unsigned int MAP_SIZE_X = 20;
const unsigned int MAP_SIZE_Y = 20;
const unsigned int START_POSITION_X = 10;
const unsigned int START_POSITION_Y = 13;

inline void location(int loc)
{
	switch (loc)
	{
	case 80:  cout << "Портал" << endl; break;
	case 84:  cout << "Город" << endl; break;
	case 86:  cout << "Деревня" << endl; break;
	case 77:  cout << "Горы" << endl; break;
	case 70:  cout << "Лес" << endl; break;
	case 82:  cout << "Дорога" << endl; break;
	case 66:  cout << "Мост" << endl; break;
	case 114: cout << "Река" << endl; break;
	case 67:  cout << "Лагерь" << endl; break;
	case 83:  cout << "Море" << endl; break;
	case 75:  cout << "Лагерь" << endl; break;
	case 102: cout << "Поле" << endl; break;
	case 72:  cout << "Нагорье" << endl; break;
	case 87:  cout << "Пустошь" << endl; break;
	case 115: cout << "Болото" << endl; break;
	case 119: cout << "Городская стена" << endl; break;
	case 103: cout << "Городские ворота" << endl; break;
	default:  cout << "Неизвестное место!" << endl;
	}
}




void Begin_chapter_2()
{
	system("cls");
	string choice_str; //Для письменных выборов
	int choice;        //Для числовых выборов
	int chance = 99;

	//Создание героя (ДОРАБОТКА)
	cout << "Введите имя героя: ";
	cin >> choice_str;
	MyHero Hero(choice_str, START_POSITION_X, START_POSITION_Y);

	while (1)
	{
		system("cls");
		cout << "Выберите класс героя: " << endl;
		cout << "1)Странник " << endl;
		cout << "2)Воин " << endl;
		cout << "3)Берсерк " << endl;
		cout << "4)Вор " << endl;
		cout << "5)Дворянин " << endl;
		cout << "6)Нищий " << endl;
		cout << "Выбор: ";
		cin >> choice;

		if ((choice > 6) or (choice < 1))
		{
			cout << "Может всё-таки сделаете выбор?" << endl;
			_getch();
			continue;
		}
		Hero.Class_choice(choice);
		break;
	}
	Hero.refresh();

	MyWeapon weapon1("Меч     \t", 1, 0, 10, 2, 5, 5, 20);
	MyWeapon weapon2("Секира  \t", 2, 2, 25, 5,-10,-10, 15);
	MyShield shield1("Баклер  \t", 8, 5, 0, 10);
	MyShield shield2("Скутум  \t", 14, -10, -5, 50);
	MyArmor  armor1 ("Кож. Броня      ", 6, 0, 5, 30);
	MyArmor  armor2 ("Куртка  \t", 2, 0, 5, 10);

	Hero.item[0].create_item(weapon1);
	Hero.item[1].create_item(weapon2);
	Hero.item[2].create_item(shield1);
	Hero.item[3].create_item(shield2);
	Hero.item[4].create_item(armor1);
	Hero.item[5].create_item(armor2);


	//Загрузка карты
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


	//Основная часть
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
			cout << "Погибель настигла вас, вы ушли во тьму..." << endl;
			system("pause");
			break;
		}
		
		while (true)
		{
			system("cls");

			//Первая информация о месте
			area_general_view(map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));

			cout << endl;
			cout << "Север:  ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]));
			cout << "Воcток: ";	location(static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]));
			cout << "Запад:  ";	location(static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]));
			cout << "Юг:     ";	location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]));
			cout << endl;
			cout << Hero.name << ": Что теперь?" << endl << endl;
			cout << "1)Движение" << endl;
			cout << "2)Осмотреться" <<endl;
			cout << "3)Действия" << endl;
			cout << "4)Инвентарь" << endl;
			cout << "5)Экипировка" << endl;	
			cout << "0)Сдаться" << endl;
			cout << Hero.name << ": "; cin >> choice;
			switch (choice)
			{
				//Движение
				case 1: 
				{
					while (true) 
					{
						system("cls");
						cout << Hero.name << ": В каком направлении?" << endl << endl;
						cout << "1)Север:  "; location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y - 1]));
						cout << "2)Восток: "; location(static_cast<int>(map_terrain[Hero.position_x + 1][Hero.position_y]));
						cout << "3)Запад:  "; location(static_cast<int>(map_terrain[Hero.position_x - 1][Hero.position_y]));
						cout << "4)Юг:     "; location(static_cast<int>(map_terrain[Hero.position_x][Hero.position_y + 1]));
						cout << "0)Отмена" << endl;
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
							case 77: cout << Hero.name << ": Через эти горы мне не перебраться." << endl;                      _getch(); continue;
							case 83: cout << Hero.name << ": С такими волнами я и на 10 метров от берега не отплыву!" << endl; _getch(); continue;
							case 114:cout << Hero.name << ": В реку лезть не стоит, течение очень быстрое." << endl;           _getch(); continue;
							default:
								switch (choice)
								{
									case 0:	break;
									case 1: Hero.position_y -= 1; break;
									case 2: Hero.position_x += 1; break;
									case 3: Hero.position_x -= 1; break;
									case 4: Hero.position_y += 1; break;
									default: cout << Hero.name << "Зовёт дорога нас вперёд, в заманчивую даль..." << endl; _getch(); continue;
								}
						}
						break;
					}

					break;
				}

				//Осмотреться
				case 2:
				{
					area_look_around(Hero, map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));
					continue;
				}

				//Действия в данном месте
				case 3:
				{
					area_action(Hero, map_event[Hero.position_x][Hero.position_y], static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]));
					continue;
				}

				//Инвентарь
				case 4:
				{
					items_check(Hero);
					continue;
				}
				//Просмотр и нстройка аммуниции
				case 5:
				{
					ammunition_check(Hero);
					continue;
				}

				default: 
				{
					cout << Hero.name << "Надо бы уже что-то решить." << endl;
					_getch();
					continue;
				}
			}
			break;

		}

	}




	system("pause");
}