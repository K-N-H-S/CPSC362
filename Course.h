#pragma once

#include <string>
#include <vector>

using namespace std;

struct Course
{
    string courseID;

    int units = 0;

    vector<string> prerequisites;

    vector<string> corequisites;
};
