#include "Header_game.h"
void event_general_view(int event, int terrain)
{
	switch (terrain)
	{
		case 80:  cout << "�� ���������� ������ �������." << endl; break;
		case 84:  cout << "�� ���������� � ������." << endl; break;
		case 86:  cout << "�� ���������� � �������." << endl; break;
		case 70:  cout << "�� ���������� � ����." << endl; break;
		case 82:  cout << "�� ���������� �� ������." << endl; break;
		case 66:  cout << "�� ���������� �� �����." << endl; break;
		case 114: cout << "�� ���������� � ����." << endl; break;
		case 67:  cout << "�� ���������� � ������." << endl; break;
		case 102: cout << "�� ���������� � �������� ����." << endl; break;
		case 87:  cout << "�� ���������� � ��������� ������ �����." << endl; break;
		case 72:  cout << "�� ���������� � ��������� �������." << endl; break;
		case 115: cout << "�� ���������� ����� �������� �����." << endl; break;
		default:  cout << "�� ���������� � ����������� �����." << endl;
	}

	switch (event)
	{
		case 001: cout << "�� ����� ����� ������ ����� � ����� ���� ������." << endl; break;
		case 002: cout << "� ������ ����� ������ ���������." << endl; break;
	}

}

