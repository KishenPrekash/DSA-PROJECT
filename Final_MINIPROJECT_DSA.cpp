#include<iostream>
#include<iomanip>
#include<fstream>
#define SIZE 20
using namespace std;

class item{
	public:
	int Order_Code[20];
	string item_Name[20];
	float price[20];
	int quantity[20];
	float totalPrice;
};

class Node
{
	public:
	int Order_ID;
	string cust_name;
	float Total_Price;
	float totalP;
    char Dine_option;
    item obj[SIZE];
    int quant;
	Node *nextnode;
	
		
	
	Node()
	{
		Order_ID=0;
		cust_name=" ";
	    Total_Price=0.0;
	    Dine_option='X';
	    quant=0;
	    nextnode=NULL;
	    
	    for(int i=0;i<SIZE;i++){
	    	obj[i].Order_Code[i]=0;
	    	obj[i].item_Name[i]=" ";
	    	obj[i].price[i]=0.0;
	    	obj[i].quantity[i]=0;
		}
		
	}

	
};

class Order{
	
	public:
      Node *backPtr; 
	  Node *frontPtr;
      
    void createQueue(){
  	
  	backPtr = NULL; 
	frontPtr = NULL;
  	
   }
  
  bool isEmpty()
  {
  	
  	if(backPtr == NULL && frontPtr == NULL)
  	{
	
  	return true;
  }
  else
  return false;
  	
  	
  }
  
   void enqueue(Node *n1)
    {
    	if(isEmpty())
    	{
    		n1->nextnode=NULL;
    		frontPtr=backPtr=n1;
    		cout<<"Order enqueued succesfully "<<endl;
		}
		else
		{
		  
		  backPtr->nextnode=n1;
          backPtr=n1;
      
            cout<<"Order enqueued succesfully "<<endl;
		}
    }
   
 void find(int x)
    {
        
        Node *temp=frontPtr;
        for(int i=0;temp->nextnode != NULL && temp->Order_ID != x;i++)
        {
		temp = temp->nextnode;
	    }
        if(temp->Order_ID  == x)
        {
            
            cout<<"("<<temp->Order_ID<<","<<temp->cust_name<<","<<temp->Dine_option<<","<<temp->Total_Price<<")";
            cout<<endl;
        }
        else if(temp->nextnode == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
        }
		
void display() 
    {
      if(isEmpty())
      {
        cout << "Queue is Empty" << endl;
      }
    else
    {
       
       Node *temp=frontPtr;
       cout<<left;
       cout<<"---------------------------------------------------------"<<endl;	
	   cout<<setw(15)<<"OrderID "<<setw(10)<<" Name "<<setw(15)<<"Dine Option"<<setw(20)<<"TotalPrice"<<endl;
	   cout<<"---------------------------------------------------------"<<endl;
        while(temp!=NULL)
        {
         cout<<setw(15)<<temp->Order_ID<<setw(10)<<temp->cust_name<<setw(15)<<temp->Dine_option<<setw(20)<<temp->Total_Price<<endl;
         temp=temp->nextnode;
        }
      cout<<endl;
    }

    }
void deleteQueue()
{
	Node *temp=frontPtr;
	if(isEmpty())
      {
        cout << "Queue is Empty. Nothing to be deleted" << endl;
      }
      else
      {
      	frontPtr=temp->nextnode;
		delete temp;
		temp=frontPtr;
		cout<<"Order dequeued succesfully"<<endl;
	  }
      	
	
}

void sortList1() {  
        
        Node *current = frontPtr, *index = NULL;  
        string temp;
        int temp1;
        char temp2;
        float temp3;
		  
          
        if(frontPtr == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                 
                index = current->nextnode;  
                  
                while(index != NULL) {  
               
                    if(current->cust_name > index->cust_name) {  
                        temp = current->cust_name;  
                        current->cust_name = index->cust_name;  
                        index->cust_name = temp;  
                        
                        temp1 = current->Order_ID;  
                        current->Order_ID = index->Order_ID;  
                        index->Order_ID = temp1;
                        
                        temp2 = current->Dine_option;  
                        current->Dine_option = index->Dine_option;  
                        index->Dine_option = temp2;
                        
                        temp3 = current->Total_Price;  
                        current->Total_Price = index->Total_Price;  
                        index->Total_Price = temp3;
                    }  
                    index = index->nextnode;  
                }  
                current = current->nextnode;  
            }      
        }  
    }  
    
