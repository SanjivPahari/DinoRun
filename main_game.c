#include <stdio.h>
#include <conio.h>

#include <iostream>

#include <time.h>
#include <windows.h>


// details ko struct

struct detail{
	char name[15];
	int score;
};



// main functions

void menu();
void Dino_Game_Home(char *username);
void Dino_Game_Main_Display(char *username);

void new_game(){

    int choice_username;
	char username_input[15]="Guest";


choose_username:
	printf("\t\t\tSelect player!\n\n");

	printf("\t\t\t1. Play as guest\n");
    printf("\t\t\t2. Play with username\n");
    scanf("%d",&choice_username);
    switch (choice_username)
    {
    case 1:
       // ok no username change
        break;

case 2:


printf("\n\nEnter username:");
scanf("%s",&username_input);


        break;

	    default :
        printf("INVALID CHOICE\t TRY AGAIN\n");
		goto choose_username;
    }

    Dino_Game_Home(username_input);


}

void top10_score() {

printf("\n\nTop 10 scores: \n\n");



struct detail player_data;
//struct detail player_data_out;
int scores_out[30];
char name_out[30][15];

FILE *fp;
fflush(stdin);
fp=fopen("scores.txt","r");

int x=0;
	int i,j;

while(fread(&player_data,sizeof(player_data),1,fp))
	{


for(i=0;i<=sizeof(player_data.name);i++) {
        name_out[x][i]=player_data.name[i];
}

       scores_out[x]=player_data.score;

    x++;

	}

int t;
char t_name[30][15];
  for(i=0;i<x;i++)
    {
        for(j=0;j<x-1;j++)
        {
            if(scores_out[j]<scores_out[j+1])
            {
                t=scores_out[j];
                scores_out[j]=scores_out[j+1];
                scores_out[j+1]=t;

int y;
                for(y=0;y<=sizeof(name_out[x]);y++) {
                t_name[x][y]=name_out[j][y];
                name_out[j][y]=name_out[j+1][y];
                name_out[j+1][y]=t_name[x][y];
                }

            }
        }
    }


    printf("\nUSERNAME\t\tSCORE\n");
    printf("-------------------------------------------------------------------------------\n");

    int number;

    if(x>=10) {
        number=10;
    } else {
    number=x;
    }
    for(i=0;i<number;i++)
    {

        printf("%s\t\t\t%d\n",name_out[i],scores_out[i]);

    }

      printf("-------------------------------------------------------------------------------\n");


fclose(fp);
// read file and show top 10 scores
menu();

}

void your_rank() {

char username_input[15]="Guest";

printf("\n\nEnter username:");
scanf("%s",&username_input);



struct detail player_data;

FILE *fp;
fflush(stdin);
fp=fopen("scores.txt","r");




    printf("\nUSERNAME\t\tSCORE\n");
    printf("-------------------------------------------------------------------------------\n");
while(fread(&player_data,sizeof(player_data),1,fp))
	{

	if(strcmp(username_input, player_data.name)==0) {
        printf("%s\t\t\t%d\n",player_data.name,player_data.score);
	}

	}


      printf("-------------------------------------------------------------------------------\n");


fclose(fp);
// read file and show top 10 scores




// read file and show username score


menu();
}

void reset_history() {



int value= remove("scores.txt");

if(!value)
    {
        printf("%s", "\nRecords removed successfully\n\n");
    }
    else
    {
        perror("\nError removing records!\n\n");
    }

menu();
}



void menu() {

    int choice;
choose_choice:
	printf("\t\t\tChoose an option:\n\n");

	printf("\t\t\t1. Start a new Game\n");
    printf("\t\t\t2. Show highscores\n");
    printf("\t\t\t3. Show user scores\n");
    printf("\t\t\t4. Reset all scores\n");
    printf("\t\t\t5. Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        new_game();
        break;

case 2:
        top10_score();
        break;

        case 3:
        your_rank();
        break;

        case 4:
        reset_history();
        break;


	    case 5:
	        exit(1);
		    break;


	    default :
        printf("INVALID CHOICE\t TRY AGAIN\n");
		goto choose_choice;
    }

}


// color code


void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void green() {
  printf("\033[1;32m");
}

void reset_color () {
  printf("\033[0m");
}

    // Thulo Box л
    // Saano Box м
    // Line Box п

/////////////////////////////////////////// certain screen position maa janey ani print use garney
void position(int x, int y)
{
 COORD location;
 location.X = x;
 location.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), location);

 // x bhaneko column number
 // y bhaneko row number
}
///////////////////////////////////////////
void print_underline() {
for(int x=0;x<26;x++) {
    printf("п");
    }
}

/////////////////////////////////////////////
// game ko functions

void insert_score_database(char *username,int score) {
// insert scores in a file

struct detail newdata;
int i;
for(i=0;i<=15;i++) {
newdata.name[i]=username[i];
}

newdata.score=score;

FILE *fp;
fflush(stdin);
fp=fopen("scores.txt","a");
fwrite(&newdata, sizeof(newdata),1,fp);
fclose(fp);

}


