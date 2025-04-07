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

	while (true)
	{
		string n;
		cin >> n;
		if (n == "0")break;

		string reverseN = n;
		reverse(reverseN.begin(), reverseN.end());

		if (reverseN == n)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";

	}
}