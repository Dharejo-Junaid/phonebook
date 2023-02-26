#include <iostream>
#include <fstream>
#include <windows.h>
//#include <cstdio>
//#include <conio.h>
using namespace std;

void phonebook() {
	cout<<"\n\n\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*==*";
	cout<<"\n\t\t\t\t\t|P H O N E  B O O K   A P P L I C A T I O N|";
	cout<<"\n\t\t\t\t\t*==*===*===*===*===*===*===*====*===*===*==*"<<endl;
	cout<<" \t\t\t\t\t\t _______\n ";
	cout<<" \t\t\t\t\t\t|       |\n";
	cout<<" \t\t\t\t\t\t|  [))  |\n";
	cout<<" \t\t\t\t\t\t|_______|\n";
}

// funtion for loding bar;
void loding () {	
	cout<<"\n\t\t\t\t\t\t Loding ";
	char bar=219;
	for(int i=0 ; i<35 ; i++) {
		
        cout<<bar;
	    
        if(i<10) Sleep(300);
		if(i>10 && i<20) Sleep(150);
		if(i>20) Sleep(25);
	}
}

////////// function for print option ;
void printOptions() {
    cout<<"\n\n\t\t\t\t\t\t1. Add CONTACT"<<endl;
	cout<<"\t\t\t\t\t\t2. DISPLAY ALL CONTACT "<<endl;
 	cout<<"\t\t\t\t\t\t3. SEARCH  "<<endl;
 	cout<<"\t\t\t\t\t\t4. DELETE "<<endl;
	cout<<"\t\t\t\t\t\t5. DELET ALL "<<endl;
	cout<<"\t\t\t\t\t\t6. EDIT "<<endl;
	cout<<"\t\t\t\t\t\t7. TOTAL CONTACT "<<endl;
    cout<<"\t\t\t\t\t\t8. Exit "<<endl;
	cout<<"\n\t\t\t\t\t Select Option  :";
}

////// function for checking the input of option either it is valid or not ;
bool isValidInput(string input) {
	
	if(input.length()>1) {
		return false;
	}
	
	if(input[0]=='1' || input[0]=='2' || input[0]=='3' || input[0]=='4' || 
		input[0]=='5' || input[0]=='6' || input[0]=='7' || input[0]=='8') {
			return true;
	}
		
	return false;
}

int menu() {
	string option ;
	
    printOptions();

    do{
        
        cin >> option;

        if(isValidInput(option)) {
            return int(option[0]-'0');
        }

        else {
            cout << "Invalid input\n\n";
            system("pause");
            system("cls");

            phonebook();
            printOptions();
        }

    }while(true);

	return 0;
}
	
	//function of adding contact
void creatcontact() {  
	string ask;
	
	
	 
   	string first_name , last_name, phone_number;
	
	cout<<"\n\t\t\t\t\t\t C R E A T   N E W  C O N T A C T "<<endl;
	cout<<"\n\t\t\t\t\t FIRST NAME  ";
	cin.ignore();
	getline(cin,first_name);
	cout<<"\n\n\t\t\t\t\t LAST NAME ";
	getline(cin,last_name);
	cout<<"\n\n\t\t\t\t\t PHONE ";
	getline(cin, phone_number);
	
	ofstream myfile;
	myfile.open("MyFile.txt",ios::app);
    
	if(myfile.is_open()) {
		myfile<<first_name<<endl<<last_name<<" : [))  "<<phone_number<<endl;
		myfile<<"0"<<endl;
		
		cout<<"\n\n\t\t\t\t\t CONTACT SAVED SUCCESSFULLY ! "<<endl;
		system("pause");
	}
	
    else {
		cout<<"\n\t Error in opening record";
	}
	
    myfile.close();
    
	system("cls");
	phonebook();
}

///funtion for seaching the contact;
void search () {
	bool flag=false;
	system("color 70");
	string f_name;
	cout<<"\n\n\t\t\t\t\t ENTER THE NAME FOR SEARCH :";
	cin.ignore();
	getline(cin,f_name);
	ifstream myfile;
	myfile.open("MyFile.txt");
		
	string para;       /// variable for reading the data of specific name;
	string name;      /// for reading the name from file;
 	while(!myfile.eof()) {
		getline(myfile,name);
		if(name==f_name) {
		    while(!myfile.eof()) {
			    getline(myfile,para);
				if(para!="0") {
				    cout<<"\n\n\t\t\t\t\t  "<<name<<" " << para << endl;
				    flag=true;
		        }
				
                else break;		
			}
		}			
	}
	
    if(flag==false) {
		cout<<"\n\n\t\t\t\t\t Not FOUND IN YOUR CONTACT LIST ";			     	
    }
}
	
	// funtion for delete the contact;
