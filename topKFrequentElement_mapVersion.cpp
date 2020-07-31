class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
       
        //sort(nums.begin(), nums.end());
        
        unordered_map<int, int> counts;
        
        for(int i : nums) counts[i] += 1;
        
        int x = nums[0], pos = 0, n = nums.size();
        
        auto cmp= [](pair<int, int> &a, pair<int, int> &b) {
            return (a.second < b.second);
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> PQ(cmp);
        /*
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
        */
        
        for(pair p : counts) PQ.push(p);
        
        for(int i = 0; i < k; i++) {
            res.push_back(PQ.top().first);
            PQ.pop();
        }
        return res;
    }
};

/**********************
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

***************************/
