#include<iostream.h>
#include<conio.h>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>

int va;


// class seller begins
class seller
{
	char sname[60];
	char userid[60];
	char password[30];
	long int phone , gstin , aadhar;
public:
void entry()
{
	clrscr();
	cout<<"\n\n\t\t\t\tWELCOME TO\n\t\t\t\t COMUPTER ARENA\n\n";
	cout<<"\nEnter Your Name:";
	gets(sname);
	cout<<"\n Enter Your User ID:";
	cin>>userid;
	cout<<"\n Enter Password:";
	char ch;
	for(int j=0;j<20;j++)
	{
	ch=getch();
	if(ch==' ')
	{
	password[j]='\0';
	break;
	}
	else
	{
	password[j]=ch;
	cout<<"*";
	}
	}
	cout<<"\n Enter Your Phone Number:";
	cin>>phone;
	cout<<"\n Enter Your GST IN:";
	cin>>gstin;
	cout<<"\n Enter Your Aadhar Number:";
	cin>>aadhar;
}
void output()
{
	textcolor(WHITE);
	cout<<"\n\n\t\t COMPUTER ARENA\n\n";
	cout<<"\t\t NAME:"<<sname<<endl;
	cout<<"\t\t USERID:";
	puts(userid);
	cout<<"\t\t PASSWORD:"<<password<<endl;
	cout<<"\t\t PHONE NUMBER:"<<phone<<endl;
	cout<<"\t\t GSTIN:"<<gstin<<endl;
	cout<<"\t\t AADHAR NUMBER:"<<aadhar<<endl;
}
void modify()
{
	cout<<"\n enter new customer id :- )";
	cin>>userid;
}

char *  pass()
{
	return password;
}
char * rid()
{
	return userid;
}
}s;


void swrite()
{
	ofstream out("seller.dat",ios::binary | ios::app);
	seller s;
	s.entry();
	out.write((char*)&s,sizeof(s));
	out.close();
}



void sdel()
{
	ifstream in("seller.dat",ios::binary|ios::in);
	ofstream out("temp.dat",ios::binary|ios::out);
	seller s;
	char rno[60];
	char found ='f',confirm='n';
	cout<<"\n Enter the ID to be deleted :";
	gets(rno);
	while(in)
	{
		in.read((char*)&s,sizeof(s));
		if(in.eof())break;
		if(strcmpi(s.rid(),rno))
		{
			s.output();
			found='t';
			cout<<"\n \n Are you sure want to delete this record ? (Y/n)\t";
			cin>>confirm;
			if (confirm=='n')
			out.write((char*)&s,sizeof(s));
		}
	else
	{
	out.write((char*)&s,sizeof(s));
	}
	in.close();
	out.close();
	remove("seller.dat");
	rename("temp.dat","seller.dat");
}
}
void supdate()
{
	ifstream in("seller.dat",ios::binary|ios::in);
	ofstream out("temp.dat",ios::binary|ios::out);
	char r[30];
	seller s;
	cout<<"\n enter the Seller id to be modified ::";
	gets(r);
	int found =0;
	while(in)

	{
	in.read((char*)&s,sizeof(s));
	if(in.eof())
	break;
	if(strcmpi(s.rid(),r)==0)
	{
		s.modify();
		out.write((char*)&s,sizeof(s));
		cout<<"\n modified";
		found=1;
		cout<<"\n now the file contain \n \n ";
		s.output();
		in.close();
		getch();
		}
		else
		out.write((char*)&s,sizeof(s));
	}
	if (found==0)
	{
	cout<<"\n seller not found ";
	in.close();
	out.close();
	remove("seller.dat");
	rename("temp.dat","seller.dat");
	}
}
 void pchecks()
{

	clrscr();
	ifstream in ("seller.dat",ios::binary |ios ::in);
	char pch[30];
	char rn[60];
	seller s;
	cout<<"\n \n ENTER your ID :\t";
	gets(rn);
	cout<<"\n \n Enter The Password:\t";
	char ch;
	for(int j=0;j<20;j++)
	{
	ch=getch();
	if(ch==' ')
	{
	pch[j]='\0';
	break;
	}
	else
	{
	pch[j]=ch;
	cout<<"*";
	}
	}
	while(!in.eof())
	{
		in.read((char*)&s,sizeof(s));
		if(strcmpi(s.rid(),rn)==0 && strcmpi(s.pass(),pch)==0)
		{
			cout<<"\n\n\t\t\t WELCOME TO THE COMPUTER ARENA ";
			break;
		}
		else
		{
			cout<<"\n\n\t\t\t INVALID PASSWORD";
			break;
		}
	}
	in.close();
}

