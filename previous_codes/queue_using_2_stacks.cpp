#include<bits/stdc++.h>

using namespace std;


class StackQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
void StackQueue :: push(int x)
{
    // Your Code
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    // Your Code
    if (s1.empty())
        return -1;
    int ans = s1.top();
    s1.pop();
    return ans;
}

class StackQueue1 {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";

            }
        }
        cout << endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue1 :: push(int x)
{
    // Your Code
    s1.push(x);
}

/*The method pop which return the element poped out of the queue*/
int StackQueue1 :: pop()
{
    // Your Code
    int ans = -1;
    if (s1.empty() && s2.empty())
        return ans;
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    ans = s2.top();
    s2.pop();
    return ans;

}
