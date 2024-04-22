#include<bits/stdc++.h>
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
};
int main()
{
  Graph g;
  g.addedge(1,2,0);
  g.addedge(2,3,1);
  g.addedge(0,1,1);
}
