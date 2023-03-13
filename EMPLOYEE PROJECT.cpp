#include <iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

void register_new();
void show_registered();
void search_by_ID(int);
void delete_record(int);
void update_record(int);
void exit();

struct employee
{
 string fname,lname,position;
 int age,ID;
 char gender;
 float salary;

}employee_info[100];

int option,num,option2;
int specific_ID;

int main()
{
    char welcome[]="\n\t\tWELCOME TO EMPLOYEE MANAGEMENT SYSTEM (DONE BY ADDIS ABABA UNIVERSITY STUDENT AS A SEMESTER PROJECT!!!)\n\n\n";
    for (int i=0;i<strlen(welcome);i++)
    {
    cout<<welcome[i];
    Sleep(30);
    }

    cout<<"\t\tPRESS 1 TO REGISTER NEW EMPLOYEE\n\n";
    Sleep(300);
    cout<<"\t\tPRESS 2 TO SEE ALL REGISTERED EMPLOYEES\n\n";
    Sleep(300);
    cout<<"\t\tPRESS 3 TO SEARCH AN EMPLOYEE BY ID\n\n";
    Sleep(300);
    cout<<"\t\tPRESS 4 TO DELETE EMPLOYEE RECORD\n\n";
    Sleep(300);
    cout<<"\t\tPRESS 5 TO UPDATE AN EMPLOYEE DATA\n\n";
    Sleep(300);
    cout<<"PRESS 0 TO EXIT\n";

    cin>>option;


    if(option==1){
        register_new();
        cout<<"\n\nPRESS 6 TO CONTINUE\n\nPRESS 0 TO EXIT"<<endl;
        cin>>option2;
        if(option2==6){
            main();
        }
        else if(option2==0){
            exit();
        }
    }

   else if(option==2)
   {

    show_registered();

    cout<<"\n\nPRESS 6 TO CONTINUE\n\nPRESS 0 TO EXIT"<<endl;
        cin>>option2;
        if(option2==6){
            main();
        }
        else if(option2==0){
            exit();
        }
    }

    else if(option==3)
    {
        cout<<"Enter the ID of the student to be searched: ";
        cin>>specific_ID;
        search_by_ID(specific_ID);
        cout<<"\n\nPress 6 to continue\n\nPress 0 to exit"<<endl;
        cin>>option2;
        if(option2==6)
        {
            main();
        }
        else if(option2==0)
        {
            exit();
        }
    }
      else if(option==4)
      {
          cout<<"Enter the ID of the student whose record to be deleted: ";
          cin>>specific_ID;
          delete_record(specific_ID);

          cout<<"\n\nPress 6 to continue\n\nPress 0 to exit"<<endl;
          cin>>option2;
          if(option2==6)
          {
              main();
          }
          else if(option2==0)
          {
              exit();
          }
      }
     else if(option=5)
     {
        cout<<"Enter the ID of the student whose record to be updated: ";
        cin>>specific_ID;
        update_record(specific_ID);
        cout<<"\n\npress 6 to continue\n\npress 0 to exit"<<endl;
        if(option2==6)
        {
            main();
        }
        else if(option2==0)
        {
            exit();
        }
     }
     else if(option==0)
     {
         exit();
     }
    return 0;
   }
void register_new()
{
    cout<<"enter the number of employees to be registered";
    cin>>num;
    ofstream out;
    out.open("employee record.text",ios::out);
    for(int i=0;i<num;i++)
    {
    cout<<"\nRecords of employee number"<<i+1<<endl;
    cout<<"enter the first name of employee"<<endl;
    cin>>employee_info[i].fname;
    cout<<"enter the last name of employee"<<endl;
    cin>>employee_info[i].lname;
    cout<<"enter the age of employee"<<endl;
    cin>>employee_info[i].age;
    cout<<"enter the ID of employee"<<endl;
    cin>>employee_info[i].ID;
    cout<<"enter the gender of employee"<<endl;
    cin>>employee_info[i].gender;
    cout<<"enter the salary of employee"<<endl;
    cin>>employee_info[i].salary;

    out<<endl<<"first name :"<<employee_info[i].fname<<endl;
    out<<"last name :"<<employee_info[i].lname<<endl;
    out<<"age :"<<employee_info[i].age<<endl;
    out<<"ID :"<<employee_info[i].ID<<endl;
    out<<"gender :"<<employee_info[i].gender<<endl;
    out<<"salary :"<<employee_info[i].salary<<endl;

    }
out.close();

}
void show_registered()
{
char next;
cout<<"\n\tAll of the records you have entered are as follows"<<endl;
ifstream in;
in.open("employee record.text",ios::in);

while(!in.eof())
{
    in.get(next);
    cout<<next;
}
in.close();
}

