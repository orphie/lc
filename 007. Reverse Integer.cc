class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while (x!=0) {
            long long cur = x%10;
            ret = ret*10 + cur;
            x   = x/10;
        }
        return (ret<INT_MIN || ret>INT_MAX) ? 0 : static_cast<int>(ret);
    }
};
