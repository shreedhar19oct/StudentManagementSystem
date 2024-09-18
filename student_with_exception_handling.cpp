#include<iostream>
#include<string>
#include<conio.h>
#include<stdexcept> // For exception handling
#include<limits>    // For numeric limits

using namespace std;

int i = 0;

struct Student {
    int id;
    float marks[5], per;
    string name, grade;
}s[25];

void insert() {
    system("cls");
    cout << "\n\n\t\t\t *** INSERT RECORD ***";
    try {
        cout << "\n\n Enter Student Id: ";
        if (!(cin >> s[i].id)) {
            throw invalid_argument("Invalid input for Student ID. Please enter an integer.");
        }
        

        cout << "\n\n Enter Student Name: ";
        cin >> s[i].name;

        cout << "\n\n Enter Student Marks (0-100): ";
        for(int a=0;a<5;a++){
        	cout<<"\n\n Enter subject-"<<a+1<<" Marks: ";
        	if (!(cin >> s[i].marks[a]) || s[i].marks[a] < 0 || s[i].marks[a] > 100) {
            	throw out_of_range("Marks must be a number between 0 and 100.");
        	}	
		}
        

        s[i].per = ((s[i].marks[0]+s[i].marks[1]+s[i].marks[2]+s[i].marks[3]+
					s[i].marks[4])/500)*100;  

        if (s[i].per >= 90)
            s[i].grade = "A+";
        else if (s[i].per >= 80)
            s[i].grade = "A";
        else if (s[i].per >= 70)
            s[i].grade = "B+";
        else if (s[i].per >= 60)
            s[i].grade = "B";
        else if (s[i].per >= 50)
            s[i].grade = "C";
        else
            s[i].grade = "F";

        cout << "\n\n *** Insert Record Successfully ***";
        i++;
    }
    catch (const exception& e) {
        cerr << "\nError: " << e.what() << "\n";
    }
}

void search() {
    system("cls");
    cout << "\n\n\t\t\t *** SEARCH RECORD ***";
    if (i == 0) {
        cout << "\n\n *** No Record Found ***";
    }
    else {
        int id, found = 0;
        try {
            cout << "\n\n Enter Student Id: ";
            if (!(cin >> id)) {
                throw invalid_argument("Invalid input for Student ID. Please enter an integer.");
            }

            for (int a = 0; a < i; a++) {
                if (id == s[a].id) {
                    cout << "\n\n Congratulations Student Found";
                    cout << "\n\n Student Name: " << s[a].name;
                    for(int b=0;b<5;b++){
                    	cout << "\n\n Student Marks in Subject"<<b+1<<" : "<<s[a].marks[b];
					}
                    
                    cout << "\n\n Student Percentage: " << s[a].per << "%";
                    cout << "\n\n Student Grade: " << s[a].grade;
                    found++;
                }
            }
            if (found == 0)
                cout << "\n\n *** Sorry no Student found with this Student ID ***";
        }
        catch (const exception& e) {
            cerr << "\nError: " << e.what() << "\n";
        }
    }
}

void update() {
    system("cls");
    cout << "\n\n\t\t\t *** UPDATE RECORD ***";
    if (i == 0) {
        cout << "\n\n *** No Record Found ***";
    }
    else {
        int id, found = 0;
        try {
            cout << "\n\n Enter Student Id: ";
            if (!(cin >> id)) {
                throw invalid_argument("Invalid input for Student ID. Please enter an integer.");
            }

            for (int a = 0; a < i; a++) {
                if (id == s[a].id) {
                    cout << "\n\n Congratulations Student Found with this ID";
                    cout << "\n\n Enter Details to be updated";
                    cout << "\n\n Enter Student Name: ";
                    cin >> s[a].name;

                    cout << "\n\n Enter Student Marks (0-100): ";
                    for(int b=0;b<5;b++){
        				cout<<"\n\n Enter subject-"<<b+1<<" Marks: ";
        				if (!(cin >> s[a].marks[b]) || s[a].marks[b] < 0 || s[a].marks[b] > 100) {
            				throw out_of_range("Marks must be a number between 0 and 100.");
        				}	
					}

                    s[a].per = ((s[a].marks[0]+s[a].marks[1]+s[a].marks[2]+s[a].marks[3]+
					s[a].marks[4])/500)*100;

                    if (s[a].per >= 90)
                        s[a].grade = "A+";
                    else if (s[a].per >= 80)
                        s[a].grade = "A";
                    else if (s[a].per >= 70)
                        s[a].grade = "B+";
                    else if (s[a].per >= 60)
                        s[a].grade = "B";
                    else if (s[a].per >= 50)
                        s[a].grade = "C";
                    else
                        s[a].grade = "F";

                    cout << "\n\n ** Update Record Successfully ***";
                    found++;
                }
            }
            if (found == 0)
                cout << "\n\n *** Sorry no Student found with this Student ID ***";
        }
        catch (const exception& e) {
            cerr << "\nError: " << e.what() << "\n";
        }
    }
}

void del() {
    system("cls");
    cout << "\n\n\t\t\t *** DELETE RECORD ***";
    if (i == 0) {
        cout << "\n\n *** No Record Found ***";
    }
    else {
        int id, found = 0;
        try {
            cout << "\n\n Enter Student Id: ";
            if (!(cin >> id)) {
                throw invalid_argument("Invalid input for Student ID. Please enter an integer.");
            }

            for (int a = 0; a < i; a++) {
                if (id == s[a].id) {
                    for (int m = a; m < i - 1; m++) {
                        s[m].id = s[m + 1].id;
                        s[m].name = s[m + 1].name;
                        for(int b=0;b<5;b++){
                    		s[m].marks[b]=s[m+1].marks[b];
						}
                        s[m].per = s[m + 1].per;
                        s[m].grade = s[m + 1].grade;
                    }
                    cout << "\n\n *** Delete Record Successfully ***";
                    found++;
                    i--;
                    break;
                }
            }
            if (found == 0)
                cout << "\n\n *** Sorry no Student found with this Student ID ***";
        }
        catch (const exception& e) {
            cerr << "\nError: " << e.what() << "\n";
        }
    }
}

void show() {
	system("cls");
    cout << "\n\n\t\t\t *** SHOW ALL RECORD ***";
    if (i == 0) {
        cout << "\n\n *** No Record Found ***";
    }
    else {
        for (int a = 0; a < i; a++) {
            cout << "\n\n Student Id: " << s[a].id;
            cout << "\n\n Student Name: " << s[a].name;
            for(int b=0;b<5;b++){
                cout << "\n\n Student Marks in Subject"<<b+1<<" : "<<s[a].marks[b];
			}
            cout << "\n\n Student Percentage: " << s[a].per <<"%";
            cout << "\n\n Student Grade: " << s[a].grade;
            cout << "\n\n *******************************";
        }
    }
}

int main() {
    p:
    system("cls");

    int choice;
    cout << "\n\n\t\t\t*** STUDENT MANAGEMENT SYSTEM ***";
    cout << "\n\n 1. Insert Record";
    cout << "\n\n 2. Search Record";
    cout << "\n\n 3. Update Record";
    cout << "\n\n 4. Delete Record";
    cout << "\n\n 5. Show Record";
    cout << "\n\n 6. Exit";
    cout << "\n\n Enter your Choice -> ";
    cin>>choice;  
        

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            show();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n *** Invalid Choice ***";
        }
        cout << "\n\n\n Press any key to continue...";
        getch();
        goto p;
}

