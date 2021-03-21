/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(long n) {
        long i = 2, j = n+1;
        long m;
        if(isBadVersion(1)) return 1;
        while(i < j){
            m = (i + j) / 2; 
            if(!isBadVersion(m-1) && isBadVersion(m)) return m;
            if(!isBadVersion(m-1) && !isBadVersion(m)) i = m + 1;
            else if(isBadVersion(m-1) && isBadVersion(m)) j = m;
        }
        return -1;
    }
};
// @lc code=end

