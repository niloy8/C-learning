#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int frames, pages, page_faults = 0;

    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Enter number of pages: ";
    cin >> pages;

    vector<int> reference_string(pages);
    cout << "Enter reference string: ";
    for (int i = 0; i < pages; i++)
    {
        cin >> reference_string[i];
    }

    vector<int> memory;
    vector<int> freq;
    vector<int> age;

    cout << "The Page Replacement Process is ->\n";

    for (int i = 0; i < pages; i++)
    {
        int page = reference_string[i];
        cout << "For " << page << " : ";

        bool page_found = false;
        for (int j = 0; j < memory.size(); j++)
        {
            if (memory[j] == page)
            {
                page_found = true;
                freq[j]++;
                age[j] = i;
                break;
            }
        }

        if (page_found)
        {
            cout << "No page fault!\n";
        }
        else
        {

            if (memory.size() < frames)
            {

                memory.push_back(page);
                freq.push_back(1);
                age.push_back(i);
            }
            else
            {

                int lfu_index = 0;
                for (int j = 1; j < memory.size(); j++)
                {
                    if (freq[j] < freq[lfu_index] ||
                        (freq[j] == freq[lfu_index] && age[j] < age[lfu_index]))
                    {
                        lfu_index = j;
                    }
                }

                memory[lfu_index] = page;
                freq[lfu_index] = 1;
                age[lfu_index] = i;
            }
            page_faults++;

            for (int k = 0; k < memory.size(); k++)
            {
                cout << memory[k] << " ";
            }
            cout << "\n";
        }
    }

    cout << "Total no of page faults using LFU is: " << page_faults << "\n";

    return 0;
}
