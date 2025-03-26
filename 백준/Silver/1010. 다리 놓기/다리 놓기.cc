#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long sum = 1;
		int a, b;
		cin >> a >> b;

		int r = 1;
		for (int j = b; j > b - a; j--)
		{
			sum *= j;
			sum /= r;
			r++;
		}
		cout << sum << endl;
	}

}