class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int n=grid.size(), m=grid[0].size();
        int stx, sty, keys=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='@')
                {
                    stx=i;
                    sty=j;
                }
                if(grid[i][j]>='a' && grid[i][j]<='z') keys++;
            }
        }
        int mask=0;
   
        map<pair<int, int>, unordered_set<int>> vis;
        queue<pair<pair<int, int>, int>> q; 
        q.push({{stx, sty}, mask});
        vis[{stx, sty}].insert(mask);
        int ans=0;
        int dx[4]={1, -1, 0, 0};
        int dy[4]={0, 0, 1, -1};
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto t=q.front();
                q.pop();
                int x=t.first.first;
                int y=t.first.second;
                mask=t.second;
                if(grid[x][y]>='a' && grid[x][y]<='z')
                {
                    mask |= (1<<(grid[x][y]-'a'));
                }
                if(mask==(1<<keys)-1) return ans;
                for(int dir=0; dir<4; dir++)
                {
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]=='#')
                    {
                        continue;
                    }
                    if(grid[nx][ny]>='A' && grid[nx][ny]<='Z' 
                        && !(mask&(1<<(grid[nx][ny]-'A'))))
                    {
                        continue;
                    }
                    if(vis[{nx, ny}].find(mask)==vis[{nx, ny}].end())
                    {
                        q.push({{nx, ny}, mask});
                        vis[{nx, ny}].insert(mask);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
