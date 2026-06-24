class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for(int i = 0; i < 9; i++) {
            vector<bool> seen(10, false);

            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        // Check columns
        for(int j = 0; j < 9; j++) {
            vector<bool> seen(10, false);

            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                if(seen[num]) return false;
                seen[num] = true;
            }
        }

        // Check 3x3 boxes
        for(int boxRow = 0; boxRow < 3; boxRow++) {
            for(int boxCol = 0; boxCol < 3; boxCol++) {

                vector<bool> seen(10, false);

                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {

                        int r = boxRow * 3 + i;
                        int c = boxCol * 3 + j;

                        if(board[r][c] == '.') continue;

                        int num = board[r][c] - '0';

                        if(seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }

        return true;
    }
};
