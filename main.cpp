#include <cmath>
#include <iostream>
#include <windows.h>


double powf(double x) noexcept { return std::pow(x, 2); }
double cosf(double x, double y) noexcept { return std::cos(x); }

double i_engine(double(*f)(double x), double(*g)(double x, double y), double a, double b, int n) {
    double step = (b - a)/n; // rectangle width
    double area = 0.0;
    double y = 0; // rectangle height

    for(int i = 0; i < n; i++) {
        y = f(a + (i + 0.5) * step) * g(a + (i + 0.5) * step, y);
        area += y * step;
    }

    return area;
}

void calculate_integral() noexcept {
    double x, low_end, high_end;
    int steps;

    std::cout << "x: ";
    std::cin >> x;

    std::cout << "low end: ";
    std::cin >> low_end;

    std::cout << "high end: ";
    std::cin >> high_end;

    std::cout << "step count: ";
    std::cin >> steps;

    std::cout << "result: " << i_engine(powf, cosf, low_end, high_end, steps);
}

int main() {
    const std::string title = "VEIL TECHNOLOGIES";
    SetConsoleTitleW(reinterpret_cast<LPCWSTR>(title.c_str()));
    std::cout << "integral calculator" << std::endl;
    calculate_integral();

    return EXIT_SUCCESS;
}
