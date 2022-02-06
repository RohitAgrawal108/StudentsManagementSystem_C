/***********************Course Project:PSAP**************************/
/***********************Student Manegement System********************/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
/***********structure student info*********/
struct student
{
	char first_name[20];
	char mid_name[20];
	char last_name[20];
	char gender;
	int age;
	char mob_no[11];
	char mail_id[40];
	//int reg_no;
	char div;
	int roll_no;
} ;
/*********functions*********/
struct student s;
void welcome() ;
void title() ;
void login() ;
void main_manu() ;
void Add_rec() ;
void List_rec() ;
void Search_rec() ;
void Edit_rec() ;
void Delete_rec() ;
void gotoxy(short x,short y) 
{
	COORD pos={x,y} ;//set co-ordinates in (x,y)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos) ;
}
/***********variables***********/
int valid;
int ok ;
/******************Main Function**********/
int main()
{
	welcome();
	title();
	login();
	return 0 ;
}
/***************************welcome**********************************/
void welcome()
{
	printf("\n\n\n\n\n") ;
	printf("\t\t\t\t*****************************************\n") ;
	printf("\t\t\t\t#\t\t WELCOME \t\t#\n") ;
	printf("\t\t\t\t*****************************************\n") ;
	printf("\n\n\n\n\n\n\n\n\n\n") ;
	printf("press any key to continue.......\n") ;
	getch() ;
	system("cls") ;
}
/***************************title**********************************/
void title()
{
	printf("\t#################################################################################################################\n") ;
	printf("\t\t\t\t\t\t------------SCHOOL\n") ;
	printf("\t#################################################################################################################\n") ;
}
/*****************************login********************************/
void login()
{
	int nl;
	char user_name[20], pass_word[20];
	char uname[20] = "rohit" ;
	char pass[20] = "7201" ;
	printf("\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t********LOGIN*******\n") ;
	nl = 0;
	do{
		printf("\n\n\n\n\t\t\t\tEnter Username And Password :\n") ;
		printf("\n\t Username : ") ;
		scanf("%s",user_name) ;
		printf("\n\t Password :") ;
		scanf("%s",pass_word) ;
		if (strcmp(user_name, uname) == 0 && strcmp(pass_word,pass) == 0)
		{
			printf("\n\n\n\t\t########## Login Successful ##########\n") ;
			getch() ;
			main_manu() ;
		}
		else
		{
			printf("\n\n\n\t Incorrect Username or Password !\n") ;
			nl++ ;
			getch() ;
			system("cls") ;
		}
	}while(nl<3) ;
	if(nl>=3)
	{
		printf("\t\t\t\tMany Attempts !\n \t\t\tyou cant login now !") ;
		getch() ;
		exit(0);//Exit function
	}
}
/***************************main_manu******************************/
void main_manu()
{
	int option ;
	title();
	printf("\n\n\t\t\t1. Add Student Records \n") ;
	printf("\n\t\t\t\t2. List Students records\n") ;
	printf("\n\t\t\t\t3. Search Student Records\n") ;
	printf("\n\t\t\t\t4. Edit Student Records \n") ;
	printf("\n\t\t\t\t5. Delete Student Records\n") ;
	printf("\n\t\t\t\t6. Exit...\n\n\n\n\n\n") ;
	printf("\t\t\t\tchoose a option from 1 to 6 : ") ;
	scanf("%d",&option) ;
	switch(option)
	{
		case 1:
			Add_rec() ;
			break;
		case 2:
			List_rec() ;
			break;
		case 3:
			Search_rec();
			break;
		case 4:
			Edit_rec() ;
			break;
		case 5:
			Delete_rec();
			break;
		case 6:
			exit(0) ;
			break;
		default :
			printf("Incorrect option!\n Please enter correct option!");
			
	}
}
/**************************Add_records**************************/
void Add_rec() 
{
	char ans;//used to recoll fuction
	title() ;
	FILE*ad;
	ad = fopen("Rohit.txt","a") ;
	printf("\t\t\t\t///Add Student Records///\n\n\n") ; 
	/*********First Name**********/
	A:
	printf("\n\t\t\tFirst Name:") ;
	scanf("%s",s.first_name) ;
	s.first_name[0] = toupper(s.first_name[0]) ;//to convert first alphabet to capital
	for(int  i=1 ; i<=strlen(s.first_name)-1 ; i++)
	{
		s.first_name[i] = tolower(s.first_name[i]) ;
	}//to convert other alphabates to small
	if(strlen(s.first_name)>20 || strlen(s.first_name)<3) 
	{
		printf("\n\n\t\t\t\t\tInvalid!\n\t\t(first name contains atleast 2 char atmost 20)\n\n\n") ;
		goto A;
	}
	else
	{
		for(int j=0 ;j <= strlen(s.first_name)-1 ; j++ )
		{
			if(isalpha(s.first_name[j])) 
			valid = 1;
			else
			{
				valid = 0 ;
				break;
			}
		}
		if(!valid)
		{
			printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
			goto A ;
		}
	}
	/*********Middle Name**********/
	B:
	printf("\n\t\t\tMiddle Name:") ;
	scanf("%s",s.mid_name) ;
	s.mid_name[0] = toupper(s.mid_name[0]) ;//to convert first alphabet to capital
	for(int  i=1 ; i<=strlen(s.first_name)-1 ; i++)
	{
		s.mid_name[i] = tolower(s.mid_name[i]) ;
	}//to convert other alphabates to small
	if(strlen(s.mid_name)>20 || strlen(s.mid_name)<3) 
	{
		printf("\n\n\t\t\t\t\tInvalid!\n\t\t(Middle name contains atleast 2 char atmost 20)\n\n\n") ;
		goto B;
	}
	else
	{
		for(int j=0 ;j <= strlen(s.mid_name)-1 ; j++ )
		{
			if(isalpha(s.mid_name[j])) 
			valid = 1;
			else
			{	valid = 0 ;
				break;
			}
		}
		if(!valid)
		{
			printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
			goto B ;
		}
	}
	/*********Last Name**********/
	C:
	printf("\n\t\t\tLast Name:") ;
	scanf("%s",s.last_name) ;
	s.last_name[0] = toupper(s.last_name[0]) ;//to convert first alphabet to capital
	for(int  i=1 ; i<strlen(s.last_name)-1 ; i++)
	{
		s.last_name[i] = tolower(s.last_name[i]) ;
	}//to convert other alphabates to small
	if(strlen(s.last_name)>20 || strlen(s.last_name)<3) 
	{
		printf("\n\n\t\t\t\t\tInvalid!\n\t\t(Last name contains atleast 2 char atmost 20)\n\n\n") ;
		goto C;
	}
	else
	{
		for(int j=0 ;j <= strlen(s.last_name)-1 ; j++ )
		{
			if(isalpha(s.last_name[j])) 
			valid = 1;
			else
			{
				valid = 0 ;
				break;
			}
		}
		if(!valid)
		{
			printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
			goto C ;
		}
	}
	/**********************gender***********************/
	do{
		printf("\t\t\tGender [F/M/O] :") ;
		scanf("%c",&s.gender) ;
		s.gender = toupper(s.gender) ;
		if(s.gender=='F'||s.gender=='M'||s.gender=='O')
		ok = 1;
		else
		{
			ok = 0;
			printf("\t\t\t\tInvalid charecter!\n\t\t\t\t[Enter F/M/O]") ;
		}
	}while(!ok);
	/*******************Age****************/
	D:
	printf("\t\t\tAge:") ;
	scanf("%d",&s.age) ;
	if(s.age<5||s.age>20)
	{
		printf("\t\t\t\tInvalid age!\n\t\t\t\t[enter age from 5-20]") ;
		goto D;
	}
	/*****************Mobile number********************/
	E:
	printf("\t\t\tMob No:") ;
	scanf("%s",s.mob_no) ;
	if(strlen(s.mob_no) != 10) 
	{
		printf("\t\tInvalid mobile number!\n\t\t\t\t[Enter 10 digit mob no]") ;	
		goto E;
	}
	for(int i=0;i<10;i++)
	{
		if(isdigit(s.mob_no[i])==0)
		{
			printf("\t\tMobile number contains invalid char!\n\t\tPlease enter valid charecters!") ;
			goto E;
		}
	}
	/*************Mail Id******************/
	F:
	printf("\t\t\tMail Id:") ;
	scanf("%s",s.mail_id) ;
	if(strlen(s.mail_id)<5||strlen(s.mail_id)>30) 
	{
		printf("\t\t\t\tInvalid Mail Id!\n\t\t\t[Enter mail id from char 5 to 30]") ;
		goto F;
	}
	/*****************Division***************/
P:
	printf("\t\t\tDivision : ");
	scanf("%c",&s.div) ;
	s.div = toupper(s.div) ;
	if (isalpha(s.div)==0)
	{
		printf("Invalid (enter a char)");
		goto P;
	}
	
	/********************Roll No********************/
Q:
	printf("\t\t\tRoll No :");
	scanf("%d",&s.roll_no)  ;
	if (s.roll_no > 50)
	{
	     printf("Invalid input(enter a no btw 1-50)");
		 goto Q;


	}
	
	/**************printing in record file***********/
	fprintf(ad,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
	printf("\n\n\n\t\t\t\t....Information recorded successfully!....\n") ;
	fclose(ad) ;
	getch() ;
	printf("\t\tAre you want to add more [Y/N] ?\n") ;
	printf("\t\tEnter your answer:") ;
	scanf("%c",&ans) ;
	if(ans == 'Y'||ans=='y')
	Add_rec() ;
	else
	{
		printf("\t\t\t\t\t# Thank You! #") ;
		getch() ;
		system("cls") ;
		main_manu() ;
	}
	
}
/***************************List records*************************/
void List_rec()
{
	int row ;
	system("cls") ;
	title() ;
	FILE*ad;
	ad = fopen("Rohit.txt","r") ;
	printf("\n\n\t\t\t!!!!!!!!!!!Students Records!!!!!!!!!!!!!\n\n\n") ;
	gotoxy(1,9);
	printf("Full Name") ;
	gotoxy(30,9);
	printf("Gender") ;
	gotoxy(40,9) ;
	printf("Age") ;
	gotoxy(47,9);
	printf("Mob No") ;
	gotoxy(62,9) ;
	printf("Mail Id") ;
	gotoxy(92,9);
	printf("Div") ;
	gotoxy(98,9) ;
	printf("Roll No") ;
	printf("\n========================================================================================================\n") ;

	row = 11;
	while(fscanf(ad,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,&s.gender,&s.age,s.mob_no,s.mail_id,&s.div,&s.roll_no)!=EOF)
	{
		gotoxy(1, row);
		printf("%s %s %s",s.first_name,s.mid_name,s.last_name) ;
		gotoxy(30,row);
		printf("%c",s.gender) ;
		gotoxy(40,row) ;
		printf("%d",s.age) ;
		gotoxy(47,row);
		printf("%s",s.mob_no) ;
		gotoxy(62,row) ;
		printf("%s",s.mail_id) ;
		gotoxy(92,row);
		printf("%c",s.div) ;
		gotoxy(98,row) ;
		printf("%d",s.roll_no) ;
		row++ ;
	}
	printf("\n\n\nEnter any key to Redirecting to main manu");
	getch();
	main_manu();
	
}
/**************************************Search Records******************************/
void Search_rec()
{
	int row;
	char ans ;
	char name[20] ;
	system("cls") ;
	title() ;
	FILE*ad;
	ad = fopen("Rohit.txt","r") ;
	printf("\n\n\n\t\t\t!!!!!!!!!!!! Search Student Record !!!!!!!!!!!!!!!\n") ;
	printf("\n\n\t\tEnter student Name:") ;
	scanf("%s",name) ;
	fflush(stdin) ;
	name[0] = toupper(name[0]) ;
	row = 12;
	while(fscanf(ad,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,&s.gender,&s.age,s.mob_no,s.mail_id,&s.div,&s.roll_no)!=EOF)
	{
		if(strcmp(s.first_name,name)==0||strcmp(s.last_name,name)==0)
		{
			gotoxy(1,9);
			printf("Full Name") ;
			gotoxy(30,9);
			printf("Gender") ;
			gotoxy(40,9) ;
			printf("Age") ;
			gotoxy(47,9);
			printf("Mob No") ;
			gotoxy(62,9) ;
			printf("Mail Id") ;
			gotoxy(92,9);
			printf("Div") ;
			gotoxy(98,9) ;
			printf("Roll No\n") ;
			printf("/n==================================================================================\n") ;
			gotoxy(1, row);
			printf("%s %s %s",s.first_name,s.mid_name,s.last_name) ;
			gotoxy(30,row);
			printf("%c",s.gender) ;
			gotoxy(40,row) ;
			printf("%d",s.age) ;
			gotoxy(47,row);
			printf("%s",s.mob_no) ;
			gotoxy(62,row) ;
			printf("%s",s.mail_id) ;
			gotoxy(92,row);
			printf("%c",s.div) ;
			gotoxy(98,row) ;
			printf("%d",s.roll_no) ;
			row++ ;
			break;
		}
	}
	if(strcmp(s.first_name,name)!=0)
	{
		printf("\n\n\n\t\t\tRecord not found!\n") ;
		getch() ;
	}
	fclose(ad) ;
	printf("\n\n\t\tDo you want to continue[Y/N] ?:") ;
	scanf("%c",&ans) ;
	if(toupper(ans)=='Y')
	Search_rec() ;
	else
	{
		printf("\n\t\t\t\tThank you!") ;
		getch() ;
		main_manu() ;
	}	
}
/************************************Edit Record********************************/
void Edit_rec()
{
	FILE*ad, *ft;
	int i,b,correct = 0;
	char ch ;
	char name[20],lname[20] ;
	system("cls")  ;
	title() ;
	ft = fopen("temp.txt","w+");
	ad = fopen("Rohit.txt","r");
	if(ad==NULL)
	{
		printf("\n\t\tCan't open  file !") ;
		getch();
		main_manu() ;
	}
	printf("\n\n\n\t\t\t!!!!!!!!!!!Edit Student Records!!!!!!!!!!!!!!!!") ;
	gotoxy(9,9);
	printf("Enter the first name of the student :");
	scanf("%s",name) ;
	fflush(stdin);
	name[0] = toupper(name[0]) ;
	gotoxy(9,10) ;
	printf("Enter the last name of student:");
	scanf("%s",lname) ;
	fflush(stdin);
	lname[0] = toupper(lname[0]) ;
	gotoxy(9,11) ;
	if(ft == NULL)
	{
		printf("\n\t\t\tCan't open file !") ;
		getch() ;
		main_manu() ;
	}
	while(fscanf(ad,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,&s.gender,&s.age,s.mob_no,s.mail_id,&s.div,&s.roll_no)!=EOF)
	{
		if(strcmp(s.first_name,name)==0 && strcmp(s.last_name,lname))
		{
			correct = 1;
			gotoxy(10,14) ;
			printf("*******Existing Records*******");
			gotoxy(10,16)  ;
			printf("%s  %s  %s  %c  %d  %s  %s  %c  %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
			gotoxy(10,17);
			printf("!!!!!!!! Enter new records !!!!!!!!!") ;
			/********first name**********/
			G:
			printf("\n\t\t\tFirst Name:") ;
			scanf("%s",s.first_name) ;
			s.first_name[0] = toupper(s.first_name[0]) ;//to convert first alphabet to capital
			for(int  i=1 ; i<strlen(s.first_name)-1 ; i++)
			{
				s.first_name[i] = tolower(s.first_name[i]) ;
			}//to convert other alphabates to small
			if(strlen(s.first_name)>20 || strlen(s.first_name)<3) 
			{
				printf("\n\n\t\t\t\t\tInvalid!\n\t\t(first name contains atleast 2 char atmost 20)\n\n\n") ;
				goto G;
			}
			else
			{
				for(int j=0 ;j < strlen(s.first_name)-1 ; j++ )
				{
					if(isalpha(s.first_name[j])) 
					valid = 1;
					else
					{
						valid = 0 ;
						break;
					}
				}
			}	
			if(!valid)
			{
				printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
				goto G ;
			}
		
			/*********Middle Name**********/
			H:
			gotoxy(10,15) ;
			printf("\n\t\tMiddle Name:") ;
			scanf("%s",s.mid_name) ;
			s.mid_name[0] = toupper(s.mid_name[0]) ;//to convert first alphabet to capital
			for(int  i=1 ; i<strlen(s.first_name)-1 ; i++)
			{
				s.mid_name[i] = tolower(s.mid_name[i]) ;
			}//to convert other alphabates to small
			if(strlen(s.mid_name)>20 || strlen(s.mid_name)<3) 
			{
				printf("\n\n\t\t\t\t\tInvalid!\n\t\t(Middle name contains atleast 2 char atmost 20)\n\n\n") ;
				goto H;
			}
			else
			{
				for(int j=0 ;j < strlen(s.mid_name)-1 ; j++ )
				{
					if(isalpha(s.mid_name[j])) 
					valid = 1;
					else
					{	valid = 0 ;
						break;
					}
				}
				if(!valid)
				{
					printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
					goto H ;
				}
			}
			/*********Last Name**********/
			I:	
			printf("\n\t\t\tLast Name:") ;
			scanf("%s",s.last_name) ;
			s.last_name[0] = toupper(s.last_name[0]) ;//to convert first alphabet to capital
			for(int  i=1 ; i<strlen(s.last_name)-1 ; i++)
			{
				s.last_name[i] = tolower(s.last_name[i]) ;
			}//to convert other alphabates to small
			if(strlen(s.last_name)>20 || strlen(s.last_name)<3) 
			{
				printf("\n\n\t\t\t\t\tInvalid!\n\t\t(Last name contains atleast 2 char atmost 20)\n\n\n") ;
				goto I;
			}
			else
			{
				for(int j=0 ;j < strlen(s.last_name)-1 ; j++ )
				{
					if(isalpha(s.last_name[j])) 
					valid = 1;
					else
					{
						valid = 0 ;
						break;
					}
			}
					if(!valid)
				{
					printf("\t\tEntered name contains invalid charecter!\n\t\t\t\t\t(Please enter again!)") ;
					goto I ;
				}
			}
			do{
				printf("\n\t\t\tGender [F/M] :") ;
				scanf("%c",&s.gender) ;
				s.gender = toupper(s.gender) ;
				if(s.gender=='F'||s.gender=='M')
				ok = 1;
				else
				{
					ok = 0;
					printf("\n\t\t\t\tInvalid charecter!\n\t\t\t\t[Enter F/M]") ;
				}
			}while(!ok);
			/*******************Age****************/
			J:
			printf("\n\t\t\tAge:") ;
			scanf("%d",&s.age) ;
			if(s.age<5||s.age>20)
			{
				printf("\t\t\t\tInvalid age!\n\t\t\t\t[enter age from 5-20]") ;
				goto J;
			}
			/*****************Mobile number********************/
			K:
			printf("\t\t\tMob No:") ;
			scanf("%s",s.mob_no) ;
			if(strlen(s.mob_no) != 10) 
			{
				printf("\t\tInvalid mobile number!\n\t\t\t\t[Enter 10 digit mob no]") ;	
				goto K;
			}
			for(int i=0;i<10;i++)
			{
				if(isdigit(s.mob_no[i])==0)
				{
					printf("\t\tMobile number contains invalid char!\n\t\tPlease enter valid charecters!") ;
					goto K;
				}
			}
			/*************Mail Id******************/
			F:
			printf("\t\t\tMail Id:") ;
			scanf("%s",s.mail_id) ;
				if(strlen(s.mail_id)<5||strlen(s.mail_id)>30) 
			{
				printf("\t\t\t\tInvalid Mail Id!\n\t\t\t[Enter mail id from char 5 to 30]") ;
				goto F;
			}
			/*****************Division***************/
			printf("\t\t\tDivision : ");
			scanf("%c",&s.div) ;
			s.div = toupper(s.div) ;
			/********************Roll No********************/
			printf("\t\t\tRoll No :");
			scanf("%d",&s.roll_no)  ;
			printf("\n\t\tPress U charecter to updating records:");
			scanf("%c",&ch) ;
			if(ch == 'u'||ch == 'U')
			{
				fprintf(ft,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
				printf("\n\n\tStudent records updated successfully!\n") ;
			}
		}
		else 
		{
			fprintf(ft,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
		}
	}
	if(!correct)
	{
		printf("\n\n\t\tRecords not found !....\n") ;
	}
	fclose(ad) ;
	fclose(ft) ;
	remove("Rohit.txt");
	rename("temp.txt","Rohit.txt") ;
	getch() ;
	main_manu();
}
void Delete_rec()
{
	char name[20] ,lname[20];
	int found =0 ;
	system("cls") ;
	title();
	FILE*ad, *ft ;
	ft = fopen("temp.txt","w+")  ;//if files not exit then make file and open it
	ad = fopen("Rohit.txt","r") ;
	printf("\n\n\t\t\t!!!!!!!!!! Delete Students Records !!!!!!!!!!!!\n") ;
	gotoxy(10,6);
	printf("Enter the student first name to be deleted:") ;
	scanf("%s",name);
	fflush(stdin) ;
	printf("Enter the  students last name:");
	scanf("%s",lname);
	fflush(stdin) ;
	name[0] =toupper(name[0]);
	while(fscanf(ad,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,&s.gender,&s.age,s.mob_no,s.mail_id,&s.div,&s.roll_no)!=EOF) 
	{
		if(strcmp(s.first_name,name)!=0&&strcmp(s.last_name,lname)!=0) 
		{
			fprintf(ft,"%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
		}
		else
		{
			printf("%s %s %s %c %d %s %s %c %d",s.first_name,s.mid_name,s.last_name,s.gender,s.age,s.mob_no,s.mail_id,s.div,s.roll_no) ;
			found = 1 ;
		}
	}
	if(!found)
	{
		printf("\n\n\t\t\t Record not found !....\n") ;
		getch();
		main_manu() ;
	}
	
	fclose(ad) ;
	fclose(ft) ;
	remove("Rohit.txt") ;
	rename("temp.txt","Rohit.txt") ;
	printf("\n\n\n\t\t\t Record Deleted Successfully !\n") ;
	getch() ;
	main_manu() ;
	
}	
