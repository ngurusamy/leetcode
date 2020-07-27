class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        
        size_t len_a = a.length(), len_b = b.length();
        
        if(len_a < len_b) {
            size_t padding = len_b - len_a;
            a = string(padding, '0').append(a);
        }
        
        if(len_b < len_a) {
            size_t padding = len_a - len_b;
            b = string(padding, '0').append(b);
        }
        
        int carry = 0;
        //std::cout<< a.length() << " " << b.length() << "\n";
        for(int i = (a.length() - 1); i >= 0; --i) {  
            //std::cout << i << "  : \n";
            int l_a = a.at(i) - '0';
            int l_b = b.at(i) - '0';
            //std::cout<< l_a << " " << l_b << "\n";
           if(l_a + l_b + carry == 1) {
               //std::cout << "l_a + l_b + carry == 1 \n"; 
                result.push_back('1');
                carry = 0;
            } else if (l_a + l_b + carry == 2) {
               //std::cout << "l_a + l_b + carry == 2 \n"; 
                result.push_back('0');
                carry = 1;
            } else if (l_a + l_b + carry == 0) {
                //std::cout << "l_a + l_b + carry == 0 \n"; 
                result.push_back('0');
                carry = 0;
            } else if (l_a + l_b + carry > 2) {
                //std::cout << "l_a + l_b + carry > 2 \n"; 
                result.push_back('1');
                carry = 1;
            }
        }
        if(carry == 1)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return  result;
    }
};
