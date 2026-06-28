class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int x = r + dx[i];
                int y = c + dy[i];

                if(x>=0 && y>=0 && x<n && y<m && ans[x][y]==-1){
                    ans[x][y] = ans[r][c] + 1;
                    q.push({x,y});
                }
            }
        }

        return ans;
        
    }
};