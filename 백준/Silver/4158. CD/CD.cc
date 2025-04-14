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

int cdCount;
void binary_search(int num)
{
	int left = 0, right = n - 1, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == num)
		{
			cdCount++;
			return;
		}

		if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0) break;
		cdCount = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;
			binary_search(num);
		}

		cout << cdCount << "\n";
	}

	return 0;
}