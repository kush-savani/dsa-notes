# C++ Data Structures Cheat Sheet

## Table of Contents

- [1.1 Overview](#11-overview)
- [1.2 Vector `std::vector`](#12-vector-stdvector)
- [1.3 Map `std::map` and `std::unordered_map`](#15-map-stdmap-and-stdunordered_map)
- [1.6 Set `std::set`](#16-set-stdset)
- [1.7 Stack `std::stack`](#17-stack-stdstack)
- [1.8 Queue `std::queue`](#18-queue-stdqueue)
- [1.9 Priority Queue `std::priority_queue`](#19-priority-queue-stdpriority_queue)
- [1.10 Heap `std::priority_queue`](#110-heap-stdpriority_queue)

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

-------------------------------------------------------
### 1.3 Map `std::map` and `std::unordered_map`

**Notes**
* Typically ordered maps (`std::map`) are slower than unordered maps (`std::unordered_map`)
* Maps are typically implemented as *binary search trees*
* `std::map`
    * Ordered map
* `std::unordered_map`
    * Hash table

**Time Complexity**

**`std::map`**

| Operation           | Time Complexity |
|---------------------|-----------------|
| Insert              |     `O(log(n))` |
| Access by Key       |     `O(log(n))` |
| Remove by Key       |     `O(log(n))` |
| Find/Remove Value   |     `O(log(n))` |

**`std::unordered_map`**

| Operation           | Time Complexity |
|---------------------|-----------------|
| Insert              |          `O(1)` |
| Access by Key       |          `O(1)` |
| Remove by Key       |          `O(1)` |
| Find/Remove Value   |              -- |


**Example Code**
```c++
#include <iostream>
#include <map>
using namespace std;

map<int, string> m;  // Declaring a map of int keys and string values
unordered_map<int, string> um;  // Declaring an unordered_map of int keys and string values

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(make_pair(1, "One"));
m[2] = "Two";  // Using [] operator for insertion

// Access by key
cout << m.at(1);  // Output: One
cout << m[2];      // Output: Two

// Size
int size = m.size();

// Empty
cout << m.empty();  // Check if map is empty


// Iterate
// Iterating through the map
for (const auto& pair : m) {
  cout << pair.first << ": " << pair.second << endl;
}

// Remove by key
m.erase("key");

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Find if an element exists by key
bool exists = (m.find("key") != m.end());

// Count the number of elements with a certain key
unsigned int count = m.count("key");
```


