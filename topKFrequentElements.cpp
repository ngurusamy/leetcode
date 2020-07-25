class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        
        sort(nums.begin(), nums.end());
        
        int x = nums[0], pos = 0, n = nums.size();
        
        auto cmp= [](pair<int, int> &a, pair<int, int> &b) {
            return (a.second < b.second);
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> PQ(cmp);
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != x) {
                PQ.push({x, i - pos});
                pos = i;
                x = nums[i];
            }
        }
        
        PQ.push({nums.back(), n - pos});
        
        for(int i = 0; i < k; i++) {
            res.push_back(PQ.top().first);
            PQ.pop();
        }
        
        return res;
    }
};
