#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int a, b, c;
	string str;

	cin >> a >> b >> c;

	int result = a * b * c;

	str = to_string(result);

	int* nums = new int[10] {0, };
	for (int j = 0; j < 10; j++)
	{

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == j + '0')
			{
				nums[j]++;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << nums[i] << endl;
	}

	return 0;
}
