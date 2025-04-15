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

#define MAX 1001

int arr[MAX];
int n;

int times[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			times[i] += arr[j];
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += times[i];
	}
	cout << result;
	return 0;
}