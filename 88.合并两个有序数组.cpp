/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        for(int k = 0; k < n; k++, nums1.pop_back());
        while(j < n){
            if(nums2[j] > nums1[i] && i < nums1.size()) i++;
            else{
                nums1.insert(nums1.begin()+i, nums2[j]);
                j++;
            }
        }
    }
};
// @lc code=end

