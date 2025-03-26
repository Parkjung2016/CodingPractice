#include <stdio.h>
#include <iostream>
using namespace std;

long long f(long long num)
{
	if (num <= 1)return 1;
	return num * f(num - 1);
}
int main()
{
	int n;
	cin >> n;
	cout << f(n);
}