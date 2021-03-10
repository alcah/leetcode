// 208-trie.cpp
// 2021-03-06

#include <bits/stdc++.h>
using namespace std;

// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		isWord = false;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* t = this;

		for (int i = 0; i < (int)word.size(); i++) {
			if (!(t->children[word[i] - 'a'])) {
				t->children[word[i] - 'a'] = new Trie();
			}
			t = t->children[word[i] - 'a'];
		}
		t->isWord = true;
		return;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* t = this;

		for (int i = 0; i < (int)word.size(); i++) {
			if (!(t->children[word[i] - 'a'])) {
				return false;
			}
			t = t->children[word[i] - 'a'];
		}
		return t->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* t = this;

		for (int i = 0; i < (int)prefix.size(); i++) {
			if (!(t->children[prefix[i] - 'a'])) {
				return false;
			}
			t = t->children[prefix[i] - 'a'];
		}
		return true;
	}
	Trie *children[26];
	bool isWord;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
