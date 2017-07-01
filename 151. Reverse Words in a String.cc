class Solution {
public:
    void reverseWords(string &s) {
        removeDuplicatedSpaces(s);
        reverse(s.begin(), s.end());
        reverseSingleWords(s);
    }
    
    inline void reverseSingleWords(string& s) {
        //Now reverse single word
        size_t posBegin = 0;
        size_t posEnd   = s.find(' ');
        while (posEnd != string::npos) {
            reverse(s.begin()+posBegin, s.begin()+posEnd);
            posBegin = posEnd + 1;
            posEnd = s.find(' ', posBegin);
        }   
        reverse(s.begin()+posBegin, s.end());
    }   

    inline void removeDuplicatedSpaces(string& s) {
        removeLeadingSpaces(s);
        string ret;
        bool spaceMode      = false;
        bool leadingSpace	= true;
        for (auto c : s) {
            if (c == ' ') {
                //in space mode, copy space only when out of space mode
                spaceMode = true;
            } else if (spaceMode) {
                ret += ' ';   
                ret += c;
                spaceMode = false;
            } else {
                ret += c;
            }   
        }   
        s = ret;
    }   

    inline void removeLeadingSpaces(string &s) {
        const auto strBegin = s.find_first_not_of(' ');
        if (strBegin != string::npos) {
            s = s.substr(strBegin);
        } else {
            s = ""; 
        }   
    }   
};
