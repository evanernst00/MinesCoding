#ifndef STRINGFILTER_H
#define STRINGFILTER_H

class StringFilter
{
private:
    std::vector<std::string> uniqueWords;
    std::vector<unsigned int> wordCounts;
    unsigned int totalWordCount;
public:
    StringFilter();
    void addWords( std::vector<std::string> );
    void printUniqueWordCounts( std::ostream& );
    void printUniqueWordStats( std::ostream& );
    std::vector<std::string> getUniqueWords();
};

#endif // STRINGFILTER_H