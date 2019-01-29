#include<stdio.h>
#include<conio.h>

void aboutus(){
	int i; char ch;
	_setcursortype(_NOCURSOR);
	clrscr();
	textbackground(BLUE);
	textcolor(WHITE);
	gotoxy(1,1);
	cprintf(" ษออ[ ]ออออออออออออออออออออออออ[ COMPUTER  SHOP ]อออออออออออออออออออออออออออออป");
	for(i=1;i<24;i++){
	gotoxy(1,1+i);
	cprintf(" บ                                                                            บ");
	}
	gotoxy(1,1+i);
	cprintf(" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	textcolor(LIGHTGREEN); gotoxy(6,1); cprintf("þ");

	textbackground(BLACK);
	textcolor(WHITE);
	gotoxy(20,3);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออป");
	for(i=1;i<7;i++){
	gotoxy(20,3+i);
	cprintf("บ                                         บ");
	}
	gotoxy(20,3+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออผ");

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(27,12);
	cprintf("ษอออออออออออออออออออออออออออป");
	for(i=1;i<2;i++){
	gotoxy(27,12+i);
	cprintf("บ                           บ");
	}
	gotoxy(27,12+i);
	cprintf("ศอออออออออออออออออออออออออออผ");

	textbackground(YELLOW);
	textcolor(WHITE);
	gotoxy(10,18);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	for(i=1;i<4;i++){
	gotoxy(10,18+i);
	cprintf("บ                                                             บ");
	}
	gotoxy(10,18+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

	textbackground(BLACK); textcolor(LIGHTGREEN);
	gotoxy(23,4); cprintf("ROYAL UNIVERSITY OF PHNOM PENH (RUPP)");
	textbackground(BLACK); textcolor(WHITE);
	gotoxy(30,5); cprintf("SUBJECT    : C PROGRAM");
	gotoxy(30,6); cprintf("GENERATION : 17th");
	gotoxy(30,7); cprintf("YEAR I     : 2013-2014");
	gotoxy(30,8); cprintf("CLASS      : M2 (B302)");
	gotoxy(30,9); cprintf("GROUP      : VII");

	textbackground(WHITE); textcolor(BLACK);
	gotoxy(28,13); cprintf("TEACHER  :  MR. HENG SAM AN");

	textbackground(YELLOW); textcolor(WHITE);
	gotoxy(35,17); cprintf("GROUP MEMBERS");

	textbackground(RED); textcolor(YELLOW);
	gotoxy(59,24); cprintf("PRESS [ESC] TO BACK ");

	textbackground(BLUE); textcolor(WHITE);
	gotoxy(3,24); cprintf("ALL RIGHT RESERVED 2014");

	textbackground(YELLOW); textcolor(WHITE);
	gotoxy(12,19); cprintf("                       1. PHON  UDORM");
	gotoxy(12,20); cprintf("2. EV  DAVITH          3. CHHON SELAVITYEA   4. CHOR RAN");
	gotoxy(12,21); cprintf("5. KIM SARAY           6. PI    KEASA        7. LY   KIMYAV");
      a:ch=getch();
	if(ch!=27) goto a;
}

void frame(){
	int i;
	_setcursortype(_NOCURSOR);
	clrscr();
	textbackground(BLUE);
	textcolor(WHITE);
	gotoxy(1,1);
	cprintf(" ษอออออออออออออออออออออออออออออ[ COMPUTER  SHOP ]อออออออออออออออออออออออออออออป");
	for(i=1;i<23;i++){
	gotoxy(1,1+i);
	cprintf(" บ                                                                            บ");
	}
	gotoxy(1,1+i);
	cprintf(" ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

}
