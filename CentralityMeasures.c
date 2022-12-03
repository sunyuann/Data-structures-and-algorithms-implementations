// Centrality Measures ADT interface
// COMP2521 Assignment 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "CentralityMeasures.h"
#include "FloydWarshall.h"
#include "Graph.h"

/**
 * Finds  the  edge  betweenness  centrality  for each edge in the given
 * graph and returns the results in a  EdgeValues  structure.  The  edge
 * betweenness centrality of a non-existant edge should be set to -1.0.
 */
EdgeValues edgeBetweennessCentrality(Graph g) {
	EdgeValues e;
	
	// get next array
	ShortestPaths sps = FloydWarshall(g);
	
	// get num of vertices in graph
	e.numNodes = GraphNumVertices(g);
	
	// initialise values array to -1.0 if no edge(u,v), 0.0 if edge exists
	e.values = (double **)(malloc(e.numNodes * sizeof(double *)));
	for (int i = 0; i < e.numNodes; i++) {
	    e.values[i] = (double *)(malloc(e.numNodes * sizeof(double)));
	}
	for (int i = 0; i < e.numNodes; i++) { 
	// initialise all to -1.0 first
	    for (int j = 0; j < e.numNodes; j++) {
            e.values[i][j] = -1.0;
	    }
	}
	
	// if edge(u,v), change e.values[u][v] to 0.0
	for (int i = 0; i < e.numNodes; i++) { 
	    for (AdjList temp = GraphOutIncident(g, i); temp != NULL; temp = temp->next) {
	        e.values[i][temp->v] = 0.0;
	    }
	}
	for (int i = 0; i < e.numNodes; i++) {
	    for (AdjList temp = GraphInIncident(g, i); temp != NULL; temp = temp->next) {
	        e.values[temp->v][i] = 0.0;
	    }
	}

    // perform centrality measure for all possible paths
	for (int i = 0; i < e.numNodes; i++) {
	    for (int j = 0; j < e.numNodes; j++) {
	        // loop through each path[i][j] in graph via double loop
	        if (sps.next[i][j] != -1) {
	            for (int temp = i; temp != j; temp = sps.next[temp][j]) {
	                // if path exists, add 1 to all edges in path[i][j]
	                e.values[temp][sps.next[temp][j]]++;
	             }
            }
	    }
	}
	return e;
}

/**
 * Prints  the  values in the given EdgeValues structure to stdout. This
 * function is purely for debugging purposes.
 */
void showEdgeValues(EdgeValues evs) {

}

/**
 * Frees all memory associated with the given EdgeValues  structure.  We
 * will call this function during testing, so you must implement it.
 */
void freeEdgeValues(EdgeValues evs) {
    // free evs.values (2d array)
	for (int i = 0; i < evs.numNodes; i++) {
	    free(evs.values[i]);
	}
	free(evs.values);
}


