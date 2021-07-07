#include<iostream>
#include<fstream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
 void main_manu();
int top=0;
long long int sum=0;

class Book
{
protected :

    int bookid;
    char title[20];
    int price;
    int bookcopy;
    char name[25];
    char email[30];
    char phone[20];
    char passward[20];
    int house;
    int road;
    char thana[20];
    char distric[20];
    int bill;
    char coment[100];
    char date[15];

public:
    Book():bookid(0),price(0) // useing constructor and initializer
    {

        bookcopy=0;
        house=0;
        road=0;
        bill=0;

        strcpy(thana,"no thana");
        strcpy(distric,"no distric");
        strcpy(name,"no name");
        strcpy(email,"no email");
        strcpy(passward,"no password");
        strcpy(title,"no title");
        strcpy(phone,"no number");
    }
    ~Book()
    {
        cout<<"\nTHANK YOU FOR VISIT OUR SITE...\n";

    }

    void getbookdata()
    {
        cout<<"\t\tENTER BOOK ID  TITLE AND PRICE\n"<<endl;
        cout<<"\t\tENTER YOUR BOOK ID: ";
        cin>>bookid;
        cout<<"\n\t\t\tENTER YOUR BOOK TITLE: ";
        cin.ignore();
        cin.getline(title,19);
        cout<<"\n\t\tENTER YOUR BOOK PRICE: ";
        cin>>price;
        cout<<"\n\t\t\tENTER YOUR BOOKCOPY NUMBER: ";
        cin>>bookcopy;

    }


    void getsigndata()
    {

        cout<<"\n\t\tPLEASE ADD YOUR INFORMATION"<<endl;
        cout<<"\n\t\tENTER YOUR NAME: ";
        cin.getline(name,24);

        cout<<"\n\t\t\tENTER YOUR PHONE NUMBER: ";
        cin.getline(phone,15);
        cout<<"\n\t\tSET YOUR PASSWARD: ";
        cin.getline(passward,20);
        cout<<"\n\t\t\tENTER YOUR EMAIL: ";
        cin.getline(email,29);



    }

    void getcusaddress()
    {
        cout<<"PLEASE ENTER YOUR ADDRESS"<<endl;
        cout<<"ENTER YOUR NAME: ";
        cin.getline(name,19);
        cout<<"ENTER YOUR HOUSE NO: ";
        cin>>house;
        cout<<"ENTER YOUR ROAD NO: ";
        cin>>road;
        cout<<"ENTER YOUR THANA: ";
        cin.ignore();
        cin.getline(thana,19);
        cout<<"ENTER YOUR DISTRICT: ";
        cin.getline(distric,19);

    }

    void showcusaddress()
    {

        cout<<"\t\tNAME: "<<name<<endl<<"\t\tHOUSE NO: "<<house<<endl<<"\t\tROAD NO: "<<road<<endl<<"\t\tTHANA: "<<thana<<endl<<"\t\tDISTRICT: "<<distric<<endl;



    }

    void showbookdata()
    {
        cout<<"\n\t"<<bookid<<"\t"<<title<<"\t    "<<price<<"\t\t    "<<bookcopy<<endl;

    }

    void showadmindata()
    {

        cout<<"\n\t\tNAME: "<<name<<endl<<"\t\tPHONE NUMBER: "<<phone<<endl<<"\t\tPASSWARD: "<<passward<<endl<<"\t\tEMAIL ID: "<<email<<endl;


    }

    void showcustomerdata()
    {

        cout<<"\n\t\tNAME: "<<name<<endl<<"\t\tPHONE NUMBER: "<<phone<<endl<<"\t\tEMAIL ID: "<<email<<endl;


    }

    void showhead()
    {

        cout<<"\n\t*************************************************"<<endl;
        cout<<"\n\t -----------BOOK SHOP MANAGMENT SYSTEM----------"<<endl;
        cout<<"\n\t*************************************************\n"<<endl;

    }

    void review()
    {
        cout<<"PLEASE ENTER YOUR BOOK NAME FOR REVIEW: ";
        cin.getline(title,19);

        cout<<"PLEASE WRITE YOUR COMENT UNDER 99 WORD: "<<endl;
        cin.getline(coment,99);

    }




    int  storebookdata();
    int  viewbookdata();
    int  serchbookdata();
    void viewselectedbook();
    int  bookreview();
    int  viewallbookreview();
    int  viewonebookreview();
    int setdate();
    friend void main_manu(); //using friend function...

};

class admin:public Book
{


public:

    void   owner();
     void admin_sign_up();
    int  admininformation();//view admin information..
    void adminlogin();
    int  viewcustomerlist();
    int  deletbookdata();
    int  updatebookdata();
    int  viewbookhistory();
    int  viewrecomentbook();
    int changeadminpass();
    int totalselllist();
    int  delevarylist();
    void bookcopyup();
    void buyup();
    void  showcus();


    friend void main_manu();

};


class customers:public Book
{



public:
    void customer();
    void customersignup();
    void customerlogin();
    int  buybook();
    void paymentmethod();
    void paybill();
    int  recomentbook();
    int changecustomerpass();
    friend void main_manu();
};


void admin :: admin_sign_up()
{
    system("CLS");
    showhead();
    int n=0,code=0;
i:
    cout<<"\n\t\tPLEASE ENTER ADMIN CODE : ";
    cin>>code;
    cin.ignore();
    if(code==0000)
    {

        ofstream fout;

        fout.open("admindata.txt",ios::app|ios::binary);


        if(!fout)
            cout<<"The file does not exist";


        else
        {
            getsigndata();
            fout.write((char*)this,sizeof(*this));
            n=1;

        }

        fout.close();
        if(n==1)
        {
           int choice=0;
            cout<<"YOU ARE SUCCESSFULLY SIGN UP..\n\n";

            cout<<"IF YOU WANT TO GO LOG IN PANEL PRESS 1...\n";
            cout<<"EXIST PRESS 2 ...\n\n";

            cout<<"ENTER YOUR CHOICE: ";
            cin>>choice;

            if(choice==1)
            {
            system("CLS");
            main_manu();

            }

            else
             exit(0);


        }

    }

    else
    {
        cout<<"\n\t\tYOUR ADMIN CODE IS WORNG\n";
        cout<<"\t\t PLEASE TRY AGAIN\n";

        goto i;

    }

}

