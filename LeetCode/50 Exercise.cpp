class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<int>q;
       int time=0;
       for(int i=0;i<tickets.size();i++)
       {
        q.push(i);
       }
       while(!q.empty())
       {
        int person=q.front();
        q.pop();
        
        if(tickets[person]>0)
        {
            tickets[person]--;
            time++;

            if(tickets[person]>0)
            {
                q.push(person);
            }
            if(person==k &&tickets[person]==0)
            {
                return time;
            }
        }
        
    }
    return -1;

}
};
