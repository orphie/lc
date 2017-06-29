class Solution {
public:
    typedef vector<pair<int, int>> PreVec;
    typedef PreVec::const_iterator PreIter;
    typedef std::unordered_map<int, std::unordered_set<int>> Id2Deps;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Id2Deps depends;
        for (PreIter it = prerequisites.begin();
             it != prerequisites.end();
             ++it)
        {
            int src = it->first;
            int tar = it->second;
            if (isDepends(tar, src, depends)) {
                return false;
            }
            // all right tar doesn't depends on src.
            depends[src].insert(tar);
            depends[src].insert(depends[tar].begin(), depends[tar].end());
        }
        return true;
    }
    inline bool isDepends(int tar, int src, Id2Deps& depends)
    {
        std::unordered_set<int>& depSet = depends[tar];
        if (depSet.find(src) != depSet.end()) {
            return true;
        }
        for (std::unordered_set<int>::const_iterator it = depSet.begin();
             it != depSet.end();
             ++it) {
            if (isDepends(*it, src, depends)) {
                return true;
            }         
        }
        return false;
    }
};
