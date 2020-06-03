#include "Header_game.h"

void LeaderboardF() {
	string line, _name;
	struct Leaderboard arr[50];
	int size = 0, _score;
	ifstream fin("leaderboard.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (!fin.eof()) {
				fin >> arr[size].name;
				fin >> arr[size].score;
				size++;
			}
		}
	}
	else cout << "file doesn't found" << endl;
	fin.close();
	int b, j;

	for (j = 0; j < size - 1; j++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (arr[b + 1].score > arr[b].score)
			{
				_score = arr[b + 1].score;
				_name = arr[b + 1].name;
				arr[b + 1].score = arr[b].score;
				arr[b + 1].name = arr[b].name;
				arr[b].score = _score;
				arr[b].name = _name;
			}
		}
	}
	cout << endl << "Таблица лидеров" << endl;
	for (j = 0; j < size - 1; j++) {
		cout << j + 1 << ". " << arr[j].name << " - " << arr[j].score << endl;
	}
}