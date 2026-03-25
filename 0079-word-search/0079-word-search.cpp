class Solution {
public:

    bool dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited,string word,int point){

        

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j]==true || board[i][j]!=word[point])return false;

        if(point==word.size()-1){
            if(board[i][j]==word[word.size()-1]) return true;
            else return false;
        }

        visited[i][j] = true;
        

        bool b = dfs(i+1,j,board,visited,word,point+1);
        bool u = dfs(i-1,j,board,visited,word,point+1);
        bool r = dfs(i,j+1,board,visited,word,point+1);
        bool l = dfs(i,j-1,board,visited,word,point+1);
        
        visited[i][j] = false;
        return (b||u||r||l);
    }



    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,visited,word,0)) return true;
                }
            }
        }

        return false;
    }
};