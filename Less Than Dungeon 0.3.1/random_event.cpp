#include "Header_game.h"
void quest_loot(MyHero& Hero, int loot_level, int loot_type);
void quest_enemy(MyHero& Hero, int enemy_type, int enemy_level);
void quest_trader(MyHero& Hero, int traider_type, int trairer_level);

void random_ivent(MyHero& Hero, int event, int terrain)
{

	switch (event / 100)
	{
		case 1:
		{
			int chance = rand() % 10;
			switch (chance)
			{
				case 1: case 2:	case 3:
				{
					cout << "На вас напал враг!" << endl;  _getch();
					switch (terrain)
					{
						case 70: case 102://лес, поле
						{
							chance = rand() % 10;
							switch (chance)
							{
								case 0: case 1: case 2: quest_enemy(Hero, 0, 1); break;
								case 3: case 4: case 5: quest_enemy(Hero, 0, 2); break;
								case 6: case 7: quest_enemy(Hero, 0, 3); break;
								case 8: case 9: quest_enemy(Hero, 1, 0); break;
							}
							break;
						}
						case 82: case 67://дорога, лагерь
						{
							chance = rand() % 10;
							switch (chance)
							{
								case 0: case 1:case 2: quest_enemy(Hero, 3, 0); break;
								case 4: quest_enemy(Hero, 3, 1); break;
								default:  quest_enemy(Hero, 0, 0); break;
							}
							break;
						}
						case 87: //гиблая пустошь
						{
							break;
						}
						case 72: //нагорье
						{
							break;
						}
						case 115: 
						{
							break;
						}
					}
					break;
				}

				case 4: case 5: case 6: quest_trader(Hero, 0, 0); break;

				default:
				{
					chance = rand() % 10;
					switch (chance)
					{
						case 1: case 2:	quest_loot(Hero, 1, 1); break;
						case 3:			quest_loot(Hero, 1, 2); break;
						case 4:			quest_loot(Hero, 1, 3); break;
						default:		quest_loot(Hero, 1, 4); break;
					}
				}
			}
			break;
		}
		case 2:
		{
			int chance = rand() % 10;
			switch (chance)
			{
				case 1: case 2:	case 3: case 4: case 5: case 6:
				{
					cout << "На вас напал враг!" << endl;  _getch();
					switch (terrain)
					{
					case 70: case 102://лес, поле
					{
						chance = rand() % 10;
						switch (chance)
						{
							case 0: case 1: case 2: quest_enemy(Hero, 1, 0); break;
							case 3: case 4: case 5: quest_enemy(Hero, 1, 1); break;
							case 6: case 7:  quest_enemy(Hero, 2, 0); break;
							case 8: case 9: quest_enemy(Hero, 2, 1); break;
						}
						break;
					}
					case 82: case 67://дорога, лагерь
					{
						chance = rand() % 10;
						switch (chance)
						{
							case 0: case 1:case 2: case 3: quest_enemy(Hero, 3, 0); break;
							case 4: case 5: quest_enemy(Hero, 3, 1); break;
							default:  quest_enemy(Hero, 0, 2); break;
						}
						break;
					}
					case 87: //гиблая пустошь
					{
						break;
					}
					case 72: //нагорье
					{
						break;
					}
					case 115: break;
					}
					break;
				}

				default:
				{
					chance = rand() % 20;
					switch (chance)
					{
						case 0: case 1: case 2:	quest_loot(Hero, 1, 1); break;
						case 3: case 4: case 5:	quest_loot(Hero, 1, 2); break;
						case 6: case 7: case 8:	quest_loot(Hero, 1, 3); break;
						case 9: case 10: case 11: case 12:	quest_loot(Hero, 1, 4); break;
						case 13: quest_loot(Hero, 1, 4); break;
						case 14: case 15: quest_loot(Hero, 2, 1); break;
						case 16: quest_loot(Hero, 2, 2); break;
						case 17: quest_loot(Hero, 2, 3); break;
						case 18: case 19: quest_loot(Hero, 2, 4); break;
					}
				}
			}
			break;
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