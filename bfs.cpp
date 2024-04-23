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
void bfs(int src)
{
    //visited array to check if the element has been already accessed or not
    unordered_map<int,bool>visited;
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
  g.addedge(1,2,0);
  g.addedge(2,3,1);
  g.addedge(0,1,1);
  g.bfs(0);
}
