#include <iostream>
#include <iomanip>
#include "person.h"
#include "worker.h"
#include "working_student.h"
#include "student.h"
#include "manager.h"
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
void get_salary(const char*, worker&, void (worker::*fp)(int));
int choose();
void add_student();
void add_worker();
void add_working_student();

manager mgr;

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
    int count = mgr.GetCount();
    if (count==0){
        cout<<"There is no data."<<endl;
        return;
    }

    /*
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
    */
}

void Add(){
    int count = mgr.GetCount();
    if(count==MAX_STUDENT_CNT){
        cout<<"There are the maximum number of data."<<endl;
        return;
    }

    int choice = choose();
    switch(choice){
    case 1:
        add_student();
        break;
    case 2:
        add_worker();
        break;
    case 3:
        add_working_student();
        break;
    }
}

void add_student(){
    student *ps = new student();
    get_score("Korean?:", *ps, &student::SetKoreanScore);
    get_score("Math?:", *ps, &student::SetMathScore);
    get_score("English?:", *ps, &student::SetEnglishScore);

    mgr.Add(ps);
    PrintScores(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void add_worker(){
    worker *pw = new worker();
    get_salary("Salary?:", *pw, &worker::set_salary);

    mgr.Add(pw);
    PrintScores(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void add_working_student(){
    working_student *pws = new working_student();
    get_score("Korean?:", *pws, &student::SetKoreanScore);
    get_score("Math?:", *pws, &student::SetMathScore);
    get_score("English?:", *pws, &student::SetEnglishScore);
    get_salary("Salary?:", *pws, &worker::set_salary);

    mgr.Add((person*)pws);
    PrintScores(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void Delete(){
    int count = mgr.GetCount();
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
    int count = mgr.GetCount();
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

    person *ps = &mystudent;
    mgr.Update(nIndex, ps);
    PrintScores(nIndex);
    cout<<"Updated!"<<endl;
}

void Quit() {
    cout<<"Bye!"<<endl;
}

void PrintScores(int nIndex) {
    person *pp = mgr.Retrieve(nIndex);
    student *sp = dynamic_cast<student*>(pp);
    cout<<nIndex<<"."<<" Korean:"<<sp->GetKoreanScore()
        <<" Math:"<<sp->GetMathScore()
        <<" English:"<<sp->GetEnglishScore()<<endl;
}
void PrintSalary(int nIndex){
    person *pp = mgr.Retrieve(nIndex);
    worker *wp = dynamic_cast<worker*>(pp);
    cout<<nIndex<<"."<<" Salary:"<<wp->get_salary()<<endl;
}

void printall(){
    std::cout << "printall!" << "\n";
    mgr.printall();
}

void get_score(const char *msg,student& mys, void (student::*fp)(int)){
    std::cout << msg;
    int tmp;
    for(;;){
        cin_validate(tmp);
        if(tmp>=0&&tmp<=100){
            (mys.*fp)(tmp);
            break;
        }else
            std::cerr << "The entered value is not within normal range.\n";
    }
}

void get_salary(const char *msg, worker& myw, void (worker::*fp)(int)){
    std::cout << msg;
    int tmp;
    for(;;){
        cin_validate(tmp);
        if(tmp>=0){
            (myw.*fp)(tmp);
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
