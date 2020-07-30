class Solution {
    public int[] singleNumber(int[] nums) {
        if(nums.length == 0) return new int[2];
        
        
        int size = nums.length;
        int vXor = 0;
        int[] result = new int[2];
        
        for(int num : nums) {
            vXor ^= num;
        }
        
        int mask = (vXor & (vXor - 1) ) ^ vXor;
        int num = 0;
        
        for(int i = 0; i < size; i++){
            if((mask & nums[i]) == 0) result[0] ^= nums[i];
        }
        
        result[1] = result[0] ^ vXor;
        return result;
 
    }
}