    void sortList2() {  
        
        Node *current = frontPtr, *index = NULL;  
        string temp;
        int temp1;
        char temp2;
        float temp3;
		  
          
        if(frontPtr == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                
                index = current->nextnode;  
                  
                while(index != NULL) {  
                   
                    if(current->Total_Price > index->Total_Price) {  
                        temp = current->cust_name;  
                        current->cust_name = index->cust_name;  
                        index->cust_name = temp;  
                        
                        temp1 = current->Order_ID;  
                        current->Order_ID = index->Order_ID;  
                        index->Order_ID = temp1;
                        
                        temp2 = current->Dine_option;  
                        current->Dine_option = index->Dine_option;  
                        index->Dine_option = temp2;
                        
                        temp3 = current->Total_Price;  
                        current->Total_Price = index->Total_Price;  
                        index->Total_Price = temp3;
                    }  
                    index = index->nextnode;  
                }  
                current = current->nextnode;  
            }      
        }  
    } 
      
};


void menu(){
	
	
	cout<<"================================================================================================"<<endl;
	cout<<"|                                           MENU                                                |"<<endl;
	cout<<"|                                          ******                                               |"<<endl;	
	cout<<"|     ********************************                    ********************************      |"<<endl;
	cout<<"|     |        Main Course           |                    |          Appetizers          |      |"<<endl;
	cout<<"|     ********************************                    ********************************      |"<<endl;
	cout<<"|     |01 Lobster Pie -> RM19.95     |                    |06 Nachos  -> RM10.95         |      |"<<endl;
	cout<<"|     |02 Turkey Dinner -> RM13.95   |                    |07 Mushroom Caps -> RM13.75   |      |"<<endl;
	cout<<"|     |03 Prime Rib -> RM20.95       |                    |08 Shrimp Cocktail -> RM12.75 |      |"<<endl;
	cout<<"|     |04 Seafood Alfredo -> RM15.95 |                    |09 Chips -> RM7.50            |      |"<<endl;
	cout<<"|     |05 Shrimp Scampi -> RM18.95   |                    |10 Potato Skins -> RM 10.95   |      |"<<endl;
	cout<<"|      *******************************                    ********************************      |"<<endl;
	cout<<"|     ********************************                    ********************************      |"<<endl;
	cout<<"|     |        Beverages             |                    |          Dessert             |      |"<<endl;
	cout<<"|     ********************************                    ********************************      |"<<endl;
	cout<<"|     |11 Soda -> RM1.95             |                    |16 Sundae  -> RM3.95          |      |"<<endl;
	cout<<"|     |12 Tea -> RM1.50              |                    |17 Carrot Cake -> RM5.95      |      |"<<endl;
	cout<<"|     |13 Coffe -> RM1.25            |                    |18 Mud Pie -> RM4.95          |      |"<<endl;
	cout<<"|     |14 Mineral Water -> RM 2.95   |                    |19 Apple Crisp -> RM5.95      |      |"<<endl;
	cout<<"|     |15 Juice -> RM2.50            |                    |20 Apple Pie -> RM5.95        |      |"<<endl;
	cout<<"|     ********************************                    ********************************      |"<<endl;
	cout<<"================================================================================================"<<endl; 
}

void displayBill(Node *n1,int x)

