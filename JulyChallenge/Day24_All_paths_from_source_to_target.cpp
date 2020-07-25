/*

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

*/

//Code:

class Solution {
public:
    vector< vector<int> >allpaths;
    int vis[17],n;
    void dfs(vector<int>&currentpath , int node, vector<vector<int>>& graph){
        if(node == n-1){
            allpaths.push_back(currentpath);
            return;
        }
        for(auto x : graph[node]){
            if(vis[x] == 0){
                vis[x] = 1;
                currentpath.push_back(x);
                dfs(currentpath, x, graph);
                currentpath.pop_back();
                vis[x] = 0;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        memset(vis , 0 , sizeof(vis));
        vector<int>currentpath;
        currentpath.push_back(0);
        vis[0] = 1;
        dfs(currentpath , 0, graph);
        return allpaths;
    }
};
