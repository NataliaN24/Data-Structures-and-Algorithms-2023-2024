class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>res;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(!pq.empty()){
            int num1=pq.top();
             pq.pop();
             int num2=pq.top();
             pq.pop();
            res.push_back(num2);
            res.push_back(num1);
           
        }
        return res;
    }
};
