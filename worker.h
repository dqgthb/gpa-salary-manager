#pragma once
#include "person.h"
#include<iostream>
#include<iomanip>

class worker: virtual public person{
protected:
    int salary;

public:
    worker(){salary=0;}
    worker(int _salary){salary=_salary;}
    //~worker(){std::cout<<"The worker with the name ("<< name <<") is deleted!\n";}

    /*
    worker(worker& orig):person(){
        pname=orig.pname;
        salary=orig.salary;
        std::cout << "copying..." << "\n";
    }
    */

    int get_salary(){return salary;}
    void set_salary(int _salary){salary=_salary;}
    void printinfo(){
        std::cout << std::setw(20) << std::left << "<< salary >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &salary << std::setw(25) << " and set(get) value of " << salary << "\n";
    }
};
