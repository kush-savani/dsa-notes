# C++ Graph Cheat Sheet

## Table of Contents

- [1 Overview](#1-overview)
- [2 Traversal Algorithms](#2-traversal-algorithms)
  - [2.1 Breadth-First Search](#21-breadth-first-search)
  - [2.2 Depth-First Search](#21-depth-first-search)




### 1 Overview

**Types of Graphs**
- Directed and Undirected Graphs
- Weighted Graph
- Cyclic and Acyclic Graphs: In the case of Directed Graphs if there’s a possibility of creating a path such that while traveling you end up on an already traveled node, the graph is Cyclic. And the opposite goes for the Acyclic graph


**Graph Representation**
- Adjacency Matrix
  ![image](https://github.com/user-attachments/assets/ca8548f5-00db-4ff0-a306-ec867b36d7c5)
- Adjacency List
  ![image](https://github.com/user-attachments/assets/15f7df84-da03-4c05-b8f7-a4abd0fd9d87)


### 2 Traversal Algorithms

#### 2.1 Breadth-First Search
BFS explores all the neighbors of a node before moving on to the next level.

**Data Structures**
Queue: To store the child or connected nodes which still need to be explored.
vector: To find that a particular node is visited or not.

**Steps to achieve algorithm**
1. Mark the first received node in the function as visited.
2. Add this node to the queue
3. Take out the front node from the queue in a front variable.
4. Clear this node from the queue.
5. Push this node to the answer vector.
6. Add its neighbor to the queue.

```
class Solution {

    void BFS(vector<int> adj[], vector<int> &answer, vector<bool> &visited, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbours : adj[front]){
                if(!visited[neighbours]){
                    visited[neighbours] = true;
                    q.push(neighbours);
                    answer.push_back(neighbours);
                }
            }
        }
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> answer;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                BFS(adj, answer, visited, i);
            }
        }

        return answer;

    }
};
```


#### 2.2 Depth-First Search
DFS explores as far as possible along each branch before backtracking.

**Data Structures**
vector: To find that a particular node is visited or not.

**Steps to achieve algorithm**
1. Mark the first received node as visited.
2. Add this note to the answer vector.
3. Make a loop over the adjacency list, if a node is not visited call the DFS function recursively.

```
class Solution {
  
    void DFS(vector<int> adj[], vector<int> &answer, vector<bool> &visited, int node){
        visited[node] = 1;
        answer.push_back(node);

        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                DFS(adj, answer, visited, neighbour);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> answer;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                DFS(adj, answer, visited, i);
            }
        }

        return answer;
    }
};
```

**Complexity Analysis**

<img width="788" alt="Screenshot 2025-03-19 at 11 25 55 AM" src="https://github.com/user-attachments/assets/7e8d7509-75a1-4f8a-9adb-00f78a9d16d0" />




