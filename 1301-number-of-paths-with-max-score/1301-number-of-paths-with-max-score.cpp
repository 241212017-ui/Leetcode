class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int x[3] = {1, 0, 1};
        int y[3] = {0, 1, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X')
                    continue;

                if (i == n - 1 && j == n - 1)
                    continue;

                int best = -1;
                int cnt = 0;

                for (int k = 0; k < 3; k++) {

                    int ni = i + x[k];
                    int nj = j + y[k];

                    if (ni >= n || nj >= n)
                        continue;

                    if (score[ni][nj] == -1)
                        continue;

                    if (score[ni][nj] > best) {
                        best = score[ni][nj];
                        cnt = ways[ni][nj];
                    }
                    else if (score[ni][nj] == best) {
                        cnt = (cnt + ways[ni][nj]) % mod;
                    }
                }

                if (best == -1)
                    continue;

                int val = 0;

                if (board[i][j] != 'E')
                    val = board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt;
            }
        }

        if (ways[0][0] == 0)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};