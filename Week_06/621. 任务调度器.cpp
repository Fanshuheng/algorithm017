class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int length = tasks.size();
        vector<int> vec(26);
        for (auto& c : tasks) ++vec[c - 'A'];
        sort(vec.begin(), vec.end(), std::greater<int>());
        int cnt = 1;
        while (cnt < vec.size() && vec[cnt] == vec[0]) cnt++;
        return max(length, (n + 1) * (vec[0] - 1) + cnt); 
    }
};
