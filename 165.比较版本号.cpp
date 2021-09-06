/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void loadversion(string& version, vector<int>& versionvec){
        int start = 0;
        int len = 0;
        for(int i = 0; i <= version.size(); i++){
            if(i == version.size() || version[i] == '.'){
                len = i - start;
                versionvec.push_back(stoi(version.substr(start, len)));
                start = i + 1;
            }
        }
    }

    int readversion(vector<int>& versionvec, int index){
        if(index < versionvec.size()) return versionvec[index];
        else return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<int> versionvec1;
        vector<int> versionvec2;
        loadversion(version1, versionvec1);
        loadversion(version2, versionvec2);
        int bound = max(version1.size(), version2.size());
        for(int i = 0; i < bound; i++){
            if(readversion(versionvec1, i) > readversion(versionvec2, i)){
                return 1;
            }else if(readversion(versionvec1, i) < readversion(versionvec2, i)){
                return -1;
            }
        }
        return 0;
    }
};
// @lc code=end

