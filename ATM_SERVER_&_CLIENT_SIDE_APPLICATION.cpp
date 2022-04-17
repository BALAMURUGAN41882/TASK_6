#include <bits/stdc++.h>

using namespace std;
namespace ATM
{
  class server_side;
  class password;
  class client_side;
  class client_analysing;

}

class ATM::server_side
{
 protected:
      vector<string>name;
      vector<long long int>mobile_num;
      vector<long long int>account_num;
      vector<string>address;
      long long int acc_reference = 11223344;
 public:

      void push(string name1,long long int mobile_num1,string address1)
      {
          name.push_back(name1);
          mobile_num.push_back(mobile_num1);
          account_num.push_back(acc_reference++);
          address.push_back(address1);
      }
       void printmethod()
       {
           cout<<endl<<endl;
           int pswd_count=0;
           for(auto k=account_num.begin();k!=account_num.end();k++)
           {

             cout<<++pswd_count<<". Account Number: "<<*k<<endl;
           }
       }
};

class ATM::password:public ATM::server_side
{
     public:
      vector<int>pswd;


      void pswd_allocate(int ps)
      {
            pswd.push_back(ps);
       }
       void printmethod1()
       {
           int pswd_count=0;
          for(auto i=pswd.begin();i<pswd.end();i++)
          {

             cout<<++pswd_count<<". Account Holder Password: "<<*i<<endl;
          }
       }

};


class ATM::client_analysing : public ATM::password
{
    public:
       int Binary_search(long long int target)
       {
           int right = account_num.size() - 1;
           int left = 0;
           while(left <= right)
           {
               int mid = (left+right)/2;
               if(account_num[mid] == target)
                    return mid;
               else if(account_num[mid] < target)
                    left = mid+1;
               else
                    right = mid - 1;
           }
           return -1;
       }
        long  int amount=0;
        void deposit()
        {
            int amnt;
            cout << "Enter amount to be Deposited: ";
            cin >> amnt;
            amount += amnt;
        }

        // Function to show the balance amount
        void showbal()
        {
            cout <<endl<< "Total balance is: " << amount<<endl;
        }

        // Function to withdraw the amount in ATM
        void withdrawl()
        {
            int amnt;
            cout << "Enter amount to withdraw: ";
            cin >> amnt;
            amount -= amnt;
            cout << endl<<"Available Balance is: " << amount<<endl;
        }
};

class ATM::client_side : public ATM::client_analysing
{
  public:
      void call(long long int tar)
      {
          int acc_num =  client_analysing::Binary_search(tar);
          int atm_password;
          if(acc_num != -1)
          {
            int cnt=4;
          while(--cnt)
          {
              cout<< "Enter Your Password: ";
              cin >> atm_password;
           try{
              if(atm_password!=pswd[acc_num])
              {
                throw atm_password;
              }
              else
                {
                    cout<<endl<<"Account Holder Details:"<<endl;
                    cout<<"Account Number : "<<account_num[acc_num]<<endl;
                    cout<<"Account Name   : "<<name[acc_num]<<endl;
                    cout<<"Mobile    : "<<mobile_num[acc_num]<<endl;
                    cout<<"Address   : "<<address[acc_num]<<endl;
                    string Continue;
                    cout<<"----------------------------------------------------------"<<endl;
                    cout<<" Transaction Details "<<endl;
                    cout << "\t1. Deposit Money\n"<<endl;
                    cout << "\t2. Total Balance\n"<<endl;
                    cout << "\t3. Withdraw Money\n"<<endl;
                    cout << "\t4. Cancel Transaction\n"<<endl;
                    int choice;
                    string check;
                    while(1)
                    {
                    cout << "Enter Your Choice"<<endl;
                    cin >> choice;
                     switch (choice)
                     {
                    case 1:
                        client_analysing::deposit();
                        cout<<endl<<"Enter Tilde(~) to continue: ";
                        cin>>check;cout<<endl;
                        if(check=="~"){continue;} else {break;}
                    case 2:
                        client_analysing::showbal();
                        cout<<"Enter Tilde(~) to continue: ";
                        cin>>check;
                        if(check=="~"){continue;} else {break;}
                    case 3:
                        client_analysing::withdrawl();
                        cout<<"Enter Tilde(~) to continue: ";
                        cin>>check;
                        if(check=="~"){continue;} else {break;}

                    case 4:
                        cout<<" Transaction Cancelled "<<endl;
                        exit(1);
                        break;
                    default:
                        cout << "Invalid choice"<<endl;
                        continue;
                        }
                    }
                }
            }
                    catch(int atm_password)
                    {
                        cout<<"Invalid Password"<<endl;
                    }
                    }
                    if(cnt==0)
                    {
                        cout<<"Password Trials over...\n Please Contact Your Branch "<<endl;
                    }
                    }
                    else
                    {
                        std::cout<<"Not Found Account Number..."<<endl;
                    }
                    }
};

using namespace ATM;
int main()
{
      long long int mobile_num;
      srand( time(NULL) );
      string address,name;
      int acc_count;
      client_side obj1;
    cout<<"--- Bank Server Side ---"<<endl;
      while(1)
      {
          cout<<"Account Holder: ";
          cin>>acc_count;
          if(acc_count!=0)
          {
              cout<<"Enter Account Holder Name: ";
              cin>>name;
              cout<<"Enter Account Holder Mobile Number: ";
              cin>>mobile_num;
              cout<<"Account Holder Address: ";
              cin>>address;
              obj1.push(name,mobile_num,address);
              long int pswd=rand()%10000;
              obj1.pswd_allocate(pswd);
              cout<<endl;
          }
          else
            break;
        }
        obj1.printmethod();
        cout<<endl;
        obj1.printmethod1();


        cout<<"---------WELCOME TO ZOHO ATM--------"<<endl;

        long long int account_num1;
        int atm_password;
        cout<<"Enter Account Number : ";
        cin>>account_num1;
        obj1.call(account_num1);
        cout<<"----- Thank You -----";
        return 0;
}

