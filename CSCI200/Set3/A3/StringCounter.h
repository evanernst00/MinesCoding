#ifndef STRINGCOUNTER_H
#define STRINGCOUNTER_H

#include <string>
#include <vector>

class StringCounter
{
private:
    std::vector<std::string> _allWords;
    std::vector<unsigned int> _letterCounts;
    unsigned int _totalLetterCount;
public:
    StringCounter();
    void readAllWords( std::istream&, std::string );
    void printLetterCounts( std::ostream& );
    void printLetterStats( std::ostream& );
    std::vector<std::string> getAllWords();
};

#endif // STRINGCOUNTER_H