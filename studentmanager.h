#pragma once
#include "student.h"
#include "worker.h"
#include "working_student.h"

#define MAX_STUDENT_CNT 10
#define MAX_WORKER 10
#define MAX_WORKING_STUDENT 10

class studentManager {
private:
    int nCnt;
    int num_workers;
    int num_working_students;
    student pStudent[MAX_STUDENT_CNT];
    worker pWorker[MAX_WORKER];
    working_student pWorkingStudent[MAX_WORKING_STUDENT];

public:
    studentManager();
    int GetCount();
    int get_num_workers(){return num_workers;};
    int get_num_working_students(){return num_working_students;};

    student Retrieve(int nIndex);
    void Add(student& _pStudent);
    bool Delete(int nIndex);
    bool Update(int nIndex, student& _pStudent);
    void printall();
};
