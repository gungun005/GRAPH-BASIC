#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Graph{
public:
unordered_map<int,list<int>>adjList;
void addedge(int u,int v, bool direction)
{
//agar direction 0 ->undirected
//if direction 1->directed
if(direction==0)
{
  //u->v and v->u both
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}
else
{
  //only u->v
adjList[u].push_back(v);
}
}
void dfs(int src,unordered_map<int,bool>&visited)
{
    visited[src]=true;
    for(auto k:adjList[src])
    {
        int data=k;
        if(!visited[data])
        {
            cout<<data<<endl;
            visited[data]=true;
            dfs(data,visited);
        }
    }
}
};
int main()
{
  Graph g;
unordered_map<int,bool>visited;
  g.addedge(0,2,0);
  g.addedge(2,3,1);
  g.addedge(1,5,1);
  g.addedge(6,7,1);
  //extra step added when you have disconnected components in a graph!
  for(int i=0;i<=7;i++)
  {
      if(!visited[i])
      {
       g.dfs(i,visited); 
      }
  }
}
