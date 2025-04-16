#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#define MAX 100001
using namespace std;

long long roadLength[MAX];
long long price[MAX];
int main()
{
	long long n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> roadLength[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	long long minValue = INT_MAX;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		minValue = min(minValue, price[i]);

		result += minValue * roadLength[i];

	}

	cout << result;
	return 0;

}