void customers :: customersignup()
{
  ss:
   int n=0;
    system("CLS");
    ofstream fout;

    showhead();

    cout<<"\n\t\t<<<<<<<<<<<<< SIGN UP >>>>>>>>>>>>>\n";

    fout.open("customerdata.txt",ios::app|ios::binary);

    if(!fout)
        cout<<"\nTHE FILE DOES NOT EXIST"<<endl;

    else
    {
        getsigndata();

        fout.write((char*)this,sizeof(*this));
        n=1;
    }

    fout.close();

     if(n==1)
        {
           int choice=0;
            cout<<"YOU ARE SUCCESSFULLY SIGN UP..\n\n";

            cout<<"IF YOU WANT TO GO LOG IN PANEL PRESS 1...\n";
            cout<<"EXIST PRESS 2 ...\n\n";

            cout<<"ENTER YOUR CHOICE: ";
            cin>>choice;

            if(choice==1)
            {
               system("CLS");
                main_manu();
              }

            else
            exit(0);


        }

     else
     {
      cout<<"SOMETHING IS WORNG ....\n";
      cout<<"PLEASE TRY AGAIN....\n";
       goto ss;
     }

}


int  admin ::admininformation()//show andmin information...
{
    int n=0,l=1;
    showhead();
    cout<<"\n\t<<<<<<<<<< ADMIN INFORMATION >>>>>>>>>>>\n"<<endl;
    ifstream fin;

    fin.open("admindata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"The file does not exist"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            cout<<endl;
            cout<<"\n\t\t"<<l;
            showadmindata();
            fin.read((char*)this,sizeof(*this));
            l++;
        }

        fin.close();

    }


    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"EXIST PRESS 2..\n"<<endl;

    cout<<"ENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");




    if(n==1)
        owner();

    else
        return 0;


}


void admin :: adminlogin()
{

J:

    ifstream fin;
    int  c=0;
    char a[20];
    cout<<endl;
    cout<<"\t\tENTER YOUR PASSWORD: ";
    cin.getline(a,19);

    fin.open("admindata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            if(strcmp(a,passward)==0)
            {
                c=1;
            }
            fin.read((char*)this,sizeof(*this));


        }


    }

    fin.close();
    if(c==0)
    {
        cout<<"YOUR PASSWORD IS WORNG"<<endl;
        cout<<"PLEASE TRY AGAIN\n";
        goto J;
    }

    else
    {
        system("CLS");
        owner();

    }


}

void customers :: customerlogin()
{
    cin.ignore();
J:

    ifstream fin;
    int  c=0;
    char a[20];

    cout<<"\n\t\tENTER YOUR PASSWORD: ";
    cin.getline(a,19);



    fin.open("customerdata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"The file does not exist"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            if(strcmp(a,passward)==0)
            {
                c=1;
            }
            fin.read((char*)this,sizeof(*this));

        }



    }

    fin.close();

    if(c==0)
    {
        cout<<"\n\t\t\tYOUR PASSWORD IS WORNG"<<endl;
        cout<<"\n\t\tPLEASE TRY AGAIN\n";
        goto J;

    }

    else
    {
        system("CLS");
        customer();
    }





}

int Book ::storebookdata() //insert a book
{
    admin b1;

j:

    showhead();
    cout<<"\n\t*****************INSERT BOOK********************\n"<<endl;

    int n=0,s=0;
    getbookdata();
    ofstream fout;
    fout.open("bookdata.txt",ios::app|ios::binary);
    if(bookid==0 && price==0)
    {
        cout<<"BOOK DATA IS NOT INISIALIZED"<<endl;
        cout<<"PLEASE ENTER 1 AND INISIALIZED YOUR BOOK INFORMATION CURECTLY: ";
        if(n==1)
            goto j;
    }
    else
    {


        fout.write((char*)this,sizeof(*this));
        s=1;

    }


    fout.close();
    system("CLS");

    showhead();
    cout<<"\n\t*****************INSERT BOOK********************\n"<<endl;


    if(s==1)
        cout<<"\n\t\tYOUR RECORED IS SUCCESSFULLY INSERT.."<<endl;

    else
        cout<<"\n\t\tSOMETHING IS WORNG "<<endl<<"\t\tPLEASE TRAY AGAIN"<<endl;


    cout<<"\n\t\tIF YOU INSERT ANOTHER BOOK PRESS 1.. "<<endl;
    cout<<"\n\t\t\tGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\n\t\tEXIST PRESS 3.."<<endl;

    cout<<"\n\t\t\tENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");

    if(n==1)
        goto j;

    else if(n==2)
        b1. owner();


    else
        return 0;

}

int Book:: viewbookdata()
{
    admin b1;
    customers b2;
    int n=0;
    showhead();
    cout<<endl<<"\n\t############### BOOK INFORMATION #############\n"<<endl;
    cout<<"\n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE"<<"\t   "<<"BOOKCOPY"<<endl;

    ifstream fin;

    fin.open("bookdata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"The file does not exist"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showbookdata();
            fin.read((char*)this,sizeof(*this));
        }



    }
    fin.close();


    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"EXIST PRESS 2..\n"<<endl;

    cout<<"ENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");


    if(n==1)
    {
        if(top==1)
            b1. owner();

        else if(top==2)
            b2. customer();

    }

    else
        return 0;


}


