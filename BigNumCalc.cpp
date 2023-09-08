#include "BigNumCalc.h"
//creates a list representing the provided string.
std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> numList;
    for (char c : numString) {
        numList.push_back(c - '0');
    }
    return numList;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry_number = 0;
    while (!num1.empty() || !num2.empty()) {
        int the_first_number = 0, the_second_number = 0;
        if (!num1.empty()) {
            the_first_number = num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            the_second_number = num2.back();
            num2.pop_back();
        }
        int sum = the_first_number + the_second_number + carry_number;
        carry_number = sum / 10;
        result.push_front(sum % 10);
    }
    if (carry_number) {
        result.push_front(carry_number);
    }
    return removeLeadingZeros(result);
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int borrow_number = 0;
    while (!num1.empty() || !num2.empty()) {
        int the_first_number = 0, the_second_number = 0;
        if (!num1.empty()) {
            the_first_number = num1.back();
            num1.pop_back();
        }
        if (!num2.empty()) {
            the_second_number = num2.back();
            num2.pop_back();
        }
        int diff = the_first_number - the_second_number - borrow_number;
        borrow_number = 0;
        if (diff < 0) {
            diff += 10;
            borrow_number = 1;
        }
        result.push_front(diff);
    }
    return removeLeadingZeros(result);
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    int carry_number = 0;
    for (int n : num1) {
        int prod = n * num2.front() + carry_number;
        carry_number = prod / 10;
        result.push_back(prod % 10);
    }
    if (carry_number) {
        result.push_back(carry_number);
    }
    return removeLeadingZeros(result);
}

std::list<int> BigNumCalc::removeLeadingZeros(std::list<int> num) {
    while (!num.empty() && num.front() == 0) {
        num.pop_front();
    }
    if (num.empty()) {
        num.push_back(0);
    }
    return num;
}
