#include <iostream>
#include <string>
using namespace std;
int main()
{
	int count;

	cin >> count;

	int* num = new int[count];
	for (int i = 0; i < count; i++)
	{
		cin >> num[i];
	}
	int minNum = num[0], maxNum = num[0];
	for (int i = 0; i < count; i++)
	{
		if (num[i] < minNum)
			minNum = num[i];
		if (num[i] > maxNum) maxNum = num[i];
	}
	cout << minNum << " " << maxNum;	
}