int admin :: viewcustomerlist()
{

    int n=0,l=1;
    showhead();
    cout<<"\n\t%%%%%%%%% CUSTOMER LIST %%%%%%%%%%%\n"<<endl;
    ifstream fin;

    int c=0;
    fin.open("customerdata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"The file does not exist"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            cout<<"\t\t"<<l<<".\n";
            showcustomerdata();
            cout<<endl;
            fin.read((char*)this,sizeof(*this));
            c=1;
            l++;
        }


    }
    fin.close();

    if(c==0)
        cout<<"CUSTOMER LIST IS EMPTY"<<endl;



    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"EXIST PRESS 2..\n"<<endl;

    cout<<"ENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");




    if(n==1)
        owner();

    else
        return 0;


}

int Book::serchbookdata()
{
    admin b1;
    customers b2;
    int n=0;
    char a[25];


i:
    showhead();

    cout<<"\n\t\t\tENTER A BOOK NAME : ";
    cin.ignore();
    cin.getline(a,24);

    ifstream fin;
    int c=0;
    fin.open("bookdata.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"\nTHE FILE DOES NOT EXIST"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            if(strcmp(a,title)==0)
            {
                cout<<endl<<"\n\t############### BOOK INFORMATION #############\n"<<endl;
                cout<<"\n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE"<<"\t   "<<"BOOKCOPY"<<endl;

                showbookdata();
                c=1;
                break;
            }
            fin.read((char*)this,sizeof(*this));

        }


    }
    if(c==0)
        cout<<"YOUR RECORD IS NOT FOUND"<<endl;

    fin.close();


    cout<<"\n\nIF YOU SERCH ANOTHER BOOK PRESS 1.. "<<endl;
    cout<<"GO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"EXIST PRESS 3..\n"<<endl;

    cout<<"\nENTER YOUR CHOICE : ";
    cin>>n;

    system("CLS");

    if(n==1)
        goto i;


    else if(n==2)
    {
        if(top==2)
            b2.customer();

        else if(top==1)
            b1. owner();
    }

    else
        return 0;


}

int admin ::deletbookdata()
{
    int n=0;
    int l=0;
    int d=0;
    char a[25];
o:
    showhead();
    cout<<endl<<"\n\t@@@@@@@@@@@@@@ DELET BOOK DATA @@@@@@@@@@@@@@\n"<<endl;
    cout<<"\n\t\t1.DELET ONE BOOK: \n";
    cout<<"\n\t\t\t2.DELET ALL BOOK RECORD: \n";
    cout<<"\n\t\tENTER YOUR COHICE: ";
    cin>>d;
    system("CLS");
    showhead();
    if(d==2)
    {
        char s;

        cout<<"\n\t\tARE YOU SURE DELET ALL RECORD Y/N:";
        cin>>s;

        if(s=='Y')
        {
            remove("bookdata.txt");
            cout<<"DELET ALL RECORED SUCCESSFULLY DONE...\n";


            cout<<"\n\t\tGO BACK TO MAIN MANU PRESS 1.. "<<endl;
            cout<<"\n\t\t\tEXIST PRESS 2..\n"<<endl;

            cout<<"\n\t\tENTER YOUR CHOICE: ";
            cin>>n;

            system("CLS");


            if(n==1)
                owner();

            else
                return 0;

        }

        else
            goto o;

    }

    else

    {

i:
        cin.ignore();

        cout<<"\n\t\tENTER YOUR BOOK NAME : ";
        cin.getline(a,23);

        ifstream fin;
        ofstream fout;

        fin.open("bookdata.txt",ios::in|ios::binary);
        fout.open("text.txt",ios::out|ios::binary);

        if(!fin)
            cout<<"THE FILE DOES NOT EXIST"<<endl;

        else
        {

            fin.read((char*)this,sizeof(*this));

            while(!fin.eof())
            {

                if(strcmp(title,a))
                {
                    fout.write((char*)this,sizeof(*this));
                    l=1;
                }

                fin.read((char*)this,sizeof(*this));


            }

            fin.close();
            fout.close();

            remove("bookdata.txt");
            rename("text.txt","bookdata.txt");

            system("CLS");

            showhead();

            if(l==1)
                cout<<"\n\t\tYOUR DELET IS SUCCESSFULLY DONE.....\n"<<endl;

            else if(l==0)
                cout<<"\n\t\tYOUR RECORED IS NOT FOUND....\n"<<endl;




            cout<<"\nIF YOU DELET ANOTHER BOOK PRESS 1.. "<<endl;
            cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
            cout<<"\nEXIST PRESS 3..\n"<<endl;

            cout<<"\nENTER YOUR CHOICE: ";
            cin>>n;

            system("CLS");

            if(n==1)
            {
                showhead();
                goto i;
            }

            else if(n==2)
                owner();

            else
                return 0;


        }


    }



}


