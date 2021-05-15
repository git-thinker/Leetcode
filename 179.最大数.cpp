/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
// @lc code=start
bool comp(const string &a, const string &b){
    string tmpa = a;
    string tmpb = b;
    tmpa.append(b);
    tmpb.append(a);
    for(int i = 0; i < tmpa.size(); i++){
        if(a[i] < b[i]) return true;
        if(a[i] > b[i]) return false;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> myNums;
        string ret;
        for(auto &item: nums){
            stringstream stream;  
            stream<<item;
            myNums.push_back(string());
            stream>>(*--myNums.end());
        }
        sort(myNums.begin(), myNums.end(), comp);
        for(auto &item: myNums)ret.append(item);
        return ret;
    }

};

// @lc code=end
int main(){
    vector<int> vec = {333133, 3331};
    Solution().largestNumber(vec);
    return 0;
}
