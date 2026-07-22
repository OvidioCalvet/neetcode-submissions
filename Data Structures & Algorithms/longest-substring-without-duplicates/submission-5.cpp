class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // empty string base case
        if(s.size() == 1) return 1;

        set<char> set;
        int maxL = 0;
        int l = 0, r = 0;

        while(r < s.size()) {
            if(!set.contains(s[r])) {
                set.insert(s[r]);
                r++;
                // update max based on window size
                maxL = max(maxL, r - l);
            } else {
                set.erase(s[l]);
                l++;
            }
        }
        return maxL;
    }
};