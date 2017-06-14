#pragma once
#include "person.h"
#include "student.h"
#include "worker.h"
#include "working_student.h"
#include <vector>

#define MAX_STUDENT_CNT 10
#define MAX_WORKER_CNT 10
#define MAX_WORKING_STUDENT_CNT 10
#define MAX_PERSON_CNT 30

class manager {
private:
    int num_students;
    int num_workers;
    int num_working_students;
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
    int get_num_workers(){return num_workers;};
    int get_num_working_students(){return num_working_students;};

    person *Retrieve(int nIndex);
    void Add(person*);
    bool Delete(int nIndex);
    bool Update(int nIndex, person*);
    void printall();
};
