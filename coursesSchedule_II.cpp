class Solution {
    bool findOrderUtil(int v, vector<int> & visited, stack<int> & Stack, vector<vector<int>>& adjList) {
        
        //if(visited[v] == 1)
          //  return false;
        
        visited[v] = 1;
        
        vector<int> :: iterator itr;
        for(itr = adjList[v].begin(); itr != adjList[v].end(); itr++) {
            if(visited[*itr] == 1) return false;
            if(visited[*itr] == 0) {
                if(!findOrderUtil(*itr, visited, Stack, adjList)) 
                    return false;
            }
        }
        
        visited[v] = 2;
        Stack.push(v);
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> courses = {0, 1, 2, 3};
        vector<int> coursesSchedule;
        vector<int> visited(numCourses, 0);
        stack<int> Stack;
        
        vector<vector<int>> adjList (numCourses);
        
        for(vector<int> & v : prerequisites) {
            adjList[v[1]].push_back(v[0]);
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0 && !findOrderUtil(i, visited, Stack, adjList)) {
                return {};
            }   
        }
        
        while(!Stack.empty()) {
            coursesSchedule.push_back(Stack.top());
            Stack.pop();
        }
        
        return coursesSchedule;
    }
};

/*
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
*/
