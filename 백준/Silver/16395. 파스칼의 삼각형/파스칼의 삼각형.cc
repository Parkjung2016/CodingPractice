#include <iostream>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int pascal[100][100];
	for (int i = 0; i < n; i++)
		pascal[i][0] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j >= k) continue;
			pascal[i][j] = pascal[i - 1][j - 1];
			if (i - 1 >= j) pascal[i][j] += pascal[i - 1][j];
		}
	}
	cout << pascal[n - 1][k - 1];
	return 0;
}
