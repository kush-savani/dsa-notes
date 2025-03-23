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




### 2.0 Overview

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



### 2.1 Breadth-First Search
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

**Practice**
- https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

-----

### 2.2 Depth-First Search
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

### 2.3 Topological Sort
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

### 2.4 Shortest Path

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

### 2.5 Dijkstra Algorithm

**Applications**
- **Routing and Navigation Systems:**
Dijkstra’s algorithm is used in GPS systems to find the shortest route between two points.

- **Network Routing Protocols:**
In computer networks, Dijkstra’s algorithm is used in protocols like OSPF (Open Shortest Path First) for determining the best path for packet delivery.

- **Optimization Problems:**
It’s used in various optimization problems like minimum-cost paths, project scheduling, and planning.


**Algorithm Steps:**

- For the current node, consider all of its unvisited neighbors and calculate their tentative distances from the source node.
- Compare the newly calculated tentative distance to the current assigned value and assign the smaller one. For example, if node A is marked with a distance of 6, and the distance from A to a neighbor B is 2, then the distance to B through A will be 6 + 2 = 8, which is smaller than the current distance, so we update the distance of B.
- Once all the neighbors have been considered, mark the current node as visited. A visited node will not be checked again.
- Select the unvisited node with the smallest tentative distance, and set it as the new current node.
- Repeat steps 1-4 until all nodes are visited.

```


// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int nodes = adj.size();
        set<pair<int, int>> st; //(distance, node)
        vector<int> distance(nodes, INT_MAX);
        
        //Initailizations
        st.insert({0, src});
        distance[src] = 0;
        
        while(!st.empty()) {
            auto top = *(st.begin());

            int current_distance = top.first;
            int current_node = top.second;
            st.erase(st.begin());
            
            for(auto adjNode: adj[node]) {
                int node = neighbor[0];
                int weight = neighbor[1];

                if(distance[node] > current_distance + weight) {
                  if(distance[node] != INT_MAX){
                        st.erase({distance[node], node});
                    }
                    distance[node] = current_distance + weight;
                    st.insert({distance[node], adjNode.first});
                }
            }
        }
        
        return dist;
    }
};


```

**Time Complexity:**
- Using a Simple Array: O(V²), where V is the number of vertices.
- Using a Min-Heap (Priority Queue): O((V + E) * log V), where E is the number of edges.
  - With a binary heap, the time complexity improves to O((V + E) * log V), where you efficiently extract the minimum distance node.
 
**Limitations:**
- **Non-negative Edge Weights:** Dijkstra’s algorithm cannot handle graphs with negative edge weights. For graphs with negative weights, the Bellman-Ford Algorithm is a better choice.
- **Efficiency with Dense Graphs:** Dijkstra’s algorithm can be slower in dense graphs if a simple array or list is used for priority queue management.

---

### 2.6 Bellman Ford Algorithm

This algorithm overcomes Dijkstra's limitation on negative edge weights.

Time Complexity: O(V * E), where V is the number of vertices and E is the number of edges.

```

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        # Step 1: Initialize distances
        vector<int> distance(V, 1e8);
        distance[src] = 0;

        # Step 2: Relax all edges V-1 times
        for(int i = 0; i < V-1; i++) {
            for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        # Step 3: Check for negative weight cycles
        for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]) {
                    // distance[v] = distance[u] + wt;
                    return {-1};
                }
            }

        # Return the shortest distances
        return distance;
    }
};


```

**Negative Weight Cycle Detection:**

- After completing the relaxation for V-1 iterations, check all edges again to see if any distance can still be updated.
- If you find an edge that can still be relaxed, it means there is a negative weight cycle in the graph.

**Practice**
- https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
- 


---


### 2.7 Floyd Warshal Algorithm

This algorithm finds the shortest paths between all pairs of vertices in a weighted graph (both directed and undirected) and works efficiently even if the graph contains negative weight edges (but no negative weight cycles).



**Application:**
- All-Pairs Shortest Path: The Floyd-Warshall algorithm calculates the shortest path from every vertex to every other vertex.
- Intermediate Vertices: The idea is to iteratively try to improve the shortest path by considering if an intermediate vertex can offer a shorter path.


**Iterative Improvement:** 
The triple nested loop runs for each vertex as an intermediate vertex k and updates the shortest distance from i to j through vertex k.

```
class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == -1) mat[i][j] = 1e7;

                # Set the distance to 0 for each vertex to itself
                if(i == j) mat[i][j] = 0;
            }
        }

        # Main loop to calculate shortest paths
        for(int k = 0; k < n; k++) { # Intermediate vertex
            for(int i = 0; i < n; i++) { # Start vertex
                for(int j = 0; j < n; j++) { # End vertex
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        
        
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1e7) mat[i][j] = -1;
            }
        }
    }
};

```

- Time Complexity: O(V³), where V is the number of vertices in the graph.
- Space Complexity: O(V²), as we need to store a distance matrix.


**Advantages:**

- All-Pairs Shortest Path: Unlike Dijkstra’s algorithm (which is single-source), Floyd-Warshall provides the shortest path between all pairs of vertices.
- Works with Negative Weights: It can handle negative weights, making it more versatile than algorithms like Dijkstra’s, which require non-negative weights.



---


### 2.8 Prim's Algorithm

---


### 2.9 Disjoint Set


---


### 2.10 Kruskal's Algorithm


---
