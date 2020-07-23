class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     
        uint32_t res = 0;
        int bitShift = 32;
        
        while (bitShift > 0) {
            res <<= 1;
            
            if(n & 1 == 1) 
                res ^= 1;
            n >>= 1;
            bitShift--;
        }
        
        return res;
         
    }
};
