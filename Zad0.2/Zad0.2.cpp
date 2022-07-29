#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void printVector(const int value)
{
        std::cout << value << std::endl;
}

class PrintLessThan
{
private:
    int _bound;
public:
    PrintLessThan(int bound) : _bound(bound)
    {
    }
    void operator () (int value)
    {
        if (value < _bound)
        {
            std::cout << value << std::endl;
        }
    }
};

bool isBiggerVal(const int value)
{
        if (value > 4)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    
}

int main()
{
    std::vector<unsigned int> vec(100);
    std::iota(vec.begin(), vec.end(), 1); //wypełnia wektor od 1 do 100 (wektor musi być już wypełniony więc robimy zerami)
    //for (size_t i = 0; i < 100; ++i) //wypelnia wektor od 1 do 100
    //{
    //    vec.push_back(i + 1);
    //    //std::cout << vec.at(i) << std::endl; // dla sprawdzenia czy się wypełnia
    //}

//pkt a 
    std::cout << "PktA bez lambdy: " << std::endl;
    for_each(vec.begin(), vec.end(), printVector);

    std::cout << std::endl;

//pkt a z lambdą 
    std::cout << "PktA z lambdą: " << std::endl;
    auto print = [](unsigned int value) {std::cout << value << std::endl; }; //robimy lambdę do for_each, unary function
    for_each(vec.cbegin(), vec.cend(), print); //const begin, const end, używać bo nie zmieniamy 
    
    std::cout << std::endl;

//pkt b
    std::cout << "PktB bez lambdy: " << std::endl;
    for_each(vec.begin(), vec.end(), PrintLessThan(50));

    std::cout << std::endl;

//pkt b z lambdą
    std::cout << "PktB z lambdą: " << std::endl;
    auto PrintLessThanLambda = [](unsigned int value)
    {
        if (value < 50)
        {
            std::cout << value << std::endl;
        }
    };
    for_each(vec.begin(), vec.end(), PrintLessThanLambda);

    std::cout << std::endl;

//pkt c 
    std::cout << "PktC bez lambdy: " << std::endl;
    std::cout << "Ilość liczb większych od 4 (bez lambdy): " << count_if(vec.begin(), vec.end(), isBiggerVal) << std::endl;

    std::cout << std::endl;


//pkt c z lambdą 
    std::cout << "PktC z lambdą: " << std::endl;
    auto isBigger = [](unsigned int value) -> bool
    {
        if (value > 4) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    std::cout << "Ilość liczb większych od 4 (z lambdą): " << count_if(vec.cbegin(), vec.cend(), isBigger) << std::endl; 

    std::cout << std::endl;
//pkt e
    std::cout << "PktE: " << std::endl;
    int divider = 15;
    auto divideByNum = [&divider](unsigned int value)
    {
        if (0 == value % divider)
        {
            std::cout << "Liczba podzielna przez " << divider << ": " << value << std::endl;
 
        }
    };
    for_each(vec.cbegin(), vec.cend(), divideByNum);

    std::cout << std::endl;

//pkt f
    std::cout << "PktF: " << std::endl;

    unsigned int sum = 0;
    auto evenNums = [&sum](unsigned int value) -> bool
    {
        if (0 == (value % 2))
        {
            sum+=value;
            return 1;
        }
        else
        {
            return 0;
        }
    };
    for_each(vec.cbegin(), vec.cend(), evenNums);
    std::cout << sum << std::endl;


}

