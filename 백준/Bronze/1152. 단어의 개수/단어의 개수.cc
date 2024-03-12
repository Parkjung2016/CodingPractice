#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')result++;
	}
	if (str[0] == ' ')result--;
	if (str.back() == ' ')result--;
	cout << result + 1 << endl;
}
