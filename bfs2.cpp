//this code is if the graph contains disconnected components
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
void bfs(int src,unordered_map<int,bool>&visited)
{
    //visited array to check if the element has been already accessed or not
  
    //queue
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int front=q.front();
        cout<<front<<"->";
        q.pop();
        for(auto k:adjList[front])
        {
            int data=k;
            if(!visited[data])
            {
                q.push(data);
                visited[data]=true;
            }
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
       g.bfs(i,visited); 
      }
  }
}
