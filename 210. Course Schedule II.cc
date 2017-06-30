class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Id to how many node it requires
        vector<int> id2Depends(numCourses, 0);
        // Id to nodes which require it
        vector< vector<int> > id2Depended(numCourses, vector<int>());
        for (vector<pair<int, int>>::const_iterator it = prerequisites.begin();
             it != prerequisites.end();
             ++it) {
            int src = it->first, tar = it->second;
            ++id2Depends[src];
            vector<int>& depended = id2Depended[tar];
            depended.push_back(src);            
        }
        
        vector<int> ret;
        collect(ret, id2Depended, id2Depends);
        return (ret.size() == numCourses) ? ret : vector<int>();
    }
    
    void 
    collect(vector<int>& ret, vector<vector<int>>& id2Depended, vector<int>& id2Depends)
    {
        unordered_set<int> done;
        for (size_t id = 0; id < id2Depends.size(); ++id) {
            if (done.find(id) != done.end()) {
                continue;
            }
            if (id2Depends[id] == 0) {
                ret.push_back(id);
                done.insert(id);
                explore(id, ret, id2Depended, id2Depends, done);
            }
        }
    }
    
    void 
    explore(int id, vector<int>& ret, vector<vector<int>>& id2Depended, vector<int>& id2Depends, 
            unordered_set<int>& done) 
    {
        vector<int>& depended = id2Depended[id];
        for (vector<int>::iterator it = depended.begin();
             it != depended.end();
             ++it) {
            int tar = *it;
            if (--id2Depends[tar] == 0) {
                ret.push_back(tar);
                done.insert(tar);
                explore(tar, ret, id2Depended, id2Depends, done);               
            }
        }
    }
};
