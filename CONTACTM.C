#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<graphics.h>


struct contact
{
     int srno;
     char name[20];
     char num[16];
     char address[30];
}cont;
void addcontact();
void listcontact();
void deletecontact();
void editcontact();
void searchcontact();
void changepassword();
int getsno();

void main()
{
    FILE *fp;
    char pass[20],original[20],ch,i=0;
    char choice,choice2;
    {
    clrscr();
    window(1,1,80,25);
    textbackground(YELLOW);
    clrscr();
    window(20,10,60,15);
    textbackground(BLACK);
    clrscr();
    textcolor(YELLOW);
    cprintf("\nEnter Password : ");

    while(1)
    {
	ch=getch();
	if(ch==13)
	{
	    pass[i]='\0';
	    break;
	}
	pass[i++]=ch;
	printf("*");
    }

    fp=fopen("password.c","r");
    fgets(original,30,fp);
    fclose(fp);

    if(!strcmp(pass,original)==0)
    {
	 clrscr();
	 gotoxy(6,3);
	 textcolor(WHITE);
	 cprintf("   Incorrect Password !... ");
	 gotoxy(6,4);
	 textcolor(YELLOW+BLINK);
	 cprintf("     [ Press Any Key...]");


	 getch();
	 clrscr();
    }
    else
    {

	 textbackground(BLACK);
	 window(1,1,80,25);
	 clrscr();

	 for(i=5;i<=75;i++)
	 {
		gotoxy(i,2);
		printf("%c",178);
	 }
	 for(i=3;i<=15;i++)
	 {
		gotoxy(5,i);
		printf("%c",178);
	 }
	 for(i=6;i<=75;i++)
	 {
		gotoxy(i,15);
		printf("%c",178);
	 }
	for(i=3;i<=15;i++)
	{
	    gotoxy(75,i);
	    printf("%c",178);
	}

	gotoxy(28,4);
	printf("*** CONTACT MANAGER ***");
	gotoxy(6,5);
	printf("*********************************************************************");
	gotoxy(30,6);
	printf("** VERSION 1.0 **  ");
	gotoxy(28,7);
	printf("---------------------");
	gotoxy(7,9);
	printf("DEVELOPED BY  :  LINESH K. MISHRA");
	gotoxy(7,11);
	printf("E-MAIL ID     :  mishrashubham @gmail.com");

	gotoxy(25,18);
	printf("LOADING !... PLEASE WAIT !...");
	gotoxy(10,19);
	for(i=10;i<=70;i++)
	{
	   gotoxy(i,19);
	   printf("%c",254);
	   delay(60);
	}
	 do
	 {

	 window(1,1,80,25);
	 textbackground(YELLOW);
	 clrscr();
	 window(20,5,60,20);
	 textbackground(BLACK);
	 clrscr();
	 textcolor(12);
	 gotoxy(11,2);
	 cprintf("*** MAIN MENU ***");
	 textcolor(WHITE);
	 gotoxy(1,3);
	 cprintf("=========================================");
	 textcolor(WHITE);
	 gotoxy(10,5);
	 cprintf("1. Add New Contact ");
	 gotoxy(10,6);
	 cprintf("2. Delete Contact ");
	 gotoxy(10,7);
	 cprintf("3. Edit Contact ");
	 gotoxy(10,8);
	 cprintf("4. Search Contact ");
	 gotoxy(10,9);
	 cprintf("5. List Of Contact ");
	 gotoxy(10,10);
	 cprintf("6. Change Password ");
	 gotoxy(10,11);
	 cprintf("7. Exit");
	 gotoxy(1,13);
	 cprintf("=========================================");
	 gotoxy(5,15);
	 textcolor(WHITE);
	 cprintf("Enter Your Choice : ");
	 scanf("%d",&choice);

	 switch(choice)
	 {
	     case 1:
	     addcontact();
	     break;
	     case 2:
	     deletecontact();
	     break;
	     case 3:
	     editcontact();
	     break;
	     case 4:
	     searchcontact();
	     break;
	     case 5:
	     listcontact();
	     break;
	     case 6:
	     changepassword();
     break;
	     case 7:
	     exit(0);
	 }
	 }
	 while(choice>=1 && choice<=6);
    }
    getch();
}
}



