class Solution {
    
    private boolean findOrderUtil(int u, List<Integer>[] adj, List<Integer>s, int[] visited) {
        
        visited[u] = 1;
        
        for(int i : adj[u]) {
            if(visited[i] == 1) return false;
            if(visited[i] == 0 && !findOrderUtil(i, adj, s, visited)) return false;
        }
        
        visited[u] = 2;
        
        s.add(u);
        
        return true;
    }
    
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<Integer>[] adj = new LinkedList[numCourses];
        
        for(int i = 0; i < numCourses; i++) {
            adj[i] = new LinkedList<Integer>();
        }
        
        for(int [] courses : prerequisites) {
            adj[courses[1]].add(courses[0]);
        }
        
        List<Integer> s = new LinkedList();
        int [] visited = new int[numCourses];
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0 && !findOrderUtil(i, adj, s, visited)) return new int[0];
        }
        
        Collections.reverse(s);
        
        int[] results = s.stream().mapToInt(Integer::intValue).toArray();
        return results;
        
    }
}
