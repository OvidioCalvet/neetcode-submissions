class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int max = 0;
        int l = 0;
        int r = 0;
        
        while (r < s.length()) {               
            // update freq of char
            freq.insert({s[r], 0});
            freq[s[r]]++;
            // find most freq char
            int freqCount = 0;
            for (const auto& c : freq) {
                if (c.second > freqCount)
                    freqCount = c.second;
            }
            // resize window depending on most freq char
            int size = r - l + 1;
            if (size - freqCount > k) {
                size--;
                freq[s[l]]--;
                l++;
                r++;
            } else {
                r++;
            }
            // update map if possible
            if (size > max) { max = size; }
        }
        return max;
    }
};