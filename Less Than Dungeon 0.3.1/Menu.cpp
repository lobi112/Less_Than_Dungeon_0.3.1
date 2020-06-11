#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <locale>
#include <windows.h>
#include <fstream>
using namespace std;
//void Begin_chapter_1();
void Begin_chapter_2();
void LeaderboardF();

void main()
{

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int controller_menu = 1;

	while (controller_menu != 0)
	{
		system("cls");
		cout << "Меню" << endl; //Главное меню
		cout << "1 - Новая игра" << endl;
		cout << "2 - Таблица лидеров" << endl;
		cout << "3 - Обновления" << endl;
		cout << "0 - Выход из игры" << endl << endl;
		cout << "Ввод :";
		cin >> controller_menu;

		if (controller_menu == 1) //Выбор главы
		{
			system("cls");
			cout << "Выберите главу:" << endl;
			cout << "1 - Глава Первая - Подземелье" << endl;
			cout << "2 - Глава Вторая - Долина" << endl;
			cout << "0 - Назад" << endl;
			cout << "Ввод :";
			cin >> controller_menu;

			switch (controller_menu)
			{
				case 1:                    break; // запуск первой главы
				case 2: Begin_chapter_2(); break; // запуск второй главы
			}
			controller_menu = 1;
			system("cls");
		}
		if (controller_menu == 2) //Таблица лидеров
		{
			system("cls");
			LeaderboardF();
			system("pause");
			system("cls");
		}
		if (controller_menu == 3) //Список обновлений
		{
			system("cls");
			string updates_file_path = "updates.txt";
			ifstream updates_in;

			updates_in.open(updates_file_path);

			string str;
			while (!updates_in.eof())
			{
				getline(updates_in,str);
				cout << str << endl;
			}
			updates_in.close();
			cout << "" << endl;
			system("pause");
			system("cls");
		}

		if (controller_menu == 0) //Выход из программы
		{
			cout << "Удачи в дороге, путник!" << endl;
			system("pause");
			break;
		}

	}
}