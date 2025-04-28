#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the processes : ";
    cin >> n;

    int pid[n], at[n], bt[n], wt[n], tat[n], ct[n], remainingtime[n];
    int shortest, minremaining;
    float t_wt = 0, t_tat = 0;
    int current = 0, completed = 0;


    // INPUT
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        cout << "enter arrival time for" << pid[i] << ":";
        cin >> at[i];
        cout << "enter burst time for" << pid[i] << ":";
        cin >> bt[i];
        remainingtime[i] = bt[i];
    }

    // SRTF

    while (completed != n)
    {
        minremaining = 1e9; // large number
        shortest = -1;
        

        for (int i = 0; i < n; i++)
        {
            if (current >= at[i] && remainingtime[i] > 0 && remainingtime[i] < minremaining)
            {
                minremaining = remainingtime[i];
                shortest = i;
                
            }
        }

        if (shortest==-1)
        {
            current++;
            continue;
        }
        // EXECUTE FOR 1 UNIT
        remainingtime[shortest]--;

        // PROCESS FINISHES
        if (remainingtime[shortest] == 0)
        {
            completed++;
            ct[shortest] = current + 1;
            wt[shortest] = current - at[shortest];
            if (wt[shortest] < 0)
            {
                wt[shortest] = 0;
            }
            tat[shortest] = ct[shortest] - at[shortest];

            t_tat += tat[shortest];
            t_wt += wt[shortest];
        }
        current++;
    }
    // OUTPUT
    cout << "\nprocess\tarrival\tburst\twaiting\tturnaround";

    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
    }
    cout << "\naverage waiting time = " << t_wt / n;
    cout << "\naverage turnaround time= " << t_tat / n<<endl;
}
