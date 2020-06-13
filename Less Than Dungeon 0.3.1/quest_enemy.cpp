#include "Header_game.h"
void ammunition_check(MyHero& Hero);
void items_check(MyHero& Hero);

void Hero_attack(MyHero& Hero, MyEnemy& Enemy, int attack_type)
{
	int damage, damage_dif;
	int attack_amount;
	int speed;
	int chance;
	bool dodge = false;
	bool block = false;

	(attack_type == 4) ? attack_amount = 2 : attack_amount = 1;

	switch (attack_type)
	{
		case 1:
		{
			damage     = Hero.damage;
			damage_dif = Hero.damage_dif;
			speed      = Hero.speed;
			break;
		}
		case 2:
		{
			damage     = Hero.damage * 1.5;
			damage_dif = Hero.damage_dif * 1.5;
			speed      = Hero.speed / 2;
			break;
		}
		case 3:
		{
			damage     = Hero.damage / 1.5;
			damage_dif = Hero.damage_dif /1.5;
			speed      = Hero.speed * 2;
			break;
		}
		case 4:
		{
			damage     = Hero.damage;
			damage_dif = Hero.damage_dif;
			speed      = Hero.speed*0.7;
			break;
		}
	}

	for (int i = 1; i < attack_amount; i++)
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
						dodge++;
					}
					break;
				}
				case 3:
				{
					if (Enemy.defense_tactic == 2)
					{
						cout << "��������� � �������� ��������� ������� �����." << endl;
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

				
			}

		}
		else
		{
			cout << "�� ������������." << endl;
			_getch();
		}
	}


}

void Enemy_attack()
{

}


void quest_enemy(MyHero& Hero, int enemy_type, int enemy_level)
{
	int chance;
	int choice;
	bool flag = false;
	MyEnemy Enemy(1,1);
	Enemy.HP = 100; //������
	cout << "�� ��� �����";
	cout << "����������� ���������� �� ����� ? (" << " �����)" << endl;
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
			break;
		}
		default:
		{
			cout << "���� �������� �� ����� ����������. � ���!" << endl;
			_getch();
		}
		//������� ���� ���
		while (Enemy.HP > 0 && Hero.HP > 0)
		{
			if (Hero.HP <= 0)
			{
				break;
			}
			while (flag == false)
			{
				system("cls");
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
						while(true) 
						{

							system("cls");
							cout << "1) ������� �����" << endl;
							cout << "2) ������ �����." << endl;
							cout << "3) ������� �����." << endl;
							cout << "4) ��� �����." << endl;
							cout << "0) �����" << endl;
							cout << Hero.name << ": "; cin >> choice;
							switch (choice)
							{
								case 1:
								{
									Hero_attack(Hero, Enemy, 1);
								}
								case 2:
								{
									if (( Hero.current_item_right_hand.weapon_style != 2) && (Hero.current_item_left_hand.weapon_style != 2) && (Hero.current_item_two_handed.weapon_style != 2))
									{
										cout << "��� ���������� ������ ����� ���������� ��������������� ������!" << endl;
										_getch();
										continue;
									}
									cout << "�� ��������� ������ �����." << endl;
									Hero_attack(Hero, Enemy, 2);
									_getch();
									flag = 0;
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
									cout << "�� ��������� ������� �����." << endl;
									Hero_attack(Hero, Enemy, 3);
									_getch();
									flag = 0;
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
									cout << "�� ��������� ������� �����." << endl;
									Hero_attack(Hero, Enemy, 4);
									_getch();
									flag = 0;
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
								break;
							}
							break;
						}
						break;
					}
					//������ ��������, ��������, �����
					case 2:
					{

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
						ammunition_check(Hero);
						continue;
					}
					case 0:
					{
						continue;
					}
					default:
					{
						cout << Hero.name << ": ������ �������." << endl;
						continue;
					}
				}
			}
			//��� ����������




		}

	}
}