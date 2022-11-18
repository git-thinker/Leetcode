/*
 * @lc app=leetcode.cn id=1800 lang=rust
 *
 * [1800] 最大升序子数组和
 */

// @lc code=start
impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        let mut sum = 0;
        let mut cache = nums[0];
        for i in 1..nums.len(){
            if nums[i-1] < nums[i]{
                cache += nums[i];
            }else{
                if cache > sum{
                    sum = cache;
                }
                cache = nums[i];
            }
        }
        if cache > sum{
            sum = cache;
        }
        sum
    }
}
// @lc code=end

