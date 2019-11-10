class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        set<char> taskSet(tasks.begin(),tasks.end());
        int * map = (int *)calloc(taskSet.size(), sizeof(int));
        for(int i=0; i<tasks.size(); i++)
        {
            map[tasks[i]-'A']++;
        }
        sort(map,map+taskSet.size());
        int time = 0;
        while(map[taskSet.size()-1] > 0)
        {
            int i=0;
            while(i <= n)
            {
                if(map[taskSet.size()-1] == 0) break;
                if(i<taskSet.size() && map[taskSet.size()-1- i] > 0) map[taskSet.size()-1-i]--;
                time++;
                i++;
            }
            sort(map,map+taskSet.size());
        }
        return time;
    }
};
