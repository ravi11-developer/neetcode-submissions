class WordDictionary {
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
    WordDictionary() { root = getNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (temp->children[c - 'a'] == nullptr) temp->children[c - 'a'] = getNode();
            temp = temp->children[c - 'a'];
        }
        temp->isend = true;
        return;
    }
    bool solve(TrieNode* root, string word, int idx) {
        if (idx == word.length() - 1) {
            if (word[idx] == '.') {
                for (int i = 0; i < 26; i++) {
                    // cout<<" loop point\n";
                    if (root->children[i] != nullptr && root->children[i]->isend == true)
                        return true;
                }
            } else {
                if (root->children[word[idx] - 'a'] == nullptr) return false;
            return root->children[word[idx] - 'a']->isend == true;
            }
            return false;
        }
        bool flag = false;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != nullptr)
                    flag = flag | solve(root->children[i], word, idx + 1);
            }
        }else{
            if(root->children[word[idx]-'a']!= nullptr){
                flag= solve(root->children[word[idx]-'a'], word, idx + 1);
            }
        }
        return flag;
    }

    bool search(string word) {
        TrieNode* temp=root;
        return solve(temp,word,0);
    }
};
