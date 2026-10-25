class Solution {
    private:
    void bfs(int row , int col,vector<vector<int>>& grid){
        //vis[row][col]=1;
        grid[row][col]=1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int ,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int nrow[] ={-1,0,1,0};
            int ncol[] ={0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int nr = nrow[i]+r;
                int nc = ncol[i]+c;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    // bfs(nr,nc,grid);
                    grid[nr][nc]=1;
                    q.push({nr,nc});

                }
            }
        }


    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        //vector<vector<int>>vis(int n , vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) bfs(i,0,grid);
            if(grid[i][m-1]==0) bfs(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0) bfs(0,i,grid);
            if(grid[n-1][i]==0) bfs(n-1,i,grid);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    cnt++;
                    bfs(i,j,grid);
                }
            }

        }
        return cnt;
    }
};