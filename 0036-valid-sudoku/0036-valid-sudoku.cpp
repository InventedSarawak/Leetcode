    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
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


            for (int y = 0; y < 9; y++) {
                for (int x = 0; x < 9; x++) {
                    // check in same row
                    for (int i = 0; i < 9; i++) {
                        if (i == x) {
                            continue;
                        }

                        if (board[y][i] == '.') {
                            continue;
                        }

                        if (board[y][x] == board[y][i]) {
                            return false;
                        }
                    }

                    // check in same col
                    for (int i = 0; i < 9; i++) {
                        if (i == y) {
                            continue;
                        }

                        if (board[i][x] == '.') {
                            continue;
                        }

                        if (board[y][x] == board[i][x]) {
                            return false;
                        }
                    }
                }
            }

            return true;
        }
    };