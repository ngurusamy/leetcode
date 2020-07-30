class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        if len(nums) == 0 : return [0,0]
        
        n = len(nums)
        vXor = 0
        
        for i in nums:
            vXor = vXor ^ i
        
        mask = (vXor & (vXor - 1)) ^ vXor
        
        num = 0
        
        for i in nums:
            if mask&i == 0 : num = num ^ i
           
        return [num,num ^ vXor]
        
