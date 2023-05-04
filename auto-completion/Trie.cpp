#include <stdio.h>
#include "Trie.h"

using namespace std;

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = nullptr;
    }
    return pNode;
}

bool isLastNode(const TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            return 0;
        }
    }
    return 1;
}

void insert(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
        {
            node->children[index] = getNewNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

void recProposition(const TrieNode* root, string currentPrefix, string* result, int& result_length)
{
    if (root->isEndOfWord)
    {
        result[result_length++] = currentPrefix;
    }

    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            currentPrefix.push_back(97 + i);
            recProposition(root->children[i], currentPrefix, result, result_length);
            currentPrefix.pop_back();
        }
    }
}

int getProposition(TrieNode* root, const string& query, string* result)
{
    struct TrieNode* node = root;

    size_t level;
    size_t n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);
        if (!node->children[index])
        {
            return 0;
        }
        node = node->children[index];
    }

    bool isWord = (node->isEndOfWord == true);

    bool isLast = isLastNode(node);

    if (isWord && isLast)
    {
        return 0;
    }
    int result_length = 0;
    if (!isLast)
    {
        recProposition(node, query, result, result_length);
    }
    return result_length;
}

void fillTrie(struct TrieNode* root)
{
    insert(root, "air");
    insert(root, "animal");
    insert(root, "answer");
    insert(root, "area");
    insert(root, "art");
    insert(root, "bird");
    insert(root, "body");
    insert(root, "book");
    insert(root, "boy");
    insert(root, "brother");
    insert(root, "business");
    insert(root, "car");
    insert(root, "case");
    insert(root, "change");
    insert(root, "child");
    insert(root, "children");
    insert(root, "city");
    insert(root, "color");
    insert(root, "company");
    insert(root, "day");
    insert(root, "death");
    insert(root, "dog");
    insert(root, "door");
    insert(root, "east");
    insert(root, "education");
    insert(root, "end");
    insert(root, "example");
    insert(root, "eye");
    insert(root, "face");
    insert(root, "fact");
    insert(root, "family");
    insert(root, "father");
    insert(root, "feet");
    insert(root, "fire");
    insert(root, "fish");
    insert(root, "food");
    insert(root, "force");
    insert(root, "game");
    insert(root, "girl");
    insert(root, "god");
    insert(root, "government");
    insert(root, "group");
    insert(root, "guy");
    insert(root, "hand");
    insert(root, "head");
    insert(root, "health");
    insert(root, "history");
    insert(root, "home");
    insert(root, "horse");
    insert(root, "hour");
    insert(root, "moment");
    insert(root, "money");
    insert(root, "month");
    insert(root, "morning");
    insert(root, "student");
    insert(root, "sun");
    insert(root, "table");
    insert(root, "teacher");
    insert(root, "team");
    insert(root, "thing");
    insert(root, "time");
    insert(root, "tree");
    insert(root, "war");
    insert(root, "watch");
    insert(root, "water");
    insert(root, "way");
    insert(root, "week");
    insert(root, "west");
    insert(root, "wind");
    insert(root, "woman");
    insert(root, "word");
    insert(root, "world");
    insert(root, "year");
};