int getsno()
{
    FILE *fp;
    int n,size;
    fp=fopen("contactmanager.txt","rb");
    size=sizeof(cont);
    fseek(fp,-size,SEEK_END);
    fread(&cont,sizeof(cont),1,fp);
    n=cont.srno;
    fclose(fp);
    n++;
    return(n);
}


void addcontact()
{
    int i;
    FILE *fp;
    clrscr();
    window(1,1,80,25);
    textbackground(11);
    clrscr();
    gotoxy(3,2);
    for(i=1;i<=23;i++)
    {
       cprintf("*");
       gotoxy(3,2+i);
    }
    gotoxy(4,24);
    for(i=1;i<=37;i++)
    {
	cprintf(" *");
    }
    gotoxy(4,2);
    for(i=1;i<=37;i++)
    {
	cprintf(" *");
    }
    gotoxy(79,2);
    for(i=1;i<24;i++)
    {
	cprintf("*");
	gotoxy(79,2+i);
    }

    window(5,3,75,22);
    textbackground(12);
    clrscr();
    textcolor(WHITE);
    gotoxy(25,2);
    cprintf("<*** ADD CONTACTS ***> ");
    gotoxy(3,3);
    cprintf("==================================================================");
    gotoxy(3,5);
    cont.srno=getsno();
    fflush(stdin);
    cprintf("Serial Number : %d",cont.srno);
    fflush(stdin);
    gotoxy(3,7);
    cprintf("Enter Name : ");
    fflush(stdin);
    gets(cont.name);
    gotoxy(3,9);
    cprintf("Enter Mobile Number : ");
    gets(cont.num);
    gotoxy(3,11);
    cprintf("Enter Address : ");
    fflush(stdin);
    gets(cont.address);
    gotoxy(3,13);

    fp=fopen("contactmanager.txt","ab");
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    cprintf("==================================================================");
    gotoxy(3,15);
    textcolor(WHITE+BLINK);
    cprintf("Contact Saved Successfully !...");
    textcolor(WHITE);
    getch();

}


void listcontact()
{
     FILE *fp;
     int i;
     char ch;
     clrscr();
     window(1,1,80,25);
     textbackground(3);
     clrscr();
     fp=fopen("contactmanager.txt","rb");
     printf("\n\n");
     printf("\n");
     gotoxy(28,2);
     cprintf("*** LIST OF CONTACT ***");
     gotoxy(1,3);
     for(i=1;i<=80;i++)
     {
	  cprintf("=");
     }
     gotoxy(1,4);
     cprintf("[SR.NO]");
     gotoxy(15,4);
     cprintf("[NAME]");
     gotoxy(33,4);
     cprintf("[PHONE NO]");
     gotoxy(53,4);
     cprintf("[ADDRESS]");
     gotoxy(1,5);
     for(i=1;i<=80;i++)
     {
	cprintf("=");
     }
     i=6;
     while(fread(&cont,sizeof(cont),1,fp)==1)
     {

	 gotoxy(2,i);
	 cprintf("%d",cont.srno);
	 gotoxy(10,i);
	 cprintf("%s",cont.name);
	 gotoxy(33,i);
	 cprintf("%s",cont.num);
	 gotoxy(47,i);
	 cprintf("%s",cont.address);
	 i++;
     }
     fclose(fp);
     getch();
}

