/*

Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

*/

//Code:

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        // insert reversed word into trie and keep track of the length of longest word
        for (auto& word: words) 
        {
            trie.insert_reversed(word);
            if (word.length() > longest_word)
                longest_word = word.length();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (queries.size() > longest_word)
            queries.pop_back();
        Trie* cur = &trie;
        for (auto it = queries.begin(); it!=queries.end();++it)
        {
            if (cur->is_leaf) return true;
            if (cur->children[*it -'a'] == NULL) return false;
            cur = cur->children[*it-'a'];
        }
        return cur->is_leaf;
    }
private:
    
    class Trie {
    public:
        Trie() {
            this->is_leaf = false;
            for(int i=0;i<26;i++)
                this->children[i] = NULL;
        }
        
        void insert_reversed(string word) {
            reverse(word.begin(), word.end());
            Trie* root = this;
            for(int i=0;i<word.length();i++)
            {
                int index = word[i] - 'a';
                if (root->children[index] == NULL)
                    root->children[index] = new Trie();
                root = root->children[index];
            }
            root->is_leaf = true;
        }
        
    bool is_leaf;
    Trie* children[26];
    };
    
    Trie trie;
    vector<char> queries;
    int longest_word=0;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
 
 //Reference from leetcode disccusions
 
