/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include<vector>
#include<cmath>
using namespace std;
// @lc code=start
class NumArray {
public:
    vector<int> data;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        this->data = nums;
        this->tree = vector<int>(100000, 0);
        this->build(0, 0, this->data.size() - 1);
    }
    
    void update(int index, int val) {
        int delta = val - this->data[index];
        this->modify(index, delta, 0, 0, this->data.size() - 1);
        this->data[index] = val;
    }
    
    int sumRange(int left, int right) {
        return this->query(0, left, right, 0, this->data.size()-1);
    }

    int find_left(int index){return 2 * index + 1;}
    int find_right(int index){return 2 * index + 2;}
    void build(int index, int left, int right){
        if(left == right){
            this->tree[index] = this->data[left];
        }else if(left > right){
            return ;
        }else{
            int m = (left + right) / 2;
            build(this->find_left(index), left, m);
            build(this->find_right(index), m + 1, right);
            this->tree[index] = this->tree[find_left(index)] + this->tree[find_right(index)];
        }
    }

    int query(int index, int L, int R, int left, int right){
        if(L == left && R == right){
            return this->tree[index];
        }else{
            int m = (left + right) / 2;
            if(m + 1 <= L){
                return this->query(this->find_right(index), L, R, m + 1, right);
            }else if(m >= R){
                return this->query(this->find_left(index), L, R, left, m);
            }else{
                return this->query(this->find_left(index), L, m, left, m) + this->query(this->find_right(index), m + 1, R, m + 1, right);
            }
        }
    }

    void modify(int data_index, int delta, int index, int left, int right){
        this->tree[index] += delta;
        int m = (left + right) / 2;
        if(left == right){
            return ;
        }else if(data_index <= m){
            modify(data_index, delta, this->find_left(index), left, m);
        }else{
            modify(data_index, delta, this->find_right(index), m + 1, right);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

