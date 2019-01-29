#include<conio.h>
#include<stdio.h>
#include<string.h>

void mainmenu(){
	textbackground(BLUE);
	clrscr();
	_setcursortype(_NOCURSOR);
	textcolor(BLACK); textbackground(WHITE);
	cprintf("ษอออออออออออออออป\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บPRODUCT INFO  บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ฬอออออออออออออออน\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บEMPLOYEE INFO บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ฬอออออออออออออออน\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บSALE INFO     บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ฬอออออออออออออออน\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บHELP          บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ฬอออออออออออออออน\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บABOUT US       บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ฬอออออออออออออออน\n\r");
	cprintf("บ               บ\n\r");
	cprintf("บEXIT PROGRAM   บ\n\r");
	cprintf("บ               บ\n\r");
	cprintf("ศอออออออออออออออผ");
}


void submenu(int x){
	_setcursortype(_NOCURSOR);
	textcolor(BLACK); textbackground(WHITE);
	gotoxy(18,1+x); cprintf("ษอออออออออออออออป");
	gotoxy(18,2+x); cprintf("บINPUT INFO     บ"); textcolor(BLUE);
	gotoxy(18,3+x); cprintf("บSHOW INFO     บ"); textcolor(BLACK); gotoxy(18,3+x); cprintf("บ"); gotoxy(34,3+x); cprintf("บ");
	gotoxy(18,4+x); cprintf("บSEARCH INFO    บ");
	gotoxy(18,5+x); cprintf("บEDIT INFO      บ");
	gotoxy(18,6+x); cprintf("บDELETE INFO    บ");
	gotoxy(18,7+x); cprintf("บBACK           บ");
	gotoxy(18,8+x); cprintf("ศอออออออออออออออผ");
	textbackground(BLACK);
	gotoxy(19,9+x); cprintf("                ");
}

void box(int x,int y,int under){
	int i;

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<under+2;i++){
		gotoxy(x+1,y+1+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÝ");
	}

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y);
	cprintf("ษอออออออออออออออป");
	for(i=0;i<under;i++){
	gotoxy(x,y+1+i);
	cprintf("บ               บ");
	}
	gotoxy(x,y+1+i);
	cprintf("ศอออออออออออออออผ");
}

void box1(int x,int y,int under){
	int i;

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(x,y);
	cprintf("ษอออออออออออออออป");
	for(i=0;i<under;i++){
	gotoxy(x,y+1+i);
	cprintf("บ               บ");
	}
	gotoxy(x,y+1+i);
	cprintf("ศอออออออออออออออผ");
}



void inputgraphic(char label[80]){

	textcolor(BLUE); textbackground(WHITE);
	gotoxy(3,3); cprintf("%s",label);

	textcolor(LIGHTGREEN); textbackground(BLUE);
	gotoxy(11,6);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(11,7);
	cprintf("ÛÛฐฐฐฐฐฐฐฐฐฐฐฐฐฐÛÛ");
	gotoxy(11,8);
	cprintf("ÛÛฐฐฐฐฐฐฐฐฐฐฐฐฐฐÛÛ");
	gotoxy(11,9);
	cprintf("ÛÛฐฐฐฐฐฐฐฐฐฐฐฐฐฐÛÛ");
	gotoxy(11,10);
	cprintf("ÛÛฐฐฐฐฐฐฐฐฐฐฐฐฐฐÛÛ");
	gotoxy(11,11);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(11,12);
	cprintf("      ÛÛÛÛÛÛ      ");
	gotoxy(11,13);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(11,14);
	cprintf("ÛÛ ID :         ÛÛ");
	gotoxy(11,15);
	cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(4,18); cprintf("BRAND NAME :");
			   textbackground(GREEN);gotoxy(17,18);cprintf("            "); //10

	textcolor(YELLOW); textbackground(BLUE); gotoxy(4,20); cprintf("MODEL :");
			   textbackground(2);gotoxy(12,20);cprintf("                 ");//17

	textcolor(YELLOW); textbackground(BLUE); gotoxy(4,22); cprintf("TYPE  :");
			   textbackground(2);gotoxy(12,22);cprintf("                 ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,6); cprintf("RAM     :");
			   textbackground(2);gotoxy(51,6); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,8); cprintf("HDD     :");
			   textbackground(2);gotoxy(51,8); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,10); cprintf("SCREEN  :");
			   textbackground(2);gotoxy(51,10); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,12); cprintf("CPU     :");
			   textbackground(2);gotoxy(51,12); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,14); cprintf("WEIGHT  :");
			   textbackground(2);gotoxy(51,14); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,16); cprintf("COLOR   :");
			   textbackground(2);gotoxy(51,16); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,18); cprintf("DATE    :");
			   textbackground(2);gotoxy(51,18); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,20); cprintf("QUANTITY:");
			   textbackground(2);gotoxy(51,20); cprintf("                     ");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,22); cprintf("PRICE   :");
			   textbackground(2);gotoxy(51,22); cprintf("                    $");
}


