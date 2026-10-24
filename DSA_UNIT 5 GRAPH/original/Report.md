## Problem Statement

Develop a C++ program to represent city electricity substations as vertices and proposed power lines as weighted edges in a graph. Apply Prim's Algorithm to construct a Minimum Spanning Tree (MST) that connects all substations with the minimum total power line length or cost. Finally, display the selected power lines along with their respective weights and calculate the total optimized cost.

## Approach

The problem is solved using a greedy graph optimization technique known as Prim's Algorithm. The graph is represented using an adjacency matrix, where rows and columns signify substations, and cell values represent the cost/length of power lines between them (with 0 or infinity denoting no direct connection).

   1. Initialization:
      
   * Maintain a boolean array visited[] to track substations included in the MST.
     
      * Maintain a key[] array initialized to infinity (INT_MAX) to store the minimum edge weight to connect each vertex to the growing MST.
        
      * Set the key value of the first vertex (root) to 0 and its parent to -1.
        
   2. MST Construction:
      
   * Loop $V - 1$ times (where $V$ is the total number of substations).
     
      * In each iteration, pick a non-visited vertex u that has the minimum key value.
        
      * Mark u as visited to include it in the MST network
        
   3. Weight Update:

   * Update the key values and parent index of all non-visited adjacent vertices of u if the weight of edge (u, v) is smaller than the current key value of v.
     
   4. Output Generation:
      
   * Print the selected edges forming the final power grid network using the parent array and compute the cumulative sum of their weights to find the total minimum cost.
     
   

## Complexity Analysis

* Time Complexity:
  
* $O(V^2)$ when using an adjacency matrix representation and a linear search to find the minimum key vertex in each step. This is efficient and optimal for dense graphs representing localized city power grids.
  
   * (Can be optimized to $O(E \log V)$ using an adjacency list combined with a min-priority queue/heap).
     
* Space Complexity:
  
* $O(V^2)$ to store the adjacency matrix representation of the substation network, along with $O(V)$ auxiliary space for tracking structural arrays (visited, key, and parent).


## Conclusion

By implementing Prim's Algorithm, we successfully modeled and designed an optimized, cost-effective electricity substation distribution network. The algorithm systematically constructed a Minimum Spanning Tree, ensuring all city substations are fully interconnected with no redundant closed loops (cycles) while minimizing the total deployment cost and structural length of the power cables.
