/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include<vector>
#include<map>
#include<set>
using namespace std;

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> cooling;
        map<char, int> tasks_remaining;
        set<char> task_list;
        int ret = 0;
        for(char task: tasks){
            if(task_list.find(task) == task_list.end()){
                task_list.insert(task);
                tasks_remaining[task] = 1;
                cooling[task] = 0;
            }else{
                tasks_remaining[task]++;
            }
        }
        while(!task_list.empty()){
            ret++;
            auto cursor = task_list.begin();
            auto mem = task_list.end();
            for(; cursor != task_list.end(); cursor++){
                if(ret - cooling[*cursor] > 0){
                    if((mem == task_list.end()) || (tasks_remaining[*mem] < tasks_remaining[*cursor])){
                        mem = cursor;
                    }
                }
            }
            if(mem != task_list.end()){
                cooling[*mem] = ret + n;
                tasks_remaining[*mem]--;
                if(!tasks_remaining[*mem]){
                    task_list.erase(mem);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

