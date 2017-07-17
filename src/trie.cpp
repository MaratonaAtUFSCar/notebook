#define ALFABET -1

struct TrieNode {
    int adj[ALFABET];
    bool word = false;
    
	TrieNode() {
    	memset(adj, -1, sizeof adj);
    }
};


struct Trie {
    vector<TrieNode> trie;
    
    Trie() {
        trie.emplace_back(); 
    }

    void insert(string str) {
        int curr = 0;

        for (char c : str) {
            int i = c - 'a';
            if (trie[curr].adj[i] == -1) trie[curr].adj[i] = trie.size(), trie.emplace_back();
            
            curr = trie[curr].adj[i];
        }
        trie[curr].word = true;
    }

    bool contains(string str) {
        int curr = 0;

        for (char c : str) {
            int i = c - 'a';
            if (trie[curr].adj[i] == -1) return false;
            
            curr = trie[curr].adj[i];
        }

        return trie[curr].word;
    }

};

Trie trie;

