class Solution {
public:
    bool isPalindrome(string s) {
        // two pointers
        int i = 0;
        int j = s.size() - 1;

        while(i < j) {
            if(!isValid(s[i])) {
                i++;
                continue;
            }
            if(!isValid(s[j])) {
                j--;
                continue;
            }

            if(tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        return true;
    }

    bool isValid(char c) {
        if(c >= 'A' && c <= 'Z')
            return true;
        if(c >= 'a' && c <= 'z')
            return true;
        if(c >= '0' && c <= '9')
            return true;

        return false;
    }
};