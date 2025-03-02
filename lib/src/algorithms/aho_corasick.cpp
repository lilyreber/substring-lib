#include "aho_corasick.h"

AhoCorasick::AhoCorasick(const std::string &pattern) {
    root = new TrieNode();
    patternLength = pattern.size();
    buildTrie(pattern);
    buildFailureLinks();
}

void AhoCorasick::buildTrie(const std::string &pattern) {
    TrieNode* node = root;
    for (char c : pattern) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isEndOfPattern = true;
}

void AhoCorasick::buildFailureLinks() {
    std::queue<TrieNode*> q;
    for (auto &[c, node] : root->children) {
        node->failureLink = root;
        q.push(node);
    }

    while (!q.empty()) {
        TrieNode *current = q.front();
        q.pop();

        for (auto &[c, child] : current->children) {
            TrieNode *fail = current->failureLink;
            while (fail && !fail->children.count(c)) {
                fail = fail->failureLink;
            }
            child->failureLink = fail ? fail->children[c] : root;
            q.push(child);
        }
    }
}

std::vector<std::size_t> AhoCorasick::search(const std::string &text) const {
    std::vector<std::size_t> result;
    TrieNode* node = root;

    for (std::size_t i = 0; i < text.size(); ++i) {
        while (node && !node->children.count(text[i])) {
            node = node->failureLink;
        }
        if (!node) {
            node = root;
            continue;
        }
        node = node->children[text[i]];
        if (node->isEndOfPattern) {
            result.push_back(i - patternLength + 1);
        }
    }

    return result;
}