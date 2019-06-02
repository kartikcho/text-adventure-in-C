#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

char catagories[][15]={"Warrior","Mage","Thief","Archer","Engineer","Paladin"};
void returnfunc(void);
void mainmenu(void);
void addplayers(void);
void searchplayers(void);
void viewplayers(void);
void closeapplication(void);
int  getdata();
int  checksr(int);
int t(void);

void issuerecord();
void loaderanim();

//global files to be accessed in program
FILE *fp,*ft,*fs;
COORD coord = {0, 0};

//global variables
int s;
char findplayers;

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct meroDate
{
int mm,dd,yy;
};
struct players
{
int id;
char stname[20];
char name[20];
int count;
char *cat;
};
struct players a;
int main()
{
mainmenu();
getch();
return 0;

}

void mainmenu()         // Main Menu for the game
{

system("cls");

int i;
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB A Mercenary in Tamriel \xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Start Game   "); 
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. View Older Players"); 
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Exit"); 
gotoxy(20,11);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,13);
t();
gotoxy(20,19);
printf("Enter your choice:");
switch(getch())
{
case '1':
addplayers();
break;
case '2':
viewplayers();
break;
case '3':
{
system("cls");
gotoxy(16,3);
printf("\tText Adventure");
gotoxy(16,4);
printf("\tmade in C");
gotoxy(16,5);
printf("\tby");
gotoxy(16,7);
printf("\tKartik Choudhary");
gotoxy(10,17);
printf("Exiting game...>");

Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option");
if(getch())
mainmenu();
}

}
}
void addplayers(void)    //funtion that adds players
{
system("cls");
int i;
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGORIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Warrior");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. Mage");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. Thief");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. Archer");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Engineer");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. Paladin");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,22);
printf("Enter your choice:");
scanf("%d",&s);
if(s==7)

mainmenu() ;
system("cls");
fp=fopen("playerdata.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The character is sucessfully saved");
        gotoxy(21,15);
        printf("Start Game?(Y / N):");                                                             // make game here
        if(getch()=='n')
        mainmenu();
        else
        system("cls");
        addplayers();
        }
}

void viewplayers(void)  //show list of players
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("***************************Adventurers Before You***************************");
gotoxy(20,2);
printf("Guild           SNo.           NAME");
j=4;
fp=fopen("playerdata.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(20,j);
printf("%s",a.cat);
gotoxy(36,j);
printf("%d",a.id);
gotoxy(44,j);
printf("%s",a.name);
printf("\n\n");
j++;
i=j-4;
}
gotoxy(3,25);
printf("Total Players = %d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}
void returnfunc(void)
{
{
printf(" Press ENTER to return menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,6);
printf("Guild:");
gotoxy(31,6);
printf("%s",catagories[s-1]);
gotoxy(21,8);
printf("Serial No.:\t");
gotoxy(32,8);
scanf("%d",&t);
if(checksr(t) == 0)
{
gotoxy(21,13);
printf("\aThis SNo. already exists\a");
getch();
getdata();
return 0;
}
a.id=t;
gotoxy(21,10);
printf("Player Name:");
gotoxy(33,10);
scanf("%s",a.name);
return 1;
}
int checksr(int t)  //check whether the player exists or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if exits
return 1; //else return 1
}
int t(void) //for time
{
time_t t;
time(&t);
printf("\t%s\n",ctime(&t));

return 0 ;
}

//End of program
