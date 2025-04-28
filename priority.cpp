#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the number of processes:";
    cin>>n;

    int pid[n],at[n],bt[n],wt[n],tat[n],ct[n],completed[n],remainingtime[n],priority[n];
    int current=0;
    float t_tat=0,t_wt=0;
    int completecount=0;

    // INPUT
    for (int  i = 0; i < n; i++)
    {
        pid[i]=i+1;
        cout<<"arrival time for process"<<pid[i]<<":";
        cin>>at[i];
        cout<<"burst time for process "<<pid[i]<<":";
        cin>>bt[i];
        cout<<"priority for process "<<pid[i]<<":";
        cin>>priority[i];
        remainingtime[i]=bt[i];
        completed[i]=0;
    }

    while(completecount<n){
        int idx=-1;
        int max_priority=1e9;

        for (int i = 0; i < n; i++)
        {
            if(current>=at[i]&& completed[i]==0){
                if (max_priority>priority[i])       
                {
                    max_priority=priority[i];
                    idx=i;
                }
                else if (priority[i]==max_priority)      
                {
                    if (at[idx]>at[i])
                    {
                        idx=i;
                    }
                }
                
                
            }
        }

        if(idx!=-1){
            remainingtime[idx]--;
            current++;
            if (remainingtime[idx]==0)
            {
              
                ct[idx]=current;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                if (wt[idx]<0)
                {
                    wt[idx]=0;
                }
                
                completecount++;
                completed[idx]=1;

                t_tat+=tat[idx];
                t_wt+=wt[idx];
            }
            
        }
        else{current++;}
        
    }
    // OUTPUT
    cout<<"\nprocess\tarrival\tburst\tpriority\twaiting\tturnaround";

    for (int i = 0; i < n; i++)
    {
        cout<<"\n"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<priority[i]<<"\t"<<"\t"<<wt[i]<<"\t"<<tat[i];
    }

    cout<<"\naverage waiting time ="<<t_wt/n;
    cout<<"\naverage turnaround time= "<<t_tat/n<<endl;
    return 0;
        
}
