/*
 * @lc app=leetcode.cn id=1716 lang=golang
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
func totalMoney(n int) int {
	// 解析解
    var fullWeeks int = n / 7
    var modDays int = n % 7
    // for a week (start + start + 6) * 7 / 2 = 7 * start + 21
    // for n full weeks (28 + 7 * fullWeeks + 21) * fullWeeks / 2
    // for extra mod days (fullWeeks + 1 + fullWeeks + modDays) * modDays / 2
    return (2 * fullWeeks + 1 + modDays) * modDays / 2 + (28 + 7 * fullWeeks + 21) * fullWeeks / 2
}
// @lc code=end

