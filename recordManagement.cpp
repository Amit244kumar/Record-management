#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class Record
{
    private:
        string name;
        int id,age;
        string  stream;
    protected:
        int getLastId()
        {
            int id=0;
            ifstream fin;
            //add your system path where you want to create file
            fin.open("D:/my documents/program in c,c++ and ds/projects/key.txt");
            while(!fin.eof())
            {
                fin>>id;
            }
            fin.close();
            return id;
        }
        void print(Record r)
        {
            cout<<"######################################"<<endl;
            cout<<"id     : "<<r.id<<endl;
            cout<<"name   : "<<r.name<<endl;
            cout<<"age    : "<<r.age<<endl;
            cout<<"stream : "<<r.stream<<endl;
            cout<<"######################################"<<endl;
        }
    public:
    void addStudentRecord();
    void deleteStudentRecord(int);
    void searchStudentRecord(int);
    void updateStudentRecord(int);
    void printAllRecord();
};

void Record::printAllRecord()
{
    ifstream fin;
    Record s;
    //add your system path where you want to create file
    fin.open("D:/my documents/program in c,c++ and ds/projects/record.txt");
    fin>>id;
    while(!fin.eof())
    {
        fin>>name;
        fin>>age;
        fin>>stream;
        s.id=id;
        s.name=name;
        s.age=age;
        s.stream=stream;
        print(s);
        fin>>id;
    }
    fin.close();
}
void Record::updateStudentRecord(int i)
{
    ofstream fout;
    ifstream fin;
    //add your system path where you want to create file
    fout.open("D:/my documents/program in c,c++ and ds/projects/temp.txt",ios::app);
    fin.open("D:/my documents/program in c,c++ and ds/projects/record.txt");
    fin>>id;
    Record s;
    cout<<"enter name : ";
    cin>>s.name;
    cout<<"Enter age : ";
    cin>>s.age;
    cin.ignore();
    cout<<"Enter stream : ";
    cin>>s.stream;

    while(!fin.eof())
    {
         fin>>name;
         fin>>age;
         fin>>stream;
         if(id==i)
         {
             fout<<i<<endl;
             fout<<s.name<<endl;
             fout<<s.age<<endl;
             fout<<s.stream<<endl;
         }
         else{
             fout<<id<<endl;
             fout<<name<<endl;
             fout<<age<<endl;
             fout<<stream<<endl;
         }
         fin>>id;
    }
    fout.close();
    fin.close();
    //add your system path where you want to create file
    remove("D:/my documents/program in c,c++ and ds/projects/record.txt");
    rename("D:/my documents/program in c,c++ and ds/projects/temp.txt","D:/my documents/program in c,c++ and ds/projects/record.txt");
    cout<<"Record updated successfully";

}
void Record::searchStudentRecord(int i)
{

    ifstream fin;
    Record s;
    //add your system path where you want to create file
    fin.open("D:/my documents/program in c,c++ and ds/projects/record.txt");
    fin>>id;
    while(!fin.eof())
    {
        fin>>name;
        fin>>age;
        fin>>stream;
        if(id==i)
        {
            s.id=id;
            s.name=name;
            s.age=age;
            s.stream=stream;
        }
        fin>>id;
    }
    fin.close();
    print(s);
}

void Record::deleteStudentRecord(int i)
{

    ofstream fout;
    ifstream fin;
    fout.open("D:/my documents/program in c,c++ and ds/projects/temp.txt",ios::out);
    fin.open("D:/my documents/program in c,c++ and ds/projects/record.txt");
    fin>>id;

    while(!fin.eof())
    {
         fin>>name;
         fin>>age;
         fin>>stream;
         if(id!=i)
         {
             fout<<id<<endl;;
             fout<<name<<endl;
             fout<<age<<endl;
             fout<<stream<<endl;
         }
         fin>>id;

    }
    fout.close();
    fin.close();
    //add your system path where you want to create file
    remove("D:/my documents/program in c,c++ and ds/projects/record.txt");
    rename("D:/my documents/program in c,c++ and ds/projects/temp.txt","D:/my documents/program in c,c++ and ds/projects/record.txt");
    cout<<"Record deleted successfully";
}

void Record::addStudentRecord()
{
    ofstream fout;
    //add your system path where you want to create file
    fout.open("D:/my documents/program in c,c++ and ds/projects/key.txt",ios::app | ios::out);
    id=getLastId();
    id++;
    fout<<id<<endl;
    fout.close();

    cout<<"Enter your name :: ";
    cin>>name;
    cout<<"Enter your age :: ";
    cin>>age;
    cin.ignore();
    cout<<"Enter your stream:: ";
    cin>>stream;
    ofstream of;

    //add your system path where you want to create file
    of.open("D:/my documents/program in c,c++ and ds/projects/record.txt",ios::app | ios::out);
    of<<id<<endl;
    of<<name<<endl;
    of<<age<<endl;
    of<<stream<<endl;
    of.close();
    cout<<"student record add successfully"<<endl;
}

int menu()
{
    int choice;
    cout<<"1.add record"<<endl;
    cout<<"2.print all record"<<endl;
    cout<<"3.search record"<<endl;
    cout<<"4.delete record"<<endl;
    cout<<"5.update record"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int id;
    Record s;
    while(1)
    {
        system("cls");
       switch(menu())
       {
           case 1:
               s.addStudentRecord();
               break;
          case 2:
               s.printAllRecord();
               break;
           case 3:
               cout<<"Enter Id of student record to be search : ";
               cin>>id;
               s.searchStudentRecord(id);
               break;
           case 4:
               cout<<"Enter Id of student record to be search : ";
               cin>>id;
               s.deleteStudentRecord(id);
               break;
           case 5:
               cout<<"Enter Id of student record to be update : ";
               cin>>id;
               s.updateStudentRecord(id);
               break;
            default:
                cout<<endl<<"Invalid choice";

       }
     getch();
    }
}
