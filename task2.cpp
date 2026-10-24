
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double h, a, b, c, D;

    cout << "Enter h: ";
    cin >> h;

    a = exp(h) + sqrt(1 + h*h*pow(sin(h+2),2)
        + pow(h,4)*pow(sin(h+4),4));

    b = log(a) - sqrt(4 + pow(tan(h),2)
        + pow(log(a),2));

    c = a*h*cosh(b*h) + b*h*sinh(a*h);

    D = b*b - 4*a*c;

    if (!isfinite(a) || !isfinite(b) ||
        !isfinite(c) || !isfinite(D)) {
        cout << "It is impossible to calculate." << endl;
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "D = " << D << endl;

    const double eps = 1e-10;

    if (D < -eps) {
        cout << "No real roots." << endl;
    }
    else if (fabs(D) <= eps) {
        double x = -b / (2*a);
        cout << "One real root: x = " << x << endl;
    }
    else {
        double x1 = (-b + sqrt(D)) / (2*a);
        double x2 = (-b - sqrt(D)) / (2*a);

        cout << "Two real roots:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    return 0;
}
