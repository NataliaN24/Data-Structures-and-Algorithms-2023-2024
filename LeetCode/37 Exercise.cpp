class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0){
            pq.push({a,'a'});
        }
         if(b>0){
            pq.push({b,'b'});
        }
         if(c>0){
            pq.push({c,'c'});
        }
        string res ="";
        while(!pq.empty()){
            auto[c1,ch1]=pq.top();
            pq.pop();
            if(res.size()>=2 && res.back()==ch1 &&res[res.size()-2]==ch1)
            {
                if(pq.empty()){
                    break;
                }
                auto[c2,ch2]=pq.top();
                pq.pop();
                res+=ch2;
                c2--;
                if(c2>0){
                    pq.push({c2,ch2});
                }
                pq.push({c1,ch1});
            }
            else{
                res+= ch1;
                c1--;
                if(c1>0){
                    pq.push({c1,ch1});
                }
            }
        }
         return res;
        }
};
