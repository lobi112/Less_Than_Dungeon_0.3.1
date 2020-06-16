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
			cout << "�� ��������� ������� �����." << endl;
			damage     = Hero.damage;
			damage_dif = Hero.damage_dif;
			speed      = Hero.speed;
			break;
		}
		case 2:
		{
			cout << "�� ��������� ������ �����." << endl;
			damage     = int(Hero.damage * 1.5);
			damage_dif = int(Hero.damage_dif * 1.5);
			speed      = int(Hero.speed / 2);
			break;
		}
		case 3:
		{
			cout << "�� ��������� ������� �����." << endl;
			damage     = int(Hero.damage / 1.5);
			damage_dif = int(Hero.damage_dif /1.5);
			speed      = int(Hero.speed * 2);
			break;
		}
		case 4:
		{
			cout << "�� ��������� ������� �����." << endl;
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
							cout << "��������� ���� ���� ������� �����." << endl;
							cout << "�� ������� 0 �����." << endl;
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
						cout << "��������� � �������� ��������� �� ������ �����." << endl;
						cout << "�� ������� 0 �����." << endl;
						_getch();
						dodge++;
					}
					break;
				}
				case 3:
				{
					if (Enemy.defense_tactic == 2)
					{
						cout << "��������� � �������� ��������� ������� �����." << endl;
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
							cout << "��������� ���� ���� ������� ����� �����." << endl;
							cout << "�� ������� 0 �����." << endl;
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
							cout << "��������� ���������." << endl;
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
			cout << "�� ������������." << endl;
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
			cout << "��������� �������� ������� �����." << endl;
			damage = Enemy.damage;
			damage_dif = Enemy.damage_dif;
			speed = Enemy.speed;
			break;
		}
		case 2:
		{
			cout << "��������� �������� ������� �����." << endl;
			damage = int(Enemy.damage * 1.5);
			damage_dif = int(Enemy.damage_dif * 1.5);
			speed = int(Enemy.speed / 2);
			break;
		}
		case 3:
		{
			cout << "��������� �������� ������� �����." << endl;
			damage = int(Enemy.damage / 1.5);
			damage_dif = int(Enemy.damage_dif / 1.5);
			speed = int(Enemy.speed * 2);
			break;
		}
		case 4:
		{
			cout << "��������� �������� ������� �����." << endl;
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
			cout << "1)����������� (����:" << int(Hero.speed*0.8) << ")" << endl;
			cout << "2)����������  (����:" << Hero.dodge << ")" << endl;
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
						cout << "�� ����������." << endl;
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
			cout << "��������� �����������." << endl;
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
	
	cout << "��������  :\t" << Hero.HP << "/" << Hero.max_HP << "\t\t" << "�������� :\t" << Enemy.HP << "/" << Enemy.max_HP << endl << endl;
	cout << "����      :\t" << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << "\t\t" << "����     :\t" << Enemy.damage - Enemy.damage_dif << "-" << Enemy.damage + Enemy.damage_dif << endl << endl;
	cout << "�����     :\t" << Hero.armor  << "\t\t" << "�����     :\t" << Enemy.armor  << endl << endl;
	cout << "����      :\t" << Hero.shield << "\t\t" << "����      :\t" << Enemy.shield << endl << endl;
	cout << "��������� :\t" << Hero.dodge  << "\t\t" /*<< "��������� :\t" << Enemy.dodge*/  << endl << endl;
	cout << "��������  :\t" << Hero.speed  << "\t\t" /*<< "��������  :\t" << Enemy.speed*/  << endl << endl;
	(flag == false) ? cout << "| ��� ����� |" : cout << "| ��� ���������� |"; cout << endl << endl;
}



void quest_enemy(MyHero& Hero, int enemy_type, int enemy_ind)
{
	int chance;
	int choice;
	bool flag = false;
	bool fight_trig = false;
	MyEnemy Enemy(enemy_type, enemy_ind);

	system("cls");
	cout << "�� ��� ����� " << Enemy.name << endl;
	if (Enemy.pay_off_possibility == true)
	{
		cout << "����������� ���������� �� ����� ? (" << Enemy.pay_off_cost << " �����)" << endl;
		cout << "1)��" << endl;
		cout << "2)���" << endl;
		cout << Hero.name << ": ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{

				break;
			}
			case 2:
			{
				fight_trig++;
				break;
			}
			default:
			{
				cout << "���� �������� �� ����� ����������. � ���!" << endl;
				_getch();
			}
		}
	}
	else 
	{
		cout << "��������� ������� ���������������!" << endl;
	}
	
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			fight_trig++;
			break;
		}
		default:
		{
			cout << "���� �������� �� ����� ����������. � ���!" << endl;
			_getch();
		}
	}
		//������� ���� ���
	while (Enemy.HP > 0 && Hero.HP > 0 && fight_trig == 1)
	{
		if (Hero.HP <= 0)
		{
			cout << "�� ��������� ������!" << endl;
			_getch();
			break;
		}

		while (flag == false)
		{
			system("cls");
			battle_info(Hero, Enemy, 0);
			cout << "1)�����" << endl;
			cout << "2)������ ��������" << endl;
			cout << "3)��������� ����������" << endl;
			cout << "4)���������" << endl;
			cout << "5)����������" << endl;
			cout << "0)�������" << endl;
			cout << Hero.name << ": "; cin >> choice;
			switch (choice)
			{
				//�����
				case 1:
				{
					while (true)
					{

						system("cls");
						battle_info(Hero, Enemy, 0);
						cout << "1) ������� ����� ( ����: " << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << ", ��������: " << Hero.speed << " )"<< endl;
						cout << "2) ������ ����� ( ����: " << int(Hero.damage*1.5) - int(Hero.damage_dif*1.5) << "-" << int(Hero.damage*1.5) + int(Hero.damage_dif*1.5) << ", ��������: " << int(Hero.speed/2) << " )" << endl;
						cout << "3) ������� ����� ( ����: " << int(Hero.damage/1.5) - int(Hero.damage_dif/1.5) << "-" << int(Hero.damage/1.5) + int(Hero.damage_dif/1.5) << ", ��������: " << Hero.speed*2 << " )" << endl;
						cout << "4) ��� �����     ( ����: " << Hero.damage - Hero.damage_dif << "-" << Hero.damage + Hero.damage_dif << ", ��������: " << int(Hero.speed*0.7) << " )" << endl;
						cout << "0) �����" << endl << endl;
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
									cout << "��� ���������� ������ ����� ���������� ��������������� ������!" << endl;
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
									cout << "��� ���������� ������� ����� ���������� ��������������� ������!" << endl;
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
									cout << "����� ������ � ���� �����!" << endl;
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
								cout << "��� ������� �� �����������!" << endl;
								_getch();
								continue;
							}
						}
						break;
					}
					break;
				}
				//������ ��������, ��������, �����
				case 2:
				{
					system("cls");
					cout << "1)������ ����� �������� (" << Hero.potion << ")" << endl;

					_getch();
					continue;
				}
				//��������� ����������
				case 3:
				{

					continue;
				}
				//���������
				case 4:
				{
					items_check(Hero);
					continue;
				}
				//���������
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
					cout << Hero.name << ": ������ �������." << endl;
					_getch();
					continue;
				}
			}
		}

		if (Enemy.HP == 0)
		{
			cout << "��������� ���!" << endl;
			_getch();
			break;
		}

		//��� ����������
		while (flag == true)
		{
			system("cls");
			battle_info(Hero, Enemy, 1);

			switch (Enemy.type)
			{
				//����� �����
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
				//�������
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