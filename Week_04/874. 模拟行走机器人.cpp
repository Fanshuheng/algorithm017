class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int current_x = 0, current_y = 0, direction_index = 0;
        int ans = 0;

        unordered_set<string> obstacles_set;
        for (auto& obs :obstacles) {
            obstacles_set.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        for (auto& c : commands) {
            if (c == -1) direction_index = (direction_index + 1) % 4;
            else if (c == -2) direction_index = (direction_index + 3) % 4;
            else {
                auto& cur_direction = direction[direction_index];
                while (c-- > 0 && obstacles_set.find(to_string(current_x + cur_direction[0]) + "," + to_string(current_y + cur_direction[1])) == obstacles_set.end()) {
                    current_x += cur_direction[0];
                    current_y += cur_direction[1];
                    ans = max(ans, current_x * current_x + current_y *current_y);
                }
            }
        }
        return ans;
    }
};
