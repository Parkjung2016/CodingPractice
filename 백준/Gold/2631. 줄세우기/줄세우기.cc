#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define MAX 100001
using namespace std;
int arr[MAX];
int len;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		auto lowerPos = lower_bound(arr, arr + len, num);

		if (*lowerPos == 0) len++;
		*lowerPos = num;
	}

	cout << n - len;
	return 0;
}
