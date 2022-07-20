/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

#include<vector>
#include<cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // use a stack to simulate
        vector<int> stack;
        // discard incoming item or not
        bool discard;
        for(int i: asteroids){
            discard = false;
            if(stack.empty()){
                stack.push_back(i);
            }else{
                while(!stack.empty()){
                    // if two asteroids move in the same direction, keep both
                    if(stack.back() >= 0 && i >= 0 || stack.back() <= 0 && i <= 0){
                        break;
                    }else{
                        // if two asteroids move apart, keep both
                        if(stack.back() < 0 && i > 0){
                            break;
                        }
                        // if incoming asteroid over-weights former asteroid, keep incoming one
                        // incoming one needs to be compare to the former of former one
                        if(abs(stack.back()) < abs(i)){
                            stack.pop_back();
                        // if same, discard both
                        }else if(abs(stack.back()) == abs(i)){
                            discard = true;
                            stack.pop_back();
                            break;
                        }else{
                            // if former asteroid over-weights incoming asteroid, keep former one
                            discard = true;
                            break;
                        }
                    }
                }
                if(!discard){
                    stack.push_back(i);
                }
            }
        }
        return stack;
    }
};
// @lc code=end

