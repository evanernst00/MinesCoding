#ifndef STRINGFILTER_H
#define STRINGFILTER_H

#include <vector>
#include <string>
#include <fstream>

class StringFilter
{
private:
    std::vector<std::string> _uniqueWords;
    std::vector<unsigned int> _wordCounts;
    unsigned int _totalWordCount;
public:
    StringFilter();
    void addWords( std::vector<std::string> );
    void printUniqueWordCounts( std::ostream& );
    void printUniqueWordStats( std::ostream& );
    std::vector<std::string> getUniqueWords();
};

#endif // STRINGFILTER_H