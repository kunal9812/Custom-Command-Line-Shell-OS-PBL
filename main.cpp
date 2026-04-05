#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
using namespace std;

static map <string , string> commands = 
{
    {"help", "./commands/help"}
};

int main(){
    string input;

    // for(auto& x : commands){
    //     cout << x.first<< endl;
    // }


    while(true){
        cout << "Custom_shell> ";
        getline(cin, input);


        auto command = commands.find(input);

        if(command != commands.end()){
            system(command->second.c_str());
        }
        else if("clear" == input || "clr" == input){
            cout<<"\033c";
        }
        else if(0 == input.length()){

        }
        else if("exit" == input){
            exit(0);
        }
        else if("calc" == input){
            char op;
            float a,b;

            cout<<"----CALCULATOR----\n";
            cout<<"Enter the opertor :";
            cin>>op;
            cout<<"Enter first number :";
            cin>>a;
            cout<<"Enter second number :";
            cin>>b;

            switch(op)
            {
                case '+':
                    cout << "Result is :" << a+b<<".\n";
                    break;
                case '-':
                    cout << "Result is :" << a-b<<".\n";
                    break;
                case '*':
                    cout << "Result is :" << a*b<<".\n";
                    break;
                case '/':
                    cout << "Result is :" << a/b<<".\n";
                    break;
                default:
                    cout << "Wrong Operator!\n";
                    break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            cout<<"Wrong Command!\n";
        }

    }
    return 0;
}