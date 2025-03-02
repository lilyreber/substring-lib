#ifndef SUBSTRING_LIB_AHO_CORASICK_H
#define SUBSTRING_LIB_AHO_CORASICK_H

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AhoCorasick {
   public:
    explicit AhoCorasick(const std::string &pattern);
    [[nodiscard]] std::vector<std::size_t> search(const std::string &text) const;

   private:
    struct TrieNode {
        std::unordered_map<char, TrieNode *> children;
        TrieNode *failureLink = nullptr;
        bool isEndOfPattern = false;
    };

    void buildTrie(const std::string &pattern);
    void buildFailureLinks();

    TrieNode *root;
    std::size_t patternLength;
};

#endif  // SUBSTRING_LIB_AHO_CORASICK_H