class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        vector<pair<int, double>> position_time_pair(len);
        for (int i = 0; i < len; i++) {
            position_time_pair[i] = {position[i], (double) (target - position[i]) / speed[i]};
        }

        sort(position_time_pair.begin(), position_time_pair.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        });

        stack<double> time;
        for (const pair pos_time: position_time_pair) {
            if (time.empty() || time.top() < pos_time.second) {
                time.push(pos_time.second);
            }
        }

        return time.size();
    }
};