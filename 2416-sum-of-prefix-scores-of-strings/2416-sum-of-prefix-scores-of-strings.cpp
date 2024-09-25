class Node {
    public:
    Node* links[26];
    bool flag;
    int cnt = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
        links[ch - 'a'] -> cnt += 1;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    void setFreq(char ch) {
        links[ch - 'a'] -> cnt += 1;
    }

    int getFreq(char ch) {
        return links[ch - 'a'] -> cnt;
    }
};

class Trie {
    private:
    Node* root;

    public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        int n = word.length();
        for(int i = 0; i < n; i++) {
            if(!node -> containsKey(word[i])) {
                node -> put(word[i], new Node());
            }
            else node -> setFreq(word[i]);
            node = node -> get(word[i]);
        }
        cout << endl;
        node -> setEnd();
    }

    int countFreq(string word) {
        Node* node = root;
        int cnt = 0, n = word.length();
        for(int i = 0; i < n; i++) {
            if(node -> containsKey(word[i])) {
                cnt += node -> getFreq(word[i]);
            }
            else{
                return cnt;
            }
            node = node -> get(word[i]);
        }
        return cnt;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie trie;
        for(int i = 0; i < n; i++) {
            trie.insert(words[i]);
        }
        vector<int> ans;
        for(auto it : words) {
            ans.push_back(trie.countFreq(it));
        }
        return ans;
    }
};