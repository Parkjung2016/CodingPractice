#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace   std;
#define  MAX 10000

int main()
{
	int n;
	cin >> n;
	int count = 1;
	int sum = 1;
	int mul = 6;
	while (true)
	{
		if (sum >= n)
			break;

		sum += mul;
		mul += 6;
		count++;
	}
	cout << count;
	return 0;
}