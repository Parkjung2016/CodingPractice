#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int countNumber;
int recursion(const char* s, int l, int r) {
	countNumber++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		countNumber = 0;
		cout << isPalindrome(str.c_str()) << " " << countNumber << endl;
	}
}