#include "Header_game.h"
void quest_loot(MyHero& Hero, int loot_level, int loot_type);
void quest_enemy(MyHero& Hero, int enemy_type, int enemy_level);

void random_ivent(MyHero& Hero, int event, int terrain)
{

	switch (event / 100)
	{
		case 1:
		{
			int chance = rand() % 10;
			switch (chance)
			{
				case 1: case 2:	case 3: case 4:	
				{
					cout << "�� ��� ����� ����!" << endl;  _getch();
					switch (terrain)
					{
					case 80:
					case 84:
					case 86:
					case 70:
					{
						quest_enemy(Hero, 1, 1);
						break;
					}
					case 82:
					case 66:
					case 114:
					case 67:
					case 102:
					case 87:
					case 72:
					case 115: break;
					}
					break;
				}
				
				case 5: cout << "�� ��������� ��������!" << endl;  _getch(); break;
				default:				
				{
					chance = rand()% 10;
					switch (chance)
					{
						case 1: case 2:	quest_loot(Hero, 1, 1); break;
						case 3:			quest_loot(Hero, 1, 2); break;
						case 4:			quest_loot(Hero, 1, 3); break;
						default:		quest_loot(Hero, 1, 4); break;
					}
				}
			}
		}
		case 2: 
		{

		}
	}

	/*switch (terrain)
	{
	case 80:  
	case 84:  
	case 86:
	case 70: switch (event / 100)
		     {
			  case 1:
			  {
				int chance = rand() % 2;

			  }
		     }

	case 82:  
	case 66:  
	case 114: 
	case 67:  
	case 102: 
	case 87:  
	case 72:  
	case 115: break;
	}*/

}