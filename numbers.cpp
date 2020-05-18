#include <iostream>
#include <string>
#include <cstdlib>

//Sveikojo skaičiaus konvertavimas iš m-tainės į n-tainę skaičiavimo sistemą

// Nuskaitymas
std::string inputNumber(int &fromBase, int &toBase)
{
    std::string num = " ";
    std::cout << "Input the number you want to convert" << std::endl;
    std::cin >> num;
    std::cout << "Select the base from you want to convert " << std::endl;
    std::cin >> fromBase;
    std::cout << "Select the base you want to convert to " << std::endl;
    std::cin >> toBase;

    return num;
}

// Konvertuoja char simbolius i atitinkamus int skaicius
int charToInt(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        return (int)symbol - '0';
    else
        return (int)symbol - 'A' + 10;
}

// Konvertuoja int skaicius i atitinkamus char simbolius
char intToChar(int const &number)
{
    if (number >= 0 && number <= 9)
        return (char)(number + '0');
    else
        return (char)(number - 10 + 'A');
}

// Apsuka string eilutes simbolius is priekio i gala
std::string reverseString(std::string reNumber)
{
    for (std::string::size_type i = 0; i < reNumber.size() / 2; ++i)
    {
        char temp = reNumber[i];
        reNumber[i] = reNumber[reNumber.size() - i - 1];
        reNumber[reNumber.size() - i - 1] = temp;
    }
    return reNumber;
}

// Konvertuoja irasyta skaiciu(su simboliais) i atitinkama desimtaini skaiciu
int toDecimal(std::string &number, int const &base)
{    
    int result = 0;  
    int power = 1; 

    for (auto i = number.size(); i > 0; i--)
    {
        if (charToInt(number[i - 1]) >= base)
        {
            std::cout << "INVALID NUMBER" << std::endl;

            return EXIT_FAILURE;
        }

        result += power * charToInt(number[i - 1]) ;
        power *= base;
    }

    return result;
}

// Is desimtaines konvertuoja i n-aine skaiciavimo sistema
std::string toAnotherBase(int decimalNum, const int &base)
{
    std::string result = "";

    while (decimalNum > 0)
    {
        result += intToChar(decimalNum % base);
        decimalNum /= base;
    }

    return reverseString(result);
}

int main()
{
    int fromBase = 0, toBase = 0;
    std::string number = inputNumber(fromBase, toBase);
    std::string line(50, '-');
    std::cout << line << std::endl;
    std::cout << "Original number is " << number << ", from base " << fromBase << " to base " << toBase << std::endl;
    std::cout << "RESULT : " << toAnotherBase(toDecimal(number, fromBase), toBase) << std::endl;

    return EXIT_SUCCESS;
}