#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace  std;

char c[] = { 'a','e','i','o','u' };

bool checkChar(char ch)
{
	int chk = 0;
	for (int j = 0; j < 5; j++)
	{
		if (ch == c[j])
		{
			chk++;
		}
	}
	return chk == 0;
}
int main()
{
	while (true)
	{
		string str;
		cin >> str;
		if (str == "end")break;
		int chk = 0;
		for (int i = 0; i < 5; i++)
		{
			if (str.find(c[i]) != string::npos)
			{
				chk++;
			}
		}
		if (chk == 0)
		{
			cout << "<" << str << ">" << " is not acceptable.\n";

			continue;
		}

		if (str.size() == 1)
		{
			cout << "<" << str << ">" << " is acceptable.\n";

			continue;
		}
		bool check = false;
		for (int i = 0; i < str.size() - 2; i++)
		{
			if ((checkChar(str[i]) && checkChar(str[i + 1]) && checkChar(str[i + 2])))
			{
				cout << "<" << str << ">" << " is not acceptable.\n";
				check = true;
				break;
			}

			if ((!checkChar(str[i]) && !checkChar(str[i + 1]) && !checkChar(str[i + 2])))
			{
				cout << "<" << str << ">" << " is not acceptable.\n";
				check = true;
				break;
			}
		}
		if (check) continue;
		check = false;
		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == str[i + 1])
			{
				if (str[i] != 'e' && str[i] != 'o')
				{
					cout << "<" << str << ">" << " is not acceptable.\n";
					check = true;
					break;
				}
			}
		}
		if (check) continue;

		cout << "<" << str << ">" << " is acceptable.\n";

	}
	return 0;
}