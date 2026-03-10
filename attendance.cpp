#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class attend
{
    float p=0,t=0;

public:
    int enter();
    void calculate();
    void report();   // NEW FEATURE
};

int attend::enter()
{
    int date,month,year;
    int i,n,k,a,c;
    int z[20];

    cout<<">>ENTER 1 TO GIVE THE DATE: ";
    cin>>i;

    while(i)
    {
        cout<<"\nEnter DATE MONTH YEAR: ";
        cin>>date>>month>>year;

        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            c = (date<=31 && date>0);
        else if(month==4||month==6||month==9||month==11)
            c = (date<=30 && date>0);
        else if(month==2)
            c = (date<=29 && date>0);
        else
            c = 0;

        if(month==0 || year==0)
            c=0;

        switch(c)
        {
            case 0:
                cout<<"Invalid Date! Try again.\n";
                break;

            case 1:
                cout<<"\nEnter number of periods in the day (max 7): ";
                cin>>n;

                for(k=1;k<=n;k++)
                {
                    cout<<"Enter 1 if PRESENT else 0 for period "<<k<<": ";
                    cin>>a;

                    if(a==1)
                    {
                        p++;
                        t++;
                        z[k]=1;
                        cout<<"Updated as PRESENT\n";
                    }
                    else
                    {
                        t++;
                        z[k]=0;
                        cout<<"Updated as ABSENT\n";
                    }
                }

                cout<<"\nAttendance Updated for "<<date<<"/"<<month<<"/"<<year<<"\n";
                break;
        }

        cout<<"\nEnter 1 to update another day else 0: ";
        cin>>i;
    }

    return 0;
}

void attend::calculate()
{
    if(t==0)
    {
        cout<<"\nNo attendance record available.\n";
        return;
    }

    float percent=(p*100)/t;

    cout<<"\nYour Attendance Percentage: "<<percent<<"%\n";

    if(percent<75)
        cout<<"Warning: Attendance below required 75%.\n";
    else
        cout<<"Good! Your attendance is sufficient.\n";
}

void attend::report()
{
    cout<<"\n========== ATTENDANCE REPORT ==========\n";

    cout<<"Total Classes Conducted : "<<t<<endl;
    cout<<"Classes Attended        : "<<p<<endl;
    cout<<"Classes Missed          : "<<t-p<<endl;

    if(t>0)
    {
        float percent=(p*100)/t;
        cout<<"Attendance Percentage   : "<<percent<<"%\n";
    }

    cout<<"=======================================\n";
}

int main()
{
    attend o1,o2,o3;
    int a,w;

    ifstream file1;
    ofstream file2;

    cout<<"\nSTUDENT ATTENDANCE MANAGEMENT SYSTEM\n";
    cout<<"------------------------------------\n";

    cout<<"\nEnter 1 to continue: ";
    cin>>a;

    while(a)
    {
        cout<<"\n=========== MENU ===========\n";
        cout<<"1. View Attendance Percentage\n";
        cout<<"2. Update Attendance\n";
        cout<<"3. View Attendance Report\n";
        cout<<"4. Exit\n";
        cout<<"=============================\n";

        cin>>w;

        switch(w)
        {
            case 1:
                file1.open("attendance1.txt");
                file1.read((char*)&o1,sizeof(o1));
                o1.calculate();
                file1.close();
                break;

            case 2:
                file1.open("attendance1.txt");
                file1.read((char*)&o2,sizeof(o2));
                file1.close();

                o2.enter();

                file2.open("attendance1.txt");
                file2.write((char*)&o2,sizeof(o2));
                file2.close();
                break;

            case 3:
                file1.open("attendance1.txt");
                file1.read((char*)&o3,sizeof(o3));
                o3.report();
                file1.close();
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid option!\n";
        }

        cout<<"\nEnter 1 to continue else 0: ";
        cin>>a;
    }

    return 0;
}