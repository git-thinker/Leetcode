/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include<vector>
#include<stack>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> myStack;
        hash_map<int, int> myMap;
        for(int item:nums2){
            if(myStack.empty()){
                myStack.push(item);
            }else{
                while(!myStack.empty() && myStack.top() < item){
                    myMap[myStack.top()] = item;
                    myStack.pop();
                }
                myStack.push(item);
            }
        }

        while(!myStack.empty()){
            myMap[myStack.top()] = -1;
            myStack.pop();
        }

        for(int item:nums1){
            auto result = myMap.find(item);
            if(result == myMap.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(result->second);
            }
        }

        return ans;
    }

    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> ans;
    //     int i, j;
    //     bool flag = false;
    //     for(i = 0; i < nums1.size(); ++i){
    //         for(j = 0; j < nums2.size(); ++j){
    //             if(nums1[i] == nums2[j]) flag = true;
    //             if(flag && nums2[j] > nums1[i]){
    //                 ans.push_back(nums2[j]);
    //                 break;
    //             }
    //         }
    //         if(j == nums2.size()){
    //             ans.push_back(-1);
    //         }
    //         flag = false;
    //     }
    //     return ans;
    // }
};
// @lc code=end

