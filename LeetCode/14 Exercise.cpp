class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size=nums.size();
        vector<int>res;
        unordered_set<int>count(nums.begin(),nums.end());
        for(int i=1;i<=size;i++){
            if(count.find(i)==count.end()){
                 res.push_back(i);
            }
        }
        return res;
    }
};
