#pragma once
#include<iostream>
#include<string>

class person{
protected:
    //std::string pname;
public:
    person(){};
    virtual ~person(){};
    /*
    person(std::string _pname):pname(_pname){}
    std::string getname(){return pname;}
    void setname(std::string _pname){pname=_pname;}
    */

    virtual void printinfo()=0;
    /*
    virtual void printinfo();
    virtual int GetKoreanScore();
    virtual int GetMathScore();
    virtual int GetEnglishScore();
    virtual int get_salary();
    */
};
