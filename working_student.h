#pragma once
#include "person.h"
#include "student.h"
#include "worker.h"

class working_student: public student ,public worker
{
public:
    working_student(){salary=0; nKoreanScore=0; nEnglishScore=0; nMathScore=0;};
    //~working_student(){std::cout<<"The working student with the name (" << name << ") is deleted!\n";}
    /*
    working_student(working_student& orig): student(), worker(){
        nKoreanScore=orig.nKoreanScore;
        nEnglishScore=orig.nEnglishScore;
        nMathScore=orig.nMathScore;
        salary=orig.salary;
        std::cout << "copying working student..." << "\n";
    };
    */
    void printinfo(){
        std::cout << std::setw(20) << std::left << "<< name >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &name << std::setw(25) << " and set(get) value of " << name << "\n";
        std::cout << std::setw(20) << std::left << "<< salary >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &salary << std::setw(25) << " and set(get) value of " << salary << "\n";
        std::cout << std::setw(20) << std::left << "<< nMathScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nMathScore << std::setw(25) << " and set(get) value of " << nMathScore << "\n";
        std::cout << std::setw(20) << std::left << "<< nKoreanScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nKoreanScore << std::setw(25) << " and set(get) value of " << nKoreanScore << "\n";
        std::cout << std::setw(20) << std::left << "<< nEnglishScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nEnglishScore << std::setw(25) << " and set(get) value of " << nEnglishScore << "\n";
    }
};
