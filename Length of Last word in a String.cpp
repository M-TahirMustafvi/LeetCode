#include <iostream>
#include <string>
using namespace std;

int length(string s) {
    int len = 0, i = s.size() - 1;
    while (i >= 0 && s[i] == ' ') i--; // skip trailing spaces
    while (i >= 0 && s[i] != ' ') { 
        len++;
        i--;
    }
    return len;
}

int main() {
    cout << length("Tahir Mustafvi") << endl;
    return 0;
}