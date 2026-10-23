## Algorithm 

1 Start the program.

2 Input the number of substations and proposed power lines.

3 Store the power lines and their weights in an adjacency matrix.

4 Ask the user whether to update an existing power line’s weight.

5 If an update is requested, modify the edge weight in both directions.

6 Initialize all vertices as unvisited and select a starting vertex.

7 Apply Prim’s algorithm to select the minimum-weight edge connecting a visited vertex to an unvisited vertex.

8 Display each selected edge, its weight, and the running total cost.

9 Repeat until \(V-1\) edges are selected or no connecting edge exists.

10 If fewer than \(V-1\) edges are selected, report that the graph is disconnected and a spanning tree cannot be formed.

11 Otherwise, display the final MST and total cost.

12 Stop the program.
