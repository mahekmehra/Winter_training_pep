class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int lc = 0;
        int rc = m-1;
        int ur = 0;
        int br = n-1;
        vector<int>ans;
        while(ur<=br && lc<=rc){
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[ur][i]);
            }
            ur++;

            for(int i=ur;i<=br;i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;

            if(ur<=br){
                for(int i=rc;i>=lc;i--){
                    ans.push_back(matrix[br][i]);
                }
                br--;
            }

            if(lc<=rc){
                for(int i=br;i>=ur;i--){
                    ans.push_back(matrix[i][lc]);
                }
                lc++;
            }
        }

        return ans;
        
    }
};