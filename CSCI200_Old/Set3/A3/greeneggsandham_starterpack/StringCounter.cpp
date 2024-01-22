#include "StringCounter.h"
#include <sstream>
#include <algorithm>

StringCounter::StringCounter()
{
    totalLetterCount = 0;
}

void StringCounter::readAllWords(std::istream& input, std::string delimiter) {
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string word;
        while (std::getline(iss, word, delimiter[0])) {
            allWords.push_back(word);

            // Count the letters in the word and update letterCounts and totalLetterCount
            unsigned int count = 0;
            for (char letter : word) {
                if (std::isalpha(letter)) {
                    count++;
                    totalLetterCount++;
                }
            }
            letterCounts.push_back(count);
        }
    }
}

void StringCounter::printLetterCounts(std::ostream& output) {
    for (unsigned int count : letterCounts) {
        output << count << " ";
    }
    output << std::endl;
}

void StringCounter::printLetterStats(std::ostream& output) {
    output << "Total letter count: " << totalLetterCount << std::endl;
}

std::vector<std::string> StringCounter::getAllWords() {
    return allWords;
}
