#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> 
#include <windows.h>

using namespace std;
 
//gloal declaration for ease when used in functions.
string username;
string password;
string name;
char van1[15];
char van2[15];
char bus[40];
void menu();
void login();
void forgot();
void back();


//functions and their definitions.
void forgot()
//forgot password function
{
	string un, pw;//for pattern check in the file.
	bool flag;
	int choice;
	string user;//user enters username to be checked further from the file.
	system("cls");
	cout<<"\t\t\tSearch by username.";

		
			cout<<"\n\t\t\tEnter Username to find Password\n";
			cout<<"\n\t\t\tUsername\t\t:\t";
			cin>>user;
			ifstream check;//prepared for reading file
			check.open("logininfo.txt");//opens file 
				while(check>>un>>pw)
				{
					if(un==user)
					//if the username exists.
					{
						cout<<"\t\t\tYour Password is\t:\t"<<pw<<endl;
						cout<<"\n\t\t\tRedirecting to Login Page......";
						Sleep(5000);
						login();
						flag=true;
						break;
					}
				}
			if(flag!=true)
			//incase no such username exists in the data.
			{
				cout<<"False Login!\nAccount could not be found!\n";
				forgot();
			}
			check.close();

		
}
void ticket(void)
{
	
	system("cls");//clear screen and display fine.
	cout<<"\n***************************************************************************\n\n";
	cout<<"\t\t\tPAF-IAST Transport System";
	cout<<"\n\t\t\t\tUser Reciept\n\n";
	cout<<"***************************************************************************\n\n";
	
	string  route, departure, arrival, vehicle,seat;//variables for saving from file.
	string un;//variable for checking one type of data in file on each line.
		
	ifstream display;
	display.open("bus.txt",ios::in);
	//reading data from file created in the name of user.
	
	getline(display, route);//saves first line in route string.
	getline(display, departure);//saves second line in departure string.
	getline(display, arrival);//saves third line in arrival string.
	getline(display, vehicle);//saves fourth line in vehicle string.
	getline(display, seat);//saves fifth line in seat string.
	
	cout<<"USERNAME      \t:\t"<<username<<endl;
	cout<<"ROUTE         \t:\t"<<route<<endl;
	cout<<"DEPARTURE TIME\t:\t"<<departure<<endl;
	cout<<"ARRIVAL TIME  \t:\t"<<arrival<<endl;
	cout<<"VEHICLE       \t:\t"<<vehicle<<endl;
	cout<<"SEAT NUMBER   \t:\t"<<seat<<endl;
	cout<<"TICKET PRICE  \t:\t500"<<endl;
	cout<<"\nKindly Print this Receipt and Submit Ticket Price to Office"<<endl;
	display.close();	
	cout<<"\nPress B to go back or press any other key to exit\n";
	cout<<"Choice : ";
	char choice;
	cin>>choice;
	if(choice=='b'||choice=='B')
		menu();
	else
	exit(0);
		
	
	
}
void select(void)
{
	
	int choice=0;
	bool flag=true;
	system("cls");
	
	ofstream file;
	file.open("bus.txt");
	cout<<"\n\t***************************************************************************\n\n";
	cout<<"\t\t\t\tPAF-IAST Transport System\n\n";
	cout<<"\t***************************************************************************\n\n";
	cout<<"\n\t\t--------------------ROUTE------------------------\n\n";
	cout<<"\t\t1.Abbottabad.\n";
	cout<<"\t\t2.Wah Cantt.\n";
	cout<<"\t\t3.Islamabad.\n";
	cout<<"\t\t4.Rawalpindi.\n";
	cout<<"\t\t5.Go Back\n";
	cout<<"\t\t6.Exit\n";
	
	cout<<"\n\t\tSelect your route \t:\t";
	cin>>choice;
	
	switch(choice)
	{
	
		case 1:
		//Ride to Abbottabad .
			file<<"Abbottabad\n";
			system("cls");
			cout<<"\n----------------------TIMING--------------------------\n\n";
			cout<<"1.\tDeparture time\t:\t 6:30 A.M\n  \tArrival time\t:\t 8:00 A.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n2.\tDeparture time\t:\t 2:30 P.M\n  \tArrival time\t:\t 4:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n3.\tDeparture time\t:\t 5:30 P.M\n  \tArrival time\t:\t 7:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n\nSelect your choice\t:\t";
			cin>>choice;
			switch(choice)
			{
				case 1:
				//6:30 to 8:00	(A.M)
					file<<"6:30A.M\n8:00A.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE--------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								
								cout<<"\n----------------------SEAT--------------------------\n\n";
								
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 2:
				//2:30 to 4:00	(P.M)
					file<<"2:30P.M\n4:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE--------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 3:
				//5:30 to 7:00	(P.M)
					file<<"5:30P.M\n7:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE-------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				
				default:
					cout<<"Invalid Input!\n";
					getch();
					select();
				break;	
			}
		break;
		case 2:
		//Ride to Wah Cantt.
			file<<"Wahh Cantt\n";
			system("cls");
			cout<<"\n----------------------TIMING------------------------\n\n";
			cout<<"1.\tDeparture time\t:\t 7:30 A.M\n  \tArrival time\t:\t 8:00 A.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n2.\tDeparture time\t:\t 2:30 P.M\n  \tArrival time\t:\t 3:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n3.\tDeparture time\t:\t 5:30 P.M\n  \tArrival time\t:\t 6:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\nSelect your choice\t:\t";
			cin>>choice;
			switch(choice)
			{
				case 1:
				//7:30 to 8:00	(A.M)
					file<<"7:30A.M\n8:00A.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE--------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 2:
				//2:30 to 3:00	(P.M)
					file<<"2:30P.M\n3:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE--------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 3:
				//5:30 to 6:00	(P.M)
					file<<"5:30P.M\n6:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE-------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				
				default:
					cout<<"Invalid Input!\n";
					getch();
					select();
				break;	
			}
		break;
		case 3:
		//Ride to Islamabad.
			file<<"Islamabad\n";
			system("cls");
			cout<<"\n----------------------TIMING-------------------------\n\n";
			cout<<"1.\tDeparture time\t:\t 6:30 A.M\n  \tArrival time\t:\t 7:45 A.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n2.\tDeparture time\t:\t 2:30 P.M\n  \tArrival time\t:\t 3:45 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n3.\tDeparture time\t:\t 5:30 P.M\n  \tArrival time\t:\t 6:45 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\nSelect your choice\t:\t";
			cin>>choice;
			switch(choice)
			{
				case 1:
				//6:30 to 7:45	(A.M)
					file<<"6:30A.M\n7:45A.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE-------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 2:
				//2:30 to 3:45	(P.M)
					file<<"2:30P.M\n3:45P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen.
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen.
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 3:
				//5:30 to 6:45	(P.M)
					file<<"5:30P.M\n6:45P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen.
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				
				default:
					cout<<"Invalid Input!\n";
					getch();
					select();
				break;	
			}
		break;
		case 4:
		//Ride to Rawalpindi.
			file<<"Rawalpindi\n";
			system("cls");
			cout<<"\n----------------------TIMING------------------------\n\n";
			cout<<"1.\tDeparture time\t:\t 6:30 A.M\n  \tArrival time\t:\t 8:00 A.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n2.\tDeparture time\t:\t 2:30 P.M\n  \tArrival time\t:\t 4:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\n3.\tDeparture time\t:\t 5:30 P.M\n  \tArrival time\t:\t 7:00 P.M\n  \tStatus\t\t:\tEveryday"<<endl;
			cout<<"\nSelect your choice\t:\t";
			cin>>choice;
			switch(choice)
			{
				case 1:
				//6:30 to 8:00	(A.M)
					file<<"6:30A.M\n8:00A.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT-------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 2:
				//2:30 to 4:00	(P.M)
					file<<"2:30P.M\n4:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE------------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<41&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT-----------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
						break;	
					}
				break;
				case 3:
				//5:30 to 7:00	(P.M)
					file<<"5:30P.M\n7:00P.M\n";
					system("cls");
					cout<<"\n----------------------VEHICLE-----------------------\n\n";
					cout<<"1.Bus.\n2.Van# 01.\n3.Van# 02.\n";
					cout<<"Select your choice\t:\t";
					cin>>choice;
					switch(choice)
					{
						case 1:	
						//bus
							file<<"Bus\n";
								system("cls");
								//mandatory clearing screen
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-40)\t:\t";
								cin>>choice;
								
								if(bus[choice-1]==0&&choice<40&&choice>0)
								//checks for already booked seats.
								{
									bus[choice-1]=1;//books array location.
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
						
						case 2:
						//van1
							file<<"VAN#01\n";
								system("cls");//clear screen
								cout<<"\n----------------------SEAT------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van1[choice-1]==0&&choice<16&&choice>0)
								//checks for already booked seat.
								{
									van1[choice-1]=1;
									file<<choice<<"\n";//saves in file
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;
										
						case 3:
						//van2
							file<<"VAN#02\n";
								system("cls");
								cout<<"\n----------------------SEAT--------------------------\n\n";
								cout<<"Select your seat number(1-15)\t:\t";
								cin>>choice;
								if(van2[choice-1]==0&&choice<16&&choice>0)//checks for already booked seats
								{
									van2[choice-1]=1;
									file<<choice<<"\n";//saves in file.
									cout<<"Your seat is reserved.";
								}
								else
								{
									cout<<"Sorry! Please try again.";
									getch();
									select();
								}
						break;		
						
						default:
							cout<<"Invalid Input!\n";
							getch();
							select();
							
						break;	
					}
				break;
				
				default:
					cout<<"Invalid Input!\n";
					getch();
					select();
				break;	
			}
		break;
		
		default:
			cout<<"Invalid Input!\n";
			getch();
			select();
		break;	
		case 5:
			menu();
			break;
		case 6:
			exit(0);
			break;
	}
	file.close();
}


