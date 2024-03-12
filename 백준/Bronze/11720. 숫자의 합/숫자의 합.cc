#include <iostream>
#include <string>
using namespace std;
int main()
{
	int length;
	cin >> length;
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		char a;
		cin >> a;
		sum += a - 48;
	}
	cout << sum << endl;


}
