#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Structure to represent a job
struct Job
{
    int id;       // Job ID
    int deadline; // Deadline
    int profit;   // P rofit
};

// sort() internally calls comparison() multiple times to decide the order of elements to sort jobs by profit in descending order
bool comparison(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobScheduling(Job arr[], int n)
{
    // Sort jobs in descending order of profit
    sort(arr, arr + n, comparison);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    // Create a time slot array initialized with -1 (unoccupied) Creates an array to track time slots for scheduled jobs.
    vector<int> schedule(maxDeadline + 1, -1);
    

    int totalProfit = 0, jobsScheduled = 0;

    // Iterate over sorted jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot from the job's deadline (backwards)
        for (int j = arr[i].deadline; j > 0; j--)
        {
            cout<<j;
            if (schedule[j] == -1)
            {                            // If slot is available
                schedule[j] = arr[i].id; // Assign job
                totalProfit += arr[i].profit;
                jobsScheduled++;
                
                break; // Stop after assigning one job
            }
        }
    }

    // Print scheduled jobs
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++)
    {
        if (schedule[i] != -1)
        {
            cout << "J" << schedule[i] << " ";
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main()
{
    Job arr[] = {{1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 80}};
    int n = sizeof(arr) / sizeof(arr[0]);

    jobScheduling(arr, n); // arr-array of jobs

    return 0;
}