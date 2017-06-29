class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef std::unordered_map<int, int> Num2Id;
        Num2Id n2id;
        std::vector<int> ret;
        for (size_t id = 0;
             id < nums.size();
             ++id) {
            int current = nums[id];
            int minus   = target - current;
            
            if (n2id.find(minus) != n2id.end()) {
                // Got it
                ret.push_back(n2id[minus]);
                ret.push_back(id);
            } else {
                n2id[current] = id;
            }
        }
        return ret;
    }
};
