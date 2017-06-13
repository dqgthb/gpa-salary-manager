#include "student.h"

student::student()
{
   nKoreanScore=0;
   nEnglishScore=0;
   nMathScore=0;
}

int student::GetKoreanScore()
{
   return nKoreanScore;
}

int student::GetEnglishScore()
{
   return nEnglishScore;
}

int student::GetMathScore()
{
   return nMathScore;
}

int student::GetTotal()
{
   return nKoreanScore+nEnglishScore+ nMathScore;
}

void student::SetKoreanScore(int _nKoreanScore)
{
   nKoreanScore=_nKoreanScore;
}

void student::SetEnglishScore(int _nEnglishScore)
{
   nEnglishScore=_nEnglishScore;
}

void student::SetMathScore(int _nMathScore)
{
   nMathScore=_nMathScore;
}
