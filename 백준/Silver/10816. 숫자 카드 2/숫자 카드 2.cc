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

#define MAX 500001
int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int m;
	cin >> m;
	sort(arr, arr + n);
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		int count = upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num);

		cout << count << " ";
	}
}