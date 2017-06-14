#include "manager.h"

manager:: manager(){
    num_people=0;
}

int manager::GetCount(){
    return num_people;
}

person* manager::Retrieve(int nIndex){
    return vpperson[nIndex - 1];
}

void manager::Add(person *_pperson){
    vpperson.push_back(_pperson);
    num_people++;
}

bool manager::Delete(int nIndex){
    if (nIndex<1||nIndex>num_people){
        return false;
    }

    for (int i=nIndex;i<num_people;i++){
        vpperson[i-1]=vpperson[i];
    }
    num_people--;
    return true;
}

bool manager::Update(int nIndex, person *_pperson){
    if (nIndex<1||nIndex>num_people){
        return false;
    }
    vpperson[nIndex-1]=_pperson;
    return true;
}

void printallpersons(){
    for (int i=0; i<MAX_PERSON_CNT; i++) {
        std::cout << "test" << "\n";
    }
}

void manager::printall(){
    auto print_forloop = [](auto ptr, auto nptr){
        for(int i = 0; i<nptr; i++){
            std::cout << std::setw(20) << std::left << "<< i >> " << std::setw(20) << " has value: " << i << "\n";
            ptr[i]->printinfo();};
    };

    print_forloop(vpperson, num_people);

    /*
    print_forloop(pStudent, num_students);
    print_forloop(pWorker, num_workers);
    print_forloop(pWorkingStudent, num_working_students);
    //Printallworkers(){};
    //printallworkingstudents(){};
    */
}
