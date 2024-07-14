#include <random>

#include "mystring.h"

MyString::MyString() {
    strtext = std::string();
    strsize = strtext.size();
    strcapacity = initialBufferSize_ + strtext.capacity();
    strtext.reserve(initialBufferSize_);
}

MyString::MyString(const char *text) {
    strtext = text;
    strsize = strtext.size();
    strcapacity = initialBufferSize_ + strtext.capacity();
    strtext.reserve(initialBufferSize_);
}

MyString::MyString(const std::string &text) {
    strtext = text;
    strsize = text.length();
    strcapacity = strtext.capacity();
}


size_t MyString::capacity() const {
    return strcapacity;
}

bool MyString::empty() const {
    return strsize == 0;
}

size_t MyString::size() const {
    return strsize;
}

std::string::const_iterator MyString::end() const {
    return strtext.end();
}

bool MyString::operator<(const MyString &string) const {
    return strtext.compare(string.strtext) < 0;
}

bool MyString::operator==(const MyString &string) const {
    return strtext == string.strtext;
}

std::string::const_iterator MyString::begin() const {
    return strtext.begin();
}



void MyString::clear() {
    strtext.clear();
    strsize = 0;
    strcapacity = initialBufferSize_ + strtext.capacity();
}

bool MyString::operator!=(const MyString &string) const {
    auto result = std::mismatch(strtext.begin(), strtext.end(), string.strtext.begin(), string.strtext.end());
    return !(result.first == strtext.end() && result.second == string.strtext.end());
}



MyString &MyString::operator+=(const char character) {
    strtext += character;
    strsize = strtext.size();
    return *this;
}


char MyString::operator[](size_t idx) const {
    if (idx >= strtext.size())
        throw std::out_of_range("Index out of range");
    return strtext[idx];
}


std::ostream &operator<<(std::ostream &st, const MyString &string) {
    st << string.strtext;
    return st;
}


std::istream &operator>>(std::istream &is, MyString &string) {
    std::string buffer;
    string.strtext.clear();
    while (is >> buffer) {
        if (!string.strtext.empty()) {
            string.strtext.append(" ");
        }
        string.strtext.append(buffer);
    }
    string.strcapacity = string.strtext.capacity();
    string.strsize = string.strtext.size();
    return is;
}

bool MyString::all_of(int (*predicate)(int)) const {
    return std::all_of(strtext.begin(), strtext.end(), predicate);
}
bool MyString::startsWith(std::string string) const {
    if (strtext.size() < string.size()) {
        return false;
    }
    return strtext.compare(0, string.size(), string) == 0;
}
bool MyString::endsWith(std::string string) const {
    size_t n = strtext.size();
    size_t s = string.size();
    if (n < s) {
        return false;
    }
    return strtext.compare(n - s, s, string) == 0;
}

size_t MyString::getPosition() const {
    return strtext.size();
}

char MyString::operator*() const {
    if (strtext.empty()) {
        throw std::out_of_range("Dereferencing an empty MyString");
    }
    return strtext[0];
}

void MyString::push_back(char c) {
    strtext.push_back(c);
}

MyString MyString::join(const std::vector<MyString> &string) const {
    if (string.empty()) {
        return MyString();
    }

    std::string result;
    size_t totalLength = 0;
    size_t numSeparators = string.size() - 1;


    for (const auto &s : string) {
        totalLength += s.strtext.length();
    }
    totalLength += numSeparators * strtext.length();

    result.reserve(totalLength);

    for (size_t i = 0; i < string.size(); ++i) {
        result += string[i].strtext;
        if (i < numSeparators) {
            result += strtext;
        }
    }

    return MyString(result.c_str());

}

MyString MyString::generateRandomWord(size_t length) {
    static std::mt19937 generator(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<int> distribution('a', 'z');

    std::string result;
    result.reserve(length);

    for (size_t i = 0; i < length; ++i) {
        char random_char = distribution(generator);
        result.push_back(random_char);
    }

    return MyString(result.c_str());
}
void MyString::trim() {
    auto start = std::find_if_not(strtext.begin(), strtext.end(),
                                  [](unsigned char c) { return std::isspace(c); });
    auto end = std::find_if_not(strtext.rbegin(), strtext.rend(),
                                [](unsigned char c) { return std::isspace(c); }).base();
    strtext = std::string(start, end);
    strsize = strtext.size();
}


std::set<MyString> MyString::getUniqueWords() const {
    std::set<MyString> unique_words;
    std::string cleaned;
    cleaned.reserve(strtext.size());

    std::transform(strtext.begin(), strtext.end(), std::back_inserter(cleaned),
                   [](unsigned char c) { return std::ispunct(c) ? ' ' : std::tolower(static_cast<char>(c), std::locale()); });

    std::istringstream stream(cleaned);
    std::string word;

    while (stream >> word) {
        if (!word.empty()) {
            unique_words.insert(MyString(word));
        }
    }

    return unique_words;
}

std::map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const {
    std::map<MyString, size_t> word_count;
    std::string normalized;

    std::transform(strtext.begin(), strtext.end(), std::back_inserter(normalized),
                   [](unsigned char c) { return std::ispunct(c) ? ' ' : std::tolower(static_cast<char>(c), std::locale("")); });

    std::istringstream stream(normalized);
    std::string word;
    while (stream >> word) {
        word_count[MyString(word)]++;
    }

    return word_count;
}


void MyString::toLower() {
    std::transform(strtext.begin(), strtext.end(), strtext.begin(),
                   [](unsigned char c) { return std::tolower(c); });
}