void update_highscore() {
// yo function will read file and update highscore in real time


struct detail player_data;


FILE *fp;
fflush(stdin);
fp=fopen("scores.txt","r");

int highscore=0;
char highscorer[15]="Guest";

while(fread(&player_data,sizeof(player_data),1,fp))
	{

        if (player_data.score > highscore) {

        int i;
  for(i=0;i<=15;i++) {
highscorer[i]=player_data.name[i];
  }

highscore=player_data.score;
      }

	}

fclose(fp);




    position(12,3);

    printf("\t\t\t                                                                  "); // clear the content

    position(12,3);

    printf("\t\t\t Highscore : %d by %s",highscore,highscorer);

    position(1,3);

}








///////////////////////////////////////////
void print_obstacle(int x) {

///// 70 column bata print hudai najeek najeek aauxa

    position(70-x,20);
    printf("л    л ");
    position(70-x,21);
    printf("л    л ");
    position(70-x,22);
    printf("лммммл ");
    position(70-x,23);
    printf("  л ");
    position(70-x,24);
    printf("  л " );
}
//////////////////////////////////////
void print_dino_upperbody(int t) {


 position(2,15-t);
    printf("                 ");
    position(2,16-t);
    printf("         млпллллм");
    position(2,17-t);
    printf("         лллллллл");
    position(2,18-t);
    printf("         лллллппп");
    position(2,19-t);
    printf(" л      мллллппп ");
    position(2,20-t);
    printf(" ллм  мллллллммм ");
    position(2,21-t);
    printf(" пллллллллллл  п ");
    position(2,22-t);
    printf("   плллллллп     ");
}
///////////////////////////////////////////
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock(); // number of ticks passed
    while (goal > clock()); // wait until delay done
}
///////////////////////////////
void Dino_Game_Main_Display(char *username)
{
    system("cls");

    printf("\n");



    printf(" Username: %s \n",username);

    red();
    print_underline();
reset_color();

update_highscore();



    printf("Score : \n");





    position(1,25);

    print_underline();
    print_underline();
    print_underline();

    position(1,27);
    printf("Press Space to Jump, Press X to Exit ");
}

int t,speed=40;



void ds(int jump=0 )
{
    static int a=1;

    if(jump==0) // no click
        t=0;
    else if(jump==2)  // jump down wala 2
        t--;
    else t++;  // jump janey time function ds 1

green();

   print_dino_upperbody(t);


    position(2,23-t);
    if(jump==1 || jump==2){
    printf("    ллп пл       ");
    position(2,24-t);
    printf("    лм   лм      ");
    }else if(a==1)
    {
    printf("    пллп  ппп    ");
    position(2,24-t);
    printf("      лм         ");
    a=2;
    }
    else if(a==2)
    {
    printf("     плм пл      ");
    position(2,24-t);
    printf("          лм     ");
    a=1;
    }

        reset_color();


    position(2,25-t); // jump hanna talai khali dekhauxa
    if(jump!=0){
        printf("                ");
    }
    else
    {

        printf("ппппппппппппппппп");
    }


    delay(speed);
}
void obstacle_touch_check(char *username)
{
    static int x=0,score=0; // ek choti setmayesi sakinan
    if(x==56 && t<4)  // 56 columns ma obstacle aayo ra hiehgt 4 set mathi samma matra chha bhaney
    {

insert_score_database(username,score);
update_highscore();


    score=-1;
    speed=40;


    ///////////////////////////////// Game Over
    position(10,8);
    printf("Game Over! Press any key to replay. Press x twice to exit. ");



getch();




    position(10,8);
    printf("                                                          "); // clear game over text
    position(9,3);
    printf("     "); // score clear


    ////////////////////////////////

    }

yellow();
    print_obstacle(x);
reset_color();


    x++;
    if(x==69) // if osbatcle has passed has new has appeared
    {
    x=0;
    score++;

    //////////////// Score Update
    position(9,3);
    printf("     ");
    position(9,3);
    printf("%d",score);
    /////////////////

    //if(speed>20) // jati nakij audai garxa teti speed badxa
      //  speed--;
    }

}

void Dino_Game_Home(char *username)
{

    char input;
    int i;


    Dino_Game_Main_Display(username);

    while(true) //// show dinosaur, osbactle and score infinite times
    {
        while(!kbhit()) //// if a keywboard is not hit, it runs infinite time
        {
            ds();
            obstacle_touch_check(username);
        }

        input=getch();

        if(input==' ') // Space Button Jump Garxa
        {


            //// dinosaur goes up
            for(i=0;i<10;i++)
            {
            ds(1);
            obstacle_touch_check(username);
            }

            ////dinosaur comes down
            for(i=0;i<10;i++)
            {
            ds(2);
            obstacle_touch_check(username);
            }
        }
        else if (input=='x')  // x for exit
return;
    }

}

int main()
{
start:

system("cls");

char main_input;


printf("\n\t\t\t Krishna | Manoj | Nabin | Sanjiv\n\n");

printf("\n\n\t\t*************STAY HOME, ENJOY GAME************\n\n");

printf("\t\t===========WELCOME TO THE DINO GAME===========\n\n");

menu();




 goto start;





printf("\n\nThank You for playing game!");
getch();
}




