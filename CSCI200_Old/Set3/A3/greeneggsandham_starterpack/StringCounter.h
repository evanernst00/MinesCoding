#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H
#include <vector>
#include <string>
#include <istream>
#include <ostream>
using namespace std;


class StringCounter {
    public:
        StringCounter();
        void readAllWords(std::istream& input, std::string delimiter);
        void printLetterCounts(std::ostream& output);
        void printLetterStats(std::ostream& output);
        std::vector<std::string> getAllWords();

    private:
        std::vector<std::string> allWords;
        std::vector<unsigned int> letterCounts;
        unsigned int totalLetterCount;
};

#endif //STRINGCOUNTER_H