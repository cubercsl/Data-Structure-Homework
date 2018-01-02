#include "Polynomial.h"
using namespace std;

int main()
{
    PolyItem a[] = {PolyItem(4, 6), PolyItem(2, 4), PolyItem(1, 2)};
    Polynomial la(a, 3);
    la.Display();
    cout << endl;
    la.Derivative();
    la.Display();
    cout << endl;
}