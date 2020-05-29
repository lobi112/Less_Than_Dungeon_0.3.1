#include "Header_game.h"

void ActPockets(MyHero& Hero)
{
	system("cls");
	cout << Hero.name << endl;
	cout << "Класс : " << Hero.class_name << endl;
	cout << "Здоровье : " << Hero.HP << "/" << Hero.max_HP << endl << endl;

	cout << "Оружие : " << endl;
	cout << "Урон оружием : " << endl;
	cout << "Броня : " << endl;
	cout << "Уровень защиты брони: " << Hero.armor << endl << endl;
	cout << "Щит : " << endl;
	cout << "Уровень защиты щита : " << Hero.shield << endl << endl;
	cout << "Предметы : " << endl << endl;
	

	//cout << "Зелья лечения : " << Hero.poition << endl;
	//cout << "Отмычки : " << Hero.picklock << endl;
	//cout << "Золото : " << Hero.gold << endl;
	//cout << "Счёт : " << Hero.score << endl << endl;
	system("pause");
	system("cls");
}