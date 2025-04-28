#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"number of processes: ";
    cin>>n;


    int pid[n],at[n],bt[n],wt[n],tat[n],ct[n],completed[n];
    int current=0,completecount=0;
    float t_wt=0,t_tat=0;

    // input
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        cout<<"arrival time for process"<<pid[i]<<":";
        cin>>at[i];
        cout<<"burst time for process"<<pid[i]<<":";
        cin>>bt[i];
        completed[i]=0;   //mark all process not completed
    }

    // SJF algorithm
    while(completecount<n){
        int minBT=1e9;
        int idx=-1;

        for(int i=0; i<n;i++){
            if(current>=at[i]&&completed[i]==0){
                if(minBT>bt[i]){
                    minBT=bt[i];
                    idx=i;
                }
            }
        }

        if(idx!=-1){
            wt[idx]=current-at[idx];
            if(wt[idx]<0){wt[idx]=0;};

            ct[idx]=current+bt[idx];
            tat[idx]=ct[idx]-at[idx];
            current=ct[idx];
            completed[idx]=1;
            completecount++;

            t_tat+=tat[idx];
            t_wt+=wt[idx];
            
        }
        else{
            current++;
        }


    }
    // output
    cout<<"\nprocess\tarrival\tburst\twaiting\tturnaround";

    for (int i = 0; i < n; i++)
    {
        cout<<"\n"<<pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    }

    cout<<"\naverage waiting time = "<<t_wt/n;
    cout<<"\naverage turnaround time = "<<t_tat/n<<endl;
}
    



