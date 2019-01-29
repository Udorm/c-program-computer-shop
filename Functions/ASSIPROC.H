#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

struct employee{
	char id[10];
	struct{
		char first[10];
		char last[10];
	}name;
	char position[25];
	char sex[7];
	int age;
	char phone[20];
	long salary;
	char date[15];
	struct{
		char commune[20];
		char district[20];
		char province[20];
	}address;
};
struct employee inputem,outputem;//sort[200],sorttemp;
long m1=sizeof(struct employee);//;


void inputemp(){

	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
       //	int count=0,find,n,i,j,a;

	clrscr();
	do{
		textbackground(BLUE);
		clrscr();
		frame();
		inputemgraphic("PLEASE INPUT EMPLOYEE INFORMATION");
		textcolor(BLACK);
		_setcursortype(_SOLIDCURSOR);

	    q1:	textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("INPUT [exit] TO FINISH");
		gotoxy(38,7); inputmix(inputem.id,9);
			if(strcmp(strlwr(inputem.id),"exit")==0) break;
			fp=fopen("employee.txt","rb");
			while(fread(&outputem,m1,1,fp)==1)
			if(strcmp(strlwr(outputem.id),strlwr(inputem.id))==0){
			textbackground(BLUE);
			gotoxy(38,7); cprintf("[ EXIST ]");
			delay(900); gotoxy(38,7); cprintf("         ");
			goto q1;
			}
			fclose(fp); gotoxy(2,25);
			textbackground(BLUE); clreol();
		gotoxy(14,12); inputmix(inputem.name.first,9);
		gotoxy(14,14); inputmix(inputem.name.last,9);
	   q11:	textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[INPUT exit TO FINISH]                              [SEX MUST male OR female]");
		gotoxy(14,16); inputmix(inputem.sex,6);
			if(strcmp(strlwr(inputem.sex),"exit")==0) break;
			if(strcmp(strlwr(inputem.sex),"male")==0 || strcmp(strlwr(inputem.sex),"female")==0){
			}else{
			textbackground(GREEN);
			gotoxy(14,16); cprintf("[male/female]");
			delay(900); gotoxy(14,16); cprintf("                 ");
			goto q11;
			}
			gotoxy(2,25);
			textbackground(BLUE); clreol();
	    q2:	textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[AGE MUST BE BETWEEN 18 AND 59 YEARS OLD]                [INPUT 100 TO FINISH]");
		gotoxy(14,18); textbackground(GREEN); cprintf("   ");
		gotoxy(14,18); inputnum(age,3);
			inputem.age=atoi(age);
			if(inputem.age==100) break;
			if(inputem.age<18 || inputem.age>=60){
				if(inputem.age<18){
				textcolor(YELLOW); textbackground(BLUE);
				gotoxy(2,25); clreol(); cprintf("AGE IS UNDER 18 YEARS OLD");
				delay(900); gotoxy(2,25); clreol();
				gotoxy(72,12); textbackground(GREEN); cprintf("    "); goto q2;
				}
				if(inputem.age>=60){
				textcolor(YELLOW); textbackground(BLUE);
				gotoxy(2,25); clreol(); cprintf("AGE IS OVER 59 YEARS OLD");
				delay(900); gotoxy(2,25); clreol();
				gotoxy(72,12); textbackground(GREEN); cprintf("    "); goto q2;
				}
			}
			gotoxy(2,25); textbackground(BLUE); clreol();
		gotoxy(14,20); inputmix(inputem.position,20);
		gotoxy(14,22); inputnum(inputem.phone,20);
		gotoxy(58,12); inputnum(salary,6);
			inputem.salary=atol(salary);
		gotoxy(58,14); inputmix(inputem.date,15);
		gotoxy(58,17); inputmix(inputem.address.commune,20);
		gotoxy(58,19); inputmix(inputem.address.district,20);
		gotoxy(58,21); inputmix(inputem.address.province,20);

		fp=fopen("employee.txt","ab");
		fwrite(&inputem,m1,1,fp);
		fclose(fp);

		_setcursortype(_NOCURSOR);
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("PRESS [ENTER] TO CONTINUE AND [ESC] TO FINISH INPUTING");

		dd:
		ch=getch();
		if(ch!=13 && ch!=27) goto dd;

	}while(ch==13);
	_setcursortype(_NOCURSOR);
}