void deletecontact()
{
    FILE *fp1,*fp2;
    int i,n,found;
    char choice;
    clrscr();
    window(1,1,80,25);
    textbackground(11);
    clrscr();
    gotoxy(3,2);
    for(i=1;i<=23;i++)
    {
       cprintf("*");
       gotoxy(3,2+i);
    }
    gotoxy(4,24);
    for(i=1;i<=37;i++)
    {
	cprintf(" *");
    }
    gotoxy(4,2);
    for(i=1;i<=37;i++)
    {
	cprintf(" *");
    }
    gotoxy(79,2);
    for(i=1;i<24;i++)
    {
	cprintf("*");
	gotoxy(79,2+i);
    }

    window(5,3,75,22);
    textbackground(12);
    clrscr();
    textcolor(WHITE);
    gotoxy(25,2);
    cprintf("<*** DELETE CONTACT ***> ");
    gotoxy(3,3);
    cprintf("==================================================================");
    gotoxy(3,5);
    cprintf("Enter Serial No. To Delete : ");
    scanf("%d",&n);
    gotoxy(3,6);
    cprintf("==================================================================");

    fp1=fopen("contactmanager.txt","rb");
    found=0;
    while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
    {
	if(cont.srno==n)
	{
	    found=1;
	    gotoxy(3,8);
	    cprintf("Serial No    : %d ",cont.srno);
	    gotoxy(3,10);
	    cprintf("Name         : %s ",cont.name);
	    gotoxy(3,12);
	    cprintf("Phone Number : %s ",cont.num);
	    gotoxy(3,14);
	    cprintf("Address      : %s ",cont.address);
	    break;

	}
    }
    if(found==0)
    {
	textcolor(YELLOW+BLINK);
	printf("\n");
	gotoxy(25,10);
	cprintf("Record Not Found !..");
	fclose(fp1);
	getch();
	return;
    }

    gotoxy(3,16);
    cprintf("=====================================================================");
    gotoxy(3,18);
    cprintf("Confirm To Delete [Y/N] : ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='y'||choice=='Y')
    {
    rewind(fp1);
    fp2=fopen("temp.txt","wb");
    while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
    {
	 if(cont.srno!=n)
	 fwrite(&cont,sizeof(cont),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("contactmanager.txt");
    rename("temp.txt","contactmanager.txt");
    gotoxy(3,20);
    textcolor(WHITE+BLINK);
    cprintf("Record Successfully Deleted !..");
    getch();
    }
}

void editcontact()
{
    FILE *fp;
    int i,pos,found,n;
    clrscr();
    window(1,1,80,25);
    textbackground(YELLOW);
    clrscr();
    window(2,2,79,24);
    textbackground(RED);
    clrscr();
    gotoxy(28,1);
    cprintf("*** EDIT CONTACTS ***");
    gotoxy(1,2);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }

    cprintf(" Enter Serial No. To Edit : ");
    scanf("%d",&n);

    gotoxy(1,4);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }
    fp=fopen("contactmanager.txt","r+b");
    found=0;
    while(fread(&cont,sizeof(cont),1,fp)!=NULL)
    {
	if(cont.srno==n)
	{
	    found=1;
	    gotoxy(2,5);
	    cprintf("Serial No : %d",cont.srno);
	    gotoxy(2,6);
	    cprintf("Name      : %s",cont.name);
	    gotoxy(2,7);
	    cprintf("Phone No  : %s",cont.num);
	    gotoxy(2,8);
	    cprintf("Address   : %s",cont.address);
	    break;
	}
    }

    if(found==0)
    {
	 gotoxy(25,10);
	 textcolor(WHITE+BLINK);
	 cprintf("No Records Found !...");
	 fclose(fp);
	 getch();
	 textcolor(WHITE);
	 return;

    }


    pos=ftell(fp);
    fseek(fp,pos-sizeof(cont),SEEK_SET);

    gotoxy(1,10);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }
    cprintf(" Enter New Information : ");

    gotoxy(1,12);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }
    gotoxy(2,13);
    cprintf("Enter Serial No : ");
    fflush(stdin);
    scanf("%d",&cont.srno);
    gotoxy(2,14);
    cprintf("Enter Name : ");
    fflush(stdin);
    gets(cont.name);
    gotoxy(2,15);
    cprintf("Enter Phone No : ");
    fflush(stdin);
    gets(cont.num);
    gotoxy(2,16);
    cprintf("Enter Address : ");
    fflush(stdin);
    gets(cont.address);
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    gotoxy(1,17);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }
    gotoxy(2,18);
    textcolor(WHITE+BLINK);
    cprintf("Information Updated Successfully !... ");

    textcolor(WHITE);
    gotoxy(1,19);
    for(i=2;i<=79;i++)
    {
       cprintf("-");
    }
    getch();
}

