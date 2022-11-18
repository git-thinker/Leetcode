/*
 * @lc app=leetcode.cn id=769 lang=rust
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut ret = 0;
        arr.into_iter().enumerate().fold((0usize, 0), |mut c, item_pair|{
            c.0 += item_pair.0;
            c.1 += item_pair.1;
            if c.0 as i32 == c.1{
                ret += 1;
            }
            c
        });
        ret
    }
}
// @lc code=end

