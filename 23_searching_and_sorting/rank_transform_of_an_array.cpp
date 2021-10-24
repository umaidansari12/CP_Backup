class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        int rank = 1;
        for (auto i : m) {
            m[i.first] = rank;
            rank++;
        }
        vector<int> res;
        for (auto i : arr) {
            res.push_back(m[i]);
        }
        return res;
    }
};