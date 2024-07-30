#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
class Graph
{
    unordered_map<int,list<pair<int,int>>>adj_list;
    public:
    void add_edge(int u,int v,int wt)
    {
        adj_list[u].push_back({v,wt});
    }
    void topo_order_dfs(int src,stack<int>&topo,unordered_map<int,bool>&visited)
    {
        visited[src]=true;
        for(auto nbrpair:adj_list[src])
        {
            int nbrNode=nbrpair.first;
            int nbrDist=nbrpair.second;
            if(!visited[nbrNode])
            {
                 topo_order_dfs(nbrNode,topo,visited);
            }
        }
        topo.push(src);
    }
    void shortest_path_dfs(stack<int>&topo,int n)
    {
        vector<int>dist(n,INT_MAX);
        //initially source mannan hoga which is top element of topological order
        int src=topo.top();
        topo.pop();
        dist[src]=0;
        //update neighbour distance for the source node
            for(auto nbrpair:adj_list[src])
        {
            int nbrNode=nbrpair.first;
            int nbrDist=nbrpair.second;
            if(dist[src]+nbrDist<dist[nbrNode]);
            {
                dist[nbrNode]=dist[src]+nbrDist;
            }
        }
        //apply the same concept for the remaining nodes
        while(!topo.empty())
        {
        int src=topo.top();
        topo.pop();
        dist[src]=0;
        //update neighbour distance for the source node
            for(auto nbrpair:adj_list[src])
        {
            int nbrNode=nbrpair.first;
            int nbrDist=nbrpair.second;
            if(dist[src]+nbrDist<dist[nbrNode]);
            {
                dist[nbrNode]=dist[src]+nbrDist;
            }
        }
        }
        for(auto i:dist)
        {
            cout<<i<<":"<<dist[i]<<endl;
        }
        
    }
};
int main()
{
    Graph g;
    g.add_edge(0,1,5);
    g.add_edge(0,2,3);
    g.add_edge(2,1,2);
    g.add_edge(1,3,3);
    g.add_edge(2,3,5);
    g.add_edge(2,4,6);
    g.add_edge(4,3,1);
    stack<int>topo;
    unordered_map<int,bool>visited;
    int src=0;
    g.topo_order_dfs(0,topo,visited);
    g.shortest_path_dfs(topo,6);
    
    
    return 0;
}