int  admin :: updatebookdata()
{

    int n=0;
    int l=0;
    char a[25];

i:
    showhead();
    cout<<endl<<"\n\t$$$$$$$$$$$$ UPDATING BOOK DATA $$$$$$$$$$$\n"<<endl;
    cout<<"\n\t\t  ENTER YOUR BOOK NAME: ";
    cin.ignore();
    cin.getline(a,23);

    cout<<endl<<"\n\t<<<<<<<<<<<<<<< YOUR SERCH BOOK DATA >>>>>>>>>>>>>>>>\n"<<endl;
    cout<<"\n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE"<<"\t   "<<"BOOKCOPY"<<endl;


    fstream file;

    file.open("bookdata.txt",ios::in|ios::out|ios::ate|ios::binary);


    if(!file)
        cout<<"\n\t\tTHE FILE DOES NOT EXIST"<<endl;

    else
    {

        file.seekg(0);

        file.read((char*)this,sizeof(*this));

        while(!file.eof())
        {
            if(strcmp(a,title)==0)
            {
                showbookdata();
                cout<<endl;
                getbookdata();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
                cout<<"\e[1;1H\e[2J";
                showhead();
                cout<<endl<<"\n\t$$$$$$$$$$$$ UPDATING BOOK DATA $$$$$$$$$$$\n"<<endl;
                cout<<"\nAFTER UPDATE.."<<endl;
                showbookdata();
                l=1;
            }
            file.read((char*)this,sizeof(*this));


        }


        file.close();

    }
    if(l==0)
    {
        cout<<"\n\t\tTHIS BOOK IS NOT AVAILABLE\n";

    }
    cout<<"\n\t\tIF YOU UPDATE ANOTHER BOOK PRESS 1.. "<<endl;
    cout<<"\n\t\t\tGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\n\t\tEXIST PRESS 3..\n"<<endl;

    cout<<"\n\t\tENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");

    if(n==1)
        goto i;


    else if(n==2)
        owner();

    else
        return 0;




}


void admin:: bookcopyup() // dicrease book copy..

{
    char copyup[20];

    ifstream fin;
    fstream file;

    fin.open("buyup.txt",ios::in|ios::binary);
    file.open("bookdata.txt",ios::in|ios::out|ios::ate|ios::binary);
    if(!fin)
    {
        cout<<"\nTHE FILE DOES NOT EXIST\n";
    }

    else
    {
        fin.seekg(0);
        fin.read((char*)this,sizeof(*this));


        {

            strcpy(copyup,title);

            file.seekg(0);
            file.read((char*)this,sizeof(*this));
            while(!file.eof())
            {
                if(strcmp(copyup,title)==0)
                {

                    bookcopy=bookcopy-1;
                    file.seekp(file.tellp()-sizeof(*this));
                    file.write((char*)this,sizeof(*this));

                    if(bookcopy==0)
                    {
                        file.close();
                        ifstream fin;
                        ofstream fout;

                        fin.open("bookdata.txt",ios::in|ios::binary);
                        fout.open("text.txt",ios::out|ios::binary);

                        if(!fin)
                            cout<<"THE FILE DOES NOT EXIST"<<endl;

                        else
                        {

                            fin.read((char*)this,sizeof(*this));

                            while(!fin.eof())
                            {

                                if(strcmp(title,copyup))
                                {
                                    fout.write((char*)this,sizeof(*this));

                                }

                                fin.read((char*)this,sizeof(*this));


                            }

                            fin.close();
                            fout.close();

                            remove("bookdata.txt");
                            rename("text.txt","bookdata.txt");


                        }

                    }
                }
                file.read((char*)this,sizeof(*this));



            }


        }


    }


    fin.close();
    file.close();
}




void admin::buyup() //view buy up
{

    ifstream fin;

    fin.open("buyup.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showbookdata();
            fin.read((char*)this,sizeof(*this));
        }



    }
    fin.close();



}

int admin :: changeadminpass()
{

    int n=0;
    int l=0;
    char a[20];

j:
    showhead();
    cout<<"\n\t<<<<<<<< CHANGE PASSWORD >>>>>>>>>>>\n";
    cout<<"\n\t\tENTER YOUR PASSWORD : ";
    cin.ignore();
    cin.getline(a,19);

    fstream file;

    file.open("admindata.txt",ios::in|ios::out|ios::ate|ios::binary);

    if(!file)
        cout<<"THE FILE DOES NOT EXIST..."<<endl;

    else
    {

        file.seekg(0);

        file.read((char*)this,sizeof(*this));

        while(!file.eof())
        {
            if(strcmp(a,passward)==0)
            {
                getsigndata();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
                cout<<"\e[1;1H\e[2J";
                showhead();
                cout<<"\n\t******* AFTER CHARNGE ********"<<endl;
                showadmindata();
                l=1;

            }

            file.read((char*)this,sizeof(*this));

        }



        file.close();

    }

    if(l==0)
    {
        cout<<"\nYOUR PASSWORD IS NOT FOUND...\n";
        cout<<"\nPLEASE ENTER YOUR CORRECT PASSWORD..\n";
        goto j;
    }


    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"\nEXIST PRESS 2..\n"<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");


    if(n==1)
        owner();

    else
        return 0;




}



int customers :: changecustomerpass()
{

    int n=0;
    int l=0;
    char a[20];

    showhead();
    cout<<"\n\t<<<<<<<<<<< CHANGE PASSWORD >>>>>>>>>>>>>>\n";
j:
    cout<<"\n\t\tENTER YOUR PASSWORD: ";
    cin.ignore();
    cin.getline(a,19);

    fstream file;

    file.open("customerdata.txt",ios::in|ios::out|ios::ate|ios::binary);

    if(!file)
        cout<<"THE FILE DOES NOT EXIST..."<<endl;

    else
    {

        file.seekg(0);

        file.read((char*)this,sizeof(*this));

        while(!file.eof())
        {
            if(strcmp(a,passward)==0)
            {
                getsigndata();
                file.seekp(file.tellp()-sizeof(*this));
                file.write((char*)this,sizeof(*this));
                cout<<"\e[1;1H\e[2J";
                showhead();
                cout<<"\n<<<<<<<<<<<<<<AFTER CHARNGE >>>>>>>>>>>>>>>.."<<endl;
                showcustomerdata();
                cout<<"\t\tPASSWORD: "<<passward<<endl<<endl;
                l=1;

            }

            file.read((char*)this,sizeof(*this));

        }



        file.close();

    }

    if(l==0)
    {
        cout<<"\nYOUR PASSWORD IS NOT FOUND...\n";
        cout<<"\nPLEASE ENTER YOUR CORRECT PASSWORD..\n";
        goto j;
    }


    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"\nEXIST PRESS 2..\n"<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");


    if(n==1)
        customer();

    else
        return 0;






}

