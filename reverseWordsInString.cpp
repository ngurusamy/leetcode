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
};
