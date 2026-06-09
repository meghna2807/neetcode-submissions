class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>> &grid,int &cnt){
        vis[i][j] = 1;

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];

            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && !vis[ni][nj] && grid[ni][nj] == 1){
                cnt++;
                dfs(ni,nj,vis,grid,cnt);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int cnt = 1;
                    dfs(i,j,vis,grid,cnt);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
