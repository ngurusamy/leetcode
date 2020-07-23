class Solution {
private:
    void subSets(vector<int> & nums, int idx, vector<vector<int>> & results)
    {
        if(idx == nums.size() - 1) {
            results.push_back({});
            results.push_back({nums[idx]});
        }
        else
        {
            subSets(nums, idx + 1, results);
            int n = results.size();
            for(int i = 0; i < n; i++) 
            {
                vector<int> r = results[i];
                r.push_back(nums[idx]);
                results.push_back(r);
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        if(nums.empty())
            return {{}};
        vector<vector<int>> res;
        
        subSets(nums, 0, res);
        
        return res;
    }
    
        vector<vector<int>> subsets_itrMode(vector<int>& nums) {
        
        if(nums.empty())
            return {{}};
        vector<vector<int>> res = {{}};
        
        //subSets(nums, 0, res);
        for(int x : nums) {
            int n = res.size();
            for(int i = 0; i < n; i++) {
                vector<int> r = res[i];
                r.push_back(x);
                res.push_back(r);
            }
        }
        
        
        return res;
    }
};
