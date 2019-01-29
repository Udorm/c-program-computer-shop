#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>

struct computer{
	char id[9];
	char brand[12];
	char model[17];
	char type[17];
	char ram[10];
	char hdd[10];
	char screen[20];
	char cpu[20];
	char weight[10];
	char color[20];
	char date[20];
	long qty;
	float price;
};
struct computer input,output,output1,output2;


FILE *fp,*fp1,*fp2,*fp3;
long m=sizeof(struct computer),n,i,j,a;
char qty[20],price[20],ch,st,x[20],ask;
int find,count;

void inputc(){
		clrscr();
		do{
			textbackground(BLUE);
			clrscr();
			frame();
			inputgraphic("              PLEASE INPUT THE FOLLOWING INFORMATION OF COMPUTER            ");
			textcolor(YELLOW);
			_setcursortype(_SOLIDCURSOR);
		    aa:
			textcolor(WHITE); textbackground(BLUE);
			gotoxy(3,25); cprintf("INPUT [exit] TO FINISH INPUTING");

			gotoxy(18,14); fflush(stdin); inputmix(input.id,8);
				if(strcmp(strlwr(input.id),"exit")==0) break;
				fp=fopen("computer.txt","rb");
				while(fread(&output,m,1,fp)==1){
					if(strcmp(strlwr(output.id),strlwr(input.id))==0){
					textbackground(BLUE);
					gotoxy(18,14);
					cprintf("[ EXIST ]");
					delay(900);
					gotoxy(18,14); cprintf("         ");
					goto aa;
					}
				}
				fclose(fp);
				gotoxy(3,25); textbackground(BLUE); clreol();

			gotoxy(17,18); inputmix(input.brand,11);
			gotoxy(12,20); inputmix(input.model,15);
			gotoxy(12,22); inputmix(input.type,8);
			gotoxy(51,6); inputmix(input.ram,10);
			gotoxy(51,8); inputmix(input.hdd,10);
			gotoxy(51,10); inputmix(input.screen,20);
			gotoxy(51,12); inputmix(input.cpu,20);
			gotoxy(51,14); inputmix(input.weight,10);
			gotoxy(51,16); inputmix(input.color,20);
			gotoxy(51,18); inputmix(input.date,20);
			gotoxy(51,20); inputnum(qty,9); input.qty=atol(qty);
			gotoxy(51,22); inputnum(price,5); input.price=atof(price);

			fp=fopen("computer.txt","ab");
			fwrite(&input,m,1,fp);
			fclose(fp);


			_setcursortype(_NOCURSOR);
			textcolor(WHITE);
			gotoxy(3,25); cprintf("PRESS [ENTER] TO CONTINE AND [ESC] TO FINISH INPUTING");

		    dd:	ch=getch();
			if(ch!=13 && ch!=27) goto dd;

		}while(ch==13);
		_setcursortype(_NOCURSOR);
}




void outputcless(){
	struct computer reab[200],gi;
	int count=0;
		again:
		fp=fopen("computer.txt","r+b");
		fseek(fp,0,SEEK_END);
		n=ftell(fp)/m; i=0;


		if(n<17){
			textbackground(BLUE);
			frame();
			outputgraphic();
			rewind(fp);
			while(fread(&output,m,1,fp)==1){
				textcolor(WHITE); textbackground(BLACK);
				gotoxy(5,6+i); cprintf("%s",output.id);
				gotoxy(16,6+i); cprintf("%s",output.brand);
				gotoxy(30,6+i); cprintf("%s",output.model);
				gotoxy(46,6+i); cprintf("%s",output.type);
				gotoxy(57,6+i); cprintf("%ld",output.qty);
				gotoxy(69,6+i); cprintf("$%.2f",output.price);
				i++;
			}
		   tt:	ch=getch();
				switch(ch){
				case 'i':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(reab[i].id,reab[j].id)>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'b':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].brand),strlwr(reab[j].brand))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'm':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].model),strlwr(reab[j].model))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 't':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].type),strlwr(reab[j].type))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'q':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(reab[i].qty>reab[j].qty){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'p':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(reab[i].price>reab[j].price){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				}
			if(ch!=27) goto tt;
		}else{
			i=0;
			do{
				a=0;
				textbackground(BLUE);
				clrscr();
				frame();
				outputgraphic();
				fseek(fp,i*m,SEEK_SET);
				for(j=i;j<i+17;j++){
					fread(&output,m,1,fp);
					textcolor(WHITE); textbackground(BLACK);
					gotoxy(5,6+a); cprintf("%s",output.id);
					gotoxy(16,6+a); cprintf("%s",output.brand);
					gotoxy(30,6+a); cprintf("%s",output.model);
					gotoxy(46,6+a); cprintf("%s",output.type);
					gotoxy(57,6+a); cprintf("%ld",output.qty);
					gotoxy(69,6+a); cprintf("$%.2f",output.price);
					a++;
				}
				ch=getch();
				switch(ch){
				case 'i':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(reab[i].id,reab[j].id)>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'b':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].brand),strlwr(reab[j].brand))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'm':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].model),strlwr(reab[j].model))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 't':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(strcmp(strlwr(reab[i].type),strlwr(reab[j].type))>0){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'q':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(reab[i].qty>reab[j].qty){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				case 'p':
					count=0;
					fclose(fp);
					fp1=fopen("computer.txt","rb");
					fp2=fopen("temp.txt","wb");
					while(fread(&reab[count],m,1,fp1)==1)
					count++;

					for(i=0;i<count;i++)
					for(j=i+1;j<count;j++)
					if(reab[i].price>reab[j].price){
						gi=reab[i];
						reab[i]=reab[j];
						reab[j]=gi;
					}

					for(i=0;i<count;i++)
					fwrite(&reab[i],m,1,fp2);
					fclose(fp1); fclose(fp2);
					remove("computer.txt");
					rename("temp.txt","computer.txt");
					goto again;
				}

				if(ch==72) if(i>0) i--;
				if(ch==80) if(i+17<n) i++;

			}while(ch!=27);
		}
		fclose(fp);
}



