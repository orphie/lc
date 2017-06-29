class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        typedef vector<int>::iterator VecIt;
        size_t total = nums1.size() + nums2.size();
        size_t midId1   = total%2 ? total/2: total/2 - 1;
        size_t midId2   = total/2;

        // play with 4 iterators;
        VecIt n1BeginIt = nums1.begin();
        VecIt n1EndIt   = nums1.end();
        VecIt n2BeginIt = nums2.begin();
        VecIt n2EndIt   = nums2.end();

        int globalId = -1;
        bool midN1 = false;
        VecIt mid, other;
        int value;
        int value_another;
        while (globalId != midId1 &&
               globalId != midId2) {
            if ((n1EndIt-n1BeginIt) > (n2EndIt-n2BeginIt)) {
                midN1 = true;
            } else if ((n1EndIt-n1BeginIt) < (n2EndIt-n2BeginIt)){
                midN1 = false;
            } else {
                midN1 = !midN1;
            }

            mid   = midN1 ? n1BeginIt + (n1EndIt-n1BeginIt)/2 : n2BeginIt + (n2EndIt-n2BeginIt)/2;
            value = *mid;
            other = midN1 ? std::lower_bound (n2BeginIt, n2EndIt, value) : 
                            std::lower_bound (n1BeginIt, n1EndIt, value);
            
            size_t id1 = mid    - (midN1 ? nums1.begin() : nums2.begin());
            size_t id2 = other  - (midN1 ? nums2.begin() : nums1.begin());
            globalId = id1 + id2;
            
            if (globalId < midId1) {
                n1BeginIt = midN1 ? mid : other;
                n2BeginIt = midN1 ? other : mid;
            } else if (globalId > midId2) {
                n1EndIt = midN1 ? mid : other;
                n2EndIt = midN1 ? other :  mid;
            }   
        }   
        
        if (midId1 == midId2) {
            return value;
        }
        if (globalId == midId1) {
            //value_another should be equal to midId2 (bigger one)
            value_another = (mid == (midN1 ? nums1.end() : nums2.end())) || (mid+1 == (midN1 ? nums1.end() : nums2.end())) ? *other : 
                            (other == (midN1 ? nums2.end() : nums1.end())) ? *(mid+1) :
                            std::min(*(mid+1), *other);
        } else {
            value_another = (mid == (midN1 ? nums1.begin() : nums2.begin())) ? (*(other-1)) :
                            (other == (midN1 ? nums2.begin() : nums1.begin()))  ? (*(mid-1)) :
                            std::max(*(mid-1), *(other-1));
        }
        return (value_another+value)/2.0;
    }   
};
