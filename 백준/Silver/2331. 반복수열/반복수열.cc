#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#define Max 240000
using namespace  std;

int check[Max];
int a, p;

void dfs(int num)
{
	check[num]++;

	if (check[num] == 3)
		return;

	int next = 0;
	while (num)
	{
		next += pow(num % 10, p);
		num /= 10;
	}
	dfs(next);
}
int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> a >> p;
	dfs(a);

	int cnt = 0;
	for (int i = 0; i < Max; i++)
	{
		if (check[i] == 1)
			cnt++;
	}
	cout << cnt;
}
