class Solution {
public:

    void dfs(int i, int j,vector<vector<int>>& grid,queue<pair<int,int>>&q){

        
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;

        grid[i][j] = 2;
        q.push({i,j});
        dfs(i+1,j,grid,q);
        dfs(i,j+1,grid,q);
        dfs(i-1,j,grid,q);
        dfs(i,j-1,grid,q);

        
    }



    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        bool found = false;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !found){
                    dfs(i,j,grid,q);
                    found=true;
                }
            }
        }
        

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        int level=0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int row = q.front().first;
                int col  = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){

                    int x = row + dx[i];
                    int y = col + dy[i]; 

                    if(x>=0 && x<n && y>=0 && y<m){
                        if(grid[x][y]==0){
                            q.push({x,y});
                            grid[x][y]=2;
                        }
                        else if(grid[x][y]==1){
                            return level;
                        }
                    }
                }
            }
            level++;
        }
        return level;
        
    }
    
};