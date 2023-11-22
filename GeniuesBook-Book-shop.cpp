#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void login();
void registr();
void forgot();

const int maxrow = 50 ;

string BookID    [maxrow] = {};
string BookName  [maxrow] = {};
string BookNo    [maxrow] = {};
string BookPrice [maxrow] = {};

void OpenFile()
	
	{
		string line;
		ifstream myfile ( "GeniusBOOK bookshop book list.txt");
		if (myfile.is_open())
		
			{
				int x=0;
				while (getline(myfile, line))
				
					{
						int l = line.length();
						BookID  [x] = line.substr(0,4);
						BookName[x] = line.substr(12,8);
						BookNo	[x] = line.substr(5,2);
						BookPrice[x]= line.substr(8,3);
						x++;
							
					}				
				
			}
			else
			{
				cout <<"Was able to Open the File !!!"<<endl;
			}
	}
	
	void CreateBook ()	 //New Added Book function Programmer
	{
		char bkID  [100];
		char bkName[100];
		char bkNo  [100];
		char bkpr  [100];
			
			cin.ignore();
			
		cout<<"~ Enter the Book ID  (BookID - Max 100 )       =: ";
		cin.getline(bkID , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Book Name                          =: ";
		cin.getline(bkName , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Number of Books (BookNo - Max 100) =: ";
		cin.getline(bkNo , 100);
		cout<<"  "<<endl;
		
		cout<<"~ Enter the Book Price 				          =: ";
		cin.getline(bkpr ,100 );
		cout<<" "<<endl;
			
			for (int x=0 ; x<maxrow ; x++)
				{
					if (BookID[x]== "\0 ")
						{
					
							BookID    [x] =bkID ;
							BookName  [x] =bkName ;
							BookNo    [x] =bkNo ;
							BookPrice [x] =bkpr;
							break;
						
						}
				}
		
		}
		
	void  UpdateBook (string search)
	
	{
		char bkID  [100];
		char bkName[100];
		char bkNo  [100];
		char bkpr  [100];
		
		int counter = 0;
		
		for ( int x = 0 ; x<maxrow ; x++)
			{
				if (BookID[x]==search)
				
				{
					
						counter++;
						
						cout<<"Name of the book              :=" ;
						cin.getline(bkName, 100);
						BookName[x]=bkName;
						
						cout<<"Number of the book           := ";
						cin.getline(bkNo , 100);
						BookNo[x]=bkNo;
						
						cout<<"Price of the book 			  := ";
						cin.getline(bkpr , 100);
						BookPrice[x]=bkpr;
						
						cout << " ...Updated Successfully !!!... "<<endl;
					
				}
						
			}
			
			if (counter == 0)
			
			{
				cout << "#######The Book ID doest not exist !!!####### "<<endl;
			}
			
	}	
	
	void DeleteBook (string search)	
	{
		int counter = 0 ;
		for (int x=0 ; x<maxrow ; x++)
		{
			if (BookID[x]==search)
			{
				counter++;
				
					counter++;
					
					BookName[x]="";
					BookID	[x]="";
					BookNo	[x]="";
					BookPrice[x]="";
				
				cout << " ****Deleted Successfully!!!**** " <<endl;
				break;
			}
		}
			
		if (counter==0)
			{
				cout << "##### The Book ID Number  does not exist!!#####";
				
			}
	}

 	void SearchBook (string search)
 	{
 		system ("CLS ");
		cout<< " GeniusBook Book Shop Item Details"<<endl;
		cout<< "=================================================="<<endl;
		
		int counter=0;
		for(int x=0 ; x<maxrow ; x++)
		{
			if (BookID[x]== search)
			{
				counter++;
				cout<<"                     "<<counter<<"  "<<BookID[x]<< "          "<<BookName[x]<<"         "<<BookNo[x]<<"              "<<BookPrice[x]<<endl;
				break;
			}
		}
		if (counter==0)
			{
				cout<<" .......Book Not Found!!!....... !!!" <<endl;	 
			}
		cout<<"==========================================================="<<endl;	 
	}
	
	void ShowBook()
	
	{
		system ("CLS");
		cout<<"                                 ~~~~~~~~~~~GeniuesBook Book shop List~~~~~~~~~~~~ "<<endl;
		cout<< "             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
		int counter =0 ;
		cout <<"                    Page  | Book ID  | Book Name | Book No:s  |  Book Price "  <<endl<<"                    =============================================================\n";
		for (int x=0 ; x<maxrow ; x++)
		{
			if (BookID[x] != "\0")
			{
				counter++;
				cout<<"                     "<<counter <<"        "<<BookID[x] <<"        "<<BookName[x] <<"       "<<BookNo[x] <<"            "<<BookPrice[x] << endl;
			
			}
		}
		if (counter==0)
		{
			
		    cout<< "                            Please let us know if there is any problem\n" <<endl;
			cout<< "                              	Email : anuja.ellepola@gmail.com  " <<endl;
			cout<< "                               	  Mobile : +94 767 327 371 " <<endl;
			cout<< "                                   	  Thank You !!!\n" <<endl;
		}
		
		cout<<"                   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<endl;
	
		
	}
	
	void SaveFile()
	{
		ofstream myfile;
		myfile.open("database.txt");
		for(int x=0 ; x<maxrow ; x++)
		{
			if (BookID[x]== "\0")
			{
				break;
			}
		else	
			{
				myfile<<BookID[x] + " "+ BookNo[x] +" "+ BookPrice[x] + " "+ BookName[x] <<endl;
			}
		
		}
	}
	
	
int main()

{

	int Start;
	
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout<<"************************************** Welcome to  GeniusBook Bookshop *******************************************\n\n";
    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"********************************************* MENU ********************************************************\n\n";
	cout<<" \n\t\t\t\t\t1 . Sign UP "<<endl;
	cout<<" \n\t\t\t\t\t2 . Book List "<<endl;
	
	cout<<"\n\t~~Enter the selection:= ";
	cin>>Start;
		switch (Start)
			{
				case 1:
					system("CLS");
					break;
				case 2:
					 ShowBook();
					break;	
					
				default:	
					system("CLS");          
                    main();	
			}




	int choice;
		
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
    cout<<"**************************************  Welcome to the GeniusBook Bookshop  *******************************************\n\n";
    cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"********************************************* MENU *********************************************************\n\n";
        
        cout<<"\t\t\t\t\t1.LOGIN"<<endl;
        cout<<"\t\t\t\t\t2.REGISTER"<<endl;
        cout<<"\t\t\t\t\t3.FORGOT PASSWORD"<<endl;
        cout<<"\t\t\t\t\t4.Exit"<<endl;
        cout<<"\n\n\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"//@//@//@ Thanks for using this program //@//@//@\n";
                        break;
                default:
                        system("CLS");
                        cout<<"You've made a mistake , Please Try Again\n"<<endl; 
                        main();
        }
      
	  
	    
}
void login()
{
		
	 
        int count;
        string user,pass,u,p;
        system("CLS");
        cout<<"\n~~~~~~~~~~~~~~~~~~ Please enter the following details ~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"\n\n\t\t ~ USERNAME :";
        cin>>user;
        cout<<"\n\n\t\t ~ PASSWORD :";
        cin>>pass;
        
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
        
                {
                        count=1;
                        system("CLS");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello  "<<user<< " Welcome to GeniusBook BookShop "<<"\n~~~~~~~~~~~~~~~~~~LOGIN SUCCESS~~~~~~~~~~~~~~~~~~\nWe're glad that you're here.\nThanks for logging in\n";
    	 }
    	 
    	      else
       {
               cout<<"\nLOGIN ERROR\nPlease check your Username and Password\n";
               main();

               
       }

 	std :: cout <<" GeniusBOOK ";
	int Option;
	string BKID;
	system (" CLS ");
	OpenFile();
	

		do 
			{	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome To to GENIUS BOOKS bookshop ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n "<<endl;
			  	 
		
			  	 
				cout << " \t\t\t\t\t 1 - Create Book   " <<endl;
				cout << " \t\t\t\t\t 2 - Update Book   " <<endl;
				cout << " \t\t\t\t\t 3 - Delete Book   " <<endl;
				cout << " \t\t\t\t\t 4 - Search Book   " <<endl;
				cout << " \t\t\t\t\t 5 - Display Book List   " <<endl;
				cout << " \t\t\t\t\t 6 - Save and exit Records   " <<endl;
				cout<<""<<endl;cout<<endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" <<endl;
				
				cout << "Please  Select an Option =: ";
				cin>>Option;
				
				cout<<endl;
				
					switch (Option)
						{
							case 1 :CreateBook();
									system (" CLS ");
									break;
									
							case 2 :
									cin.ignore();
									cout<<"Enter the Book ID of which book to be updated :=";
									getline(cin ,BKID);
									UpdateBook(BKID);
									system("CLS");
									
									break;		
							case 3:
									cin.ignore();
									cout<<"Enter the Book ID of which book to be deleted:=";
									getline(cin, BKID);
									DeleteBook(BKID);
									system("CLS");
									cout<<"  "<<endl;
									break;
									
							case 4 :
									cin.ignore();
									cout<<"Enter the Book ID of which book to be searched:=";
									getline(cin,BKID);
									SearchBook(BKID);
									cin.ignore();
									system("CLS");
									cout<<"  "<<endl;
									break;
													
							
							case 5 : ShowBook();
									break;	
									
					
							
						}
			} while (Option !=6);
			

			
				SaveFile();
				cout<< "..............Exit.............Saved to file !!!! "<<endl<<endl; //final 
				cout<< "~~~~~~~~~~~  Thank You !!! ~~~~~~~~~~ " <<endl;
			  	
      		
    
                cin.get();

             
                main();

   
}


void registr()
{
        
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the USERNAME :=";
        cin>>reguser;
        cout<<"\nEnter the PASSWORD :=";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nSuccessfully Resgistered\n";
        main();
        
        
}

void forgot()
{
        int ch;
        system("CLS");
        cout<<"Did you forget your Username or Password? We're here for help\n" ;
        cout<<"\t 1.Search your  by USERNAME "<<endl;
        cout<<"\t 2.Search your  by PASSWORD \n"<<endl;
        cout<<"\t 3. Main menu \n"<<endl;
        cout<<"Enter your choice 1 or 2  :=";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter the Username you remember:=";
                        cin>>searchuser;
                        
                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nYeahhh, Account found\n";
                                cout<<"\nYour PASSWORD is  =: "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry!!!!, Your USERNAME is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the Password you remember:=";
                        cin>>searchpass;
                        
                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }       
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\n\nYeahhh, Account found\n";
                                cout<<"\nYour USERNAME is := "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry!!!!, Your PASSWORD is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                
                        break;
                }
                
                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry!!, You choice was wrong. Try again........."<<endl;
                        forgot();
        }
}


