/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        std::map<int,int> start2Id;
        std::vector<int> starts;
        int id = 0;
        for (auto interval : intervals) {
            start2Id[interval.start] = id;
            starts.push_back(interval.start);
            ++id;
        }
        std::sort(starts.begin(),starts.end());
        std::vector<int> ret;
        for (auto interval : intervals) {
            auto it = lower_bound(starts.begin(),starts.end(),interval.end);
            if (it == starts.end()) {
                ret.push_back(-1);
            } else {
                ret.push_back(start2Id[*it]);
            }
        }
        return ret;
    }
};