// class consumer begins
class consumer
{
	char cid[40];
	char cname[60];
	char address[150];
	unsigned long int aadhar, phone;
	char password[30];

	public:


void entry()
{
	clrscr();
	cputs(" Computer Arena ");
	cputs("\n Customer Name :");
	gets (cname);
	cputs("\n Customer ID :");
	cin>>cid;
	cputs("\n Customer Address :");
	gets(address);
	cputs("\n Customer Aadhar Number :");
	cin>>aadhar;
	cputs("\n Customer Phone Number :");
	cin>>phone;
	cout<<"\n Enter The Password :";
	char ch;
	for(int j=0;j<20;j++)
	{
	ch=getch();
	if(ch==' ')
	{
	password[j]='\0';
	break;
	}
	else
	{
	password[j]=ch;
	cout<<"*";
	}
	}
}

void display()
{
	cout<<"\n customer id :"<<cid;
	cout<<"\n customer name :"<<cname;
	cout<<"\n customer address :"<<address;
	cout<<"\n customer Aadhar no :"<<aadhar;
	cout<<"\n customer phone no :"<<phone;
}

void modify()
{
	cout<<"\n enter new customer id :- )";
	cin>>cid;
}
char * rid()
{
	return cid;
}
char * pass()
{
	return password;
}
}c;

void cwrite()
{
	ofstream out("customer.dat",ios::binary | ios::in);
	consumer c;
	c.entry();
	out.write((char*)&c,sizeof(c));
	out.close();
}



void del()
{
	ifstream in ("consumer.dat",ios::binary|ios::in);
	ofstream out("temp.dat",ios::binary|ios::out);
	consumer c;
	char rno[40];
	char found ='f',confirm='n';
	cout<<"\n enter the id to be deleted ";
	gets(rno);
	while(in)
	{
		in.read((char*)&c,sizeof(c));
		if(in.eof())break;
		if(strcmpi(c.rid(),rno)==0)
		{
			c.display();
			found='t';
			cout<<"\n \n Are you sure want to delete this record ? (Y/n)\t";
			cin>>confirm;
			if (confirm=='n')
			out.write((char*)&c,sizeof(c));
		}

	else
	out.write((char*)&c,sizeof(c));
	if(found=='f')
	{
		cout<<"\n \n \t record not found \n ";
	}
	in.close();
	out.close();
	remove("customer.dat");
	rename("temp.dat","customer.dat");
	cout<<"\n \n the file contain \n \n ";
	in.open("customer.dat",ios::binary|ios::in);
	while(in)
	{
		in.read((char*)&c,sizeof(c));
		if(in.eof())break;
		c.display();
	}
	in.close();
}
}


void update()
{
	ifstream in ("customer.dat",ios::binary|ios::in);
	ofstream out("temp.dat",ios::binary|ios::out);
	char r[40];
	consumer c;
	cout<<"\n enter the customer id to be modified ::";
	gets(r);
	int found =0;
	while(in)
	{
	in.read((char*)&c,sizeof(c));
	if(in.eof())
	break;
	if(strcmpi(c.rid(),r)==0)
	{
		c.modify();
		out.write((char*)&c,sizeof(c));
		cout<<"\n modified";
		found=1;
		cout<<"\n now the file contain \n \n ";
		c.display();
		in.close();
		getch();
	}
	else
	out.write((char*)&c,sizeof(c));
	}
	if (found==0)
	cout<<"\n customers not found ";
	in.close();
	out.close();
	remove("customer.dat");
	rename("temp.dat","customer.dat");
	}


 void pcheck()
{
	ifstream in ("consumer.dat",ios::binary |ios ::in);
	char pch[30];
	int found=0;
	char rn[40];
	consumer c;
	cout<<"\n \n ENTER your ID :\t";
	gets(rn);
	cout<<"\n \n Enter The Password:\t";
	char ch;
	for(int j=0;j<20;j++)
	{
	ch=getch();
	if(ch==' ')
	{
	pch[j]='\0';
	break;
	}
	else
	{
	pch[j]=ch;
	cout<<"*";
	}
	}
	while(!in.eof())
	{
		in.read((char*)&c,sizeof(c));
		if(strcmpi(c.rid(),rn)==0||strcmp(c.pass(),pch)==0)
		{
			cout<<"\n\n\t\t\t WELCOME TO THE COMPUTER ARENA ";
			found++;
			break;
		}
		else
		{
			cout<<"\n\n\t\t\t INVALID PASSWORD";
			getch();
			break;

		}
	}
	in.close();
}



	// class product begins




