class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i,j,k,c=0,s=0;
        for(i=0;i<mat.size();i++){
            c+=mat[i][i];
            if(i!=mat.size()-i-1)
            c+=mat[mat.size()-i-1][i];
        }
        return c;
        
    }
};
