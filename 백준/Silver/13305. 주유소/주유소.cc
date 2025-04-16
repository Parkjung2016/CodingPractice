#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define MAX 100001
using namespace std;

int roadLength[MAX];
int price[MAX];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> roadLength[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	int minValue = INT_MAX;
	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		minValue = min(minValue, price[i]);

		result += (long long)minValue * roadLength[i];

	}

	cout << result;
	return 0;

}
