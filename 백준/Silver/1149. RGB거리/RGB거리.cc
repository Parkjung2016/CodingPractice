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
int dp[MAX][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int price[3];

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> price[0] >> price[1] >> price[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + price[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + price[1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + price[2];
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

}