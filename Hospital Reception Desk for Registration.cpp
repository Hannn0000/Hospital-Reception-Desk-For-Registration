/**************************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                          */ 
/*	Matric number : (1)147033           & (2)146928											      */
/*	Project Title : HOSPITAL RECEPTION DESK FOR REGISTRATION   								      */
/*	Purpose 		: The purposes of this program is to:                                         */
/*               	 (1)  Record the patient's information and display it on the screen for user. */
/*				 	 (2)  Generate a patient's queue number and print it during registration      */
/* 				 	 (3)  Enhance the efficiency and conveniency for the patient's information    */
/*                    	 handling                                                                 */
/**************************************************************************************************/

#include<iostream>
#include<fstream>
#include<windows.h>
#include <sstream>

using namespace std;

struct Patient
{
	string name,address,nationality,bloodgrp,ic_no,phone_no,age,gender;
};
 

void display_welc();
void display_login(bool,string,string);
void display_menu(int,Patient[]);
void add_patient (Patient[],int);
void search_patient(Patient[],int );
void generate_no(Patient[],int);
void edit_patient(Patient[],int );


int main()
{
	string username,password;
	bool login = false;
	int selection,number,index;
	Patient patient[50];
	display_welc();
	display_login(login,username,password);
	display_menu(selection,patient);
	
}


/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To display welcoming page      											   */
/***********************************************************************************************/
void display_welc()
{
	system("color 0B");
	cout<<"==============================================================================================="<<endl;
	cout<<endl<<endl;	
	cout<<"\tXX    XX  XXXXXXXX  XXXXXXXX  XXXXXXXX  XXXXXXXX  XXXXXXXX  XXXXXXXX  XX        "<<endl;
	cout<<"\tXX    XX  XX    XX  XX        XX    XX     XX        XX     XX    XX  XX        "<<endl;
	cout<<"\tXXXXXXXX  XX    XX  XXXXXXXX  XXXXXXXX     XX        XX     XXXXXXXX  XX        "<<endl;
	cout<<"\tXX    XX  XX    XX        XX  XX           XX        XX     XX    XX  XX        "<<endl;
	cout<<"\tXX    XX  XXXXXXXX  XXXXXXXX  XX        XXXXXXXX     XX     XX    XX  XXXXXXXX  "<<endl;
	cout<<endl<<endl;
	cout<<"\t	xxxx        xxxx    xxxxxxxxxxxxxxxx    xxxxxxxxxxxxxxxx"<<endl;
	cout<<"\t	xxxx        xxxx    xxxxxxxxxxxxxxxx    xxxxxxxxxxxxxxxx"<<endl;
	cout<<"\t	xxxx        xxxx    xxxx                xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxx        xxxx    xxxx                xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxx        xxxx    xxxxxxxxxxxxxxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxx        xxxx    xxxxxxxxxxxxxxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxx        xxxx                xxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxx        xxxx                xxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxxxxxxxxxxxxxx    xxxxxxxxxxxxxxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<"\t	xxxxxxxxxxxxxxxx    xxxxxxxxxxxxxxxx    xxxx  xxxx  xxxx"<<endl;
	cout<<endl<<endl;
	cout<<"==============================================================================================="<<endl;
	cout<<endl<<endl;
	system("pause");
	system("cls");
	
}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To display login page      												   */
/***********************************************************************************************/

void display_login(bool login,string username,string password)
{
	system("color 0A");
	login = false;
	do
	{
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"                                                    SYSTEM LOG IN                                                    "<<endl;               
		cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl<<endl<<endl<<endl;
	
		cout<<"\t\t\t\t\t\tUSERNAME : " ;
		cin >>username;
		cout<<"\t\t\t\t\t\tPASSWORD : " ;	
		cin >>password;
		cout<<"\n\n\n\n\n================================================== Checking starts ====================================================="<<endl;
		Sleep(1500);
		if ((username == "admin") && (password == "12345"))
		{
			cout<<"\n\n\n_______________________________________|---L-O-G-I-N---S-U-C-C-E-S-S-F-U-L---|__________________________________________"<<endl;
			login = true;
		}	
	
		else
		{
			cout<<"\n\n\n____________________________________________|---L-O-G-I-N---F-A-I-L-E-D---|__________________________________________"<<endl;
			cout<<"\n\t\t\t\t\t\tPlease Try Again !" <<endl;
			system("pause");
			system("cls");
		}
	}
	while (login!=true);
	system("pause");
	system("cls");
	
}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To display main menu page      											   */
/***********************************************************************************************/

