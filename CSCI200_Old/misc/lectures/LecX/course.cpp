#include <iostream>
#include <string>
#include "course.h"

using namespace std;

Course()
{
    _enrollment = 0;
    _title = "CSM 101";
}
Course (const string TITLE)
{
    _enrollment = 0;
    _title = TITLE;
}