{      ofstream out;
		out.open("output.txt", ios::out | ios::app | ios::binary);
		
      float sum1=0;
      static int count;
	  count++;
	  out<<"Customer"<<"#"<<count<<endl;
      cout<<left;
      cout<<"-------------------------------------------------------"<<endl;
	  cout<<"|                 RESTRAURANT ABC                     |"<<endl;
	  cout<<"-------------------------------------------------------"<<endl;
	  cout<<"| OrderID= "<<n1->Order_ID<<"    "<<"Customer Name= "<<n1->cust_name<<"  "<<"DineOption= "<<n1->Dine_option<<"  |"<<endl;
	  cout<<"-------------------------------------------------------"<<endl;
	  cout<<setw(10)<<"ItemCode"<<setw(20)<<"ItemName"<<setw(15)<<"Quantity"<<setw(5)<<"Price"<<endl;
	  cout<<setw(10)<<"********"<<setw(20)<<"********"<<setw(15)<<"********"<<setw(5)<<"*****"<<endl<<endl;
	  
	  for(int i=0;i<x;i++)
	  {
	  	sum1=sum1+(n1->obj[i].price[i]*n1->obj[i].quantity[i]);
	  	cout<<setw(10)<<n1->obj[i].Order_Code[i]<<setw(20)<<n1->obj[i].item_Name[i]<<setw(15)<<n1->obj[i].quantity[i]<<"RM "<<(n1->obj[i].price[i]*n1->obj[i].quantity[i]);
	  	cout<<endl<<endl;
	  	
	  	
	  	
	  	out<<"("<<n1->obj[i].Order_Code[i]<<","<<n1->obj[i].item_Name[i]<<","<<n1->obj[i].quantity[i]<<","<<"RM "<<(n1->obj[i].price[i]*n1->obj[i].quantity[i])<<")"<<endl<<endl;
	  
	
	  	
	  	
	  }
	 cout<<"-------------------------------------------------------"<<endl<<endl;
	  cout<<"TotalPrice= RM "<<sum1<<endl;
	  cout<<endl<<endl<<endl;
	  cout<<"-------------------------------------------------------"<<endl;
	  cout<<"|            THANK YOU FOR DINING WITH US!            |"<<endl;
	  cout<<"|                PLEASE COME AGAIN                    |"<<endl;
	  cout<<"-------------------------------------------------------"<<endl;     
	  
}

int   checkpword(string user[],string pword[], int x, string username,string pass)
{
	int temp=-1;
	for(int i=0;i<x;i++)
	{
		if(user[i]==username)
		{
			cout<<"Welcome"<<endl;
			return temp = 0;
			break;
			
		}
		
	}
	
	if(temp==-1)
	{
		
		cout<<"Try again "<<endl;
		return temp;
	}
	
}

 








int main()
{
int menu_option=1,odid;
int item_code[20];
int item_quantity[20];
float item_price[20];
int Course_Quantity;

string item_name[20];
string c_name;
char c,bill;
int order=1;
Order s;
string name[10];
string pword[10];

int op1,op2,op3,op4;
string username=" ";
string password=" ";
bool loginsuccess = false;
ifstream in;
in.open("username&password.txt");

cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                     WELCOME TO                                        |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                              RESTAURANT MANAGEMENT SYSTEM                             |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n"<<endl;





do{
float TotalPrice=0;
B:
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    |RESTAURANT MANAGEMENT SYSTEM|                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    | 1)CUSTOMER                 |                                    "<<endl;
cout<<"                                    | 2)STAFF                    |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl<<endl;

cout<<"Please,Choose from the following options to use the system as : "<<endl<<endl;
cin>>op1;
system("CLS");

if(op1==1)
{
	
	
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    |CUSTOMER                    |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    | 1)MENU                     |                                    "<<endl;
cout<<"                                    | 2)TAKE ORDER               |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;

cout<<"Enter option: "<<endl;
cin>>op2;
system("CLS");	

if(op2==1)
{
   menu();
   
}
else if(op2==2)
{
	Node *n1=new Node();
	menu();
	    cin.ignore();
        cout<<"What is your name: ";
        getline(cin,c_name);
        
        
		cout<<"How many Courses would you like to order: ";
		cin>>Course_Quantity;
		
		for(int i=0;(i<Course_Quantity && i<=20);i++){
		cout<<"Enter Course Menu Code for item #" <<i+1<<":";
		cin>>item_code[i];
		cout<<"Enter Quantity for item #"<<i+1<<":";
		cin>>item_quantity[i];
		
		
		if(item_code[i]==1){
			item_price[i]= 19.95;
			item_name[i]="Lobster Pie";
		}
		if(item_code[i]==2){
			item_price[i]= 13.95;
			item_name[i]="Turkey Dinner";
		}
		if(item_code[i]==3){
			item_price[i]= 20.95;
			item_name[i]="Prime Rib ";
		}
		if(item_code[i]==4){
			item_price[i]= 15.95;
			item_name[i]="Seafood Alfredo";
		}
		if(item_code[i]==5){
			item_price[i]= 18.95;
			item_name[i]="Shrimp Scampi";
		}
		if(item_code[i]==6){
			item_price[i]= 10.95;
			item_name[i]="Nachos";
		}
		if(item_code[i]==7){
			item_price[i]= 13.75;
			item_name[i]="Mushroom Caps";
		}
		if(item_code[i]==8){
			item_price[i]= 12.75;
			item_name[i]="Shrimp Cocktail";
		}
		if(item_code[i]==9){
			item_price[i]= 7.50;
			item_name[i]="Chips";
		}
		if(item_code[i]==10){
			item_price[i]= 10.95;
			item_name[i]="Potato Skins";
		}
		if(item_code[i]==11){
			item_price[i]= 1.95;
			item_name[i]="Soda";
		}
		if(item_code[i]==12){
			item_price[i]= 1.50;
			item_name[i]="Tea";
		}
		if(item_code[i]==13){
			item_price[i]= 1.25;
			item_name[i]="Coffee";
		}
		if(item_code[i]==14){
			item_price[i]= 2.95;
			item_name[i]="Mineral Water ";
		}
		if(item_code[i]==15){
			item_price[i]= 2.50;
			item_name[i]="Juice ";
		}
		if(item_code[i]==16){
			item_price[i]= 3.95;
			item_name[i]="Sundae";
		}
		if(item_code[i]==17){
			item_price[i]= 5.95;
			item_name[i]="Carrot Cake";
		}
		if(item_code[i]==18){
			item_price[i]= 4.95;
			item_name[i]="Mud Pie";
		}
		if(item_code[i]==19){
			item_price[i]= 5.95;
			item_name[i]="Apple Crisp";
		}
		if(item_code[i]==20){
			item_price[i]= 5.95;
			item_name[i]="Apple Pie";
		}
			
}
	cout<<"Dine/in(D) or Take-Away(T)?";
	cin>>c;
	cout<<endl<<endl;
	
	

	for(int i=0;i< Course_Quantity;i++)
	{
     
		TotalPrice = TotalPrice +(item_price[i] * item_quantity[i]); 
			
	}
	
	n1->Order_ID=order;
  n1->cust_name=c_name;
  n1->Dine_option=c;
 n1->Total_Price=TotalPrice;


		
  
  for(int i=0;i<Course_Quantity;i++)
  {
  n1->obj[i].item_Name[i]=item_name[i];
  n1->obj[i].Order_Code[i]=item_code[i];
  n1->obj[i].price[i]=item_price[i];
  n1->obj[i].quantity[i]=item_quantity[i];
  
 
  
  }
  
  system("CLS");
  displayBill(n1,Course_Quantity);

  order++;
  
  s.enqueue(n1);
  
  
  
  
  
  
}





}


