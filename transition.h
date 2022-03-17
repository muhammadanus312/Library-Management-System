#ifndef CLASS_transition
#define CLASS_transition
#include"student.h"
#include"faculty.h"
#include"book.h"
using namespace std;
void gotoxy(short x,short y);
class transition:public student,public faculty,public book
{
	string due_date;
	string issue_date;
	public:
		//friend void mainmenu();
		void show_all_member_data()
		{
			student s1;
			faculty f1;
			int opt;
			gotoxy(45,14);
				cout<<"1. STUDENT";
				gotoxy(45,16);
				cout<<"2. FACULTY";
				gotoxy(45,18);
				cout<<"select:";
				cin>>opt;
				system("cls");
				switch(opt)
				{
					case 1:
						s1.show_student_data();
						break;
					case 2:
						f1.show_faculty_data();
						break;
						
					default:
					{
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
					system("cls");
					show_all_member_data();
					}	
				}
    	}
		void add_member()
		{
			student s1;
			faculty f1;
			int opt;
			gotoxy(45,14);
				cout<<"1. STUDENT";
				gotoxy(45,16);
				cout<<"2. FACULTY";
				gotoxy(45,18);
				cout<<"select:";
				cin>>opt;
				system("cls");
				switch(opt)
				{
					case 1:
						s1.set();
						break;
					case 2:
						f1.set();
						break;
					default:
					{
						cout<<"\n\n\t\tplease enter a valid number:";
					    cout<<"\n\n\t\tpress any key for going back.......";
					    system("cls");
					    add_member();
					}	
				}
		}
		void update_member_data()
		{
			student s1;
			faculty f1;
			int opt;
			gotoxy(45,14);
				cout<<"1. STUDENT";
				gotoxy(45,16);
				cout<<"2. FACULTY";
				gotoxy(45,18);
				cout<<"select:";
				cin>>opt;
				system("cls");
				switch(opt)
				{
					case 1:
						s1.update_member();
						break;
					case 2:
						f1.update_member();
						break;
					
					default:
					{
						cout<<"\n\n\t\tplease enter a valid number:";
					    cout<<"\n\n\t\tpress any key for again enter.......";
					    system("cls");
					    update_member_data();
		            }
               	}
	 	}
		void delete_member_data()
		{
			student s1;
			faculty f1;
			int opt;
			gotoxy(45,14);
				cout<<"1. STUDENT";
				gotoxy(45,16);
				cout<<"2. FACULTY";
				gotoxy(45,18);
				cout<<"select:";
				cin>>opt;
				system("cls");
				switch(opt)
				{
					case 1:
						s1.delete_member();
						break;
					case 2:
						f1.delete_member();
						break;
					
					default:
					{
						cout<<"\n\n\t\tplease enter a valid number:";
					    cout<<"\n\n\t\tpress any key for again enter.......";
					    system("cls");
					    delete_member_data();
		            }
               	}
	 	}
	 	
	 		
	 	void issue_student()
	 	{
	 		string m,n;
	 		int a,b,flag1,flag3,flag2;
	 		gotoxy(35,10);
			 cout<<"ENTER ISBN OF BOOK: ";
	 		cin>>a;
	 		ifstream bookin;
	 		ifstream stu_in;
	 		ofstream stu_issue_out;
	 		ifstream stu_issue_in;
	 		stu_issue_out.open("stu_issue.txt",ios::app);
	 		stu_issue_in.open("stu_issue.txt",ios::app);
	 		bookin.open("book.txt",ios::app);
	 		while(!bookin.eof())
	 		{
	 			bookin>>isbn>>title>>author>>quantity>>category;
	 			if(isbn==a)
	 			{
	 				flag3=0;
	 				if(quantity<1)
	 				{
	 					gotoxy(35,18);
	 					cout<<"book is out of stock!!!!";
	 					break;
					 }
	 				gotoxy(35,12);
	 				cout<<"ENTER STUDENT ID: ";
	 				cin>>b;
	 				stu_in.open("stu.txt",ios::app);
	 				while(!stu_in.eof())
	 				{
	 					stu_in>>name>>student_id>>address>>phone_no>>department>>currentsemester;
	 					if(student_id==b)
	 					{
	 						m=title;
	 						n=name;
	 						flag1=1;
	 						break;
	 					}
	 					else
	 					{
	 						flag1=0;
	 					}
	 				}
	 				
	 				if(flag1==1)
	 				{
	 					flag2=0;
	 					while(!stu_issue_in.eof())
	 					{
	 						stu_issue_in>>student_id>>name>>title>>isbn>>due_date;
	 						if(b==student_id)
	 						{
	 							
	 							flag2=flag2+1;
							}
						}
						if(flag2<4)
						{
							
							fflush(stdin);
							gotoxy(35,14);
								while(1)
							{
				         	try{
							cout<<"ENTER DATE OF RETURN(dd-mm-yy)";
							getline(cin,due_date);
							if(due_date[0]<='3'&&due_date[1]<'10'&&due_date[2]=='-'&&due_date[3]<='1'&&due_date[4]<'12'&&due_date[5]=='-'&&due_date[6]<'10'&&due_date[7]<'10')
							{
								if(due_date[0]=='3'&&due_date[1]>='2'||due_date[3]=='1'&&due_date[4]>'2')
								{
									throw -1;
								}
							stu_issue_out<<b<<"\t\t"<<n<<"\t\t"<<m<<"\t\t"<<a<<"\t\t"<<due_date<<endl;
							break;
						}
						else
						{
							throw -1;
						}
					}
					catch(...)
					{
						cout<<"\nERROR PLEASE ENTER DATE IN CORRET FORMAT I.E(dd-mm-yy)"<<endl;
					}
				}			
							cout<<"\n\n\t\t\tBOOK SUCCESSFULLY ISSUED!!";
							book b1;
							b1.operator--(a);
						}
						else
						{
							gotoxy(25,18);
							cout<<"THIS STUDENT ALREADY ISSUE A 3 BOOK SO FIRST HE DEPOSIT ANYONE THEN ISSUE A OTHER BOOK";
							break;
						}
					}
					else
					{
						gotoxy(35,18);
						cout<<"STUDENT NOT FOUND!!";
					}
					break;
	 			}
	 			else
	 			{
	 				flag3=1;
	 				//cout<<"BOOK NOT FOUND";
	 				
				}
	 		}
	 		if(flag3==1)
	 		{
	 			gotoxy(35,18);
	 			cout<<"BOOK NOT FOUND";
	 		}
	 		bookin.close();
	 		stu_in.close();
	 		stu_issue_in.close();
	 		stu_issue_out.close();
	 		if(flag3!=1&&flag1==1&&flag2<=2)
	 		{
			 
			remove("book.txt");
	  		rename("new.txt","book.txt");
	  	}
	  	int d;
		  back(d);	
	 	}
	 	void issue_faculty()
	 	{
	 		string m,n;
	 		int a,b,flag1,flag3,flag2=0;
	 		gotoxy(35,10);
			 cout<<"ENTER ISBN OF BOOK: ";
	 		cin>>a;
	 		ifstream bookin;
	 		ifstream fac_in;
	 		ofstream fac_issue_out;
	 		ifstream fac_issue_in;
	 		fac_issue_out.open("fac_issue.txt",ios::app);
	 		fac_issue_in.open("fac_issue.txt",ios::app);
	 		bookin.open("book.txt",ios::app);
	 		while(!bookin.eof())
	 		{
	 			bookin >> isbn >> title>>author>>quantity>>category;
	 			if(isbn==a)
	 			{
	 				flag3=0;
	 				if(quantity<1)
	 				{
	 					gotoxy(35,18);
	 					cout<<"book is out of stock!!!!";
	 					break;
					 }
	 				gotoxy(35,12);
	 				cout<<"ENTER FACULTY ID: ";
	 				cin>>b;
	 				fac_in.open("fac.txt",ios::app);
	 				while(!fac_in.eof())
	 				{
	 					fac_in>>name>>faculty_id>>address>>phone_no>>department;
	 					if(faculty_id==b)
	 					{
	 						m=title;
	 						n=name;
	 						flag1=1;
	 						break;
	 					}
	 					else
	 					{
	 						flag1=0;
	 					}
	 				}
	 				
	 				if(flag1==1)
	 				{
	 					flag2=0;
	 					while(!fac_issue_in.eof())
	 					{
	 						fac_issue_in>>faculty_id>>name>>title>>isbn>>due_date;
	 						if(b==faculty_id)
	 						{
	 							
	 							flag2=flag2+1;
							}
						}
						if(flag2<4)
						{
							
							fflush(stdin);
							gotoxy(35,14);
						//	cout<<"ENTER DATE OF RETURN(dd-mm-yy)";
						//	cin>>due_date;
							while(1)
							{
				         	try{
							cout<<"ENTER DATE OF RETURN(dd-mm-yy)";
							getline(cin,due_date);
							if(due_date[0]<='3'&&due_date[1]<'10'&&due_date[2]=='-'&&due_date[3]<='1'&&due_date[4]<'12'&&due_date[3]&&due_date[5]=='-'&&due_date[6]<'10'&&due_date[7]<'10')
							{
								if(due_date[0]=='3'&&due_date[1]>='2'||due_date[3]=='1'&&due_date[4]>'2')
								{
									throw -1;
								}
							fac_issue_out<<b<<"\t\t"<<n<<"\t\t"<<m<<"\t\t"<<a<<"\t\t"<<due_date<<endl;
							break;
						}
						else
						{
							throw -1;
						}
					}
					catch(...)
					{
						
						cout<<"\nERROR PLEASE ENTER DATE IN CORRET FORMAT I.E(dd-mm-yy)"<<endl;
					}
				}
							cout<<"\n\n\t\t\tBOOK SUCCESSFULLY ISSUED......";
							book b1;
							b1.operator--(a);
						}
						else
						{
							gotoxy(25,18);
							cout<<"THIS FACULTY MEMBER ALREADY ISSUE A 3 BOOK SO FIRST HE DEPOSIT ANYONE THEN ISSUE A OTHER BOOK";
							break;
						}
					}
					else
					{
						gotoxy(35,18);
						cout<<"FACULTY MEMBER NOT FOUND!!";
					}
					break;
	 			}
	 			else
	 			{
	 				flag3=1;
	 				//cout<<"BOOK NOT FOUND";
	 				
				}
	 		}
	 		if(flag3==1)
	 		{
	 			gotoxy(35,18);
	 			cout<<"BOOK NOT FOUND";
	 		}
	 		bookin.close();
	 		fac_in.close();
	 		fac_issue_in.close();
	 		fac_issue_out.close();
	 		if(flag3!=1&&flag1==1&&flag2<=2)
	 		{
			 
			remove("book.txt");
	  		rename("new.txt","book.txt");
	  	    }
	  	    float d;
		  back(d);	
	 	}
	 	void deposit_student()
	 	{
	 		int flag=0;
	 		int a,b;
	 		book b1;
	 		ifstream stu_issue_in;
	 		ofstream e;
	 		gotoxy(35,10);
	 		cout<<"ENTER STUDENT ID:";
	 		cin>>a;
	 		gotoxy(35,12);
	 		cout<<"ENTER ISBN OF BOOK: ";
	 		cin>>b;
	 		e.open("newfile.txt",ios::app);
	 		stu_issue_in.open("stu_issue.txt",ios::app);
	 		flag=0;
	 		while(stu_issue_in>>student_id>>name>>title>>isbn>>due_date)
	 		{
	 				if(student_id==a&&isbn==b)
	 				{
	 					flag=1;
	 					gotoxy(35,16);
						cout<<"BOOK HAS SUCCESSFULLY DEPOSIT!!";
						b1.operator++(b);
	 			       
					}
					else 
					{
						 e<<student_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t"<<isbn<<"\t\t"<<due_date<<endl;
					
					}
			}
			 if(flag==0)
				{
					gotoxy(35,16);	
					cout<<"RECORD NOT FOUND!!";
				}
			 
			stu_issue_in.close();
			e.close();
			remove("stu_issue.txt");
			rename("newfile.txt","stu_issue.txt");
			int d;
			back(d,d);
	
		}
		
