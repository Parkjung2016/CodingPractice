#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define MAX 100001
using namespace std;


int n, m;
int lamps[MAX];

bool canLight(int num)
{
	int last = 0;
	for (int i = 0; i < m; i++)
	{
		if (lamps[i] - num > last)
		{
			return false;
		}
		last = lamps[i] + num;

		if (last >= n)
			return true;
	}
	return last >= n;
}
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> lamps[i];
	}
	sort(lamps, lamps + m);

	int low = 0, high = n;
	int answer = n;
	while (low <= high)
	{
		int mid = (low + high) / 2;


		if (canLight(mid))
		{
			answer = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << answer;
	return 0;
}
