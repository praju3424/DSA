class Solution {
   void dfs(int row ,int col ,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[row][col]=1;
    int n = grid.size();
    int m = grid[0].size();

    int nrow[] = {-1,1,0,0};
    int ncol[]={0,0,1,-1};
   


    for(int i=0; i<4; i++){
        int nr = row + nrow[i];
        int nc = col + ncol[i];
        if(nr>=0 && nc>=0 && nr< n && nc < m && grid[nr][nc]=='1' && !vis[nr][nc]){
            vis[nr][nc]=1;
            dfs(nr,nc,grid,vis);

        }
        
    }

}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));

        int cnt = 0;

        for(int i= 0; i<n; i++){
            
            for(int j =0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                   cnt++;
            dfs(i,j,grid,vis);
               
                }
            }
        }
        return cnt ;
    }
};