void outputemless(){
	struct employee sort[200],sorttemp;
	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
	int count=0,find,n,i,j,a;

	show:
	fp=fopen("employee.txt","r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/m1; i=0;

	if(n<17){
		textbackground(BLUE);
		frame();
		outputemgraphic();
		rewind(fp);
		while(fread(&outputem,m1,1,fp)==1){
			textcolor(WHITE); textbackground(BLACK);
			gotoxy(4,6+i); cprintf("%s",outputem.id);
			gotoxy(16,6+i); cprintf("%s",outputem.name.first); gotoxy(26,6+i); cprintf("%s",outputem.name.last);
			gotoxy(38,6+i); cprintf("%s",outputem.sex);
			gotoxy(47,6+i); cprintf("%d",outputem.age);
			gotoxy(54,6+i); cprintf("%s",outputem.position);
			i++;
		}
		tt1:
		ch=getch();
		switch(ch){
		case 'i':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort[i].id,sort[j].id)>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 'n':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort[i].name.first),strlwr(sort[j].name.first))>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 'a':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort[i].age>sort[j].age){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 's':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort[i].sex,sort[j].sex)>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
			//break;
		case 'p':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort[i].position),strlwr(sort[j].position))>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		}
		if(ch!=27) goto tt1;
	}else{
		i=0;
		do{
		a=0;
		textbackground(BLUE);
		clrscr();
		frame();
		outputemgraphic();
		fseek(fp,i*m1,SEEK_SET);
		for(j=i;j<i+17;j++){
			fread(&outputem,m1,1,fp);
			textcolor(WHITE); textbackground(BLACK);
			gotoxy(4,6+a); cprintf("%s",outputem.id);
			gotoxy(16,6+a); cprintf("%s",outputem.name.first);  gotoxy(26,6+a); cprintf("%s",outputem.name.last);
			gotoxy(38,6+a); cprintf("%s",outputem.sex);
			gotoxy(47,6+a); cprintf("%d",outputem.age);
			gotoxy(54,6+a); cprintf("%s",outputem.position);
			a++;
		}
		ch=getch();
		switch(ch){
		case 'i':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort[i].id,sort[j].id)>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 'n':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort[i].name.first),strlwr(sort[j].name.first))>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 'a':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort[i].age>sort[j].age){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		case 's':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort[i].sex,sort[j].sex)>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
			//break;
		case 'p':
			count=0;
			fclose(fp);
			fp1=fopen("employee.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort[count],m1,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort[i].position),strlwr(sort[j].position))>0){
				sorttemp=sort[i];
				sort[i]=sort[j];
				sort[j]=sorttemp;
			}

			for(i=0;i<count;i++)
			fwrite(&sort[i],m1,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("employee.txt");
			rename("temp.txt","employee.txt");
			goto show;
		}
		if(ch==72) if(i>0) i--;
		if(ch==80) if(i+17<n) i++;
		}while(ch!=27);
	}
	fclose(fp);
}



