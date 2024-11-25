#pragma once
#include <string>
#include <locale>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
class tablecipher {
private:
    int st;
    bool isValidKey(int key); 
    string getValidOpenText(const std::string& s);
public:
    tablecipher(int key);
    tablecipher() = delete;
    string encrypt(string text);
    string decrypt(string text);
};
class cipher_error : public std::invalid_argument
{
public:
    explicit cipher_error(const std::string& what_arg): 
    std::invalid_argument(what_arg){}
    explicit cipher_error(const char* what_arg): 
    std::invalid_argument(what_arg){}
};
