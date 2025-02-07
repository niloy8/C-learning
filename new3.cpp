#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    int burst_time[n], priority[n], waiting_time[n], turnaround_time[n], process[n];

    for (int i = 0; i < n; i++)
    {
        process[i] = i;
        cout << "Enter Burst Time for Process P" << i << ": ";
        cin >> burst_time[i];
        cout << "Enter Priority for Process P" << i << ": ";
        cin >> priority[i];
    }

    // Sort processes based on priority
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                // Swap priority
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap burst time
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap process ID
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate total waiting time and total turnaround time
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    double average_waiting_time = (double)total_waiting_time / n;
    double average_turnaround_time = (double)total_turnaround_time / n;

    // Print results
    cout << "PROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << process[i] << "\t" << priority[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << "\n";
    }

    cout << "Average Waiting Time --> " << average_waiting_time << "\n";
    cout << "Average Turnaround Time --> " << average_turnaround_time << "\n";

    return 0;
}
