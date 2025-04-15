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

int arr[MAX][6];

int countS[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> arr[i][j];
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			for (int k = 1; k <= 5; k++)
			{
				if (arr[i][k] == arr[j][k])
				{
					countS[i]++;
					break;
				}
			}
		}
	}
	int maxCount = 0;
	for (int i = 1; i <= n; i++)
	{
		maxCount = max(maxCount, countS[i]);
	}
	vector<int > v;
	for (int i = 1; i <= n; i++)
	{
		if (maxCount == countS[i])
		{
			v.push_back(i);
		}
	}

	if (v.size() == 1)
		cout << v[0];
	else
	{
		sort(v.begin(), v.end());
		cout << v[0];
	}
	return 0;
}