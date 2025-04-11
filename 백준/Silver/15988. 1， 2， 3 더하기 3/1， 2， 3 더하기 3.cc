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

#define MAX 1000001
long long dp[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (long long i = 4; i <= MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		cout << dp[n] << "\n";
	}
}