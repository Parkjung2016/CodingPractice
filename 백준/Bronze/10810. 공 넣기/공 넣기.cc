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
	int n, m;
	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	while (m--)
	{
		int i, j, k;

		cin >> i >> j >> k;

		for (int x = i - 1; x <= j - 1; x++)
		{
			arr[x] = k;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] arr;
}