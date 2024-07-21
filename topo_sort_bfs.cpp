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
void topo_bfs(int n)
{
    unordered_map<int,int>indegree;
    queue<int>q;
    //phle indegree nikalo
    for(auto k:adj_list)
    {
        for(auto nbr:k.second)
        {
            indegree[nbr]++;
        }
    }
    //agar kisi ki indegree 0 hae toh use queu mae daldo
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    //ab normal bfs chalaooo..
    
    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();
        cout<<frontnode<<",";
        for(auto nbr:adj_list[frontnode])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
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
 g.topo_bfs(8);
return 0;
}

  



