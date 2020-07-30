class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int size = nums.size();
        int vXor = 0;
        //vector<int> result(2,0);
        
        for(int i = 0; i < size; i++) {
            vXor ^= nums[i];
        }
        
        int mask = (vXor & (vXor - 1) ) ^ vXor;
        int num = 0;
        
        for(int i = 0; i < size; i++){
            if((mask & nums[i]) == 0) num ^= nums[i];
        }
        
        //result[1] = result[0] ^ vXor;
        return {num, num ^ vXor};
    }
};
