#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#define  MAX 101
using namespace std;
int main()
{
	int arr[30];
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < 28; i++)
	{
		int n;
		cin >> n;
		arr[n - 1] = n;
	}


	vector<int> student;
	for (int i = 0; i < 30; i++)
	{
		if (arr[i] == -1)
		{
			student.push_back(i);
		}
	}


	for (int i = 0; i < student.size(); i++)
	{
		cout << student[i]+1 << "\n";
	}
}