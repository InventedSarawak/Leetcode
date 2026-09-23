class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack<int> temps;
        vector<int> days(len);

        for (int i = 0; i < len; i++) {
            int temp = temperatures[i];
            while (!temps.empty() && temperatures[temps.top()] < temp) {
                int idx = temps.top();
                days[idx] = i - idx;
                temps.pop();
            }
            temps.push(i);
        }

        while (!temps.empty()) {
            int idx = temps.top();
            days[idx] = 0;
            temps.pop();
        } 

        return days;
    }
};