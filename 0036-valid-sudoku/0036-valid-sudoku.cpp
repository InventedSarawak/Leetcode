    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {

            // check for rows and cols to be unique
            for (int i = 0; i < 9; i++) {
                vector<int> rows;
                vector<int> cols;

                for (int j = 0; j < 9; j++) {
                    char currRow = board[i][j];
                    char currCol = board[j][i];

                    if (currRow != '.') {
                        rows.push_back(currRow);
                    }

                    if (currCol != '.') {
                        cols.push_back(currCol);
                    }
                }

                if (unordered_set<int>(rows.begin(), rows.end()).size() != rows.size() ||
                    unordered_set<int>(cols.begin(), cols.end()).size() != cols.size()) {
                    return false;
                }

            }

            // check in same grid
            for (int g = 0; g < 9; g++) {
                vector<int> members;
                unordered_set<int> seen;

                for (int i = 0; i < 9; i++) {
                    char curr = board[(g / 3) * 3 + i / 3][(g % 3) * 3 + i % 3];
                    if (curr == '.') {
                        continue;
                    }
                    members.push_back(curr - '0');
                    seen.insert(curr - '0');
                }

                if (members.size() != seen.size()) {
                    return false;
                }
            }

            return true;
        }
    };