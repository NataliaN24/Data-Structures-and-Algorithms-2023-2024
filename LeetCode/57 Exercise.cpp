class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        vector<int>steps(n,0);
        stack<int>st;
        int maxStep=0;

        for(int i=0;i<n;i++)
        {
            int current=0;
            while(!st.empty() &&nums[st.top()]<=nums[i])
            {
                current=max(current,steps[st.top()]);
                st.pop();
            }
            if(!st.empty()){
                steps[i]=current+1;
            }
            st.push(i);
            maxStep=max(maxStep,steps[i]);
            
        }
        return maxStep;
    }
};