void outputgraphic(){

	int i;
	textbackground(WHITE); textcolor(BLUE);
	gotoxy(3,3); cprintf("                         COMPUTER LESS INFORMATION                          ");

	textbackground(LIGHTGREEN); textcolor(BLACK);
	gotoxy(4,5); cprintf(" COMP ID  ");   		textcolor(RED); gotoxy(10,5);  cprintf("I"); textcolor(BLACK);//9
	gotoxy(15,5); cprintf(" BRAND NAME  ");  	textcolor(RED); gotoxy(16,5); cprintf("B"); textcolor(BLACK);//12
	gotoxy(29,5); cprintf("      MODEL     ");      textcolor(RED); gotoxy(35,5); cprintf("M"); textcolor(BLACK);//15
	gotoxy(46,5); cprintf("  TYPE   ");  		textcolor(RED); gotoxy(48,5); cprintf("T"); textcolor(BLACK);//8
	gotoxy(56,5); cprintf(" QUANTITY  "); 		textcolor(RED); gotoxy(57,5); cprintf("Q"); textcolor(BLACK);//10
	gotoxy(68,5); cprintf("   PRICE  "); 		textcolor(RED); gotoxy(71,5); cprintf("P"); textcolor(BLACK);//10

	textbackground(BLACK);
	for(i=0;i<17;i++){
		gotoxy(4,6+i);
		cprintf("%10c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(15,6+i);
		cprintf("%13c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(29,6+i);
		cprintf("%16c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(46,6+i);
		cprintf("%9c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(56,6+i);
		cprintf("%11c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(68,6+i);
		cprintf("%10c",' ');
	}

	textbackground(YELLOW); textcolor(BLUE);
	gotoxy(3,23); cprintf("SORT INFORMATION: [i]=ID, [b]=BRAND, [m]=MODEL, [t]=TYPE, [q]=QTY, [p]=PRICE");
	textbackground(BLUE); textcolor(YELLOW);
	gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");
}


void message(char ask[30],char detail[30]){

	int i;
	textbackground(BLUE);
	_setcursortype(_NOCURSOR);

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<6;i++){
		gotoxy(23,10+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	}


	textcolor(WHITE); textbackground(YELLOW);
	for(i=0;i<4;i++){
		gotoxy(22,9);
		cprintf("ษออออออออออออ MESSAGE อออออออออออออป");
		gotoxy(22,10+i);
		cprintf("บ                                  บ");
		gotoxy(22,11+i);
		cprintf("ศออออออออออออออออออออออออออออออออออผ");
	}

	textcolor(BLUE);
	for(i=0;i<3;i++){
		gotoxy(23,11+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	}

	textcolor(YELLOW); textbackground(GREEN);
	gotoxy(23,10); cprintf("%34c",' ');
	gotoxy((80-strlen(ask))/2,10); cprintf("%s",ask);

	textcolor(WHITE); textbackground(BLUE);
	gotoxy((80-strlen(detail))/2,12); cprintf("%s",detail);
}


void yesno(char *ch){

	int i;
	textbackground(WHITE); textcolor(BLUE);
	gotoxy(29,12);
	cprintf(" YES ");
	textbackground(WHITE); textcolor(RED);
	gotoxy(30,12); cprintf("Y");

	textbackground(BLUE); textcolor(BLACK);
	gotoxy(30,13); cprintf("฿฿฿฿฿");
	gotoxy(34,12); cprintf("Ü");

	textbackground(WHITE); textcolor(BLUE);
	gotoxy(44,12);
	cprintf("  NO  ");
	textbackground(WHITE); textcolor(RED);
	gotoxy(46,12); cprintf("N");
	textbackground(BLUE); textcolor(BLACK);
	gotoxy(45,13); cprintf("฿฿฿฿฿฿");
	gotoxy(50,12); cprintf("Ü");

	textcolor(YELLOW); textbackground(BLUE);
	gotoxy(2,25); cprintf("[PRESS 'Y' OR 'y' FOR YES]   [PRESS 'N' OR 'n' FOR NO]");
	do{*ch=getch();}while(*ch!='n'&*ch!='N'&&*ch!='Y'&&*ch!='y');
}



void inputmix(char S[],int ability){
	char ch;
	int i=0;
	do{
	    xy1:
	    ch=getch();
	    if(ch!=13){       //if we don't put this condition, when we press enter 'i' will increase 1
		if(ch==8){
			if(i>0){
				printf("%c",ch);  //print backspace(move cursor back)
				printf(" ");      //print on the old char by space(cursor go forward)
				printf("%c",ch);  //print backspace(move cursor back)
				i--;
				S[i]='\0';
			}
		}else if(i<ability){
			printf("%c",ch);
			//printf("*");
			S[i]=ch;
			i++;
			S[i]='\0';
		}
	    }
	}while(ch!=13);
	if(i==0) goto xy1;
}

void inputpass(char S[],int ability){
	char ch;
	int i=0;
	do{
	    xy1:
	    ch=getch();
	    if(ch!=13){       //if we don't put this condition, when we press enter 'i' will increase 1
		if(ch==8){
			if(i>0){
				printf("%c",ch);  //print backspace(move cursor back)
				printf(" ");      //print on the old char by space(cursor go forward)
				printf("%c",ch);  //print backspace(move cursor back)
				i--;
				S[i]='\0';
			}
		}else if(i<ability){
			//printf("%c",ch);
			printf("*");
			S[i]=ch;
			i++;
			S[i]='\0';
		}
	    }
	}while(ch!=13);
	if(i==0) goto xy1;
}

void inputnum(char S[],int ability){
	char ch;
	int i=0;
	//int b=0;
	do{
	     xy:
	    ch=getch();
	    //if(ch=='.' && b==1) goto xy;
	    //if(ch=='.') b=1;

	    if(ch>='0' && ch<='9' || ch==8 || ch=='.'){



		if(ch==8){
			if(i>0){
				//if(
				printf("%c",ch);
				printf(" ");
				printf("%c",ch);
				i--;
				S[i]='\0';
			}
		}else if(i<ability){
			printf("%c",ch);
			//printf("*");
			S[i]=ch;
			i++;
			S[i]='\0';
		}
	    }
	}while(ch!=13);
	if(i==0) goto xy;
}



void inputemgraphic(char label[50]){

	int i;
	gotoxy(3,3); textbackground(GREEN);
	cprintf("%76c",' '); textcolor(WHITE);
	gotoxy((80-strlen(label))/2,3); cprintf("%s",label);

	textcolor(CYAN); textbackground(BLUE);
	for(i=0;i<6;i++){
		gotoxy(3,4+i);
		cprintf("Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿Ü฿");
	}

	textbackground(BLUE); textcolor(GREEN);
	gotoxy(30,6);         cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	gotoxy(22,7); cprintf("ÝÝÝÝÝÝÝÝÛÛ                ÛÛÞÞÞÞÞÞÞÞ");
	gotoxy(30,8);         cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
	for(i=0;i<5;i++){
		gotoxy(22,4+i); cprintf("ÝÝÝÝÝÝÝÝ");
		gotoxy(50,4+i); cprintf("ÞÞÞÞÞÞÞÞ");
	}

	textcolor(YELLOW);
	gotoxy(33,7); cprintf("ID :");

	textcolor(YELLOW); textbackground(BLUE); gotoxy(3,11);  cprintf("NAME");
	textcolor(YELLOW); textbackground(BLUE); gotoxy(7,12);  cprintf("FIRST :");
			   textbackground(2);	 gotoxy(14,12); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(7,14);  cprintf("LAST  :");
			   textbackground(2);	 gotoxy(14,14); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(3,16);  cprintf("SEX       :");
			   textbackground(2);	 gotoxy(14,16); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(3,18);  cprintf("AGE       :");
			   textbackground(2);	 gotoxy(14,18); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(3,20);  cprintf("POSITION  :");
			   textbackground(2);	 gotoxy(14,20); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(3,22);  cprintf("PHONE     :");
			   textbackground(2);	 gotoxy(14,22); cprintf("%20c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,12); cprintf("SALARY (DOLLA)   :");
			   textbackground(2);	 gotoxy(58,12); cprintf("%21c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,14); cprintf("START WORK DATE  :");
			   textbackground(2);	 gotoxy(58,14); cprintf("%21c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(40,16); cprintf("ADDRESS");
	textcolor(YELLOW); textbackground(BLUE); gotoxy(48,17); cprintf("KHAN     :");
			   textbackground(2);	 gotoxy(58,17); cprintf("%21c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(48,19); cprintf("SANGKAT  :");
			   textbackground(2);	 gotoxy(58,19); cprintf("%21c",' ');
	textcolor(YELLOW); textbackground(BLUE); gotoxy(48,21); cprintf("CITY     :");
			   textbackground(2);	 gotoxy(58,21); cprintf("%21c",' ');
}


void outputemgraphic(){

	int i;
	char label1[50]="EMPLOYEES LESS INFORMATION";
	gotoxy(3,3); textbackground(WHITE);
	cprintf("%76c",' '); textcolor(BLUE);
	gotoxy((80-strlen(label1))/2,3); cprintf("%s",label1);

	textbackground(LIGHTGREEN); textcolor(BLACK);
	gotoxy(3,5); cprintf("  EMP. ID  "); 			textcolor(RED); gotoxy(10,5); cprintf("I"); textcolor(BLACK);  //10
	gotoxy(15,5); cprintf("        NAME         ");	        textcolor(RED); gotoxy(23,5); cprintf("N"); textcolor(BLACK); //20
	gotoxy(37,5); cprintf("  SEX   "); 			textcolor(RED); gotoxy(39,5); cprintf("S"); textcolor(BLACK); //7
	gotoxy(46,5); cprintf(" AGE  "); 			textcolor(RED); gotoxy(47,5); cprintf("A"); textcolor(BLACK); //5
	gotoxy(53,5); cprintf("         POSITION         ");	textcolor(RED); gotoxy(62,5); cprintf("P"); textcolor(BLACK); //25

	textbackground(BLACK);
	for(i=0;i<17;i++){
		gotoxy(3,6+i);
		cprintf("%11c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(15,6+i);
		cprintf("%21c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(37,6+i);
		cprintf("%8c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(46,6+i);
		cprintf("%6c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(53,6+i);
		cprintf("%26c",' ');
	}


	textbackground(YELLOW); textcolor(BLUE);
	gotoxy(3,23); cprintf("SORT INFORMATION: [i]=ID,  [n]=FIRST NAME,  [s]=SEX,  [a]=AGE,  [p]=POSITION");
	textbackground(BLUE); textcolor(YELLOW);
	gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");

}


void inputsalegraphic(char label[90]){
	int i;
	textcolor(BLACK); textbackground(WHITE);
	gotoxy(3,5);
	cprintf("                            EMPLOYEE INFORMATION                            ");
	for(i=0;i<3;i++){
	textcolor(BLACK); textbackground(BLACK);
	gotoxy(3,6+i);
	cprintf("%76c",' ');
	}

	textcolor(BLACK); textbackground(WHITE);
	gotoxy(3,10);
	cprintf("                            COMPUTER INFOMATION                             ");
	for(i=0;i<3;i++){
	textcolor(BLACK); textbackground(BLACK);
	gotoxy(3,11+i);
	cprintf("%76c",' ');
	}

	textcolor(BLACK); textbackground(WHITE);
	gotoxy(3,15);
	cprintf("                             MORE INFORMATION                               ");
	for(i=0;i<8;i++){
	textcolor(BLACK); textbackground(BLACK);
	gotoxy(3,16+i);
	cprintf("%76c",' ');
	}

	textbackground(BLUE); textcolor(YELLOW); gotoxy(3,3); cprintf("%s",label);

	textcolor(YELLOW); textbackground(BLACK); gotoxy(5,12); cprintf("COMPUTER ID");
			textbackground(3); gotoxy(17,12); cprintf("%34c",' ');

	textcolor(YELLOW); textbackground(BLACK); gotoxy(5,7); cprintf("EMPLOYEE ID");
			  textbackground(3); gotoxy(17,7); cprintf("%34c",' ');

	textcolor(YELLOW); textbackground(BLACK); gotoxy(5,17); cprintf("SALE ID");
			   textbackground(3); gotoxy(13,17); cprintf("                         ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(42,17); cprintf("CUSTOMER NAME");
			   textbackground(3); gotoxy(51,17); cprintf("                          ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(5,19); cprintf("DATE");
			   textbackground(3); gotoxy(13,19); cprintf("                         ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(42,19); cprintf("SEX");
			   textbackground(3); gotoxy(51,19); cprintf("                          ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(5,21); cprintf("QUANTITY");
			   textbackground(3); gotoxy(13,21); cprintf("                         ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(42,21); cprintf("PHONE");
			   textbackground(3); gotoxy(51,21); cprintf("                          ");
	textcolor(YELLOW); textbackground(BLACK); gotoxy(30,23); cprintf("TOTAL");
			   textbackground(3); gotoxy(36,23); cprintf("                 ");
}

void outputsalegraphic(){
	int i;
	textbackground(WHITE); textcolor(BLUE);
	gotoxy(3,3); cprintf("                           SALE LESS INFORMATION                            ");

	textbackground(LIGHTGREEN); textcolor(BLACK);
	gotoxy(3,5); cprintf("  SALE ID  ");  		textcolor(RED); gotoxy(5,5); cprintf("S"); textcolor(BLACK);//10
	gotoxy(15,5); cprintf("COMPUTER ID ");		textcolor(RED); gotoxy(15,5); cprintf("C"); textcolor(BLACK);  //10
	gotoxy(28,5); cprintf(" CUSTOMERS NAME ");	textcolor(RED); gotoxy(39,5); cprintf("N"); textcolor(BLACK);  //15
	gotoxy(45,5); cprintf(" QUANTITY  "); 		textcolor(RED); gotoxy(46,5); cprintf("Q"); textcolor(BLACK); //10
	gotoxy(57,5); cprintf("UNIT PRICE "); 		textcolor(RED); gotoxy(57,5); cprintf("U"); textcolor(BLACK);//10
	gotoxy(69,5); cprintf("  TOTAL   "); 		textcolor(RED); gotoxy(71,5); cprintf("T"); textcolor(BLACK);//10

	textbackground(BLACK);
	for(i=0;i<17;i++){
		gotoxy(3,6+i);
		cprintf("%11c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(15,6+i);
		cprintf("%12c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(28,6+i);
		cprintf("%16c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(45,6+i);
		cprintf("%11c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(57,6+i);
		cprintf("%11c",' ');
	}

	for(i=0;i<17;i++){
		gotoxy(69,6+i);
		cprintf("%10c",' ');
	}

	textbackground(YELLOW); textcolor(BLUE);
	gotoxy(3,23); cprintf("SORT : [s]=SID,  [c]=CID,  [n]=C NAME,  [q]=QTY,  [u]=UNIT PRICE,  [t]=TOTAL");
	textbackground(BLUE); textcolor(YELLOW);
	gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");
}


void editcomputerinfo(){

	int i;

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<7+2;i++){
		gotoxy(10+1,8+1+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÝ");
	}

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(10,8);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	for(i=0;i<7;i++){
	gotoxy(10,8+1+i);
	cprintf("บ                                                         บ");
	}
	gotoxy(10,8+1+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

	textcolor(YELLOW); textbackground(GREEN);
	gotoxy(11,9);
	cprintf("        Please press the following letter to edit        ");

	textcolor(BLUE); textbackground(WHITE);
	gotoxy(11,11);
	cprintf("[A] Edit Brand      [E] Edit HDD        [I] Edit color");
	gotoxy(11,12);
	cprintf("[B] Edit Model      [F] Edit Screen     [J] Edit Date");
	gotoxy(11,13);
	cprintf("[C] Edit Type       [G] Edit CPU        [K] Edit Quantity");
	gotoxy(11,14);
	cprintf("[D] Edit RAM        [H] Edit Weight     [L] Edit Price");
	gotoxy(11,15);
	cprintf("                    [M] Back");


}

void editemployeeinfo(){

	int i;

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<6+2;i++){
		gotoxy(10+1,8+1+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÝ");
	}

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(10,8);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	for(i=0;i<6;i++){
	gotoxy(10,8+1+i);
	cprintf("บ                                                         บ");
	}
	gotoxy(10,8+1+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

	textcolor(YELLOW); textbackground(GREEN);
	gotoxy(11,9);
	cprintf("        Please press the following letter to edit        ");

	textcolor(BLUE); textbackground(WHITE);
	gotoxy(11,11);
	cprintf("[A] Edit First Name [E] Edit Position   [I] Edit Khan");
	gotoxy(11,12);
	cprintf("[B] Edit Last Name  [F] Edit Phone      [J] Edit Sangkat");
	gotoxy(11,13);
	cprintf("[C] Edit Sex        [G] Edit Salary     [K] Edit City");
	gotoxy(11,14);
	cprintf("[D] Edit Age        [H] Edit Date       [l] Back");


}


void searchbox(){
	int i;

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<1+2;i++){
		gotoxy(10+1,11+1+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÝ");
	}

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(10,11);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	for(i=0;i<1;i++){
	gotoxy(10,11+1+i);
	cprintf("บ                                                         บ");
	}
	gotoxy(10,11+1+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
}


void editsaleinfo(){

	int i;

	textbackground(BLUE); textcolor(BLACK);
	for(i=0;i<5+2;i++){
		gotoxy(10+1,8+1+i);
		cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÝ");
	}

	textbackground(WHITE);
	textcolor(BLACK);
	gotoxy(10,8);
	cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	for(i=0;i<5;i++){
	gotoxy(10,8+1+i);
	cprintf("บ                                                         บ");
	}
	gotoxy(10,8+1+i);
	cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

	textcolor(YELLOW); textbackground(GREEN);
	gotoxy(11,9);
	cprintf("        Please press the following letter to edit        ");

	textcolor(BLUE); textbackground(WHITE);
	gotoxy(11,11);
	cprintf("[A] Employee ID     [D] Quantity        [G] Phone number");
	gotoxy(11,12);
	cprintf("[B] Computer ID     [E] Customer name   [H] Back");
	gotoxy(11,13);
	cprintf("[C] Date            [F] Sex ");

}
