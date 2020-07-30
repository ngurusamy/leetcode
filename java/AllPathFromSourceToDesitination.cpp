class Solution {
    private void dfsUtil(int[][] graph, List<List<Integer>> result, List<Integer> path, int u) {
        path.add(u);
        if(u == graph.length - 1) result.add(new ArrayList(path));
        else for(int v : graph[u]) dfsUtil(graph, result, path, v);
        
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> result = new ArrayList();
        List<Integer> path = new ArrayList();
        dfsUtil(graph, result, path, 0);
        
        return result;
    }
}
