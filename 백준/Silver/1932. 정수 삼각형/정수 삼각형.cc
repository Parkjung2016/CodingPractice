#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 501
int dp[MAX][MAX];

int arr[MAX][MAX];

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int j = 0; j < n; j++)
	{
		dp[n - 1][j] = arr[n - 1][j];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
		}
	}
	cout << dp[0][0];
	return 0;
}
