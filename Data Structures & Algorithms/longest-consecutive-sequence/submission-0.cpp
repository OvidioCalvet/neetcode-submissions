class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longCon = 0;

        for(int& n : nums) {
            // if no prev num then its the start of a sequence therefore start counting
            if(s.find(n - 1) == s.end()) {
                int count = 1;
                // while their is a next num increase count by 1
                while(s.find(n + count) != s.end())
                    count++;

                // compare curr sequence with curr longest and update
                longCon = max(longCon, count);
            }
        }

        return longCon;
    }
};