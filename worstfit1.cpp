#include <iostream>
#include <climits> // Include for INT_MIN constant
using namespace std;

int main(int argc, char const *argv[])
{
    int nob, nof;
    cout << "Enter the number of blocks - ";
    cin >> nob;
    int no[nob];
    for (int i = 0; i < nob; i++)
    {
        cout << "Enter the size of block " << i + 1 << " - ";
        cin >> no[i];
    }
    cout << "Enter the number of files - ";
    cin >> nof;
    int fl[nof];
    for (int i = 0; i < nof; i++)
    {
        cout << "Enter the size of file " << i + 1 << " - ";
        cin >> fl[i];
    }
    cout << "File_no\tFile_size\tBlock_no\tBlock_size\tFragment\n";
    bool allocated[nob] = {false};
    for (int i = 0; i < nof; i++)
    {
        int worstfitblock = -1;
        int maxFragmentsize = INT_MIN;
        for (int j = 0; j < nob; j++)
        {
            if (!allocated[j] && no[j] >= fl[i] && no[j] - fl[i] > maxFragmentsize)
            {
                maxFragmentsize = no[j] - fl[i];
                worstfitblock = j;
            }
        }
        if (worstfitblock != -1)
        {
            cout << i + 1 << "\t\t" << fl[i] << "\t\t" << worstfitblock + 1 << "\t\t" << no[worstfitblock] << "\t\t" << maxFragmentsize << endl;
            allocated[worstfitblock] = true;
        }
        else
        {
            cout << i + 1 << "\t\t" << fl[i] << "\t\t"
                 << "0"
                 << "\t\t"
                 << "0"
                 << "\t\t"
                 << "0" << endl;
        }
    }
    return 0;
}