# C++ Data Structures and Algorithms Cheat Sheet

## Table of Contents

<!-- TOC -->
- [C++ Data Structures and Algorithms Cheat Sheet](#c-data-structures-and-algorithms-cheat-sheet)
	- [Table of Contents](#table-of-contents)
	- [1.0 Data Structures](#10-data-structures)
		- [1.1 Overview](#11-overview)
		- [1.2 Vector `std::vector`](#12-vector-stdvector)
		- [1.3 Deque `std::deque`](#13-deque-stddeque)
		- [1.4 List `std::list` and `std::forward_list`](#14-list-stdlist-and-stdforward_list)
		- [1.5 Map `std::map` and `std::unordered_map`](#15-map-stdmap-and-stdunordered_map)
		- [1.6 Set `std::set`](#16-set-stdset)
		- [1.7 Stack `std::stack`](#17-stack-stdstack)
		- [1.8 Queue `std::queue`](#18-queue-stdqueue)
		- [1.9 Priority Queue `std::priority_queue`](#19-priority-queue-stdpriority_queue)
		- [1.10 Heap `std::priority_queue`](#110-heap-stdpriority_queue)
	- [2.0 Trees](#20-trees)
		- [2.1 Binary Tree](#21-binary-tree)
		- [2.2 Balanced Trees](#22-balanced-trees)
		- [2.3 Binary Search](#23-binary-search)
		- [2.4 Depth-First Search](#24-depth-first-search)
		- [2.5 Breadth-First Search](#25-breadth-first-search)
	- [3.0 NP Complete Problems](#30-np-complete-problems)
		- [3.1 NP Complete](#31-np-complete)
		- [3.2 Traveling Salesman Problem](#32-traveling-salesman-problem)
		- [3.3 Knapsack Problem](#33-knapsack-problem)
	- [4.0 Algorithms](#40-algorithms)
		- [4.1 Insertion Sort](#41-insertion-sort)
		- [4.2 Selection Sort](#42-selection-sort)
		- [4.3 Bubble Sort](#43-bubble-sort)
		- [4.4 Merge Sort](#44-merge-sort)
		- [4.5 Quicksort](#45-quicksort)

<!-- /TOC -->

## 1.0 Data Structures
### 1.1 Overview

![Data Structures](https://github.com/user-attachments/assets/8566a718-2fbb-441e-a91d-986b7245213d)

![Complexity Chart](https://github.com/user-attachments/assets/8cd9ce90-567b-452a-a687-b997e42ff85c)

### 1.2 Vector `std::vector`

**Time Complexity**

| Operation    | Time Complexity |
|--------------|-----------------|
| Insert Head  |          `O(n)` |
| Insert Index |          `O(n)` |
| Insert Tail  |          `O(1)` |
| Remove Head  |          `O(n)` |
| Remove Index |          `O(n)` |
| Remove Tail  |          `O(1)` |
| Find Index   |          `O(1)` |
| Find Object  |          `O(n)` |

**Example Code**
```c++
vector<int> v;         // Empty vector
vector<int> v(5);      // Vector with 5 elements, default-initialized to 0
vector<int> v(5, 10);  // Vector with 5 elements, each initialized to 10
vector<int> v = {1, 2, 3}; // Vector initialized with 3 elements
vector<vector<int>> v(5, vector<int>(5, 0)) // 2D vector
vector<vector<int>> v(5, vector<int>(5, 0)) // 2D vector


//---------------------------------
// General Operations
//---------------------------------

// Size
int size = v.size();

// Empty
bool isEmpty = vec.empty(); // Check if the vector is empty

// Resize
vec.resize(10);  // Resize the vector to contain 10 elements

// Insert
v.insert(v.begin() + index, value);     // index
v.push_back(value);                     // tail

// Access head
int head = v.front();       // head
int value = v[index];       // index
int tail = v.back();        // tail

// Remove head, index, tail
v.erase(v.begin());             // head
v.erase(v.begin() + index);     // index
v.pop_back();                   // tail

// Clear
v.clear();

// Iterate
for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
}

// Range-based for loop (C++11 and above)
for (int x : vec) {
    std::cout << x << " ";
}

// Using iterators
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```


















