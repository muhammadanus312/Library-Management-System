#ifndef CLASS_admin
#define CLASS_Admin
using namespace std;
void mainmenu();
class admin
{
	string admin_name;
	int login_id;
	string password;
	public:
		void check_admin()
		{
			ifstream fin;
			fin.open("myfile.txt");
			fin>>login_id;
			fin>>password;
			int a;
			string b;
			while(1)
			{
			cout<<"\n\n\n\t\t\t\tenter id: ";
			cin>>a;
		
			fflush(stdin);
			cout<<"\n\n\t\t\t\tenter password: ";
			getline(cin,b);
			
			
			if(a==login_id && b==password)
			{
			   system("cls");
			   mainmenu();
			}
			else
			{
				cout<<"\n\n\t\tID or PASSWORD incorrect......";
				cout<<"\n\t\t\tplease enter again";
			}
		}
			fin.close();
		}
	void set_admin()
		{
			cout<<"HELLO";
			int a ;string b;
			ifstream fin;
			ofstream fout;
			
			fin.open("myfile.txt");
			fin>>login_id;
			fin>>password;
			cout<<"\n\n\n\n";
		while(1)
		{
			
			cout<<"\n\n\n\n\n\t\t\t\tENTER CURRENT ID: ";
			cin>>a;
			fflush(stdin);
		
			cout<<"\n\n\t\t\t\tENTER CURRENT PASSWORD: ";
			getline(cin,b);
		
			
			
		if(a==login_id && b==password)
			{
				
				
				cout<<"\n\n\n\n\n\t\t\t\tENTER NEW LOGIN ID: ";
			    cin>>login_id;
			    fflush(stdin);
			    cout<<"\n\n\t\t\t\tENTER PASSWORD: ";
			    getline(cin,password);
			    fout.open("myfile.txt");
				fout<<login_id;
			    fout<<"\t"<<password;
			    fout.close();
			    fin.close();
			    cout<<"\n\n\n\t\t\t\tID and PASSWORD changed....";
			    cout<<"\n\n\t\t\t\tpress any key for go to mainmenu:";
			    getch();
			    system("cls");
			    mainmenu();
			}
			else
			{
				cout<<"\n\n\n\t\tID or PASSWORD incorrect.......";
				cout<<"\n\n\t\t\tplease enter again!!";
			}
	    }
}
};
#endif