void searchcontact()
{
    FILE *fp;
    char choice,name[20],phone[15];
    int i,j,found,n;
    clrscr();
    textbackground(RED);
    window(1,1,80,25);
    clrscr();
    textbackground(BLACK);
    window(20,6,60,18);
    clrscr();
    textcolor(WHITE);
    gotoxy(10,2);
    cprintf("*** SEARCH CONTACT ***  ");
    gotoxy(1,3);
    cprintf("=========================================");
    gotoxy(10,5);
    cprintf("1. Search By Serial No");
    gotoxy(10,6);
    cprintf("2. Search By Name");
    gotoxy(10,7);
    cprintf("3. Search By Mobile No ");
    gotoxy(1,9);
    cprintf("=========================================");
    gotoxy(7,11);
    cprintf("Enter Your Choice : ");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:
       window(1,1,80,25);
       textbackground(RED);
       clrscr();
       textcolor(WHITE);
       gotoxy(20,2);
       cprintf("*** SEARCH CONTACT BY SERIAL NO ***");
       gotoxy(1,3);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }
       gotoxy(2,4);
       cprintf("Enter Serial No. To Search : ");
       scanf("%d",&n);
       gotoxy(1,5);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }

       found=0;
       fp=fopen("contactmanager.txt","r");
       while(fread(&cont,sizeof(cont),1,fp)!=NULL)
       {
	   if(cont.srno==n)
	   {
	       found=1;
	       gotoxy(2,6);
	       cprintf("Serial Number : %d",cont.srno);
	       gotoxy(2,7);
	       cprintf("Name          : %s",cont.name);
	       gotoxy(2,8);
	       cprintf("Phone Number  : %s",cont.num);
	       gotoxy(2,9);
	       cprintf("Address       : %s",cont.address);
	       break;
	   }
       }
       if(found==0)
       {
	    textcolor(WHITE+BLINK);
	    gotoxy(20,8);
	    cprintf("Record Not Found !...");
	    fclose(fp);
	    getch();
       }
       fclose(fp);
       break;

       case 2:
       window(1,1,80,25);
       textbackground(RED);
       clrscr();
       textcolor(WHITE);
       gotoxy(20,2);
       cprintf("*** SEARCH CONTACT BY NAME ***");
       gotoxy(1,3);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }
       gotoxy(2,4);
       cprintf("Enter Name To Search : ");
       fflush(stdin);
       gets(name);
       gotoxy(1,5);
       for(i=1;i<=80;i++)
       {
	  cprintf("-");
       }
       gotoxy(1,6);
       cprintf("[SR.NO]");
       gotoxy(15,6);
       cprintf("[NAME]");
       gotoxy(33,6);
       cprintf("[PHONE NO]");
       gotoxy(53,6);
       cprintf("[ADDRESS]");
       gotoxy(1,7);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }
       j=8;
       found=0;
       fp=fopen("contactmanager.txt","r");
       while(fread(&cont,sizeof(cont),1,fp)!=NULL)
       {
	   if(strcmpi(cont.name,name)==0)
	   {
	       found=1;
	       gotoxy(2,j);
	       cprintf("%d",cont.srno);
	       gotoxy(10,j);
	       cprintf("%s",cont.name);
	       gotoxy(33,j);
	       cprintf("%s",cont.num);
	       gotoxy(47,j);
	       cprintf("%s",cont.address);
	       j++;
	   }
       }
       if(found==0)
       {
	    textcolor(WHITE+BLINK);
	    cprintf("Record Not Found !...");
	    fclose(fp);
	    return;
       }
       fclose(fp);
       break;

       case 3:
       window(1,1,80,25);
       textbackground(RED);
       clrscr();
       textcolor(WHITE);
       gotoxy(20,2);
       cprintf("*** SEARCH CONTACT PHONE NUMBER ***");
       gotoxy(1,3);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }
       gotoxy(2,4);
       cprintf("Enter Phone Number To Search : ");
       fflush(stdin);
       gets(phone);
       gotoxy(1,5);
       for(i=1;i<=80;i++)
       {
	  cprintf("-");
       }
       gotoxy(1,6);
       cprintf("[SR.NO]");
       gotoxy(15,6);
       cprintf("[NAME]");
       gotoxy(33,6);
       cprintf("[PHONE NO]");
       gotoxy(53,6);
       cprintf("[ADDRESS]");
       gotoxy(1,7);
       for(i=1;i<=80;i++)
       {
	   cprintf("-");
       }
       j=8;
       found=0;
       fp=fopen("contactmanager.txt","r");
       while(fread(&cont,sizeof(cont),1,fp)!=NULL)
       {
	   if(strcmp(cont.num,phone)==0)
	   {
	       found=1;
	       gotoxy(2,j);
	       cprintf("%d",cont.srno);
	       gotoxy(10,j);
	       cprintf("%s",cont.name);
	       gotoxy(33,j);
	       cprintf("%s",cont.num);
	       gotoxy(47,j);
	       cprintf("%s",cont.address);
	       j++;
	   }
       }
       getch();
       if(found==0)
       {
	    textcolor(WHITE+BLINK);
	    cprintf("Record Not Found !...");
	    fclose(fp);
	    getch();
	    return;
       }
       fclose(fp);
       break;
    }
    getch();
}

