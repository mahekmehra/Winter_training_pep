class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));

        int ansmax = INT_MIN;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        vector<int>dx = {-1,1,0,0};
        vector<int>dy = {0,0,1,-1};

        while(!q.empty()){

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int cr = row + dx[i];
                int cc = col + dy[i];

                if(cr>=0 && cc>=0 &&  cr<n && cc<m && ans[cr][cc]==-1){
                    q.push({cr,cc});
                    ans[cr][cc] = ans[row][col]+1;
                    ansmax = max(ansmax,ans[cr][cc]);
                }
            }

            
        }
        return (ansmax==INT_MIN)? -1 : ansmax;

        
    }
};