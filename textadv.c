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
void viewplayers(void);

void page1(void);                       //pages for game
void page2_1(void);
void page2_2(void);

void closeapplication(void);
int  getdata();
int  checksr(int);
int t(void);


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
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB A Mercenary in Pinebreak \xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Start Game   "); 
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. View Older Players"); 
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Exit"); 
gotoxy(20,11);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
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
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT A GUILD\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
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
        printf("Start Game?(Y / N):");                                                            
        if(getch()=='n')
        mainmenu();
        else
        system("cls");                                                           
        page1();
        }
}

void viewplayers(void)  //show list of players
{
int i=0,j,sr=1;
system("cls");
gotoxy(1,1);
printf("***********************Adventurers Before You***********************");
gotoxy(20,2);
printf("SNo.          Guild           NAME");
j=4;
fp=fopen("playerdata.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(20,j);
printf("%d",sr);
gotoxy(34,j);
printf("%s",a.cat);
gotoxy(50,j);
printf("%s",a.name);
printf("\n\n");
j++;
i=j-4;
sr=j-3;
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
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,6);
printf("Guild:");
gotoxy(31,6);
printf("%s",catagories[s-1]);
gotoxy(21,8);
printf("Player Name:");
gotoxy(33,8);
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
//Game content starts here

void page1(void){

        system("cls");
        gotoxy(10,3);printf("Page 1, Welcome to Pinebreak");
        gotoxy(10,4);
        for(int i=0; i<81; i++){printf("\xB2");}                //printing outline of the textbox
        gotoxy(10,5);
        printf("\xB2");gotoxy(90,5);printf("\xB2");
        gotoxy(10,6);
        printf("\xB2");gotoxy(90,6);printf("\xB2");
        gotoxy(10,7);
        printf("\xB2");gotoxy(90,7);printf("\xB2");
        gotoxy(10,8);
        printf("\xB2");gotoxy(90,8);printf("\xB2");
        gotoxy(10,9);
        printf("\xB2");gotoxy(90,9);printf("\xB2");
        gotoxy(10,10);
        printf("\xB2");gotoxy(90,10);printf("\xB2");
        gotoxy(10,11);
        printf("\xB2");gotoxy(90,11);printf("\xB2");
        gotoxy(10,12);
        printf("\xB2");gotoxy(90,12);printf("\xB2");
        gotoxy(10,13);
        printf("\xB2");gotoxy(90,13);printf("\xB2");
        gotoxy(10,14);
        printf("\xB2");gotoxy(90,14);printf("\xB2");
        gotoxy(10,15);
        printf("\xB2");gotoxy(90,15);printf("\xB2");
        gotoxy(10,16);
        for(int i=0; i<81; i++){printf("\xB2");}
        gotoxy(12,6);
        printf("'Don't start any trouble merc, we don't take kindly to your kind around here.'\n");
        gotoxy(12,7);
        printf("Said the guard looking at me as I entered Relisia's biggest city, Pinebreak.\n");
        gotoxy(12,8);
        printf("Little does he know you are here on a contract for the Emperor's head.\n");
        gotoxy(12,10);
        printf("You decide to:\n");
        gotoxy(12,11);
        printf("1. Go to the Armory on your right\n");
        gotoxy(12,12);
        printf("2. Taunt the Guard\n");
        gotoxy(12,14);
        printf("Choose an option:");                                                            
        if(getch()=='1')
        page2_1();
        else
        system("cls");                                                    
        page2_2();
        
}

void page2_1(void){

        system("cls");
        gotoxy(10,3);printf("Page 2_1, Pinebreak Armory");
        gotoxy(10,4);
        for(int i=0; i<81; i++){printf("\xB2");}                //printing outline of the textbox
        gotoxy(10,5);
        printf("\xB2");gotoxy(90,5);printf("\xB2");
        gotoxy(10,6);
        printf("\xB2");gotoxy(90,6);printf("\xB2");
        gotoxy(10,7);
        printf("\xB2");gotoxy(90,7);printf("\xB2");
        gotoxy(10,8);
        printf("\xB2");gotoxy(90,8);printf("\xB2");
        gotoxy(10,9);
        printf("\xB2");gotoxy(90,9);printf("\xB2");
        gotoxy(10,10);
        printf("\xB2");gotoxy(90,10);printf("\xB2");
        gotoxy(10,11);
        printf("\xB2");gotoxy(90,11);printf("\xB2");
        gotoxy(10,12);
        printf("\xB2");gotoxy(90,12);printf("\xB2");
        gotoxy(10,13);
        printf("\xB2");gotoxy(90,13);printf("\xB2");
        gotoxy(10,14);
        printf("\xB2");gotoxy(90,14);printf("\xB2");
        gotoxy(10,15);
        printf("\xB2");gotoxy(90,15);printf("\xB2");
        gotoxy(10,16);
        for(int i=0; i<81; i++){printf("\xB2");}
        gotoxy(12,6);
        printf("You enter the stone building with steel swords and axes hung on the walls.\n");
        gotoxy(12,7);
        printf("In front of you is the owner and a smith working the anvil with a sword.\n");
        gotoxy(12,8);
        printf("He asks, 'What do you need weary traveller? I can patch that sword for you.'\n");
        gotoxy(12,10);
        printf("You say:\n");
        gotoxy(12,11);
        printf("1. My sword's fine, I am here for some information.\n");
        gotoxy(12,12);
        printf("2. Fix my sword for me, it has grown dull along the journey.\n");
        gotoxy(12,13);
        printf("3. Show me what you have for sale.\n");
        gotoxy(12,14);
        printf("Choose an option:");                                                            
        if(getch()=='1')
        mainmenu();
        else
        system("cls");                                                                       // make game here
        mainmenu();
        
}

void page2_2(void){

        system("cls");
        gotoxy(10,3);printf("Page 2_2, The annoying city watch");
        gotoxy(10,4);
        for(int i=0; i<81; i++){printf("\xB2");}                //printing outline of the textbox
        gotoxy(10,5);
        printf("\xB2");gotoxy(90,5);printf("\xB2");
        gotoxy(10,6);
        printf("\xB2");gotoxy(90,6);printf("\xB2");
        gotoxy(10,7);
        printf("\xB2");gotoxy(90,7);printf("\xB2");
        gotoxy(10,8);
        printf("\xB2");gotoxy(90,8);printf("\xB2");
        gotoxy(10,9);
        printf("\xB2");gotoxy(90,9);printf("\xB2");
        gotoxy(10,10);
        printf("\xB2");gotoxy(90,10);printf("\xB2");
        gotoxy(10,11);
        printf("\xB2");gotoxy(90,11);printf("\xB2");
        gotoxy(10,12);
        printf("\xB2");gotoxy(90,12);printf("\xB2");
        gotoxy(10,13);
        printf("\xB2");gotoxy(90,13);printf("\xB2");
        gotoxy(10,14);
        printf("\xB2");gotoxy(90,14);printf("\xB2");
        gotoxy(10,15);
        printf("\xB2");gotoxy(90,15);printf("\xB2");
        gotoxy(10,16);
        for(int i=0; i<81; i++){printf("\xB2");}
        gotoxy(12,6);
        printf("'Have you ever used that sword in your life while guarding doors, old man'\n");
        gotoxy(12,7);
        printf("Not expecting that from a newcomer the guard stood mum. Looking at me he said\n");
        gotoxy(12,8);
        printf("'Just giving you the proper Pinebreak welcome lad, let's have some ale.'\n");
        gotoxy(12,10);
        printf("You say:\n");
        gotoxy(12,11);
        printf("1. 'I'll pass, need to stay sober for the journey' and proceed to the armory\n");
        gotoxy(12,12);
        printf("2. 'Yes, also tell me what's new in Pinebreak'\n");
        gotoxy(12,14);
        printf("Choose an option:");                                                            
        if(getch()=='1')
        page2_1();
        else
        system("cls");                                                                       // make game here
        mainmenu();
        
}



//End of program
