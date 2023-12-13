#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;

class cafe
{
	int bill,order,quantity;
	public:
		void printline();
		void welcome();
		void welcomeagain();
		int cechoice();
		void login();
		void employeeaccess();
		void customer();
};
void cafe::printline()
{
	for(int i=0;i<120;i++)
	{
		cout<<"*";
	}
}

void cafe::welcome()
{
	printline();
	cout<<"\t\t\t\t\t\t\tWELCOME To Cafe\n";
	printline();
}

int cafe::cechoice()
{
	int num;
	cout<<endl<<"Are you a customer or employee: ";
	cout<<endl<<"For customer press 1: \nFor employee press 2: \nFor return press 3: ";
	cin>>num;	
	return num;
}

void cafe::welcomeagain()
{
	printline();
	cout<<"\n\t\t\t\t\t\t\tWELCOME AGAIN\n";
	printline();
	
}
void cafe::login()
{
	int x = cechoice();
	if(x == 1)
	{
		system("cls");
		customer();
	}
	else if(x == 2)
	{
		system("cls");
		employeeaccess();
	}
	else if(x == 3)
	{
		exit(0);
	}
	else
	{
		cout<<"\aWrong input!!!\n Try again: ";
	}
	
}

void cafe::employeeaccess()
{
	system("cls");
	int choice;
	welcomeagain();
	cout<<"press 1 for sales record:\nPress 2 for total sales: \nPress 3 for return: ";
	cin>>choice;
	if(choice == 1)
	{
		system("cls");
		ifstream sales;
		string line;
		sales.open("salesrecord.txt",ios::in);
		cout<<"Total price\tQuantity\tS.No\n";
		while(sales)
		{
			getline(sales,line);
			cout<<line<<endl;
		}
		sales.close();
		cout<<endl<<"Press any key to return back......";
		getch();
		employeeaccess();
	}
	else if (choice == 2)
	{
		system("cls");
		int bill;
		int sum = 0;
		fstream totalbill;
		totalbill.open("totalbill.txt");
		while(!totalbill.eof())
		{
			totalbill>>bill;
			//cout<<bill<<endl;
			sum = sum +bill;
		}
		cout<<endl<<"Your total sales of the day is "<<sum;
		totalbill.close();
		cout<<endl<<"Press any key to return back......";
		getch();
		employeeaccess();
	}
	else if (choice == 3)
	{
		system("cls");
		welcomeagain();
		login();
	}
	else
	{
		system("cls");
		cout<<endl<<"\a\a\aWrong input!!!\n Try agian";
	}
}
void cafe::customer()
{
	system("cls");
	welcomeagain();
	fstream sales;
	fstream totalbill;
	
	cout<<"\n\t\t\t\t\tWelcome to order section: \n";
	cout<<"1: Tea with fries (120RS only)\n2: Biryani with drink (200RS only)\n3: Ice cream (120RS only)"
	"\n4: Burger (150RS only)";
	cout<<"\n\nPlace your order by entering its serial number(0 to retrun back): ";
	cin>>order;
	totalbill.open("totalbill.txt",ios::app);
	sales.open("salesrecord.txt",ios::app);
	

	switch(order)
	{
		case 0:
			{
				system("cls");
				welcomeagain();
				login();
			}
		case 1:
			{
				cout<<endl<<"Enter your quantity: ";
				cin>>quantity;
				bill = 120*quantity;
				cout<<endl<<"Your total bill is "<<bill;
				cout<<endl<<"Thankyou  for having uss\nHave a nice day";
				sales<<bill<<" /-RS"<<"\t"<<quantity<<"\t\t"<<order<<"\n";
				totalbill<<bill<<"\n";
				cout<<endl<<"Press any key to exit.....";
				getch();
				system("cls");
				cout<<endl<<"\t\t      DO COME AGAIN\n\n\n\t\t~~~~~~~~GoodBye~~~~~~~~";
				break;
			}
		case 2:
			{
				cout<<endl<<"Enter your quantity: ";
				cin>>quantity;
				bill = 200*quantity;
				cout<<endl<<"Your total bill is "<<bill;
				cout<<endl<<"Thankyou  for having uss\nHave a nice day";
				sales<<bill<<" /-RS"<<"\t"<<quantity<<"\t\t"<<order<<"\n";
				totalbill<<bill<<"\n";
				cout<<endl<<"Press any key to exit.....";
				getch();
				system("cls");
				cout<<endl<<"\t\t      DO COME AGAIN\n\n\n\t\t~~~~~~~~GoodBye~~~~~~~~";
				break;
			}
		case 3:
			{
				cout<<endl<<"Enter your quantity: ";
				cin>>quantity;
				bill = 120*quantity;
				cout<<endl<<"Your total bill is "<<bill;
				cout<<endl<<"Thankyou  for having uss\nHave a nice day";
				sales<<bill<<" /-RS"<<"\t"<<quantity<<"\t\t"<<order<<"\n";
				totalbill<<bill<<"\n";
				cout<<endl<<"Press any key to exit.....";
				getch();
				system("cls");
				cout<<endl<<"\t\t      DO COME AGAIN\n\n\n\t\t~~~~~~~~GoodBye~~~~~~~~";
				break;
			}
		case 4:
			{
				cout<<endl<<"Enter your quantity: ";
				cin>>quantity;
				bill = 150*quantity;
				cout<<endl<<"Your total bill is "<<bill;
				cout<<endl<<"Thankyou  for having uss\nHave a nice day";
				sales<<bill<<" /-RS"<<"\t"<<quantity<<"\t\t"<<order<<"\n";
				totalbill<<bill<<"\n";
				cout<<endl<<"Press any key to exit.....";
				getch();
				system("cls");
				cout<<endl<<"\t\t      DO COME AGAIN\n\n\n\t\t~~~~~~~~GoodBye~~~~~~~~";
				break;
			}
		default:
			{
				cout<<endl<<"!!!Wrong input\nTry again";
			}
	}
	sales.close();
	totalbill.close();
}


int main()
{
	cafe universitycafe;
	universitycafe.welcome();
	universitycafe.login();
	
}

