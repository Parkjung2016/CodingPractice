#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101

int main()
{
	int x, y;
	int maxNum = -1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int num;
			cin >> num;

			if (num > maxNum)
			{
				maxNum = num;
				x = j;
				y = i;
			}
		}
	}
	cout << maxNum << "\n";
	cout << y << " " << x;
}