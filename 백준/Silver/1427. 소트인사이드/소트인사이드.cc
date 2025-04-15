#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

#define MAX 1000001
bool check[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	vector<int> v;
	for (int i = 0; i < str.size(); i++)
	{
		v.push_back(str[i] - '0');
	}

	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return 0;
}