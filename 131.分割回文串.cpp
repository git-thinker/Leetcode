/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        set<vector<string>> ansSet;
        vector<string> initial;
        for(auto chars:s){
            string charss(1, chars);
            initial.push_back(charss);
        }
        ansSet.insert(initial);
        this->recursive(initial, ansSet);
        return vector<vector<string>>(ansSet.begin(), ansSet.end());
    }

    void recursive(vector<string> initial, set<vector<string>>& ansSet){
        if(initial.size() == 1) return;
        for(int i = 0; i < initial.size()-1; ++i){
            if(isSymmetric(initial[i], initial[i+1])){
                vector<string> scopy = vector<string>(initial.begin(), initial.end());
                scopy[i] = scopy[i] + scopy[i+1];
                scopy.erase(scopy.begin()+i+1);
                int length = ansSet.size();
                ansSet.emplace(scopy);
                if(length != ansSet.size()){
                    recursive(scopy, ansSet);
                }
            }
            if(i > 0  && isSymmetric(initial[i-1], initial[i+1])){
                vector<string> scopy = vector<string>(initial.begin(), initial.end());
                scopy[i] = scopy[i-1] + scopy[i] + scopy[i+1];
                scopy.erase(scopy.begin()+i+1);
                scopy.erase(scopy.begin()+i-1);
                int length = ansSet.size();
                ansSet.emplace(scopy);
                if(length != ansSet.size()){
                    recursive(scopy, ansSet);
                } 
            }
        }
    }

    bool isSymmetric(string& s0, string& s1){
        if(s0.size() != s1.size()) return false;
        auto iteratorS0 = s0.begin();
        auto iteratorS1 = s1.rbegin();
        for(; iteratorS0 != s0.end(); iteratorS0++, iteratorS1++){
            if(*iteratorS0 != *iteratorS1) return false;
        }
        return true;
    }
};
// @lc code=end

