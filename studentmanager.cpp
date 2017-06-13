#include "student.h"
#include "studentmanager.h"

studentmanager:: studentmanager()
{
    num_students=0;
}
int studentmanager::GetCount(){
    return num_students;
}

int studentmanager::GetCount(int choice)
{
    switch(choice){
    case 1:
        return num_students;
    case 2:
        return num_working_students;
    case 3:
        return num_workers;
    default:
        std::cerr << "wrong choice." << "\n";
        return -1;
    }
}

student studentmanager::Retrieve(int nIndex)
{
    return pStudent[nIndex - 1];
}

void studentmanager::Add(student& _pStudent)
{
    pStudent[num_students]=_pStudent;
    num_students++;
}

bool studentmanager::Delete(int nIndex)
{
    if (nIndex<1||nIndex>num_students)
    {
        return false;
    }

    for (int i=nIndex;i<num_students;i++)
    {
        pStudent[i-1]=pStudent[i];
    }
    num_students--;
    return true;
}

bool studentmanager::Update(int nIndex, student& _pStudent)
{
    if (nIndex<1||nIndex>num_students)
    {
        return false;
    }
    pStudent[nIndex-1]=_pStudent;
    return true;
}

void printallstudents(){
    for (int i=0; i<MAX_STUDENT_CNT; i++) {
        std::cout << "test" << "\n";
    }
}

void studentmanager::printall(){
    auto print_forloop = [](auto ptr, auto nptr){
        for(int i = 0; i<nptr; i++){
            std::cout << std::setw(20) << std::left << "<< i >> " << std::setw(20) << " has value: " << i << "\n";
            ptr[i].printinfo();};
    };

    print_forloop(pStudent, num_students);
    print_forloop(pWorker, num_workers);
    print_forloop(pWorkingStudent, num_working_students);
    //Printallworkers(){};
    //printallworkingstudents(){};
}
