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
#include <unordered_set>
#include <climits>
using namespace std;

#define MAX 500001

int arr[MAX];
int dp[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int result = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		result = max(result, dp[i]);
	}
	cout << result;
	return 0;
}