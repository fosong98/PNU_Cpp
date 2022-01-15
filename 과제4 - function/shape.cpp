#include "shape.h"

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;



unique_ptr<Rectangle> make_rectangle(){
    int w, h;
    cin >> w >> h;
    int area = w * h;
    unique_ptr<Rectangle> ptr(new Rectangle{w, h, area});
    return move(ptr);
}

unique_ptr<Circle> make_circle(){
    int r;
    cin >> r;
    double area = 3.14 * r * r;
    unique_ptr<Circle> ptr(new Circle{r, area});
    return move(ptr);
}

Command getCommand(const string& command){
    vector<string> cmd = {"rect", "circle", "print", "sum", "sort", "clear", "quit"};
    map<string, Command> coll;
    for_each(cmd.begin(), cmd.end(), [&](string s) {
        coll[s] = Command(find(cmd.begin(), cmd.end(), s) - cmd.begin());
    });
    if (coll.find(command) == coll.end()) {
        return INVALID;
    } else {
        return coll[command];
    }
}
