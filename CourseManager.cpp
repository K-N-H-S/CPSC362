#include "pch.h"
#include "CourseManager.h"

#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> CourseManager::ExtractCourses(
    const string& line)
{
    vector<string> courses;

    for (size_t i = 0; i < line.length(); i++)
    {
        // Look for department code
        if (i + 8 < line.length() &&
            isupper(line[i]) &&
            isupper(line[i + 1]) &&
            isupper(line[i + 2]) &&
            isupper(line[i + 3]) &&
            line[i + 4] == ' ')
        {
            string course;

            course += line[i];
            course += line[i + 1];
            course += line[i + 2];
            course += line[i + 3];
            course += ' ';

            size_t j = i + 5;

            while (j < line.length() &&
                (isdigit(line[j]) ||
                    isalpha(line[j])))
            {
                course += line[j];
                j++;
            }

            courses.push_back(course);
        }
    }

    return courses;
}

bool CourseManager::LoadCourses(const string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    string line;
    string currentCourse;

    while (getline(file, line))
    {
        if (line.find('(') != string::npos && line.find(')') != string::npos)
        {
            Course course;

            size_t leftParen = line.find('(');

            size_t rightParen = line.find(')');

            currentCourse = line.substr(0, leftParen);

            while (!currentCourse.empty() && currentCourse.back() == ' ')
            {
                currentCourse.pop_back();
            }

            course.courseID = currentCourse;

            string unitsString =
                line.substr(
                    leftParen + 1,
                    rightParen - leftParen - 1);

            if (unitsString.find('-') == string::npos)
            {
                course.units = stoi(unitsString);
            }

            courseMap[currentCourse] = course;
        }

        else if (line.find("Prerequisite") != string::npos)
        {
            if (line.find("N/A") != string::npos)
            {
                continue;
            }

            vector<string> prereqs = ExtractCourses(line);

            for (const auto& prereq : prereqs)
            {
                courseMap[currentCourse]
                    .prerequisites
                    .push_back(prereq);
            }
        }

        else if (line.find("Corequisite") != string::npos)
        {
            if (line.find("N/A") != string::npos)
            {
                continue;
            }

            vector<string> coreqs = ExtractCourses(line);

            for (const auto& coreq : coreqs)
            {
                courseMap[currentCourse]
                    .corequisites
                    .push_back(coreq);
            }
        }
    }

    file.close();

    return true;
}

bool CourseManager::LoadMajor(const string& major)
{
    string tempMajor = major;

    for (char& ch : tempMajor)
    {
        ch = static_cast<char>(
            tolower(
                static_cast<unsigned char>(ch)));
    }

    if (tempMajor == "computer science")
    {
        courseMap.clear(); 
        return LoadCourses("ComputerScienceMajorClasses.txt");
    }

    if (tempMajor == "biology")
    {
        courseMap.clear();
        return LoadCourses("BiologyMajorClasses.txt");
    }

    if (tempMajor == "chemistry")
    {
        courseMap.clear();
        return LoadCourses("ChemistryMajorClasses.txt");
    }

    if (tempMajor == "physics")
    {
        courseMap.clear();
        return LoadCourses("PhysicsMajorCLasses.txt");
    }

    return false;
}

Course* CourseManager::GetCourse(const string& courseID)
{
    auto it = courseMap.find(courseID);

    if (it != courseMap.end())
    {
        return &(it->second);
    }

    return nullptr;
}

map<string, Course>& CourseManager::GetCourses()
{
    return courseMap;
}

bool CourseManager::AddCourseToSchedule(const string& courseID)
{
    // Maximum 4 classes

    if (studentSchedule.size() >= 4)
    {
        return false;
    }

    auto it = courseMap.find(courseID);

    if (it == courseMap.end())
    {
        return false;
    }

    // Prevent duplicates

    for (const auto& course : studentSchedule)
    {
        if (course.courseID
            == courseID)
        {
            return false;
        }
    }

    studentSchedule.push_back(it->second);

    return true;
}

vector<Course>& CourseManager::GetSchedule()
{
    return studentSchedule;
}

void CourseManager::ClearSchedule()
{
    studentSchedule.clear();
}