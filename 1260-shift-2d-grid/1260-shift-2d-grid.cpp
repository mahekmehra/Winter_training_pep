class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<int> res;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res.push_back(grid[i][j]);
            }
        }

        int size = n*m;
        k=k%size;
        reverse(res.begin(),res.end());
        reverse(res.begin(),res.begin()+k);
        reverse(res.begin()+k,res.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]  = res[i*m+j];
            }
        }

        return grid;
        
        
    }
};