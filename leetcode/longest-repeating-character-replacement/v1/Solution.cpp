Impossible without the video >:|
https://www.youtube.com/watch?v=gqXU1UyA8pk

class Solution {
public:
    int characterReplacement(string s, int k) {
        uint16_t hash_map[26] = {0};
        uint16_t l = 0, maxf = 0, res = 0;

        for (uint16_t r = 0; r < s.size(); r++) {

            hash_map[s[r] - 'A']++;
            if (maxf < hash_map[s[r] - 'A'])
                maxf = hash_map[s[r] - 'A'];

            while (r - l + 1 - maxf > k) {
                hash_map[s[l] - 'A']--;
                l++;
            }
            if (res < r - l + 1)
                res = r - l + 1;

        }
        return res;
    }
};
