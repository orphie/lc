class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> tNums2(nums2.begin(),nums2.end());
        std::set<int> uNums1(nums1.begin(),nums1.end());
        vector<int> ret;
        for (auto uit : uNums1) {
            if (tNums2.find(uit) != tNums2.end()) {
                ret.push_back(uit);
            }
        }
        return ret;
    }
};
