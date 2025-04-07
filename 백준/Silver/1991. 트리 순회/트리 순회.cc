#include <iostream>
#include <map>
using namespace std;
map<char, pair<char, char>> node;

void preorder(const char ch)
{
	if (ch == '.')return;

	cout << ch;
	preorder(node[ch].first);
	preorder(node[ch].second);
}

void inorder(const char ch)
{
	if (ch == '.')return;

	inorder(node[ch].first);
	cout << ch;
	inorder(node[ch].second);
}

void postorder(const char ch)
{
	if (ch == '.')return;

	postorder(node[ch].first);
	postorder(node[ch].second);
	cout << ch;
}

int main()
{
	int n;
	char lname, name, rname;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> name >> lname >> rname;
		node[name] = { lname,rname };
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

}
