#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
using namespace std;

#define MAX 10001

long long dp[MAX];

int amounts[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> amounts[i];
	}
	dp[1] = amounts[1];
	dp[2] = amounts[1] + amounts[2];
	dp[3] = max(amounts[1] + amounts[2], max(amounts[2] + amounts[3], amounts[1] + amounts[3]));
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], max(dp[i - 2] + amounts[i], dp[i - 3] + amounts[i - 1] + amounts[i]));
	}

	cout << dp[n];
}