void delet() {	
	
	string f_name;
	
	do {
		system("cls");
		phonebook();
    	
		cout<<"\n\n\t\t\t\t\tENTER THE NAME FOR DELETE CONTACT ";
	
		cin.ignore();
		getline(cin,f_name);
		
		if(!(f_name.length()==0)) break;
		
	}while(true);
	
	fstream myFile;     //// file open here;

	myFile.open("MyFile.txt", ios::in);
		
	string str, allText="";
		
	bool isPresent=false;
		
	while(!myFile.eof()) {		
		getline(myFile, str);
			
		if(str != f_name) {
			allText.append(str+"\n");
		}
		
		else {
			isPresent=true;
			getline(myFile, str);
			getline(myFile, str);
		}
	}
		
	(isPresent)? cout << "\n\t\t\t\t\t CONTACT SUCCESSFULLY DELETED !" << endl : 
		cout << "\n\t\t\t\t\t CONTACT IS NOT EXIT !" << endl;
	
	myFile.close();
	
	myFile.open("MyFile.txt", ios::out);
	myFile<<allText;
	myFile.close();
	
}
	// function for dispaly the contact;
void show () {
   	bool flag=false;

	ifstream myfile;
	myfile.open("MyFile.txt");
		
    cout<<"\n\n\t\t\t\t\t\t";
	string name;
 	while(!myfile.eof()) {
		getline(myfile,name);
		if(name!="0") {
			cout<<name<<" ";
		}
	    
        if(name=="0") {
			cout<<"\n\n\t\t\t\t\t\t";
			flag=true;
		}	    
	}
	
    if(flag==false) {
		cout<<"\n\t\t\t\t\t CONTACT LIST IS EMPTY !";
    }				    
}

/////// function for delete all the contact;	
void deleteAll() {
	fstream myFile;
	myFile.open("MyFile.txt", ios::out);
	myFile<<"";
	myFile.close();
	cout<<"\n\t\t\t\t\t ALL CONTACT ARE DELETED ";
}

	///// function for edit the contact;
	
void edit() {
		
	string name;
	cout << "\n\t\t\t\t\t ENTER THE NAME FOR EDIT: ";
	cin.ignore();
	getline(cin, name);
	
	fstream myFile;    // decelare the file name;

	myFile.open("MyFile.txt", ios::in);     /// file open ;
	
	string str;
	string allText="";
	
	bool isPresent=false;
	
	while(!myFile.eof()) {
		getline(myFile, str);
		if(str == name) isPresent=true;
	}
	
	myFile.close();                         //// file close here;
	
	myFile.open("MyFile.txt", ios::in);   //// file reopen here;
		
	if(isPresent) {
		 
		string allText="";
		
		string newName;
		cout << "\n\t\t\t\t\t ENTER NEW NAME: ";
		getline(cin, newName);
		
		string newLastName;
		cout << "\n\t\t\t\t\t ENTER NEW LAST NAME: ";
		getline(cin, newLastName);
		
		string contact;
		cout << "\n\t\t\t\t\t ENTER NEW CONTACT NUMBER: ";
		getline(cin, contact);
		
		while(!myFile.eof()) {
		    getline(myFile, str);
			
		    if(str != name) {
				allText.append(str+"\n");
			}
			
			else {
				getline(myFile, str);
				getline(myFile, str);
				
				allText.append(newName + "\n");
				allText.append(newLastName + " : [))  " + contact + "\n0\n");
			}
		}
		
		myFile.close();
		myFile.open("MyFile.txt", ios::out);
		myFile<<allText;
		myFile.close();
		cout<<"\n\t\t\t\t\t CONTACT EDITED SUCCEFULLY !";	
				
	}
		
	else {
		cout << "\n\t\t\t\t\tContact is not present" << endl;
	}
}
	
	/// function for counting total contact ;
void totalContacts() {
	fstream myFile;
	myFile.open("MyFile.txt", ios::in);
	
	int countNumbers=0;
	string str="";
	
	while(!myFile.eof()) {
		getline(myFile, str);
		
		if(str=="0") {
			countNumbers++;
		}
	}
		
	myFile.close();	
	cout << "\n\t\t\t\t\tTOTAL CONTACTS ARE: " << countNumbers << endl;
}

int main () {

	system("color F5 ");
	phonebook();   //funcrion call for design of phone book
	loding();     // function call for loding
	system("cls"); 
	
    label:
	
    phonebook();   //funcrion call for design of phone book
	//loding();     // function call for loding
   	 
	 
	int check=menu(); //return value from the function name menu;
    system("cls");
	phonebook();
	
    if(check==1) {
		system("cls");
		phonebook();          // function call for design;
		creatcontact();       // fuction call for add contact;
    }
	
    else if(check==3) {
		system("cls");
		phonebook() ;   
		search();         // function call for search contact;
	}
	
    else if(check==2) {
		show();	 	    	
	}
			
	else if(check==4) {
		delet();
	}
			
	else if(check==5) {
		deleteAll();
	}
			
	else if(check==6) {
		edit();
	}
			
	else if(check==7) {
		totalContacts();
	}

    if(check==8) {
        return 0;
    }

	if(check!=8) {	
		cout<<"\n\t\t\t\t\t";
		system("pause");
		system("cls");
		
		goto label;
	}

    return 0;
}
