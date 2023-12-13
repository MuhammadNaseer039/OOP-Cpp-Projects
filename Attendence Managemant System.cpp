#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
using namespace std;

class attendance
{
	int strength,rollno;
	char attendence,name[20];
	string date;
	public:
		void welcome();
		void addministration();
		void Mainmenu();
		void _attendance();
		void addclass();
		void showattendance();
		int getStrength(int filename);

};



int main()
{
	
	attendance attend;
	attend.welcome();
	attend.Mainmenu();
}
void attendance::welcome()
{
	for(int i=0;i<=115;i++)
	{
		cout<<"*";
	}
	cout<<endl<<"\t\t\t\t\t  ATTENDANCE MANAGEMENT SYSTEM\n\t\t\t\t\t DEPARTMENT OF COMPUTER SCIENCE\n\t\t\t\t    UNIVERSITY OF KOTLI AZAD JAMMU & KASHMIR"<<endl;
	for(int i=0;i<=115;i++)
	{
		cout<<"*";
	}
}
void attendance::Mainmenu()
{
	char choice;
	cout<<endl<<"\t\t\tPRESS 1 FOR ATTENDENCE: ";
	cout<<endl<<"\t\t\tPRESS 2 FOR ADMINISTRATION: ";
	cout<<endl<<"\t\t\tPress 3 FOR SHOW ATTENDANCE: ";
	cout<<endl<<"\t\t\tPRESS 0 TO EXIT: ";
	choice = getch();
	switch(choice)
	{
		case '0':
			exit(0);
			break;
		case '1':
			system("cls");
			_attendance();
			break;
		case '2':
			system("cls");
			addministration();
			break;
		case '3':
			system("cls");
			showattendance();
			break;
		default:
			cout<<endl<<"Wrong input";
			cout<<endl<<"Press any key to continue.....";
			getch();
			system("cls");
			attendance::welcome();
			Mainmenu();
	}
}
void attendance::_attendance()
{
	char choice;
	cout<<endl<<"\t\t\t\tATTENDENCE SECTION";
	cout<<endl<<"\t\tPress 1 for CS 2nd: ";
	cout<<endl<<"\t\tPress 2 for CS 4nd: ";
	cout<<endl<<"\t\tPress 3 for CS 6nd: ";
	cout<<endl<<"\t\tPress 4 for CS 8nd: ";
	cout<<endl<<"\t\tPress 0 to back: ";
	choice = getch();
	switch(choice)
	{
		case '0':
		{
			system("cls");
			attendance::welcome();
			Mainmenu();
		}
		case '1':
			{
				system("cls");
				ofstream myfile;
				cout<<endl<<"\t\t\t\tCS 2ND";
				myfile.open("CS2ndAS.txt",ios::app);
				strength = getStrength(1);
				cout<<endl<<"Enter date: ";
				cin>>date;
				myfile<<"Roll NO\t\t"<<date<<endl;
				for(int i=0;i<strength;i++)
				{
					cout<<endl<<"Roll number "<<i+1<<" (P/A): ";
					cin>>attendence;
					myfile<<i+1<<"\t\t"<<attendence<<endl;
				}
				myfile.close();
				cout<<endl<<"Attendence has been updated: ";
				cout<<endl<<"Press any key to continue.....";
				getch();
				system("cls");
				attendance::welcome();
				Mainmenu();					
				break;
			}
		case '2':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 4TH";
				strength = getStrength(2);
				ofstream myfile;
				myfile.open("CS4ndAS.txt",ios::app);
				
				cout<<endl<<"Enter date: ";
				cin>>date;
				myfile<<"Roll NO\t\t"<<date<<endl;
				for(int i=0;i<strength;i++)
				{
					cout<<endl<<"Roll number "<<i+1<<" (P/A): ";
					cin>>attendence;
					myfile<<(i+1)<<"\t\t"<<attendence<<endl;
				}
				myfile.close();
				cout<<endl<<"Attendence has been updated: ";
				cout<<endl<<"Press any key to continue.....";
				getch();
				system("cls");
				attendance::welcome();
				Mainmenu();
				break;	
			}
		case '3':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 6TH";
				strength = getStrength(3);
				ofstream myfile;
				myfile.open("CS6ndAS.txt",ios::app);
				cout<<endl<<"Enter date: ";
				cin>>date;
				myfile<<"Roll NO\t\t"<<date<<endl;
				for(int i=0;i<strength;i++)
				{
					cout<<endl<<"Roll number "<<i+1<<" (P/A): ";
					cin>>attendence;
					myfile<<i+1<<"\t\t"<<attendence<<endl;
				}
				myfile.close();
				cout<<endl<<"Attendence has been updated: ";
				cout<<endl<<"Press any key to continue.....";
				getch();
				system("cls");
				attendance::welcome();
				Mainmenu();
				break;
			}
		case '4':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 8TH";
				strength = getStrength(4);
				ofstream myfile;
				myfile.open("CS8ndAS.txt",ios::app);
				
				cout<<endl<<"Enter date: ";
				cin>>date;
				myfile<<"Roll NO\t\t"<<date<<endl;
				for(int i=0;i<strength;i++)
				{
					cout<<endl<<"Roll number "<<i+1<<" (P/A): ";
					cin>>attendence;
					myfile<<i+1<<"\t\t"<<attendence<<endl;
				}
				myfile.close();
				cout<<endl<<"Attendence has been updated: ";
				cout<<endl<<"Press any key to continue.....";
				getch();
				system("cls");
				attendance::welcome();
				Mainmenu();
				break;
			}
		default:
			{
				
				cout<<endl<<"Wrong input!!!!!!!";
				cout<<endl<<"Press any key to continue.....";
				getch();
				system("cls");
				attendance::welcome();
				Mainmenu();
			}
	}
}
void attendance::addministration()
{
	char choice;
	cout<<endl<<"\t\t\t\tADMINISTRATION";
	cout<<endl<<"PRESS 1 FOR ADD STUDENTS IN CLASS: ";
	cout<<endl<<"PRESS 2 FOR DELETE CLASS: ";
	cout<<endl<<"PRESS 0 TO BACK: ";
	choice = getch();
	switch(choice)
	{
		case '0':
			{
				system("cls");
				welcome();
				Mainmenu();
				break;
			}
		case '1':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tADD STUDENTS IN DATA CLASS";
				char choice;
				cout<<endl<<"\t\t1. CS 2ND";
				cout<<endl<<"\t\t2. CS 4TH";
				cout<<endl<<"\t\t3. CS 6TH";
				cout<<endl<<"\t\t4. CS 8TH";
				cout<<endl<<"\t\tPress 0 to back: ";
				choice = getch();
				switch(choice)
				{
					case '0':
						{
							system("cls");
							addministration();
							break;
						}
					case '1':
						{
							int st = getStrength(1);
							if(st > 0)
							{
								cout<<endl<<"File is already been created";
								cout<<endl<<"Press any key to continue......";
								getch();
								system("cls");
								addministration();
								break;
							}
							cout<<endl<<"Enter strength of the class: ";
							cin>>strength;
							ofstream myfile;
							myfile.open("CS2ndNS.txt",ios::app);
							for(int i=0;i<strength;i++)
							{
								cout<<endl<<"Enter Name of roll number "<<i+1<<" : ";
								cin>>name;
								myfile<<i+1<<"\t"<<name<<"\n";
							}
							myfile.close();
							cout<<endl<<"Data has been saved successfully.....";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '2':
						{
							int st = getStrength(2);
							if(st > 0)
							{
								cout<<"File is already been created";
								cout<<endl<<"Press any key to continue......";
								getch();
								system("cls");
								addministration();
								break;
							}
							cout<<endl<<"Enter strength of the class: ";
							cin>>strength;
							ofstream myfile;
							myfile.open("CS4ndNS.txt");
							for(int i=0;i<strength;i++)
							{
								cout<<endl<<"Enter Name of roll number "<<i+1<<" : ";
								cin>>name;
								myfile<<i+1<<"\t"<<name<<"\n";
							}
							myfile.close();
							cout<<endl<<"Data has been saved successfully.....";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '3':
						{
							int st = getStrength(3);
							if(st > 0)
							{
								cout<<"File is already been created";
								cout<<endl<<"Press any key to continue......";
								getch();
								system("cls");
								addministration();
								break;
							}
							cout<<endl<<"Enter strength of the class: ";
							cin>>strength;
							ofstream myfile;
							myfile.open("CS6ndNS.txt");
							for(int i=0;i<strength;i++)
							{
								cout<<endl<<"Enter Name of roll number "<<i+1<<" : ";
								cin>>name;
								myfile<<i+1<<"\t"<<name<<"\n";
							}
							myfile.close();
							cout<<endl<<"Data has been saved successfully.....";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '4':
						{
							int st = getStrength(4);
							if(st > 0)
							{
								cout<<"File is already been created";
								cout<<endl<<"Press any key to continue......";
								getch();
								system("cls");
								addministration();
								break;
							}
							cout<<endl<<"Enter strength of the class: ";
							cin>>strength;
							ofstream myfile;
							myfile.open("CS8ndNS.txt");
							for(int i=0;i<strength;i++)
							{
								cout<<endl<<"Enter Name of roll number "<<i+1<<" : ";
								cin>>name;
								myfile<<i+1<<"\t"<<name<<"\n";
							}
							myfile.close();
							cout<<endl<<"Data has been saved successfully.....";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					default:
						{
							cout<<endl<<"Wrong input!!!!!!";
							cout<<endl<<"Data has been saved successfully.....";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
						}
				}
				break;
			}
		case '2':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tDELETE CLASS";
				char choice;
				cout<<endl<<"\t\t1. CS 2ND";
				cout<<endl<<"\t\t2. CS 4TH";
				cout<<endl<<"\t\t3. CS 6TH";
				cout<<endl<<"\t\t4. CS 8TH";
				cout<<endl<<"\t\tPress 0 to back: ";
				choice = getch();
				switch(choice)
				{
					case '0':
						{
							system("cls");
							addministration();
							break;
						}
					case '1':
						{
							remove("CS2ndAS.txt");
							remove("CS2ndNS.txt");
							cout<<endl<<"Data has been removed successfully";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '2':
						{
							remove("CS4ndAS.txt");
							remove("CS4ndNS.txt");
							cout<<endl<<"Data has been removed successfully";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '3':
						{
							remove("CS6ndAS.txt");
							remove("CS6ndNS.txt");
							cout<<endl<<"Data has been removed successfully";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					case '4':
						{
							remove("CS8ndAS.txt");
							remove("CS8ndNS.txt");
							cout<<endl<<"Data has been removed successfully";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
							break;
						}
					default:
						{
							cout<<endl<<"Wrong input!!!!!!";
							cout<<endl<<"Press any key to continue......";
							getch();
							system("cls");
							addministration();
						}
				}
				break;
			}
		default:
			{
				cout<<endl<<"Wrong input!! try again";
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				attendance::welcome();
				attendance::Mainmenu();
			}
	}
}
void attendance::showattendance()
{
	char choice;
	cout<<endl<<"\t\t\t\tSHOW ATTENDANCE";
	cout<<endl<<"\t\tPRESS 1 FOR CS 2ND: ";
	cout<<endl<<"\t\tPRESS 2 FOR CS 4TH: ";
	cout<<endl<<"\t\tPRESS 3 FOR CS 6TH: ";
	cout<<endl<<"\t\tPRESS 4 FOR CS 8TH: ";
	cout<<endl<<"\t\tPRESS 0 TO BACK: ";
	choice = getch();
	switch(choice)
	{
		case '0':
			{
				system("cls");
				welcome();
				Mainmenu();
				break;
			}
		case '1':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 2ND"<<endl;
				string line;
				ifstream myfile;
				myfile.open("CS2ndAS.txt",ios::app);
				while(!myfile.eof())
				{
					getline(myfile,line);
					cout<<line<<endl;
				}
				myfile.close();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				showattendance();
				break;
			}
		case '2':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 4TH"<<endl;
				string line;
				ifstream myfile;
				myfile.open("CS4ndAS.txt",ios::app);
				while(!myfile.eof())
				{
					getline(myfile,line);
					cout<<line<<endl;
				}
				myfile.close();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				showattendance();
				break;	
			}
		case '3':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 6TH"<<endl;
				string line;
				ifstream myfile;
				myfile.open("CS6ndAS.txt",ios::app);
				while(!myfile.eof())
				{
					getline(myfile,line);
					cout<<line<<endl;
				}
				myfile.close();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				showattendance();
				break;
			}
		case '4':
			{
				system("cls");
				cout<<endl<<"\t\t\t\tCS 8TH"<<endl;
				string line;
				ifstream myfile;
				myfile.open("CS8ndAS.txt",ios::app);
				while(!myfile.eof())
				{
					getline(myfile,line);
					cout<<line<<endl;
				}
				myfile.close();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				showattendance();
				break;
			}
		default:
			{
				
				cout<<endl<<"Wrong input";
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				showattendance();
			}
	}	
}
int attendance::getStrength(int filename)
{
	int i = -1;
	ifstream myfile;
	string line;
	switch(filename)
	{
		case 1:
			myfile.open("CS2ndNS.txt",ios::app);
			break;
		case 2:
			myfile.open("CS4ndNS.txt",ios::app);
			break;
		case 3:
			myfile.open("CS6ndNS.txt",ios::app);
			break;
		case 4:
			myfile.open("CS8ndNS.txt",ios::app);
			break;
		default:
			cout<<endl<<"Wrong input....";
	}
	while(!myfile.eof())
	{
		getline(myfile,line);
		i++;
	}
	return i;
}
