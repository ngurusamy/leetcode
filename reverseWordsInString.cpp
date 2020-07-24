class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        regex re("\\s{2,}");
        s = regex_replace(s, re, " ");
        s = regex_replace(s, regex("^\\s+"), "");
        s = regex_replace(s, regex("\\s+$"), "");
        
        for(int i = 0; i < s.length(); i++) {
            
            if(s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        
        reverse(s.begin() + start, s.end());
        
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    string reverseWords_2(string s) { 
        string result;
        
        size_t len = s.length();
        
        size_t i = 0, j = 0, n = 0;
        
        while (i < (len)) {
            while(i < (len) && s[i] == ' ') i++;
            if(i >= len) break;
            j = i + 1;
        
            while( j < (len) && s[j] != ' ') j++;
        
            if(result.length() == 0)
                result = s.substr(i, j - i);
            else
                result = s.substr(i, j - i) + " " + result;
            
            i = j + 1;
        }
        
        return result;        
    }
};
