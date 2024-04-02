
#include <iostream>
using namespace std;
int main()
{

    cout << "Enter the number of blocks - ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        cout << "Block " << i << " size ";
        cin >> arr[i];
    }

    cout << "Enter the number of process";
    int process;
    cin >> process;
    int arr2[process];
    for (int i = 1; i <= process; i++)
    {
        cout << "Enter the number of process " << i << " - ";
        cin >> arr2[i];
    }
    cout << "OUTPUT\n";
    cout << "ProcessSize\tBlocks\tBlocks size\tAllocated\tInt. frag\n";
    for (int i = 1; i <= process; i++)
    {
        cout << arr2[i] << "\t\t\t" << i << "\t\t\t" << arr[i] << "\t\t\t";
        bool allocated = false;
        for (int j = 1; j <= process; j++)
        {
            if (arr[j] >= arr2[i])
            {
                allocated = true;
                cout << "Yes"
                     << "\t\t\t";
                cout << arr[j] - arr2[i] << endl;
                arr[j] = -1;
                break;
            }
        }
        if (!allocated)
        {
            cout << "No\n";
        }
    }
    return 0;
}
