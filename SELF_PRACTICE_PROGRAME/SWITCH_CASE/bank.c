
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
class Bank
{
char name[100],add[100],y;
public:
        void open_account();
        void deposite_money();
        void withdraw_money();
        void display_account();
};
void bank::open_account()
{
  cout<<"enter your full name:";
cin.ignore();
  cin.getLine(name,100);
cout<<"Enter your Adress:";
cin.ignore();
  cin.getLine(add,100);
cout<<"what type of account you want to open savi g (s) or current account (c)";
cinn>>y;
cout<<"enter amount for deposite:";
cin>>balance;
cout<<"Your account is created \n";
}
void deposite::deposite_money()
{
int a;
cout<<"enter how much you deposite:";
cin>>a;
balance+a;
cout<<"total amount you deposite:"<<balance;
}
void bank:: display_account()
{
cout<<"your full name: \t"<<nam;
cout<<"Your adress: \t"<<add;
cout<<"type of account that you open: \t"<<y;
cout<<"amount you deposite: \t"<<balance;
}
void bank::withdraw_money()
{
float amount;
cout<<"\n withdraw::";
cout<<"enter amount two withdraw ::";
cin>>amount;
balance=balance-amount;
cout<<"now total amount is left ::"<<balance;
}

int main()
{
int ch,x;
bank obj;
do
{
cout<<"1) open account \n";
cout<<"2) deposite money \n";
cout<<"3) withdraw money \n";
cout<<"4) display account \n";
cout<<"5) Exit";
cout<<"select the option from above \n";
cin>>ch;
switch(ch)
{
         case 1:  <<"1) open account \n";
                  obj.open_account();
                   break;
         case 2:  <<"2) deposite_money \n";
                  obj.deposite_money();
                  break;
         case 3:  <<"3) withdraw_money \n";
                  obj.withdraw_money();
                   break;
case 4:  <<"4) display_account \n";
obj.display_account();
break;
case 5:
if(ch==5)
{
exit(1);
default:
cout<<"this is not exist try again \n";
}
cout<<"\n do you want to select next option then press:: y \n";
cout<<"if you want to exit then press::N";
x=getch();
if(x=="n"||x=="N")
exit(0);
}
while(x=="y"||x=="Y");
getch();
return 0;
}