int  admin :: viewbookhistory() //buy book list
{

    system("CLS");


    ifstream fin;

    int n=0;
    showhead();
    cout<<"\n\t&&&&&&&&&& BUY BOOK LIST &&&&&&&&&&\n";

    cout<<" \n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE"<<endl;

    fin.open("buybookhistory.txt",ios::in|ios::binary);



    if(!fin)
        cout<<"\nTHE FILE DOES NOT EXIST"<<endl;

    else
    {

        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {

            cout<<" \n\t"<<bookid<<"\t"<<title<<"\t    "<<price<<endl;

            fin.read((char*)this,sizeof(*this));
        }




    }

    fin.close();


    cout<<"\nIF YOU DELET ALL BUY BOOK HISTORY PRESS 1\n";
    cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\nEXIST PRESS 3..\n"<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");


    if(n==1)
    {
        char s;

        cout<<"ARE YOU SURE Y/N: ";
        cin>>s;
        cout<<"\e[1;1H\e[2J";
        if(s=='Y')
        {
            remove("buybookhistory.txt");
            cout<<"YOUR DELET IS SUCCESSFULLY DONE...\n";
        }
        else
            owner();


    }

    else if(n==2)
        owner();

    else
        return 0;


}

void Book:: viewselectedbook() // selected buy book
{

    ifstream file;

    file.open("selectedbook.txt",ios::in|ios::binary);
    file.seekg(0);
    if(!file)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {

        file.read((char*)this,sizeof(*this));

        while(!file.eof())
        {
            cout<<"\n\t"<<bookid<<"\t"<<title<<"\t    "<<price<<endl;
            file.read((char*)this,sizeof(*this));

        }


    }


    file.close();



}

int  customers :: buybook()
{

    admin b1;
    int l=0,t=0,c;


    char a[25];

    int n=0;
    ofstream file;
    ofstream flist;
    file.open("selectedbook.txt",ios::out|ios::binary);
    flist.open("cusaddress.txt",ios::app|ios::binary);

    cin.ignore();

    showhead();
    cout<<"\n\t<<<<<<<<<<<<<< BUYING BOOK >>>>>>>>>>>>>>>\n";
r:
    c=0;

    ifstream fin;
    ofstream fout;
    ofstream fbuy;

    fin.open("bookdata.txt",ios::in|ios::binary);
    fout.open("buybookhistory.txt",ios::app|ios::binary);
    fbuy.open("buyup.txt",ios::app|ios::binary);




    if(!fin)
        cout<<"\nTHE FILE DOES NOT EXIST"<<endl;

    else
    {

        cout<<"\n\tPLEASE ENTER A BOOK NAME : ";
        cin.getline(a,23);

        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            if(strcmp(a,title)==0)
            {
                sum=sum+price;

                fout.write((char*)this,sizeof(*this));
                file.write((char*)this,sizeof(*this));
                fbuy.write((char*)this,sizeof(*this));
                flist.write((char*)this,sizeof(*this));
                l++;
                c=1;
            }

            fin.read((char*)this,sizeof(*this));


        }
        fbuy.close();
        b1.bookcopyup();
        remove("buyup.txt");

        if(c==0)
        {
            cout<<"\n\t\t\tTHE BOOK IS NOT FOUND"<<endl;
            cout<<"\n\t\tPLEASE TRY ANOTHER BOOK\n"<<endl;
            goto r;

        }

        else
        {
            cout<<"\n\t\tIF YOU WANT TO BUY ANOTHER BOOK PRESS 1"<<endl;
            cout<<"\n\t\t\tELSE PRESS 2\n";
            cout<<"\t\t\t";
            cin>>n;
            cin.ignore();
            if(n==1)
                goto r;
        }
    }

    if(n!=1)
    {
        file.close();
        flist.close();
    }




    {

        cout<<"\n\t\tYOUR TOTAL CHILECTED BOOK IS: "<<l<<endl;
        cout<<"\n\t\tSELECTED BOOK ARE..."<<endl;
        cout<<"\n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE";
        viewselectedbook();
        cout<<"\n\t\tTOTAL PRICE IS: "<<sum<<endl<<endl;

    }

    fin.close();
    fout.close();

    paymentmethod();
    paybill();


    cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\nEXIST PRESS 3.."<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>t;

    system("CLS");


    sum=0;
    if(t==2)
        customer();

    else
        return 0;



}


void customers :: paymentmethod()
{

    ofstream fout;


    fout.open("cusaddress.txt",ios::app|ios::binary);

    if(!fout)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {

        getcusaddress();
        fout.write((char*)this,sizeof(*this));

    }

    fout.close();




}

int admin :: delevarylist()// show delevary list
{

    system("CLS");

    int n=0,l=1,u=1,v=1;
    showhead();
    cout<<"\n\t\t<<<<<<<<<< DELEVARY LIST >>>>>>>>>>>\n"<<endl;
    ifstream fin;


    fin.open("cusaddress.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {
        //fin.seekg(0);
        fin.read((char*)this,sizeof(*this));
        //  cout<<fin.tellg()<<endl;
        while(!fin.eof())
        {

            if(road!=0 && house!=0)
            {
                cout<<"\t\t"<<l<<"."<<endl;
                showcusaddress();
                l++;

            }
            cout<<"\t\t"<<title<<endl;
            cout<<endl;

            fin.read((char*)this,sizeof(*this));

        }

    }

    fin.close();

    if(l==1)
        cout<<"THERE IS NO DELEVARY LIST\n";

    cout<<"\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"EXIST PRESS 2..\n"<<endl;
    cout<<"\n\nDELET DELEVARY LIST PRESS 3\n";

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");




    if(n==1)
        owner();

    else if(n==2)
        return 0;

    else if(n==3)
    {
      int press=0;
        remove("cusaddress.txt");

        cout<<"DELETE SUCCUSSFULLY DONE..\n";
        cout<<"GO TO MAIN MANU PRESS 1..\n";
        cout<<"EXIT PRESS 2..\n";

        cin>>press;

        if(press ==1)
         owner();

         else
         exit(0);


    }

}


