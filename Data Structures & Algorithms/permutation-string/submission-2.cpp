class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        if(s1.length() > s2.length()) { return false; }

        // get the freq array representation of s1
        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        // base case if first window iteration matches
        bool isEqual = ranges::equal(freq1, freq2);
        if(isEqual) { return true; }
        // slide the window one by one returning true if freq arrays match
        for(int i = s1.length(); i < s2.length(); i++) {
            // shift left pointer over one by reducing freq
            int l = i - s1.length();
            freq2[s2[l] - 'a']--;
            // shift right pointer over one by increasing freq
            freq2[s2[i] - 'a']++;
            bool isEqual = ranges::equal(freq1, freq2);
            if(isEqual) { return true; }
        }
        return false;
    }
};