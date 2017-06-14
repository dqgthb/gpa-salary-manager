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

void print_name(int nIndex);
void PrintScores(int nIndex);
void PrintSalary(int nIndex);

void cin_score(const char*, student&, void (student::*fp)(int));
void cin_salary(const char*, worker&, void (worker::*fp)(int));
string cin_name(void);

int choose();
void add_student();
void add_worker();
void add_working_student();
void update_student(int);
void update_worker(int);
void update_working_student(int);

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
    */

    for(int i=1;i<=count;i++){
        cout << "current index i : " << i << endl;
        person *p_dontknow = mgr.Retrieve(i);
        if(working_student *p_maybews=dynamic_cast<working_student*>(p_dontknow)){
            p_maybews->printinfo();
        }
        else if(student *p_maybes=dynamic_cast<student*>(p_dontknow)){
            p_maybes->printinfo();

        }else if(worker *p_maybew=dynamic_cast<worker*>(p_dontknow)){
            p_maybew->printinfo();

        }

    }

        /*
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
    ps->set_name(cin_name());
    cin_score("Korean?:", *ps, &student::SetKoreanScore);
    cin_score("Math?:", *ps, &student::SetMathScore);
    cin_score("English?:", *ps, &student::SetEnglishScore);

    mgr.Add(ps);
    print_name(mgr.GetCount());
    PrintScores(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void add_worker(){
    worker *pw = new worker();
    pw->set_name(cin_name());
    cin_salary("Salary?:", *pw, &worker::set_salary);

    mgr.Add(pw);
    print_name(mgr.GetCount());
    PrintSalary(mgr.GetCount());
    cout<<"Added!"<<endl;
}

void add_working_student(){
    working_student *pws = new working_student();
    pws->set_name(cin_name());
    cin_score("Korean?:", *pws, &student::SetKoreanScore);
    cin_score("Math?:", *pws, &student::SetMathScore);
    cin_score("English?:", *pws, &student::SetEnglishScore);
    cin_salary("Salary?:", *pws, &worker::set_salary);

    //mgr.Add((person*)pws);
    mgr.Add(pws);
    print_name(mgr.GetCount());
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
    int choice = choose();
    switch(choice){
    case 1:
        update_student(nIndex);
        break;
    case 2:
        update_worker(nIndex);
        break;
    case 3:
        update_working_student(nIndex);
        break;
    }

}
void update_student(int nIndex){
    student *ps=new student();
    ps->set_name(cin_name());
    cin_score("Korean?:", *ps, &student::SetKoreanScore);
    cin_score("Math?: ", *ps, &student::SetMathScore);
    cin_score("English?:", *ps, &student::SetEnglishScore);

    person *pp = dynamic_cast<person*>(ps);
    mgr.Update(nIndex, pp);
    print_name(nIndex);
    PrintScores(nIndex);
    cout<<"Updated!"<<endl;
}

void update_worker(int nIndex){
    worker *pw=new worker();
    pw->set_name(cin_name());
    cin_salary("Salary?:", *pw, &worker::set_salary);

    person *pp = dynamic_cast<person*>(pw);
    mgr.Update(nIndex, pp);
    print_name(nIndex);
    PrintScores(nIndex);
    cout<<"Updated!"<<endl;
}

void update_working_student(int nIndex){
    working_student *psw=new working_student();
    psw->set_name(cin_name());
    cin_score("Korean?:", *psw, &student::SetKoreanScore);
    cin_score("Math?: ", *psw, &student::SetMathScore);
    cin_score("English?:", *psw, &student::SetEnglishScore);
    cin_salary("Salary?:", *psw, &worker::set_salary);

    //person *pp = dynamic_cast<person*>(psw);
    person *pp = psw;
    mgr.Update(nIndex, pp);
    print_name(nIndex);
    cout<<"Updated!"<<endl;
}

void Quit() {
    cout<<"Bye!"<<endl;
}
void print_name(int nIndex){
    person *pp = mgr.Retrieve(nIndex);
    cout << "Name:" << pp->get_name() << "\n";
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

void cin_score(const char *msg,student& mys, void (student::*fp)(int)){
    std::cout << msg;
    int tmp;
    for(;;){
        cin_int(tmp);
        if(tmp>=0&&tmp<=100){
            (mys.*fp)(tmp);
            break;
        }else
            std::cerr << "The entered value is not within normal range.\n";
    }
}

void cin_salary(const char *msg, worker& myw, void (worker::*fp)(int)){
    std::cout << msg;
    int tmp;
    for(;;){
        cin_int(tmp);
        if(tmp>=0){
            (myw.*fp)(tmp);
            break;
        }else
            std::cerr << "The entered value is not within normal range.\n";
    }
}

int choose(){
    int sub_input;
    do{
        std::cout << "Add what?\n"
                << "(1) Student\n"
                << "(2) Worker\n"
                << "(3) Working Student\n";
        cin_int(sub_input);
        if(sub_input>0&&sub_input<=3)
            return sub_input;
        else
            cout << "Must be between 1 to 3!\n";
    }while(true);
}

string cin_name(){
    cout << "name?:";
    string in;
    cin_valid(in);
    return in;
}
