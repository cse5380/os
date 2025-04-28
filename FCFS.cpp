#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n];    // Process IDs
    int bt[n];     // Burst Time (how long each process needs)
    int wt[n];     // Waiting Time
    int tat[n];    // Turnaround Time

    // Input burst times
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter burst time of process " << pid[i] << ": ";
        cin >> bt[i];
    }

    // First process waits 0
    wt[0] = 0;

    // Calculate waiting time for rest
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time = waiting time + burst time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output the result
    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    return 0;
}
