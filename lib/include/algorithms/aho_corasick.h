#ifndef SUBSTRING_LIB_AHO_CORASICK_H
#define SUBSTRING_LIB_AHO_CORASICK_H

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

class AhoCorasick {
   public:
    explicit AhoCorasick(const std::string &text);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &pattern) const;

   private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        TrieNode* failureLink = nullptr;
        std::vector<std::size_t> output;
    };

    void buildTrie(const std::string &pattern);
    void buildFailureLinks();

    TrieNode* root;
    std::string text;
};

#endif  // SUBSTRING_LIB_AHO_CORASICK_H