void menu(void)
{
	//system("cls");
	string choice;
	do
	{
	cout<<"\n\t***************************************************************************\n\n";
	cout<<"\t\t\t\tPAF-IAST Transport System\n\n";
	cout<<"\t***************************************************************************\n\n";
	cout<<"\t\t\t1.Book ticket\n\t\t\t2.Show Ticket\n\t\t\t3.Change ticket\n\t\t\t4.Logout\n\t\t\t5.Exit\n";
	cout<<"\n\t\t\tChoice\t:\t";
	cin>>choice;
	if(choice>="1" || choice<="5")
	{
		if (choice=="1")
		{	select();//user books seat.
			system("cls");
			cout<<"\t\t\t\tSeat Has Been Reserved For You!";
			Sleep(3000);
			ticket();//ticket is displayed.
	    }
		else if (choice=="2")
		{
			ticket();//ticket displayed if exists with that username.
	    }
		else if (choice=="3")
		{
			select();
			system("cls");
			cout<<"\t\t\tYour Reservation Has Been Modified";
			Sleep(3000);
			ticket();
	    }
		else if (choice=="4")
		{
			back();
        }
		else if (choice=="5")
		{
			exit(0);
		}
			
		else
		{
			cout<<"Invalid input!\n";
			menu();//reshow menu untill valid input by user.
	    }
	}
	else
	{
		cout<<"\nInvalid Choice\nEnter again";
	}
   }while(choice!="5");
}
void signup(void)
{
	system("cls");//clears screen
	cout<<"\t\t\tWelcome ! Create Your Account by Entering Username and Password\n\n";
	fstream in;
	//file writing.
	//opens file using append to add information to previous information.
	in.open("logininfo.txt", ios::app);
	
	cout<<"\t\t\tUSERNAME\t:\t";
	cin>>username;
	name=username;//save for later use.
	cout<<"\t\t\tPASSWORD\t:\t";
	cin>>password;

	
	in<<username<<" "<<password<<"\n";//save in file
	in.close();
	
	cout<<"\n\t\t\tRegistration Successful!\n";
	Sleep(2000);
}
void login(void)
{
	string un;
	string pw;
	//temp string variable for reading data from file according to saved pattern.
	char notfound;
	bool flag=false;//for checking if data matches.
	
	system("cls");//clears screen for appealing output.	
	ifstream out;
	//file opened.
	//for validating user input from file.
	out.open("logininfo.txt");//reading from file.
	cout<<"\t\tWelcome ! Enter Username and Password to Login\n\n";
	cout<<"\t\tUSERNAME\t:\t";
	cin>>username;
	name=username;//for later use
	cout<<"\t\tPASSWORD\t:\t";
	cin>>password;
	
		while(out>>un>>pw)
		//checks each line in file untill same pattern exists.
		{
			if((un==username)&&(pw==password))
			//checks if user's name and password matches any data from the file.
			{
				flag=true;
				break;
				//immediately stops checking once data matched.
			}
		}
		
	
		if(flag==true)
		//login success and proceeds
		{	
			system("cls");//clears screen
			cout<<"Checking..... Please Wait\n";
			Sleep(4000);
			system("cls");
			cout<<"Log-in Success!";	
			Sleep(2000);
			menu();//proceeds
		}	
		else
		{
			system("cls");//clears screen
			cout<<"\nSORRY!\nNo such account exists.\n\n1.Do you want to register?\n2.Forgot Password.\n3.Login.\n4.Exit.";
			cout<<"\nSelect your choice\t:\t";
			cin>>notfound;
			switch(notfound)
			//further options if user id not found.
			{
				case '1':
					signup();
					login();
					
				break;
				
				case '2':
					forgot();
				break;
				
				case '3':
					login();
					//ends program
				case '4':
					exit(0);
				break;	
				default:
					cout<<"No such option exist.\nGoing Back.....\n";
					login();
					//retakes user choice untill valid input.
				break;	
			}
		}
	out.close();
	//mandatory file closing after successful reading
}