void changepassword()
{
    FILE *fp;
    int i;
    char current[10],original[10],newpass[10],repass[10];
    clrscr();
    window(1,1,80,25);
    textbackground(RED);
    clrscr();
    window(20,5,60,20);
    textbackground(BLACK);
    clrscr();
    textcolor(YELLOW);
    gotoxy(9,2);
    cprintf("*** CHANGE PASSWORD ***");
    gotoxy(1,3);
    textcolor(WHITE);
    for(i=1;i<=41;i++)
    {
	cprintf("=");
    }
    gotoxy(2,4);
    cprintf("Enter Current Password : ");
    fflush(stdin);
    gets(current);
    gotoxy(1,5);
    for(i=1;i<=41;i++)
    {
	cprintf("=");
    }
    fp=fopen("password.c","r");
    fgets(original,10,fp);
    fclose(fp);
    if(strcmpi(current,original)!=0)
    {
	 textcolor(WHITE+BLINK);
	 gotoxy(10,8);
	 cprintf("Wrong Password !...");
	 getch();
	 return;
    }
    gotoxy(2,7);
    cprintf("Enter New Passwrod : ");
    fflush(stdin);
    gets(newpass);
    gotoxy(2,9);
    cprintf("Re-Enter New Password : ");
    fflush(stdin);
    gets(repass);
    gotoxy(1,11);
    for(i=1;i<=41;i++)
    {
       cprintf("=");
    }

    if(strcmpi(newpass,repass)!=0)
    {
       textcolor(WHITE+BLINK);
       gotoxy(8,11);
       cprintf("Password Not Matched !..");
       gotoxy(10,12);
       cprintf("    Try Again !...");
       gotoxy(1,13);
       for(i=1;i<=41;i++)
       {
	  cprintf("=");
       }
       getch();
       return;
    }
    fp=fopen("password.c","w");
    fprintf(fp,"%s",newpass);
    fclose(fp);

    gotoxy(2,12);
    textcolor(WHITE+BLINK);
    cprintf("Successfully Updated Password !..");
    gotoxy(1,13);
    textcolor(WHITE);
    for(i=1;i<=41;i++)
    {
	cprintf("=");
    }
    getch();
}



