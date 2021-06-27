#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cout << "Enter number of Elements you want to insert : ";
    cin >> n;
    unordered_map<int,int> a;
    for(int i = 0; i < n ; i++)
    {
        cin>>k;
        a[k]++; 
    }
     for (auto itr :a) { 
        if(itr.second==1)
         {
             cout<<itr.first<<"\t";
             //cout<<itr.second<<endl;
            break;
         }
    } 
    cout << endl; 
}