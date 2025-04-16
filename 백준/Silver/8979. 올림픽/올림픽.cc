#include <iostream>
#include <algorithm>
#include <vector>
using namespace   std;
struct Info
{
	int index;
	int gold;
	int silver;
	int bronze;
};
#define  MAX 1001
Info v[MAX];

bool compare(Info a, Info b)
{
	if (a.gold != b.gold)
		return a.gold > b.gold;
	else if (a.silver != b.silver)
		return a.silver > b.silver;
	else if (a.bronze != b.bronze)
		return a.bronze > b.bronze;
	return false;
}
int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int index, gold, silver, bronze;
		cin >> index >> gold >> silver >> bronze;

		v[i].index = index;
		v[i].bronze = bronze;
		v[i].silver = silver;
		v[i].gold = gold;
	}

	sort(v, v + n, compare);
	for (int i = 0; i < n; i++)
	{
		if (v[i].index == k)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}