void outputemmore(){

	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
	int find,n,i,j,a;

	fp=fopen("employee.txt","r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/m1; i=0;

	ch=80;
	rewind(fp);
	do{
		if(ch==80)if(i<n){
			i++;
			fread(&outputem,m1,1,fp);
		}
		if(ch==72)if(i>1){
			i--;
			fseek(fp,-2*m1,SEEK_CUR);
			fread(&outputem,m1,1,fp);
		}

		textbackground(BLUE);
		clrscr();
		frame();
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");
		inputemgraphic("EMPLOYEE INFORMATON WITH DETAIL");

		textbackground(BLUE); textcolor(WHITE);
		gotoxy(39,7); cprintf("%s",outputem.id);
		textbackground(GREEN);
		gotoxy(14,12); cprintf("%s",outputem.name.first);
		gotoxy(14,14); cprintf("%s",outputem.name.last);
		gotoxy(14,16); cprintf("%s",outputem.sex);
		gotoxy(14,18); cprintf("%d",outputem.age);
		gotoxy(14,20); cprintf("%s",outputem.position);
		gotoxy(14,22); cprintf("%s",outputem.phone);
		gotoxy(58,12); cprintf("$%ld",outputem.salary);
		gotoxy(58,14); cprintf("%s",outputem.date);
		gotoxy(58,17); cprintf("%s",outputem.address.commune);
		gotoxy(58,19); cprintf("%s",outputem.address.district);
		gotoxy(58,21); cprintf("%s",outputem.address.province);
		ch=getch();
	}while(ch!=27);
	fclose(fp);
}


void searchemid(){
	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
	int find,n,i,j,a;

	again:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT EMPLOYEE ID TO SEARCH");
	gotoxy(46,12); textbackground(BLUE); cprintf("%22c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(46,12); inputmix(x,10); _setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("employee.txt","r+b");
	rewind(fp);
	while(fread(&outputem,m1,1,fp)==1)
	if(strcmp(strlwr(outputem.id),strlwr(x))==0){
		find=1;
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("PRESS [ESC] TO FINISH SHOWING");
		inputemgraphic("ID SEARCH RESULT");

		textbackground(BLUE); textcolor(WHITE);
		gotoxy(39,7); cprintf("%s",outputem.id);
		textbackground(GREEN);
		gotoxy(14,12); cprintf("%s",outputem.name.first);
		gotoxy(14,14); cprintf("%s",outputem.name.last);
		gotoxy(14,16); cprintf("%s",outputem.sex);
		gotoxy(14,18); cprintf("%d",outputem.age);
		gotoxy(14,20); cprintf("%s",outputem.position);
		gotoxy(14,22); cprintf("%s",outputem.phone);
		gotoxy(58,12); cprintf("$%ld",outputem.salary);
		gotoxy(58,14); cprintf("%s",outputem.date);
		gotoxy(58,17); cprintf("%s",outputem.address.commune);
		gotoxy(58,19); cprintf("%s",outputem.address.district);
		gotoxy(58,21); cprintf("%s",outputem.address.province);
		ch=getch();
		}while(ch!=27);
	}
	if(find==0){
		do{
		textbackground(BLUE);
		frame();
		message("YOUR ID SEARCHING","NO RESULT");
		gotoxy(2,25); textcolor(YELLOW); cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again;
		}while(ch!=27);
	}
	fclose(fp);
}


void deleteem(){
	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
	int find,n,i,j,a;

	again1:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT EMPLOYEE ID TO DELETE");
	gotoxy(46,12); textbackground(BLUE); cprintf("%22c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(46,12); inputmix(x,10); _setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("employee.txt","rb");
	fp1=fopen("temp.txt","wb");
	while(fread(&outputem,m1,1,fp)==1){
		if(strcmp(strlwr(outputem.id),strlwr(x))==0){
			if(find==0){
			message("ARE YOU SURE WANT TO DELETE","");
			yesno(&ask);
				if(ask=='n' || ask=='N') goto bbbb;
			}
			find=1;
		}else{
			bbbb:
			fwrite(&outputem,m1,1,fp1);
		}
	}
	fclose(fp); fclose(fp1);
	remove("employee.txt");
	rename("temp.txt","employee.txt");

	if(find==0){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR DELETING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again1;
		}while(ch!=27);
	}
	if(find==1){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR DELETING","COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK");
		ch=getch();
		}while(ch!=27);
	}
}

