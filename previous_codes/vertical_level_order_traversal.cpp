#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
public:
    // root: root node of the tree
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> res;
        if (!root)
            return res;
        queue<pair<Node*, int>> q;
        map<int, vector<int>> m;
        int col = 0;
        q.push({root, col});
        while (!q.empty())
        {
            pair<Node*, int> curr = q.front();
            q.pop();
            m[curr.second].push_back(curr.first->data);
            if (curr.first->left)
                q.push({curr.first->left, curr.second - 1});
            if (curr.first->right)
                q.push({curr.first->right, curr.second + 1});
        }
        for (auto i : m)
        {
            for (auto j : i.second)
                res.push_back(j);
        }
        return res;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        // string c;
        // getline(cin,c);
        Solution obj;
        Node* root = buildTree(s);

        vector <int> res = obj.verticalOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends