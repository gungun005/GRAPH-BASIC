//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //Helper Function to find the cycle is present or not using BFS!!
  
   bool isCycleHelper(int src,int V, vector<int> adj[],unordered_map<int,bool>&visited) {
        // Code here
        
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        visited[src]==true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            for(auto k:adj[frontnode])
            {
              //if the node is the parent node
                if(k==parent[frontnode])
                {
                    continue;
                }
              //if the node is never visited other than parent node
                if(!visited[k])
                {
                    q.push(k);
                    parent[k]=frontnode;
                    visited[k]=true;
                }
                else if(visited[k]==true && k!=parent[frontnode])
                {
                    //cycle present hae
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=isCycleHelper(i,V,adj,visited);
                if(ans==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
