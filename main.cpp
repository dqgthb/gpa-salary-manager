#include <iostream>
#include <iomanip>
#include "worker.h"
#include "working_student.h"
#include "student.h"
#include "studentmanager.h"
#include "cin_validate.h"

using namespace std;

void PrintMenu();
void Retrieve();
void Add();
void Delete();
void Update();
void Quit();
void printall();
void PrintScores(int nIndex);
void get_score(const char*, student&, void (student::*fp)(int));
int choose();

studentmanager mgr;

int main(){
    int nMenu;

    while (true){
        PrintMenu();
        cin_int(nMenu);

        switch (nMenu){
        case 1:
            Retrieve();
            break;
        case 2:
            Add();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Update();
            break;
        case 5:
            Quit();
            return 0;
        case 6:
            printall();
            break;
        default:
            std::cout << "Please enter the correct switch number." << "\n";
            break;
        }

    }
    return 0;
}

void PrintMenu(){
    cout<<"*********************"<<endl;
    cout<<"1. Retrieve"<<endl;
    cout<<"2. Add"<<endl;
    cout<<"3. Delete"<<endl;
    cout<<"4. Update"<<endl;
    cout<<"5. Quit"<<endl;
    std::cout << "6. Print all data" << "\n";
    cout<<"*********************"<<endl;
    cout<<"> ";
}

void Retrieve(){
    int choice = choose();
    int count = mgr.GetCount(choice);
    if (count==0){
        cout<<"There is no data."<<endl;
        return;
    }

    int nMin=300;
    int nMax=0;
    int nKoreanSum=0;
    int nEnglishSum=0;
    int nMathSum=0;

    for(int i=1;i<=count;i++){
        PrintScores(i);

        if (nMin>=mgr.Retrieve(i).GetTotal())
            nMin=mgr.Retrieve(i).GetTotal();

        if (nMax<=mgr.Retrieve(i).GetTotal())
            nMax=mgr.Retrieve(i).GetTotal();

        nKoreanSum+=mgr.Retrieve(i).GetKoreanScore();
        nEnglishSum+=mgr.Retrieve(i).GetEnglishScore();
        nMathSum+=mgr.Retrieve(i).GetMathScore();
    }

    cout<<"Sum: Korean "<<nKoreanSum<<" points"<<" Math "<<nMathSum<<" points"
        <<" English "<<nEnglishSum<<" points"<<endl;
    cout<<"Average: Korean "<<nKoreanSum/mgr.GetCount()<<" points"
        <<" Math "<<nMathSum/mgr.GetCount()<<" points"
        <<" English "<<nEnglishSum/mgr.GetCount()<<" points"<<endl;

    cout<<"#1/";
    for (int i=1;i<=mgr.GetCount();i++)
        if (nMax==mgr.Retrieve(i).GetTotal())
            PrintScores(i);

    cout<<"#Last/";
    for (int i=1;i<=mgr.GetCount();i++)
        if (nMin==mgr.Retrieve(i).GetTotal())
            PrintScores(i);
}

void choose_Add(){
    int choice = choose();
    int count = mgr.GetCount(choice);
    if (count==MAX_STUDENT_CNT){
        cout<<"There are the maximum number of data."<<endl;
        return;
    }

    switch(choice){
    case 1:
        return;
    }
}

void Add(){
    int choice = choose();
    int count = mgr.GetCount(choice);
    if (count==MAX_STUDENT_CNT){
        cout<<"There are the maximum number of data."<<endl;
        return;
    }
    student mystudent;
    //student mystudent;
    get_score("Korean?:", mystudent, &student::SetKoreanScore);
    get_score("Math?:", mystudent, &student::SetMathScore);
    get_score("English?:", mystudent, &student::SetEnglishScore);
    mgr.Add(mystudent);
    PrintScores(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void Delete(){
    int choice = choose();
    int count = mgr.GetCount(choice);
    int nIndex;
    cout<<"Delete No?>";
    cin_int(nIndex);

    if (nIndex<1||nIndex>count){
        cout<<"There is no data."<<endl;
        return;
    }

    mgr.Delete(nIndex);

    cout<<"Deleted!"<<endl;
}

void Update(){
    int choice = choose();
    int count = mgr.GetCount(choice);
    int nIndex;
    cout<<"Update No?>";
    cin_int(nIndex);
    if (nIndex<1||nIndex>count) {
        cout<<"There is no data."<<endl;
        return;
    }

    student mystudent;
    get_score("Korean?:", mystudent, &student::SetKoreanScore);
    get_score("Math?: ", mystudent, &student::SetMathScore);
    get_score("English?:", mystudent, &student::SetEnglishScore);
    mgr.Update(nIndex, mystudent);
    PrintScores(nIndex);
    cout<<"Updated!"<<endl;
}

void Quit() {
    cout<<"Bye!"<<endl;
}

void PrintScores(int nIndex) {
    cout<<nIndex<<"."<<" Korean:"<<mgr.Retrieve(nIndex).GetKoreanScore()
        <<" Math:"<<mgr.Retrieve(nIndex).GetMathScore()
        <<" English:"<<mgr.Retrieve(nIndex).GetEnglishScore()<<endl;
}

void printall(){
    std::cout << "printall!" << "\n";
    mgr.printall();
}

void get_score(const char *msg,student& mys, void (student::*fp)(int)){
    std::cout << msg;
    unsigned int tmp;
    for(;;){
        cin_validate(tmp);
        if(tmp<=100){
            (mys.*fp)(tmp);
            break;
        }else
            std::cerr << "The entered value is not within normal range.\n";
    }
}

int choose(){
    std::cout << "Add what?\n"
              << "(1) Student\n"
              << "(2) Worker\n"
              << "(3) Working Student\n";
    int sub_input;
    cin_int(sub_input);
    return sub_input;
}