void admin :: showcus()
{

    ifstream fin;
    char named[20];

    fin.open("cusaddress.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {

        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            int a;
            //  cout<<a;

            cout<<name<<endl;

            cout<<title;
            // break;
            fin.read((char*)this,sizeof(*this));

        }

    }

    fin.close();




}

void customers :: paybill()
{

    int n=0;
    int number=0;
    int siz=0;
    cout<<"\n\t\tENTER YOUR PAYMENT METHOD: "<<endl;
    cout<<"\n\t\t\t1.BIKASH"<<endl;
    cout<<"\n\t\t2.ROCKET"<<endl;
    cout<<"\n\t\t\t3.CARD"<<endl;

    cout<<"\n\t\tENTER YOUR CHOICE: ";
    cin>>n;

    switch(n)
    {
    case 1:
q:
        cout<<"\n\t\tENTER YOUR BIKASH NUMBER: ";
        cin>>phone;
        siz=strlen(phone);

        try
        {

            if(phone[0]!='0' &&  phone[1]!='1' &&  phone[2]!='7'
                    ||  phone[0]!='0' &&  phone[1]!='1' &&  phone[2]!='9'
                    ||  phone[0]!='0' &&  phone[1]!='1' &&  phone[2]!='8' )
            {
                throw 4;
            }

            else if(siz!=11)
            {
                throw 2;
            }

            else
                goto i;

        }

        catch(int m)
        {

            if(m==4)
            {
                cout<<"\n\t\tPLEASE INTER CORRECT FORMET\n";
                goto q;

            }

            else if(m==2)
            {
                cout<<"\n\t\tPLEASE INTER 11 DIGIT\n";
                goto q;

            }

        }

i:
        cout<<"\n\t\t\tENTER YOUR BILL: ";
        cin>>bill;




        if(bill==sum)
        {
            cout<<"\e[1;1H\e[2J";
            cout<<"\n\t\tYOUR PAYBILL IS SUCCESSFULLY DONE..."<<endl;
            cout<<"\n\t\t\tTHANK YOU"<<endl;
            cout<<"\n\t\tYOU CAN GET YOUR BOOK BEFORE THREE DAYS"<<endl;
        }

        else
        {
            cout<<"\n\t\tPLEASE ENTER CURRECT BILL.."<<endl;
            goto i;

        }
        break;


    case 2:

        cout<<"\n\t\tENTER YOUR ROCKET NUMBER: ";
        cin>>phone;

j:
        {
            cout<<"\n\t\t\tENTER YOUR BILL: ";
            cin>>bill;

            if(bill==sum)
            {
                void adminlogin();
                cout<<"YOUR PAYBILL IS SUCCESSFULLY DONE..."<<endl;
                cout<<"THANK YOU"<<endl;
                cout<<"YOU CAN GET YOUR BOOK BEFORE THREE DAYS"<<endl;
            }

            else
            {
                cout<<"PLEASE ENTER CURRECT BILL.."<<endl;
                goto j;

            }
        }
        break;


    case 3:

        cout<<"ENTER YOUR CARD NUMBER: ";
        cin>>phone;

k:
        {
            cout<<"ENTER YOUR BILL: ";
            cin>>bill;

            if(bill==sum)
            {
                cout<<"YOUR PAYBILL IS SUCCESSFULLY DONE..."<<endl;
                cout<<"THANK YOU"<<endl;
                cout<<"YOU CAN GET YOUR BOOK BEFORE THREE DAYS"<<endl;
            }

            else
            {
                cout<<"PLEASE ENTER CURRECT BILL.."<<endl;
                goto k;

            }
        }
        break;



    }

}

int  customers :: recomentbook() //recoment a book
{
    ofstream fout;
    int n=0,t=0;

    showhead();
    cin.ignore();
    fout.open("recomentbook.txt",ios::app|ios::binary);
s:
    {
        if(!fout)
            cout<<"THE FILE DOES NOT EXIST"<<endl;


        else
        {
            cout<<"\n\t\tPLEASE ENTER YOUR BOOK NAME: ";
            cin.getline(name,23);
            fout.write((char*)this,sizeof(*this));

        }
        cout<<"\nIF YOU RECOMENT ANOTHER BOOK PRESS 1: ";
        cout<<"\nELSE PRESS 2 \n";
        cin>>n;
        cin.ignore();
        if(n==1)
            goto s;
    }
    fout.close();


    cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\nEXIST PRESS 3.."<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>t;

    system("CLS");



    if(t==2)
        customer();

    else
        return 0;



}



int admin :: viewrecomentbook()
{
    int   n=0,l=1;
    char a;

    ifstream fin;
    showhead();
    cout<<"\n\t<<<<<<<<< RECOMENT BOOK LIST >>>>>>>>>>>\n"<<endl;
    fin.open("recomentbook.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {

            cout<<"\n\t\t"<<l<<"."<<name<<endl;

            fin.read((char*)this,sizeof(*this));
            l++;
        }


    }

    fin.close();

    cout<<"\nIF YOU DELET PREVIOUS RECOMENT BOOK PRESS 1 "<<endl;
    cout<<"\nIF YOU GO BACK TO MAIN MANU PRESS 2..\n";
    cout<<"\nEXIST PRESS 3..\n";
    cin>>n;

    system("CLS");
    if(n==1)
    {
        cout<<"ARE YOU SURE Y/N : ";
        cin>>a;
        if(a=='Y')
        {
            remove("recomentbook.txt");
            cout<<"DELET SUCCESSFULLY DONE...";

            cout<<"IF YOU GO BACK TO MAIN MANU PRESS 2..\n";
            cout<<"EXIST PRESS 3..\n";
            cin>>n;
            system("CLS");

        }


        else
            owner();

    }
    else if(n==2)
        owner();

    else
        return 0;
    system("CLS");


}


