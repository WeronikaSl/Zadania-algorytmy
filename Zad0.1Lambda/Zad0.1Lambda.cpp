#include <iostream>

void hello()
{
    std::cout << "Hello world function" << std::endl;
}
int addNums(int a, int b)
{
    return a + b;
}

int main()
{
    auto helloLambda = []() {std::cout << "Hello world lambda" << std::endl; };
    hello();
    helloLambda();

    auto addNumsLambda = [](int a, int b) -> int { return a + b; };
    std::cout << addNums(5, 6) << std::endl;
    std::cout << addNumsLambda(6,7) << std::endl;

}
