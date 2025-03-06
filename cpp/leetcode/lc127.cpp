class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        int wordLength = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while(!q.empty())
        {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++)
            {
                string word = q.front();
                q.pop();
            

                for(int j = 0; j < wordLength; j++)
                {
                    char originalChar = word[j];
                    for(char c = 'a' ; c <= 'z'; c++)
                    {
                        word[j] = c;
                        if(st.find(word) == st.end())
                            continue;
                        if(word == endWord)
                            return steps + 1;

                        q.push(word);
                        st.erase(word);
                    }
                    word[j] = originalChar;
                }
            }
            steps++;
        }
        return 0;
    }
};
