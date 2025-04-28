#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n];       // Process IDs
    int at[n];        // Arrival Time
    int bt[n];        // Burst Time
    int wt[n];        // Waiting Time
    int tat[n];       // Turnaround Time

    // Input
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter arrival time of process " << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter burst time of process " << pid[i] << ": ";
        cin >> bt[i];
    }

    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for(int i = 1; i < n; i++) {
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
        if(wt[i] < 0) wt[i] = 0;  // No negative waiting time
    }

    // Turnaround time = waiting time + burst time
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Output
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    return 0;
}
