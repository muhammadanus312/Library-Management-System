/***OOP PROJECT***/

#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include"gotoxy.h"
#include"book.h"
#include"admin.h"
#include"member.h"
#include"student.h"
#include"faculty.h"
#include"transition.h"
//#include"mainmenu.h"
using namespace std;
void mainmenu()
{
	int option,opt;
	admin a1;
	book b1;
	student s1;
	faculty f1;
	transition t1;
	time_t t;
    time (&t);
    gotoxy(50,7);
    cout<<asctime(localtime(&t));
	gotoxy(38,9);
	cout<<"********LIBRARY MANAGEMENT SYSTEM********";
	gotoxy(45,13);
	cout<<"MAINMENU: ";
	gotoxy(45,15);
	cout<<"1. ADD NEW BOOK";
	gotoxy(45,17);
	cout<<"2. ADD NEW MEMBER";
	gotoxy(45,19);
	cout<<"3. UPDATE BOOK RECORD";
	gotoxy(45,21);
	cout<<"4. UPDATE MEMBER RECORD";
	gotoxy(45,23);
	cout<<"5. REMOVE A BOOK";
	gotoxy(45,25);
	cout<<"6. REMOVE A MEMBER";
	gotoxy(45,27);
	cout<<"7. VIEW MEMBER ACCOUNT";
	gotoxy(45,29);
	cout<<"8. VIEW STOCK OF BOOK";
	gotoxy(45,31);
	cout<<"9. ISSUE A BOOK";
	gotoxy(45,33);
	cout<<"10. DEPOSIT A BOOK";
	gotoxy(45,35);
	cout<<"11. LIST OF BOOK ISSUED";
	gotoxy(45,37);
	cout<<"12. CHANGE ADMIN ACOUNT";
	gotoxy(45,39);
	cout<<"13. EXIT";
	gotoxy(45,41);
	cout<<"ENTER YOUR CHOICE:";
	cin>>option;
	system("cls");
	switch(option)
	{
		case 1:
			b1.set_book();
			break;
		
		case 2:
			t1.add_member();
			break;	
			
	    case 3:
	    	b1.update_book();
	    	break;
		
		case 4:
			t1.update_member_data();
			break;
			
	
		case 5:
			b1.remove_book();
			break;
			
        case 6:
		t1.delete_member_data();
		break;
		case 7:
		t1.show_all_member_data();
		break;
		
		case 8:
			b1.view_stock_of_book();
			break;
			
		case 9:
		t1.issue_book();
		break;
			
		case 10:
		t1.deposit_book();
		break;
	   case 11:
	    t1.list_book_issue();
		break;
		case 12:
			a1.set_admin();
			break;
		case 13:
		exit(1);		
		default:
		{
			cout<<"\n\n\t\tplease enter a valid number:";
			cout<<"\n\n\t\tpress any key for going back.......";
		    system("cls");
			mainmenu();
				    
		}		
		
}

}
int main()
{
	int opt;
	admin a1;
	time_t t;
   time (&t);
   gotoxy(50,5);
   cout<<asctime(localtime(&t));
	gotoxy(30,7);
	cout<<"**WELCOME TO FAST NUCESS LIBRARY MANAGEMENT SYSTEM**";
	gotoxy(50,9);
	cout<<"*KARACHI CAMPUS*";
	gotoxy(40,16);
	cout<<"LOGIN ADMIN ACCOUNT";
	a1.check_admin();
   mainmenu();	


}
