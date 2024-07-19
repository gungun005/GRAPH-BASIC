//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  //Implementing Cycle Detection Using DFS
   bool isCycleHelper(int src,unordered_map<int,bool>&visited ,int parent,vector<int> adj[]) 
   {
        // Code here
        visited[src]=true;
        for(auto k:adj[src])
        {
            if(!visited[k])
            {
                //main ye function call hae!
                bool ans=isCycleHelper(k,visited,src,adj);
                if(ans==true)
                {
                    return true;
                }
            }
            //agar function call repeat hoti hae toh cycle present hae! kyunki koi aur node 
            //us node ko access krna chaha rha hae!!
            //cycle is present
            else if(visited[k]==true && k!=parent)
            {
                return true;
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
            int parent=-1;
            bool ans=isCycleHelper(i,visited,parent,adj);
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