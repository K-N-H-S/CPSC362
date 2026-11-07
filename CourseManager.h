#pragma once

#include "Course.h"

#include <map>
#include <vector>
#include <string>

using namespace std;

class CourseManager
{
private:

    map<string, Course> courseMap;

    vector<Course> studentSchedule;

    vector<string> ExtractCourses(
        const string& line);

public:

    bool LoadCourses(
        const string& filename);

    bool LoadMajor(
        const string& major);

    Course* GetCourse(
        const string& courseID);

    map<string, Course>& GetCourses();

    bool AddCourseToSchedule(
        const string& courseID);

    vector<Course>& GetSchedule();

    void ClearSchedule();
};
