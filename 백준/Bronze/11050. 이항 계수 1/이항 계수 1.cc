#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101

int arr[MAX];

int f(int n)
{
	if (n == 0 || n == 1)return 1;

	return f(n - 1) * n;
}
int main()
{
	int n, k;
	cin >> n >> k;

	cout << f(n) / (f(k) * f(n - k));
}