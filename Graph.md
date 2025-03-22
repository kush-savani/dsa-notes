# C++ Graph Cheat Sheet

## Table of Contents

  - [2.0 Overview](#20-overview)
  - [2.1 Breadth-First Search](#21-breadth-first-search)
  - [2.2 Depth-First Search](#22-depth-first-search)
  - [2.3 Topological Sort](#23-topological-sort)
  - [2.4 Shortest Path](#24-shortest-path)
  - [2.5 Dijkstra Algorithm](#25-dijkstra-algorithm)
  - [2.6 Bellman Ford Algorithm](#26-bellman-ford-algorithm)
  - [2.7 Floyd Warshal Algorithm](#27-floyd-warshal-algorithm)
  - [2.8 Prim's Algorithm](#28-prims-algorithm)
  - [2.9 Disjoint Set](#29-disjoint-set)
  - [2.10 Kruskal's Algorithm](#210-kruskals-algorithm)




#### 2.0 Overview

**Types of Graphs**
- Directed and Undirected Graphs
- Weighted Graph
- Cyclic and Acyclic Graphs: In the case of Directed Graphs if there’s a possibility of creating a path such that while traveling you end up on an already traveled node, the graph is Cyclic. And the opposite goes for the Acyclic graph


**Graph Representation**
- Adjacency Matrix
  ![image](https://github.com/user-attachments/assets/ca8548f5-00db-4ff0-a306-ec867b36d7c5)
- Adjacency List
  ![image](https://github.com/user-attachments/assets/15f7df84-da03-4c05-b8f7-a4abd0fd9d87)

-----



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
        unordered_map<int, int> parent;
        parent[node] = -1;

        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbours : adj[front]){
                // Cycle Detection condition
                // The prime condition which clears that a cycle is present in the graph is that a neighbor of the node for which you are checking is marked true and is not the parent of the node.
                if (visited[neighbour] == true && neighbour != parent[front])
                {
                    return true; 
                }

                else if(!visited[neighbours]){
                    visited[neighbours] = true;
                    q.push(neighbours);
                    answer.push_back(neighbours);
                    parent[neighbour] = front;
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

-----

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
                DFS(adj, answer, visited, neighbour, node);
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

-----

#### 2.3 Topological Sort
Topological Sort (or Topological Ordering) of a directed graph is a linear ordering of its vertices such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

> NOTE: Topological sorting is only possible on Directed Acyclic Graphs (DAGs). If a graph has a cycle, it is impossible to produce a topological ordering.

**Applications:**
- Task Scheduling: Organizing tasks in such a way that dependencies are respected.
- Course Prerequisites: Determining the order in which courses should be taken based on prerequisite relationships.
- Compilation Order: In programming language compilers, determining the order in which files should be compiled.

**Example:**
```
   A → B → D
   ↓    ↑
   C → E
Ans: A → C → B → E → D
```

**Algorithms for Topological Sort:**
1. Kahn’s Algorithm (BFS-based):

Works by removing nodes with no incoming edges and processing them.

> NOTE: If, after processing all nodes, there are still nodes with non-zero in-degrees, the graph has a cycle.

Steps:
  - Find nodes with no incoming edges (in-degree = 0).
  - Add these nodes to a queue.
  - Remove a node from the queue, add it to the topological sort.
  - For each outgoing edge of the node, decrease the in-degree of the destination node.
  - If the in-degree of the destination becomes 0, add it to the queue.
  - Repeat until the queue is empty.
  
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.

```

vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    // Step 1: Calculate in-degrees
    vector<int> inDegree(V, 0);
    
    // Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Step 2: Initialize a queue to store nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process the nodes
    vector<int> topOrder;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topOrder.push_back(node);
        
        // Decrease in-degree of all adjacent nodes
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Check if the topological sort is possible (i.e., no cycle)
    if (topOrder.size() != V) {
        // If topOrder doesn't contain all nodes, a cycle exists
        cout << "Cycle detected! Topological Sort not possible." << endl;
        return {};
    }
    
    return topOrder;
}

```

**Practice**
1. [Topological sort](https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort)
2. [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/description/)
3. [Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/description/)
4. [Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/)

---

#### 2.4 Shortest Path

- BFS will be used for find shortest path in Undirected or Directed Graphs. 

```
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distance(N, INT_MAX);

        queue<int> q;
        q.push(src);
        distance[src] = 0;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto neighbor : adj[front])
            {
                if (distance[front] + 1 < distance[neighbor]){
                    distance[neighbor] = distance[front] + 1;
                }
                q.push(neighbor);
            }
        }

        for(int i=0; i<distance.size(); i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }

        return distance;
    }
};
```

----

#### 2.5 Dijkstra Algorithm

---


#### 2.6 Bellman Ford Algorithm

---


#### 2.7 Floyd Warshal Algorithm

---


#### 2.8 Prim's Algorithm

---


#### 2.9 Disjoint Set


---


#### 2.10 Kruskal's Algorithm


---
