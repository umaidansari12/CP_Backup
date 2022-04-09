/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    while (firstHead) {
        Node* second_temp = secondHead;
        while (second_temp) {
            if (second_temp == firstHead)
                return firstHead->data;
            second_temp = second_temp->next;
        }
        firstHead = firstHead->next;
    }
    return -1;
}

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_set<Node*> hash;

    while (firstHead) {
        hash.insert(firstHead);
        firstHead = firstHead->next;
    }

    while (secondHead) {
        if (hash.find(secondHead) != hash.end())
            return secondHead->data;
        secondHead = secondHead->next;
    }

    return -1;
}