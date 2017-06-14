#pragma once
#include "person.h"
#include "student.h"
#include "worker.h"
#include "working_student.h"
#include <vector>

#define MAX_PERSON_CNT 3

class manager {
private:
    int num_people; // Logically, this must be sum of the above three.
    /*
    student pStudent[MAX_STUDENT_CNT];
    worker pworker[MAX_WORKER];
    working_student pworking_student[MAX_WORKING_STUDENT];
    */
    std::vector<person*> vpperson; // vector of pointer to person

public:
    manager();
    int GetCount(int);
    int GetCount();

    person *Retrieve(int nIndex);
    void Add(person*);
    bool Delete(int nIndex);
    bool Update(int nIndex, person*);
    void printall();
    void print_forloop(std::vector<person*>, int);
};
