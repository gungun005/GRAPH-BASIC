//topological sort using DFS
#include<bits/stdc++.h>
#include<stack>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adj_list;
    void add_edge(int u,int v)
    {
        adj_list[u].push_back(v);
    }
    void dfs(unordered_map<int,bool>&visited,int src,stack<int>&st)
    {
        //yeh function recursively kaam krta hae pt to remember!
        visited[src]=true;
        st.push(src);
        for(auto k:adj_list[src])
        {
            int data=k;
            if(!visited[k])
            {
                visited[data]=true;
                dfs(visited,data,st);
            }
        }
        
    }
};

int main()
{
 Graph g;
unordered_map<int,bool>visited;
stack<int>st;
  g.add_edge(0,2);
  g.add_edge(0,3);
  g.add_edge(1,5);
  g.add_edge(3,2);
  g.add_edge(2,4);
  g.add_edge(1,7);
  g.add_edge(5,6);
  //extra step added when you have disconnected components in a graph!
  for(int i=0;i<=7;i++)
  {
      if(!visited[i])
      {
       g.dfs(visited,i,st); 
      }
  }
  while(!st.empty())
  {
      cout<<st.top()<<"->";
      st.pop();
  }
}
