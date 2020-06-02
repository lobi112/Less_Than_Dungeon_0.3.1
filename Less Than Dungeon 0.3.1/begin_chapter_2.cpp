#include "Header_game.h"

void ammunition_check(MyHero& Hero);
void items_check(MyHero& Hero);

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

	//Создание героя (ДОРАБОТКА)
	cout << "Введите имя героя: ";
	cin >> choice_str;
	cout << choice_str;
	_getch();
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

	MyWeapon weapon1("Меч", 1, 10, 2, 5, 5, 20);
	MyWeapon weapon2("Секира", 2, 25, 5,-10,-10, 15);
	Hero.item[0].create_item(weapon1);
	Hero.item[1].create_item(weapon2);



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

			cout << map_terrain[j][i] << "  ";

		}
		cout << endl;
	}
	_getch();
	map_terrain_out.close();
	map_event_out.close();


	//Основная часть
	while (true)
	{
		

		if (Hero.HP < 0)
		{
			cout << "Погибель настигла вас, вы ушли во тьму..." << endl;
			system("pause");
			break;
		}
		
		while (true)
		{
			system("cls");

			switch (static_cast<int>(map_terrain[Hero.position_x][Hero.position_y]))
			{
				case 80:  cout << "Вы находитесь вблизи Портала." << endl; break;
				case 84:  cout << "Вы находитесь в городе." << endl; break;
				case 86:  cout << "Вы находитесь в деревне." << endl; break;
				case 70:  cout << "Вы находитесь в лесу." << endl; break;
				case 82:  cout << "Вы находитесь на дороге." << endl; break;
				case 66:  cout << "Вы находитесь на мосту." << endl; break;
				case 114: cout << "Вы находитесь в реке." << endl; break;
				case 67:  cout << "Вы находитесь в лагере." << endl; break;
				case 102: cout << "Вы находитесь в открытом поле." << endl; break;
				case 87:  cout << "Вы находитесь в пустынном гиблом месте." << endl; break;
				case 72:  cout << "Вы находитесь в скалистом нагорье." << endl; break;
				case 115: cout << "Вы находитесь среди болотных топей." << endl; break;
				default:  cout << "Вы находитесь в неизвестном месте." << endl;
			}


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
			cout << "6)Информация о герое" << endl;
			cout << "0)Сдаться" << endl;
			cout << Hero.name << ": ";
			cin >> choice;
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
									default: cout << Hero.name << "Завёт дорога нас вперёд, в заманчивую даль..." << endl; _getch(); continue;
								}
						}
						break;
					}

					break;
				}

				//Осмотреться
				case 2:
				{
					break;
				}

				//Действия в данном месте
				case 3:
				{
					break;
				}

				//Просмотр и настройка аммуниции
				case 4:
				{
					items_check(Hero);
					break;
				}

				case 5:
				{
					ammunition_check(Hero);
					break;
				}

				case 6:
				{
					break;
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