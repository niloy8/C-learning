#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter the number of blocks - ";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Block size " << i + 1 << " - ";
        cin >> arr[i];
    }
    cout << "Enter the number of processes - ";
    int m;
    cin >> m;
    int p[m];
    bool allocated[m] = {false};

    for (int i = 0; i < m; i++)
    {
        cout << "Enter memory required for process " << i + 1 << " - ";
        cin >> p[i];
    }
    cout << "Process\tMemory Required\tBlock Size\tAllocated\tInternal Fragment\n";
    for (int i = 0; i < m; i++)
    {
        cout << i + 1 << "\t\t" << p[i] << "\t\t";
        bool allocatedFlag = false;
        for (int j = 0; j < n; j++)
        {
            if (p[i] <= arr[j] && allocated[j] == false)
            {
                cout << arr[j] << "\t\tYes\t\t" << arr[j] - p[i] << "\n";
                allocated[j] = true;
                allocatedFlag = true;
                break;
            }
        }
        if (!allocatedFlag)
            cout << arr[i] << "\t\tNo\t\t--\n";
    }
    return 0;
}
