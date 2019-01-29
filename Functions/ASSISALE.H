#include<conio.h>
#include<string.h>
#include<dos.h>

struct salecom{
	char cid[10];
	char eid[10];
	char sid[10];
	char date[15];
	long sqty;
	float cprice;
	float total;
	char cmodel[20];
	char cbrand[20];
	struct{
		char name[20];
		char sex[10];
		char phone[20];
	}cus;
};
struct salecom inputsa,outputsa;
long m2=sizeof(struct salecom),stock,qtytemp,quantity;
char sqty[9],sprice[9],cidtemp[10],cmodel[20],cbrand[20],oldcid[10],oldcmodel[20],oldcbrand[20];


void sale(){

	do{
		textbackground(BLUE);
		clrscr();
		frame();
		inputsalegraphic("===========================INPUT SALE INFORMATION===========================");
		_setcursortype(_SOLIDCURSOR);

		zz1: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("INPUT [exit] TO FINISH");
		gotoxy(17,7); inputmix(inputsa.eid,9);
			if(strcmp(strlwr(inputsa.eid),"exit")==0) break;
			fp1=fopen("employee.txt","rb");
			find=0;
			while(fread(&inputem,m1,1,fp1)==1)
			if(strcmp(strlwr(inputsa.eid),strlwr(inputem.id))==0)
				find=1;
			if(find==0){
				textbackground(3);
				gotoxy(17,7);  cprintf("[NOT MATCHED]");
				delay(900); gotoxy(17,7); cprintf("               ");
				goto zz1;
			}
			fclose(fp1); gotoxy(2,25); textbackground(BLUE); clreol();
		zz2: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("INPUT [exit] TO FINISH");
		gotoxy(17,12); inputmix(inputsa.cid,9);
			if(strcmp(strlwr(inputsa.cid),"exit")==0) break;
			fp=fopen("computer.txt","rb");
			find=0;
			while(fread(&output,m,1,fp)==1)
			if(strcmp(strlwr(inputsa.cid),strlwr(output.id))==0){
				find=1;
				stock=output.qty;
				strcpy(inputsa.cmodel,output.model);
				strcpy(inputsa.cbrand,output.brand);
			}
			if(find==0){
				textbackground(3);
				gotoxy(17,12);  cprintf("[NOT MATCHED]");
				delay(900); gotoxy(17,12); cprintf("              ");
				goto zz2;
			}
			fclose(fp); gotoxy(2,25); textbackground(BLUE); clreol();

		zz3: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("INPUT [exit] TO FINISH");
		gotoxy(13,17); inputmix(inputsa.sid,9);
			if(strcmp(strlwr(inputsa.sid),"exit")==0) break;
			fp=fopen("sale.txt","rb");
			while(fread(&outputsa,m2,1,fp)==1)
			if(strcmp(strlwr(outputsa.sid),strlwr(inputsa.sid))==0){
				textbackground(3);
				gotoxy(13,17); cprintf("[ EXIST ] ");
				delay(900); gotoxy(13,17); cprintf("          ");
				goto zz3;
			}
			fclose(fp); gotoxy(2,25); textbackground(BLUE); clreol();

		gotoxy(13,19); inputmix(inputsa.date,15);


		zz4: gotoxy(2,25); textcolor(YELLOW); textbackground(BLUE); clreol(); cprintf("INPUT NUMBER [0] to FINISH");
		gotoxy(13,21); inputnum(sqty,5); if(strcmp(sqty,"0")==0) break;
			inputsa.sqty=atol(sqty);
			if(inputsa.sqty>stock){
				textbackground(3);
				gotoxy(13,21); cprintf("[OUT OF STOCK]");
				gotoxy(2,25); textbackground(BLUE); clreol();
				gotoxy(2,25); cprintf("PRODUCT IS STOCK REMAIN %ld",stock);
				textbackground(3);
				delay(900); gotoxy(13,21); cprintf("                 ");
				goto zz4;
			}
			gotoxy(2,25); clreol();
			fp=fopen("computer.txt","rb");
			fp1=fopen("temp.txt","wb");
			while(fread(&input,m,1,fp)==1)
			if(strcmp(input.id,inputsa.cid)==0){
				inputsa.cprice=input.price;
				input.qty=input.qty-inputsa.sqty;
				inputsa.total=inputsa.sqty*inputsa.cprice;
				fwrite(&input,m,1,fp1);
			}
			else fwrite(&input,m,1,fp1);

			fclose(fp); fclose(fp1);
			remove("computer.txt");
			rename("temp.txt","computer.txt");
			gotoxy(2,25); textbackground(BLUE); clreol();

		gotoxy(51,17); inputmix(inputsa.cus.name,15);
	   q12: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[AGE MUST BE BETWEEN 18 AND 59 YEARS OLD]               [INPUT 100 TO FINISH]");
		gotoxy(51,19); inputmix(inputsa.cus.sex,7);
			if(strcmp(strlwr(inputsa.cus.sex),"exit")==0) break;
			if(strcmp(strlwr(inputsa.cus.sex),"male")==0 || strcmp(strlwr(inputsa.cus.sex),"female")==0){
			}else{
			textbackground(3);
			gotoxy(51,19); cprintf("[male/female]");
			delay(900); gotoxy(51,19); cprintf("             ");
			goto q12;
			}
			gotoxy(2,25);
			textbackground(BLUE); clreol();
		gotoxy(51,21); inputnum(inputsa.cus.phone,15); textbackground(3);
		gotoxy(37,23); cprintf("%.2f$",inputsa.total);

		fp=fopen("sale.txt","ab");
		fwrite(&inputsa,m2,1,fp);
		fclose(fp);

		_setcursortype(_NOCURSOR);
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("PRESS [ENTER] TO CONTINUE AND [ESC] TO FINISH INPUTING");

		z:
		ch=getch();
		if(ch!=13&&ch!=27) goto z;
	}while(ch==13);
	_setcursortype(_NOCURSOR);
}

