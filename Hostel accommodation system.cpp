#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class hostel
{
	struct information
	{
		char name[20];
		char fathername[20];
		int age;
		int roomno;
		char phonenumber[20];
	};
	public:
		information info;
		void menu();
		void dataenter();
		void view_all_records();
		void deleterecord();
		void searchrecord();
		
};

void hostel::menu()
{
	int choice;
    cout<<"\n\n\t\t\t\tHOSTEL ACCOMMODATION SYSTEM";
    cout<<"\n\n\n\t\t\tWELCOME TO THE MAIN MENU";
    cout<<endl<<"\n\n\t\tPress 1 to enter information of student: ";
    cout<<endl<<"\n\n\t\tPress 2 to view all records: ";
    cout<<endl<<"\n\n\t\tPress 3 to delete record: ";
    cout<<endl<<"\n\n\t\tPress 4 to search record: ";
    cout<<endl<<"\n\n\t\tPress 5 to exit: ";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    		{
    			system("cls");
    			dataenter();
    			break;
			}
		case 2:
			{
				system("cls");
				view_all_records();
				break;
			}
		case 3:
			{
				system("cls");
				deleterecord();
				break;
			}
		case 4:
			{
				system("cls");
				searchrecord();
				break;
			}
		case 5:
			{
				exit(0);
			}
		default:
			{
				cout<<endl<<"Wrong input!!!\nTry again.......";
				cout<<endl<<"Press any key to continue.......";
				getch();
				system("cls");
				menu();
			}
	}
    
}

void hostel::dataenter()
{
	cout<<endl<<"\t\t\t\tENTER DATA";
	cout<<endl<<"Enter room number: ";
	cin>>info.roomno;
	cout<<endl<<"Enter name: ";
	cin>>info.name;
	cout<<endl<<"Enter father name: ";
	cin>>info.fathername;
	cout<<endl<<"Enter age: ";
	cin>>info.age;
	cout<<endl<<"Enter phone number: ";
	cin>>info.phonenumber;
	
	ofstream myfile;
	myfile.open("record.dat",ios::app);
	
	myfile.write((char*)&info,sizeof(info));
	myfile.close();
	
	cout<<endl<<"Record has been saved successfully....";
	
	
	cout<<endl<<"Press any key to continue......";
	
	getch();
	system("cls");
	menu();
}

void hostel::view_all_records()
{
	cout<<endl<<"\t\t\t\tALL RECORDS";
	ifstream myfile;
	myfile.open("record.dat");
	if(!myfile)
	{
		cout<<endl<<"\t\t\tFile not found";
	}
	else
	{
		while(myfile.read((char*)&info,sizeof(info)))
		{
			cout<<endl<<"Room number \t:\t"<<info.roomno;
			cout<<endl<<"Name \t\t:\t"<<info.name;
			cout<<endl<<"Father name \t:\t"<<info.fathername;
			cout<<endl<<"Age \t\t:\t"<<info.age;
			cout<<endl<<"Phone number \t:\t"<<info.phonenumber;
			cout<<endl;
		}
	}
	myfile.close();
	cout<<endl<<"Press any key to continue......";
	
	getch();
	system("cls");
	menu();	
}
void hostel::deleterecord()
{
	cout<<endl<<"\t\t\t\tDELETE RECORDS";
	int roomnumber,flag = 1;
	cout<<endl<<"Enter room number to delete the record: ";
	cin>>roomnumber;
	ifstream myfile;
	ofstream newfile;
	myfile.open("record.dat",ios::in);
	newfile.open("temp.dat",ios::out);
	if(!myfile||!newfile)
	{
		cout<<endl<<"\t\t\tFile not found";
	}
	else
	{
		while(myfile.read((char*)&info,sizeof(info)))
		{
			if(roomnumber == info.roomno)
			{
				flag = 0;
			}
			if(roomnumber != info.roomno)
			{
				newfile.write((char*)&info,sizeof(info));
			}
		}
	}
	myfile.close();
	newfile.close();
	remove("record.dat");
	rename("temp.dat","record.dat");
	if(flag == 0)
	{
		cout<<endl<<"The record has been deleted successfully";
	}
	else
	{
		cout<<endl<<"Record not found!!!!!!!";
	}
		
	cout<<endl<<"Press any key to continue......";
	
	getch();
	system("cls");
	menu();
}
void hostel::searchrecord()
{
	cout<<endl<<"\t\t\t\tSEARCH RECORDS";
	int roomnumber,flag = 0;
	cout<<endl<<"Enter room number to Search the record: ";
	cin>>roomnumber;
	ifstream myfile;
	myfile.open("record.dat",ios::in);
	if(!myfile)
	{
		cout<<endl<<"\t\t\tFile not found";
	}
	else
	{
		while(myfile.read((char*)&info,sizeof(info)))
		{
			if(roomnumber == info.roomno)
			{
				cout<<endl<<endl<<"\tData found";
				cout<<endl<<"Room number \t:\t"<<info.roomno;
				cout<<endl<<"Name \t\t:\t"<<info.name;
				cout<<endl<<"Father name \t:\t"<<info.fathername;
				cout<<endl<<"Age \t\t:\t"<<info.age;
				cout<<endl<<"Phone number \t:\t"<<info.phonenumber;
				cout<<endl;
			}
		}
	}
	myfile.close();
	cout<<endl<<"Press any key to continue......";
	
	getch();
	system("cls");
	menu();
}

int main()
{
	hostel h1;
	h1.menu();
}
