#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define  MAX 101

string days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	int x, y;

	cin >> x >> y;
	int days_passed = 0;
	for (int i = 0; i < x - 1; i++)
	{
		days_passed += month_days[i];

	}

	days_passed += y - 1;

	int idx = (1 + days_passed) % 7;
	cout << days[idx];

}