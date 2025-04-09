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
#define  MAX 1000001
long long arr[MAX];
long long sorted[MAX];

void merge(long long  left, long long right, long long  mid)
{
	long long  l = left;
	long long  r = mid + 1;
	long long  idx = left;

	while (l <= mid && r <= right)
	{
		if (arr[l] <= arr[r]) sorted[idx++] = arr[l++];
		else
			sorted[idx++] = arr[r++];
	}

	while (l <= mid) sorted[idx++] = arr[l++];
	while (r <= right) sorted[idx++] = arr[r++];

	for (long long i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
	}

}

void mergeSort(long long  left, long long  right)
{
	if (left < right)
	{
		long long  mid = (left + right) / 2;

		mergeSort(left, mid);
		mergeSort(mid + 1, right);

		merge(left, right, mid);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	mergeSort(0, n - 1);
	for (long long i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
}