//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    /*
    if (!head or !head->next)
            return head;
        Node* prev = head;
        Node* curr = head->next;
        head = curr;
        Node* next = NULL;
        while (1)
        {
            next = curr->next;
            curr->next = prev;
            if (next == NULL || next->next == NULL)
            {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            prev = next;
            curr = next->next;
        }

        return head;
    */
    vector<Node*> list;
    Node* curr = head;
    while (curr)
    {
        list.push_back(curr);
        curr = curr->next;
    }
    for (int i = 0; i < list.size() - 1; i += 2)
    {
        swap(list[i]->data, list[i + 1]->data);
    }
    return head;
}

// { Driver Code Starts.
void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ", (node)->data);
        node = (node)->next;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, firstdata;
        cin >> n;
        // taking first node of linked list
        cin >> firstdata;
        struct Node* head = new Node(firstdata);
        struct Node* tail = head;
        // taking remaining nodes of linked list
        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head = pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}  // } Driver Code Ends

ListNode* Solution::swapPairs(ListNode* A) {
    if (!A)
        return NULL;
    ListNode* head = A;
    ListNode* curr, *next, *prev;
    prev = NULL;
    curr = A;
    next = curr->next;
    if (next)
        A = next;
    while (next)
    {
        curr->next = next->next;
        next->next = curr;
        if (prev)
            prev->next = next;      //I had missed this part of linking 1 to 4: 2->1 ~ 4->3
        prev = curr;
        curr = curr->next;
        if (curr)
            next = curr->next;
        else
            next = NULL;
    }
    return A;
}