else if(op1==2)
{
	system("CLS");
	cout<<"Please Log in below"<<endl;
	do{
		cout<<"Username:  ";
		cin>>username;
		cout<<"Password:  ";
		cin>>password;
		
		if(username=="Manager"&&password=="123456")
		{
			cout<<"\nSuccessful Login\n\n";
			loginsuccess=true;
		}
		else
		{
			cout<<"Incorrect username or password \n";
			cout<<"Please try to login again\n";
			goto B;
		}
	}while(!loginsuccess);
	
   
	
	A:
	
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    |STAFF                       |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    | 1)SEARCH ORDER             |                                    "<<endl;
cout<<"                                    | 2)SORT ORDER               |                                    "<<endl;
cout<<"                                    | 3)DISPLAY ORDER            |                                    "<<endl;
cout<<"                                    | 4)LOGOUT                   |                                    "<<endl;
cout<<"                                    | 5)DELETE ORDER             |                                    "<<endl;
cout<<"                                    | 6)END SYSTEM               |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;

cout<<"Enter Option: ";
cin>>op3;
system("CLS");

if(op3==1)
{
	cout<<"ENTER THE ORDER ID TO SEARCH: ";
	cin>>odid;
	s.find(odid);
	
	goto A;
}
else if(op3==2)
{
	
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    |SORTING                     |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl;
cout<<"                                    | 1)NAME                     |                                    "<<endl;
cout<<"                                    | 2)TOTAL PRICE              |                                    "<<endl;
cout<<"                                    ******************************                                    "<<endl<<endl;

cout<<"ENTER OPTION: ";
cin>>op4;

if (op4==1)
{
	s.sortList1();
	s.display();
	goto A;
}
else if (op4==2)
{
  s.sortList2();
  s.display();
  goto A;
	
}
}
else if(op3==3)
{
	s.display();
	goto A;
}
else if(op3==4)
{
	goto B;
}
else if(op3==5)
{
	s.deleteQueue();
	order--;
	goto A;
}
}
	}while(op3!=6);
	
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
cout<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                            RESTAURANT MANAGEMENT SYSTEM                               |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
}

	              

