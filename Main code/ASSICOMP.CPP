#include<assibox.h>
#include<assimenu.h>
#include<assiaboutus.h>
#include<assistart.h>
#include<assihelp.h>
#include<assiprocess.h>
#include<assisale.h>
#include<assilast.h>

void main(){
	bg:
	int i,a=0,c=0,e=0,g=0,b=0,d=0,f=0,h=0;
	char ch;
	textbackground(BLACK);
	_setcursortype(_NOCURSOR);
	clrscr();
	login();
	start();

aaa:
do{     textbackground(BLUE);
	clrscr();

       /*	textbackground(WHITE); textcolor(BLACK);
	gotoxy(21,25);  cprintf("[l]+[ENTER] TO LOCK    [] TO MOVE UP    [] TO MOVE DOWN");
	textcolor(GREEN); gotoxy(22,25); cprintf("l");
			       gotoxy(26,25); cprintf("ENTER");
			       gotoxy(45,25); cprintf("");
			       gotoxy(63,25); cprintf(""); */

	textbackground(BLUE);
	box1(1,1,23);	menu1(23,15,2,2,&a);
       /*	gotoxy(2,3);  printf("PRODUCT INFO  ");
	gotoxy(2,7);  printf("EMPLOYEE INFO ");
	gotoxy(2,11); printf("SALE INFO     ");
	gotoxy(2,15); printf("HELP          "); */
	switch(a){
	case 0:
		do{
			for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }

			mainmenu();
			submenu(0);

			textbackground(BLUE);
			box(18,1,6); c=0;	menu3(5,15,19,2,&c);
			textcolor(BLUE);
			gotoxy(19,3); cprintf("SHOW INFO     ");
			switch(c){
			case 0: //input computer
				inputc();
				break;
			case 1: //show computer
				do{
				for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(35,1+i); clreol(); }
				mainmenu();
				submenu(0);
				textbackground(BLUE);
				box(35,3,3); b=0; menu2(2,15,36,4,&b);
				switch(b){
				case 0:
					outputcless();
					break;
				case 1:
					outputcmore();
					break;
				}
				}while(b!=2);
				break;
			case 2: //search computer
				searchcid();
				break;
			case 3: //edit computer
				editcom();
				break;
			case 4: //delete computer
				deletecom();
				break;
			}
		}while(c!=5);
		break;

	case 4: //employee info
		do{
			for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }

			mainmenu();
			submenu(4);

			textbackground(BLUE);
			box(18,5,6); e=0;	menu3(5,15,19,6,&e);
			textcolor(BLUE);
			gotoxy(19,7); cprintf("SHOW INFO     ");
			switch(e){
			case 0: //input em
				inputemp();
				break;
			case 1: //show em
				do{
				for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }
				mainmenu();
				submenu(4);
				textbackground(BLUE);
				box(35,7,3); d=0; menu2(2,15,36,8,&d);
				switch(d){
				case 0:
					outputemless();
					break;
				case 1:
					outputemmore();
					break;
				}
				}while(d!=2);
				break;
			case 2: //search em
				searchemid();
				break;
			case 3: //edit em
				editem();
				break;
			case 4: //delete em
				deleteem();
				break;
			}
		}while(e!=5);
		break;
	case 8: //sale & order

		do{
			for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }

			mainmenu();
			submenu(8);

			textbackground(BLUE);
			box(18,9,6); g=0;	menu3(5,15,19,10,&g);
			textcolor(BLUE);
			gotoxy(19,11); cprintf("SHOW INFO     ");
			switch(g){
			case 0: //input sale
				sale();
				break;

			case 1: //show sale
				do{
				for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }
				mainmenu();
				submenu(8);
				textbackground(BLUE);
				box(35,11,3); f=0; menu2(2,15,36,12,&f);
				switch(f){
				case 0:
					outputsaleless();
					break;
				case 1:
					outputsalemore();
					break;
				}
				}while(f!=2);
				break;
			case 2: //search sale
				searchsaleid();
				break;
			case 3: //edit sale
				editsale();
				break;
			case 4: //delete sale
				deletesale();
				break;
			}
		}while(g!=5);
		break;
	case 12://help
		do{
			for(i=0;i<25;i++){ textbackground(BLUE); gotoxy(18,1+i); clreol(); }

			mainmenu();

			textbackground(BLUE);
			box(18,13,4); h=0; menu4(3,15,19,14,&h);
			switch(h){
			case 0:
				helppro();
				break;
			case 1:
				helpemp();
				break;
			case 2:
				helpsale();
				break;
			}
		}while(h!=3);
		break;
	case 16://about u
		textbackground(BLACK);
		loading("LOADING...");
		textbackground(BLUE);
		aboutus();
		break;
	case 20://exit
		textbackground(BLUE);
		frame();
		message("DO YOU WANT TO EXIT PROGRAM?","");
		char ask;
		yesno(&ask);
		if(ask=='n' ||ask=='N') break;
		if(ask=='y' ||ask=='Y'){ textbackground(BLACK); finish(); exit(1); }
	case 111:
		lock();
		goto bg;
	}
}while(1);
}