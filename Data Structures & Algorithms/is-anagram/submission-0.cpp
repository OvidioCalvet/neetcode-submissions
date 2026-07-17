class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq;
        std::unordered_map<char, int> freqTwo;
        
        // base case
        if(s.length() != t.length()) return false;

        for(int i = 0; i < s.length(); i++) {
            // freq table for string s
            if(freq.find(s[i]) == freq.end())
                freq.emplace(s[i], 1);
            else freq[s[i]] += 1;

            // freq table for string t
            if(freqTwo.find(t[i]) == freqTwo.end())
                freqTwo.emplace(t[i], 1);
            else freqTwo[t[i]] += 1;
        }

        for(auto& letter : freq) {
            if(freqTwo.find(letter.first) == freqTwo.end()) return false;
            if(letter.second != freqTwo[letter.first]) return false;
        }

        return true;
    }
};
