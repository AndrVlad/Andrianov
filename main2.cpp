#include <iostream>

using namespace std;

int main() {

    char in;
    double square, a, b, r, h, pi;

while (in != 'X') {

    cout << "Choose figure:\n R - rectangle; \n T - triangle; \n C - circle" << endl;
    cout << "For exit use X \n";
    cin >> in;

    switch (in)
    {
    case 'R':
        {
        cout << "Your figure is Rectangle: S = a * b \n";
        cout << "Input a: \n";
        cin >> a;
        cout << "Input b: \n";
        cin >> b;

        square=a*b;

        cout << "Your result S= " << square << endl;
        break;
        }
    case 'T':
        {
        cout << "Your figure is Triangle: S = 0.5*a*h \n";
        cout << "Input a: \n";
        cin >> a;
        cout << "Input h: \n";
        cin >> h;

        square=(a*h)*0.5;
        cout << "Your result S= " << square << endl;

        break;
        }
    case 'C':
        {
        cout << "Your figure is Circle: S = pi * r^2 \n";
        pi=3.14;
        cout << "Input r: \n";
        cin >> r;

        square=pi*r*r;
        cout << "Your result S= \v" << square << endl;

        break;
        }
    case 'X':
        {
        return 0;
        }
    default:
        cout << "\nInput is incorrect, try again \n";
    }
}

}

