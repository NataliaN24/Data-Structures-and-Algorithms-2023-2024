class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
      unordered_map<int, int> count;
        for (int barcode : barcodes) {
            count[barcode]++;
        }
           priority_queue<pair<int, int>> maxHeap;
        for (auto& entry : count) {
            maxHeap.push({entry.second, entry.first});
        }
        vector<int> result;
        pair<int, int> prev = {0, 0}; 
                while (!maxHeap.empty()) {
            auto [freq, barcode] = maxHeap.top();
            maxHeap.pop();
             result.push_back(barcode);
             if (prev.first > 0) {
                maxHeap.push(prev);
            }
            freq--;
            prev={freq,barcode};
                }
                return result;
    }
};
