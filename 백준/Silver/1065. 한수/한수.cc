#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

#define MAX 1001

int n;


bool check(int num)
{
	if (num < 100)
		return true;

	int first = num / 100;
	int second = (num / 10) % 10;
	int third = num % 10;


	return (second - first) == (third - second);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (check(i))
		{
			count++;
		}
	}
	cout << count;
	return 0;
}