#include <iostream>


void cin_int(int& input){ // handling invalid user inputs such as 'ARSTAR', '123tas', '!@#$'
    bool bad=false;
    do{
        std::cin >> input;
        bad = std::cin.fail();
        if(bad){
            std::cout << "Invalid input. Please enter valid int." << "\n";
            std::cin.clear();
            std::cin.ignore(255,'\n');
            std::cout << "> ";
        }
    } while (bad);
}

int int_from_cin(){
    int input;
    bool bad=false;
    do{
        std::cin >> input;
        bad = std::cin.fail();
        if(bad){
            std::cout << "Invalid input. Please enter valid int." << "\n";
            std::cin.clear();
            std::cin.ignore(255,'\n');
            std::cout << "> ";
        }
    } while (bad);
    return input;
}
