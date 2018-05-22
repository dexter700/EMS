#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#define db "revert_db.txt"

using namespace std;

class employee{
public:
    string name;
    string email;
    string eid;
    string age;
    string dept;
    string salary;
    string dob;
    string bonus;
    string address;
    string contact;
    string temp;
    string buffer;

    bool checkid(string id){
        bool res = false;
        fstream file;
        file.open(db);

        /*ifstream file2(db, ios::binary | ios::ate);
        int sized = file.tellg();
        file2.close();
        cout<<sized;
        if(sized == 0){
            return true;
        }else{
            */while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
                    if(eid.compare(id) != 0){
                    res = true;
                }
            }
            res = false;
            file.close();
        //}

        return res;
    }
    void addEmployee(){
        cout<<"Enter Employee ID: "<<endl;
        cin>>eid;
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter age: "<<endl;
        cin>>age;
        cout<<"Enter Department: "<<endl;
        cin>>dept;
        cout<<"Enter salary: "<<endl;
        cin>>salary;
        cout<<"Enter DOB: "<<endl;
        cin>>dob;
        cout<<"Enter Bonus: "<<endl;
        cin>>bonus;
        cout<<"Enter address: "<<endl;
        cin>>address;
        cout<<"Enter contact"<<endl;
        cin>>contact;
        buffer = eid+" "+name+" "+age+" "+dept+" "+salary+" "+dob+" "+bonus+" "+address+" "+contact;
        if(checkid(eid) == false){
                cout<<"Employee Exist!"<<endl;
        }else{
            ofstream file;
            file.open(db,ios::app);
            file<<buffer<<endl;
            cout<<"Added to database"<<endl;
            file.close();
        }
    }
    void displayEmployee(){
        fstream file;
        file.open(db);
        cout<<"ID\t\tName\t\tAge\t\tDept\t\tSalary\t\tDOB\t\tBonus\t\tAddress\t\tContact"<<endl;
        cout<<"--\t\t----\t\t---\t\t----\t\t------\t\t---\t\t------"<<endl;
        while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
            cout<<eid<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<dept<<"\t\t"<<salary<<"\t\t"<<dob<<"\t\t"<<bonus<<"\t\t"<<address<<"\t\t"<<contact<<endl;
        }
        file.close();
    }
    void showHash(){
        fstream file;
        file.open(db);
        int key=0;
        cout<<"KEY\t\tValue"<<endl;
        while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
            cout<<key<<"\t\t"<<eid<<endl;
            key++;
        }
        cout<<"Total Size: "<<key;
        file.close();
    }
    void searchEmployee(){
        string id;
        cout<<"Enter Employee ID: ";
        cin>>id;
        fstream file;
        file.open(db);
        cout<<"ID\t\tName\t\tAge\t\tDept\t\tSalary\t\tDOB\t\tBonus\t\tAddress\t\tContact"<<endl;
        cout<<"--\t\t----\t\t---\t\t----\t\t------\t\t---\t\t------"<<endl;
        while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
                if(eid.compare(id) == 0){
                    cout<<eid<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<dept<<"\t\t"<<salary<<"\t\t"<<dob<<"\t\t"<<bonus<<"\t\t"<<address<<"\t\t"<<contact<<endl;
                    getch();
                }
        }
        file.close();
    }
    void deleteEmployee(){
            string line,deleteid;
            cout<<"EMPLOYEE ID TO DELETE: ";
            cin>>deleteid;
            ifstream file;
            ofstream outfile;
            file.open(db);
            outfile.open("newM.txt",ios::app);
            while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
                if(eid.compare(deleteid) != 0){
                    outfile<<eid<<" "<<name<<" "<<dept<<" "<<salary<<" "<<dob<<" "<<bonus<<" "<<address<<" "<<contact<<"\n";
                }
            }
            outfile.close();
            file.close();
            remove(db);
            rename("newM.txt",db);
    }
    bool deleteD(string id){
        string line,deleteid;
            deleteid = id;
            ifstream file;
            ofstream outfile;
            file.open(db);
            outfile.open("newM.txt",ios::app);
            while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
                if(eid.compare(deleteid) != 0){
                    outfile<<eid<<" "<<name<<" "<<dept<<" "<<salary<<" "<<dob<<" "<<bonus<<" "<<address<<" "<<contact<<"\n";
                }
            }
            outfile.close();
            file.close();
            remove(db);
            rename("newM.txt",db);
            return true;
    }
    void modifyEmployee(){
        string id;
        bool e=false;
        cout<<"Enter Employee ID: ";
        cin>>id;
        fstream file;
        file.open(db);
        while(file>>eid>>name>>age>>dept>>salary>>dob>>bonus>>address>>contact){
                if(eid.compare(id) == 0){
                    e = true;
                    cout<<"Modified employee details!"<<endl;
                    cout<<"ID\t\tName\t\tAge\t\tDept\t\tSalary\t\tDOB\t\tBonus\t\tAddress\t\tContact"<<endl;
                    cout<<"--\t\t----\t\t---\t\t----\t\t------\t\t---\t\t------\t\t------\t\t-------"<<endl;
                    cout<<eid<<"\t\t"<<name<<"\t\t"<<age<<"\t\t"<<dept<<"\t\t"<<salary<<"\t\t"<<dob<<"\t\t"<<bonus<<"\t\t"<<address<<"\t\t"<<contact<<endl;
                }
        }
        file.close();
        if(e == true){
            cout<<"Enter Employee Name: ";
            cin>>name;
            cout<<"Enter employee age: ";
            cin>>age;
            cout<<"Enter Employee Department: ";
            cin>>dept;
            cout<<"Enter employee salary: ";
            cin>>salary;
            cout<<"Enter employee dob: ";
            cin>>dob;
            cout<<"Enter employee bonus: ";
            cin>>bonus;
            cout<<"Enter employee address: ";
            cin>>address;
            cout<<"Enter employee contact: ";
            cin>>contact;
            buffer = id+" "+name+" "+age+" "+dept+" "+salary+" "+dob+" "+bonus+" "+address+" "+contact;
            //update
            if(deleteD(id) == true){
                    //ifstream file;
                    file.open(db,ios::app);
                    file<<buffer<<endl;
                    file.close();
                    cout<<"EMPLOYEE RECORD UPDATED!"<<endl;
            }            //end
        }else{
            cout<<"NO EMPLOYEE DATA FOUND TO MODIFY"<<endl;
            getch();
        }


    }

    bool login(string key){
        system("cls");
        bool result=false;
        string code="12345";
        if(code.compare(key) == 0){
            result = true;
        }else{
            result = false;
        }
        return result;
    }
    void menu(){
        cout<<"1. ADD NEW EMPLOYEE DATA"<<endl;
        cout<<"2. DISPLAY ALL EMPLOYEE DATA"<<endl;
        cout<<"3. DISPLAY HASH TABLE OF THE EMPLOYEES"<<endl;
        cout<<"4. MODIFY EMPLOYEE DATA"<<endl;
        cout<<"5. DELETE EMPLOYEE DATA"<<endl;
        cout<<"6. SEARCH EMPLOYEE DATA"<<endl;
        cout<<"7. EXIT"<<endl;
    }



};
employee emp;
int main(){
    string key;
    int opt;
    cout<<"=====================EMS :: EMPLOYEE MANAGEMENT SYSTEM======================="<<endl;
    cout<<"=============================AUTHENTICATION=================================="<<endl;
    cout<<"Enter PIN to continue: ";
    cin>>key;

    if(emp.login(key) == true){
        system("cls");
        cout<<"WELCOME MANISHA\n"<<endl;
        while(1){
            LOOP:
                system("cls");
            emp.menu();
            cout<<"ENTER YOUR OPTION: ";
            cin>>opt;
            switch(opt){
            case 1:
                emp.addEmployee();
                getch();
                goto LOOP;
                break;
            case 2:
                emp.displayEmployee();
                getch();
                goto LOOP;
                break;
            case 3:
                emp.showHash();
                getch();
                goto LOOP;
                break;
            case 4:
                emp.modifyEmployee();
                getch();
                goto LOOP;
                break;
            case 5:
                emp.deleteEmployee();
                getch();
                goto LOOP;
                break;
            case 6:
                emp.searchEmployee();
                getch();
                goto LOOP;
                break;
            case 7:
                cout<<"SYSTEM TERMINATED! PRESS ANY KEY TO EXIT!";
                getch();
                exit(0);
                break;
            default:
                cout<<"Invalid option"<<endl;
                getch();
                goto LOOP;

            }
        }
    }else{
        cout<<"MANISHA DO NOT WANT UNAUTHORISED USER TO ACCESS HER DATA"<<endl;
    }
    //emp.addEmployee();
    //emp.displayEmployee();
    //emp.showHash();
    //emp.deleteEmployee();
    //emp.modifyEmployee();
}
