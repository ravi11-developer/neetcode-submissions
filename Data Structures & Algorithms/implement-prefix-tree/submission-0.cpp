class PrefixTree {
    struct TrieNode {
        bool isend;
        TrieNode* children[26];
    };
    TrieNode* getNode() {
        TrieNode* newnode = new TrieNode();
        newnode->isend = false;
        for (int i = 0; i < 26; i++) {
            newnode->children[i] = nullptr;
        }
        return newnode;
    };
    TrieNode* root;

   public:
    PrefixTree() { root = getNode(); }

    void insert(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (temp->children[c - 'a'] == nullptr) temp->children[c - 'a'] = getNode();
            temp = temp->children[c - 'a'];
        }
        temp->isend = true;
        return;
    }

    bool search(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (temp->children[c - 'a'] == nullptr) return false;
            temp = temp->children[c - 'a'];
        }
        return temp->isend == true;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            if (temp->children[c - 'a'] == nullptr) return false;
            temp = temp->children[c - 'a'];
        }
        return true;
    }
};
