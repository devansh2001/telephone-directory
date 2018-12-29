#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<windows.h>

// System currently built to handle a maximum of 100 records
// Capacity can be increased by changing below value of int MAX
const int MAX = 100;

// Structure to handle Date of Birth
struct dob {
    int mm,dd,yyyy;
};

// Class to handle operations of Telephone Directory
class Telephone_Directory {
   char name[25], sex,emailid_p[50],emailid_o[50],address[35];
   int code;
   char phoneresi[15],phonemobi[15],faxresi[15],faxoffi[15],phoneoffi[15];
   dob birthday;

public:
    // Public Method to Handle Data Input
    void input() {
        cout<<"Please input details: \n" ;
        cout<<"Input Code: ";
        cin>>code;
        cout<<"Input Name: ";
        gets(name);
        cout<<"Input Date of Birth (DD/MM/YYYY): ";
        cin>>birthday.dd>>birthday.mm>>birthday.yyyy;
        cout<<"Input Sex: ";
        cin>>sex;
        cout<<"Input Residential Phone Number: ";
        cin>>phoneresi;
        cout<<"Input Mobile Number: ";
        cin>>phonemobi;
        cout<<"Input Residential Fax Number: ";
        cin>>faxresi;
        cout<<"Input Personal Email-ID: ";
        cin>>emailid_p;
        cout<<"Input Residential Address: ";
        gets(address);
        cout<<"Input Office Phone Number: ";
        cin>>phoneoffi;
        cout<<"Input Office Fax Number: ";
        cin>>faxoffi;
        cout<<"Input Office Email-ID: ";
        cin>>emailid_o;
    }

    // Public Method to Display Data
    void display() {
        cout<<"Code: "<<code<<endl
        <<"Name: "<<name<<endl;
        <<"Date of Birth (DD/MM/YYYY):
        "<<birthday.dd<<'/'<<birthday.mm<<'/'<<birthday.yyyy<<endl
        <<"Sex: "<<sex<<endl
        <<"Residential Phone Number: "<<phoneresi<<endl
        <<"Mobile Number: "<<phonemobi<<endl
        <<"Residentail Fax Number: "<<faxresi<<endl
        <<"Personal Email-ID: "<<emailid_p<<endl
        <<"Official Email-I: "<<emailid_o<<endl
        <<"Residentail Address: "<<address<<endl
        <<"Office Phone Nummber: "<<phoneoffi<<endl
        <<"Office Fax Number: "<<faxoffi<<endl;
        getch();
    }

    // Getter Methods
    int retcode() {return code;}
    dob retbirthday() { return birthday;}
    char* retname() {return name;}
    char retsex() {return sex;}
    char* retemailid_p() {return emailid_p;}
    char* retemailid_o() {return emailid_o;}
    char* retphoneresi() {return phoneresi;}
    char* retphonemobi() {return phonemobi;}
    char* retfaxresi() {return faxresi;}
    char* retfaxoffi() {return faxoffi;}
    char* retphoneoffi() {return phoneoffi;}
    char* retaddress() {return address;}
};

// Record Addition Starts here
void addrecord() {
    char ch;
    fstream df("TelephoneDir.DAT", ios::app|ios::binary);
    do
    {
        Telephone_Directory T;
        T.input();
        df.write((char*)&T, sizeof(T));
        cout<<endl;
        cout<<"Record Added!";
        cout<<endl<<endl;
        cout<<"Input more records? (Y/N) ";
        cin>>ch;
    } while (ch == 'y' || ch == 'Y');
    df.close();
}
// Record Addition Ends here

// Record Deletion Starts here
void deleterecord() {
   Telephone_Directory T,Ttemp;
   T.input();
   fstream df,tf;
   df.open("TelephoneDir.DAT", ios::in|ios::binary);
   tf.open("TelephoneDir.TEMP", ios::out|ios::binary);
   while (df.read((char*)&Ttemp, sizeof(Ttemp))) {
    if (T.retcode() !=  Ttemp.retcode())
        tf.write((char*)&Ttemp, sizeof(Ttemp));
}
df.close();
tf.close();
remove("TelephoneDir.DAT");
rename("TelephoneDir.TEMP", "TelephoneDir.DAT");
}
// Record Deletion Ends here

