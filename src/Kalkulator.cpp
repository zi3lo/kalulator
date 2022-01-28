#include "Kalkulator.h"

Kalkulator::Kalkulator()
{
    // ctor - nie używany :)
    // można pokusić się o zadawanie w konstruktorze wrtości początkowej ans
}

void Kalkulator::licz(const std::string &s_input)
{

    s_to_all(s_input);
    err = 0;
    if (arg == 0) rules();
    else
    {
        std::cout << ">>>> ";
        if (ope == "add" && arg > 2) ans_ = add(a,b);
        else if (ope == "sub" && arg > 2) ans_ = sub(a,b);
        else if (ope == "mul" && arg > 2) ans_ = mul(a,b);
        else if (ope == "div" && arg > 2) ans_ = div(a,b);
        else if (ope == "ans" && arg > 1) ans(a);
        else if (ope == "sqrt" && arg > 1) ans_ = sqrt_(a);
        else if (ope == "sin" && arg > 1) ans_ = sin_(a);
        else if (ope == "cos" && arg > 1) ans_ = cos_(a);
        else if (ope == "tan" && arg > 1) ans_ = tan_(a);
        else if (ope == "cot" && arg > 1) ans_ = cot(a);
        else if (ope == "ans" || ope == "000");
        else
        {
            err = 1;
            err_com = "Błąd składni";
        }

        if (!err && ope != "000") // obsługa błędów (np dzielenie przez 0, pierw z ujemnej etc
            print(ans_);
        else if (ope == "000") std::cout << "Papapa!\n";
        else
            print(err_com);

    }
}

void Kalkulator::print(float a)
{
    std::cout << a << std::endl;
}

void Kalkulator::print(const std::string& s)
{
    std::cout << s << std::endl;
}


void Kalkulator::rules()
{
    std::cout << " Składnia:\n\n [add/sub/mul/div] a b\n [sqrt/sin/cos/tan/cot/ans] a\n\n 000 - kończy działanie programu\n\n" << std::endl;
}

void Kalkulator::s_to_all(const std::string& s)
{
    expression = split(s);
    arg = expression.size();
    if (arg > 0)
    {
        ope = expression[0];
        if (arg > 1)
        {
            if (expression[1] == "ans") a = ans_;
            else a = stof(expression[1]);
            if (arg > 2)
            {
                if (expression[2] == "ans") b = ans_;
                else b = stof(expression[2]);
            }
        }
    }
}

void Kalkulator::ans(float a)
{
    ans_ = a;
}

float Kalkulator::add(float a, float b)
{
    return a + b;
}

float Kalkulator::sub(float a, float b)
{
    return a - b;
}

float Kalkulator::mul(float a, float b)
{
    return a * b;
}

float Kalkulator::div(float a, float b)
{
    if (b == 0)
    {
        err = 1;
        err_com = "Błąd dzielenia przez 0!! - ans pozostaje bez zmian"; // - wyj
        return ans_;
    }
    else return a / b;
}

float Kalkulator::sqrt_(float a)
{
    if (a < 0)
    {
        err = 1;
        err_com = "Pierwiastek z liczby ujemnej nie ma rozwiązania w zbiorze liczb rzeczywistych\nans bez zmian"; // - wyj
        return ans_;
    }
    else return sqrt(a);
}

float Kalkulator::sin_(float a)
{
    return sin(a);
}

float Kalkulator::cos_(float a)
{
    return cos(a);
}

float Kalkulator::tan_(float a)
{
    return tan(a);
}

float Kalkulator::cot(float a)
{
    return 1/tan_(a);
}

std::vector<std::string> Kalkulator::split(const std::string& s_input)
{
    std::vector<std::string> parts;
    std::string part;
    std::istringstream input_stream(s_input); // zamieniamy na stream
    while (std::getline(input_stream, part, ' '))
        parts.push_back(part);
    return parts;
}
