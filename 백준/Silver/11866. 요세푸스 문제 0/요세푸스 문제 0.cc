#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int n, k;

	queue<int> q;


	int i;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		q.push(i);
	cout << "<";
	while (q.size() != 0)
	{
		for (i = 1; i < k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (q.size() != 1)
			cout << ", ";
		q.pop();
	}
	cout << ">";

}


