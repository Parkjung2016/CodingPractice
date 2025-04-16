#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace   std;
#define  MAX 10000

int arr[MAX];
int n;
int m;

int answer;
void SetMaxPrice()
{
	int low = 0, high = *max_element(arr, arr + n);
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += min(arr[i], mid);
		}

		if (sum <= m)
		{
			answer = max(answer, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	SetMaxPrice();
	cout << answer;

	return 0;
}