void deletesale(){
	again:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT SALE ID TO DELETE");
	gotoxy(42,12); textbackground(BLUE); cprintf("%26c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(42,12); inputmix(x,10); _setcursortype(_NOCURSOR);

	find=0;
	fp2=fopen("sale.txt","rb");
	fp3=fopen("temp.txt","wb");
	while(fread(&outputsa,m2,1,fp2)==1){
		if(strcmp(strlwr(outputsa.sid),strlwr(x))==0){
			if(find==0){
			message("ARE YOU SURE WANT TO DELETE","");
			yesno(&ask);
				if(ask=='n' || ask=='N') goto gg;
			}
			find=1;
			qtytemp=outputsa.sqty;
			strcpy(cidtemp,outputsa.cid);
			strcpy(cmodel,outputsa.cmodel); //for compare when delete sale information
			strcpy(cbrand,outputsa.cbrand);
		}else{
			gg:
			fwrite(&outputsa,m2,1,fp3);
		}
	}
	fclose(fp2); fclose(fp3);
	remove("sale.txt");
	rename("temp.txt","sale.txt");

	if(find==0){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR DELETING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again;
		}while(ch!=27);
	}
	if(find==1){
		fp=fopen("computer.txt","rb");
		fp1=fopen("temp.txt","wb");
		while(fread(&input,m,1,fp)==1)
			if(strcmp(strlwr(input.id),strlwr(cidtemp))==0&&strcmp(input.model,cmodel)==0&&strcmp(input.brand,cbrand)==0){
				//inputsa.sprice=input.price;
				input.qty=input.qty+qtytemp;
				//inputsa.total=inputsa.sqty*inputsa.sprice;
				fwrite(&input,m,1,fp1);
			}
			else fwrite(&input,m,1,fp1);

			fclose(fp); fclose(fp1);
			remove("computer.txt");
			rename("temp.txt","computer.txt");
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


void outputsaleless(){
	struct salecom sort1[200],ttt;

	loop:
	fp=fopen("sale.txt","r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/m2; i=0;

	if(n<17){
		textbackground(BLUE);
		frame();
		outputsalegraphic();
		rewind(fp);
		while(fread(&outputsa,m2,1,fp)==1){
			textcolor(WHITE); textbackground(BLACK);
			gotoxy(4,6+i); cprintf("%s",outputsa.sid);
			gotoxy(16,6+i); cprintf("%s",outputsa.cid);
			gotoxy(29,6+i); cprintf("%s",outputsa.cus.name);
			gotoxy(46,6+i); cprintf("%ld",outputsa.sqty);
			gotoxy(58,6+i); cprintf("%.2f$",outputsa.cprice);
			gotoxy(70,6+i); cprintf("%.2f$",outputsa.total);
			i++;
		}
	   tt1: ch=getch();
		switch(ch){
		case 'i':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort1[i].sid,sort1[j].sid)>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'c':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort1[i].cid,sort1[j].cid)>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'n':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort1[i].cus.name),strlwr(sort1[j].cus.name))>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'q':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].sqty>sort1[j].sqty){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'u':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].cprice>sort1[j].cprice){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 't':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].total>sort1[j].total){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
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
			gotoxy(4,6+a); cprintf("%s",outputsa.sid);
			gotoxy(16,6+a); cprintf("%s",outputsa.cid);
			gotoxy(29,6+a); cprintf("%s",outputsa.cus.name);
			gotoxy(46,6+a); cprintf("%ld",outputsa.sqty);
			gotoxy(58,6+a); cprintf("%.2f$",outputsa.cprice);
			gotoxy(70,6+a); cprintf("%.2f$",outputsa.total);
			a++;
		}
		ch=getch();
		switch(ch){
		case 'i':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort1[i].sid,sort1[j].sid)>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'c':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(sort1[i].cid,sort1[j].cid)>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'n':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(strcmp(strlwr(sort1[i].cus.name),strlwr(sort1[j].cus.name))>0){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'q':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].sqty>sort1[j].sqty){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 'u':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].cprice>sort1[j].cprice){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		case 't':
			count=0;
			fclose(fp);
			fp1=fopen("sale.txt","rb");
			fp2=fopen("temp.txt","wb");
			while(fread(&sort1[count],m2,1,fp1)==1)
			count++;

			for(i=0;i<count;i++)
			for(j=i+1;j<count;j++)
			if(sort1[i].total>sort1[j].total){
				ttt=sort1[i];
				sort1[i]=sort1[j];
				sort1[j]=ttt;
			}

			for(i=0;i<count;i++)
			fwrite(&sort1[i],m2,1,fp2);

			fclose(fp1); fclose(fp2);
			remove("sale.txt");
			rename("temp.txt","sale.txt");
			goto loop;
		}
		if(ch==72) if(i>0) i--;
		if(ch==80) if(i+17<n) i++;
		}while(ch!=27);
	}
	fclose(fp);
}


