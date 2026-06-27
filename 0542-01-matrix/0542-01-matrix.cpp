class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){

                int x = row + dx[i];
                int y = col + dy[i];

                if(x>=0 && y>=0 && x<n && y<m && ans[x][y]==-1){

                    q.push({x,y});
                    ans[x][y] = ans[row][col] + 1;

                }
            }
        }

        return ans;
        
    }
};