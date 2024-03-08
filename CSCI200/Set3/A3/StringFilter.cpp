#include "StringFilter.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

StringFilter::StringFilter()
{
    std::vector<std::string> _uniqueWords;
    std::vector<unsigned int> _wordCounts;
    _totalWordCount = 0;
}

void StringFilter::addWords( std::vector<std::string> allWords)
{
    _totalWordCount = (unsigned int)allWords.size();

    for(size_t w=0; w < allWords.size(); w++)
    {
        bool isUnique = true;

        for(size_t words = 0; words < allWords.size(); words++)
        {
            if(_uniqueWords.at(words) == allWords.at(w))
            {
                isUnique = false;
                _wordCounts.at(words)++;
            }
        }

        if(isUnique == true)
        {
            _uniqueWords.push_back(allWords.at(w));
            _wordCounts.push_back(1);
        }
    }
}


void StringFilter::printUniqueWordCounts( std::ostream& )
{
    for(size_t i = 0; i < _uniqueWords.size(); i++)
    {
        cout << _uniqueWords.at(i) << " " << _wordCounts.at(i) << endl;
    }
}


void StringFilter::printUniqueWordStats( std::ostream& out )
{
    // Word counts
    unsigned int topWordCount = _wordCounts.at(0);
    unsigned int topWordCount2 = _wordCounts.at(0);
    unsigned int bottomWordCount = _wordCounts.at(0);
    unsigned int bottomWordCount2 = _wordCounts.at(0);

    // Which Word?
    string topWord;
    string topWord2;
    string bottomWord;
    string bottomWord2;

    int topWordIndex = 0;
    int bottomWordIndex = 0;
    for(int i = 0; i < _wordCounts.size(); i++)
    {
        if(topWordCount < _wordCounts.at(i))
        {
            topWordCount = _wordCounts.at(i);
            topWordIndex = i;
        }

        if(bottomWordCount > _wordCounts.at(i))
        {
            bottomWordCount = _wordCounts.at(i);
            bottomWordIndex = i;
        }
    }

    topWord = _uniqueWords.at(topWordIndex);
    bottomWord = _uniqueWords.at(bottomWordIndex);

    // second to top words
    int topWordIndex2 = 0;
    int bottomWordIndex2 = 0;
    for(int i = 0; i < _wordCounts.size(); i++)
    {
        if(topWordCount2 < _wordCounts.at(i) && (topWordCount != _wordCounts.at(i)))
        {
            topWordCount2 = _wordCounts.at(i);
            topWordIndex2 = i;
        }

        if((bottomWordCount2 > _wordCounts.at(i)) && (bottomWordCount != _wordCounts.at(i)))
        {
            bottomWordCount2 = _wordCounts.at(i);
            bottomWordIndex2 = i;
        }
    }

    topWord2 = _uniqueWords.at(topWordIndex2);
    bottomWord2 = _uniqueWords.at(bottomWordIndex2);

    out << "Most frequent Word: "         << topWord        << topWordCount       << (double)topWordCount / _totalWordCount     << endl;
    out << "Least frequent Word: "        << bottomWord     << bottomWordCount    << (double)bottomWordCount / _totalWordCount  << endl;
    out << "Second most frequent Word: "  << topWord2       << topWordCount2      << (double)topWordCount2 / _totalWordCount    << endl;
    out << "Second least frequent Word: " << bottomWord2    << bottomWordCount2   << (double)bottomWordCount2 / _totalWordCount << endl;
}


std::vector<std::string> StringFilter::getUniqueWords()
{
    return _uniqueWords;
}
