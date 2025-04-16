#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector< pair<int, int> >vec(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[i] = make_pair(a, b);
	}


	for (int i = 0; i < n; i++)
	{
		int rank = 1;
		for (int j = 0; j < n; j++)
		{

			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
				rank++;
		}
		cout << rank << " ";
	}
}