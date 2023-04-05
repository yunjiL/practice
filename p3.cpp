#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >>c;
    if (a >= c && b >= c)
        cout << c << endl;
    else if (a >= b && c >= b)
        cout << b << endl;
    else cout << a << endl;

    return 0;
}