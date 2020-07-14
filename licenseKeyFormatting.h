#include <string>

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
              
        S.erase(std::remove(S.begin(), S.end(), '-'), S.end());
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        
        //std::cout << "S : " << S << std::endl;
        size_t N = S.length();
        int init = N % K;
        string res;
        
        if(N < 2) 
            return S;
        
        if (init > 0) {
            for(size_t i = 0; i < init; i++)
            {
                res += S.at(i);
            }
            res += '-';
        }
        int count = 0;
        for(size_t i = init; i < N; i++) {
            //std::cout << "CNT : " << count << std::endl;
            res += S.at(i);
            count++;
            if(count == K && i < N - 1) {
                res += '-';
                count = 0;
            }
            
            
        }
        
        
        return res;       
    }
};

int main()
{
    //string S("5F3Z-2e-9-w");
    
    string S("2-5g-3-J");
    
    Solution sol;
    
    S = sol.licenseKeyFormatting(S, 2);
    
    std::cout << " S : " << S <<"\n";

    return 0;
}
