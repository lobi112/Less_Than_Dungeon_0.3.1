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
		cout << "����" << endl; //������� ����
		cout << "1 - ����� ����" << endl;
		cout << "2 - ������� �������" << endl;
		cout << "3 - ����������" << endl;
		cout << "0 - ����� �� ����" << endl << endl;
		cout << "���� :";
		cin >> controller_menu;

		if (controller_menu == 1) //����� �����
		{
			system("cls");
			cout << "�������� �����:" << endl;
			cout << "1 - ����� ������ - ����������" << endl;
			cout << "2 - ����� ������ - ������" << endl;
			cout << "0 - �����" << endl;
			cout << "���� :";
			cin >> controller_menu;

			switch (controller_menu)
			{
				case 1:                    break; // ������ ������ �����
				case 2: Begin_chapter_2(); break; // ������ ������ �����
			}
			controller_menu = 1;
			system("cls");
		}
		if (controller_menu == 2) //������� �������
		{
			system("cls");
			LeaderboardF();
			system("pause");
			system("cls");
		}
		if (controller_menu == 3) //������ ����������
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

		if (controller_menu == 0) //����� �� ���������
		{
			cout << "����� � ������, ������!" << endl;
			system("pause");
		}

	}
}