#include "tablecipher.h"
tablecipher::tablecipher(int key) : st(key) {
    if(!isValidKey(key)) {
        throw cipher_error("Bad Key");
    }
    }
string tablecipher::encrypt(string text)
{
    text = getValidOpenText(text);
    int s = text.length();
    int str = ceil(double(s) / st);
    char tab[str][st];
    string res;
    int index = 0;
    for(int a = 0; a < str; ++a) {
        for(int b = 0; b < st; ++b) {
            tab[a][b] = text[index];
            index++;
        }
    }
    for(int i = st - 1; i >= 0; --i) {
        for(int j = 0; j < str; ++j) {
            if(tab[i][j] != ' ') {
                res += tab[j][i];
            }
        }
    }
    return res;
}
string tablecipher::decrypt(string text)
{
    text = getValidOpenText(text);
    int s = text.length();
    int p = s;
    string res;
    int str = ceil(double(s) / st);
    char tab[str][st];
    for (int x = 0; x < s; x++) {
        if (p%st != 0) {
        p++;
    } else {
        break;
    }
    }
    int n = p-s;
    int h = str - 1;
    int z = 0;
    for (int j = st - 1; j >= 0; --j) {
            if (z < n) {
            tab[h][j] = ' ';
            z++;
            } else {
                break;
            }
    }
    int index = 0;
    for (int i = st - 1; i >= 0; --i) {
        for (int j = 0; j < str; ++j) {
            if (index < s and tab[j][i] != ' ') {
                tab[j][i] = text[index];
                index++;
            }
            }
        }
    for (int a = 0; a < str; ++a) {
        for (int b = 0; b < st; ++b) {
            if (tab[a][b] != ' ') {
                res += tab[a][b];
            }
        }
    }
    return res;
}
 bool tablecipher::isValidKey(int key) { 
    return key > 0; 
}
inline std::string tablecipher::getValidOpenText (const std::string& s)
{
    std::string tmp;
    for(auto c : s) {
        if(c != ' ') {
            tmp.push_back(c);
        }
    }
    if(tmp.empty())
        throw cipher_error("Pusto");
    return tmp;
}
    
