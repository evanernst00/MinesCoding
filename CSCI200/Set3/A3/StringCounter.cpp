#include "StringCounter.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
private:
    std::vector<std::string> allWords;
    std::vector<unsigned int> letterCounts;
    unsigned int totalLetterCount;
*/

StringCounter::StringCounter()
{
    std::vector<std::string> _allWords;
    std::vector<unsigned int> _letterCounts;
    unsigned int _totalLetterCount = 0;
}

void StringCounter::readAllWords(std::istream& input, std::string removedChars)
{

    std::string word;
    input >> word;

    while(input >> word)
    {
        for(size_t letter = 0; letter < word.length(); letter++)
        {
            for(size_t specChar = 0; specChar < removedChars.length(); specChar++)
            {
                if(removedChars.at(specChar) == word.at(letter))
                {
                    word.erase(letter, 1);
                    letter--;
                }
                else
                {
                    word[letter] = toupper(word.at(letter));
                }
            }
        }

        _allWords.push_back(word);
    }
}

void StringCounter::printLetterCounts( std::ostream& out )
{

    vector<char> capitalLetters;

    for(size_t i = (int)'A'; i <= (int)'Z'; i++)
    {
        capitalLetters.push_back(i);
        _letterCounts.push_back(0);
    }

    for(size_t w = 0; w < _allWords.size(); w++)
    {
        string currentWord = _allWords.at(w);

        for(size_t indexChar = 0; indexChar < currentWord.length(); indexChar++)
        {
            _letterCounts.at(currentWord.at(indexChar)-(int)'A')++;
        }
    }

    for(int n = 0; n <= 25; n++)
    {
        out << capitalLetters.at(n) << ": " << _letterCounts.at(n) << endl;
    }

}

void StringCounter::printLetterStats( std::ostream& out )
{
    // Letter counts
    unsigned int topLetterCount = _letterCounts.at(0);
    unsigned int topLetterCount2 = _letterCounts.at(0);
    unsigned int bottomLetterCount = _letterCounts.at(0);
    unsigned int bottomLetterCount2 = _letterCounts.at(0);

    // Which letter?
    char topLetter;
    char topLetter2;
    char bottomLetter;
    char bottomLetter2;

    // top letters
    int finalIndexTL;
    int finalIndexBL;
    for(int i = 0; i < _letterCounts.size(); i++)
    {
        if(topLetterCount < _letterCounts.at(i))
        {
            topLetterCount = _letterCounts.at(i);
            finalIndexTL = i;
        }

        if(bottomLetterCount > _letterCounts.at(i))
        {
            bottomLetterCount = _letterCounts.at(i);
            finalIndexBL = i;
        }
    }

    topLetter = (char)(finalIndexTL + (int)'A');
    bottomLetter = (char)(finalIndexBL + (int)'A');

    // second to top letters
    int finalIndexTL2;
    int finalIndexBL2;
    for(int i = 0; i < _letterCounts.size(); i++)
    {
        if(topLetterCount2 < _letterCounts.at(i) && (topLetterCount != _letterCounts.at(i)))
        {
            topLetterCount2 = _letterCounts.at(i);
            finalIndexTL2 = i;
        }

        if((bottomLetterCount2 > _letterCounts.at(i)) && (bottomLetterCount != _letterCounts.at(i)))
        {
            bottomLetterCount2 = _letterCounts.at(i);
            finalIndexBL2 = i;
        }
    }

    topLetter2 = (char)(finalIndexTL2 + (int)'A');
    bottomLetter2 = (char)(finalIndexBL2 + (int)'A');

    out << "Most frequent letter: "         << topLetter        << topLetterCount       << (double)topLetterCount / _totalLetterCount     << endl;
    out << "Least frequent letter: "        << bottomLetter     << bottomLetterCount    << (double)bottomLetterCount / _totalLetterCount  << endl;
    out << "Second most frequent letter: "  << topLetter2       << topLetterCount2      << (double)topLetterCount2 / _totalLetterCount    << endl;
    out << "Second least frequent letter: " << bottomLetter2    << bottomLetterCount2   << (double)bottomLetterCount2 / _totalLetterCount << endl;
}

std::vector<std::string> StringCounter::getAllWords()
{
    return _allWords;
}
