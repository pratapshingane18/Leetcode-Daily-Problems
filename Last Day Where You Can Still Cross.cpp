class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();

        //checking if outside matrix or water
        if(x<0 || x==m || y<0 || y==n || grid[x][y]==1) return false;

        //if bottom reached return true
        if(x==m-1) return true;

        grid[x][y] = 1; //destroying land as dfs done and no need to do dfs on this again

        bool up = dfs(grid,x-1,y);
        bool down = dfs(grid,x+1,y);
        bool left = dfs(grid,x,y-1);
        bool right = dfs(grid,x,y+1);

        return up || down || left || right; //if any direction results in reaching bottom, return true
    }

    bool checkIfCanWalk(int row, int col, vector<vector<int>>& cells, int idx){
        //initializing grid and marking water cells 
        vector<vector<int>> grid(row,vector<int>(col,0));
        for(int i=0;i<=idx;i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        for(int i=0;i<col;i++){
            //applying dfs on each land in top row
            if(grid[0][i]==0 && dfs(grid,0,i)) return true;
        }

        //if no dfs results in true, then we cannot walk from top to down
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //simple bfs to check if can walk top to down if cells till mid index are marked water
        int i=0,j=cells.size()-1;
        int ans;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(checkIfCanWalk(row,col,cells,mid)){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        // return the last day on which we can walk top to down
        return ans+1;
    }
};