// Record Modification Starts here
void modifyrecord() {
    int c;
    cout<<"Enter the code of the record to be modified: ";
    cin>>c;
    Telephone_Directory T;
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (c == T.retcode())
        {
            df.seekg(-sizeof(T), ios::cur);
            df.write((char*)&T, sizeof(T));
        }
    }
    df.close();
}
//Record Modification Ends here

//Searching starts here
void searchname() {
    ifstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T;
    char requiredname[25];
    cout<<"Please input the NAME to be search for: ";
    gets(requiredname);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(requiredname, T.retname()) == 0)
            T.display();
    }
    df.close();
}

void searchphoneoffi() {
    ifstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T;
    char n[15];
    cout<<"Please input the OFFICE PHONE NUMBER to be search for: ";
    gets(n);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(n, T.retphoneoffi()) == 0)
            T.display();
    }
    df.close();
}

void searchphoneresi() {
    ifstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T;
    char n[15];
    cout<<"Please input the RESIDENTIAL PHONE NUMBER to be search for: ";
    gets(n);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(n, T.retphoneresi()) == 0)
            T.display();
    }
    df.close();
}

void searchfaxoffi() {
    ifstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T;
    char n[15];
    cout<<"Please input the OFFICE FAX NUMBER to be search for:
    ";gets(n);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(n, T.retfaxoffi()) == 0)
            T.display();
    }
    df.close();
}

void searchfaxresi() {
    ifstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T;
    char n[15];
    cout<<"Please input the RESIDENTIAL FAX NUMBER to be search for: ";
    gets(n);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(n, T.retfaxresi()) == 0)
            T.display();
    }
    df.close();
}

void searchphonemobi() {
    ifstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T;
    char n[15];
    cout<<"Please input the MOBILE NUMBER to be search for: ";gets(n);
    while (df.read((char*)&T, sizeof(T)))
    {
        if (strcmpi(n, T.retphonemobi()) == 0) {
            T.display();
        }
    }
    df.close();
}

void searchemailid_p() {
    ifstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T;
    char id[50];
    cout<<"Please input the PERSONAL EMAIL-ID to be search for: ";gets(id);
    while (df.read((char*)&T, sizeof(T)))
    {
           if (strcmpi(id, T.retemailid_p()) == 0) {
                T.display();
           }
    }
    df.close();
}

void searchemailid_o() {
    ifstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T;
    char id[50];
    cout<<"Please input the OFFICE EMAIL-ID to be search for: ";gets(id);
    while (df.read((char*)&T, sizeof(T)))
    {
       if (strcmpi(id,T.retemailid_o()) == 0) {
            T.display();
       }
    }
    df.close();
}

void searchmenu() {
    int ch;
    do {
        cout<<"What would you like to search on? "<<endl<<endl;
        cout<<"1. Name\n2. Mobile Number\n3. Office Phone Number\n4.
        Residential Phone Number\n5. Office Fax Number\n6. Personal Fax Number\n7.
        Office Email-ID\n8. Personal Email-ID\n\n";
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        switch(ch) {
            case 1:searchname();break;
            case 2:searchphonemobi();break;
            case 3:searchphoneoffi();break;
            case 4:searchphoneresi();break;
            case 5:searchfaxoffi();break;
            case 6:searchfaxresi();break;
            case 7:searchemailid_o();break;
            case 8:searchemailid_p();break;
        }
    } while (ch != 0);
}
//Searching Ends here

