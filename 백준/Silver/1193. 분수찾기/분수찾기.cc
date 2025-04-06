#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101

string rooms[MAX][MAX];
int main()
{
	int n;
	cin >> n;

	int i = 1;
	while (n>i)
	{
		n -= i;
		i++;
	}

	if (i % 2 == 1)
	{
		cout << i + 1 - n << '/' << n;
	}
	else
	{
		cout << n << '/' << i + 1 - n;

	}
}