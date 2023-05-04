#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_VARIANTS = 15;

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool isLastNode(const TrieNode* root);
void recProposition(const TrieNode* root, string currentPrefix, string* result, int& result_length);
int getProposition(TrieNode* root, const string& query, string* result);
void fillTrie(TrieNode*);