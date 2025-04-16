#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace   std;
#define  MAX 1001

string currentStates;
string goalStates;
string temp;
int cnt;
int n;
int result = INT_MAX;
void solve(int first)
{
	temp = currentStates;
	cnt = 0;
	if (first == 0)
	{
		temp[0] = temp[0] == '0' ? '1' : '0';
		temp[1] = temp[1] == '0' ? '1' : '0';
		cnt++;
	}

	for (int i = 1; i < n; i++)
	{
		if (temp[i - 1] != goalStates[i - 1])
		{
			if (i > 0) temp[i - 1] = temp[i - 1] == '0' ? '1' : '0';
			temp[i] = temp[i] == '0' ? '1' : '0';
			if (i < n - 1) temp[i + 1] = temp[i + 1] == '0' ? '1' : '0';

			cnt++;
		}
	}
	if (temp == goalStates) result = min(result, cnt);
}
int main()
{
	cin >> n;
	cin >> currentStates;
	cin >> goalStates;


	solve(0);
	solve(1);

	if (result != INT_MAX) cout << result;
	else cout << -1;

	return 0;
}