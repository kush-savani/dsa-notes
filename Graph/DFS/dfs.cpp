/*
DFS (Depth First Search)

- Data Structure :- vector<vector<int>> adj // adjacency list
                 :- vector<bool> visited // visit track

- Application :- Cycle detection
              :- Graph traversal 

LeetCode Question:
- All Ancestors of a Node in a Directed Acyclic Graph (https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Function to return a list containing the DFS traversal of the graph.
     vector<int> dfsOfGraph(int V, vector<vector<int>> adj) {
        // Code here
        vector<int> dfsStore (V+1);
        vector<bool> vis(V + 1);
        
        for(int i = 0; i < V; i++){
            if(vis[i] == false){
                dfs(i, vis, adj, dfsStore);
            }
        }
        return dfsStore;
    }
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &dfsStore){
        dfsStore.push_back(node);
        vis[node] = true;
        
        for(int i : adj[node]){
            if(vis[i] == false){
                dfs(i, vis, adj, dfsStore);
            }
        }
    }
};
