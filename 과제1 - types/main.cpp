#include <iostream>
#include <limits>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    int countI{}, countL{}, countF{}, countD{};
    string cmd;

    while (1) {
        cin >> cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) { return toupper(c); });

        if (cmd == "INT") {
            countI++;
            cout << numeric_limits<int>::max() << " "
                << numeric_limits<int>::min() << endl;
        } else if (cmd == "LONG") {
            countL++;
            cout << numeric_limits<long>::max() << " "
                 << numeric_limits<long>::min() << endl;
        } else if (cmd == "FLOAT") {
            countF++;
            cout << numeric_limits<float>::max() << " "
                 << numeric_limits<float>::min() << endl;
        } else if (cmd == "DOUBLE") {
            countD++;
            cout << numeric_limits<double>::max() << " "
                 << numeric_limits<double>::min() << endl;
        } else if (cmd == "QUIT") {
            break;
        } else {
            cout << "Invalid Command\n";
        }
    }
    cout << "=== the number of types ===\n"
        << "int: " << countI << endl
        << "long: " << countL << endl
        << "float: " << countF << endl
        << "double: " << countD << endl;
}