#pragma once
#include<iostream>
#include<iomanip>
#include<string>

class person{
protected:
    std::string name;
public:
    person(){};
    virtual ~person(){};
    std::string get_name(){return name;}
    void set_name(std::string _name){ name=_name; }

    /*
    person(std::string _pname):pname(_pname){}
    std::string getname(){return pname;}
    void setname(std::string _pname){pname=_pname;}
    */

    //virtual void printinfo()=0;
    void printinfo(){
        std::cout << std::setw(20) << std::left << "<< name >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &name << std::setw(25) << " and set(get) value of " << name << "\n";
    }
    /*
    virtual void printinfo();
    virtual int GetKoreanScore();
    virtual int GetMathScore();
    virtual int GetEnglishScore();
    virtual int get_salary();
    */
};
