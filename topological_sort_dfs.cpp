#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Graph{
public:
unordered_map<int,list<int>>adj_list;
void add_edges(int u,int v,int direction)
  {
    //adjacency list creation
    if(direction==0)
    {
      //undirected//
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }
    else
    {
    //directed//
      adj_list[u].push_back(v);
    }
  }
  
void print_list()
{
for(auto i:adj_list)
  {
    cout<<i.first<<" ";
    for(auto k:i.second)
      {
        cout<<k<<","<<endl;
      }
    cout<<endl;
}
}
void topo_dfs(int src,map<int,bool>&visited,stack<int>&st)
{
    visited[src]=true;
    for(auto nbr:adj_list[src])
    {
        if(!visited[src])
        topo_dfs(nbr,visited,st);
    }
    st.push(src);
}
};
int main()
{
  Graph g;
  g.add_edges(0,1,1);
  g.add_edges(1,2,1);
  g.add_edges(2,3,1);
  g.add_edges(2,4,1);
  g.add_edges(3,5,1);
  g.add_edges(4,5,1);
  g.add_edges(5,6,1);
  g.add_edges(5,7,1);
  map<int,bool>visited;
  stack<int>st;
  int n=8;
  for(int i=0;i<8;i++)
  {
      g.topo_dfs(i,visited,st);
  }
 while(!st.empty())
 {
     cout<<st.top()<<"->";
     st.pop();
 }
return 0;
}

  