class products
{
	char type[30];
	char pname[30];
	char des[170];
	long int price;
	public:
	void input()
	{
		cout<<"\n\n\t\t\t WELCOME TO COMPUTER ARENA ";
		cout<<"\n \n\n Enter Product Type:";
		gets(type);
		cout<<"\n Enter Product Name:";
		gets(pname);
		cout<<"\n Enter Description of the Product:";
		gets(des);
		cout<<"\n Enter The Price:";
		cin>> price;
	}
	void output()
	{
		 cout<<"\n\n\t\t\t WELCOME TO THE COMPUTER ARENA";
		 cout<<"\n\n\n\n Product Type:";
		 puts(type);
		 cout<<"\n\n\n\nProduct Name:";
		 puts(pname);
		 cout<<"\n\n\n\n Product Details:";
		 puts(des);
		 cout<<"\n\n\n\n Price:";
		 cout<<price;
		}
	char * ptype()
	{
		return type;
	}
	int rprice()
	{
		return price;
	}
}p;



void pwrite()
{
	ofstream out("products.dat",ios::binary | ios::in);
	products p;
	p.input();
	out.write((char*)&p,sizeof(p));
	out.close();
}

void pread ()
{
	ifstream in ("products.dat",ios::binary|ios::in);
	products p;
	while(in)
	{
	in.read((char*)&p,sizeof(p));
	if(in.eof())
	break;
	p.output();
}
	in.close();
	cout<<"\n reach end of file ";

}

void psearch()
{
	ifstream in ("products.dat",ios::binary |ios ::in);
	char pt[30];
	products p;
	char found='n';
	cout<<"\n \n enter product you want to search \t";
	gets(pt);
	while(!in.eof())
	{
		in.read((char*)&p,sizeof(p));
		if(strcmpi(p.ptype(),pt)==0)
		{       int val;
			p.output();
			found='y';
		}
	}
	if (found =='n')
	cout<<"\n \n product not found not found ";
	in.close();
}
int val;
void pbuy()
{
	ifstream in ("products.dat",ios::binary |ios ::in);
	char pt[30];
	products p;
	char found='n';
	cout<<"\n \n Enter Product you want to Buy \t";
	gets(pt);
	while(!in.eof())
	{
		in.read((char*)&p,sizeof(p));
		if(strcmpi(p.ptype(),pt)==0)
		{
			p.output();
			found='y';
			val=p.rprice();
			cout<<"\n Price To Be Paid Is :"<<val;
		}
	}
	if (found =='n')
	cout<<"\n \n product not found not found ";
	in.close();
}

