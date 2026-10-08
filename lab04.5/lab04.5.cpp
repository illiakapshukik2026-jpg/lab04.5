#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x, y, R;

    cout << "R = "; cin >> R;

    // Спосіб 1: Введення координат з клавіатури
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        // Умова влучення в заштриховану область:
        // 1) Верхнє півколо у I чверті з центром у (R, 0) та радіусом R (y >= 0)
        // 2) Куток у III чверті поза колом з центром у (-R, -R) та радіусом R (x <= 0, y <= 0, x >= -R, y >= -R)
        if ((y >= 0 && (x - R) * (x - R) + y * y <= R * R) ||
            (x <= 0 && x >= -R && y <= 0 && y >= -R && (x + R) * (x + R) + (y + R) * (y + R) >= R * R))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    // Спосіб 2: Генерація випадкових точок на інтервалі [-2R; 2R]
    srand((unsigned)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        // Генерація чисел у діапазоні [-2R; 2R]
        x = 4.0 * R * rand() / RAND_MAX - 2.0 * R;
        y = 4.0 * R * rand() / RAND_MAX - 2.0 * R;

        if ((y >= 0 && (x - R) * (x - R) + y * y <= R * R) ||
            (x <= 0 && x >= -R && y <= 0 && y >= -R && (x + R) * (x + R) + (y + R) * (y + R) >= R * R))
            cout << setw(8) << setprecision(4) << x << "  "
            << setw(8) << setprecision(4) << y << "  " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << "  "
            << setw(8) << setprecision(4) << y << "  " << "no" << endl;
    }

    return 0;
}
