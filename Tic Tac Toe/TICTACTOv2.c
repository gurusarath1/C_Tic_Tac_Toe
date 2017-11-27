#include<stdio.h>
#include<conio.h>

//tic tac toe game v2.0
//By T.Guru Sarath EC B

int printf_board(char board[3][3]);
int win_check(char board[3][3]);

int main()
{
int i,j,rowin,colin,X,count,win,PLAY_AGAIN;
char board[3][3],name[15],c;
FILE *fp;

do {

// Variable init

printf("\n>Initializing variables . . . . . . . . ");

X = 1;
count= 0;
win = 0;
PLAY_AGAIN = 0;

// initialising board
for(i=0 ; i<3 ; i++)
{
for(j=0 ; j<3 ; j++)
board[i][j] = '.';
}

// initial board print
printf_board(board);

while(count < 9  && win == 0){


	if(X)printf("\n X's turn\n");
	else printf("\n O's turn\n");

//Input

	printf("\nRow ? - ");
	if(scanf("%d",&rowin)){;}else{printf("\n\n\n\n	>Invalid Input Not Tolerated :( Emergency exit\a\a\a\n	>Program Failed"); getch(); return 0;}
	printf("Column ? - ");
	if(scanf("%d",&colin)){;}else{printf("\n\n\n\n	>Invalid Input Not Tolerated :( Emergency exit\a\a\a\n	>Program Failed"); getch(); return 0;}
	rowin-- ; colin-- ;


// Input Validity check

if(board[rowin][colin] == '.')
{
	if(X)
	{ board[rowin][colin] = 'X'; X = 0; }
	else
	{ board[rowin][colin] = 'O'; X = 1; }

	count++;

}else{printf(" \n ********* Entry already taken :( *********\a\a\a");getch();}




	//printf new board
	
	printf_board(board);

	printf("\a");

//win check

win = win_check(board);



// while count
}

if(win == 1)
	printf("\n   X WINS !!!!    \a\a\a\a\a\a");
	
else if(win == 2)
	printf("\n   O WINS !!!!    \a\a\a\a\a\a");
else 
	printf("\n   Tie Match !!!!    ");

getch();


if(win == 1 || win == 2)
{
	printf("\n\n\t Enter Your NAme -- ");
	scanf("%s",name);

	if((fp = fopen("score.txt","a")) == NULL) {printf("Cannot open file");}
	
	fprintf(fp,"%s  Won with %c \n",name,(win == 1)? 'X':'O');
	
	fclose(fp);
}


	system("cls");
	fp = fopen("score.txt","r");
	
	while((fscanf(fp,"%c",&c)) == 1)
	printf("%c",c);
	
	fclose(fp);







printf("\n\n\n\t Game programmed by T.Guru Sarath ECE - B 2nd Sem");


printf("\n\n\n        Play Again ??? 1(yes)/0(no)       > ");

if(scanf("%d",&PLAY_AGAIN)){;}else{printf("\n\n\n\n	>Invalid Input Not Tolerated :( Emergency exit\a\a\a\n	>Program Failed"); getch(); return 0;}

}

while (PLAY_AGAIN);







getch();
return 0;
}


// Board Print function

	int printf_board(char board[3][3]){

	int i,j;
	system("cls");
	printf("\nTIC TAC TO v2.0\n\n");
		for(i=0 ; i<3 ; i++)
			{
				for(j=0 ; j<3 ; j++)
				printf(" %c ",board[i][j]);
				printf("\n\n");
			}

	}

// Win Check function

int win_check(char board[3][3]){

int i,j;

for(i = 0; i<3 ; i++)
{
if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') return(1);
else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') return(2);
}

for(i = 0; i<3 ; i++)
{
if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') return(1);
else if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') return(2);
}

if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return(1);
else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return(2);

if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return(1);
else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return(2);

return 0;

}












// Hare Krishna