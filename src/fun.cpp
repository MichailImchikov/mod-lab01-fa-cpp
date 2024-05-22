// Copyright 2022 UNN-IASR
#include <iostream>
#include<vector>
#include <cmath>
#include <cctype>
unsigned int faStr1(const char* str) {
    bool newWord = false;
    int Count = 0;
    int i = 0;
    std::vector<char> bufStr;
    while (str[i]) {
        if (newWord) {
            bool world = true;
            for (int j = 0; j < bufStr.size(); j++) {
                if (!isalpha(bufStr[j])) {
                    world = false;
                }
            }
            if (world&&bufStr.size() > 0) {
                Count++;
            }
            newWord = false;
            bufStr.clear();
            continue;
        }
        if (str[i] == ' ' || str[i] == '\0') {
            newWord = true;
            i++;
            continue;
        }
        bufStr.push_back(str[i]);
        i++;
    }
    bool world = true;
    for (int j = 0; j < bufStr.size(); j++) {
        if (!isalpha(bufStr[j])) {
            world = false;
        }
    }
    if (world && bufStr.size() > 0) {
        Count++;
    }
    return Count;
}
unsigned int faStr2(const char* str) {
    bool flag = false;
    float result = 0;
    int i = 0;
    int count = 0;
    bool IsWorld = true;
    while (str[i]) {
        if (!flag && str[i] != ' ' && str[i] >= 65 && str[i] <= 90&&IsWorld) {
            flag = true;
            count = 1;
        } else if (flag && str[i] == ' ') {
            flag = false;
            result += count;
            if (flag) {
                IsWorld = true;
            }
        } else if (str[i] < 97 || str[i] > 122) {
            count = 0;
        }
        i++;
        if (flag) {
            IsWorld = true;
        }
    }
    return (int)result;
}
unsigned int faStr3(const char* str) {
    int i = 0;
    int SumChar = 0;
    int CountWord = 0;
    int BufWord = 0;
    while (str[i]) {
        if (str[i] == ' ') {
            if (BufWord > 0) {
                CountWord++;
            }
            SumChar += BufWord;
            BufWord = 0;
        } else {
            BufWord++;
        }
        i++;
    }
    if (str[i - 1] != ' ') {
        if (BufWord > 0) {
            CountWord++;
        }
        SumChar += BufWord;
    }
    return round(static_cast<float>(SumChar) / CountWord);
}
