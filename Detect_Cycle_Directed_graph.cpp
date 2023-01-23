Question : Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not;

==========================================================================================================================================

Approach:  
LINK => 
  https://takeuforward.org/data-structure/detect-cycle-in-a-directed-graph-using-dfs-g-19/
Lets Consider the following graph:


We will be solving it using DFS traversal. DFS goes in-depth, i.e., traverses all nodes by going ahead, 
and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes. 
  
-----------------------------------------------
  
The algorithm steps are as follows:

We will traverse the graph component-wise using the DFS technique. 
---> Make sure to carry two visited arrays in the DFS call. One is a visited array(vis) and the other is a path-visited(pathVis) array. 
      The visited array keeps a track of visited nodes, and the path-visited keeps a track of visited nodes in the current traversal only. 
  
---> While making a DFS call, at first we will mark the node as visited in both the arrays and then will traverse through its adjacent nodes. 
     Now, there may be either of the three cases:

---> Case 1: If the adjacent node is not visited, we will make a new DFS call recursively with that particular node.
  
---> Case 2: If the adjacent node is visited and also on the same path(i.e marked visited in the pathVis array), we will return true;
      because it means it has a cycle, thereby the pathVis was true. Returning true will mean the end of the function call, 
      as once we have got a cycle, there is no need to check for further adjacent nodes. 
        
---> Case 3: If the adjacent node is visited but not on the same path(i.e not marked in the pathVis array),
      we will continue to the next adjacent node, as it would have been marked as visited in some other path, and not on the current one.
        
---> Finally, if there are no further nodes to visit, we will unmark the current node in the pathVis array and just return false.
      Then we will backtrack to the previous node with the returned value. The point to remember is, 
      while we enter we mark both the pathVis and vis as true, but at the end of traversal to all adjacent nodes, 
      we just make sure we unmark the pathVis and still keep the vis marked as true, as it will avoid future extra traversal calls. 
        
============================================================================================================================================        
        
CODE BELOW ::::

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}





