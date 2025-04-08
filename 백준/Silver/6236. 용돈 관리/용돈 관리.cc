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
#define  MAX 100001

int arr[MAX];
int n, m;

bool isPossible(int mid)
{
	int count = 1;

	int now = mid;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > mid)return false;

		if (now < arr[i])
		{
			count++;
			now = mid;
		}
		now -= arr[i];
	}

	return count <= m;
}

void binary_search()
{
	int low = *max_element(arr, arr + n);
	int high = accumulate(arr, arr + n, 0);

	int result = high;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (isPossible(mid))
		{
			result = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	cout << result;
}
int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	binary_search();
}