		void deposit_faculty()
	 	{
	 		int flag=0;
	 		int a,b;
	 		book b1;
	 		ifstream fac_issue_in;
	 		ofstream e;
	 		gotoxy(35,10);
	 		cout<<"ENTER FACULTY ID:";
	 		cin>>a;
	 		gotoxy(35,12);
	 		cout<<"ENTER ISBN OF BOOK: ";
	 		cin>>b;
	 		e.open("newfile.txt",ios::app);
	 		fac_issue_in.open("fac_issue.txt",ios::app);
	 		flag=0;
	 		while(fac_issue_in>>faculty_id>>name>>title>>isbn>>due_date)
	 		{
	 				if(faculty_id==a&&isbn==b)
	 				{
	 					flag=1;
	 					gotoxy(35,16);
						cout<<"BOOK HAS SUCCESSFULLY DEPOSIT!!";
						b1.operator++(b);
	 			       
					}
					else 
					{
						 e<<faculty_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t"<<isbn<<"\t\t"<<due_date<<endl;
						
					}
			}
			 if(flag==0)
				{
					gotoxy(35,16);	
					cout<<"RECORD NOT FOUND!!";
				}
			 
			fac_issue_in.close();
			e.close();
			remove("fac_issue.txt");
			rename("newfile.txt","fac_issue.txt");
			float d;
			back(d,d);
	
		}
	 	void issue_book()
	 	{
	 		int a;
	 		gotoxy(45,14);
	 		cout<<"1.FOR STUDENT";
	 		gotoxy(45,16);
	 		cout<<"2.FOR FACULTY";
	 		gotoxy(45,18);
	 		cout<<"ENTER YOUR CHOICE: ";
	 		cin>>a;
	 		system("cls");
	 		switch(a)
	 		{
	 			case 1:
	 				issue_student();
	 				break;
	 			case 2:
	 				issue_faculty();
	 				break;
	 			default:
				{
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
				    system("cls");
				    issue_book();
				    
			    }	
			}
	 		
		}
		void deposit_book()
	 	{
	 		int a;
	 		gotoxy(45,14);
	 		cout<<"1.FOR STUDENT";
	 		gotoxy(45,16);
	 		cout<<"2.FOR FACULTY";
	 		gotoxy(45,18);
	 		cout<<"ENTER YOUR CHOICE: ";
	 		cin>>a;
	 		system("cls");
	 		switch(a)
	 		{
	 			case 1:
	 				deposit_student();
	 				break;
	 			case 2:
	 				deposit_faculty();
	 				break;
	 			default:
				{
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
				    system("cls");
				    issue_book();
				    
			    }	
			}
	 		
		}
		void list_book_issue()
		{
			student s1;
			faculty f1;
			int opt;
			gotoxy(45,14);
			cout<<"1. LIST OF BOOK ISSUE TO STUDENT";
			gotoxy(45,16);
			cout<<"2. LIST OF BOOK ISSUE TO FACULTY";
			gotoxy(45,18);
			cout<<"select:";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					student_books();
					break;
					
				case 2:
					faculty_books();
					break;
					
				default:
				{
				cout<<"\n\n\t\tplease enter a valid number:";
				cout<<"\n\n\t\tpress any key for going back.......";
				system("cls");
				list_book_issue();
				}	
			}
    	}
    	void faculty_books()
		{
		
			int opt;
			gotoxy(45,14);
			cout<<"1.Show all books issue to faculty_ members";
			gotoxy(45,16);
			cout<<"2.Search ";
			gotoxy(45,18);
			cout<<"ENTER YOUR CHOICE";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					show_faculty_books();
					break;
				case 2:
					search_faculty_books();
					break;
				
				default:
				{
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
					getch();
					system("cls");
					faculty_books();
				}	
		    }
		}
		void student_books()
		{
		
			int opt;
			gotoxy(45,14);
			cout<<"1.Show all books issue to student";
			gotoxy(45,16);
			cout<<"2.Search ";
			gotoxy(45,18);
			cout<<"ENTER YOUR CHOICE";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					show_student_books();
					break;
				case 2:
					search_student_books();
					break;
				
				default:
				{
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
					getch();
					system("cls");
					student_books();
				}	
		    }
		}
		show_student_books()
		{
			ifstream stu_issue_in;
			stu_issue_in.open("stu_issue.txt",ios::app);
			cout<<"\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n\n";
	 		while(stu_issue_in>>student_id>>name>>title>>isbn>>due_date)
	 		{
	 				cout<<"\t"<<student_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
			}
			stu_issue_in.close();
			int d;float f;
			back(d,f);
		}
		show_faculty_books()
		{
			ifstream fac_issue_in;
			fac_issue_in.open("fac_issue.txt",ios::app);
			cout<<"\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n\n";
	 		while(fac_issue_in>>faculty_id>>name>>title>>isbn>>due_date)
	 		{
	 			cout<<"\t"<<faculty_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
			}
			fac_issue_in.close();
			int d;float f;
			back(d,f);
		}
		void search_student_books()
		{
			int opt,a,b;
			ifstream stu_issue_in;
			gotoxy(45,14);
			cout<<"1. Search by ISBN of book";
			gotoxy(45,16);
			cout<<"2. Search by student ID";
			gotoxy(45,18);
			cout<<"Enter your choice: ";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					{
						int flag=0;
						stu_issue_in.open("stu_issue.txt",ios::app);
						cout<<"\n\n\t\tENTER ISBN OF BOOK: ";
						cin>>a;
						cout<<"\n\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n\n";
				 		while(stu_issue_in>>student_id>>name>>title>>isbn>>due_date)
				 		{
				 			if(isbn==a)
				 			{
								 flag=1;
				 				cout<<"\t"<<student_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
				 			}
						}
						if(flag!=1)
						{
							cout<<"\n\n\t\tRECORD NOT FOUND!!";
						}

						stu_issue_in.close();
						int d;float f;
						back(d,f);
					}
				case 2:
					{
						int flag=0;
						stu_issue_in.open("stu_issue.txt",ios::app);
						cout<<"\n\n\t\tENTER ID OF STUDENT ";
						cin>>b;
						cout<<"\n\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n";
				 		while(stu_issue_in>>student_id>>name>>title>>isbn>>due_date)
				 		{
				 			if(student_id==b)
				 			{
								 flag=1;
				 				cout<<"\t"<<student_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
				 			}
						}
						if(flag!=1)
						{
							cout<<"\n\n\t\tRECORD NOT FOUND!!";
						}
						stu_issue_in.close();
						int d;float f;
						back(d,f);
					}
				default:
				{
					cout<<"\n\n\n\t\t\tplease enter a valid number ";
					cout<<"\n\n\t\tpress any key for going back.......";
					getch();
					system("cls");
					search_student_books();
				}	
					
					
			}
		}
		void search_faculty_books()
		{
			int opt,a,b;
			ifstream fac_issue_in;
			gotoxy(45,14);
			cout<<"1. Search by ISBN of book";
			gotoxy(45,16);
			cout<<"2. Search by FACULTY_ID";
			gotoxy(45,18);
			cout<<"Enter your choice: ";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					{
						int flag=0;
						fac_issue_in.open("fac_issue.txt",ios::app);
						cout<<"\n\n\t\tENTER ISBN OF BOOK: ";
						cin>>a;
						system("cls");
						cout<<"\n\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n\n";
				 		while(fac_issue_in>>faculty_id>>name>>title>>isbn>>due_date)
				 		{
				 			if(isbn==a)
				 			{
								 flag=1;
				 				cout<<"\t"<<faculty_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
				 			}
						}
						if(flag!=1)
						{
							cout<<"\n\n\t\tRECORD NOT FOUND!!";
						}
						fac_issue_in.close();
						int d;float f;
						back(d,f);
					}
				case 2:
					{
						int flag=0;
						fac_issue_in.open("fac_issue.txt",ios::app);
						cout<<"\n\n\tENTER ID OF FACULTY_MEMBER ";
						cin>>b;
						cout<<"\n\n\n\tID\t\t"<<"NAME\t\t"<<"BOOK_TITLE\t\t"<<"ISBN\t\t"<<"DUE_DATE\n\n";
				 		while(fac_issue_in>>faculty_id>>name>>title>>isbn>>due_date)
				 		{
				 			if(faculty_id==b)
				 			{
								 flag=1;
				 				cout<<"\t"<<faculty_id<<"\t\t"<<name<<"\t\t"<<title<<"\t\t\t"<<isbn<<"\t\t"<<due_date<<endl<<endl;
				 			}
						}
						if(flag!=1)
						{
							cout<<"\n\n\t\tRECORD NOT FOUND!!";
						}
						fac_issue_in.close();
						int d;float f;
						back(d,f);
					}
				default:
				{
					cout<<"\n\n\n\t\t\tplease enter a valid number ";
					cout<<"\n\n\t\tpress any key for going back.......";
					system("cls");
					search_faculty_books();
				}	
					
					
			}
		}
		private:
					
