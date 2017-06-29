class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> curSet;
        size_t longest      = 0;
        size_t curLength    = 0;
        size_t startPoint   = 0;
        for (size_t id = 0; id < s.size(); ++id) {
            char cur = s[id];
            if (curSet.find(cur) != curSet.end() &&
                curSet[cur] >= startPoint) {
                    // well, fail
                    longest = curLength > longest ? curLength : longest;
                    curLength   = id - curSet[cur];
                    startPoint  = curSet[cur] + 1; 
                    curSet[cur] = id;
                    continue;
            }
            
            // pass, new char found!
            curSet[cur] = id;
            ++curLength;
        }
        return (longest > curLength) ? longest : curLength;
    }
};
