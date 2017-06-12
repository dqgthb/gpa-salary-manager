#pragma once
#include<iostream>
#include<iomanip>

class worker
{
protected:
    int salary;

public:
    worker(){salary=0;}
    worker(int _salary){salary=_salary;}
    worker(worker& origin){
        salary=origin.salary;
        std::cout << "copying..." << "\n";
    }
    int getSalary(){return salary;}
    void setSalary(int _salary){salary=_salary;}
    void printinfo(){
        std::cout << std::setw(20) << std::left << "<< salary >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &salary << std::setw(25) << " and set(get) value of " << salary << "\n";
    }
};
