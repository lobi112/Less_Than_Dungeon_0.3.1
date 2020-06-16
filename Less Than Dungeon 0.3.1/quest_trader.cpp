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
			cout << "Вы покупаете: ";
			switch (choice)
			{
				case 1: cout << "Зелье Лечения (М)" << endl << endl; break;
				case 2: cout << "Зелье Лечения (Б)" << endl << endl;  break;
				case 3: cout << "Отмычки" << endl << endl;  break;
			}
			cout << "У вас на данный момент: ";
			switch (choice)
			{
				case 1: cout << Hero.heal_potion_s << endl << endl;  break;
				case 2: cout << Hero.heal_potion_l << endl << endl;  break;
				case 3: cout << Hero.picklock << endl << endl;  break;
			}
			cout << "Стоимость единицы : " << cost << endl;
			cout << "Ваши деньги       : " << Hero.gold << endl << endl;
			cout << "N)Купить (Укажите количество)" << endl;
			cout << "0)Назад" << endl;
			cout << Hero.name << ": "; cin >> amount;
			if (amount*cost >= Hero.gold)
			{
				cout << "Торговец: Увы, друг, тебе не хватает на это монет." << endl;
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
				cout << "Вы приобрели " << amount;
				switch (choice)
				{
					case 1: cout << " Зелье Лечения (М)"; break;
					case 2: cout << " Зелье Лечения (Б)";  break;
					case 3: cout << " Отмычки";  break;
				}
				cout << " за " << amount * cost << " монет." << endl;
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
				cout << "Вы встречаете бродячего торговца." << endl;
				cout << "Торговец: Приветствую тебя, путник! Не желаешь чего прикупить?" << endl << endl;
				break;
			}
			case 1:
			{
				cout << "Вы заглядывате в лавку к одному из торговцев." << endl;
				cout << "Торговец: Здравствуй, что тебя интересует?" << endl << endl;
				break;
			}
			case 2:
			{
				cout << "Вы заходити в лавку оружейника." << endl;
				cout << "Торговец: Привет тебе, воин! Выбирай, мечи, топоры, у меня много чего найдётся!" << endl << endl;
				break;
			}
			case 3:
			{
				cout << "Вы заглядываете в лавку бронника." << endl;
				cout << "Торговец: Привет тебе! Что-нибудь подсказать?" << endl << endl;
				break;
			}
		}

		cout << "1)Покажи свои товары" << endl;
		cout << "2)Я бы хотел кое-что продать" << endl;
		cout << "3)Инвентарь" << endl;
		cout << "4)Аммуниция" << endl;
		cout << "0)Уйти" << endl;
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
							cout << "Торговец: Взгляни!" << endl << endl;
							cout << "1)Зелье Лечения (М) : " << heel_potion_s_cost << " монет" << endl;
							cout << "2)Зелье Лечения (Б) : " << heel_potion_l_cost << " монет" << endl;
							cout << "3)Отмычки           : " << picklock_cost << " монет" << endl;
							cout << "0)Назад" << endl;
							cout << Hero.name << ": "; cin >> choice;
							if (choice == 0) break;
							switch (choice)
							{
								case 1: buy_consumables(Hero, traider_type, choice, heel_potion_s_cost); break;
								case 2: buy_consumables(Hero, traider_type, choice, heel_potion_l_cost); break;
								case 3: buy_consumables(Hero, traider_type, choice, picklock_cost); break;
								default: cout << "Торговец: Хм, вы что-то сказали?" << endl; 
							}
						}
						continue;
					}
					case 2:
					{
						while (true)
						{
							system("cls");
							cout << "1)Оружие" << endl;
							cout << "2)Щиты" << endl;
							cout << "0)Назад" << endl;
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
							cout << "1)Доспехи" << endl;
							cout << "2)Одежда" << endl;
							cout << "0)Назад" << endl;
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
				cout << "Торговец: Ха-ха, ещё не определились? Я не тороплю!" << endl;
				_getch();
			}
		}
		break;
	}
}