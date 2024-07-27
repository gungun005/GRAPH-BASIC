#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adj_list;
    //creating adjacency list for an undirected graph
    void add_edge(int u,int v)
    {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    void shortest_path_bfs(int src,int dest)
    {
        queue<int>pq;
        map<int,bool>visited;
        map<int,int>parent;
        //initial state maintain kro
        pq.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!pq.empty())
        {
            int frontnode=pq.front();
            pq.pop();
            for(auto k:adj_list[frontnode])
            {
                if(!visited[k])
                {
                    pq.push(k);
                    visited[k]=true;
                    parent [k]=frontnode;
                }
               
            }
        }
        //parent array tyar ab hmko shortest path print krana hae
        vector<int>ans;
        //hm backwards chalenge path ke liye..
        while(dest!=-1)
        {
            ans.push_back(dest);
            dest=parent[dest];
        }
        //reverse order mae aya hoga
        //isliye ans ko reverse krna padega
        reverse(ans.begin(),ans.end());
        //now printing the array
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
        
    }
};
int main()
{
    Graph g;
    g.add_edge(0,4);
    g.add_edge(0,3);
    g.add_edge(0,6);
    g.add_edge(4,1);
    g.add_edge(3,5);
    g.add_edge(6,2);
    g.add_edge(1,5);
    g.add_edge(2,5);
    g.shortest_path_bfs(0,5);
}
