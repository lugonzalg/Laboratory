class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        uint8_t max = 0, len = 0;
        uint8_t uom[256] = {0};
        
        for (uint16_t i = 0; i < s.size(); i++) {
            
            len = 0;
            memset(&uom, 0, 256);
            for (uint16_t j = i; j < s.size(); j++) {
                
                
                if (!uom[s[j]]) {
                    len++;
                    uom[s[j]] = 1;
                } else {
                    break ;
                }
            }
            if (max < len)
               max = len;
        }
        if (len > max)
            return len;
        return max;
    }
};
