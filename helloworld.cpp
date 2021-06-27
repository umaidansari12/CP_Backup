#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

#define square(x) x*x

int main()
{
   /*string s="abababab";
   string sm=s.substr(0,2);
   cout << sm ;*/
   vector <int> a;
   a.push_back(6);
   a.push_back(2);
   a.push_back(1);
   a.push_back(4);
   a.push_back(5);
   a.push_back(3);
   int m=*min_element(a.begin(),a.begin()+6);
   cout << m;


   /*for(auto i=a.begin(); i <= a.begin()+2;i++)
   {
      cout << *i << " ";
   }*/
  /*vector < vector < int > > Matrix(5, vector< int >(5,15));
   for(int i=0;i< 5;i++)
   {
      for(int j=0;j<5;j++)
      {
         cout<<Matrix[i][j]<<" ";
      }
      cout<<endl;
   }
   cout<<endl;
   vector<vector<int>> s(vector<int>(5,15));
   for(int i = 0;i < s.size() ;i++)
   {
      for(int j : s[i])
      {
         cout << j <<" ";
      }
      cout<<endl;
   }
*/
} 
