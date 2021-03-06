/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<algorithm>
#include<set>
#include<map>
#include<hash_set>
#include<hash_map>
#include<iterator>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        vector<int> ans = vector<int>(length, -1);
        stack<pair<int, int>> myStack; 
        for(int i = 0; i < nums.size(); ++i){
            if(i >= length && myStack.empty()) break;
            while(!myStack.empty() && myStack.top().second < nums[i]){
                if(myStack.top().first < length){
                    ans[myStack.top().first] = nums[i];
                }
                myStack.pop();
            }
            myStack.push(pair<int, int>(i, nums[i]));   
        }
        return ans;
    }
};
// @lc code=end

