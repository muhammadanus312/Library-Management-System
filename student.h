#ifndef CLASS_student
#define CLASS_student
#include"member.h"
void gotoxy(short x,short y);
using namespace std;
class student: virtual public member
{
	protected:
	int student_id;
	int currentsemester;
	string batch;
	public:
	void search()
	{
		char buff[200];int i,a,id;
		ifstream stu_in;
		stu_in.open("stu.txt",ios::app);
		gotoxy(35,10);
		cout<<"ENTER STUDENT_ID";
		cin>>id;
		int flag;
		for( i=1;stu_in>>name>>student_id>>address>>phone_no>>department>>currentsemester;i++)
		{
		    if(id==student_id)
		    {
		    	flag=0;
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
            cout<<"\n\n\tNAME\t\t"<<"STU_ID\t\t"<<"ADDRESs\t\t"<<"MOB.NO\t\t"<<"DEP\t\t"<<"CURRENT_SEM"<<endl<<endl;
		    	
		    cout<<"\t"<<name<<"\t\t"<<student_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<"\t\t"<<currentsemester<<endl;
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
			    cout<<"STUDENT NOT FOUND!!";
	    }   
		stu_in.close();
		back();
			
		
		
	}
	void set()
	{
		int a,flag=0;
		ifstream stu_in;
		ofstream stu_out;
		stu_in.open("stu.txt",ios::app);
		stu_out.open("stu.txt",ios::app);
		gotoxy(40,14);
		cout<<"ENTER  STUDENT-ID: ";
		cin>>student_id;
		while(!stu_in.eof())
		{
			stu_in>>name>>a>>address>>phone_no>>department>>currentsemester;
			if(a==student_id)
			{
				flag=1;
			}
			else
			{
				//cout<<"helo";
				continue;
			}
		}
		if(flag!=1)
		{
			fflush(stdin);
			gotoxy(40,15);
			cout<<"ENTER NAME OF STUDENT: ";
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

		
			cout<<"\t\t\t\t\tENTER DEPARTMENT: ";
			fflush(stdin);
			getline(cin,department);
			gotoxy(40,22);
			cout<<"\n\t\t\t\t\tENTER NO OF CURRENT SEMESTER:";
			cin>>currentsemester;
			stu_out<<name<<"\t\t"<<student_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<"\t\t"<<currentsemester<<endl;
		    cout<<"\n\n\t\tstudent member successfully added...";
		}
		else
		{
			cout<<"\n\n\n\n\t\t\tTHIS ID STUDENT ALREADY ADDED....";
		}
		
		 stu_out.close();
		 stu_in.close();
	    cout<<"\n\n\n\n\t\tpress any key for go to mainmenu.....";
	    getch();
	    system("cls");
	    mainmenu();
	}
	void show()
	{
		char buff[200];int i;
		ifstream stu_in;
		stu_in.open("stu.txt",ios::app);
		cout<<"\n\n\tS.NO\t\t"<<"NAME\t\t"<<"STU_ID\t\t"<<"ADDRESs\t\t"<<"MOB.NO\t\t"<<"DEP\t\t"<<"CURRENT_SEM\t"<<endl<<endl;
	//	for(int i=1;!stu_in.eof();i++)
	//	{
	//		stu_in.getline(buff,sizeof(buff));
	//		cout<<i<<"\t\t"<<buff<<endl;
	//	}
		for(int i=1;stu_in>>name>>student_id>>address>>phone_no>>department>>currentsemester;i++)
		{
		
			cout<<"\t"<<i<<"\t\t"<<name<<"\t\t"<<student_id<<"\t\t"<<address<<"\t\t"<<phone_no<<"\t"<<department<<"\t\t"<<currentsemester<<endl<<endl;
		}
		stu_in.close();
		back();
	}
	
	void show_student_data()
	{
		string check_id;
		int opt;
		gotoxy(45,14);
		cout<<"1.Show all students";
		gotoxy(45,16);
		cout<<"2.search student";
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
				show_student_data();
			}	

		}
		
	}
	void delete_member()
	{
		int c,i;
		gotoxy(35,10);
		cout<<"Enter Student id to remove: ";
		cin>>c;
		ifstream stu_in;
		stu_in.open("stu.txt",ios::app);
		ofstream e;
		e.open("temp.txt");
	
			
		int flag=0;
		while(stu_in>>name>>student_id>>address>>phone_no>>department>>currentsemester)
		{
		
			if(c!=student_id)
			{
		
				e<<name<<"\t\t";
				e<<student_id<<"\t\t";
				e<<address<<"\t\t";
				e<<phone_no<<"\t\t";
				e<<department<<"\t\t";
				e<<currentsemester<<endl;
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
		        for( i=0;i<=25;i++)
		        {
		            cout<<b;
		            Sleep(200);
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
	stu_in.close();
	remove("stu.txt");
	rename("temp.txt","stu.txt");
	back2();
	}
	void update_member()
	{
		int c;
		gotoxy(35,10);
		cout<<"Enter Student id to update: ";
		cin>>c;
		ifstream stu_in;
		stu_in.open("stu.txt",ios::app);
		ofstream e;
		e.open("temp.txt");
	
			
		int flag=0;
		while(stu_in>>name>>student_id>>address>>phone_no>>department>>currentsemester)
		{
		
			if(c==student_id)
			{
				flag=1;
				fflush(stdin);
				gotoxy(40,15);
				cout<<"ENTER NAME OF STUDENT: ";
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
				cout<<"\n\t\t\t\t\tENTER NO OF CURRENT SEMESTER:";
				cin>>currentsemester;
				
				e<<name<<"\t\t";
				e<<student_id<<"\t\t";
				e<<address<<"\t\t";
				e<<phone_no<<"\t\t";
				e<<department<<"\t\t";
				e<<currentsemester<<endl;
			}
			else
			{
				e<<name<<"\t\t";
				e<<student_id<<"\t\t";
				e<<address<<"\t\t";
				e<<phone_no<<"\t\t";
				e<<department<<"\t\t";
				e<<currentsemester<<endl;
			}
    	}	
	if(flag!=1)
	{
		gotoxy(35,18);
		cout<<"STUDENT NOT FOUND!!";
	}
	else
	{
			gotoxy(35,25);
			cout<<"RECORD SUCCESFULLY UPDATED!!";
		
	}
	
	e.close();
	stu_in.close();
	remove("stu.txt");
	rename("temp.txt","stu.txt");
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
		show_student_data();
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
