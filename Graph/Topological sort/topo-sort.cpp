/*
Topological sort 

- Data struture:- vector<vector<int>> adj : adjacency list
               :- vector<int> count       : count for in edge
               :- queue<int> q            : trac node

- Application :- cycle detection using kahn's algo
              :- scheduling question

- Leetcode Question list
    1. https://leetcode.com/problems/course-schedule/ 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& P) {
        vector<vector<int>> adj(n);
        vector<int> count(n);

        // create adjacency list
        for(auto &a:P) {
            adj[a[1]].push_back(a[0]);

            // increase inside edge count
            count[a[0]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i< n; i++) {
            // if node don't have any inbound edge add it in queue
            if(!count[i]) q.push(i);
        }
        
        // track till queue get empty
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(int i: adj[front]) {
                count[i]--;

                // if any node inbound count get zero add it into queue
                if(!count[i]) q.push(i);
            }
        }
        
        for(int i = 0;i < n; i++) {
            // if any node still have count we can't make topological sort
            if(count[i]) return false;
        }
        return true;
    }
};