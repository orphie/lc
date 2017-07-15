class Solution {
public:
    bool isSubsequence(string s, string t) {
        for (char c : s) {
            if (!check(c,t)) return false;
        }
        return true;
    }
    
    bool check(char s, string& t)
    {
        #cout << t << "\t" << s << endl;
        size_t pos = t.find(s);
        if (pos != string::npos) {
            t = t.substr(pos+1);
            return true;
        }
        return false;
    }
};
