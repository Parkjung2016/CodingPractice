#include <iostream>
using namespace std;

struct node // 노드 
{
	int data;
	node* left;
	node* right;
};

node* MakeNode(int n) // 노드를 만드는 함수
{
	node* nd = new node;
	nd->data = n;
	nd->left = nullptr;
	nd->right = nullptr;
	return nd;
}
node* root = nullptr;

void Insert(node* r, node* node)
{
	if (root == nullptr) root = node;
	else if (r->data < node->data) //root 오른쪽으로
	{
		if (r->right == nullptr)
		{
			r->right = node;

		}
		else
		{
			Insert(r->right, node);

		}
	}
	else if ((r->data > node->data))//root 왼쪽으로
	{
		if (r->left == nullptr)
		{
			r->left = node;


		}
		else
		{
			Insert(r->left, node);


		}
	}
}
void postorder(const node* nd)
{
	if (nd == nullptr)
	{
		return;
	}
	postorder(nd->left);
	postorder(nd->right);

	cout << nd->data << endl;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int value;
	while (cin >> value)
	{
		Insert(root, MakeNode(value));
	}
	postorder(root);
	return 0;
}