void editem(){

	FILE *fp,*fp1,*fp2,*fp3;
	char salary[20],age[5],ch,x[20],st,ask,bb[10];
	int find,n,i,j,a;

	again2:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT EMPLOYEE ID TO EDIT");
	gotoxy(46,12); textbackground(BLUE); cprintf("%22c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(46,12); gets(x); _setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("employee.txt","rb");
	fp1=fopen("temp.txt","wb");
	while(fread(&outputem,m1,1,fp)==1){
		if(strcmp(strlwr(outputem.id),strlwr(x))==0){
			do{
			_setcursortype(_NOCURSOR);
			textbackground(BLUE);
			clrscr();
			frame();
			editemployeeinfo();
			st=getch();

			clrscr();
			frame();
			inputemgraphic("PLEASE INPUT THE FOLLOWING INFORMATION OF EMPLOYEE");
			textbackground(BLUE); textcolor(WHITE);
			gotoxy(39,7); cprintf("%s",outputem.id);
			textbackground(GREEN);
			gotoxy(14,12); cprintf("%s",outputem.name.first);
			gotoxy(14,14); cprintf("%s",outputem.name.last);
			gotoxy(14,16); cprintf("%s",outputem.sex);
			gotoxy(14,18); cprintf("%d",outputem.age);
			gotoxy(14,20); cprintf("%s",outputem.position);
			gotoxy(14,22); cprintf("%s",outputem.phone);
			gotoxy(58,12); cprintf("$%ld",outputem.salary);
			gotoxy(58,14); cprintf("%s",outputem.date);
			gotoxy(58,17); cprintf("%s",outputem.address.commune);
			gotoxy(58,19); cprintf("%s",outputem.address.district);
			gotoxy(58,21); cprintf("%s",outputem.address.province);

			_setcursortype(_SOLIDCURSOR);
			switch(st){
			case 'a':
				find=1;
				gotoxy(14,12); cprintf("         ");
				gotoxy(14,12); inputmix(outputem.name.first,9);
				break;
			case 'b':
				find=1;
				gotoxy(14,14); cprintf("        ");
				gotoxy(14,14); inputmix(outputem.name.last,9);
				break;
			case 'c':
				find=1;
				gotoxy(14,16); cprintf("      ");
			   q14:	textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[INPUT exit TO FINISH]                              [SEX MUST male OR female]");
				gotoxy(14,16); inputmix(bb,6);
					if(strcmp(strlwr(bb),"exit")==0) break;
					if(strcmp(strlwr(bb),"male")==0 || strcmp(strlwr(bb),"female")==0){
						strcpy(inputem.sex,bb);
					}else{
						textbackground(GREEN);
						gotoxy(14,16); cprintf("[male/female]");
						delay(900); gotoxy(14,16); cprintf("                 ");
						goto q14;
					}
					gotoxy(2,25);
					textbackground(BLUE); clreol();
				break;
			case 'd':
				find=1;
				gotoxy(14,18); cprintf("   ");
			   q2:	textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[AGE MUST BE BETWEEN 18 AND 59 YEARS OLD]               [INPUT 100 TO FINISH]");
				gotoxy(14,18); inputnum(age,3);
					outputem.age=atoi(age);
					if(outputem.age==100) break;
					if(outputem.age<18 || outputem.age>=60){
						if(outputem.age<18){
						textcolor(YELLOW); textbackground(BLUE);
						gotoxy(2,25); clreol(); cprintf("AGE IS UNDER 18 YEARS OLD");
						delay(900); gotoxy(2,25); clreol();
						gotoxy(72,12); textbackground(GREEN); cprintf("    "); goto q2;
						}
						if(outputem.age>=60){
						textcolor(YELLOW); textbackground(BLUE);
						gotoxy(2,25); clreol(); cprintf("AGE IS OVER 59 YEARS OLD");
						delay(900); gotoxy(2,25); clreol();
						gotoxy(72,12); textbackground(GREEN); cprintf("    "); goto q2;
					}
					}
					gotoxy(2,25); textbackground(BLUE); clreol();
				break;
			case 'e':
				find=1;
				gotoxy(14,20); cprintf("                   ");
				gotoxy(14,20); inputmix(outputem.position,20);
				break;
			case 'f':
				find=1;
				gotoxy(14,22); cprintf("            ");
				gotoxy(14,22); inputnum(outputem.phone,15);
				break;
			case 'g':
				find=1;
				gotoxy(58,12); cprintf("      ");
				gotoxy(58,12); inputnum(salary,6);
				outputem.salary=atol(salary);
				break;
			case 'h':
				find=1;
				gotoxy(58,14); cprintf("               ");
				gotoxy(58,14); inputmix(outputem.date,15);
				break;
			case 'i':
				find=1;
				gotoxy(58,17); cprintf("                  ");
				gotoxy(58,17); inputmix(outputem.address.commune,20);
				break;
			case 'j':
				find=1;
				gotoxy(58,19); cprintf("                  ");
				gotoxy(58,19); inputmix(outputem.address.district,20);
				break;
			case 'k':
				find=1;
				gotoxy(58,21); cprintf("                  ");
				gotoxy(58,21); inputmix(outputem.address.province,20);
				break;
			}
			}while(st!='l'&&st!=27);
			fwrite(&outputem,m1,1,fp1);
		}else{
			fwrite(&outputem,m1,1,fp1);
		}
	}
	fclose(fp); fclose(fp1);
	remove("employee.txt");
	rename("temp.txt","employee.txt");

	_setcursortype(_NOCURSOR);
	if(find==0){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR EDITING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGIAN");
		ch=getch();
		if(ch==13) goto again2;;
		}while(ch!=27);
	}
	if(find==1){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR EDITING","COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK");
		ch=getch();
		}while(ch!=27);
	}
}


