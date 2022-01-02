#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tools.cpp"



class Schueler {
public: 
    int nummer;
    int name;
};

int main()
{
    CCalculator calc;
    Schueler senpaiii;
    senpaiii.nummer = 69420;
    std::string lel = std::to_string(calc.getPi(1000000));

    std::cout << lel;
    return 0;
}

