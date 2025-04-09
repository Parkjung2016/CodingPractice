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
#define  MAX 200001
long long n, c;
long long arr[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> c;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int result = 0;
	sort(arr, arr + n);
	long long left = 0;
	long long right = arr[n - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int count = 1;

		long long last = arr[0];

		for (int i = 0; i < n; i++)
		{
			if (arr[i] - last >= mid)
			{
				count++;
				last = arr[i];
			}
		}

		if (count >= c)
		{
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result;
}