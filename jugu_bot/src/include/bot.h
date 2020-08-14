#include<iostream>
#include<string>
#define max_time_out 5;
using namespace std;

namespace jd{
    void display_menu(){            //display function
        cout<<"welcome to jugu chat bot....version 1.0"<<endl;
        cout<<endl<<endl;
        cout<<" hello!!\t\t('_')"<<endl;
        cout<<endl<<endl;
    }

    void activate() {
        cout<<"say ""hello"" to activate"<<endl;
        string active_command;
        cin>>active_command;
        if(active_command == "hello" && active_command == "hello"){
                cout<<"hello I am jugu version 1.0"<<endl;
        }else{
                cout<<"say \t hello\n"<<endl;
        }
        
    }
}