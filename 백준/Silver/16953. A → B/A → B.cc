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

#define MAX 101

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long a, b;
	cin >> a >> b;

	queue<pair<int, int>> q;

	q.emplace(a, 0);
	long long result = -2;
	while (!q.empty())
	{
		pair<long, long> pair = q.front();
		q.pop();

		if (pair.first == b)
		{
			result = pair.second;
			break;
		}
		long long mul = pair.first * 2;
		if (mul <= b)
		{
			q.emplace(mul, pair.second + 1);
		}
		long long sum = pair.first * 10 + 1;
		if (sum <= b)
		{
			q.emplace(sum, pair.second + 1);
		}
	}
	cout << result + 1;
	return 0;
}