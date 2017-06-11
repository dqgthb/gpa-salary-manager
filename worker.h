#pragma once
#include<iostream>

class worker
{
protected:
    int salary;

public:
    worker(){salary=0;};
    worker(int _salary){salary=_salary;}
    worker(worker& origin){
        salary=origin.salary;
        std::cout << "copying..." << "\n";}
    int getSalary(){return salary;};
    void setSalary(int _salary){salary=_salary;};
};
