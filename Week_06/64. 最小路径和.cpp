class Solution {
public:
    /* 思路
        跟 62.不同路径 的思想差不多，下面列出动态规划三要素就明了了
        状态定义：dp[i][j]:方格[i][j]代表的最小路径和
        初始条件：dp[0][0] = grid[0][0]
                                dp[i-1][0] + grid[i][0],j==0,i>=1
        状态转移方程：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j],i,j>=1
                                dp[0][j-1] + grid[0][j],i==0.j>=1
     */
    typedef int DataType;
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        auto row = grid.size();
        auto column = grid[0].size();

        //申请动态数组
        DataType** dp = new DataType*[row];
        for(int i = 0; i < row; i++){
            dp[i] = new DataType[column];
        }

        //计算DP
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(j == 0 && i >= 1)dp[i][j] = dp[i-1][0] + grid[i][0];
                else if(i == 0 && j >= 1)dp[i][j] = dp[0][j-1] + grid[0][j];
                else if(i >= 1 && j >= 1)dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                else dp[i][j] = grid[i][j];//grid[0][0]
            }
        }

        return dp[row-1][column-1];
    }
};

