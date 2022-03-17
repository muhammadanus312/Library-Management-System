#ifndef CLASS_faculty
#define CLASS_faculty
#include"member.h"
using namespace std;
void gotoxy(short x,short y);
class faculty: virtual public member
{
	protected:
	int faculty_id;
	public:
		
	void set()
	{
		int a,flag=0;
		ifstream fac_in;
		ofstream fac_out;
		fac_in.open("fac.txt",ios::app);
		fac_out.open("fac.txt",ios::app);
		fflush(stdin);
		gotoxy(40,14);
		cout<<"ENTER  FACULTY-ID: ";
		cin>>faculty_id;
		
		while(!fac_in.eof())
		{
			fac_in>>name>>a>>address>>phone_no>>department;
			if(a==faculty_id)
			{
				flag=1;
			}
			else
			{
				continue;
			}
		}
		if(flag!=1)
		{
			fflush(stdin);
			gotoxy(40,15);
			cout<<"ENTER NAME OF FACULTY MEMBER: ";
			getline(cin,name);
			gotoxy(40,16);
			cout<<"ENTER ADDRESS: ";
			fflush(stdin);
			getline(cin,address);
			gotoxy(40,17);
				while(1)
							{
							       try{
						cout<<"\n\t\t\t\t\tENTER PHONE NUMBER(11 digits): ";
						cin>>phone_no;
						if(phone_no.length()!=11)
						{
							throw -1;
						}
						break;
						
					}
					catch(int x)
					{
						int a;
						cout<<"\n\t\tERROR!!!!!: MAXIMUM DIGITS ARE 11";
					}
				}
			cout<<"\n\t\t\t\t\tENTER DEPARTMENT: ";
			fflush(stdin);
			getline(cin,department);
	
			fac_out<<name<<"\t\t"<<faculty_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<endl;
			cout<<"\n\n\t\tfaculty member successfully added...";		
		}
		else
		{
			cout<<"\n\n\n\n\t\t\tTHIS ID FACULTY MEMEBER ALREADY ADDED...";
		}
		
	    
	    fac_out.close();
	    fac_in.close();
	    cout<<"\n\n\n\n\t\tpress any key for go to mainmenu.....";
	    getch();
	    system("cls");
	    mainmenu();
	}
	void show()
	{
		char buff[100];
		ifstream fac_in;
		fac_in.open("fac.txt",ios::app);
		cout<<"\n\n\tS.NO\t\t"<<"NAME\t\t"<<"FAC_ID\t\t"<<"ADDRESs\t\t"<<"MOB.NO\t\t"<<"DEP"<<endl<<endl;
	/*	for(int i=1;!fac_in.eof();i++)
		{
			fac_in.getline(buff,sizeof(buff));
			cout<<i<<"\t\t"<<buff<<endl;
		}*/
		for(int i=1;fac_in>>name>>faculty_id>>address>>phone_no>>department;i++)
		{
			
			cout<<"\t"<<i<<"\t\t"<<name<<"\t\t"<<faculty_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<endl<<endl;
		}
		fac_in.close();
		back();
	}
	void search()
	{
		int id,i;
		char buff[200];
		ifstream fac_in;
		fac_in.open("fac.txt",ios::app);
		gotoxy(35,10);
		cout<<"ENTER FACULTY_ID: ";
		cin>>id;
		int flag;
		for( i=1;fac_in>>name>>faculty_id>>address>>phone_no>>department;i++)
		{
			if(id==faculty_id)
			{
				flag=0;
				system("color 0a");
                cout<<"\n\n\n\t\t\t\t\t-----------SEARCHING THE DATA-------------\n\n";
                char a=177, b=219;
                cout<<"\t\t\t\t";
                cout<<"\r";
                cout<<"\t\t\t\t";
                for ( i=0;i<=35;i++)
                {
                     cout<<b;
                    Sleep(50);
                }
                system("cls");
				cout<<"\n\n\n\n\t"<<"NAME\t\t"<<"FAC_ID\t\t"<<"ADDRESs\t\t"<<"MOB.NO\t\t"<<"DEP"<<endl<<endl;
			    cout<<"\t"<<name<<"\t\t"<<faculty_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<endl;	
			    break;
			}
			else
			{
				flag=1;
			}
			
	   }
	   if(flag==1)
		{
				gotoxy(35,18);
			    cout<<"FACULTY MEMBER NOT FOUND!!";
	    }   
		fac_in.close();
		back();		
}
	void show_faculty_data()
	{
		string check_id;
		int opt;
		gotoxy(45,14);
		cout<<"1.Show all faculty_ members";
		gotoxy(45,16);
		cout<<"2.Search a faculty_member";
		gotoxy(45,18);
		cout<<"ENTER YOUR CHOICE";
		cin>>opt;
		system("cls");
		switch(opt)
		{
			case 1:
				show();
				break;
			case 2:
				search();
				break;
			
			default:
			{
				cout<<"\n\n\t\tplease enter a valid number:";
				cout<<"\n\n\t\tpress any key for going back.......";
				system("cls");
				show_faculty_data();
			}	
		}
}
void delete_member()
	{
		int c;
		gotoxy(35,10);
		cout<<"Enter faculty id to remove";
		cin>>c;
		ifstream fac_in;
		fac_in.open("fac.txt");
		ofstream e;
		e.open("new.txt");
		int flag=0;	
	while(fac_in>>name>>faculty_id>>address>>phone_no>>department)
	{
		if(faculty_id!=c)
		{
	
			e<<name<<"\t\t";
			e<<faculty_id<<"\t\t";
			e<<address<<"\t\t";
			e<<phone_no<<"\t\t";
	        e<<department<<endl;
		}
		else
		{
			flag=1;
		    system("color 0a");
            cout<<"\n\n\n\t\t\t\tPlease wait while record is deleting\n\n";
            char a=177, b=219;
            cout<<"\t\t\t\t";
            cout<<"\r";
            cout<<"\t\t\t\t";
            for (int i=0;i<=25;i++)
            {
 	            Sleep(200);
                cout<<b;
            }
				gotoxy(35,18);
				cout<<endl<<"MEMBER RECORD HAS BEEN DELTED SUCCESSFULLY";	
		}
	}
	if(flag!=1)
	{
		gotoxy(35,18);
		cout<<"STUDENT NOT FOUND!!";
	}
	
	e.close();
	fac_in.close();
	remove("fac.txt");
	rename("new.txt","fac.txt");
	back2();
	}
	void update_member()
	{
		int c;
		gotoxy(35,10);
		cout<<"Enter faculty id to update: ";
		cin>>c;
		ifstream fac_in;
		fac_in.open("fac.txt");
		ofstream e;
		e.open("new.txt");
		int flag=0;	
	while(fac_in>>name>>faculty_id>>address>>phone_no>>department)
	{
		if(faculty_id==c)
		{
			flag=1;
			gotoxy(40,15);
			fflush(stdin);
			cout<<"ENTER NAME OF FACULTY MEMBER: ";
			getline(cin,name);
			gotoxy(40,16);
			cout<<"ENTER ADDRESS: ";
			fflush(stdin);
			getline(cin,address);
			gotoxy(40,17);
			while(1)
							{
							       try{
						cout<<"\n\t\t\t\t\tENTER PHONE NUMBER(11 digits): ";
						cin>>phone_no;
						if(phone_no.length()!=11)
						{
							throw -1;
						}
						break;
						
					}
					catch(int x)
					{
						int a;
						cout<<"\n\t\tERROR!!!!!: MAXIMUM DIGITS ARE 11";
					}
				}
		
			cout<<"\n\t\t\t\t\tENTER DEPARTMENT: ";
			fflush(stdin);
			getline(cin,department);
			
			e<<name<<"\t\t";
			e<<faculty_id<<"\t\t";
			e<<address<<"\t\t";
			e<<phone_no<<"\t\t";
	        e<<department<<endl;
		}
		else
		{
			e<<name<<"\t\t";
			e<<faculty_id<<"\t\t";
			e<<address<<"\t\t";
			e<<phone_no<<"\t\t";
	        e<<department<<endl;
		}
	}
	if(flag!=1)
	{
		gotoxy(35,18);
		cout<<"FACULTY_ID NOT FOUND!!";
	}
	else
	{
		gotoxy(35,25);
		cout<<"RECORD SUCCESSFULLY UPDATED!!";
	}
	e.close();
	fac_in.close();
	remove("fac.txt");
	rename("new.txt","fac.txt");
	back2();
	}
	private:		
void back()
{
	int a;
	cout<<"\n\n\t\t\tpress '1' for go to back , press '2' for mainmenu , press '3' for exit : ";
	cin>>a;
	if(a==1)
	{
		system("cls");
		show_faculty_data();
	}
	else if(a==2)
	{
		system("cls");
		mainmenu();
	}
	else if(a==3)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number.......";
		back();
	}
}	
void back2()
{
	int a;
	cout<<"\n\n\t\t\tpress '1' for mainmenu , press '2' for exit : ";
	cin>>a;
	if(a==1)
	{
		system("cls");
		mainmenu();
	}
	else if(a==2)
	exit(1);
	else
	{
		cout<<"\n\n\t\tplease enter a valid number.......";
		back2();
	}
}	
};
#endif
