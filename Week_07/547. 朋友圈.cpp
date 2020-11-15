class UnionFinder {
private:
    vector<int> parent;
    vector<int> rank;
    int count = 0;
public:
    UnionFinder(vector<vector<int>>& M) {
        count = M.size();
        for (int i = 0; i < count; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rootx < rooty) swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx]++;
            count--;
        }
    }
    int get_count() {return count;}
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UnionFinder union_finder(M);
        int rows = M.size(), cols = M[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) {
                    union_finder.unite(i, j);
                }
            }
        }
        return union_finder.get_count();
    }
};
