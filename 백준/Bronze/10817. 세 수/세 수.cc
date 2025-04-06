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
	vector<int> v;

	for (int i = 0; i < 3; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cout << v[1];
}