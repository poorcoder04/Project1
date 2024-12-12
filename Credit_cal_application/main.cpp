#include <iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "windows.h"
using namespace std;

void gotoxy(int x, int y)
{
     COORD coord;
     coord.X=x;
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*class defination*/
class applicant
{
     string name;
     string address;
     int age;
     int m_sal;
     int h_loan;
     int p_loan;
     int no_chq_bounce;
     char own_house;
     char spouse_working;
     char dependant_parents;
     int company_tier;

public:
     void get_data();
     int calc_liability();
     void display_score();
};

void applicant :: get_data()
{
     system("cls");
     cout<<"Name of applicant : ";
     getline(cin,name);

     cout<<"Age : ";
     cin>>age;

     cin.clear();
     cin.ignore(1000, '\n');

     cout<<"Address : ";
     getline(cin,address);

     cout<<"Monthly Salary : ";
     cin>>m_sal;
     cout<<"Total home loan EMI : ";
     cin>>h_loan;
     cout<<"Total personal loan EMI : ";
     cin>>p_loan;
     cout<<"Number of check bounces in last six month : ";
     cin>>no_chq_bounce;
     cout<<"Own house? (y or n) : ";
     cin>>own_house;
     cout<<"Spouse working?(y or n) : ";
     cin>>spouse_working;
     cout<<"Dependent parents?(y or n) : ";
     cin>>dependant_parents;
     cout<<"Company tier?(1 or 2 or 3) : ";
     cin>>company_tier;
}

int applicant :: calc_liability()
{
     int score = 0;
     int liability;
     if(age>22 && age<=30)
          score+=2;
     else if(age>30 && age<=35)
          score+=1;
     else
          score-=1;

     liability=h_loan + p_loan;
     if(liability<=m_sal/4)
          score+=5;
     else if(liability>m_sal/4 && liability<=m_sal/3)
          score+=3;
     else if(liability>m_sal/3 && liability<=m_sal/2)
          score+=1;
     else
          score-=1;

     if(no_chq_bounce>1)
          score-=2;
     else if(no_chq_bounce==1)
          score-=1;
     else
          score+=1;

     if(p_loan>h_loan)
          score-=1;
     else
          score+=1;

     if(own_house=='y')
          score+=1;
     else
          score-=1;

     if(spouse_working=='y')
          score+=1;
     else
          score-=1;

     if(dependant_parents=='y')
          score-=1;
     else
          score+=1;

     if(company_tier==1)
          score+=3;
     if(company_tier==2)
          score+=2;
     else
          score+=1;

     return score;
}

void applicant :: display_score()
{
     int sc=calc_liability();
     system("cls");

     if(sc>9){
          cout<<"The applicant "<<name<<" is at low risk."<<endl;
          cout<<"credit score : "<<sc<<endl;
          cout<<"Credit can be given."<<endl;
     }
     else if(sc>5 && sc<=9){
          cout<<"The applicant "<<name<<" is at average risk."<<endl;
          cout<<"credit score : "<<sc<<endl;
          cout<<"Credit can be given with due precaution."<<endl;
     }
     else{
          cout<<"The applicant "<<name<<" is at high risk."<<endl;
          cout<<"credit score : "<<sc<<endl;
          cout<<"Credit can not be given."<<endl;
     }
     getch();
}

int main()
{
     char flag='f';
     applicant a;
     char ch;
     while(1)
     {
          system("cls");
          gotoxy(31,8);
          cout<<"Credit Calc";
          gotoxy(31,9);
          cout<<"-----------------";
          gotoxy(22,12);
          cout<<"1 - Enter loan applicant's details : ";
          gotoxy(22,13);
          cout<<"2 - Display credit score : ";
          gotoxy(22,14);
          cout<<"3 - Exit ";
          gotoxy(22,16);
          cout<<"Select an option by typing the numeric code: ";
          ch=getch();
          switch(ch)
          {
          case('1'):
               {
                    a.get_data();
                    flag='t';
                    break;
               }

          case('2'):
               {
                    if(flag=='f')
                    {
                         gotoxy(22,18);
                    cout<<"Loan applicant's details not yet entered!Press any button to continue.";
                    getch();
                    }
                    else{
                         a.display_score();
                         break;
                    }
               }
               case('3'):
               {
                    exit(1);
                    break;
               }
               default:
                    {
                         gotoxy(22,18);
                         cout<<"Invalid choice!Press any key to continue.";
                         getch();
                    }
          }
     }
}
