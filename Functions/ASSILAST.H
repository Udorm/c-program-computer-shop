#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
//int i;

void helppro(){
	int i; char ch;
	textbackground(BLUE);
	//clrscr();

	for(i=1;i<=25;i++){
	gotoxy(18,i); clreol();
	}

	textcolor(15); textbackground(0);
	gotoxy(19,2);  cprintf("浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	gotoxy(19,3);  cprintf("�                                                           �");
	gotoxy(19,4);  cprintf("麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	for(i=0;i<19;i++){
	gotoxy(19,5+i);cprintf("�                                                           �");
	}
	gotoxy(19,23); cprintf("藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");

	textcolor(LIGHTRED); textbackground(0);
	gotoxy(39,3); cprintf("<<< PRODUCT HELP >>>");

	textcolor(YELLOW);
	gotoxy(20,5); cprintf("� INPUT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,6); cprintf("  This function allows you to store new computers that you");
	gotoxy(20,7); cprintf("  import to your shop. You must completes all information.");

	textcolor(YELLOW);
	gotoxy(20,8); cprintf("� SHOW INFORMATION");
	textcolor(LIGHTGREEN);
	gotoxy(20,9); cprintf("     >>SHOW AS LIST");
	gotoxy(20,12);cprintf("     >>SHOW WITH DETAIL");
	textcolor(WHITE);
	gotoxy(20,10);cprintf("       This function allows you to show all data in a list");
	gotoxy(20,11);cprintf("       form that you can only see some infomation of a PC.");
	gotoxy(20,13);cprintf("       This function allows you to show all data in full");
	gotoxy(20,14);cprintf("       information of each product.  (You can scroll)");

	textcolor(YELLOW);
	gotoxy(20,15); cprintf("� SEARCH INFORMATION");
	textcolor(WHITE);
	gotoxy(20,16); cprintf("  This function allows you to search the specfic computer");
	gotoxy(20,17); cprintf("  that you want to see its information. Just know its ID.");

	textcolor(YELLOW);
	gotoxy(20,18); cprintf("� EDIT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,19); cprintf("  This function allows you to edit every information. You");
	gotoxy(20,20); cprintf("  just type computer ID and follow the instructions.");

	textcolor(YELLOW);
	gotoxy(20,21); cprintf("� DELETE INFORMATION");
	textcolor(WHITE);
	gotoxy(20,22); cprintf("  Allows you to delete data that you do not need it anymore");
  //  /*
	textcolor(YELLOW);textbackground(BLUE);
	gotoxy(19,24); cprintf("PRESS [ESC] TO BACK");
	textbackground(BLACK);
	gotoxy(19,25); cprintf("様様様様様様様様様�");
  //  */
     /*
	textcolor(BLACK); textbackground(RED);
	gotoxy(39,24); cprintf("ESC");

     */

	aa:ch=getch();
	while(ch!=27) goto aa;
}


void helpemp(){
	int i; char ch;
	textbackground(BLUE);
	//clrscr();

	for(i=1;i<=25;i++){
	gotoxy(18,i); clreol();
	}

	textcolor(15); textbackground(0);
	gotoxy(19,2);  cprintf("浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	gotoxy(19,3);  cprintf("�                                                           �");
	gotoxy(19,4);  cprintf("麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	for(i=0;i<19;i++){
	gotoxy(19,5+i);cprintf("�                                                           �");
	}
	gotoxy(19,23); cprintf("藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");

	textcolor(LIGHTRED); textbackground(0);
	gotoxy(39,3); cprintf("<<< EMPLOYEE HELP >>>");

	textcolor(YELLOW);
	gotoxy(20,5); cprintf("� INPUT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,6); cprintf("  This function allows you to keep each employee data. You");
	gotoxy(20,7); cprintf("  need to complete all the employees information.");

	textcolor(YELLOW);
	gotoxy(20,8); cprintf("� SHOW INFORMATION");
	textcolor(LIGHTGREEN);
	gotoxy(20,9); cprintf("     >>SHOW AS LIST");
	gotoxy(20,12);cprintf("     >>SHOW WITH DETAIL");
	textcolor(WHITE);
	gotoxy(20,10);cprintf("       This function allows you to show all data in a list");
	gotoxy(20,11);cprintf("       form that you can only see only a few information.");
	gotoxy(20,13);cprintf("       This function allows you to show all data in full");
	gotoxy(20,14);cprintf("       information of each employee who is working in shop.");

	textcolor(YELLOW);
	gotoxy(20,15); cprintf("� SEARCH INFORMATION");
	textcolor(WHITE);
	gotoxy(20,16); cprintf("  This function allows you to search the specfic employee");
	gotoxy(20,17); cprintf("  that you want to see detail information. (Need ID)");

	textcolor(YELLOW);
	gotoxy(20,18); cprintf("� EDIT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,19); cprintf("  This function allows you to edit every information. You");
	gotoxy(20,20); cprintf("  just type employee ID and follow the instructions.");

	textcolor(YELLOW);
	gotoxy(20,21); cprintf("� DELETE INFORMATION");
	textcolor(WHITE);
	gotoxy(20,22); cprintf("  Allows you to delete data that you do not need it anymore");

	textcolor(YELLOW); textbackground(BLUE);
	gotoxy(19,24); cprintf("PRESS [ESC] TO BACK");
	textbackground(BLACK);
	gotoxy(19,25); cprintf("様様様様様様様様様�");

	aa:ch=getch();
	while(ch!=27) goto aa;
}

void helpsale(){
	int i; char ch;
	textbackground(BLUE);
	//clrscr();

	for(i=1;i<=25;i++){
	gotoxy(18,i); clreol();
	}

	textcolor(15); textbackground(0);
	gotoxy(19,2);  cprintf("浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	gotoxy(19,3);  cprintf("�                                                           �");
	gotoxy(19,4);  cprintf("麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");
	for(i=0;i<19;i++){
	gotoxy(19,5+i);cprintf("�                                                           �");
	}
	gotoxy(19,23); cprintf("藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�");

	textcolor(LIGHTRED); textbackground(0);
	gotoxy(37,3); cprintf("<<< SALE & ORDER HELP >>>");

	textcolor(YELLOW);
	gotoxy(20,5); cprintf("� INPUT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,6); cprintf("  This function allows you to sale computers. You will need");
	gotoxy(20,7); cprintf("  to choose an employee to sale the products.");

	textcolor(YELLOW);
	gotoxy(20,8); cprintf("� SHOW INFORMATION");
	textcolor(LIGHTGREEN);
	gotoxy(20,9); cprintf("     >>SHOW AS LIST");
	gotoxy(20,12);cprintf("     >>SHOW WITH DETAIL");
	textcolor(WHITE);
	gotoxy(20,10);cprintf("       This function allows you to show all data in a list");
	gotoxy(20,11);cprintf("       form that you can only see some infomation of saling");
	gotoxy(20,13);cprintf("       This function allows you to show all data in full");
	gotoxy(20,14);cprintf("       information of each saling and ordering.");

	textcolor(YELLOW);
	gotoxy(20,15); cprintf("� SEARCH INFORMATION");
	textcolor(WHITE);
	gotoxy(20,16); cprintf("  This function allows you to search the specfic saling");
	gotoxy(20,17); cprintf("  that you want to see its information. Just know its ID.");

	textcolor(YELLOW);
	gotoxy(20,18); cprintf("� EDIT INFORMATION");
	textcolor(WHITE);
	gotoxy(20,19); cprintf("  This function allows you to edit every information. When");
	gotoxy(20,20); cprintf("  When you edit, your PC info will update automatically.");

	textcolor(YELLOW);
	gotoxy(20,21); cprintf("� DELETE INFORMATION");
	textcolor(WHITE);
	gotoxy(20,22); cprintf("  Allows you to delete data that you do not need if anymore");

	textcolor(YELLOW); textbackground(BLUE);
	gotoxy(19,24); cprintf("PRESS [ESC] TO BACK");
	textbackground(BLACK);
	gotoxy(19,25); cprintf("様様様様様様様様様�");

	aa:ch=getch();
	while(ch!=27) goto aa;
}


void lock(){
	int i;
	textbackground(BLUE);
	clrscr();
      //	int i;
     /*	for(i=0;i<24;i++){
	for(j=0;j<80;j++){
		textcolor(BLUE); textbackground(BLUE);
		gotoxy(1+j,1+i); cprintf(" ");
	}delay(20); }
	textcolor(WHITE); textbackground(BLACK);
	gotoxy(1,5);
	cprintf(" 栩栩 栩栩栩 栩� 栩� 栩栩� 栩  栩 栩栩栩 栩栩 栩栩栩    栩栩 栩 栩 栩栩栩 栩栩�\n");
	gotoxy(1,6);
	cprintf(" 栩   栩  栩 栩 � 栩 栩  � 栩  栩   栩   栩   栩  栩    栩   栩 栩 栩  栩 栩  �\n");
	gotoxy(1,7);
	cprintf(" 栩   栩  栩 栩   栩 栩栩� 栩  栩   栩   栩�  栩栩�     栩栩 栩栩� 栩  栩 栩栩�\n");
	gotoxy(1,8);
	cprintf(" 栩   栩  栩 栩   栩 栩    栩  栩   栩   栩   栩  栩      栩 栩 栩 栩  栩 栩   \n");
	gotoxy(1,9);
	cprintf(" 栩栩 栩栩栩 栩   栩 栩    栩栩栩   栩   栩栩 栩  栩    栩栩 栩 栩 栩栩栩 栩   \n");
	*/

	textcolor(YELLOW); textbackground(BLUE);
	gotoxy(1,10);
	cprintf("                 栩       栩栩    栩栩�  栩   栩   栩栩�  栩栩栩");
	gotoxy(1,11);
	cprintf("                 栩      栩  栩  栩      栩  栩   栩       �   栩");
	gotoxy(1,12);
	cprintf("                 栩      栩  栩  栩      栩栩     栩栩     �   栩");
	gotoxy(1,13);
	cprintf("                 栩      栩  栩  栩      栩  栩   栩       �   栩");
	gotoxy(1,14);
	cprintf("                  栩栩�   栩栩    栩栩�  栩   栩   栩栩�  栩栩栩");

	getch();

	for(i=0;i<24;i++){
		textbackground(BLACK);
		gotoxy(1,24-i); clreol();
		delay(50);
	}
}