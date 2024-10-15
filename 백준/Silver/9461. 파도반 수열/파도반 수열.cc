#include <stdio.h>
#include <iostream>

using namespace std;

unsigned long long  arr[101]{ 0,1, 1,1 };
//long long p(int n)
//{
//	for (int i = 0; i < 2; i++)
//		arr[i] = i;
//	if (n<3)
//
//}
int main() {
	int t;
	cin >> t;
	for (int i = 4; i < 101; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < t; i++)
	{
		int num;
		cin >> num;
		cout << arr[num] << endl;

	}


	//int n, k;
	//cin >> n >> k;

	//int pascal[100][100];
	//for (int i = 0; i < n; i++)
	//	pascal[n][0] = 1;

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < k; j++)
	//	{

	//	}
	//}

	return 0;
}
