#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 301
int dp[MAX];
int score[MAX];


int f(int i)
{
	if (dp[i] != -1) return dp[i];

	dp[i] = max(f(i - 2), f(i - 3) + score[i - 1]) + score[i];

	return dp[i];
}
int main() {

	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	dp[0] = score[0];
	dp[1] = score[0]+score[1];
	dp[2] = max(score[0] + score[2], score[1] + score[2]);
	int result = f(n - 1);
	cout << result;
	return 0;
}
