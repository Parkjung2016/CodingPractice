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

#define MAX 1001
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	int startIdx = k - 1;
	cout << '<';
	for (int i = 0; i < n; i++)
	{
		int num = v[startIdx];
		cout << num;
		if (v.size() != 1) cout << ", ";
		v.erase(find(v.begin(), v.end(), num));
		if (v.size() == 0)break;
		startIdx = (startIdx + (k - 1)) % (v.size());
	}
	cout << '>';

}