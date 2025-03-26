#include <stdio.h>
#include <iostream>
using namespace std;

long long f(long long num)
{
	if (num == 0) return 0;
	if (num == 1)return 1;
	return f(num - 1) + f(num - 2);
}
int main()
{
	int n;
	cin >> n;
	cout << f(n);
}