#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

Node* buildTree(int n) {

	int d;
	cin >> d;
	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);
	int i = 1;
	while (!q.empty() and i < n)
	{
		Node* curr = q.front();
		q.pop();
		cin >> d;
		if (d == -1)
			curr->left = NULL;
		else
		{
			curr->left = new Node(d);
			q.push(curr->left);
		}
		cin >> d;
		if (d == -1)
			curr->right = NULL;
		else
		{
			curr->right = new Node(d);
			q.push(curr->right);
		}
		i += 2;
	}
	return root;
}


void inorder(Node* root, vector<int>&main)
{
	if (!root)
		return;
	inorder(root->left, main);
	main.push_back(root->val);
	inorder(root->right, main);
}

Node* ArraytoBST(vector<int> r, int low, int high)
{
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	Node* root = new Node(r[mid]);
	root->left = ArraytoBST(r, low, mid - 1);
	root->right = ArraytoBST(r, mid + 1, high);
	return root;
}
vector<Node*> splitBST (Node* root, int value)
{
	// Write your code here.
	vector<int> main;
	inorder(root, main);
	vector<int> first, second;
	for (int i = 0; i < main.size(); i++)
	{
		cout << main[i] << " ";
		if (main[i] <= value)
			first.push_back(main[i]);
		else if (main[i] > value)
			second.push_back(main[i]);
	}
	cout << endl;
	// sort(first.begin(), first.end());
	// sort(second.begin(), second.end());
	Node* root1 = ArraytoBST(first, 0, first.size() - 1);
	Node* root2 = ArraytoBST(second, 0, second.size() - 1);
	vector<Node*> res;
	res.push_back(root1);
	res.push_back(root2);
	return res;
}

void inorderTraversal(Node* root)
{
	if (!root)
		return;
	inorderTraversal(root->left);
	cout << root->val << " ";
	inorderTraversal(root->right);
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Node* root = buildTree(n);
		int  value;
		cin >> value;
		vector<Node*> r = splitBST(root, value);
		cout << r[0]->val << endl;
		inorderTraversal(r[0]);
		cout << endl;
		cout << r[1]->val << endl;
		inorderTraversal(r[1]);
		cout << endl;
	}


	return 0;
}