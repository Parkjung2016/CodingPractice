#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num;

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		int result;
		cin >> result;
		v.push_back(result);

	}
	for (int i = 0; i < 10; i++)
	{
		v[i] = v[i] % 42;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size() << endl;
	return 0;
}
