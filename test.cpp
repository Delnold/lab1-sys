#include <iostream>
#include <vector>
#include "functions.h"

void checkAndPrintResult(bool result, const std::string& testName) {
    if (result) {
        std::cout << testName << " - Passed" << std::endl;
    } else {
        std::cout << testName << " - Failed" << std::endl;
    }
}

int main() {
    checkAndPrintResult(to_lower("Hello") == "hello", "to_lower Test 1");
    checkAndPrintResult(to_lower("WORLD") == "world", "to_lower Test 2");
    checkAndPrintResult(isVowel('a') == true, "isVowel Test 1");
    checkAndPrintResult(isVowel('b') == false, "isVowel Test 2");
    checkAndPrintResult(checkWordCondition("apple") == false, "checkWordCondition Test 1");
    checkAndPrintResult(checkWordCondition("banana") == false, "checkWordCondition Test 2");
    checkAndPrintResult(checkWordCondition("avocado") == true, "checkWordCondition Test 3");
    checkAndPrintResult(checkWordCondition("Notebook") == false, "checkWordCondition Test 4");


    std::cout << "All tests completed." << std::endl;
    std::cin.get();

    return 0;
}
