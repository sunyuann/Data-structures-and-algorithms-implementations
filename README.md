# Data-structures-and-algorithms-implementations

Centrality Measures:
  Finds the edge betweenness centrality for each edge in the given graph and returns the results in a EdgeValues structure. The edge betweenness centrality of a non-existent edge is set to -1.0.

Floyd Warshall algorithm:
  Finds the shortest paths between all pairs of nodes using the Floyd Warshall algorithm (returns ShortestPaths structure with the number of vertices in the graph, a distance matrix and the matrix of intermediates).

Girvan-Newman algorithm for community discovery:
  The algorithm progressively removes edges from the original network until communities of connected components in the remaining network are formed. This algorithm first calculates the betweenness of all existing edges in the network, and then removes the edge(s) with the highest betweenness. The betweenness of the edges affected by the removal is then recalculated. These steps are repeated until no edges remain, which results in a dendrogram. This dendrogram is produced from the top down, where the leaves of the dendrogram are the individual nodes.
