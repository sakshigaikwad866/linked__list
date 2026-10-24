## 1. Problem Statement

Develop a C++ program to represent electricity substations as vertices and proposed power lines as weighted edges. Implement Prim's algorithm to construct a Minimum Spanning Tree (MST). Modify the program to update the weight of an existing power line and recalculate the MST, display every selected power line with its weight and running total cost, and detect whether the graph is disconnected (meaning a spanning tree cannot be formed).


## 2. Approach

To solve this optimization problem, the system is designed using a graph-based structure implemented in C++. The step-by-step approach is as follows:

* Graph Representation:
  
* Represent the power grid network using an adjacency matrix where the row/column indices represent the electricity substations (vertices) and the cell values represent the cost/distance of the power lines (edge weights).
  
* Input and Initialization:
  
* Take user input for the total number of substations ($V$) and lines ($E$).
  
   * Initialize the adjacency matrix with a large value (infinity) to represent no initial connections.
     
* Edge Weight Update Mechanism:
  
* Provide an interactive menu asking the user if they wish to update the weight of an existing line.
  
   * Since the network is bidirectional (undirected graph), update the matrix value at both matrix[u][v] and matrix[v][u].
     
* Disconnected Graph Detection:
  
* Before or during the execution of Prim's algorithm, check if the graph is connected. If any vertex remains completely unreachable or if the MST cannot include all $V$ vertices, flag the network as disconnected and terminate with an error message stating that a spanning tree cannot be formed.
  
* Prim's Algorithm Implementation:
  
* Maintain a tracking array to keep track of visited vertices.
  
   * Start from an arbitrary substation (e.g., vertex 0) and mark it as visited.
     
   * In each iteration, find the minimum-weight edge that connects a visited vertex to an unvisited vertex.
     
   * Add this edge to the MST, mark the new vertex as visited, and update the running total cost dynamically.
     
* Output Generation:
  
* Display each selected power line along with its individual weight and the progressive running total cost after every step until the full tree is constructed.


## 3. Complexity Analysis

## Time Complexity

* Graph Initialization & Input: $\mathcal{O}(V^2)$ due to filling the $V \times V$ adjacency matrix.
  
* Prim's Algorithm (Adjacency Matrix): $\mathcal{O}(V^2)$ because we search for the minimum key vertex across all vertices $V$ times.
  
* Edge Weight Update: $\mathcal{O}(1)$ direct lookup and update in the matrix.
  
* Total Time Complexity: $\mathcal{O}(V^2)$, where $V$ is the number of substations.

## Space Complexity

* Adjacency Matrix: $\mathcal{O}(V^2)$ to store the edge weights between all vertices.
  
* Auxiliary Arrays: $\mathcal{O}(V)$ for storing visited states, minimum weights (key array), and parent trackers.
  
* Total Space Complexity: $\mathcal{O}(V^2)$.


## 4. Conclusion

The implemented program successfully models and optimizes an electricity substation network using an enhanced version of Prim's Algorithm. By leveraging an adjacency matrix, the system provides an efficient way to calculate the most cost-effective path to connect all substations. Furthermore, the inclusion of dynamic edge-weight updating allows the network to adapt to real-world alterations, while the disconnected graph check ensures robust error-handling when an optimal power grid layout is physically impossible to construct.
