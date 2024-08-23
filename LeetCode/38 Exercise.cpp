class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> largest;
        while (!pq.empty()) {
            largest.push_back(pq.top());
            pq.pop();
        }
        
        unordered_map<int, int> count;
        for (int num : largest) {
            count[num]++;
        }
        
        vector<int> res;
        for (int num : nums) {
            if (count[num] > 0) {
                res.push_back(num);
                count[num]--;
                if (res.size() == k) {
                    break;
                }
            }
        }
        
        return res;
    }
};
