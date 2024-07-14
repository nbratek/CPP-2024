
#ifndef ZAD6MYSTRING_MYSTRING_H
#define ZAD6MYSTRING_MYSTRING_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <locale>
#include <sstream>

class MyString {
    std::string strtext;
    size_t strsize;
    size_t strcapacity;
public:

    static const size_t initialBufferSize_ = 20;
    MyString();
    MyString(const char text[]);
    explicit MyString(const std::string &text);
    [[nodiscard]] std::string::const_iterator begin() const;

    [[nodiscard]] size_t capacity() const;

    size_t getPosition() const;

    [[nodiscard]] bool empty() const;

    [[nodiscard]] size_t size() const;

    [[nodiscard]] std::string::const_iterator end() const;

    bool operator!=(const MyString &m) const;

    bool operator<(const MyString &string) const;

    MyString &operator+=(char);

    char operator*() const;

    bool operator==(const MyString &string) const;

    char operator[](size_t) const;

    friend std::ostream &operator<<(std::ostream &, const MyString &);

    friend std::istream &operator>>(std::istream &, MyString &m);

    bool all_of(int predicate(int)) const;

    void push_back(char c);

    [[nodiscard]] MyString join(const std::vector<MyString> &m) const;

    static char generateRandomChar() { return rand() % 26 + 65 + rand() % 2 * 32; }

    static MyString generateRandomWord(size_t len);

    [[nodiscard]] std::set<MyString> getUniqueWords() const;

    [[nodiscard]] std::map<MyString, size_t> countWordsUsageIgnoringCases() const;

    [[nodiscard]] bool startsWith(std::string) const;

    [[nodiscard]] bool endsWith(std::string) const;

    void toLower();
    void trim();
    void clear();

};

#endif //ZAD6MYSTRING_MYSTRING_H
