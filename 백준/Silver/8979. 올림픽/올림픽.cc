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
	int rank = 1;
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			if (!(v[i].gold == v[i - 1].gold &&
				v[i].silver == v[i - 1].silver &&
				v[i].bronze == v[i - 1].bronze))
			{
				rank = i + 1;
			}
		}

		if (v[i].index == k)
		{
			cout << rank;
		}
	}
	return 0;
}