//Sorting Starts here
void sortname() {
    fstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
       df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k < MAX-j; k++) {
            if (strcmpi(T[k].retname(), T[k + 1].retname())>0)
            {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortdob() {
    fstream df;
    df.open("TelephoneDir.DAT",ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0;!df.eof(); i++)
    df.read((char*)&T[i], sizeof(T[i]));
    df.close();
    for (int j = 0; j<MAX; j++) {
        for (int k = 1; k < MAX - j; k++) {
            dob date1 = T[k].retbirthday(),date2 = T[k + 1].retbirthday();
            if (date1.yyyy > date2.yyyy) {
                if (date1.mm > date2.mm) {
                    if (date1.dd > date2.dd) {
                        Telephone_Directory temp;
                        temp = T[k];
                        T[k] = T[k + 1];
                        T[k + 1] = temp;
                    }
                }
            }
        }
    }
    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0;k < i;k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortemailid_o() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1;k < MAX - j;k++) {
            if (strcmpi(T[k].retemailid_o(), T[k + 1].retemailid_o())>0) {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT", ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortemailid_p() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k < MAX - j; k++) {
            if (strcmpi(T[k].retemailid_p(),T[k + 1].retemailid_p())>0)
            {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
       df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortphone_office() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k < MAX - j; k++) {
            if (T[k].retphoneoffi() > T[k + 1].retphoneoffi()) {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}


void sortphone_residence() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k< MAX - j; k++) {
            if (T[k].retphoneresi() > T[k + 1].retphoneresi()) {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }

    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortphone_mobile() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0; !df.eof(); i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k < MAX - j; k++) {
            if (T[k].retphonemobi() > T[k + 1].retphonemobi())
            {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT", ios::out|ios::binary);
    for (int k = 0; k<i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortfax_office() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0;!df.eof();i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX; j++) {
        for (int k = 1; k < MAX - j; k++) {
            if (T[k].retfaxoffi() > T[k + 1].retfaxoffi()) {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT",ios::out|ios::binary);
    for (int k = 0; k<i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortfax_residence() {
    fstream df;
    df.open("TelephoneDir.DAT", ios::in|ios::binary);
    Telephone_Directory T[MAX];
    int i;
    for (i = 0;!df.eof();i++) {
        df.read((char*)&T[i], sizeof(T[i]));
    }
    df.close();
    for (int j = 0; j < MAX;j++) {
        for (int k = 1; k < MAX - j; k++) {
            if (T[k].retfaxresi() > T[k + 1].retfaxresi()) {
                Telephone_Directory temp;
                temp = T[k];
                T[k] = T[k + 1];
                T[k + 1] = temp;
            }
        }
    }
    df.open("TelephoneDir.DAT", ios::out|ios::binary);
    for (int k = 0; k < i; k++) {
        df.write((char*)&T[k], sizeof(T[k]));
    }
    df.close();
}

void sortmenu()
{
    int ch;
    do
    {
        cout<<"What would you like to sort the data on? :";
        cout<<"1. Name\n"
        <<"2. Date of Birth\n"
        <<"3. Residential Phone Number\n"
        <<"4. Mobile Phone Number\n"
        <<"5. Office Phone Number\n"
        <<"6. Residential Fax Number\n"
        <<"7. Office Fax Number\n"
        <<"8. Personal Email-ID\n"
        <<"9. Office Email-ID\n"
        <<"0. Exit\n\n"
        <<"Enter choice: ";
        cin>>ch;
        switch(ch) {
           case 1: sortname(); break;
           case 2: sortdob(); break;
           case 3: sortphone_residence(); break;
           case 4: sortphone_mobile(); break;
           case 5: sortphone_office(); break;
           case 6: sortfax_residence(); break;
           case 7: sortfax_office(); break;
           case 8: sortemailid_p(); break;
           case 9: sortemailid_o(); break;
       }
   } while (ch != 0);
}
//Sorting Ends here


void mainmenu() {
    int ch;
    do {
        cout<<"1. Addition of New Record\n"
        <<"2. Deletion of Existing Record\n"
        <<"3. Modification of Records\n"
        <<"4. Search for Particular Record\n"
        <<"5. Sort Records\n"
        <<"6. Generate Reports\n\n"
        <<"0. Exit\n\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch) {
            case 1: addrecord(); break;
            case 2: deleterecord(); break;
            case 3: modifyrecord(); break;
            case 4: searchmenu(); break;
            case 5: sortmenu(); break;
            case 6: reportnew(); break;
        }
    } while (ch != 0);
}

void main() {
    clrscr();
    mainmenu();
    getch();
}