void outputsalemore(){

	fp=fopen("sale.txt","r+b");
	fseek(fp,0,SEEK_END);
	n=ftell(fp)/m2; i=0;

	ch=80;
	rewind(fp);
	do{
		if(ch==80)if(i<n){
			i++;
			fread(&outputsa,m2,1,fp);
		}
		if(ch==72)if(i>1){
			i--;
			fseek(fp,-2*m2,SEEK_CUR);
			fread(&outputsa,m2,1,fp);
		}

		textbackground(BLUE);
		clrscr();
		frame();
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("[PRESS  TO SCROLL UP] [PRESS  TO SCROLL DOWN]  [PRESS ESC TO FINISH SHOWING]");
		inputsalegraphic("========================SALE INFORMATION WITH DETAIL========================");

		textbackground(3); textcolor(YELLOW);
		gotoxy(17,7);  cprintf("%s",outputsa.eid);
		gotoxy(17,12); cprintf("%s",outputsa.cid);
		gotoxy(13,17); cprintf("%s",outputsa.sid);
		gotoxy(13,19); cprintf("%s",outputsa.date);
		gotoxy(13,21); cprintf("%ld",outputsa.sqty);
		gotoxy(51,17); cprintf("%s",outputsa.cus.name);
		gotoxy(51,19); cprintf("%s",outputsa.cus.sex);
		gotoxy(51,21); cprintf("%s",outputsa.cus.phone);
		gotoxy(37,23); cprintf("%.2f$",outputsa.total);
		ch=getch();
	}while(ch!=27);
	fclose(fp);
}


