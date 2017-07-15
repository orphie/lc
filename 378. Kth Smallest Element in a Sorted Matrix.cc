class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::vector<int> help;
        for (const auto& elem : matrix) {
            help.insert(help.end(),elem.begin(),elem.end());   
        }   
        std::sort(help.begin(),help.end());
        return help[k-1];
    }   
};
