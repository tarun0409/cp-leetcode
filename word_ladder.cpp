class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endWordFound = false;
        unordered_map<string,bool> wordVisited;
        unordered_map<string, vector<string>> oneDistStrings;
        vector<string> temp;
        for(int i=0; i<wordList.size(); i++)
        {
            if(!wordList[i].compare(endWord))
            {
                endWordFound = true;
            }
            int dist = 0;
            for(int k = 0; k<wordList[i].length(); k++)
            {
                if(beginWord[k] != wordList[i][k]) dist++;
            }
            if(dist == 1)
            {
                temp.push_back(wordList[i]);
            }
            wordVisited[wordList[i]] = false;
        }
        if(!endWordFound)
        {
            return 0;
        }
        oneDistStrings[beginWord] = temp;
        for(int i=0; i<wordList.size(); i++)
        {
            vector<string> ods;
            for(int j=0; j<wordList.size(); j++)
            {
                if(i==j) continue;
                int dist = 0;
                for(int k = 0; k<wordList[i].length(); k++)
                {
                    if(wordList[i][k] != wordList[j][k]) dist++;
                }
                if(dist == 1)
                {
                    ods.push_back(wordList[j]);
                }
            }
            oneDistStrings[wordList[i]] = ods;
        }
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        wordVisited[beginWord] = true;
        while(!q.empty())
        {
            pair<string,int> frontEntry = q.front();
            q.pop();
            string currWord = frontEntry.first;
            int level = frontEntry.second;
            if(!endWord.compare(currWord))
            {
                return level;
            }
            vector<string> ods = oneDistStrings[currWord];
            for(int i=0; i<ods.size(); i++)
            {
                if(!ods[i].compare(endWord))
                {
                    return (level+1);
                }
                if(wordVisited[ods[i]]) continue;
                wordVisited[ods[i]] = true;
                q.push({ods[i], (level+1)});
            }
        }
        return 0;
    }
};
