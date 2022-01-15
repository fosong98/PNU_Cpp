#include "shape.h"
#include <iostream>
#include <algorithm>
using namespace std;



int main() {

    vector<unique_ptr<Rectangle>> rvec; vector<unique_ptr<Circle>> cvec;

    while(true) {

        string cmd; cin >> cmd;

        transform(begin(cmd), end(cmd), begin(cmd),  [](char& c){return tolower(c);});

        Command c = getCommand(cmd);

        switch(c){

            case RECT:

                rvec.emplace_back(make_rectangle());

                break;

            case CIRCLE:

                cvec.emplace_back(make_circle());

                break;

            case CLEAR:

                rvec.clear(); cvec.clear();

                break;

            case QUIT:

                return 0;

            case INVALID:

                cout << "Invalid Command" << '\n';

                break;

            case PRINT:

                for_each(rvec.cbegin(), rvec.cend(), [](const unique_ptr<Rectangle>& r) {
                    cout << "Rectangle:\t\t" << r->width << '\t'
                         << r->height << '\t' << r->area << endl;
                });

                for_each(cvec.cbegin(), cvec.cend(), [](const unique_ptr<Circle>& c) {
                    cout << "Circle:\t\t\t" << c->radius << '\t' << c->area << endl;
                });

                break;

            case SORT:
                sort(rvec.begin(), rvec.end(), [&](const unique_ptr<Rectangle>& r1, const unique_ptr<Rectangle>& r2) {
                    return r1->area > r2->area;
                });

                sort(cvec.begin(), cvec.end(), [&](const unique_ptr<Circle>& c1, const unique_ptr<Circle>& c2) {
                    return c1->area > c2->area;
                });

                break;

            case SUM:
                int sum = 0;
                for_each(cvec.cbegin(), cvec.cend(), [&](const unique_ptr<Circle>& ptr) {
                    sum += ptr->area;
                });
                for_each(rvec.cbegin(), rvec.cend(), [&](const unique_ptr<Rectangle>& ptr) {
                    sum += ptr->area;
                });
                cout << sum << endl;

                break;
        }
    }
}