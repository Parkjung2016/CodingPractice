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

int arr[MAX];
int n, m;

void binary_search(int num)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == num)
		{
			cout << 1 << "\n";
			return;
		}

		if (arr[mid] > num)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << 0 << "\n";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cin >> m;
		sort(arr, arr + n);
		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;
			binary_search(num);
		}
	}
}