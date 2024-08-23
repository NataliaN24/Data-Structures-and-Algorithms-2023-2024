class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char ,int>count;
        for(char ch:s){
            count[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto&e:count){
            pq.push({e.second,e.first});
        }
        string res;
        while(!pq.empty()){
            auto[freq,ch]=pq.top();
            pq.pop();
            res.append(freq,ch);
        }
        return res;

    }
};
