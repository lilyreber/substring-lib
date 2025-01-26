#ifndef KMP_H
#define KMP_H

#include <vector>
#include <string>

class KMP {
public:
    explicit KMP(const std::string& pattern);
    std::vector<std::size_t> search(const std::string& text) const;

private:
    void computeLPS();

    std::string pattern;
    std::vector<std::size_t> lps;
};

#endif // KMP_H
