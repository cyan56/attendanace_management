#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
void student_login();                               //Declare functions for student and teacher logins
void teacher_login();
struct student                                      //Structure to hold student details
{
    char first_name[50], last_name[50];
    int  roll_num;
    int  maths_attended,maths_total,science_attended,science_total,computers_attended,computers_total,english_attended,english_total,history_attended,history_total;
};
struct student e;                                   //Initialize structure variable
FILE *fp, *ft;                                      //Declare file pointers and other
char xfirst_name[50], xlast_name[50], divider[190] = "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
int mp,cp,sp,hp,ep;                                //global variables which will be
int xroll_num ;                                     //accessed by different functions
long int recsize;
const char separator    = ' ';
const int nameWidth     = 20;
const int numWidth      = 15;
using namespace std;                                //namespace is used in beginning of all C++ programs
int main()                                          //Main function
{

    fp=fopen("record.txt","rb+");                   //Open the file record.txt if it's already created(rb+)
    if (fp == NULL)                                 //If file does not exist then create a new one(wb+)
    {
        fp = fopen("record.txt","wb+");             //If new file can not be created,exit the program
        if (fp==NULL)
        {
            puts("Cannot open file");
            exit(0);
        }
}
    recsize = sizeof(e);                            //Store the size of structure variable
    int x;
    lpb:do{                                         //Build the main menu using exit controlled loop
    cout<<setw(20)<<"\t\t\t"<<"WELCOME TO STUDENT ATTENDANCE RECORD MANAGEMENT\n";
    cout<<endl;
    cout<<"1->Student Login\n";
    cout<<endl;
    cout<<"2->Teacher Login\n";
    cout<<endl;
    cout<<"3->Exit\n";
    cout<<endl;
    cin>>x;
    system("cls");
    if(x==1)
    {
        student_login();                            //Call the appropriate functions for user inputs
    }
    if(x==2)
    {
        teacher_login();
    }
    if(x==3)
    {
        exit(0);
    }
    if(x!=1||2||3)
    {
	cout<<"Wrong Option\n";
	system("cls");
    goto lpb;                                       //system(cls") clears the screen and sets the pointer to the top left
    }

    }while(x>0&&x<4);
    return 0;
}
void teacher_login()                                //Definition of the teacher_login function
{
    char another, choice;
    string mr,er,sr,cr,hr;
    string teacher_id,password;
    cout<<"Please Enter you registered teacher ID : ";  //Teacher id is pre decided so it can be changed here
    cin>>teacher_id;
    cout<<"\nPlease enter the password provided to you : ";      //Teacher password is pre decided so it can be changed here
    cin>>password;
    if(teacher_id == "johndoe" && password == "defaultpass")    //Compare entered id/password with pre decided id/password
    {
     while(1) {                                                 //If the login details are correct,open the Main page of Teachers portal
     system("cls");

     cout << "\t\t     ====== STUDENT INFORMATION SYSTEM ======";   //Build the main page with all relevant operations needed by the teacher
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t======================";
     cout << "\n \t\t\t  1. Add    Records";
     cout << "\n \t\t\t  2. List   Records";
     cout << "\n \t\t\t  3. Modify Records";
     cout << "\n \t\t\t  4. Delete Records";
     cout << "\n \t\t\t  5. Exit   Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     fflush(stdin);                                                  //fflush(stdin) clears the input stream and waits for a user input which is being done through _getche()
     choice = _getche();
     switch(choice)
     {
      case '1' :
            fseek(fp,0,SEEK_END);                                    //If Add record option is chosen then set the file pointer to the end of file(SEEK_END)
            another ='Y';
            while(another == 'Y' || another == 'y')                  //Enter data to the structure and then write it into the file using fwrite
            {
                system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter Maths classes attended    : ";
                cin >> e.maths_attended;
                cout << "Enter total Maths classes    : ";
                cin >> e.maths_total;
                cout << "Enter English classes attended    : ";
                cin >> e.english_attended;
                cout << "Enter total English classes    : ";
                cin >> e.english_total;
                cout << "Enter Science classes attended    : ";
                cin >> e.science_attended;
                cout << "Enter total Science classes    : ";
                cin >> e.science_total;
                cout << "Enter Computer classes attended    : ";
                cin >> e.computers_attended;
                cout << "Enter total Computer classes    : ";
                cin >> e.computers_total;
                cout << "Enter History classes attended    : ";
                cin >> e.history_attended;
                cout << "Enter total History classes    : ";
                cin >> e.history_total;
                cout << "Enter the USN number :";
                cin >> e.roll_num;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";               //Add more records or exit depending on user input
                fflush(stdin);
                another = getchar();
            }
            break;
      case '2':
           system("cls");
           rewind(fp);                                                //rewind sets the file pointer to the beginning of the file
           cout << "\t\t\t\t\t\t\t\t\t\t\t---> View the Records in the Database <---\n\n\n";
           cout << "\n\n\n\n";
           cout << divider << endl;
           cout << "Name"<<"\t\t\t"<<"   USN"<<"\t\t\t"<< "  " <<"Maths"<<"\t\t"<<"    \t"<<"English"<<"\t\t\t\t"<<"Science"<<"\t\t\t   "<<"Computers"<<"\t\t\t"<<"History\n";
           cout << divider << endl;
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n\n";
           mp = (float(e.maths_attended)/float(e.maths_total))*100; if(mp >= 85) { mr = "E"; } else { mr = "NE"; }
           ep = (float(e.english_attended)/float(e.english_total))*100; if(ep >= 85) { er = "E"; } else { er = "NE"; }
           sp = (float(e.science_attended)/float(e.science_total))*100; if(sp >= 85) { sr = "E"; } else { sr = "NE"; }
           cp = (float(e.computers_attended)/float(e.computers_total))*100; if(cp >= 85) { cr = "E"; } else { cr = "NE"; }
           hp = (float(e.history_attended)/float(e.history_total))*100; if(hp >= 85) { hr = "E"; } else { hr = "NE"; }
           cout << left << e.first_name << " " << setw(nameWidth) <<e.last_name <<setfill(separator)<< left << setw(numWidth) << e.roll_num << setfill(separator)<< e.maths_attended << "/" << left  << e.maths_total << " ( " << mp << "--> " << mr << setw(numWidth) << " ) " <<setfill(separator);
           cout << e.english_attended << "/" << left << e.english_total << " ( " << ep << "--> " << er << setw(numWidth) << " ) " << setfill(separator);
           cout << e.science_attended << "/" << left << e.science_total << " ( " << sp << "--> " << sr << setw(numWidth) << " ) " << setfill(separator);
           cout << e.computers_attended << "/" <<left << e.computers_total << " ( " << cp << "--> " << cr << setw(numWidth) << " ) " << setfill(separator);
           cout << e.history_attended << "/" << left << e.history_total << " ( " << hp << "--> " << hr << setw(numWidth) << " ) " <<endl;
           cout << divider;
           cout << "\n\n\n";
           }
           cout << "P.S. : ";
           cout << "All attendance records are in the form of 'Attended/Total Classes(Percentage of attendance->E OR NE)' where E = Eligible and NE = Not Eligible\n\n\n";
           cout << "\n\n";                                            //Display the output in a tabular form using formatting tools like setw() and setfill().Learn more on these online
           system("pause");
           break;

       case '3' :
        system("cls");
        another = 'Y';
        while (another == 'Y'|| another == 'y')
        {
              cout << "\n Enter the USN number of the student : ";    //Since names can be same we use USN to uniquely identify students.For modifying a record,take the USN of the student first
              cin >> xroll_num;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)                       //While there still is data to be read from structure e
            {
                if(e.roll_num == xroll_num )                          //Check if USN number from the record matches the one entered
                {
                cout << "Enter the new First Name : ";                //If it does match rewrite all the records of that specific USN in the structure
                cin >> e.first_name;
                cout << "Enter the new Last Name : ";
                cin >> e.last_name;
                cout << "Enter Maths classes attended    : ";
                cin >> e.maths_attended;
                cout << "Enter total Maths classes    : ";
                cin >> e.maths_total;
                cout << "Enter English classes attended    : ";
                cin >> e.english_attended;
                cout << "Enter total English classes    : ";
                cin >> e.english_total;
                cout << "Enter Science classes attended    : ";
                cin >> e.science_attended;
                cout << "Enter total Science classes    : ";
                cin >> e.science_total;
                cout << "Enter Computer classes attended    : ";
                cin >> e.computers_attended;
                cout << "Enter total Computer classes    : ";
                cin >> e.computers_total;
                cout << "Enter History classes attended    : ";
                cin >> e.history_attended;
                cout << "Enter total History classes    : ";
                cin >> e.history_total;
                fseek(fp, - recsize, SEEK_CUR);                     //Go to the current position and write the structure data into the file
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"record not found";                           //Display record not found if the USN is invalid
            }
            cout << "\n Modify Another Record (Y/N) ";              //Check if user wants to modify more records
                fflush(stdin);
                another = getchar();
        }
            break;
            case '4':                                               //Deleting a student's record
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
              cout <<"\n Enter the roll number of the student to delete : ";    //Enter the USN of the student
              cin >> xroll_num;
              ft = fopen("temp.dat", "wb");                                     //using our second file pointer ft we open another file called temp.dat
              rewind(fp);                                                       //Goto the start of file pointed by fp(record.txt)
              while (fread (&e, recsize,1,fp) == 1)                             //if entered roll number does not matches the one in record then write its content in the file temp.dat using ft pointer
                if(e.roll_num != xroll_num )
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);                                                     //Close ft and fp files
                fclose(ft);
                remove("record.txt");                                           //Delete the old record.txt file
                rename("temp.dat","record.txt");                                //Rename the new temp.dat to record.txt.This way new file contains all the records except the one which was deleted

                fp=fopen("record.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";                      //Ask if user wants to delete another record
                fflush(stdin);
                another = getchar();
              }

              break;

              case '5':
              fclose(fp);
              cout << "\n\n";
              cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";             //Exit when 5 selected
              cout << "\n\n";
              system("pause");
              system("cls");
              return;
          }
          }

    }
    else
    {
        cout<<"Incorrect credentials\n";                                        //Exit if teachers credentials are wrong
        system("pause");
        system("cls");
        return;
    }
}
void student_login()                                                            //Student_login definition
{
    string student_password;
    string mr,er,sr,cr,hr;
    int student_usn,flag=0;
    fp=fopen("record.txt","rb+");
    fflush(stdin);
    cout << "Please enter your USN number : ";                                  //Enter the USN and password from student
    cin >> student_usn;
    cout << "\nPlease enter the password provided : ";
    cin >> student_password;
    system("cls");
    rewind(fp);
    while (fread(&e,recsize,1,fp) == 1)                                         //Read through file to find the student USN
    {
        if(e.roll_num == student_usn && student_password == "defaultstudent")   //Notice that this if statement executes only if USN is found AND the password matches the pre-decided password
        {
           flag =1;                                                             //Notice that initial value for flag is 0 and i will only turn 1 when this if statement is true
           cout <<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tThe attendance record for USN "<<student_usn<<" is shown below\n\n\n\n";
           cout << divider << endl;
           cout << "Name"<<"\t\t\t"<<"   USN"<<"\t\t\t"<< "  " <<"Maths"<<"\t\t"<<"    \t"<<"English"<<"\t\t\t\t"<<"Science"<<"\t\t\t   "<<"Computers"<<"\t\t\t"<<"History\n";
           cout << divider << "\n\n\n";
           mp = (float(e.maths_attended)/float(e.maths_total))*100; if(mp >= 85) { mr = "E"; } else { mr = "NE"; }
           ep = (float(e.english_attended)/float(e.english_total))*100; if(ep >= 85) { er = "E"; } else { er = "NE"; }
           sp = (float(e.science_attended)/float(e.science_total))*100; if(sp >= 85) { sr = "E"; } else { sr = "NE"; }
           cp = (float(e.computers_attended)/float(e.computers_total))*100; if(cp >= 85) { cr = "E"; } else { cr = "NE"; }
           hp = (float(e.history_attended)/float(e.history_total))*100; if(hp >= 85) { hr = "E"; } else { hr = "NE"; }
           cout << left << e.first_name << " " << setw(nameWidth) <<e.last_name <<setfill(separator)<< left << setw(numWidth) << e.roll_num << setfill(separator)<< e.maths_attended << "/" << left  << e.maths_total << " ( " << mp << "--> " << mr << setw(numWidth) << " ) " <<setfill(separator);
           cout << e.english_attended << "/" << left << e.english_total << " ( " << ep << "--> " << er << setw(numWidth) << " ) " << setfill(separator);
           cout << e.science_attended << "/" << left << e.science_total << " ( " << sp << "--> " << sr << setw(numWidth) << " ) " << setfill(separator);
           cout << e.computers_attended << "/" <<left << e.computers_total << " ( " << cp << "--> " << cr << setw(numWidth) << " ) " << setfill(separator);
           cout << e.history_attended << "/" << left << e.history_total << " ( " << hp << "--> " << hr << setw(numWidth) << " ) " <<endl;
           cout << divider << endl;
           cout << "\n\n\n";
           cout << "P.S. : ";
           cout << "All attendance records are in the form of 'Attended/Total Classes(Percentage of attendance->E OR NE)' where E = Eligible and NE = Not Eligible\n\n\n";                                                   //Print the result for that specific number using the formatting mentioned before
           system("pause");
        }

    }


    if(flag == 0){                                                              //If value of flag still remains 0 it means the if statement didn't execute because either the student USN isn't in the records or the student entered the wrong password
            cout<<"Incorrect Credentials\n\n";
            system("pause");                                                    //system("pause") pauses the operation and waits for a user input
            system("cls");
            return; }                                                           //return makes the control go back to the main function

}
