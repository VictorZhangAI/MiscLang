class Solution {
public:

    bool backtrack(int i, int j, int k, vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        if(k == word.length())
        {
            return true;
        }
        if(i < 0 || i >= m ||
        j < 0 || j >= n ||
        board[i][j] != word[k])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '\0';

        bool c1 = backtrack(i + 1, j, k + 1, board, word);
        bool c2 = backtrack(i - 1, j, k + 1, board, word);
        bool c3 = backtrack(i, j - 1, k + 1, board, word);
        bool c4 = backtrack(i, j + 1, k + 1, board, word);

        if(c1 || c2 || c3 || c4)
        {
            return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(backtrack(i, j, 0, board, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
