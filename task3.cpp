
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c, d, x, y, z;

    cout << "Enter a, b, c, d: ";
    cin >> a >> b >> c >> d;

    double r1 = a*a*(c+1)+d;
    double r2 = 4+exp(d);

    if (r1 < 0 || !isfinite(r1) || !isfinite(r2)) {
        cout << "It is impossible to calculate." << endl;
        return 0;
    }

    x = sqrt(r1);
    y = b-c*sqrt(r2);

    if (x > 0) {
        if (fabs(y) < 1e-12) {
            cout << "Division by zero!" << endl;
            return 0;
        }
        z = x*x-1/y;
    } else {
        z = pow(y,3)-pow(x,4)+1;
    }

    if (!isfinite(x) || !isfinite(y) || !isfinite(z)) {
        cout << "It is impossible to calculate." << endl;
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}

