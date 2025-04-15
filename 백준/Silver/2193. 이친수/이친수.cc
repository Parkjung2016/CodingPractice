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

#define MAX 91

long long dp[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	dp[1] = 1;
	dp[2] = 1;
	//dp[3] = 2;
	for (int i = 3; i <= MAX; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	int n;
	cin >> n;

	cout << dp[n];
	return 0;
}