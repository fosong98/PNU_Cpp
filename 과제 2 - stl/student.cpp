#include "student.h"

using namespace std;



unique_ptr<StudentInfo> make_student(){
    StudentInfo* st = new StudentInfo;
    int sum = 0;
    cin >> st->name;
    for (int i = 0; i < SUBJECT_NO; ++i) {
        cin >> st->scores[i];
        sum += st->scores[i];
    }
    st->sum = sum;
    st->average = double(sum) / SUBJECT_NO;

    unique_ptr<StudentInfo> ptr(st);
    return move(ptr);
}

void print(const StudentInfo& si) {
    cout << si.name << '\t';
    for (auto elem : si.scores) {
        cout << elem << '\t';
    }
    cout << si.sum << '\t' << si.average << endl;
}

void print_all(const vector<unique_ptr<StudentInfo>>& vec) {
    for (auto& elem : vec) {
        print(*move(elem));
    }
}