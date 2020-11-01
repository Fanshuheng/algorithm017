class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail, *p_head, *p_tail;
        if (dict.find(endWord) == dict.end()) return 0;
        head.insert(beginWord);
        tail.insert(endWord);

        int count = 2;
        while (!head.empty() && !tail.empty()) {
            p_head = head.size() > tail.size() ? &tail : &head;
            p_tail = head.size() > tail.size() ? &head : &tail;

            unordered_set<string> tmp;//不能直接在p_head里面添加或删除，因为会导致iter失效，整个for都废了
            for (auto it = p_head->begin(); it != p_head->end(); it++) {
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char c = word[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        word[i] = j;
                        if (p_tail->find(word) != p_tail->end()) return count;
                        if (dict.find(word) != dict.end()) {
                            tmp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            p_head->swap(tmp);
            count++;
        }
        return 0;
    }
};
