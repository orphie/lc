class Solution {
public:
    bool isMatch(string s, string p) {
        //merge '**'
        p = polish(p);
        return isMatchEnc(s, p, '\0');
    }   

    bool isMatchEnc(const string& s, const string& p, char pre) {
        //cout << "Testing:\t" << s << "\t" << p << "\t\t" << pre << endl;
        if (s.empty()) {
            if (p.empty() || p == "*") {
                return true;
            }
            
            if (p.size() > 1 &&
                p[1] == '*') {
                if (isMatchEnc(s, p.substr(2), '\0')) {
                    return true;
                }
            }
            
            if (p.size() > 0 &&
                p[0] == '*') {
                if (isMatchEnc(s, p.substr(1), '\0')) {
                    return true;
                }                    
            }
            
            return false;
            
        }   
            
        if (!s.empty() && p.empty()) {
            return false;
        }   
        
        #if 1
        if (s[s.size()-1] != p[p.size()-1]  &&
            '.' != p[p.size()-1]            &&
            '*' != p[p.size()-1]) {
            return false;
        }
        #endif
        // both s && p has value

        // equal without '.'
        if (s[0] == p[0]) {
            if (isMatchEnc(s.substr(1), p.substr(1), p[0])) {
                return true;
            }
        }   
            
        // equal with '.'
        if (p[0] == '.') {
            if (isMatchEnc(s.substr(1), p.substr(1), p[0])) {
                return true;
            }
        }   
            
        // well, *
        if (p[0] == '*') {
            if (s[0] == pre) {
                if(isMatchEnc(s.substr(1), p, pre)) {
                    return true;
                }
            }   

            if (pre == '.') {
                // well, .*
                if (isMatchEnc(s.substr(1), p, pre)) {
                    return true;
                } else if (isMatchEnc(s, p.substr(1), '\0')) {
                    return true;
                }
            }
            
            
            if (isMatchEnc(s, p.substr(1), '\0')) {
                return true;
            }        
            
        }

        // try eliminate current p char
        if (p.size() > 1    &&
            p[1] == '*') {
            if (isMatchEnc(s, p.substr(2), '\0')) {
                return true;
            }
        }
        // simple not match
        return false;
    }

    inline string
    polish(const string& p)
    {
        size_t beginPos = 0;
        size_t pos = p.find('*');
        std::string ret("");
        while (pos != std::string::npos) {
            ret += p.substr(beginPos, pos - beginPos + 1);

            beginPos = pos + 1;
            while ((beginPos != p.size()) &&
                   (p[beginPos] == '*')) {
                ++beginPos;
            }

            if (beginPos == p.size()) {
                return ret;
            }
            pos = p.find('*', beginPos);
        }

        ret += p.substr(beginPos);
        //cout << "ret\t" << ret << endl;
        return ret;
    }
};
