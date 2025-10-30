//(Problem): We have a strip of n white squares.
//We want to color some squares of the strip (with black) so that no three white squares are next to each other.

#include <iostream>
using namespace std;

void generate(string current, int n, int num_white, int& Mode)
{
	if (current.length() == n)
	{
		cout << "\033[1;32mMode:\033[0m\033[1;36m" << Mode << "\033[0m\n";
		cout << current << "\n\n";
		Mode++;
		return;
	}

	generate(current + "B", n, 0, Mode);
	if (num_white < 2)
	{
		generate(current + "W", n, num_white + 1, Mode);
	}
}

int main()
{
	int n;
	while (true)
	{
		int Mode = 1;
		cout << "\033c\033[1;32mEnter the number of squares (n): \033[0m";
		cin >> n;
		cout << "\033[4;3;33m\n****(Different modes of tape)****\033[0m\n\n";
		generate("", n, 0, Mode);
		cout << "\033[1;5;31mPress Enter to continue...\033[0m";
		cin.ignore();
		cin.get();
	}
}