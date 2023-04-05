#include <iostream>
using namespace std;

int n;
int a[100001];
int ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (a[i+1]>a[i+2])
        {
            int two = min(a[i], a[i+1]-a[i+2]);
            ans += 5 * two;
            a[i] -= two;
            a[i+1] -= two;

            int three = min(a[i], min(a[i+1], a[i+2]));
            ans += 7 * three;
            a[i] -= three;
            a[i+1] -= three;
            a[i+2] -= three;
        }
        else
        {
            int three = min(a[i], min(a[i+1], a[i+2]));
            ans += 7 * three;
            a[i] -= three;
            a[i+1] -= three;
            a[i+2] -= three;

            int two = min(a[i], a[i+1]);
            ans += 5 * two;
            a[i] -= two;
            a[i+1] -= two;
        }
        ans += 3 * a[i];
    }

    cout << ans << endl;
    return 0;
}