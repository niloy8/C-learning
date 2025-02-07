#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        long long area = a * b;
        bool possible = false;

        for (long long x = 1; x * x <= area; x += 2)
        {
            long long tilearea = x * x;
            long long tilesneeded = area / tilearea;

            if (tilesneeded <= c && area % tilearea == 0)
            {
                possible = true;
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
