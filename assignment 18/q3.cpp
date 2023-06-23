//Leetcode solution of the question as the isBadVersion is already defined so i have
//directly written the solution here without the main function.

class Solution {
public:
    
    int find(int start, int end) {
        if(start>end) {
            return -1;
        }
        
        int mid = start+(end-start)/2;
        bool isBad = isBadVersion(mid);
        if(isBad && (mid == 0 ||  !isBadVersion(mid-1))) {
            return mid;
        }
        
        if(isBad) {
           return find(start, mid-1);
        } else {
            return find(mid+1, end);
        }
        
    }
    
    int firstBadVersion(int n) {
        
        return find(1, n);
        
    }
};