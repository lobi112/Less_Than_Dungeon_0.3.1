#include "Header_game.h"
bool ammunition_check(MyHero& Hero, bool in_fight);
void items_check(MyHero& Hero);

void Hero_attack(MyHero& Hero, MyEnemy& Enemy, int attack_type)
{
	int damage, damage_dif;
	int attack_amount = 1;
	int speed;
	int chance;
	bool dodge = false;
	bool block = false;

	(attack_type == 4) ? attack_amount = 2 : attack_amount = 1;

	switch (attack_type)
	{
		case 1:
		{
			cout << "Вы проводите обычную атаку." << endl;
			damage     = Hero.damage;
			damage_dif = Hero.damage_dif;
			speed      = Hero.speed;
			break;
		}
		case 2:
		{
			cout << "Вы проводите тяжёлую атаку." << endl;
			damage     = int(Hero.damage * 1.5);
			damage_dif = int(Hero.damage_dif * 1.5);
			speed      = int(Hero.speed / 2);
			break;
		}
		case 3:
		{
			cout << "Вы проводите быструю атаку." << endl;
			damage     = int(Hero.damage / 1.5);
			damage_dif = int(Hero.damage_dif /1.5);
			speed      = int(Hero.speed * 2);
			break;
		}
		case 4:
		{
			cout << "Вы проводите двойную атаку." << endl;
			damage     = Hero.damage;
			damage_dif = Hero.damage_dif;
			speed      = int(Hero.speed*0.7);
			attack_amount++;
			break;
		}
	}

	for (int i = 0; i < attack_amount; i++)
	{
		chance = rand() % 100;
		if (chance < speed)
		{
			switch (attack_type)
			{
				case 1:
				{
					if (Enemy.defense_tactic == 3)
					{
						chance = rand() % 10;
						if (chance < 6)
						{
							cout << "Противник сбил вашу обычную атаку." << endl;
							cout << "Вы нанесли 0 урона." << endl;
							_getch();
							dodge++;
						}
					}
					break;
				}
				case 2:
				{
					if (Enemy.defense_tactic == 1)
					{
						cout << "Противник с лёгкостью увернулся от тяжёлой атаки." << endl;
						cout << "Вы нанесли 0 урона." << endl;
						_getch();
						dodge++;
					}
					break;
				}
				case 3:
				{
					if (Enemy.defense_tactic == 2)
					{
						cout << "Противник с лёгкостью блокирует быструю атаку." << endl;
						_getch();
						dodge++;
					}
					break;
				}
				case 4:
				{
					if (Enemy.defense_tactic == 4)
					{
						chance = rand() % 10;
						if (chance < 6)
						{
							cout << "Противник сбил вашу двойную атаку атаку." << endl;
							cout << "Вы нанесли 0 урона." << endl;
							dodge++;
						}
					}
					break;
				}
			}

			if (block)
			{
				Enemy.take_damage(damage + (-damage_dif + rand()%(2*damage_dif+1) ), 1);
			}

			if (!dodge && !block)
			{
				chance = rand() % 2;
				switch (chance)
				{
					case 0:
					{
						chance = rand() % 100;
						if (chance < Enemy.speed*0.8)
						{
							Enemy.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 1);
						}
						else 
						{
							Enemy.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 0);
						}
						break;
					}
					case 1:
					{
						chance = rand() % 100;
						if (chance < Enemy.dodge)
						{
							cout << "Противник Увернулся." << endl;
							_getch();
						}
						else
						{
							Enemy.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 0);
						}
						break;
					}
				}
			}
		}
		else
		{
			cout << "Вы промахнулись." << endl;
			_getch();
		}


	}
}

void Enemy_attack(MyHero& Hero, MyEnemy& Enemy, int attack_type)
{
	int choice;

	int damage, damage_dif;
	int attack_amount = 1;
	int speed;
	int chance;
	bool dodge = false;
	bool block = false;

	switch (attack_type)
	{
		case 1:
		{
			cout << "Противник проводит обычную атаку." << endl;
			damage = Enemy.damage;
			damage_dif = Enemy.damage_dif;
			speed = Enemy.speed;
			break;
		}
		case 2:
		{
			cout << "Противник проводит тяжелую атаку." << endl;
			damage = int(Enemy.damage * 1.5);
			damage_dif = int(Enemy.damage_dif * 1.5);
			speed = int(Enemy.speed / 2);
			break;
		}
		case 3:
		{
			cout << "Противник проводит быструю атаку." << endl;
			damage = int(Enemy.damage / 1.5);
			damage_dif = int(Enemy.damage_dif / 1.5);
			speed = int(Enemy.speed * 2);
			break;
		}
		case 4:
		{
			cout << "Противник проводит двойную атаку." << endl;
			damage = Enemy.damage;
			damage_dif = Enemy.damage_dif;
			speed = int(Enemy.speed*0.7);
			attack_amount++;
			break;
		}
	}
	if (Hero.dodge < 0)
	{
		speed += abs(Hero.dodge);
	}
	_getch();

	for (int i = 0; i < attack_amount; i++)
	{
		chance = rand() % 100;
		
		if (chance < speed)
		{
			cout << endl;
			cout << "1)Блокировать (Шанс:" << int(Hero.speed*0.8) << ")" << endl;
			cout << "2)Увернуться  (Шанс:" << Hero.dodge << ")" << endl;
			cout << Hero.name << ": "; cin >> choice;
			cout << endl;
			switch (choice)
			{
				case 1:
				{
					chance = rand() % 100;
					if (chance < Hero.speed*0.8)
					{
						Hero.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 1);
					}
					else
					{
						Hero.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 0);
					}
					break;
				}
				case 2:
				{
					chance = rand() % 100;
					if (chance < Enemy.dodge)
					{
						cout << "Вы Увернулись." << endl;
						_getch();
					}
					else
					{
						Hero.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 0);
					}
					break;
				}
				default:
				{
					Hero.take_damage(damage + (-damage_dif + rand() % (2 * damage_dif + 1)), 0);
					break;
				}
			}
		}
		else
		{
			cout << "Противник промахнулся." << endl;
			_getch();
		}
	}
}

