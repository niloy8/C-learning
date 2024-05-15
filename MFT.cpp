#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cout << "Enter the total memory avaiablle in bytes - ";
    int n, blocksize, processes;
    cin >> n;
    cout << "Enter the block size - ";
    cin >> blocksize;
    cout << "Enter the number of processes - ";
    cin >> processes;
    int processarray[processes];
    for (int i = 0; i < processes; i++)
    {
        cout << "Enter memory required for process " << i + 1 << " - ";
        cin >> processarray[i];
    }
    cout << "No of blocks avaiable in memory - ";
    int blocks;
    cin >> blocks;
    int ef = n - blocksize * blocks;
    cout << "Process\tMemory Required\tAllocated\tInternal Fragment\n";
    int i, p = 0, itf = 0;
    for (i = 0; i < processes && p < blocks; i++)
    {
        cout << i + 1 << "\t\t" << processarray[i] << "\t\t";
        if (processarray[i] > blocksize)
        {
            cout << "NO\t\t--\n";
        }
        else
        {
            cout << "\t\tYES\t\t" << blocksize - processarray[i] << "\n";
            itf = itf + blocksize - processarray[i];
            p++;
        }
    }
    if (i < processes)
    {
        cout << "\nMemory is full remanaing processes cannot be accomodated.\n";
    }
    cout << ef << "\n";
    cout << itf << "\n";
    return 0;
}
