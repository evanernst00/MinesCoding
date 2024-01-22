#ifndef course
#define course
#include <string>
#include <iostream>

using namespace std;

class Course {
public:

    int enrollment;
    string title;

    Course();
    Course(const string title);
};

#endif