void battle_info(MyHero& Hero, MyEnemy& Enemy, bool flag)
{
	system("cls");
	cout << Hero.name;
	int tabul = 4- Hero.name.length() / 8;
	for (int i = 0; i < tabul; i++) { cout << "\t"; } cout << Enemy.name << endl << endl;
	
	cout << "Здоровье  :\t" << Hero.HP << "/" << Hero.max_HP << "\t\t" << "Здоровье :\t" << Enemy.HP << "/" << Enemy.max_HP << endl << endl;
	cout << "Урон      :\t" << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << "\t\t" << "Урон     :\t" << Enemy.damage - Enemy.damage_dif << "-" << Enemy.damage + Enemy.damage_dif << endl << endl;
	cout << "Броня     :\t" << Hero.armor  << "\t\t" << "Броня     :\t" << Enemy.armor  << endl << endl;
	cout << "Блок      :\t" << Hero.shield << "\t\t" << "Блок      :\t" << Enemy.shield << endl << endl;
	cout << "Уклонение :\t" << Hero.dodge  << "\t\t" /*<< "Уклонение :\t" << Enemy.dodge*/  << endl << endl;
	cout << "Скорость  :\t" << Hero.speed  << "\t\t" /*<< "Скорость  :\t" << Enemy.speed*/  << endl << endl;
	(flag == false) ? cout << "| Ход Героя |" : cout << "| Ход Противника |"; cout << endl << endl;
}