int  Book :: bookreview() //insert book review....
{
    customers b2;
    showhead();
    cout<<"\n\t<<<<<<<<<< INSERT BOOK REVIEW >>>>>>>>>>>>\n\n";
J:
    ofstream fout;

    int t=0;
    cin.ignore();

    fout.open("review.txt",ios::app|ios::binary);

    if(!fout)
        cout<<"\nTHE FILE DOES NOT EXIST"<<endl;

    else
    {
        review();
        fout.write((char*)this,sizeof(*this));
        cout<<"\nYOUR REVIEW IS ADD SUCCESSFULLY....\n";
    }


    fout.close();


    cout<<"\nADD ANOTHER BOOK REVIEW PRESS 1"<<endl;
    cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\nEXIST PRESS 3.."<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>t;

    system("CLS");


    if(t==1)
        goto J;

    if(t==2)
        b2.customer();

    else
        return 0;


}


int  Book :: viewallbookreview()
{
    admin b1;
    customers b2;
    ifstream fin;
    int n=1;
    int l=0;
    showhead();
    cout<<"\n\t********* REVIEW BOOK LIST **********"<<endl;
    fin.open("review.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"\nTHE DOES NOT EXIST"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            cout<<"\n\t\t"<<n<<"."<<title<<endl;
            cout<<"\n\t\t"<<coment<<endl;
            fin.read((char*)this,sizeof(*this));
            n++;
        }


    }

    fin.close();


    cout<<"\n\nGO BACK TO MAIN MANU PRESS 1.. "<<endl;
    cout<<"\nEXIST PRESS 2.."<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>l;

    system("CLS");



    if(l==1)
    {
        if(top==1)
            b1.owner();

        else if(top==2)
            b2.customer();

    }

    else
        return 0;



}

