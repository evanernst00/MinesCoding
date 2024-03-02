#include "string_functions.h"

#include <iostream>
#include <vector>
#include <sstream>

unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = STR.at(IDX);
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR.substr(0, IDX) + TO_INSERT + STR.substr(IDX, STR.length());
    return result;
}

size_t string_find(const string STR, const char C)  {
    size_t result = STR.find(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    size_t pos;
    // replace all instances of TEXT_TO_REPLACE with REPLACE_WITH
    while ((pos = result.find(TEXT_TO_REPLACE)) != string::npos) {
        result.replace(pos, TEXT_TO_REPLACE.length(), REPLACE_WITH);
    }

    return result;
}

string string_first_word(const string STR)  {
    string result = STR.substr(0, STR.find(' '));
    return result;
}

string string_remove_first_word(const string STR)  {
    size_t spaceIndex = STR.find(' ');
    
    if (spaceIndex == std::string::npos /*no spaces in string*/ || STR.empty()) {
        return "";
    }
    
    // If the space is the last character, also return an empty string
    if (spaceIndex == STR.length() - 1) {
        return "";
    }
    
    // Return the substring starting from the character after the first space
    return STR.substr(spaceIndex + 1);
}

string string_second_word(const string STR)  {
    // string result = STR;
    // result = result.substr(result.find(' ') + 1); // remove first word
    // result = result.substr(0, result.find(' '));
    // return result;

    std::istringstream stream(STR);
    std::string word;

    stream >> word; // first word

    if (stream >> word) { // second word
        return word;
    }

    // If there's no second word, return an empty string
    return "";
}

string string_third_word(const string STR)  {
    // string result = STR;
    // result = result.substr(result.find(' ') + 1); // remove first word first time
    // result = result.substr(result.find(' ') + 1); // remove first word second time
    // result = result.substr(0, result.find(' '));
    // return result;

    vector<std::string> words;
    istringstream stream(STR);
    string word;

    while(stream >> word) {
        words.push_back(word);
    }

    if(words.size() < 3) return "";
    
    return words.at(2);
}

string string_nth_word(const string STR, const int N) {
    
    vector<std::string> words;
    istringstream stream(STR);
    string word;

    size_t n = static_cast<size_t>(N);

    while(stream >> word) {
        words.push_back(word);
    }
    
    if (n > 0 && n <= words.size()) return words[N-1];
    return "";
}

vector<string> string_tokenize(const string STR, const char DELIMITER) {
    vector<string> result;
    istringstream stream(STR);
    string token;

    if(STR.empty()) return {""};

    while(getline(stream, token, DELIMITER)) {
        if(!token.empty()) {
            result.push_back(token);
        }
    }

    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    // Iterate over each character and replace if it matches TARGET
    for (char& ch : result) {
        if (ch == TARGET) {
            ch = REPLACEMENT;
        }
    }
    return result;
}

string string_to_lower(const string STR) {

    string result = STR;

    for(size_t i = 0; i < result.length(); i++) {
        result.at(i) = tolower(result[i]);
    }

    return result;
}

string string_to_upper(const string STR) {
    string result = STR;

    for(size_t i = 0; i < result.length(); i++) {
        result.at(i) = toupper(result[i]);
    }

    return result;
}

int string_compare(const string LHS, const string RHS) {
    if(LHS.compare(RHS) == 0) return 0;
    else if(LHS.compare(RHS) < 0) return -1;
    else return 1;
}