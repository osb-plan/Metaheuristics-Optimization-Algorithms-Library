#include <iostream>




class Mia{

public:
    Mia(int a) : _a(a){};
    int getA(){return _a;}
    int _a;
};

void change(Mia& M )
{
    M._a = 3;

}

int main()
{
    Mia MM(2);
    std::cout << MM.getA();
    change(MM);
    std::cout << MM.getA();
    return 0;
}
