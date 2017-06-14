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

/* // Disabled for backward-compatibility. auto is not supported before c++14.
void manager::printall(){
    auto print_forloop = [](auto ptr, auto nptr){
        for(int i = 0; i<nptr; i++){
            std::cout << std::setw(20) << std::left << "<< i >> " << std::setw(20) << " has value: " << i << "\n";
            ptr[i]->printinfo();};
    };
    print_forloop(vpperson, num_people);
}
*/

void manager::printall(){
    print_forloop(vpperson, num_people);
}

void manager::print_forloop(std::vector<person*> vpp, int num_people){
    for (int i = 0; i < num_people; i++){
        std::cout << std::setw(20) << std::left << "<< i >> " << std::setw(20) << " has value: " << i << "\n";
        vpp[i]->printinfo();
    }
}
