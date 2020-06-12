#include "Header_game.h"
void area_general_view(int event, int terrain)
{
	switch (terrain)
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
	switch (event%100)
	{
		case 01: cout << "На камне сидит чёрный ворон и чешет свои пёрышки." << endl; break;
		case 02: cout << "У дороги стоит старый указатель." << endl; break;
	}
}

void area_look_around(MyHero& Hero, int event, int terrain)
{
	switch (event % 100)
	{
		case 01:
		{
			cout << "Вы подходите к своему недавнему знакомому." << endl << endl;
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
				cout << "1)Поговорить c вороном" << endl;
				cout << "2)Осмотреть портал" << endl;
				cout << "0)Назад" << endl;
				cout << Hero.name << ": "; cin >> choice;
				cout << endl;
				switch (choice)
				{
					case 1:
					{
						while (true)
						{
							system("cls");
							cout << "1)Ты всё ещё говоришь!" << endl;
							cout << "2)Какие планы?" << endl;
							if (trig_1) cout << "3)Что посоветуешь?" << endl;
							if (trig_2) cout << "4)Подожди, собственно, что это за место? Как оно называтся?" << endl;
							cout << "0)Назад" << endl;
							cout << Hero.name << ": "; cin >> choice;
							cout << endl;
							switch (choice)
							{
								case 1:
								{
									cout << Hero.name << ": " << "Ты не потерял способность говорить, любопытно." << endl;
									_getch();
									cout << "Ворон: Да, неплохое приобретение, правда, пока не знаю, как им воспользоваться." << endl;
									cout << "Ворон: Может что посоветуешь ?" << endl;
									_getch();
									cout << Hero.name << ": " << "Хмм, даже не знаю..." << endl;
									_getch();
									cout << Hero.name << ": " << "Но, что бы ты не выбрал, оставь пение напоследок." << endl;
									_getch();
									continue;
								}
								case 2:
								{
									cout << "Ворон: Буду, вероятно, ждать здесь, пока не появится желание улететь." << endl;
									_getch();
									cout << "Или пока не проголодаюсь." << endl;
									_getch();
									cout << "А до тех пор...\n *Распушившись*" << endl;
									cout << "...Как мудрейший из птиц, могу дать совет!" << endl;
									_getch();
									trig_1++;
									continue;
								}
								case 3:
								{
									if (trig_1)
									{
										cout << Hero.name << ": " << "Так что за совет?" << endl;
										_getch();
										cout << "Ворон: Мне знакомы эти места, тут довольно недружелюбное окружение." << endl;
										_getch();
										cout << "Тебе лично я бы посоветовал отправиться в каменные гнёзда на севере, там собираются такие, как ты." << endl;
										_getch();
										cout << "Чтобы туда попасть, иди по догоге на север, свернув чуть позже на запад и доберёшься." << endl;
										_getch();
										cout << "Не говорю, что там дружелюбно, но там хотя бы ОтНоСиТеЛьНо дружилюбно, а без острых блестящих штук ты долго здесь не проживёшь." << endl;
										_getch();
										trig_2++;
									}
									continue;
								}
								case 4:
								{
									if (trig_2)
									{
										cout << Hero.name << ": " << "Так, секунду, я упустил один момент. Где мы находимся? Как называется это место?" << endl;
										_getch();
										cout << "Ворон: Я никогда и не задумывался, что место может как-то называться." << endl;
										_getch();
										cout << Hero.name << ": " << "Тогда как его называли люди?" << endl;
										_getch();
										cout << "Ворон: Я никогда не спрашивал, да и вообще со мной никогда не разговаривали." << endl;
										cout << "Голоса ведь у меня ещё не было. \n*РасКАРтисто смеётся*" << endl;
										_getch();
									}
									continue;
								}
								case 0: 
								{
									break;
								}
								default: cout << Hero.name << ": " << "Стоит ли мне тут задерживаться?" << endl; _getch(); continue;
							}
							break;
						}
						continue;
					}
					case 2:
					{
						cout << Hero.name << ": " << "Не, эта развалина уже никакого интереса не представляет." << endl;
						cout << "Удивительно, как она вообще смогла меня телепортировать." << endl;
						_getch();
						cout << Hero.name << ": " << "Хорошо хоть я живым выбрался..." << endl;
						_getch();
						continue;
					}
					case 0:
					{
						break;
					}
					default: cout << Hero.name << ": " << "Стоит ли мне тут задерживаться?" << endl; _getch(); continue;
				}
			}
		}

	}
}

