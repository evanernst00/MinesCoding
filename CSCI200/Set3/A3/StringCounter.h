#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H

#include <string>
#include <vector>

class StringCounter
{
private:
    std::vector<std::string> allWords;
    std::vector<unsigned int> letterCounts;
    unsigned int totalLetterCount;
public:
    StringCounter();
    void readAllWords( std::istream&, std::string );
    void printLetterCounts( std::ostream& );
    void printLetterStats( std::ostream& );
    std::vector<std::string> getAllWords();
};

#endif // STRINGCOUNTER_H