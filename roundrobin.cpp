#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of processes:";
    cin>>n;
    int quantum;
    cout<<"Enter the quantum:";
    cin>>quantum;
    
    int pid[n],bt[n],at[n],ct[n],wt[n],tat[n],completed[n],remainingbt[n];
    int current=0,completecount=0;
    float t_wt=0,t_tat=0;

    // INPUT
    for (int i = 0; i < n; i++)
    {
        pid[i]=i+1;
        cout<<"Enter arrival time for "<<pid[i]<<":";
        cin>>at[i];
        cout<<"Enter burst time for "<<pid[i]<<":";
        cin>>bt[i];
        remainingbt[i]=bt[i];
    }

    // Round Robin 
    while (completecount<n)
    {
        int executed=0;
        for (int i = 0; i < n; i++)
        {
            if (current>=at[i]&& remainingbt[i]>0)
            {   
                executed++;
                if (remainingbt[i]>quantum)
                {
                   current+=quantum;
                   remainingbt[i]-=quantum;
                }
                else{
                    current+=remainingbt[i];
                    ct[i]=current;
                    remainingbt[i]=0;
                    completecount++;
                    
                }
            }
            
        }
        if (executed==0)
        {
            current++;
        }

    }
    // calculate
    for (int i = 0; i < n; i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        t_tat+=tat[i];
        t_wt+=wt[i];
    }
    
    // output
    cout<<"\nprocess\tarrival\tburst\twaiting\tturnaround";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    }
    
    cout<<"\nAverage waiting time = "<<t_wt/n;
    cout<<"\nAverage turnaround time = "<<t_tat/n<<endl;
    
    return 0;
}