void quest_enemy(MyHero& Hero, int enemy_type, int enemy_ind)
{
	int chance;
	int choice;
	bool flag = false;
	bool fight_trig = true;
	MyEnemy Enemy(enemy_type, enemy_ind);

	system("cls");
	cout << "На вас напал " << Enemy.name << endl;
	if (Enemy.pay_off_possibility == true)
	{
		cout << "Попробовать откупиться от врага ? (" << Enemy.pay_off_cost << " монет)" << endl;
		cout << "Ваши деньги : " << Hero.gold << endl << endl;
		cout << "1)Да" << endl;
		cout << "2)Нет" << endl;
		cout << Hero.name << ": ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				chance = rand() % 100;
				if (Hero.gold < Enemy.pay_off_cost)
				{
					flag = true;
					cout << Hero.name << ": Эх, дырявые мои карманы... Мне не хватает денег!" << endl;
					cout << "Противник атакует." << endl;
					_getch();
					break;
				}
				if (chance < Enemy.pay_off_chance)
				{
					fight_trig = false;
					Hero.gold -= Enemy.pay_off_cost;
					cout << "Вы откуписись, отдав " << Enemy.pay_off_cost;
					switch (Enemy.pay_off_cost%10)
					{
						case 1: cout << " монету" << endl; break;
						case 2: case 3: case 4: cout << " монеты" << endl; break;
						default: cout << " монет" << endl;
					}
					_getch();
				}
				else
				{
					flag = true;
					cout << "Звон монет не переубедил противника, и он атакует!" << endl;
					_getch();
				}
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
				cout << "Враг оказался не таким терпеливым. К бою!" << endl;
				_getch();
			}
		}
	}
	else 
	{
		cout << "Противник атакует незамедлительно!" << endl;
		_getch();
	}



	//Главный цикл боя
	while (Enemy.HP > 0 && Hero.HP > 0 && fight_trig == 1)
	{
		if (Hero.HP <= 0)
		{
			cout << "Вы истекаете кровью!" << endl;
			_getch();
			break;
		}

		while (flag == false)
		{
			system("cls");
			battle_info(Hero, Enemy, 0);
			cout << "1)Атака" << endl;
			cout << "2)Особое действие" << endl;
			cout << "3)Осмотреть противника" << endl;
			cout << "4)Инвентарь" << endl;
			cout << "5)Экипировка" << endl;
			cout << "0)Сбежать" << endl;
			cout << Hero.name << ": "; cin >> choice;
			switch (choice)
			{
				//Атака
				case 1:
				{
					while (true)
					{

						system("cls");
						battle_info(Hero, Enemy, 0);
						cout << "1) Обычная атака ( Урон: " << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << ", Скорость: " << Hero.speed << " )"<< endl;
						cout << "2) Тяжёлая атака ( Урон: " << int(Hero.damage*1.5) - int(Hero.damage_dif*1.5) << "-" << int(Hero.damage*1.5) + int(Hero.damage_dif*1.5) << ", Скорость: " << int(Hero.speed/2) << " )" << endl;
						cout << "3) Быстрая атака ( Урон: " << int(Hero.damage/1.5) - int(Hero.damage_dif/1.5) << "-" << int(Hero.damage/1.5) + int(Hero.damage_dif/1.5) << ", Скорость: " << Hero.speed*2 << " )" << endl;
						cout << "4) Две атаки     ( Урон: " << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << ", Скорость: " << int(Hero.speed*0.7) << " )" << endl;
						cout << "0) Назад" << endl << endl;
						cout << Hero.name << ": "; cin >> choice;
						system("cls");
						battle_info(Hero, Enemy, 0);
						switch (choice)
						{
							case 1:
							{
								Hero_attack(Hero, Enemy, 1);
								flag = true;
								break;
							}
							case 2:
							{
								if ((Hero.current_item_right_hand.weapon_style != 2) && (Hero.current_item_left_hand.weapon_style != 2) && (Hero.current_item_two_handed.weapon_style != 2))
								{
									cout << "Для проведение тяжёлой атаки необходимо соответствующее оружие!" << endl;
									_getch();
									continue;
								}

								Hero_attack(Hero, Enemy, 2);
								flag = true;
								break;

							}
							case 3:
							{
								if ((Hero.current_item_right_hand.weapon_style != 1) && (Hero.current_item_left_hand.weapon_style != 1) && (Hero.current_item_two_handed.weapon_style != 1))
								{
									cout << "Для проведения быстрой атаки необходимо соответствующее оружие!" << endl;
									_getch();
									continue;
								}

								Hero_attack(Hero, Enemy, 3);
								flag = true;
								break;
							}
							case 4:
							{
								if ((Hero.current_item_right_hand.weapon_type != 1) && (Hero.current_item_left_hand.weapon_type != 1))
								{
									cout << "Нужно оружие в двух руках!" << endl;
									_getch();
									continue;
								}
								Hero_attack(Hero, Enemy, 4);
								flag = true;
								break;
							}
							case 0:
							{
								break;
							}
							default:
							{
								cout << "Нет времени на размышление!" << endl;
								_getch();
								continue;
							}
						}
						break;
					}
					break;
				}
				//Особое действие, например, зелье
				case 2:
				{
					system("cls");
					cout << "1)Выпить зелье здоровья (М) (" << Hero.heal_potion_s << ")" << endl;
					cout << "2)Выпить зелье здоровья (Б) (" << Hero.heal_potion_l << ")" << endl;

					_getch();
					continue;
				}
				//Осмотреть противника
				case 3:
				{

					continue;
				}
				//Инвентарь
				case 4:
				{
					items_check(Hero);
					continue;
				}
				//Аммуниция
				case 5:
				{
					bool change = ammunition_check(Hero , 1);
					if (change == true)
					{
						flag = true;
						break;
					}
					else 
					{
						continue;
					}
				
				}
				case 0:
				{
					continue;
				}
				default:
				{
					cout << Hero.name << ": Нельзя медлить." << endl;
					_getch();
					continue;
				}
			}
		}

		if (Enemy.HP == 0)
		{
			cout << "Противник пал!" << endl;
			_getch();
			break;
		}

		//Ход противника
		while (flag == true)
		{
			system("cls");
			battle_info(Hero, Enemy, 1);

			switch (Enemy.type)
			{
				//Дикие звери
				case 0:
				{
					switch (Enemy.attack_tactic)
					{
						case 0:
						{
							Enemy_attack(Hero, Enemy, 1);
							break;
						}
						case 1:
						{
							chance = rand() % 10;
							(chance < 7) ? Enemy_attack(Hero, Enemy, 3) : Enemy_attack(Hero, Enemy, 1);
							break;
						}
						case 2:
						{
							chance = rand() % 2;
							(chance == 0) ? Enemy_attack(Hero, Enemy, 2) : Enemy_attack(Hero, Enemy, 1);
							break;
						}
						default: 
						{
							Enemy_attack(Hero, Enemy, 1);
							break;
						}
					}
					flag = false;
					break;
				}
				//Гоблины
				case 1:
				{
					switch (Enemy.attack_tactic)
					{
						case 1:
						{
							break;
						}
						case 2:
						{
							break;
						}
						default:
						{
							Enemy_attack(Hero, Enemy, 1);
							break;
						}
					}
				}
				flag = false;
				break;
			}
		}
	}
}