void searchsaleid(){
	again1:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT SALE ID TO SEARCH");
	gotoxy(42,12); textbackground(BLUE); cprintf("%26c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(42,12); inputmix(x,9); _setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("sale.txt","r+b");
	rewind(fp);
	while(fread(&outputsa,m2,1,fp)==1)
	if(strcmp(strlwr(outputsa.sid),strlwr(x))==0){
		find=1;
		do{
		textbackground(BLUE);
		clrscr();
		frame();
		textbackground(BLUE); textcolor(YELLOW);
		gotoxy(2,25); cprintf("PRESS [ESC] TO FINISH SHOWING");
		inputsalegraphic("=============================ID SEARCH RESULT===============================");

		textbackground(3); textcolor(WHITE);
		gotoxy(17,7);  cprintf("%s",outputsa.eid);
		gotoxy(17,12); cprintf("%s",outputsa.cid);
		gotoxy(13,17); cprintf("%s",outputsa.sid);
		gotoxy(13,19); cprintf("%s",outputsa.date);
		gotoxy(13,21); cprintf("%ld",outputsa.sqty);
		gotoxy(51,17); cprintf("%s",outputsa.cus.name);
		gotoxy(51,19); cprintf("%s",outputsa.cus.sex);
		gotoxy(51,21); cprintf("%s",outputsa.cus.phone);
		gotoxy(37,23); cprintf("%.2f$",outputsa.total);
		ch=getch();
		}while(ch!=27);
	}
	if(find==0){
		do{
		textbackground(BLUE);
		frame();
		message("YOUR ID SEARCHING","NO RESULT");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again1;
		}while(ch!=27);
	}
	fclose(fp);
}


void editsale(){
	again2:
	clrscr();
	textbackground(BLUE);
	frame();
	searchbox();
	gotoxy(11,12); textbackground(WHITE); textcolor(BLACK);
	cprintf("PLEASE INPUT SALE ID TO EDIT");
	gotoxy(42,12); textbackground(BLUE); cprintf("%24c",' ');
	_setcursortype(_SOLIDCURSOR);
	gotoxy(42,12); gets(x); _setcursortype(_NOCURSOR);

	find=0;
	fp=fopen("sale.txt","r+b");
	fp1=fopen("temp.txt","w+b");
	while(fread(&outputsa,m2,1,fp)==1){
		if(strcmp(strlwr(outputsa.sid),strlwr(x))==0){

			strcpy(oldcid,outputsa.cid);
			strcpy(oldcmodel,outputsa.cmodel);
			strcpy(oldcbrand,outputsa.cbrand);

			fp2=fopen("computer.txt","r+b");
			while(fread(&output,m,1,fp2)==1)
			if(strcmp(strlwr(outputsa.cid),strlwr(output.id))==0){
				stock=output.qty;
			}
			fclose(fp2);

			do{
			quantity=outputsa.sqty;
			_setcursortype(_NOCURSOR);
			textbackground(BLUE);
			clrscr();
			frame();
			editsaleinfo();
			st=getch();

			textbackground(BLUE);
			clrscr();
			frame();
			inputsalegraphic("=============================ID SEARCH RESULT===============================");

			textbackground(3); textcolor(WHITE);
			gotoxy(17,7);  cprintf("%s",outputsa.eid);
			gotoxy(17,12); cprintf("%s",outputsa.cid);
			gotoxy(13,17); cprintf("%s",outputsa.sid);
			gotoxy(13,19); cprintf("%s",outputsa.date);
			gotoxy(13,21); cprintf("%ld",outputsa.sqty);
			gotoxy(51,17); cprintf("%s",outputsa.cus.name);
			gotoxy(51,19); cprintf("%s",outputsa.cus.sex);
			gotoxy(51,21); cprintf("%s",outputsa.cus.phone);
			gotoxy(37,23); cprintf("%.2f$",outputsa.total);

			_setcursortype(_SOLIDCURSOR);  textbackground(BLUE);
			switch(st){
			case 'a':
				find=1; char eid[10];
				zz1: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("INPUT [exit] TO FINISH");
				gotoxy(17,7); textbackground(3); cprintf("             ");
				gotoxy(17,7); inputmix(eid,9);
						if(strcmp(strlwr(eid),"exit")==0) break;
						fp2=fopen("employee.txt","rb");
						int find1=0;
						while(fread(&inputem,m1,1,fp2)==1)
						if(strcmp(strlwr(eid),strlwr(inputem.id))==0)
						find1=1;
						if(find1==0){
						textbackground(3);
						gotoxy(17,7);  cprintf("[NOT MATCHED]");
						delay(900); gotoxy(17,7); cprintf("               ");
						goto zz1;
						}
				fclose(fp2); gotoxy(2,25); textbackground(BLUE); clreol();
				strcpy(outputsa.eid,eid);
				break;
			case 'b':
				textbackground(BLUE);
				find=1; char cid[10];
				fp2=fopen("computer.txt","r+b");
				fp3=fopen("tempcomputer.txt","w+b");
				zz2:  textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25);  cprintf("INPUT [exit] TO FINISH");
				gotoxy(17,12); textbackground(3); cprintf("         ");
				gotoxy(17,12); inputmix(cid,9);


					find1=0;
					while(fread(&output,m,1,fp2)==1)
					if(strcmp(strlwr(output.id),strlwr(cid))==0 && output.qty>=outputsa.sqty){

					   /*	if(output.qty<outputsa.sqty){
							textbackground(3);
							gotoxy(17,12);  cprintf("[NOT ENOUGH STOCK]");
							delay(900); gotoxy(17,12); cprintf("                  ");
							goto zz2;
						}  */

						find1=1;
						output.qty=output.qty-outputsa.sqty;
						stock=output.qty;
						outputsa.cprice=output.price;
						strcpy(outputsa.cbrand,output.brand);
						strcpy(outputsa.cmodel,output.model);
						outputsa.total=outputsa.sqty*outputsa.cprice;
						fwrite(&output,m,1,fp3);
					}else fwrite(&output,m,1,fp3);
					if(strcmp(strlwr(cid),"exit")==0) goto ff;
					if(find1==0){
						textbackground(3);
						gotoxy(17,12);  cprintf("[NOT MATCHED]");
						delay(900); gotoxy(17,12); cprintf("              ");
						goto zz2;
					}
				strcpy(outputsa.cid,cid);

				textbackground(3); textcolor(YELLOW);
				gotoxy(37,23); cprintf("             ");
				gotoxy(37,23); cprintf("%.2f$",outputsa.total);
				textbackground(BLUE);
				getch();

				ff:
				fclose(fp2); fclose(fp3);
				remove("computer.txt");
				rename("tempcomputer.txt","computer.txt");
				gotoxy(2,25); textbackground(BLUE); clreol();

				if(find1==1){
					fp2=fopen("computer.txt","r+b");
					fp3=fopen("tempcomputer.txt","w+b");
					while(fread(&output,m,1,fp2)==1)
					if(strcmp(strlwr(output.id),strlwr(oldcid))==0 && strcmp(strlwr(output.model),strlwr(oldcmodel))==0 && strcmp(strlwr(output.brand),strlwr(oldcbrand))==0){
						output.qty=output.qty+outputsa.sqty;
						fwrite(&output,m,1,fp3);
					}else  fwrite(&output,m,1,fp3);
					fclose(fp2); fclose(fp3);
					remove("computer.txt");
					rename("tempcomputer.txt","computer.txt");

				}
				break;
			case 'c':
				find=1;
				gotoxy(13,19); textbackground(3); cprintf("              ");
				gotoxy(13,19); inputmix(inputsa.date,15);
				break;
			case 'd':
				textbackground(BLUE);
				find=1; long sqtynum;
				zz4:textcolor(YELLOW); textbackground(BLUE) ;gotoxy(2,25); clreol(); cprintf("INPUT NUMBER [0] to FINISH");
				gotoxy(13,21); textbackground(3); cprintf("       ");
				gotoxy(13,21); inputnum(sqty,5); if(strcmp(sqty,"0")==0) break;
					sqtynum=atoi(sqty);
					if(sqtynum>stock){
						textbackground(3);
						gotoxy(13,21); cprintf("[OUT OF STOCK]");
						gotoxy(2,25); textbackground(BLUE); clreol();
						gotoxy(2,25); cprintf("PRODUCT IS STOCK REMAIN %ld",stock);
						textbackground(3);
						delay(900); gotoxy(13,21); cprintf("                 ");
						goto zz4;
					}
					outputsa.sqty=atoi(sqty);

					gotoxy(2,25); clreol();
					fp2=fopen("computer.txt","rb");
					fp3=fopen("temp2.txt","wb");
					while(fread(&input,m,1,fp2)==1)
					if(strcmp(input.id,outputsa.cid)==0 && strcmp(input.model,outputsa.cmodel)==0 && strcmp(input.brand,outputsa.cbrand)==0){
						//outputsa.cprice=input.price;
						input.qty=input.qty+quantity;
						input.qty=input.qty-outputsa.sqty;
						fwrite(&input,m,1,fp3);
					}
					else fwrite(&input,m,1,fp3);

					outputsa.total=outputsa.sqty*outputsa.cprice;

					fclose(fp2); fclose(fp3);
					remove("computer.txt");
					rename("temp2.txt","computer.txt");
					gotoxy(2,25); textbackground(BLUE); clreol();

				textbackground(3); textcolor(YELLOW);
				gotoxy(37,23); cprintf("            ");
				gotoxy(37,23); cprintf("%.2f$",outputsa.total);
				textbackground(BLUE);
				getch();
				break;
			case 'e':
				find=1;
				gotoxy(51,17); textbackground(3); cprintf("               ");
				gotoxy(51,17); inputmix(outputsa.cus.name,15);
				break;
			case 'f':
				find=1;   char vv[10];
				gotoxy(51,19); textbackground(3); cprintf("             ");
			   q12: textcolor(YELLOW); textbackground(BLUE); gotoxy(2,25); cprintf("[AGE MUST BE BETWEEN 18 AND 59 YEARS OLD]               [INPUT 100 TO FINISH]");
				gotoxy(51,19); inputmix(vv,7);
					if(strcmp(strlwr(vv),"exit")==0) break;
					if(strcmp(strlwr(vv),"male")==0 || strcmp(strlwr(vv),"female")==0){
						strcpy(inputsa.cus.sex,vv);
					}else{
						textbackground(3);
						gotoxy(51,19); cprintf("[male/female]");
						delay(900); gotoxy(51,19); cprintf("             ");
						goto q12;
					}
					gotoxy(2,25);
					textbackground(BLUE); clreol();
				break;
			case 'g':
				find=1;
				gotoxy(51,21); textbackground(3); cprintf("                    ");
				gotoxy(51,21); inputnum(outputsa.cus.phone,15); textbackground(3);
				break;
			}
			}while(st!='h'&&st!=27);
			fwrite(&outputsa,m2,1,fp1);
		}else{
			fwrite(&outputsa,m2,1,fp1);
		}
	}
	fclose(fp); fclose(fp1);
	remove("sale.txt");
	rename("temp.txt","sale.txt");

	_setcursortype(_NOCURSOR);
	if(find==0){
		do{
		textbackground(BLUE); clrscr();
		frame();
		message("YOUR EDITING","NOT FOUND OR NOT COMPLETED");
		gotoxy(2,25); textcolor(YELLOW);
		cprintf("PRESS [ESC] TO GO BACK OR [ENTER] TO TRY AGAIN");
		ch=getch();
		if(ch==13) goto again2;
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