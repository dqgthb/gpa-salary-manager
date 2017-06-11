#pragma once
#include "CStudent.h"
#include "worker.h"

class working_student: public CStudent, public worker
{
public:
    working_student(){salary=0; nKoreanScore=0; nEnglishScore=0; nMathScore=0;};
    working_student(working_student& orig): CStudent(), worker(){
        nKoreanScore=orig.nKoreanScore;
        nEnglishScore=orig.nEnglishScore;
        nMathScore=orig.nMathScore;
        salary=orig.salary;
        std::cout << "copying working student..." << "\n";
    };
};
