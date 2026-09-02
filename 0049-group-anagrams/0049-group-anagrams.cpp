class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> res;

        for (string str: strs) {
            string temp = str;
            sort(str.begin(), str.end());

            if (groups.find(str) == groups.end()) {
                groups[str] = {};
            }

            groups[str].push_back(temp);
        }

        for (const auto&[sortedStr, strs] : groups) {
            res.push_back(strs);
        }
        return res;
    }
};