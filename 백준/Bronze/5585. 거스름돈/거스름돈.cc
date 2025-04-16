#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define MAX 1001
using namespace std;


int main()
{
	int arr[] = { 500,100,50,10,5,1 };
	int n;
	cin >> n;
	int price = 1000;
	int idx = 0;

	int num = price - n;

	int currentMoney = 0;
	int result = 0;
	while (true)
	{
		if (currentMoney == num)
		{
			break;
		}
		if (currentMoney + arr[idx] <= num)
		{
			currentMoney += arr[idx];
			result++;
		}
		else
		{
			idx++;
		}
	}
	cout << result;
	return 0;
}
