class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> sqrs;

        // iter through row
        for(int r = 0; r < 9; r++) {
            //iter through col at curr row
            for(int c = 0; c < 9; c++) {
                // set vals
                char val = board[r][c];
                pair<int, int> sqKey = {r/3, c/3};

                // base case
                if(val == '.') continue;

                // check duplicates
                if(rows[r].count(val) || cols[c].count(val) || sqrs[sqKey].count(val))
                    return false;

                // no duplicates, emplace and continue
                rows[r].insert(val);
                cols[c].insert(val);
                sqrs[sqKey].insert(val);
            }
        }
        return true;
    }
};