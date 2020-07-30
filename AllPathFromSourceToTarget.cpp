class Solution {
    void dfsUtil(vector<vector<int>> & graph, vector<vector<int>> & result, int u, vector<int> & path) {
        path.push_back(u);
        
        if(u == graph.size() - 1) result.push_back(path);
        else
            for(int v : graph[u]) dfsUtil(graph, result, v, path);
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> path;
        vector<vector<int>> results;
        dfsUtil(graph, results, 0, path);
        return results;
    }
};

/***
Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
****/