void outputcmore(){

	clrscr();
	fp=fopen("computer.txt","r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/m; i=0;

	i=0; ch=80;
	rewind(fp);
	do{
		if(ch==80)if(i<n){
			i++;
			fread(&output,m,1,fp);
		}
		if(ch==72)if(i>1){
			i--;
			fseek(fp,-2*m,SEEK_CUR);
			fread(&output,m,1,fp);
		}


		textbackground(BLUE);
		clrscr();
		frame();
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");
		inputgraphic("                       COMPUTER INFORMATION WITH DETAIL                     ");

		textcolor(WHITE); textbackground(BLUE);
		gotoxy(18,14); printf("%s",output.id);
		textbackground(GREEN);
		gotoxy(17,18); cprintf("%s",output.brand);
		gotoxy(12,20); cprintf("%s",output.model);
		gotoxy(12,22); cprintf("%s",output.type);
		gotoxy(51,6);  cprintf("%s",output.ram);
		gotoxy(51,8);  cprintf("%s",output.hdd);
		gotoxy(51,10); cprintf("%s",output.screen);
		gotoxy(51,12); cprintf("%s",output.cpu);
		gotoxy(51,14); cprintf("%s",output.weight);
		gotoxy(51,16); cprintf("%s",output.color);
		gotoxy(51,18); cprintf("%s",output.date);
		gotoxy(51,20); cprintf("%ld",output.qty);
		gotoxy(51,22); cprintf("$%.2f",output.price);
		ch=getch();
	}while(ch!=27);
	fclose(fp);
}



void searchcid(){
	again:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textcolor(BLACK); textbackground(WHITE);
	cprintf("PLEASE INPUT COMPUTER ID TO SEARCH");
	gotoxy(46,12); textbackground(BLUE); cprintf("%22c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(46,12); inputmix(x,7);
	_setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("computer.txt","r+b");
	rewind(fp);
	while(fread(&output,m,1,fp)==1)
	if(strcmp(strlwr(output.id),strlwr(x))==0){
		find=1;
		do{
			textbackground(BLUE);
			clrscr();
			frame();
			textbackground(BLUE); textcolor(YELLOW);
			gotoxy(2,25); cprintf("[PRESS ESC TO FINISH SHOWING]");
			inputgraphic("                              ID SEARCH RESULT                              ");

			textcolor(WHITE); textbackground(BLUE);
			gotoxy(18,14); printf("%s",output.id);
			textbackground(GREEN);
			gotoxy(17,18); cprintf("%s",output.brand);
			gotoxy(12,20); cprintf("%s",output.model);
			gotoxy(12,22); cprintf("%s",output.type);
			gotoxy(51,6);  cprintf("%s",output.ram);
			gotoxy(51,8);  cprintf("%s",output.hdd);
			gotoxy(51,10); cprintf("%s",output.screen);
			gotoxy(51,12); cprintf("%s",output.cpu);
			gotoxy(51,14); cprintf("%s",output.weight);
			gotoxy(51,16); cprintf("%s",output.color);
			gotoxy(51,18); cprintf("%s",output.date);
			gotoxy(51,20); cprintf("%ld",output.qty);
			gotoxy(51,22); cprintf("%.2f$",output.price);
			ch=getch();
		}while(ch!=27);
	}
	if(find==0){
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		message("YOUR ID SEARCHING","NO RESULT");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again;
		}while(ch!=27);
	}
	fclose(fp);
}


void deletecom(){
	again1:
	clrscr();
	textbackground(BLUE);
	clrscr();
	frame();
	searchbox();
	gotoxy(11,12); textcolor(BLACK); textbackground(WHITE);
	cprintf("PLEASE INPUT COMPUTER ID TO DELETE");
	gotoxy(46,12); textbackground(BLUE); cprintf("%22c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(46,12); inputmix(x,8);
	_setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("computer.txt","rb");
	fp1=fopen("temp.txt","wb");
	while(fread(&output,m,1,fp)==1){
		if(strcmp(strlwr(output.id),strlwr(x))==0){
			if(find==0){
			message("ARE YOU SURE WANT TO DELETE","");
			yesno(&ask);
			if(ask=='n'||ask=='N') goto aaaa;
			}
			find=1;
		}else{
			aaaa:
			fwrite(&output,m,1,fp1);
		}
	}
	fclose(fp); fclose(fp1);
	remove("computer.txt"); rename("temp.txt","computer.txt");
	if(find==0){
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		message("YOU DELETING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again1;
		}while(ch!=27);
	}
	if(find==1){
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		message("YOU DELETING","COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK");
		ch=getch();
		}while(ch!=27);
	}


}



void editcom(){
	again2:
	clrscr();
	textbackground(BLUE);
	clrscr();
	frame();
	searchbox();
	gotoxy(11,12); textcolor(BLACK); textbackground(WHITE);
	cprintf("PLEASE INPUT COMPUTER ID TO EDIT");
	gotoxy(44,12); textbackground(BLUE); cprintf("%24c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(44,12); inputmix(x,7);
	_setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("computer.txt","r+b");
	fp1=fopen("temp.txt","w+b");
	while(fread(&output,m,1,fp)==1){
		if(strcmp(strlwr(output.id),strlwr(x))==0){
		   do{
			_setcursortype(_NOCURSOR);
			textbackground(BLUE);
			clrscr();
			frame();
			textcolor(YELLOW);

			editcomputerinfo();
			st=getch();

			clrscr(); frame();
			inputgraphic("              PLEASE INPUT THE FOLLOWING INFORMATION OF COMPUTER            ");
			textbackground(GREEN);
			gotoxy(18,14); printf("%s",output.id);
			gotoxy(17,18); cprintf("%s",output.brand);
			gotoxy(12,20); cprintf("%s",output.model);
			gotoxy(12,22); cprintf("%s",output.type);
			gotoxy(51,6);  cprintf("%s",output.ram);
			gotoxy(51,8);  cprintf("%s",output.hdd);
			gotoxy(51,10); cprintf("%s",output.screen);
			gotoxy(51,12); cprintf("%s",output.cpu);
			gotoxy(51,14); cprintf("%s",output.weight);
			gotoxy(51,16); cprintf("%s",output.color);
			gotoxy(51,18); cprintf("%s",output.date);
			gotoxy(51,20); cprintf("%ld",output.qty);
			gotoxy(51,22); cprintf("$%.2f",output.price);
			_setcursortype(_SOLIDCURSOR);
			switch(st){
			case 'a':  find=1;
				gotoxy(17,18); cprintf("            ");
				gotoxy(17,18); inputmix(output.brand,11);
				break;
			case 'b':  find=1;
				gotoxy(12,20); cprintf("                 ");
				gotoxy(12,20); inputmix(output.model,15);
				break;
			case 'c':   find=1;
				gotoxy(12,22); cprintf("                 ");
				gotoxy(12,22); inputmix(output.type,8);
				break;
			case 'd':  find=1;
				gotoxy(51,6); cprintf("           ");
				gotoxy(51,6); inputmix(output.ram,10);
				break;
			case 'e':  find=1;
				gotoxy(51,8); cprintf("           ");
				gotoxy(51,8); inputmix(output.hdd,10);
				break;
			case 'f':   find=1;
				gotoxy(51,10); cprintf("                    ");
				gotoxy(51,10); inputmix(output.screen,20);
				break;
			case 'g':   find=1;
				gotoxy(51,12); cprintf("                    ");
				gotoxy(51,12); inputmix(output.cpu,20);
				break;
			case 'h':  find=1;
				gotoxy(51,14); cprintf("          ");
				gotoxy(51,14); inputmix(output.weight,10);
				break;
			case 'i':    find=1;
				gotoxy(51,16); cprintf("                    ");
				gotoxy(51,16); inputmix(output.color,20);
				break;
			case 'j':   find=1;
				gotoxy(51,18); cprintf("                    ");
				gotoxy(51,18); inputmix(output.date,20);
				break;
			case 'k':    find=1;
				gotoxy(51,20); cprintf("      ");
				gotoxy(51,20); inputnum(qty,9);
				output.qty=atol(qty);
				break;
			case 'l':   find=1;
				gotoxy(51,22); cprintf("          ");
				gotoxy(51,22); inputnum(price,5);
				output.price=atof(price);
				break;
			}
		   }while(st!='m'&& st!=27);
			fwrite(&output,m,1,fp1);

		}else{
			fwrite(&output,m,1,fp1);
		}
	}
	fclose(fp); fclose(fp1);
	remove("computer.txt"); rename("temp.txt","computer.txt");

	_setcursortype(_NOCURSOR);
	if(find==0){
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		message("YOU EDITING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again2;
		}while(ch!=27);
	}
	if(find==1){
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		message("YOU EDITING","COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK");
		ch=getch();
		}while(ch!=27);
	}


}

