#pragma once
#include "CStudent.h"
#include "worker.h"
#include "working_student.h"

#define MAX_STUDENT_CNT 10
#define MAX_WORKER 10
#define MAX_WORKING_STUDENT 10

class CStudentManager {
private:
    int nCnt;
    int num_workers;
    int num_working_students;

    CStudent pStudent[MAX_STUDENT_CNT];
    worker pWorker[MAX_WORKER];
    working_student pWorkingStudent[MAX_WORKING_STUDENT];

public:
    CStudentManager();
    int GetCount();
    int get_num_workers(){return num_workers;};
    int get_num_working_students(){return num_working_students;};

    CStudent Retrieve(int nIndex);
    void Add(CStudent& _pStudent);
    bool Delete(int nIndex);
    bool Update(int nIndex, CStudent& _pStudent);
};
