#pragma once
#include<iomanip>
#include<iostream>

class CStudent
{
protected:
    int nKoreanScore;
    int nEnglishScore;
    int nMathScore;

public:
    CStudent();
    int GetKoreanScore();
    int GetEnglishScore();
    int GetMathScore();
    int GetTotal();

    void SetKoreanScore(int _nKoreanScore);
    void SetEnglishScore(int _nEnglishScore);
    void SetMathScore(int _nMathScore);

    void printinfo(){
        std::cout << std::setw(20) << std::left << "<< nKoreanScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nKoreanScore << std::setw(25) << " and set(get) value of " << nKoreanScore << "\n";
        std::cout << std::setw(20) << std::left << "<< nEnglishScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nEnglishScore << std::setw(25) << " and set(get) value of " << nEnglishScore << "\n";
        std::cout << std::setw(20) << std::left << "<< nMathScore >> " << std::setw(20) << " goes to memory: " << std::setw(20) << &nMathScore << std::setw(25) << " and set(get) value of " << nMathScore << "\n";
    };
};
