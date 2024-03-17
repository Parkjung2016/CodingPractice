#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int num[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
	}
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		result += num[i] * num[i];
	}
	result %= 10;

	cout << result << endl;
	return 0;
}
