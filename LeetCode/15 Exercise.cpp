class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizeToPeople;
        vector<vector<int>> result;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            sizeToPeople[size].push_back(i);
            
            if (sizeToPeople[size].size() == size) {
                result.push_back(sizeToPeople[size]);
                sizeToPeople[size].clear(); 
            }
        }
        
        return result;
    }
};