void login(){
	int i,j=0;
	char user[20],pass[20],ch;
	textbackground(BLACK);
	clrscr();
	_setcursortype(_NOCURSOR);

	textbackground(WHITE);
	for(i=0;i<5;i++){
	gotoxy(20,11+i);  cprintf("                                          ");
	}

	textbackground(BLUE); textcolor(WHITE);
	gotoxy(20,10); cprintf("     PLEASE LOG IN TO USE THE PROGRAM     ");

	a:         _setcursortype(_SOLIDCURSOR);
	textbackground(0);
	gotoxy(33,12); cprintf("                          ");
	gotoxy(33,14); cprintf("                          ");

	textbackground(WHITE); textcolor(BLACK);
	gotoxy(24,12); cprintf("USERNAME ");
	gotoxy(24,14); cprintf("PASSWORD ");

	gotoxy(33,12); inputmix(user,26);
	gotoxy(33,14); inputpass(pass,26);

	_setcursortype(_NOCURSOR);
	if(strcmp(user,"computer shop")==0 && strcmp(pass,"123456")==0){

	}else{
		j++;
		for(i=0;i<4;i++){
		textbackground(BLACK);    textcolor(WHITE);
		gotoxy(33,12); cprintf("                          "); gotoxy(33,12); cprintf("%s",user);
		gotoxy(33,14); cprintf("                          "); //gotoxy(33,14); cprintf("%s",pass);
		delay(100);
		textbackground(RED);    textcolor(WHITE);
		gotoxy(33,12); cprintf("                          "); gotoxy(33,12); cprintf("%s",user);
		gotoxy(33,14); cprintf("                          "); //gotoxy(33,14); cprintf("%s",pass);
		delay(100);
		}

		textcolor(RED); textbackground(YELLOW);
		gotoxy(26,17); cprintf("USERNAME OR PASSWORD INCORRECT");

		if(j>=5){
			message("YOU ARE WRONG 5 TIMES","SO YOU CAN NOT CONTINUE");
			getch();
			exit(1);
		}

		i=0;  textcolor(WHITE);
		do{
			textcolor(WHITE); textbackground(GREEN);
			gotoxy(35,19+i); cprintf("         ");

			gotoxy(35,19); printf("TRY AGAIN");
			gotoxy(35,20); printf("  EXIT!  ");

			ch=getch();
			textbackground(BLACK);
			gotoxy(35,19+i); cprintf("         ");

			if(ch==80) i++; if(i>1) i=0;
			if(ch==72) i--; if(i<0) i=1;
		}while(ch!=13);
		if(i==0){
			textcolor(WHITE);
			gotoxy(26,17); cprintf("                              ");
			gotoxy(26,19); cprintf("                              ");
			gotoxy(26,20); cprintf("                              ");
			goto a;
		}
		if(i==1) exit(1);
	}
	textbackground(BLACK);
}

