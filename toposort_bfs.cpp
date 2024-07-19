#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Graph
{
  public:
    unordered_map<int,list<int>>adjList;
    void add_edge(int u,int v,int direction)
    {
      //we are working on directed acyclic graph which is the most important property to implement the topological sort!
        adjList[u].push_back(v);
    }
//bfs graph traversal technique//
void bfs(int src,unordered_map<int,bool>&visited,stack<int>&st)
{
  //visited array will check whether the node is visited already or not
  //we will use a queue data structure for this operation
  queue<int>q;
  q.push(src);
  st.push(src);
  visited[src]=true;
  while(!q.empty())
  {
    int front=q.front();
      q.pop();
    for(auto k:adjList[front])
    {
      int data=k;
      if(!visited[data])
      {  
          st.push(data);
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
stack<int>st;
  g.add_edge(0,2,1);
  g.add_edge(0,1,1);
  g.add_edge(2,4,1);
  g.add_edge(1,3,1);
  g.add_edge(3,4,1);
  g.add_edge(3,5,1);
  g.add_edge(5,6,1);
  //extra step added when you have disconnected components in a graph!
  for(int i=0;i<=6;i++)
  {
      if(!visited[i])
      {
       g.bfs(i,visited,st); 
      }
  }
  while (!st.empty())
  {
      cout<<st.top()<<"<-";
      st.pop();
  }
}

    