void back(int b)
{
	int a;
	
	cout<<"\n\n\n\n\n\t\t\tpress '1' for again issue a book to student , press '2' for mainmenu , press '3' for exit : ";
	cin>>a;
	system("cls");
	if(a==1)
	{
		 issue_student();
	}
	else if(a==2)
	{
		
		mainmenu();
	}
	else if(a==3)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number:";
		cout<<"\n\n\t\tpress any key for going back.......";
		system("cls");
		int d;
		back(d);
	}
}
void back(float b)
{
	int a;
	
	cout<<"\n\n\n\n\n\t\t\tpress '1' for again issue a book to faculty member, press '2' for mainmenu , press '3' for exit : ";
	cin>>a;
	system("cls");
	if(a==1)
	{
		 issue_faculty();
	}
	else if(a==2)
	{
		mainmenu();
	}
	else if(a==3)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number:";
		cout<<"\n\n\t\tpress any key for going back.......";
		system("cls");
		float d;
		back(d);
	}
	
}
void back(int b,int c)
{
	int a;
	
	cout<<"\n\n\n\n\n\t\t\tpress '1' for student  deposit a book  , press '2' for mainmenu , press '3' for exit : ";
	cin>>a;
	system("cls");
	if(a==1)
	{
		 deposit_student();
	}
	else if(a==2)
	{
		mainmenu();
	}
	else if(a==3)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number:";
		cout<<"\n\n\t\tpress any key for going back.......";
		system("cls");
		int d;
		back(d,d);
	}
	
}
void back(float b,float c)
{
	int a;
	
	cout<<"\n\n\n\n\n\t\t\tpress '1' for faculty member deposit a book  , press '2' for mainmenu , press '3' for exit : ";
	cin>>a;
	system("cls");
	if(a==1)
	{
		 deposit_faculty();
	}
	else if(a==2)
	{
		mainmenu();
	}
	else if(a==3)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number:";
		cout<<"\n\n\t\tpress any key for going back.......";
		system("cls");
		float d;
		back(d,d);
	}
	
}
void back(int b,float c)
{
	int a;
	
	cout<<"\n\n\n\n\n\t\t\tpress '1'  for mainmenu , press '2' for exit : ";
	cin>>a;
	system("cls");
	if(a==1)
	{
		mainmenu();
	}
	
	else if(a==2)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number:";
		cout<<"\n\n\t\tpress any key for going back.......";
		system("cls");
		int d=1;float f=1.1;
		back(d,f);
	}
	
}
};
#endif
