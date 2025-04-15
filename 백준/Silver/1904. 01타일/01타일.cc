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

long long dp[MAX];
long long arr[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= MAX; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	int n;
	cin >> n;
	cout << dp[n];
	return 0;
}