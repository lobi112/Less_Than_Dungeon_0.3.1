#include "Header_game.h"
void event_general_view(int event, int terrain)
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

	switch (event)
	{
		case 001: cout << "На камне сидит чёрный ворон и чешит свои пёрышки." << endl; break;
		case 002: cout << "У дороги стоит старый указатель." << endl; break;
	}

}

