

//Virtual Table Analyser 

//For better understanding please refer the Readme file and Digramatic representaion.


using namespace std;

#include<iostream>

class Base
{
    int i,j;

    
    virtual void fun()//1000
    {
        cout<<"Inside Base fun()";
    }

    virtual void gun()//2000
    {
        cout<<"Inside Base gun()";
    }

    void sun()//3000
    {
        cout<<"Inside Base sun()";
    }

};

class Derived:public Base
{

    int x,y;

    void fun()//4000
    {
        cout<<"Inside Derived fun()";
    }

    void sun()//5000
    {
        cout<<"Inside Derived sun()";
    }

    virtual void run()//6000
    {
        cout<<"Inside Derived run()";
    }
};

int main()
{
    Base bobj;//object of base class
    Derived dobj;//object of Derived class


    cout<<"Size of Base class:"<<sizeof(bobj)<<"\n";
    cout<<"Size of Derived class:"<<sizeof(dobj)<<"\n";

    //To get address of derived class object.
    
    long int *BA_D=(long int *)(&dobj);     //100==(*(80))<--
    cout<<"Base address of Derived class object:"<<BA_D<<"\n";

    //By getting address of derived class get data form if by operation(*)=(400),then get data form that data
    //ie.1000 which is the address of virtual function from VTABLE.
   
    long int *VPTR = (long int *)(*BA_D);  //1000==(*(400==(*(110))))<--

    cout<<"Base address of virtual table:"<<VPTR<<"\n";

    void (*fp)();//function pointer

    fp=(void(*)())(*VPTR);//(VPTR[0])
    fp();
    cout<<"\n";

    fp=(void(*)())(*(VPTR+1));//(VPTR[1])
    fp();
    cout<<"\n";

    fp=(void(*)())(*(VPTR+2));//(VPTR[2])
    fp();
    cout<<"\n";


    return 0;    
}
