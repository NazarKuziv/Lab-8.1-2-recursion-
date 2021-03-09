// Lab_8_1-1.cpp
// < Кузів Назар >
// Лабораторна робота № 8.1
// Пошук та заміна символів у літерному рядку
// Варіант 6

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/*Дано літерний рядок, який містить послідовність символів s0, …, sn, … .
 Замінити кожну пару сусідніх букв “SQ” або ”QS” трійкою зірочок “***”.
 */

char* Change(char* dest, const char* s, char* t, int i)
{
	if (s[i + 1] != 0)
	{
		if ((s[i] == 'S' && s[i + 1] == 'Q') || (s[i] == 'Q' && s[i + 1] == 'S'))
		{
			strcat(t, "***");
			return Change(dest, s, t + 3, i + 2);
		}
		else
		{
			*t++ = s[i++];
			*t = '\0';
			return Change(dest, s, t, i);
		}
	}
	else
	{
		*t++ = s[i++];
		*t++ = s[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char s[101]; //Оголошення літерного рядка


	cout << "Enter string:" << endl;
	cin.getline(s, 100);

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2;
	dest2 = Change(dest1, s, dest1, 0);

	cout << endl;
	cout << "string : " << s << endl;
	cout << "Modified string : " << dest2 << endl;

	return 0;
}