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
#include <unordered_set>
#include <climits>
using namespace std;

#define MAX 500001

int arr[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	int sum = 0;
	for (int i = n; i > 0; i--)
	{
		if (arr[i] > k)continue;

		while (true)
		{
			int  num = sum + arr[i];
			if (num <= k)
			{
				sum = num;
				count++;
			}
			else
			{
				break;
			}
		}

	}
	cout << count;
	return 0;
}