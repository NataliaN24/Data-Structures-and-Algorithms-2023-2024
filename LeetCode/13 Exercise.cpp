#include <vector>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int size=candyType.size();
        int maxCandies=size/2;
        unordered_set<int>uniqueCandy(candyType.begin(),candyType.end());
        int count=static_cast<int>(uniqueCandy.size());
        return std::min(count,maxCandies);
        
    }
};
