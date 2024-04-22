#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// class Graph{
// public:
// void solve(vector<pair<int,int>>&edgelist)
// {
//     vector<vector<int>>adjacencymatrix(edgelist.size(),0);
//   //edgelist will be like 0->1,1->2,2->3..
// for(auto i:edgelist)
//   {
//     int x=i.first;
//     int y=i.second;
//     cout<<" i  m here with the code flow!"<<endl;
//     cout<<adjacencymatrix[x][y]<<endl;
//     adjacencymatrix[x][y]=1;
//   }
// }
// };
void solve(vector<pair<int,int>>&edgelist)
{
    vector<vector<int>>adjacencymatrix(edgelist.size(),0);
  //edgelist will be like 0->1,1->2,2->3..
for(auto i:edgelist)
  {
    int x=i.first;
    int y=i.second;
    cout<<" i  m here with the code flow!"<<endl;
    cout<<adjacencymatrix[x][y]<<endl;
    adjacencymatrix[x][y]=1;
  }  
};
int main()
{
  vector<pair<int,int>>edgelist;
  edgelist.push_back({0,1});
  edgelist.push_back({1,2});
  edgelist.push_back({2,0});
  cout<<"i m working"<<endl;
 return 0;
}
