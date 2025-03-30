// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// https://leetcode.com/problems/implement-trie-ii-prefix-tree/

// Implement Trie

// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store 
// and retrieve keys in a dataset of strings. 
// There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously 
// inserted string word that has the prefix prefix, and false otherwise.

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True


#include<string>
using namespace std;

struct Node {

    // Every node of the trie consists of an array of character representing all the alphabets, 
    // and a boolean variable which is used to represent the termination of the word.
    // we are using the index to simply mark pointers
    // if at that index we do have a pointer, then that character is present.
    // this is alternate to the map approach
    Node *a[26];

    // mark terminal node
    bool is_term = false;

    // for count of words that end with
    int ends_with_count = 0;

    // for prefix count
    int prefix_count = 0;

};


class Trie {
    public:
        Node *root;

        Trie () {
            root = new Node();
        }

        // insert a word into Trie
        // this is just iterating through trie
        void insert(string word) {
            Node *node = root;
            
            for(char ch: word) {

                // if there is no character
                if(node->a[ch - 'a'] == nullptr) {
                    node->a[ch - 'a'] = new Node();
                }
                
                // move the pointer
                node = node->a[ch - 'a'];

                node->prefix_count += 1;

            }

            node->ends_with_count += 1;
            node->is_term = true;
        }

        // search in Trie
        bool search(string word) {
            Node *node = root;

            for(char ch: word) {

                // we have a null pointer. That character is absent
                if(node->a[ch - 'a'] == nullptr) {
                    return false;
                }

                // move the pointer
                node = node->a[ch - 'a'];
            }
            
            // if the whole word is there, we should check if it is marked as terminal
            // cases would be, we have substring, but not the whole word
            return node->is_term;
        }

        // check if string starts with given prefix
        bool startsWith(string prefix) {
            Node *node = root;
            for(char ch: prefix) {
                
                if(node->a[ch - 'a'] == nullptr) {
                    return false;
                }

                node = node->a[ch - 'a'];
            }

            return true;
        }

        // part of follow up asks 3 more methods to do
        int countWordsEqualTo(string &word){
            
            Node *node = root;

            // move the node 
            for(char ch: word) {
                if(node->a[ch - 'a'] != nullptr) {
                    node = node->a[ch - 'a'];
                }
                else {
                    return 0;
                }
            }

            // If we do have node, then it's ends with count will help
            return node->ends_with_count;
        }
        
        // same idea
        int countWordsStartingWith(string &word){
            
            Node *node = root;

            // move the node
            for(char ch: word) {
                if(node->a[ch - 'a'] != nullptr) {
                    node = node->a[ch - 'a'];
                }

                else {
                    return 0;
                }
            }

            return node->prefix_count;
        }
        
        // this is tricky
        // we need to also decrement the counts
        void erase(string &word){

            Node *node = root;

            for(char ch: word) {

                // if we do find the character
                if(node->a[ch - 'a'] != nullptr) {

                    // move the node?
                    node = node->a[ch - 'a'];
                    node->prefix_count -= 1;
                }
                else {
                    return;
                }
            }
            
            // just once we need to reduce this count
            // on the last node
            node->ends_with_count -= 1;
            return;
        }

};


