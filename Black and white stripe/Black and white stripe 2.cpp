//(Problem): We have a strip of n white squares.
//We want to color some squares of the strip (with black) so that no three white squares are next to each other.

#include <iostream>
#include <Windows.h>
using namespace std;

void status(int& Mode)
{
	cout << "\033[3;36mMode: \033[0m\033[3;33m" << Mode << "\033[0m\n";
	Mode++;
}
void stripe(int n, string current, string W, string B, int& Mode)
{
	if (n > 3)
	{
		stripe(n - 1, current + B, W, B, Mode);
		stripe(n - 2, current + W + B, W, B, Mode);
		stripe(n - 3, current + W + W + B, W, B, Mode);
	}
	else if (n == 1)
	{
		status(Mode);
		cout << current + B << "\n\n";
		status(Mode);
		cout << current + W << "\n\n";
	}
	else if (n == 2)
	{
		status(Mode);
		cout << current + B + B << "\n\n";
		status(Mode);
		cout << current + W + W << "\n\n";
		status(Mode);
		cout << current + B + W << "\n\n";
		status(Mode);
		cout << current + W + B << "\n\n";

	}
	else if (n == 3)
	{
		status(Mode);
		cout << current + B + B + B << "\n\n";
		status(Mode);
		cout << current + W + W + B << "\n\n";
		status(Mode);
		cout << current + B + W + B << "\n\n";
		status(Mode);
		cout << current + W + B + B << "\n\n";
		status(Mode);
		cout << current + B + B + W << "\n\n";
		status(Mode);
		cout << current + B + W + W << "\n\n";
		status(Mode);
		cout << current + W + B + W << "\n\n";
	}
}

int main()
{
	int n;
	while (true)
	{
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		string White = u8"\u25A0";
		string Black = u8"\u25A1";
		int Mode = 1;
		cout << "\033c\033[1;32mEnter the number of squares (n): \033[0m";
		cin >> n;
		cout << "\033[1m=================================\033[0m";
		cout << "\033[3;33m\n****(Different modes of tape)****\033[0m\n\n";
		stripe(n, "", White, Black, Mode);
		cout << "\033[1;3;35mTotal Mode: \033[0m\033[3;32m" << Mode << "\033[0m\n\n";
		cout << "\033[1;5;31mPress Enter to continue...\033[0m";
		cin.ignore();
		cin.get();
	}
}