class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>nums;
        int sum=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="C")
            {
                if(!nums.empty())
                {
                    
                    nums.pop();
                }

            }
            else if (operations[i]=="D")
            {
                if(!nums.empty()){
                int num=nums.top()*2;
                nums.push(num);
                }

            }
            else if(operations[i]=="+")
            {
                int num1=nums.top();
                nums.pop();
                int num2=nums.top();
                nums.pop();
                int sum=num1+num2;
                 nums.push(num2);
                nums.push(num1);
                nums.push(sum);

            }
            else{
                int num=stoi(operations[i]);
                nums.push(num);
                
            }

        }
        while(!nums.empty())
        {
            sum+=nums.top();
            nums.pop();
        }
        return sum;
    }
};