void display_menu(int selection,Patient patient[])
{
	system("color 0B");
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"                                      HOSPITAL RECEPTION DESK FOR REGISTRATION                                              "<<endl;     
	cout<<"                                                     MAIN MENU                                               "<<endl;            
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t1. Add New Patient"<<endl;
	cout<<"\n\t\t\t\t\t\t2. Edit Patient's information"<<endl;
	cout<<"\n\t\t\t\t\t\t3. Search Patient's information"<<endl;
	cout<<"\n\t\t\t\t\t\t4. Get Queue Number"<<endl;
	cout<<"\n\t\t\t\t\t\t5. Log Out"<<endl<<endl<<endl<<endl;
	cout<<"Please select the number : "<<endl;
	cin >>selection;
	
	if (selection == 1)
	{
		system("cls");
		add_patient (patient,selection); //add patient information
	}
	else if (selection == 2)
	{
		system("cls");
		edit_patient(patient,selection); //edit patient information
	}
	else if (selection == 3)
	{
		system("cls");
		search_patient(patient,selection); //view patient information
	}
	else if (selection == 4)
	{
		system("cls");
		generate_no(patient,selection);//generate queue no
	}
	else if (selection == 5)
	{
		system("cls");
		cout<<"\n\n\n____________________________________________|---L-O-G-G-E-D---O-U-T---|__________________________________________"<<endl;
		cout<<"\n\n\n\t\t\t\t\tThank you for using this system..."<<endl<<endl<<endl<<endl<<endl<<endl;
	}
	else 
	{
		cerr<<"Invalid! Please select again!";
		Sleep(1500);
		system("cls");
		display_menu(selection,patient);
	}
}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To append new patient's information to patient.txt file 				   */
/***********************************************************************************************/

void add_patient (Patient patient[],int selection)
{
	
	char choice;
	int i;
	cout<<"Please enter I.C. number : "<<endl;
	cin >> patient[i].ic_no;

	cout<<"\n\t\t Name : ";
	cin.ignore(50,'\n');
	getline(cin,patient[i].name);
	
	cout<<"\n\t\t Age : ";
	cin >> patient[i].age;
		
	cout<<"\n\t\t Gender : ";
	cin >> patient[i].gender;

	cout<<"\n\t\t Address : ";
	cin.ignore(100,'\n');
	getline(cin,patient[i].address);
		
	cout<<"\n\t\t Nationality : ";
	cin >> patient[i].nationality;
		
	cout<<"\n\t\t Blood Group : ";
	cin >> patient[i].bloodgrp;
		
	cout<<"\n\t\t Phone Number : ";
	cin >> patient[i].phone_no;
		
	cout<<"Enter Y to add patient..."	<<endl;
	cin >> choice;
		
	if((choice=='Y')||(choice=='y'))
	{
		fstream fout("patient.txt",ios::app);
		fout<<patient[i].name<<endl;
		fout<<patient[i].age<<endl;
		fout<<patient[i].ic_no<<endl;
		fout<<patient[i].gender<<endl;
		fout<<patient[i].address<<endl;
		fout<<patient[i].nationality<<endl;
		fout<<patient[i].bloodgrp<<endl;
		fout<<patient[i].phone_no<<endl;
		fout.close();
		i++;
		cout<<"New Patient's information added!"<<endl;
		cout<<" Press any key to back to main menu..."<<endl<<endl<<endl;
		system("pause");
		system("cls");
		display_menu(selection,patient);
		
	}
	else
	{	
		
		system("cls");
		display_menu(selection,patient);	
	}

}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To search and display certain patient's information      				   */
/***********************************************************************************************/

void search_patient(Patient patient[],int selection)
{
	
	ifstream fin("patient.txt");
	string code;
	int index;
	cout<<"Please enter your I.C. number : ";
	cin >>code;
	cout<<endl<<endl;
	for (int i = 0; fin.good();i++)
	{
		getline(fin,patient[i].name);
		getline(fin,patient[i].age);
		getline(fin,patient[i].ic_no);
		getline(fin,patient[i].gender);
		getline(fin,patient[i].address);
		getline(fin,patient[i].nationality);
		getline(fin,patient[i].bloodgrp);
		getline(fin,patient[i].phone_no);
		
	
    	if (code == patient[i].ic_no)
		{
		
			cout<<"\t\t\t"<<patient[i].name<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].age<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].ic_no<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].gender<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].address<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].nationality<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].bloodgrp<<endl<<endl;
			cout<<"\t\t\t"<<patient[i].phone_no<<endl<<endl<<endl<<endl;
		 
		}
		
	}	
	system("pause");
	system("cls");
	display_menu(selection,patient);	
}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To edit certain patient's information and update patient.txt file      	   */
/***********************************************************************************************/

