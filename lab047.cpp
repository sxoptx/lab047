// lab047.cpp
// Дем'ян Аліна
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів
// та рекурентних співвідношень.
// Варіант 7

#include <iostream> 
#include <iomanip> 
#include <cmath> 
using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    double PI = acos(-1.);
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
        << setw(10) << "arcctg" << "   |"
        << setw(7) << "S" << "      |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "-------------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		n = 0;
		a = -x;
		S = PI / 2 + a;
		do {
			n++;
			R = -x * x * (2 * n - 1) / (2 * n + 1);
			a *= R;
			S += a;
		} while (fabs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << exp(x) << "   |"
            << setw(10) << setprecision(5) << S << "   |"
            << setw(5) << n << "   |"
            << endl;
		x += dx;
	}
	cout << "-------------------------------------------------" << endl;

	return 0;
}