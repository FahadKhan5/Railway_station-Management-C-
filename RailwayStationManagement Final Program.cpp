#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void intro()
{
     system("color 03");
     system("cls");
  cout<<"\t\t\t\t*\t*";
  cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t*******\t*******";
   cout<<"\t\t\t\t******\t******";
   cout<<"\t\t\t\t*****\t*****";
   cout<<"\t\t\t\t****\t****";
   cout<<"\t\t\t\t***\t***";
   cout<<"\t\t\t\t**\t**";
   cout<<"\t\t\t\t*\t*";
}

static int p = 0;
class Train_Reservation
{
  char trainn[5];
  char driver[10];
  char arrival[5];
  char depart[5];
  char from[10];
  char to[10];
  char seat[8][4][10];

public:
  void add_train();
  void reserve_train();
  void empty();
  void show_train();
  void is_train_available();
  void position(int i);
}

train[10];

void Train_Reservation::add_train()
{
  cout<<"Enter train number: ";
  cin>>train[p].trainn;

  cout<<"Enter Driver's name: ";
  cin>>train[p].driver;

  cout<<"Arrival time: ";
  cin>>train[p].arrival;

  cout<<"Departure: ";
  cin>>train[p].depart;

  cout<<"From: ";
  cin>>train[p].from;

  cout<<"To: ";
  cin>>train[p].to;

   cout<<"\n Added Successfully....";

  train[p].empty();
  p++;

  getch();

}

void Train_Reservation::reserve_train()
{
  int seat;
  char number[5];
  top:
  cout<<"Train number: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(train[n].trainn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this train.";
    }
    else
    {
      if (strcmp(train[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>train[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct train no.\n";
      goto top;
    }
    cout<<"\n Added Successfully....";
	getch();
  }


void Train_Reservation::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(train[p].seat[i][j], "Empty");
    }
  }
}

void Train_Reservation::show_train()
{
  int n;
  char number[5];
  cout<<"Enter train number: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(train[n].trainn, number)==0)
    break;
  }
  while(n<=p)
  {
  	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  	cout<<"Train no: "<<train[n].trainn
  	<<"\nDriver: "<<train[n].driver<<"\nArrival time: "
  	<<train[n].arrival<<"\nDeparture time: "<<train[n].depart
  	<<"\nFrom: "<<train[n].from<<"\nTo: "<<
  	train[n].to<<"\n";
  	cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  	train[0].position(n);

  	int a=1;
  	for (int i=0; i<8; i++)
  	{
    	for(int j=0;j<4;j++)
    	{
      	a++;
      	if(strcmp(train[n].seat[i][j],"Empty")!=0)
      	cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<train[n].seat[i][j]<<".";
    	}
  	}
  	break;
  	}
  	if(n>p)
    	cout<<"Enter correct train no: ";

  	getch();
}

void Train_Reservation::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(train[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<train[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<train[l].seat[i][j];
        }
      }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in Train Number: "<<train[l].trainn;
  }

void Train_Reservation::is_train_available()
{
  for(int n=0;n<p;n++)
  {
  		cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    	cout<<"Train number: "<<train[n].trainn<<"\nDriver: "<<train[n].driver
    	<<"\nArrival time: "<<train[n].arrival<<"\nDeparture Time: "
    	<<train[n].depart<<"\nFrom: "<<train[n].from<<"\nTo: "
    	<<train[n].to;
    	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  }
getch();
}

int main()
{
system("cls");
int w;
while(1)
{
system("cls");
    intro();

  cout<<"\n";
  cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\t\t\t1. Add Train\n\t\t\t"
  <<"2. Reservation\n\t\t\t"
  <<"3. Show Train\n\t\t\t"
  <<"4. Exit \n\t\t\t";
  //<<"5. Exit";
  cout<<"\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  train[p].add_train();
      break;
    case 2:  train[p].reserve_train();
      break;
    case 3:  train[0].show_train();
      break;
    case 4:  exit(0);
  }
}
return 0;
}


