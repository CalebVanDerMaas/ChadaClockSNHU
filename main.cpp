#include <iostream>
using namespace std;

// Time class
class Time
{
public:
    int h1,h2,m1,m2,s1,s2;
    string meridiem;

    // default constructor
    // Two clocks : 12-hour format and
    // 24-hour format
    Time()
    {
        this->h1 = 12;
        this->h2 = 00;
        this->m1 = 00;
        this->m2 = 00;
        this->s1 = 00;
        this->s2 = 00;
        this->meridiem = "AM";
    }

    // checks time limit on each action
    // i.e. second and minute should not exceed 60
    void manageTime(int t=1)
    {
        if(t==1)
        {
            if(s1/60>0)
            {
                s1 %= 60;
                m1++;
            }
            if(m1/60 > 0)
            {
                m1 %= 60;
                h1++;
            }
            if(h1/12>0)
            {
                h1 %= 12;
                if(h1==0)
                    h1=12;
            }
        }
        if(t==2)
        {
            if(s2/60>0)
            {
                s2 %= 60;
                m2++;
            }
            if(m2/60 > 0)
            {
                m2 %= 60;
                h2++;
            }
            if(h2/24>0)
            {
                h1 %= 24;
            }
        }

        if(h2>=12){
            meridiem = "PM";
        }

        if(h2==25){
            h2 = 1;
        }

    }
    // function to add 1 sec
    void addSecond()
    {
        s1++;
        s2++;
        manageTime(1);
        manageTime(2);
    }

    // function to add 1 min
    void addMinute()
    {
        m1++;
        m2++;
        manageTime(1);
        manageTime(2);
    }

    // function to add 1 hour
    void addHour()
    {
        h1++;
        h2++;
        manageTime(1);
        manageTime(2);
    }

    // function to display both times
    void display()
    {
        printf("**************************     **************************");
        printf("\n*     12-Hour Clock      *     *     24-Hour Clock      *");
        printf("\n*       %02d:%02d:%02d ",h1,m1,s1);
        std::cout << meridiem << "";
        printf("      *     *       %02d:%02d:%02d         *\n",h2,m2,s2);
        printf("**************************     **************************\n");
    }
};

int main()
{
    Time t ;
    int p,f=1;

    // Menu as given in flowchart
    while(f>0)
    {
        t.display();
        printf("**************************\n");
        printf("*1 - Add One Hour        *\n");
        printf("*2 - Add One Minute      *\n");
        printf("*3 - Add One Second      *\n");
        printf("*4 - Exit Program        *\n");
        printf("**************************\n");
        cin>>p;
        switch(p){
            case 1: t.addHour(); break;
            case 2: t.addMinute(); break;
            case 3: t.addSecond(); break;
            case 4: f=-1;
        }
    }
}