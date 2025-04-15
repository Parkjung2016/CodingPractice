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

#define MAX 1000001
bool check[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long m, n;
	cin >> m >> n;

	check[0] = check[1] = true;
	for (long long i = 2; i * i <= n; i++)
	{
		if (!check[i])
		{
			for (long long k = i * i; k <= n; k += i)
			{
				check[k] = true;
			}
		}
	}

	for (long long i = m; i <= n; i++)
	{
		if (!check[i])cout << i << "\n";
	}
	return 0;
}