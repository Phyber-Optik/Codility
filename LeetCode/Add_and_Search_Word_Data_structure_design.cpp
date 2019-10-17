#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* next[26];
    bool marks_end;
    Node() {
        for(int i = 0; i < 26; i++) next[i] = nullptr;
        marks_end = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        this->root = new Node();
    }
    void insert(string word) {
        Node* cur = root;
        for(auto ch : word) {
            if(cur->next[ch - 'a'] == nullptr) cur->next[ch - 'a'] = new Node();
            cur = cur->next[ch - 'a'];
        }
        cur->marks_end = true;
    }
    bool search(int pos, string& word, Node* cur) {
        if(pos == word.size()) return cur->marks_end == true;
        bool ret = false;
        if(word[pos] == '.') {
            for(int i = 0; i < 26; i++) {
                if(cur->next[i]) ret |= search(pos + 1, word, cur->next[i]);
            }
        }
        else {
            if(cur->next[word[pos] - 'a']) ret |= search(pos + 1, word, cur->next[word[pos] - 'a']);
        }
        return ret;        
    }
};

class WordDictionary {
    Trie trie = Trie();
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return trie.search(0, word, trie.root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {
    Trie* t = new Trie();
    string s = "mad";
    t->insert(s);
    cout<<t->search(0, s, t->root);
}