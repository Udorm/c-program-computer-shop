#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

void start(){
       //	clrscr();
	int i=0,j=0,a=0,c=16,b=22,d=13;
	clrscr();
	_setcursortype(_NOCURSOR);

   while(b>=0){
	clreol();
	textcolor(LIGHTGREEN);
	gotoxy(27,4+b);
	cprintf("                ÜÜÜÜÜÜÜÜÜÛÛ\n\r");
	gotoxy(27,4+b);
	b--; delay(50);
   }

   gotoxy(27,5);
   while(c>=0){
	clreol();
	textcolor(LIGHTGREEN);
	gotoxy(27,4+c);
	cprintf(" ÜÜÜ     ÜÜÜ    ÜÜÜ     ÜÜÜ\n\r");
	gotoxy(27,5+c);
	cprintf(" Ûßß     Ûßß    Ûßß     Ûßß\n\r");
	gotoxy(27,6+c);
	cprintf("ÛÛÛÛÛÛÛÛ  ÛÛ   ÛÛÛÛÛÛÛÛ  ÛÛ\n\r");
	gotoxy(27,7+c);
	cprintf("ÛÛ    ÛÛ  ÛÛ   ÛÛ    ÛÛ  ÛÛ\n\r");
	gotoxy(27,8+c);
	cprintf("ÛÛ    ÛÛ  ÛÛ   ÛÛ    ÛÛ  ÛÛ\n\r");
	gotoxy(27,9+c);
	cprintf("ÛÛÛÛ  ÛÛÛÛÛÛ   ÛÛÛÛ  ÛÛÛÛÛÛ\n\r");
	gotoxy(27,9+c);
	c--; delay(50);
   }

   gotoxy(27,10);
   while(d>0){
	clreol();
	textcolor(LIGHTGREEN);
	gotoxy(27,9+d);
	cprintf("    ÜÜ   Ü         ÜÜÜÜÜ\n\r");
	gotoxy(27,10+d);
	cprintf("     Û   Û         Û   Û\n\r");
	gotoxy(27,11+d);
	cprintf("     ÛÜßÜÛ         ÛÛ  Û\n\r");
	gotoxy(27,11+d);
	d--; delay(50);
   }
	delay(500);
	textcolor(LIGHTBLUE);
	textbackground(BLACK);
	gotoxy(4,3);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(4,4);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(4,5);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(4,6);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(4,7);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(4,8);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(4,9);
	cprintf("      ÛÛÛÛÛÛ      ");
	gotoxy(4,10);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(4,11);
	cprintf("ÛÛ              ÛÛ");
	gotoxy(4,12);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");

	delay(500);
	textcolor(LIGHTBLUE);
	textbackground(BLACK);
	gotoxy(60,3);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(60,4);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(60,5);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(60,6);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(60,7);
	cprintf("ÛÛ°°°°°°°°°°°°°°ÛÛ");
	gotoxy(60,8);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(60,9);
	cprintf("      ÛÛÛÛÛÛ      ");
	gotoxy(60,10);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(60,11);
	cprintf("ÛÛ              ÛÛ");
	gotoxy(60,12);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");


	delay(500);
	textcolor(WHITE);
	gotoxy(1,17);
	cprintf(" ÛÛÛÛ ÛÛÛÛÛÛ ÛÛÛ ÛÛÛ ÛÛÛÛÛ ÛÛ  ÛÛ ÛÛÛÛÛÛ ÛÛÛÛ ÛÛÛÛÛÛ    ÛÛÛÛ ÛÛ ÛÛ ÛÛÛÛÛÛ ÛÛÛÛÛ\n");
	gotoxy(1,18);
	cprintf(" ÛÛ   ÛÛ  ÛÛ ÛÛ Û ÛÛ ÛÛ  Û ÛÛ  ÛÛ   ÛÛ   ÛÛ   ÛÛ  ÛÛ    ÛÛ   ÛÛ ÛÛ ÛÛ  ÛÛ ÛÛ  Û\n");
	gotoxy(1,19);
	cprintf(" ÛÛ   ÛÛ  ÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ ÛÛ  ÛÛ   ÛÛ   ÛÛÛ  ÛÛÛÛÛ     ÛÛÛÛ ÛÛÛÛÛ ÛÛ  ÛÛ ÛÛÛÛÛ\n");
	gotoxy(1,20);
	cprintf(" ÛÛ   ÛÛ  ÛÛ ÛÛ   ÛÛ ÛÛ    ÛÛ  ÛÛ   ÛÛ   ÛÛ   ÛÛ  ÛÛ      ÛÛ ÛÛ ÛÛ ÛÛ  ÛÛ ÛÛ   \n");
	gotoxy(1,21);
	cprintf(" ÛÛÛÛ ÛÛÛÛÛÛ ÛÛ   ÛÛ ÛÛ    ÛÛÛÛÛÛ   ÛÛ   ÛÛÛÛ ÛÛ  ÛÛ    ÛÛÛÛ ÛÛ ÛÛ ÛÛÛÛÛÛ ÛÛ   \n");


	delay(500);
	textcolor(YELLOW);
	gotoxy(1,16);
	cprintf(" ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß");
	delay(500);
	gotoxy(1,22);
	cprintf(" ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ");

	while(!kbhit()){
		clreol();
		textcolor(random(9)+7);
		gotoxy(2+j,24);
		cprintf("PRESS ANY KEY TO CONTINUE");
		gotoxy(2+j,24);

		if(a==0) {j++; if(j>53) a=1;}
		if(a==1) {j--; if(j<0)  a=0;}
		delay(50);
	}

getch();
	gotoxy(1,24); clreol();

	while(i<1000){
		textcolor(random(8)+7);
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		i++;
		delay(1);
		textcolor(WHITE);
		gotoxy(32,25);
		cprintf("PROCESSING...");
	}



//getch();
}


void finish(){
       //	clrscr();
	int i=0;
	clrscr();
	//textbackground(BLACK);

	while(i<1000){
		textcolor(random(8)+7);
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		gotoxy(random(80)+1,random(23)+1);
		cprintf("Û");
		i++;
		delay(1);
		textcolor(WHITE);
		gotoxy(35,25);
		cprintf("EXISTING...");
	}

}


void loading(char loading[20]){
       //	clrscr();
	int i=0;
	clrscr();
	_setcursortype(_NOCURSOR);

	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(31,20);cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
	gotoxy(31,21);cprintf("º                º");
	gotoxy(31,22);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
	gotoxy((80-strlen(loading))/2,23);cprintf("%s",loading);

	textcolor(GREEN); textbackground(GREEN);
	while(i<16){
		gotoxy(32+i,21);
		cprintf(" ");
		i++;
		delay(100);
	}
	delay(500);


}





