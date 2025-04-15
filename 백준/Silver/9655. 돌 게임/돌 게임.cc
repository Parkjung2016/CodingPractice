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
	int n;
	cin >> n;
	if (n % 2 == 0) cout << "CY";
	else cout << "SK";
	return 0;
}