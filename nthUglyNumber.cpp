class Solution {
public:
    int nthUglyNumber(int n) {
        unsigned int uglyNum[n];
        unsigned int i2 = 0, i3 = 0, i5 = 0;
        
        unsigned int next_multiple_of_2 = 2;
        unsigned int next_multiple_of_3 = 3;
        unsigned int next_multiple_of_5 = 5;
        
        unsigned int next_ugly_num = 1;
        
        uglyNum[0] = 1;
        
        for(int i = 1; i < n; i++) {
            //next_ugly_num = std::min(next_multiple_of_2, std::min(next_multiple_of_3, next_multiple_of_5));
            next_ugly_num = std::min({next_multiple_of_2, next_multiple_of_3, next_multiple_of_5});
            uglyNum[i] = next_ugly_num;
            
            if(next_ugly_num == next_multiple_of_2) {
                i2++;
                next_multiple_of_2 = uglyNum[i2]*2;
            }
            
            if(next_ugly_num == next_multiple_of_3) {
                i3++;
                next_multiple_of_3 = uglyNum[i3]*3;
            }
            
            if(next_ugly_num == next_multiple_of_5) {
                i5++;
                next_multiple_of_5 = uglyNum[i5]*5;
            }
        }
        
        return next_ugly_num;
        
    }
};
