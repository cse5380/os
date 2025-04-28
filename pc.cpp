#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter size of buffer= ";
    cin>>n;

    int buffer[n];
    int choice,item;
    int count=0;

    while (true)
    {
        cout<<"\n1.produce\n2.consumer\n3.exit\n";
        cout<<"Enter you choice:";
        cin>>choice;

        switch(choice){
            case 1:if(count==n){
                cout<<"no space is availble in buffer!!";
            }
            else{
                cout<<"enter item to produce in buffer:";
                cin>>item;
                buffer[count]=item;
                count++;
                cout<<"Item produced in buffer:"<<item<<endl;
            }
            break;
            case 2: if(count==0){
                cout<<"no item is available in buffer!!";
            }
            else{
                item=buffer[0];

                for (int  i = 0; i < count; i++)
                {
                    buffer[i]=buffer[i+1];
                }
                count--;
                cout<<"the item consumed from buffer:"<<item;
            }
            break;
            case 3: 
            cout<<"exit the buffer";
            return 0;
            
            default:
            cout<<"invalid choice";
        }

    }
    
}
