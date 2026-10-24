
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x, y, u;

    cout << "Enter x and y: ";
    cin >> x >> y;

    // Великий еліпс
    bool ellipse = pow(x - 3, 2) / 4 + pow(y - 1, 2) <= 1;

    // Два верхні кола
    bool circle1 = pow(x - 1.5, 2) + pow(y - 2.6, 2) <= 0.25;
    bool circle2 = pow(x - 4.5, 2) + pow(y - 2.6, 2) <= 0.25;

    // Прямокутники
    bool rect1 = x >= 0 && x <= 1 && y >= 1 && y <= 2;
    bool rect2 = x >= 5 && x <= 6 && y >= 1 && y <= 2;
    bool rect3 = x >= 2 && x <= 4 && y >= -1 && y <= 0;
    bool rect4 = x >= 1 && x <= 2 && y >= -2 && y <= -1;
    bool rect5 = x >= 4 && x <= 5 && y >= -2 && y <= -1;

    bool inside = ellipse || circle1 || circle2 ||
                  rect1 || rect2 || rect3 || rect4 || rect5;

    if (inside) {
        u = sinh(y * y - cos(x));
    } else {
        double angle = sin(y + x) + 10;
        double cosine = cos(angle);

        if (fabs(cosine) < 1e-10) {
            cout << "It is impossible to calculate u." << endl;
            return 0;
        }

        u = tan(angle) - sqrt(pow(cosh(x + 1), 2));
    }

    cout << fixed << setprecision(5);
    cout << (inside ? "YES: " : "NO: ");
    cout << "x = " << x << ", y = " << y;

    if (isfinite(u)) {
        cout << ", u = " << u << endl;
    } else {
        cout << ". It is impossible to calculate u." << endl;
    }

    return 0;
}



