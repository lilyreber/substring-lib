#include "aho_corasick.h"

AhoCorasick::AhoCorasick(const std::string &text) : text(text) {
    root = new TrieNode();
}

void AhoCorasick::buildTrie(const std::string &pattern) {
    TrieNode* node = root;
    for (std::size_t i = 0; i < pattern.size(); ++i) {
        char c = pattern[i];
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->output.push_back(pattern.size());  // Сохраняем длину паттерна
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
            child->output.insert(child->output.end(), child->failureLink->output.begin(), child->failureLink->output.end());
            q.push(child);
        }
    }
}

std::vector<std::size_t> AhoCorasick::search(const std::string &pattern) const {
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
        for (std::size_t len : node->output) {
            result.push_back(i - len + 1); // Добавляем индекс начала совпадения
        }
    }
    return result;
}