void edit_patient(Patient patient[],int selection)
{
	ifstream fin ("patient.txt");
	ofstream fout ("temp.txt");
	string a;
	cout<<"Enter I.C. number to edit information : "<<endl;
	cin >> a;
	
	for (int i = 0; fin.good(); i++)
	{
		getline(fin,patient[i].name);
		getline(fin,patient[i].age);
		getline(fin,patient[i].ic_no);
		getline(fin,patient[i].gender);
		getline(fin,patient[i].address);
		getline(fin,patient[i].nationality);
		getline(fin,patient[i].bloodgrp);
		getline(fin,patient[i].phone_no);
		
		if (a == patient[i].ic_no)
		{
			cout<<"\n\n\n\nPlease type in the new information..."<<endl;
			cout<<"\n\t\t Name : ";
			cin.ignore(50,'\n');
			getline(cin,patient[i].name);
	
			cout<<"\n\t\t Age : ";
			cin >> patient[i].age;
		
			cout<<"\n\t\t Gender : ";
			cin >> patient[i].gender;
			
			cout<<"\n\t\t Address : ";
			cin.ignore(100,'\n');
			getline(cin,patient[i].address);
		
			cout<<"\n\t\t Nationality : ";
			cin >> patient[i].nationality;
				
			cout<<"\n\t\t Blood Group : ";
			cin >> patient[i].bloodgrp;
			
			cout<<"\n\t\t Phone Number : ";
			cin >> patient[i].phone_no;
			
			fout<<patient[i].name<<endl<<patient[i].age<<endl<<patient[i].ic_no<<endl<<patient[i].gender<<endl<<patient[i].address<<endl<<patient[i].nationality<<endl<<patient[i].bloodgrp<<endl<<patient[i].phone_no<<endl;
		}
		
		else
		{
			fout<<patient[i].name<<endl<<patient[i].age<<endl<<patient[i].ic_no<<endl<<patient[i].gender<<endl<<patient[i].address<<endl<<patient[i].nationality<<endl<<patient[i].bloodgrp<<endl<<patient[i].phone_no<<endl;
		}
	}
	fin.close();
	fout.close();

	ifstream finn ("temp.txt");
	ofstream foutt ("patient.txt");
	
	for (int j = 0; finn.good(); j++)
	{
		getline(finn,patient[j].name);
		getline(finn,patient[j].age);
		getline(finn,patient[j].ic_no);
		getline(finn,patient[j].gender);
		getline(finn,patient[j].address);
		getline(finn,patient[j].nationality);
		getline(finn,patient[j].bloodgrp);
		getline(finn,patient[j].phone_no);
		foutt<<patient[j].name<<endl<<patient[j].age<<endl<<patient[j].ic_no<<endl<<patient[j].gender<<endl<<patient[j].address<<endl<<patient[j].nationality<<endl<<patient[j].bloodgrp<<endl<<patient[j].phone_no<<endl;
	}
	foutt.close();
	finn.close();
	remove("temp.txt");
	cout<<"Patient's information updated! Press any key to back to main menu..."<<endl;
	system("pause");
	system("cls");
	display_menu(selection,patient);
}

/***********************************************************************************************/
/*	Programmers   : (1)TAN SHU HAN      & (2)SUI YUN HEN                                       */ 
/*	Purpose       : To generate and print queue number for patient     						   */
/***********************************************************************************************/

void generate_no(Patient patient[],int selection)
{
	bool generate = true;
	string department;
	int select;
	static int count(1001);
	cout<<"\n\n\t\t\t\t\t\t1. Cardiologist"<<endl;
	cout<<"\n\t\t\t\t\t\t2. Ear, Nose and Throat"<<endl;
	cout<<"\n\t\t\t\t\t\t3. Skin"<<endl;
	cout<<"\n\t\t\t\t\t\t4. Bone and Joint"<<endl;
	cout<<"\n\t\t\t\t\t\t5. Child and Baby"<<endl;
	cout<<"\n\t\t\t\t\t\t6. Others"<<endl<<endl<<endl<<endl;
	
	cout<<"Please select the department : ";
	cin >> select;
	if (select == 1)
	{
		department = "CARDIOLOGIST";
		generate = true;
	}

	else if (select == 2)
	{
		department = "EAR, NOSE AND THROAT SPECIALIST";
		generate = true;

	}
	else if (select == 3)
	{
		department = "SKIN SPECIALIST";	
		generate = true;	
	}

	else if (select == 4)
	{
		department = "BONE AND JOINT SPECIALIST";	
		generate = true;	
	}

	else if (select == 5)
	{
		department = "CHILD AND BABY SPECIALIST";
		generate = true;
	}

	else if (select == 6)
	{
		department = "OTHERS";
		generate = true;
	}
	
	else
	{
		cerr<<"Invalid option! ";
		generate = false;
		system("pause");
		system("cls");
		display_menu(selection,patient);
	}

	if(generate == true)
	{
		cout<<"\t\t\t\t\t\t"<<department<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t\tYour queue number is : "<<count;
		cout<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t\tYour queue number is generated... "<<count<<endl<<endl;
	
	
		string queue_no;
		stringstream ss;  
		ss<<count;  
		string s;  
		ss>>s;  
		queue_no=(s+".txt");
		ofstream fout ;

    	fout.open(queue_no.c_str());
    
	
		fout<<"\t\t************************************************************"<<endl;
		fout<<"\t\t                       HOSPITAL USM "<<endl;
		fout<<"\t\t************************************************************"<<endl<<endl<<endl;
		fout<<"\t\t\t\tDepartment : "<<department<<endl<<endl;
		fout<<"\t\t\t\tYour queue number is : "<<endl<<endl;
		fout<<"\t\t\t\t\t"<<count;
		fout<<endl<<endl<<"\t\t\t\t"<<__TIMESTAMP__<<endl<<endl;
		count ++ ;
		system("pause");
		system("cls");
		display_menu(selection,patient);
	}

}







