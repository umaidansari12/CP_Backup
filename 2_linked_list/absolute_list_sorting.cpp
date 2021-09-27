#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    Node* next;
    int data;
};
void sortList(Node** head);
// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}


// Driver code
int main()
{

    int t = 0;
    int n = 0;
    cin >> t;
    while (t--)
    {
        Node* head = NULL;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            // push(&head, a);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            push(&head, arr[i]);
        }
        // printList(head);

        sortList(&head);

        printList(head);

    }
    return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */

Node* merge(Node* first, Node* second) {
    Node* result = NULL;
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->data <= second->data) {
        result = first;
        result->next = merge(first->next, second);
    }
    else
    {
        result = second;
        result->next = merge(first, second->next);
    }
    return result;
}

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next and fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* head) {
    if (head == NULL or head->next == NULL)
        return head;
    Node* mid = getMiddle(head);
    Node* newHead = mid->next;
    mid->next = NULL;
    return merge(mergeSort(head), mergeSort(newHead));
}
void sortList(Node** head)
{
    // Your Code Here
    *head = mergeSort(*head);
}