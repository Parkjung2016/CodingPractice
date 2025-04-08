#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;
#define  MAX 10001

int arr[MAX];
int n, m;

void binary_search()
{
	int low = 0;
	int high = *max_element(arr, arr + n);
	int result;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		long long total = 0;

		for (int i = 0; i < n; i++)
		{
			total += min(arr[i], mid);
		}

		if (total <= m)
		{
			result = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << result;
}
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;

	binary_search();
}