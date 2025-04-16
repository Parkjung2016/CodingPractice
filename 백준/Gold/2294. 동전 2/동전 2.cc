#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace   std;
#define  MAX 10001
int arr[101];
int dp[MAX];
int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++)
	{
		dp[i] = MAX;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}

	if (dp[k] == MAX) cout << "-1";
	else cout << dp[k];
	return 0;
}