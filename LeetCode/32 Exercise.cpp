class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        priority_queue<int>pq(score.begin(),score.end());
        unordered_map<int,string>rankMap;
        int rank=1;

        while(!pq.empty()){
            int current=pq.top();
            pq.pop();
            if(rank==1){
                rankMap[current]="Gold Medal";
            }
           else if(rank==2){
            rankMap[current]="Silver Medal";

            }
            else if(rank==3){
                rankMap[current]="Bronze Medal";

            }
            else{
                rankMap[current]=to_string(rank);
            }
            rank++;
            
        }
       vector<string>res;
       for(int s:score){
        res.push_back(rankMap[s]);
       }
       return res;

        }
    
};
