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

#define MAX 1000000

int arr[MAX];
int n, m;

int GetMaxHeight()
{
	int left = 0, right = arr[n - 1], mid = 0, maxHeight = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid)
			{
				sum += arr[i] - mid;
			}
		}
		if (sum >= m)
		{
			maxHeight = mid;
			left = mid + 1;

		}
		else
		{
			right = mid - 1;
		}
	}
	return maxHeight;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cout << GetMaxHeight();


}