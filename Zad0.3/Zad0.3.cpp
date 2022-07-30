#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    std::cout << "Pkt a:" << std::endl;
    std::vector<int> vec(201);
    std::iota(vec.begin(), vec.end(), -100);

    //for (auto it = vec.begin(); it != vec.end(); ++it) //sprawdzamy czy wypisuje się wektor
    //{
    //    std::cout << *it << std::endl;
    //}

//a
    auto ifBigger = [](int value) -> bool
    {
        if (value > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    if (std::all_of(vec.begin(), vec.end(), ifBigger))
    {
        std::cout << "Wszystkie liczby są dodatnie" << std::endl;
    }
    else
    {
        std::cout << "Nie wszystkie liczby są dodatnie" << std::endl;
    }
    //if (std::all_of(vec.begin(), vec.end(), [](int value) {return value > 0; })) //drugi sposób
    //{
    //    std::cout << "Wszystkie liczby są dodatnie" << std::endl;
    //}
    //else
    //{
    //    std::cout << "Nie wszystkie liczby są dodatnie" << std::endl;
    //}

//b
    std::cout << std::endl << "Pkt b:" << std::endl;

    auto ifAny = [](int value) -> bool
    {
        if ((0 == value % 3) && (0 == value % 5) && (0 == value % 30))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    if (std::any_of(vec.begin(), vec.end(), ifAny))
    {
        std::cout << "Istnieją liczby podzielne przez 3, 5 i 30" << std::endl;
    }
    else
    {
        std::cout << "Nie istnieją liczby podzielne przez 3, 5 i 30" << std::endl;
    }

    //if (std::any_of(vec.begin(), vec.end(), [](int value) {return((0 == value % 3) && (0 == value % 5) && (0 == value % 30)); }))
    //{
    //    std::cout << "Istnieją liczby podzielne przez 3, 5 i 30" << std::endl;
    //}
    //else
    //{
    //    std::cout << "Nie istnieją liczby podzielne przez 3, 5 i 30" << std::endl;
    //}


//c
    std::cout << std::endl << "Pkt c:" << std::endl;

    auto isZero = [](int value)
    {
        if (0 == value)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    
    vec.erase(std::remove_if(vec.begin(), vec.end(), isZero), vec.end()); //wersja 1 z lambdą wydzieloną do zmiennej, remove_if
    //vec.erase(std::remove(vec.begin(), vec.end(), 0), vec.end()); //wersja 2 z podaną wartością remove
    //vec.erase(std::remove_if(vec.begin(), vec.end(), [](int value) {return 0 == value; }), vec.end()); //wesja 3 z lambdą, remove_if

    for (auto it = vec.begin(); it != vec.end(); ++it) 
    {
        std::cout << *it << std::endl;
    }


//d
    std::cout << std::endl << "Pkt d:" << std::endl;
    //jeśli zwróci ostatni element to "nie ma zera"
    // jeśli zwróci jakikolwiek inny "jest zero"

    auto valIt = find(vec.cbegin(), vec.cend(), 0);
    if (vec.cend() == valIt)
    {
        std::cout << "W tym wektorze nie ma zera" << std::endl;
    }
    else
    {
        std::cout << "W tym wektorze jest zero" << std::endl;

    }

//e
    std::cout << std::endl << "Pkt e:" << std::endl;

    auto ifSorted = std::is_sorted(vec.cbegin(), vec.cend());
    if (ifSorted == true)
    {
        std::cout << "W tym wektorze elementy są posortowane" << std::endl;
    }
    else
    {
        std::cout << "W tym wektorze elementy nie są posortowane" << std::endl;
    }

//f
    std::cout << std::endl << "Pkt f:" << std::endl;

    std::vector<int> newVec;
    auto ifInRange = [](int value)
    {
        return ((value < -90) || (value > 90)); // zwraca prawdę jeśli vartość z wektora jest < -90 lub > 90
    };

    std::copy_if(vec.cbegin(), vec.cend(), std::back_inserter(newVec), ifInRange); //kopiuje wartości dla których lambda zwraca true do nowego wektora

    for (auto it = newVec.begin(); it != newVec.end(); ++it) //sprawdzamy czy nowy wektor się wypełnił
    {
        std::cout << *it << std::endl;
    }

//g
    std::cout << std::endl << "Pkt g:" << std::endl;

    std::vector<int> newVec2;

    auto it = std::find(vec.cbegin(), vec.cend(), 78); //znajduje miejsce elementu o wartości 78

    std::copy(it, (it + 10), std::back_inserter(newVec2)); //wypełnia dziesięcioma wartościami od wartości 78

    for (auto it = newVec2.begin(); it != newVec2.end(); ++it) //sprawdzamy czy nowy wektor się wypełnił
    {
        std::cout << *it << std::endl;
    }

}
