#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int frames, pages, page_faults = 0;

    // Input number of frames
    cout << "Enter number of frames: ";
    cin >> frames;

    // Input number of pages
    cout << "Enter number of pages: ";
    cin >> pages;

    vector<int> reference_string(pages);
    cout << "Enter reference string: ";
    for (int i = 0; i < pages; i++)
    {
        cin >> reference_string[i];
    }

    vector<int> memory;
    vector<int> last_used; // Stores the last used index of the pages

    cout << "The Page Replacement Process is ->\n";

    for (int i = 0; i < pages; i++)
    {
        int page = reference_string[i];
        cout << "For " << page << " : ";

        // Check if the page is already in memory
        bool page_found = false;
        for (int j = 0; j < memory.size(); j++)
        {
            if (memory[j] == page)
            {
                page_found = true;
                last_used[j] = i; // Update the last used index
                break;
            }
        }

        if (page_found)
        {
            cout << "No page fault!\n";
        }
        else
        {
            // Page fault
            if (memory.size() < frames)
            {
                // If there is still space in memory
                memory.push_back(page);
                last_used.push_back(i);
            }
            else
            {
                // Find the least recently used page
                int lru_index = 0;
                for (int j = 1; j < memory.size(); j++)
                {
                    if (last_used[j] < last_used[lru_index])
                    {
                        lru_index = j;
                    }
                }
                // Replace the LRU page with the new page
                memory[lru_index] = page;
                last_used[lru_index] = i;
            }
            page_faults++;

            // Print current memory state
            for (int k = 0; k < memory.size(); k++)
            {
                cout << memory[k] << " ";
            }
            cout << "\n";
        }
    }

    cout << "Total no of page faults using LRU is: " << page_faults << "\n";

    return 0;
}
