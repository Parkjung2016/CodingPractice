#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned	int k, n;

	cin >> k >> n;
	unsigned int v[10000];

	unsigned	int maxI = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
		maxI = max(maxI, v[i]);
	}
	unsigned int ans = 0;

	unsigned int left = 1, right = maxI, mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;


		unsigned int now = 0;

		for (int i = 0; i < k; i++)
		{
			now += v[i] / mid;
		}

		if (now >= n)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans << endl;
}