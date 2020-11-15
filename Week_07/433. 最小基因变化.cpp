class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        //1.建立字典（可行节点集）、变化方向数组,BFS专用队列（用unorder_set代替）
        unordered_set<string> dict(bank.begin(), bank.end()), head, tail, *p_head, *p_tail;
        vector<char> gene = {'A', 'C', 'G','T'};

        //2.特判
        if (dict.find(end) == dict.end()) return -1;

        int count = 0;
        head.insert(start);
        tail.insert(end);

        //3.BFS框架
        while (!head.empty() && !tail.empty()) {
            p_head = head.size() > tail.size() ? &tail : &head;
            p_tail = head.size() > tail.size() ? &head : &tail;

            unordered_set<string> tmp;
            for (auto it = p_head->begin(); it != p_head->end(); it++) {
                string gene_sequence = *it;
                for (int i = 0; i < gene_sequence.size(); i++) {
                    char tmp_gene = gene_sequence[i];
                    for (int j = 0; j < gene.size(); j++) {
                        gene_sequence[i] = gene[j];
                        if (p_tail->find(gene_sequence) != p_tail->end()) return count + 1;
                        if (dict.find(gene_sequence) != dict.end()) {
                            dict.erase(gene_sequence);
                            tmp.insert(gene_sequence);
                        }
                    }
                    gene_sequence[i] = tmp_gene;
                }
            }
            count++;
            p_head->swap(tmp);
        }
        return -1;
    }
};
