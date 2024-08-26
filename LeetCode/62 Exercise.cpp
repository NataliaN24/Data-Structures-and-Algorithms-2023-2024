class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustCount(n+1,0);
        for(const auto&t:trust)
        {
            int a=t[0];
            int b=t[1];
            trustCount[a]--;
            trustCount[b]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(trustCount[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};
