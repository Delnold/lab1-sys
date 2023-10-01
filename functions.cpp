#include "functions.h"
#include <regex>
#include <unordered_set>
#include <iostream>

std::string to_lower(const std::string& word) {
    std::string lower = word;
    for (auto& c : lower) {
        c = tolower(c);
    }
    return lower;
}

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool checkWordCondition(const std::string& word) {
    int countVowels = 0;
    int countConsonants = 0;
    for (char c : word) {
        if (isVowel(c)) {
            countVowels++;
        } else {
            countConsonants++;
        }
    }
    return (countVowels > countConsonants);
}

std::vector<std::string> getWords(const std::string& text) {
    std::vector<std::string> words;
    std::regex word_regex("\\b\\w+\\b");
    std::sregex_iterator words_begin(text.begin(), text.end(), word_regex);
    std::sregex_iterator words_end;

    while (words_begin != words_end) {
        std::smatch match = *words_begin;
        if (match.str().length() <= 30) {
            words.push_back(match.str());
        }
        ++words_begin;
    }
    return words;
}

void filterAndPrintWords(const std::vector<std::string>& words) {
    std::unordered_set<std::string> filteredWords;
    for (const std::string& word : words) {
        if (checkWordCondition(word)) {
            filteredWords.insert(to_lower(word));
        }
    }

    for (const std::string& word : filteredWords) {
        std::cout << word << std::endl;
    }
}
