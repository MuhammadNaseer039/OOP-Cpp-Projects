#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


class shop
{
	struct customer
	{
		char name[20];
		int shopnumber;
		char address[20];
		char contactnumber[15];
	};
	struct employee
	{
	char name[20];
	int salary;
	};
	struct book
	{
	char name[20];
	char auther[20];
	int price;
	int pages;	
	};
	public:
		void welcome();
		void menu();
		void showbooks();
		void adminlogin();
		void welcomeagain();
		void addcustomer();
		void addemployee();
		void addbooks();
		void showcustomer();
		void showemployee();
};


void shop::welcome()
{
	for(int j=0;j<120;j++)
	{
		cout<<"~";
	}
	cout<<endl<<"\t\t\t\t\tWelcome to BookShop Management System"<<endl;
	for(int j=0;j<120;j++)
	{
		cout<<"~";
	}	
}

void shop::welcomeagain()
{
	for(int j=0;j<120;j++)
	{
		cout<<"~";
	}
	cout<<endl<<"\t\t\t\t\tWelcome Again"<<endl;
	for(int j=0;j<120;j++)
	{
		cout<<"~";
	}	
}

void shop::menu()
{
	int choice;
	cout<<endl<<"Press 1 for books information.\t\t\tPress 2 for Admin login."
	"\npress 3 to leave. : ";
	cin>>choice;
	if(choice == 1)
	{
		system("cls");
		cout<<endl<<"\t\t\t\tBOOKS INFORMATION";
		showbooks();
		cout<<endl<<"Press any key to continue.....";
		getch();
		system("cls");
		welcome();
		menu();
	}
	else if(choice == 2)
	{
		system("cls");
		welcomeagain();
		adminlogin();
	}

	else if (choice == 3)
	{
		exit(0);
	}
	else
	{
		cout<<endl<<"Wrong input\n\nTry Again";
	}
	
}
void shop::addbooks()
{
	book B1;
	cout<<endl<<"Enter book name :";
	cin>>B1.name;
	cout<<endl<<"Enter book Auther :";
	cin>>B1.auther;
	cout<<endl<<"Enter book pages :";
	cin>>B1.pages;
	cout<<endl<<"Enter book price :";
	cin>>B1.price;
	
	fstream myfile;
	myfile.open("bookinfo.dat",ios::app);
	
	myfile.write((char*)&B1,sizeof(B1));
	
	myfile.close();
	
}
void shop::showbooks()
{
	book b1;
	fstream myfile;
	myfile.open("bookinfo.dat");
	while(myfile.read((char*)&b1,sizeof(b1)))
	{
		cout<<endl<<"Name\t:\t"<<b1.name;
		cout<<endl<<"Author\t:\t"<<b1.auther;
		cout<<endl<<"Pages\t:\t"<<b1.pages;
		cout<<endl<<"Price\t:\t"<<b1.price;
		cout<<endl;
	}
	myfile.close();
}
void shop::adminlogin()
{
	cout<<endl<<"\t\t\tWELCOME TO ADMIN MENU";
	int choice;
	cout<<endl<<"\n\t\t\tPRESS 1 FOR CUSTOMER INFORMATION\n\n\t\t\tPRESS 2 FOR EMPLOYEE INFORMATION"
	"\n\n\t\t\tPRESS 3 FOR ADD CUSTOMER\n\n\t\t\tPRESS 4 FOR ADD EMPLOYEE\n\n\t\t\tPRESS 5 TO ADD NEW BOOKS\n\n\t\t\tPRESS 6 TO RETURN BACK";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
				system("cls");
				cout<<"\t\t\t\t\tCUSTOMER INFORMATION";
				showcustomer();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				adminlogin();
			}
		case 2:
			{
				system("cls");
				cout<<"\t\t\t\t\tEMPLOYEE INFORMATION";
				showemployee();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				adminlogin();
				
			}
		case 3:
			{
				system("cls");
				cout<<"\t\t\t\t\tADD NEW CUSTOMERS";
				addcustomer();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				adminlogin();
			}
		case 4:
			{
				system("cls");
				cout<<"\t\t\t\t\tADD NEW EMPLOYEE";
				addemployee();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				adminlogin();
			}
		case 5:
			{
				system("cls");
				cout<<"\t\t\t\t\tADD NEW BOOKS";
				addbooks();
				cout<<endl<<"Press any key to continue......";
				getch();
				system("cls");
				adminlogin();
				
			}
		case 6:
			{
				system("cls");
				welcome();
				menu();
			}
		default:
			{
				cout<<"Wrong input please try again!!!!";
			}
	}
}



void shop::addcustomer()
{
	customer c1;
	cout<<endl<<"Enter name of the customer: ";
	cin>>c1.name;
	cout<<endl<<"Enter shop number of the customer: ";
	cin>>c1.shopnumber;
	cout<<endl<<"Enter address of the customer(without blankspace): ";
	cin>>c1.address;
	cout<<endl<<"Enter contact number of the customer: ";
	cin>>c1.contactnumber;
	
	fstream myfile;
	myfile.open("customer.dat",ios::app);
	
	myfile.write((char*)&c1,sizeof(c1));
	myfile.close();


}
void shop::showcustomer()
{
	customer c1;
	fstream myfile;
	myfile.open("customer.dat");
	while(myfile.read((char*)&c1,sizeof(c1)))
	
	{
		cout<<endl<<"NAME\t\t:\t"<<c1.name;
		cout<<endl<<"SHOP NUMBER\t:\t"<<c1.shopnumber;
		cout<<endl<<"ADDRESS\t\t:\t"<<c1.address;
		cout<<endl<<"CONTACT NUMBER\t:\t"<<c1.contactnumber;
		cout<<endl;
	}
	myfile.close();
}
void shop::addemployee()
{
	employee em1;
	cout<<endl<<"Enter Employee name :";
	cin>>em1.name;
	cout<<endl<<"Enter Employee salary :";
	cin>>em1.salary;
	
	fstream myfile;
	myfile.open("employee.dat",ios::app);
	
	myfile.write((char*)&em1,sizeof(em1));
	myfile.close();
}
void shop::showemployee()
{
	employee em1;
	
	fstream myfile;
	myfile.open("employee.dat");
	while(myfile.read((char*)&em1,sizeof(em1)))
	{
		cout<<endl<<"Name of employee\t:\t"<<em1.name;
		cout<<endl<<"salary of employee\t:\t"<<em1.salary;
		cout<<endl;
	}	
}


int main()
{
	shop shop1;
	shop1.welcome();
	shop1.menu();
}