void main()
{
	int q,p,d,found;
	long int sum , add,f,e,g,h,j,l,w,x,y,z,choice,pre=0;
	long int total=0;
	char pu,str[10],yes, et;
	clrscr();
	clrscr();
	lab:;
	clrscr();
	cout<<"\n \n \n \n \n \n \t \tWELCOME \n \n\n \n";
	cout<<"\t\t\t\t to \n\n\n";
	cout<<"\t\t\t\t\t\t Computer Arena \n\n\n\n";
	getch();
	clrscr();
	cout<<"\n\n\n\t\t\t ARE YOU A \n\t\t\t\t 1. SELLER  \n\t\t\t\t 2. BUYER "<<endl;
	cin>>q;
	clrscr();

	textcolor(12);
	if(q==1)
	{
		cout<<"\n\n\t\t\t\t TO LOGIN PRESS -> 1 \n\n\t\t\t\t TO SIGN UP PRESS -> 2"<<endl;
		cout<<"\n\t\t\t\t Enter Your Choice :";
		cin>>p;
		if(p==1)
		{
		clrscr();
		pchecks();

		}
		else if(p==2)
		{
		swrite();

		}
		else
		{
			cout<<"INVALID CHOICE";
			goto lab;
		}

clrscr();

gotoxy(25,6);
textcolor(5);
cputs("Computer Science Project Work \n");
printf("\n ");
textcolor(2);
cout<<"\n ";
cputs("                       WELCOME TO COMPUTER ARENA  ");
textcolor(2);
cout<<endl;
cputs("\n                 School :- DEWAN PUBLIC SCHOOL MEERUT");
cout<<endl;
gotoxy(10,29);
textcolor(3);
cputs("Subject Teacher :- \n Meena Dogra  ");
gotoxy(10,61);
textcolor(1);
cputs("          Submitted By :- \n Harshit Jain   ");

cputs("\n                                                                  Class:- XII C \n");
cputs("                                                                    Year:-2019-2020\n");
cout<<"\n\n";
textcolor(14+BLINK);
gotoxy(45,50);
cputs("PRESS ENTER TO CONTINUE!!!!!!!");
getch();
clrscr();



//LOADING THE PROJECT


gotoxy(28,15);
textcolor(LIGHTGREEN);
cputs("********************* \n");
gotoxy(29,16);
cputs("LOADING THE PROJECT");
gotoxy(28,17);
cputs("*********************");
gotoxy(32,25);
textcolor(MAGENTA+BLINK);
cputs("Please Wait    ");
textcolor(RED+GREEN);
delay(500);
gotoxy(28,31);
cputs("10% completed... ");
delay(500);
gotoxy(28,31);
cputs("20% completed... ");
delay(500);
gotoxy(28,31);
cputs("30% completed... ");
delay(500);
gotoxy(28,31);
cputs("40% completed... ");
delay(500);
gotoxy(28,31);
cputs("50% completed... ");
delay(500);
gotoxy(28,31);
cputs("60% completed... ");
delay(500);
gotoxy(28,31);
cputs("70% completed... ");
delay(500);
gotoxy(28,31);
cputs("80% completed... ");
delay(500);
gotoxy(28,31);
cputs("90% completed... ");
delay(500);
gotoxy(28,31);
cputs("100% completed... ");
delay(500);


again:;
clrscr();
cout<<"\n\n\t\t\t\t   1.SELL THE PRODUCTS  ";
cout<<"\n\n\t\t\t\t   2.DELETE YOUR ID    ";
cout<<"\n\n\t\t\t\t   3.MODIFY YOUR ID   ";
cout<<"\n\n\t\t\t\t   4.EXIT ";
cout<<"\n\n\n\t Enter Your Choice ->  \t";
cin>>d;
if(d==1)
{

clrscr();
pwrite();
cout<<"\n Do you wish to continue  (Y/N) ";
char r ;
cin>>r;
if(r=='Y'||r=='y')
	{
	goto again;
	}
	else
	{
	goto lab;
	}
}
else if(d==2)

{
clrscr();
sdel();
getch();
}
else if(d==3)
{
clrscr();
supdate();

cout<<"\n Do you wish to continue  (Y/N) ";
char h ;
cin>>h;
if(h=='Y'||h=='y')
	{
	goto again;
	}
	else
	{
	goto lab;
	} }

else if(d==4)
{


//TO EXIT FROM THE PROGRAM

	clrscr();

	cout<<"\n\n\n\t ARE YOU SURE TO EXIT FROM THE PROGRAM(Y/N)\t";
	cin>>et;
	if(et=='Y'||et=='y')
	{
	goto ex;
	}
	else
	{
	goto again;
	}

ex:;
clrscr();

textcolor(4);
cout<<endl;
cout<<endl;
cputs("HAVE A NICE DAY");
gotoxy(45,46);
textcolor(11+BLINK);
cputs("PRESS ENTER TO EXIT.....");
getch();
exit(0);
}

else

{
	cout<<"OOPS!!!!!!!YOUR CHOICE IS WRONG";
	getch();
	goto again;
}

}
	else if(q==2)
	{
		cout<<"\n\n\t\t\t\t TO LOGIN PRESS -> 1 \n\t\t\t\t TO SIGN UP PRESS -> 2 "<<endl;
		cout<<"\t\t\t\t Enter Your Choice :";
		cin>>p;
		if(p==1)
		{
			clrscr();
			pcheck();
		}
		else if(p==2)
		{
			cwrite();
		}
		else
		{
			cout<<"INVALID CHOICE";
			goto lab;
		}

clrscr();


gotoxy(25,6);
textcolor(5);
cputs("Computer Science Project Work \n");
printf("\n ");
textcolor(2);
cout<<"\n ";
cputs("                       WELCOME TO COMPUTER ARENA  ");
textcolor(2);
cout<<endl;
cputs("\n                 School :- DEWAN PUBLIC SCHOOL MEERUT");
cout<<endl;
gotoxy(10,29);
textcolor(3);
cputs("Subject Teacher :- \n Meena Dogra  ");
gotoxy(10,61);
textcolor(1);
cputs("          Submitted By :- \n Harshit Jain   ");

cputs("\n                                                                  Class:- XII C \n");
cputs("                                                                    Year:-2019-2020\n");
cout<<"\n\n";
textcolor(14+BLINK);
gotoxy(45,50);
cputs("PRESS ENTER TO CONTINUE!!!!!!!");
getch();
clrscr();



//LOADING THE PROJECT


gotoxy(28,15);
textcolor(LIGHTGREEN);
cputs("********************* \n");
gotoxy(29,16);
cputs("LOADING THE PROJECT");
gotoxy(28,17);
cputs("*********************");
gotoxy(32,25);
textcolor(MAGENTA+BLINK);
cputs("Please Wait    ");
textcolor(RED+GREEN);
delay(500);
gotoxy(28,31);
cputs("10% completed... ");
delay(500);
gotoxy(28,31);
cputs("20% completed... ");
delay(500);
gotoxy(28,31);
cputs("30% completed... ");
delay(500);
gotoxy(28,31);
cputs("40% completed... ");
delay(500);
gotoxy(28,31);
cputs("50% completed... ");
delay(500);
gotoxy(28,31);
cputs("60% completed... ");
delay(500);
gotoxy(28,31);
cputs("70% completed... ");
delay(500);
gotoxy(28,31);
cputs("80% completed... ");
delay(500);
gotoxy(28,31);
cputs("90% completed... ");
delay(500);
gotoxy(28,31);
cputs("100% completed... ");
delay(500);



//TO PURCHASE,SEARCH,MODIFY,DELETE,DISPLAY ALL RECORDS,DETAILS,NEW CUSTOMER

xyz:

clrscr();


textcolor(WHITE);

cout<<"\n\n\t\t\t    1.PURCHASE THE PRODUCTS    ";
cout<<"\n\n\t\t\t    2.DETAILS    ";
cout<<"\n\n\t\t\t    3.SERACH A PRODUCT   ";
cout<<"\n\n\t\t\t    4.DELETE YOUR ID    ";
cout<<"\n\n\t\t\t    5.MODIFY YOUR ID    ";
cout<<"\n\n\t\t\t    6.DISPLAY ALL PRODUCTS IN YOUR CART    ";
cout<<"\n\n\t\t\t    0.EXIT    ";
cout<<endl<<endl;

cout<<"\n\n\n\n\t Enter Your Choice ->  \t";
cin>>d;
if(d==1)
{
clrscr();
textcolor(WHITE);


//PURCHASE LIST

items:;

cout<<"\n\t\t\t\t**************** \n ";
cout<<"\n\t\t\t\tPURCHASE LISt \n ";
cout<<"\n\t\t\t\t****************\n\n ";
cout<<"\n\n\t\t\t 1.PENDRIVE ";
cout<<"\n\n\t\t\t 2.SCANNER ";
cout<<"\n\n\t\t\t 3.PRINTER ";
cout<<"\n\n\t\t\t 4.WEBCAM ";
cout<<"\n\n\t\t\t 5.GRAPHIC CARDS ";
cout<<"\n\n\t\t\t 6.RAM ";
cout<<"\n\n\t\t\t 7.HARD DISK ";
cout<<"\n\n\t\t\t 8.WINDOWS ORIGINAL CD's " ;
cout<<"\n\n\t\t\t 9.ANTIVIRUS ";
cout<<"\n\n\t\t\t 10.MOUSE ";

pbuy();
getch();

    clrscr();

    cash:;

    cout<<"\n\n\n\n\n\n\t\t\t\t COMPUTER ARENA \n";

    cout<<"\n\n\t\t\t\t    CASH MEMO  \n";

    cout<<"\n\n\n\n\n\n\n\n";




	money:;
		 cout<<"total price to be paid = "<<val;

		cout<<"\n\n\n\n\t\t\tEnter the cash paid =\t";

		cin>>total;

		cout<<"\n\n\n\t\t\tCASH RECEIVED ="<<total;

      if((pre+total)<val)
      {
		  pre=total;

		  cout<<"\n\n\tThe money you paid is less!!!!! ";

		  getch();

		  goto money;

      }

      clrscr();

	cout<<"\n\n\n\n\n\tNO CREDIT OF THE ADDITIONAL DUTY OF";
	cout<<"\n\n\t  CUSTOMS LEVIED UNDER SECTION (5) OF";
	cout<<"\n\n\t  SECTION-3 OF THE CUSTOMS TARIFF ACT";
	cout<<"\n\n\t  1975 HAVE BEEN AVAILED/SHALL BE ADMISSABLE\n\n";
	cout<<"\n\n\n\n\n\t\tCASH RECEIVED:\t"<<total;
	cout<<"\n\n\t\tCASH AMOUNT :\t"<<val;
	cout<<"\n\n\t\tBALANCE RETURNED:\t"<<total-val;
	cout<<"\n\n\tTHANK YOU .\t\t\t\tVISIT US AGAIN\n";
	cout<<"\n\n\tTHANK YOU FOR USING OUR SERVICE \n\n";
	getch();

      goto xyz;

}

else if(d==2)

{


	//TO DISPLAY THE SHOP DETAILS

clrscr();

cout<<"\n\n\n\n\n\t\t\t\tSHOP DETAILS\n\n\n";
cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
cout<<"\t\t # TIMINGS :10 A.M to 02 P.M & 03 P.M to 10 P.M                \n";
cout<<"\t\t # SHOP WILL BE CLOSED ON MONDAY.                              \n";
cout<<"\t\t # GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED.             \n";
cout<<"\t\t # COLLECT YOUR BILL AFTER PAYMENT.                            \n";
cout<<"\t\t # ADDRESS:A/5,PL SHARMA ROAD,MEERUT                           \n";
cout<<"\t\t # DO NOT BREAK ANY SHOP ITEMS.                                \n";
cout<<"\t\t # FOR ANY COMPLAINT CONTACT-9400000000.                       \n";
cout<<"\t\t # WELL QUALIFIED STAFF MEMBERS.                               \n";
cout<<"\t\t # Email:-www.computerarena.com                             \n";
cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
getch();

clrscr();

goto xyz;


}

else if (d==3)
{

//TO SEARCH THE product

clrscr();

psearch();

getch();

goto xyz;

}


else if(d==4)
{
	//TO DELETE THE CUSTOMER ID

	clrscr();

	del();

	getch();

	goto xyz;

}

else if(d==5)
{

	//TO MODIFY THE CUSTOMER DETAILS

	clrscr();

	update();

	getch();

	goto xyz;

}


else if(d==6)
{


	//TO DISPLAY ALL SAVED PRODUCTS

	clrscr();

	pread();

	getch();

	goto xyz;

}


else if(d==0)
{

	//TO EXIT FROM THE PROGRAM

	clrscr();

	cout<<"\n\n\n\tARE YOU SURE TO EXIT FROM THE PROGRAM(Y/N)\t";

	cin>>et;

	if(et=='Y'||et=='y')

	{

		goto ey;
	}
else

{
	goto xyz;
}
ey:

clrscr();

textcolor(RED);

cputs("HAVE A NICE DAY");

gotoxy(45,45);

textcolor(YELLOW+BLINK);

cputs("PRESS ENTER TO EXIT.....");

getch();

exit(0);

}
else
{
	cout<<"OOPS!!!!!!!YOUR CHOICE IS WRONG";

	getch();

	goto xyz;

}

}

	else

	{

		goto lab;

	}

}