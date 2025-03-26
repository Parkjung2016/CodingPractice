#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long DP[91];

	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n];

}