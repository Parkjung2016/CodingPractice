#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101
int main()
{
	int t;

	cin >> t;
	while (t--)
	{
		int n, m;
		priority_queue < int> pq;
		queue<pair<int, int>> q;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			int rating;
			cin >> rating;
			q.emplace(rating, i);
			pq.push(rating);
		}

		int ans = 1;
		while (true)
		{
			pair<int, int> pair = q.front();
			int p = pair.first;
			int nth = pair.second;

			if (p != pq.top())
			{
				q.pop();
				q.emplace(p, nth);
			}

			else
			{
				if (nth == m)break;
				q.pop();
				pq.pop();
				ans++;
			}
		}

		cout << ans << "\n";
	}
}