#include <iostream>
#include <map>
#include <regex>

using namespace std;

int main(void) {
    map<string, int> words;
    string str;
    while (cin >> str && str != "^") {
        str = regex_replace(str, regex("[.|,|:|;| ]"), "");
        auto f = words.find(str);
        if (f != words.end())
            f->second++;
        else
            words[str] = 1;
    }
    cout << "words: " << words.size() << endl;
    string cmd;
    while (1) {
        cin >> cmd;
        if (cmd == "QUIT")
            break;
        else {
            if (words.find(cmd) == words.end())
                cout << cmd << ": " << 0 << endl;
            else
                cout << cmd << ": " << words[cmd] << endl;
        }
    }
    cout << "Bye!";
}