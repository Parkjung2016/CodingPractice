#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	bool isReverse = false;
	cin >> n;

	queue<int> myQueue;

	for (int i = 1; i <= n; i++)
	{
		myQueue.push(i);
	}

	for (int i = 0; i < n-1; i++)
	{
		myQueue.pop();
		int n = myQueue.front();
		myQueue.pop();
		myQueue.push(n);


	}
	cout << myQueue.front() << endl;
}


