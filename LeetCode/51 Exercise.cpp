class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        for(const auto &i:intervals){
            if(result.empty() || result.back()[1]<i[0])
            {
                result.push_back(i);
            }
            else{
                result.back()[1]=max(result.back()[1],i[1]);

            }
        }
        return result;
    }
};
