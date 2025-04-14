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

#define MAX 15
int dp[MAX][MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < MAX; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	while (t--)
	{

		int k, n;
		cin >> k >> n;

		cout << dp[k][n] << "\n";
	}

}