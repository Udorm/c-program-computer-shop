#include<stdio.h>
#include<conio.h>

void menu1(int row,int space,int x,int y,int *j){
	 int i,b;
	 char ch;
do{
	textbackground(GREEN);
	for(i=0;i<space;i++){
		for(b=0;b<3;b++){
		gotoxy(x+i,y+*j+b);
		cprintf("%c",' ');
		}
	}
	gotoxy(x,y+1);
	printf("PRODUCT INFO  ");
	gotoxy(x,y+1+4);
	printf("EMPLOYEE INFO ");
	gotoxy(x,y+1+8);
	printf("SALE INFO     ");
	gotoxy(x,y+1+12);
	printf("HELP          ");
	gotoxy(x,y+1+16);
	printf("ABOUT US");
	gotoxy(x,y+1+20);
	printf("EXIT PROGRAM");
	gotoxy(1,5);
	printf("ฬอออออออออออออออน");
	gotoxy(1,9);
	printf("ฬอออออออออออออออน");
	gotoxy(1,13);
	printf("ฬอออออออออออออออน");
	gotoxy(1,17);
	printf("ฬอออออออออออออออน");
	gotoxy(1,21);
	printf("ฬอออออออออออออออน");

	ch=getch();
	textbackground(WHITE);
	for(i=0;i<space;i++){
		for(b=0;b<3;b++){
		gotoxy(x+i,y+*j+b);
		cprintf("%c",' ');
		}
	}
	switch(ch){
		case 'l':*j=111;
			  break;
		case 72: *j=*j-4; if(*j<0) *j=row-3; break;
		case 80: *j=*j+4; if(*j>row-3) *j=0; break;
	}
}while(ch!=13);
}

void menu2(int row,int space,int x,int y,int *k){
	char ch; int i;
do{
	textbackground(GREEN);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}

	gotoxy(x,y);
	printf("SHOW AS LIST");
	gotoxy(x,y+1);
	printf("SHOW ALL DETAIL");
	gotoxy(x,y+2);
	printf("BACK");
	ch=getch();
	textbackground(15);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}
	switch(ch){
		case 72: *k=*k-1; if(*k<0) *k=row; break;
		case 80: *k=*k+1; if(*k>row) *k=0; break;
	}
}while(ch!=13);
}


void menu3(int row,int space,int x,int y,int *k){
	char ch; int i;
do{
	textbackground(GREEN);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}

	gotoxy(x,y);
	printf("INPUT INFO");
	gotoxy(x,y+1);
	printf("SHOW INFO     ");
	gotoxy(x,y+2);
	printf("SEARCH INFO");
	gotoxy(x,y+3);
	printf("EDIT INFO");
	gotoxy(x,y+4);
	printf("DELETE INFO");
	gotoxy(x,y+5);
	printf("BACK");
	ch=getch();
	textbackground(15);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}
	switch(ch){
		case 72: *k=*k-1; if(*k<0) *k=row; break;
		case 80: *k=*k+1; if(*k>row) *k=0; break;
	}
}while(ch!=13);
}


void menu4(int row,int space,int x,int y,int *k){
	char ch; int i;
do{
	textbackground(GREEN);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}

	gotoxy(x,y);
	printf("PRODUCT HELP");
	gotoxy(x,y+1);
	printf("EMPLOYEE HELP");
	gotoxy(x,y+2);
	printf("SALE HELP");
	gotoxy(x,y+3);
	printf("BACK");

	ch=getch();
	textbackground(15);
	for(i=0;i<space;i++){
		gotoxy(x+i,y+*k);
		cprintf("%c",' ');
	}
	switch(ch){
		case 72: *k=*k-1; if(*k<0) *k=row; break;
		case 80: *k=*k+1; if(*k>row) *k=0; break;
	}
}while(ch!=13);
}

