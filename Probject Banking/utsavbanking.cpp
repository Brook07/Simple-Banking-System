#include<iostream>
#include<vector>
#include<string>
using namespace std;

class bankaccount{
    private:
    string name;
    string account_number;
    int balance;
    public:
    bankaccount(string n,string A_N,int b){ 
        name=n;
        account_number=A_N;
        balance=b;
    }
    string getname(){
        return name;
    }
    string getaccountnumber(){
        return account_number;
    }
    int getbalance(){
        return balance;
    }
    void deposit(int depositamt){
        balance = balance + depositamt;
        cout<<"Deposited Successfully";
    }
    void  withdraw(int withdrawamt){
         balance = balance - withdrawamt;
         cout<<"\nWithdrawn Successfully";
         }
};
    class bankmanagement{
        private:
        vector<bankaccount> account;
        public:
        void addaccount(string name,string account_number,int balance){
            account.push_back(bankaccount(name,account_number,balance));
        }
        void showallaccounts(){
            cout<<"\n-------Show All Accounts--------";
            for(int i=0; i<account.size();i++){

                cout<<"\nAccount Number : "<<account[i].getaccountnumber();
                cout<<"\nName           : "<<account[i].getname();
                cout<<"\nBalance        : "<<account[i].getbalance();
                cout<<"\n                 ";
            }
        }
        void searchaccount(string accountnumber){
            cout<<"\nAccount no.";
            for(int i=0;i<account.size();i++){
                if(account[i].getaccountnumber()==accountnumber){
                    cout<<"\nAccount Number : "<<account[i].getaccountnumber();
                    cout<<"\nName           : "<<account[i].getname();
                    cout<<"\nBalance        : "<<account[i].getbalance();
                    cout<<"\n                 ";
                }
            }
        }
    bankaccount* findaccount(string accountnumber){
        for(int i=0;i<account.size();i++){
            if(account[i].getaccountnumber() == accountnumber){
                return &account[i];
            }
        }
    }
    };
    int main(){
        bankmanagement bank;
        int choice;
        char op;
        do{
            system("cls");
        cout<<"------- Banking Mangement System ------";
        cout<<"\nMain menu ";
        cout<<"\n1.Create an Account ";
        cout<<"\n2.Display all Accounts ";
        cout<<"\n3.Search Account ";
        cout<<"\n4.Deposit Money";
        cout<<"\n5.Withdraw Money";
        cout<<"\n6.Exit";
        cout<<"\n-----------------------------------------";
        cout<<"\nEnter Your Choice : ";
        cin>>choice;

        switch(choice){
            case 1:{
            string name;
            int balance;
            string account_number; 
            cout<<"\nEnter the name : ";
            cin>>name;
            cout<<"\nEnter the account number : ";
            cin>>account_number;
            cout<<"\nEnter the balance amount : ";
            cin>>balance;
            bank.addaccount(name,account_number,balance);
            cout<<"\nAccount Created Successfully!";
            break;
                }
            case 2:
            {
                bank.showallaccounts();
                break;
            }
            case 3:
            {   string accountnumber;
                cout<<"Enter the account number : ";
                cin>>accountnumber;
                bank.searchaccount(accountnumber);
                break;
            }
            case 4:
            {   string accountnumber;
                cout<<"Enter the account number to Deposit in : ";
                cin>>accountnumber;
                bankaccount* account= bank.findaccount(accountnumber); 
                if (account != 0){
                int depositamt;
                cout<<"Enter the deposit amount : ";
                cin>>depositamt;
                account->deposit(depositamt);
                cout<<"Deposited Successfully";
            }
            else{
                cout<<"Account Not Found";
            }
            break;
        }
        case 5:
        {
            string accountnumber;
            cout<<"Enter the account number to withdraw money from :";
            cin>>accountnumber;
            bankaccount* account = bank.findaccount(accountnumber); 
                if (account != 0){
                int withdrawamt;
                cout<<"Enter the Withdraw amount : ";
                cin>>withdrawamt;
                account->withdraw(withdrawamt);
                cout<<"Withrawn Successfully";
            }
            else{
                cout<<"Account Not Found";
            }
            break;
        }
        default:
        {
            cout<<"Invalid Input";
        }
    }   
            cout<<"\nDo you want to continue or exit [Yes/No] : ";
            cin>>op;
        } while(op == 'y' || op == 'Y');
        return 0;
    }