void back(void)
{
	system ("color 3F");
	system("cls");
	cout<<"Your id is being logout ! Please wait"<<endl;
	Sleep(4000);
	system("cls");
	char input=0;//for user's choice.
	
	//intiall display
	cout<<"\n\t***************************************************************************\n\n";
	cout<<"\t\t\t\tPAF-IAST Transport System\n\n";
	cout<<"\t***************************************************************************\n\n";
	cout<<"\t\t\t\t\t1.Login.\n";
	cout<<"\t\t\t\t\t2.Register.\n";
	cout<<"\t\t\t\t\t3.Exit.\n\n";
	cout<<"\t\t\t\t\tSelect your choice  :  ";
	cin>>input;
	
	switch(input)
	{
		case '1':
			login();
		break;	
		
		case '2':
			signup();
			//goes straight to login for validation and booking.
			login();
		break;
		
		case '3':
			break;	
			//ends the execution of program.
	
		default:
			system("cls");
			cout<<"Invalid input!\nTry Again\n";
			back();
			//repeats questioning untill valid input.
		break;	
	}
	
	
}


int main()
{
	system ("color 3F");
	
	string input;//for user's choice.
do
{
	//intiall display
	cout<<"\n\t***************************************************************************\n\n";
	cout<<"\t\t\t\tPAF-IAST Transport System\n\n";
	cout<<"\t***************************************************************************\n\n";
	cout<<"\t\t\t\t\t1.Login.\n";
	cout<<"\t\t\t\t\t2.Register.\n";
	cout<<"\t\t\t\t\t3.Exit.\n\n";
	cout<<"\t\t\t\t\tSelect your choice  :  ";
	cin>>input;
	
	if (input>="1" || input<="3")
	{
	    if (input=="1")
	    {
			login();
		}	
		
		else if (input=="2")
		{
			signup();
			//goes straight to login for validation and booking.
			login();
	    }
		else if (input=="3")
		{
			exit(0);
			//ends the execution of program.
		}
	    else
	    {
			system("cls");
			cout<<"Invalid input!\nTry Again\n";
			main();
			//repeats questioning untill valid input.
	    }
	}
	else
	{
		cout<<"\nWrong input\nEnter again";
	}
}while(input!="3");
}