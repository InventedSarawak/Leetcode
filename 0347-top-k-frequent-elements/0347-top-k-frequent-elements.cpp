class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto &pair: freq) {
            heap.push({pair.second, pair.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> out;
        while (heap.size() > 0) {
            out.push_back(heap.top().second);
            heap.pop();
        }

        return out;
    }
};