int  Book :: viewonebookreview()
{
    admin b1;
    customers b2;
j:

    int n=0,l=0,m=1;
    char a[20];



    ifstream fin;

    showhead();
    cout<<"\n\t\tINTER YOUR BOOK NAME: ";
    cin.ignore();
    cin.getline(a,19);
    cout<<"\n\n\t********* REVIEW BOOK *********\n"<<endl;


    fin.open("review.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"The file does not exist"<<endl;

    else
    {
        fin.read((char*)this,sizeof(*this));

        while(!fin.eof())
        {
            if(strcmp(a,title)==0)
            {
                cout<<"\n\t\t"<<m<<"."<<title;
                cout<<"\n\t\t"<<coment<<endl;
                n=1;
            }
            fin.read((char*)this,sizeof(*this));

        }

        fin.close();

    }

    if(n==0)
        cout<<"\nTHERE ARE NO REVIEW IN THIS BOOK.....\n";

    cout<<"\n\nIF YOU VIEW ANOTHER REVIEW PRESS 1.. "<<endl;
    cout<<"\nGO BACK TO MAIN MANU PRESS 2.. "<<endl;
    cout<<"\nEXIST PRESS 3.."<<endl;

    cout<<"\nENTER YOUR CHOICE: ";
    cin>>l;

    system("CLS");

    if(l==1)
        goto j;

    else if(l==2)
    {
        if(top==1)
            b1.owner();

        else if(top==2)
            b2.customer();

    }

    else
        return 0;





}

int Book :: setdate()
{
    admin b1;
    int n=0,l;

    cout<<"PLEASE ENTER TODAYS DATE: ";
    cin.ignore();
    cin.getline(date,14);

    ofstream fout;

    fout.open("buybookhistory.txt",ios::app|ios::binary);

    if(!fout)
        cout<<"THE FILE DOES NOT EXIST\n";

    else
    {
        fout.write((char*)this,sizeof(*this));

        fout.close();
        n=1;
    }

    cout<<"YOUR DATE IS SUCCESSFULLY ADD\n";
    cout<<"GO BACT TO MAIN MANU PRESS 1\n";
    cout<<"EXIST PRESS 2\n";

    cout<<"ENTER YOUR CHOICH: ";
    cin>>l;

    system("CLS");

    if(l==1)
        b1.owner();

    else
        return 0;
}


int admin :: totalselllist()
{

    char a[15];
    int n=0;
    showhead();
    cout<<"\n\tENTER YOUR DATE(dd/mm/year) : ";

    cin.ignore();
    cin.getline(a,14);

    cout<<"\n\n\t&&&&&&&&&& BUY BOOK LIST &&&&&&&&&&\n";
    cout<<" \n\tID  "<<"\t"<<"TITLE"<<"\t    "<<"PRICE"<<endl;

    ifstream fin;

    fin.open("buybookhistory.txt",ios::in|ios::binary);

    if(!fin)
        cout<<"THE FILE DOES NOT EXIST\n";

    else
    {
        fin.read((char*)this,sizeof(*this));


        if(strcmp(a,date)==0)
        {
            while(!fin.eof())
            {
                sum=sum+price;
                cout<<" \n\t"<<bookid<<"\t"<<title<<"\t    "<<price<<endl;
                fin.read((char*)this,sizeof(*this));

                n=1;

            }

        }

    }

    cout<<"\n\n\tTOTAL AMOUNT IS : ";
    cout<<sum<<endl;
    fin.close();
    int l;
    if(n==0)
        cout<<"\nYOUR RECORD IS NOT FOUND\n";

    cout<<"\n GO TO MAIN MANU PRESS 1\n";
    cout<<"\nEXIST PRESS 2\n";

    cout<<"ENTER YOUR CHOICH: ";
    cin>>l;

    system("CLS");
    sum=0;
    if(l==1)
        owner();

    else
        return 0;

}

void admin :: owner()
{


    int n=0;
    int d=0;
    top=1;

    showhead();

    cout<<"\n\t\t0.PLEASE SET TODAYS DATE FIRSTLY \n";
    cout<<"\n\t\t\t1.INSERT A BOOK"<<endl;
    cout<<"\n\t\t2.SERCH A BOOK"<<endl;
    cout<<"\n\t\t\t3.DELET A BOOK"<<endl;
    cout<<"\n\t\t4.UPDATE BOOK DATA"<<endl;
    cout<<"\n\t\t\t5.VIEW ALL BOOK LIST"<<endl;
    cout<<"\n\t\t6.VIEW DELEVARY LIST"<<endl;
    cout<<"\n\t\t\t7.VIEW CUSTOMER LIST"<<endl;
    cout<<"\n\t\t8.VIEW ADMIN INFORMATION"<<endl;
    cout<<"\n\t\t\t9.VIEW BUY BOOK HISTORY"<<endl;
    cout<<"\n\t\t10.VIEW RECOMENTED BOOK LIST"<<endl;
    cout<<"\n\t\t\t11.VIEW ONE BOOK REVIEW"<<endl;
    cout<<"\n\t\t12.VIEW ALL BOOK REVIEW"<<endl;
    cout<<"\n\t\t\t13.VIEW BUY BOOK LIST OF A DAY OR MOUNTH\n";

    cout<<"\n\t\t14.CHANGE YOUR PASSWORD"<<endl;

    cout<<"\n\t\t\t15.LOGOUT"<<endl;
    cout<<"\n\t\t16.EXIST"<<endl;

    cout<<"\n\t\tPLEASE ENTER YOUR CHOICE: ";
    cin>>n;

    system("CLS");


    switch(n)
    {


    case 0:
        setdate();
        break;


    case 1:
        storebookdata();
        break;

    case 2:
        serchbookdata();
        break;

    case 3:
        deletbookdata();
        break;

    case 4:
        updatebookdata();
        break;

    case 5:
        viewbookdata();
        break;

    case 6:
        delevarylist();
        break;

    case 7:
        viewcustomerlist();
        break;

    case 8:
        admininformation();
        break;

    case 9:
        viewbookhistory() ;
        break;

    case 10:
        viewrecomentbook();
        break;

    case 11:
        viewonebookreview();
        break;

    case 12:
        viewallbookreview();
        break;

    case 13:
        totalselllist();
        break;

    case 14:
        changeadminpass();
        break;

    case 15:
        cout<<"\e[1;1H\e[2J";
        main_manu();
        break;

    case 16:
      exit(0);




    }



}


void customers :: customer()
{

    int n=0;
    int d=0;
    top=2;

    showhead();

    cout<<"\n\t\t1.SERCH A BOOK"<<endl;
    cout<<"\n\t\t\t2.VIEW ALL BOOK LIST"<<endl;
    cout<<"\n\t\t3.BUY A BOOK"<<endl;
    cout<<"\n\t\t\t4.RECOMENT A BOOK"<<endl;
    cout<<"\n\t\t5.INSERT BOOK REVIEW"<<endl;
    cout<<"\n\t\t\t6.VIEW ONE BOOK REVIEW"<<endl;
    cout<<"\n\t\t7.VIEW ALL BOOK REVIEW"<<endl;
    cout<<"\n\t\t\t8.CHANGE YOUR PASSWORD"<<endl;
    cout<<"\n\t\t9.LOGOUT"<<endl;
    cout<<"\n\t\t\t10.EXIT"<<endl;

    cout<<"\n\n\t\t\tPLEASE ENTER YOUR CHOICE : ";
    cin>>n;
    system("CLS");

    switch(n)
    {

    case 1:
        cout<<"***SERCH BOOK DATA***\n\n";
        serchbookdata();
        break;

    case 2:
        viewbookdata();
        break;

    case 3:
        buybook();
        break;

    case 4:
        recomentbook();
        break;

    case 5:
        bookreview();
        break;

    case 6:
        viewonebookreview();
        break;

    case 7:
        viewallbookreview();
        break;

    case 8:
        changecustomerpass();
        break;

    case 9:
        system("CLS");
        main_manu();
        break;

     case 10:
       exit(0);


    }

}


void main_manu() // using friend function........
{

    int n=0;
    Book b;
    admin b1;
    customers b2;
    char s[20];

    cout<<"\n\t*****************************************"<<endl;
    cout<<"\n\t -------------WELCOME TO----------------"<<endl;
    cout<<"\n\t -----------OUR BOOK SHOP---------------"<<endl;
    cout<<"\n\t*****************************************\n"<<endl;

    cout<<"\t\t1.OWNER LOGE IN..\n";
    cout<<"\n\t\t\t2.OWNER SIGN UP \n";
    cout<<"\n\t\t3.CUSTOMER LOGE IN\n";
    cout<<"\n\t\t\t4.CUSTOMER SIGN UP \n\n\n";

    cout<<"\t  ENTER YOUR CHOICH : ";
    cin>>n;

    switch(n)
    {


    case 1:
        cin.ignore();
        b1.adminlogin();
        break;

    case 2:
        cin.ignore();
        b1.admin_sign_up();
        break;

    case 3:
        b2.customerlogin();
        break;

    case 4:
        cin.ignore();
        b2.customersignup();
        break;

    default:
        break;

    }

}


int main()
{

    main_manu();

    return 0;

}

