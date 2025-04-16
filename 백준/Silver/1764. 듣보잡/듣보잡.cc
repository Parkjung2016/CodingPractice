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
#include <unordered_set>
using namespace std;

#define MAX 500001


unordered_set<string> name1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		name1.insert(str);
	}
	vector<string> v;

	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;

		if (name1.find(name) != name1.end())
		{
			v.push_back(name);

		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (string name : v)
	{
		cout << name << "\n";
	}
	return 0;
}