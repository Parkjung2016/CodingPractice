#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	deque<int> mDequeue;
	for (size_t i = 0; i < n; i++)
	{
		int comm;
		cin >> comm;
		if (comm == 1)
		{
			int number;
			cin >> number;
			mDequeue.push_front(number);
		}
		else if (comm == 2)
		{
			int number;
			cin >> number;
			mDequeue.push_back(number);
		}
		else if (comm == 3)
		{
			cout << (mDequeue.empty() ? -1 : mDequeue.front()) << '\n';
			if (!mDequeue.empty())
				mDequeue.pop_front();
		}
		else if (comm == 4)
		{
			cout << (mDequeue.empty() ? -1 : mDequeue.back()) << '\n';
			if (!mDequeue.empty())
				mDequeue.pop_back();
		}
		else if (comm == 5)
		{
			cout << mDequeue.size() << '\n';
		}
		else if (comm == 6)
		{
			cout << mDequeue.empty() << '\n';
		}
		else if (comm == 7)
		{
			cout << (mDequeue.empty() ? -1 : mDequeue.front()) << '\n';

		}
		else if (comm == 8)
		{
			cout << (mDequeue.empty() ? -1 : mDequeue.back()) << '\n';

		}
	}
}


