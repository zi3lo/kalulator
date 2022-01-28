#pragma once
#include <vector>
#include <iostream>
#include <sstream> // do isstringstream (metoda split)
#include <cmath> // sqrt

class Kalkulator
{
    public:
        Kalkulator();
        void licz(const std::string&);
        void rules();

    private:
        float ans_ = 0,a,b;
        int arg, err = 0;
        std::string ope, err_com;
        std::vector<std::string> expression;
        void print(float);
        void print(const std::string&);
        void s_to_all(const std::string&);
        void ans(float);
        float add(float, float);
        float sub(float, float);
        float mul(float, float);
        float div(float, float);
        float sqrt_(float);
        float sin_(float);
        float cos_(float);
        float tan_(float);
        float cot(float);
        std::vector<std::string> split(const std::string&); // rozdział stringu na części
};