void search_by_ID(int x)
{
    ifstream in;
    in.open("employee record.text",ios::in);
    cout<<"Enter the total number of students registered: ";
    cin>>num;
    while(!in.eof())
    {
     for(int i=0;i<num;i++)
     {
      if(employee_info[i].ID==x)
      {
    cout<<endl<<"first name :"<<employee_info[i].fname<<endl;
    cout<<"last name :"<<employee_info[i].lname<<endl;
    cout<<"age :"<<employee_info[i].age<<endl;
    cout<<"ID :"<<employee_info[i].ID<<endl;
    cout<<"gender :"<<employee_info[i].gender<<endl;
    cout<<"salary :"<<employee_info[i].salary<<endl;


      }
     }
    }
in.close();
}
   void delete_record(int n)
   {
   cout<<"Enter the total number of students registered: ";
   cin>>num;
   ifstream in;
   in.open("employee record.text",ios::in);
   ofstream out;
   out.open("temp.text",ios::app);
   for(int i=0;i<num;i++)
   {
    if(employee_info[i].ID!=n)
    {
        out<<endl<<employee_info[i].fname<<endl;
        out<<employee_info[i].lname<<endl;
        out<<employee_info[i].age<<endl;
        out<<employee_info[i].ID<<endl;
        out<<employee_info[i].gender<<endl;
        out<<employee_info[i].salary<<endl;
    }
   }
   in.close();
   out.close();
   remove("employee record.text");
   rename("temp.text","employee record.text");
   cout<<"The record was deleted successfully!";
   }

   void update_record(int x)
   {
   ifstream in;
   in.open("employee record.text",ios::in);
   ofstream out;
   out.open("employee record.text",ios::app);
   cout<<"Enter the total number of students registered: ";
   cin>>num;
   for(int i=0;i<num;i++)
   {
       if(employee_info[i].ID=x)
       {
           cout<<endl<<"first name :"<<employee_info[i].fname<<endl;
           cout<<"last name :"<<employee_info[i].lname<<endl;
           cout<<"age :"<<employee_info[i].age<<endl;
           cout<<"ID :"<<employee_info[i].ID<<endl;
           cout<<"gender:"<<employee_info[i].gender<<endl;
           cout<<"salary:"<<employee_info[i].salary<<endl;


           cout<<"\n\tthe records of an employee"<<i+1<<endl;
           cout<<"enter first name of an employee"<<endl;
           cin>>employee_info[i].fname;
           cout<<"enter last name of an employee"<<endl;
           cin>>employee_info[i].lname;
           cout<<"enter age of an employee"<<endl;
           cin>>employee_info[i].age;
           cout<<"enter ID of an employee"<<endl;
           cin>>employee_info[i].ID;
           cout<<"enter gender of an employee"<<endl;
           cin>>employee_info[i].gender;
           cout<<"enter salary of an employee"<<endl;
           cin>>employee_info[i].salary;

           out<<endl<<employee_info[i].fname<<endl;
           out<<employee_info[i].lname<<endl;
           out<<employee_info[i].age<<endl;
           out<<employee_info[i].ID<<endl;
           out<<employee_info[i].gender<<endl;
           out<<employee_info[i].salary<<endl;
       }
   }
in.close();
out.close();

   }

void exit(){
cout<<"\n\nGOOD BYE"<<endl;
}
