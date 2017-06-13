#include "CStudent.h"
#include "CStudentManager.h"

CStudentManager:: CStudentManager()
{
   nCnt=0;
}

int CStudentManager::GetCount()
{
   return nCnt;
}

CStudent CStudentManager::Retrieve(int nIndex)
{
   return pStudent[nIndex - 1];
}

void CStudentManager::Add(CStudent& _pStudent)
{
   pStudent[nCnt]=_pStudent;
   nCnt++;
}

bool CStudentManager::Delete(int nIndex)
{
   if (nIndex<1||nIndex>nCnt)
   {
      return false;
   }

   for (int i=nIndex;i<nCnt;i++)
   {
      pStudent[i-1]=pStudent[i];
   }
   nCnt--;
   return true;
}

bool CStudentManager::Update(int nIndex, CStudent& _pStudent)
{
   if (nIndex<1||nIndex>nCnt)
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

void CStudentManager::printall(){
    auto print_forloop = [](auto ptr, auto nptr){
        for(int i = 0; i<nptr; i++){
            std::cout << std::setw(20) << std::left << "<< i >> " << std::setw(20) << " has value: " << i << "\n";
            ptr[i].printinfo();};
    };

    print_forloop(pStudent, nCnt);
    print_forloop(pWorker, num_workers);
    print_forloop(pWorkingStudent, num_working_students);
    //Printallworkers(){};
    //printallworkingstudents(){};
}
