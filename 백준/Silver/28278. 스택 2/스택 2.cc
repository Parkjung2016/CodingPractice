#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> mStack;
	for (size_t i = 0; i < n; i++)
	{
		int comm;
		cin >> comm;
		if (comm == 1)
		{
			int num;
			cin >> num;
			mStack.push(num);
		}
		else if (comm == 2)
		{
			cout << (mStack.empty() ? -1 : mStack.top()) << "\n";
			if (!mStack.empty())
				mStack.pop();

		}
		else if (comm == 3)
		{
			cout << mStack.size() << "\n";
		}
		else if (comm == 4)
		{
			cout << mStack.empty() << "\n";
		}
		else if (comm == 5)
		{
			cout << (mStack.empty() ? -1 : mStack.top()) << "\n";
		}
	}

}


