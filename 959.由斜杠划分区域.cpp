/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class UnionFind{
	public:
		vector<int> myMap;
		int m, n;
		UnionFind(vector<string>& grid){
			this->m = grid.size();
			if(!this->m) return ;
			this->n = grid[0].size();
			for(int i = 0; i < this->m * this->n * 4; i++){
				this->myMap.push_back(i);		
			}

			for(int i = 0; i < this->m; i++){
				for(int j = 0; j < this->n; j++){
					if(grid[i][j] == ' '){
                        this->unite(i, j, 0, i, j, 1);
                        this->unite(i, j, 1, i, j, 2);
                        this->unite(i, j, 2, i, j, 3);
                    }
                    if(grid[i][j] == '/'){
                        this->unite(i, j, 0, i, j, 3);
                        this->unite(i, j, 1, i, j, 2);
                    }
                    if(grid[i][j] == '\\'){
                        this->unite(i, j, 0, i, j, 1);
                        this->unite(i, j, 2, i, j, 3);
                    }
                    if(j + 1 != this->n){
                        this->unite(i, j, 1, i, j + 1, 3);
                    }
                    if(i + 1 != this->m){
                        this->unite(i, j, 2, i + 1, j, 0);
                    }
				}		
			}
		}
		
		int Find(int index){
			while(this->myMap[index] != index) index = this->myMap[index];
			return index;
		}

		void Union(int index0, int index1){
			this->myMap[this->Find(index0)] = this->Find(index1);
		}

		void unite(int x0, int y0, int z0, int x1, int y1, int z1){
			this->Union((x0*this->n+y0)*4+z0, (x1*this->n+y1)*4+z1);
		}

        int count(){
            int ans = 0;
            for(int i = 0; i < this->m * this->n * 4; i++){
				if(this->myMap[i] == i) ++ans;
			}
            return ans;
        }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        UnionFind myUnionFind = UnionFind(grid);
        return myUnionFind.count();
    }
};
// @lc code=end

