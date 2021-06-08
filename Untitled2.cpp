#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

int c1;
int seat_arr[10];
int zee;
int Display()              //display() function
{
    cout<<"                           WELCOME TO THE CINEMA WORLD\n\n";
    cout<<"WE HAVE A WIDE RANGE OF CHOICES BEFORE U BOOK YOUR TICKET\nU CAN FIRST CHECK THE REVIEWS AND THEN BOOK THE TICKETS\nALL LATEST MOVIES ARE AVAILABLE \n\n";
    cout<<"\n1.MOVIES  \n\n2.REVIEWS\n";
    cout<<"\nPRESS 1 FOR BOOKING AND 2 FOR THE REVIEWS : ";
    cin>>c1;
    return c1;
}

int Movies()                                   //movies() function
{
	system("color 06");
    system("cls");
    void Ticket_available(int check1,int check2);//prototype
    int movies_count=0,movies_number;
    char Movies_arr[100];
    fstream file_movies("movies.txt",ios::in);
    cout<<"\nAvailable Movies are: \n";
    while(!file_movies.eof())
    {
        movies_count++;
        file_movies.getline(Movies_arr,100);
        cout<<endl<<movies_count<<". "<<Movies_arr<<endl<<endl;
    }
    file_movies.close();
    cout<<"\nEnter The No. To Check For Available Tickets \n";
    cin>>movies_number;
    Ticket_available(movies_number,movies_count);
    return movies_number;
}

void Booking()              //booking() function
{
    void Select_seats();//prototype
    int seats_available=100;
    cout<<"\n\nTotal Available Seats Are: "<<seats_available;
    cout<<"\n\nPress Enter  To Select Seats: \n";
    Select_seats();
}
void Select_seats()               //select_seats() function
{
	system("color 0c");
    void Confirm_booking();//prototype
    int seat_number=1,select;
    char ch='A';
    cout<<endl<<endl<<endl;
    cout<<"                                    SCREEN\n";
    cout<<"                      =======================================\n";
    cout<<"                      =======================================\n";
    cout<<"                      =======================================\n";
    cout<<"\n\nEXIT                                                                        EXIT\n\n";
    for(int i=1;i<=10;i++)
    {
       cout<<ch<<"    ";
       for(int j=1;j<=5;j++ )
       {
	 if(seat_number>=1&&seat_number<=9)
	    cout<<"0"<<seat_number<<"   ";
	 else
	    cout<<seat_number<<"   ";
	  seat_number++;
       }
       cout<<"                      ";
       for(int k=1;k<=5;k++)
       {
	   if(seat_number>=1&&seat_number<=9)
	      cout<<"0"<<seat_number<<"   ";
	   else
	      cout<<seat_number<<"   ";
	  seat_number++;
       }
    cout<<endl;
    ch++;
    }
    cout<<"\n\nHow Many Seats Do You Want?(Max 10): ";
    cin>>select;
    while(select>10)
    { if (select>10)
      cout<<"maximum only 10";
      cout<<"\n\nHow Many Seats Do You Want?(Max 10): ";
      cin>>select;
      if (select<10)
      break;
    }
    cout<<"\nStart Entering The Seat Numbers: ";
    for(zee=0;zee<select;zee++)
      {
          cin>>seat_arr[zee];
          while(seat_arr[zee]>100)
          {
          	if(seat_arr[zee]>100)
          	cout<<"\nPLEASE ENTER A VALID SEAT NUMBER";
          	cout<<"\nStart Entering The Seat Numbers: ";
          	cin>>seat_arr[zee];
		  }
	  }  
	  Confirm_booking();
}

void Confirm_booking()     //confirm_booking() function
{
	system("color 08");
    char ch='n';
       while (ch=='n')
       {
          cout<<"\nConfirm Booking?(y/n) ";
          cin>>ch;
          if(ch=='n')
          {
              system("cls");
              Select_seats();
          }
          else
              break;
       }
    system("cls");
    cout<<"\nBooking Confirmed!!!\n";
}

void Ticket_available(int check1,int check2)    //ticket_available(() function
{
    while(1){
       if(check1>=1&&check1<=check2){
               system("cls");
               cout<<"\nSearching is in progress...\n";
               _sleep(2000); // time in milliseconds//delay(2000);
               //system("cls");
               Booking();
               break;
        }
       else{
           cout<<"\nEnter The Correct No. ";
           cin>>check1;
           cout<<endl;
       }
    }
}

void Reviews()
{
	system("color 09");
    char reviews_arr[100];
    fstream file_reviews("reviews.txt",ios::in);
    while(!file_reviews.eof())
    {
        file_reviews.getline(reviews_arr,100);
        cout<<endl<<reviews_arr<<" "<<endl;
    }
    file_reviews.close();
}

int main()
{
	system("color 04");
    void movie_bill(int[],int);//prototype
    char ch='y';
    int Result_Display,Result_Movies;
    while(ch=='y'||ch=='Y')
    {
       system("cls");
       Result_Display=Display();
       if(Result_Display==1)
       {
           Result_Movies=Movies();
           cout<<"\nWanna Continue Booking?(y/n)";
           cin>>ch;
           if(ch=='n') break;
       }
       else if(Result_Display==2)
        {
           Reviews();
           cout<<"\nWanna Continue Booking?(y/n)";
           cin>>ch;
           if(ch=='n') break;
        }
    }
    system("cls");
    movie_bill(seat_arr,Result_Movies);
    cout<<"\nThank You Visit Again !!!\n";
       return 0;
}
void movie_bill(int seat_arr[],int line_no)
{
	char str[100];
    ifstream file("movies.txt",ios::in);
    for(int i=1; i<=line_no && !file.eof(); ++i)
        file.getline(str,100);
    if(!file.bad() && !file.fail())
    cout<<str;
    cout<<endl;
    cout<<"Seat Nos: ";
    for(int k=0;k<zee;k++)
    {
        cout<<seat_arr[k]<<" ";
    }
    cout<<"\nPLEASE TAKE THIS BILL WHILE GOING FOR THE MOVIE\nTHIS IS SAVED IN A FILE NAMED BILL.TXT\n\nENJOY YOUR MOVIE WITH OUR NEW IMPROVED BUTTER POP-CORN\n";
    fstream bill;
    bill.open("bill.txt",ios::out);
    bill<<"                        THE CINEMA WORLD\n\n                            TAKE THIS BILL\n\n";
    bill<<"\nSEAT NUM : ";
    for(int k=0;k<zee;k++)
    {
        bill<<seat_arr[k]<<" ";
    }
    bill<<endl;
    bill<<"MOVIE NAME : ";
    bill<<str<<endl;
    bill<<"\nCODE : 2795\n\n!!!THANK U VISIT AGAIN!!!";
    bill.close();
}
