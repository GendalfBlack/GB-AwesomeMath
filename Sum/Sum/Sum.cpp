#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Додавання в стовпчик ще ніколи не було таким простим!\n";
    cout << "Введіть перше число:";
    char a[100];
    fflush(stdin);
    gets_s(a);
    cout << "Введіть друге число:";
    char b[100];
    fflush(stdin);
    gets_s(b);
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    int na = strchr(&a[0], '\0') - &a[0] - 1;
    int nb = strchr(&b[0], '\0') - &b[0] - 1;

    int n = na > nb ? na : nb;
    int c = 0, d = 0;

    for (int i = 0; i <= n; i++)
    {
        int ai = na - i >= 0 ? a[na - i] - 48 : 0;
        int bi = nb - i >= 0 ? b[nb - i] - 48 : 0;

        if (ai + bi + d > 9)
        {
            c += ((ai + bi + d) % 10) * pow(10, i);
            d = (ai + bi + d) / 10;
        }
        else {
            c += (ai + bi + d) * pow(10, i);
            d = 0;
        }
    }
    c += d * pow(10, n + 1);
    char c2[100];
    _itoa_s(c, c2, 10);
    int nc = strchr(&c2[0], '\0') - &c2[0] - 1;
    if (na >= nb)
    {
        cout << " ";
        for (int i = 0; i < nc - na; i++) { cout << "  "; }
        for (int i = 0; i <= n; i++) { cout << a[i] << " "; }
        cout << endl;
        cout << "+";
        for (int i = 0; i < nc - na; i++) { cout << "  "; }
        for (int i = 0; i < na - nb; i++) { cout << "  "; }
        for (int i = 0; i <= nb; i++) { cout << b[i] << " "; }
    }
    else {
        cout << " ";
        for (int i = 0; i < nc - nb; i++) { cout << "  "; }
        for (int i = 0; i <= n; i++) { cout << b[i] << " "; }
        cout << endl;
        cout << "+";
        for (int i = 0; i < nc - nb; i++) { cout << "  "; }
        for (int i = 0; i < nb - na; i++) { cout << "  "; }
        for (int i = 0; i <= na; i++) { cout << a[i] << " "; }
    }
    cout << endl;
    for (int i = 0; i <= nc; i++) { cout << char(196) << char(196); }
    cout << endl;
    cout << " ";
    for (int i = 0; i <= nc; i++) { cout << c2[i] << " "; }
    cout << endl;
}