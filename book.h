#ifndef CLASS_book
#define CLASS_book
void gotoxy(short x,short y);
using namespace std;

void mainmenu();
class book
{
	protected:
	int isbn;
	string title;
	string author;
	int quantity;
	string category;
	public:
		friend void mainmenu();
		void set_book()
		{
			//friend void mainmenu();
			int a,flag=0;
			ofstream bookout;
			ifstream bookin;
			bookin.open("book.txt",ios::app);
			bookout.open("book.txt",ios::app);
			gotoxy(40,14);
		    cout<<"ENTER ISBN NUMBER OF BOOK:";
		    cin>>isbn;
		    while(!bookin.eof())
		    {
		    	bookin >> a >> title>>author>>quantity>>category;
		    	if(a==isbn)
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
			
			    gotoxy(40,16);
			    fflush(stdin);
			    cout<<"ENTER TITLE OF BOOK:";
			    getline(cin,title);
			    gotoxy(40,18);
			    fflush(stdin); 
			    cout<<"ENTER AUTHOR'S NAME:";
			    getline(cin,author);
			    gotoxy(40,20);
			    fflush(stdin);
			    cout<<"ENTER QUANTITY OF BOOK:";
			    cin>>quantity;
			    gotoxy(40,22);
			    fflush(stdin);
			    cout<<"ENTER CATEGORY OF BOOK:";
			    getline(cin,category);
			   	bookout<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<endl;	
				cout<<"\n\n\t\tBOOK SUCCESSFULLY ADDED.......\n\n";
			   
			}
			else
			{
				cout<<"\n\n\n\t\t\t\tThis ISBN book is already added!! ";
				
			}
			bookout.close();
			bookin.close();
			cout<<"\n\n\n\n\t\tpress any key for go to mainemnu..";
			getch();
		    system("cls");
		    //public:
		    mainmenu();
			
			   
		   
}
		
		void show_allbooks()
		{
			int i;
		
			char buff[100];
			ifstream bookin;
			bookin.open("book.txt",ios::app);
			
			cout<<"\n\tS.NO\t\tISBN\t\t"<<"TITLE\t\t"<<"AUTHOR\t\t"<<"QUANTITY\t"<<"CATEGORY\n\n";
			
		    for(i=1;bookin >> isbn >> title>>author>>quantity>>category;i++)
		    {
		    	
		    	cout<<"\t"<<i<<"\t\t"<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n\n";
		    }
		   /* for(i=1;!bookin.eof();i++)
		    {
			    bookin.getline(buff,sizeof(buff));
			    cout<<i<<"\t\t"<<buff<<endl;
			
		    }*/ 
		    
			bookin.close();
			back();
		}
		void search()
		{
			int i,num;
		
			char buff[100];
			ifstream bookin;
			bookin.open("book.txt",ios::app);
			gotoxy(35,14);
			cout<<"ENTER ISBN OF BOOK";
			cin>>num;
			
			int flag;
		    for(i=1;bookin >> isbn >> title>>author>>quantity>>category;i++)
		    {
		    	if(num==isbn)
		    	{
		    		flag=0;
		    	//system("color 0a");
                cout<<"\n\n\n\t\t\t\t-----------SEARCHING THE DATA-------------\n\n";
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
		    		cout<<"\n\n\n\tISBN\t\t"<<"TITLE\t\t"<<"AUTHOR\t\t"<<"QUANTITY\t"<<"CATEGORY\n\n";
		    		cout<<"\t"<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
		    		
			    }
			    else 
			    {
			    	flag==1;
				}
		    }
		    if(flag==1)
		    {
		    	gotoxy(35,18);
			    cout<<"BOOK NOT FOUND!!";
			}
		    bookin.close();
			back();
		}
		void view_stock_of_book()
		{
			int opt;
			gotoxy(45,14);
			cout<<"1. show all books";
			gotoxy(45,16);
			cout<<"2. search book";
			gotoxy(45,18);
			cout<<"enter your choice";
			cin>>opt;
			system("cls");
			switch(opt)
			{
				case 1:
					show_allbooks();
					break;
				
				case 2:
					search();
					break;
					
				default:
				{
					
					cout<<"\n\n\t\tplease enter a valid number:";
					cout<<"\n\n\t\tpress any key for going back.......";
					system("cls");
					view_stock_of_book();
				}	
			}
		}
		void update_book()
	{
		int c,flag=0;
		gotoxy(35,10);
		cout<<"Enter ISBN of book to update: ";
		cin>>c;
		ifstream bookin;
		bookin.open("book.txt");
		ofstream e;
		e.open("new.txt");	
	while(bookin >> isbn >> title>>author>>quantity>>category)
	{
		if(c==isbn)
		{
			flag=1;
			
		    gotoxy(40,16);
		    fflush(stdin);
		    cout<<"UPDATE TITLE OF BOOK:";
		    getline(cin,title);
		    gotoxy(40,18);
		    fflush(stdin); 
		    cout<<"UPDATE AUTHOR'S NAME:";
		    getline(cin,author);
		    gotoxy(40,20);
		    fflush(stdin);
		    cout<<"UPDATE QUANTITY OF BOOK:";
		    cin>>quantity;
		    gotoxy(40,22);
		    fflush(stdin);
		    cout<<"UPDATE CATEGORY OF BOOK:";
		    getline(cin,category);
		
			e<<c<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
			
		}
		else
		{
			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
			
		}
	}
	if(flag!=1)
	{
		gotoxy(35,18);
		cout<<"BOOK NOT FOUND!!";
	}
	else 
	{gotoxy(35,21);
		cout<<"BOOK RECORD UPDATED!!";
	}
	
	e.close();
	bookin.close();
	remove("book.txt");
	rename("new.txt","book.txt");
	back2();
	}
		void remove_book()
	{
		int c;
		gotoxy(35,10);
		cout<<"Enter ISBN of book to remove";
		cin>>c;
		ifstream bookin;
		bookin.open("book.txt");
		ofstream e;
		e.open("new.txt");
		int flag=0;	
	while(bookin >> isbn >> title>>author>>quantity>>category)
	{
		if(c!=isbn)
		{
		
			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
			
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
				cout<<endl<<"\nMEMBER RECORD HAS BEEN DELTED SUCCESSFULLY";
			
		}
	}
	if(flag!=1)
	{
		gotoxy(35,18);
		cout<<"BOOK NOT FOUND!!";
	}
	
	e.close();
	bookin.close();
	remove("book.txt");
	rename("new.txt","book.txt");
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
		view_stock_of_book();
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
public:
 void operator--(int a)
 {
 	ofstream e;
 	e.open("new.txt");
 	ifstream bookin;
 	bookin.open("book.txt",ios::app);
 	while(bookin >> isbn >> title>>author>>quantity>>category)
 	{
 		
 		if(isbn==a)
 		{
 			quantity-=1;
 			
 			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
		}
 		else
 		{
 			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
 		}
 		
	}
 	bookin.close();
 	e.close();
 	
 	
 }
 void operator++(int a)
 {
 	ofstream e;
 	e.open("new.txt");
 	ifstream bookin;
 	bookin.open("book.txt",ios::app);
 	while(bookin >> isbn >> title>>author>>quantity>>category)
 	{
 		
 		if(isbn==a)
 		{
 			quantity+=1;
 			
 			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
		}
 		else
 		{
 			e<<isbn<<"\t\t"<<title<<"\t\t"<<author<<"\t\t"<<quantity<<"\t\t"<<category<<"\n";
 		}
 		
	}
 	bookin.close();
 	e.close();
 	remove("book.txt");
	rename("new.txt","book.txt");
 	
 	
 }
};
#endif
