/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
 */
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;
// @lc code=start

const int N = 1e9+7;
class Comp_sort{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[0] != b[0]) return a[0] < b[0];
        else if(a[1] != b[1]) return a[1] < b[1];
        else if(a[2] != b[2]) return a[2] < b[2];
        else return a[3] < b[3];
    }
};

class Comp_heap{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[2] != b[2]) return a[2] > b[2];
        else return a[3] > b[3];
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        // sort into ascending order in accordance with x1 
        sort(rectangles.begin(), rectangles.end(), Comp_sort());

        // a small root 
        // 0/0;
        priority_queue<vector<int>, vector<vector<int>>, Comp_heap> heap;
        
        list<vector<int>> cache;

        long long int ret = 0;
        int scan_index = rectangles[0][0];
        int scanned_edge_length = rectangles[0][3] - rectangles[0][1];
        heap.push(rectangles[0]);
        cache.push_back({rectangles[0][1], rectangles[0][3]});
        auto i = ++rectangles.begin();
        while(!heap.empty() || i != rectangles.end()){
            if(heap.empty() || (!heap.empty() && i != rectangles.end() && (*i)[0] <= heap.top()[2])){
                // process next rect
                long long int operator_a = scanned_edge_length % N;
                long long int operator_b = ((*i)[0] - scan_index) % N;
                ret += (operator_a * operator_b) % N;
                ret %= N;
                scan_index = (*i)[0];
                heap.push((*i));
                update_cache(cache, {(*i)[1], (*i)[3]});
                scanned_edge_length = coverage(cache);
                scan_index = (*i)[0];
                i++;
            }else if(i == rectangles.end() || (!heap.empty() && i != rectangles.end() && heap.top()[2]) < (*i)[0]){
                // no more new rect
                long long int operator_a = scanned_edge_length % N;
                long long int operator_b = (heap.top()[2] - scan_index) % N;
                ret += (operator_a * operator_b);
                ret %= N;
                scan_index = heap.top()[2];
                vector<int> tmp = {heap.top()[1], heap.top()[3]};
                for(auto item = cache.begin(); item != cache.end(); item++){
                    if(*item == tmp){
                        cache.erase(item);
                        break;
                    }
                }
                scanned_edge_length = coverage(cache);
                heap.pop();
            }else{
                // cout << "oops";
            }
        }
        return ret;
    }

    void update_cache(list<vector<int>> &cache, vector<int> tmp){
        if(cache.empty()){
            cache.push_back(tmp);
            return;
        } 
        for(auto item = cache.begin(); item != cache.end(); item++){
            if((*item)[0] > tmp[0]){
                cache.insert(item, tmp);
                return;
            }
        }
        cache.push_back(tmp);
    }

    int coverage(list<vector<int>> &coverage_list){
        if(coverage_list.empty()) return 0;
        // [[y1, y2], [y1, y2]]
        int start = coverage_list.front()[0];
        int end = coverage_list.front()[1];
        int length = end - start;

        for(auto i = ++coverage_list.begin(); i != coverage_list.end(); i++){
            if(start <= (*i)[0] && (*i)[0] <= end){
                if(start <= (*i)[1] && (*i)[1] <= end){
                    // do nothing
                }else{
                    length += (*i)[1] - end;
                    end = (*i)[1];
                }
            }else{
                start = (*i)[0];
                end = (*i)[1];
                length += end - start;
            }
        }
        return length;
    }
};

// @lc code=end

