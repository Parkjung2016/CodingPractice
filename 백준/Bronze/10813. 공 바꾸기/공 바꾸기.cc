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
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		arr[i] = i;
	while (m--)
	{
		int i, j;
		cin >> i >> j;
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
}