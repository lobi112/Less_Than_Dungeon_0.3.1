#include "Header_game.h"

void buy_items()
{

}


void quest_traider(int traider_type, int trairer_level)
{
	double buy_factor, sale_factor;

	while (true)
	{
		int choice;
		system("cls");
		switch (traider_type)
		{
			case 0: 
			{
				cout << "Вы встречаете бродячего торговца." << endl;
				cout << "Торговец: Приветствую тебя, путник! Не желаешь чего прикупить?" << endl << endl;
			}
		}

		cout << "1)Покажи свои товары" << endl;
		cout << "2)Я бы хотел кое-что продать" << endl;
		cout << "0)Уйти" << endl;

		switch (choice)
		{
			case 1:
			{
				switch (traider_type)
				{
					case 0:
					{
						while (true)
						{
							cout << "1)Зелье Лечения" << endl;
							cout << "2)Сильное зелье Лечения" << endl;
							cout << "3)Отмычки" << endl;
							cout << "0)Назад" << endl;
							break;
						}



					}
					case 1:
				}
			}

		}
	}
}