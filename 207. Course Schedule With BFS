class Solution {
public:
    typedef vector<pair<int, int>>          PreVec;
    typedef PreVec::const_iterator          PreIter;
    typedef std::vector<size_t>             Point2Weight;
    typedef Point2Weight::const_iterator    PwIter;
    typedef std::vector<std::vector<int>>   Id2Deps;
    typedef Id2Deps::const_iterator         MapIter;
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Id2Deps depends(numCourses, std::vector<int>());
        Point2Weight p2w(numCourses, 0);
        std::unordered_set<int> points;
        for (PreIter it = prerequisites.begin();
             it != prerequisites.end();
             ++it)  {
            depends[it->first].push_back(it->second);
            points.insert(it->first);
        }
        
        // graph has been build. Now check
        while (!points.empty()) {
            int cur = *(points.begin());
            points.erase(points.begin());
            const std::vector<int>& depend = depends[cur];
            for (std::vector<int>::const_iterator dit = depend.begin();
                 dit != depend.end();
                 ++dit) {
                int dep = *dit;
                p2w[dep] = std::max(p2w[dep], p2w[cur]+1);
                if (p2w[dep] >= numCourses) {
                    return false;
                }
                points.insert(dep);
            }
        }
        return true;
    }
};
