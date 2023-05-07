/**********************
**Rantses Vinse
**AM:2022201900196
**dit19196@uop.gr
**
**Alexandropoulos Ilias
**AM:2022201900007
**dit19007@uop.gr
***********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//ORIA DIASTASEWN TAMPLOU
#define minN 4
#define minM 5
#define maxN 10
#define maxM 10 

//SYNARTISEIS
void time_sleep (double secs);
void tamplo(int *n, int *m, int epipedo, int *exthroi);//Gemisma tamplou
void enemies(int n, int m, int nMAX, int mMAX, int rng, int exthroi);//TOPOTHETISH EXTHRWN TYXAIA ME ANADROMH (BONUS)
void emfanisi_tamplou(int *n, int *m, int money);//Emfanisi tamplou
void pista(int *n, int *m, int epipedo, char *move, char *move_palio, int *knight, int *money, int *exthroi);//Allagi pistas
void attack(int *n, int *m, char *move, char *move_palio, int epipedo, int *knight, int *money, int *exthroi);//Epitheseis ippoth
void movement(int *n, int *m, char *move, char *move_palio, int epipedo, int *knight, int *money, int *exthroi);//Kinish ippoth
void epilogi(int *n, int *m, int epipedo, char *move, char *move_palio, int *knight, int *money, int *exthroi);//Epilogh energeias(kinish h' epithesh) 

int **arr, end = 0;

int main(void)
{
	srand(time(NULL));
	char clear[2], move[3], move_palio[3];
	int i, j, n, m, epipedo, money = 0, knight[2], exthroi, rng_move;
	rng_move = 1 + rand()%4;
	if( rng_move == 1 )
		move_palio[0] = 'u';
	else if( rng_move == 2)
		move_palio[0] = 'r';
	else if( rng_move == 3 )
		move_palio[0] = 'd';
	else
		move_palio[0] = 'l';
	printf("\033[0;33m");
	printf("Welcome to StingyKnight\n\n");
	printf("\033[0m");
	time_sleep(2);
	do{
		printf("Dwse plhthos grammwn:\n");
		scanf("%d", &n);
	}while( n < 4 || n > 10 );

	do{
		printf("Dwse plhthos sthlwn:\n");
		scanf("%d", &m);
	}while( m < 5 || m > 10); 
	
	//MENU 
	printf("##############\n# 1) Eukolo  #\n# 2) Metrio  #\n# 3) Dyskolo #\n##############\n");
	do{	
		printf("Epileje ena apo ta parapanw 1-3:\n");
		scanf("%d", &epipedo);
	}while( epipedo < 1 || epipedo > 3);
	fgets( clear, sizeof(clear), stdin);
	printf("\n\nPerimenete...\n\n");
	time_sleep(1.5);

	//GEMISMA TAMPLOU 	
	tamplo(&n, &m, epipedo, &exthroi);

	//EURESH THESIS IPPOTH
	for(i = 0; i < n; i -= -1)
	{
		for(j = 0; j < m; j++)
			if( arr[i][j] == '$' )
			{
				knight[0] = i;
				knight[1] = j;
				break;
			}
		if( arr[i][j] == '$')
			break;
	}
	do{
		//EMFANISH TAMPLOU
		emfanisi_tamplou(&n, &m, money);

		//EISAGWGH EPILOGIS
		epilogi(&n, &m, epipedo, move, move_palio,knight, &money, &exthroi);
	}while( end != 1);
	printf("Developed by ");
	printf("\033[1;36m");
	printf("L0uSg3");
	printf("\033[0m");
	printf(" and ");
	printf("\033[1;31m");
	printf("TheHueMaster");
	printf("\033[0m");	
	printf("!!\n\nExiting...\n");
	time_sleep(2);
	return 0;
}

void time_sleep (double secs) 
{
	int kathisterish;	
	kathisterish = time(NULL) + secs;  
	while( time(NULL) < kathisterish );
}

void tamplo(int *n, int *m, int epipedo, int *exthroi)
{
	int i, j, empodia, rng, rng2, grammh, sthlh, flag = 0;
	double temp;//TEMP == EXTHROI

	//DYNAMIKH DESMEUSH MNHMHS
	arr = (int **)malloc( *n * sizeof(int *) );
	for( i = 0; i < *n; i++)
		arr[i] = (int *)malloc( *m * sizeof(int) );
	for( i = 0; i < *n; i++)
		for( j = 0; j < *m; j++)
			arr[i][j] ='.';
	//YPOLOGISMOS POSOSTWN EMPODIWN/EXTHRWN
	empodia = *n * *m * 0.05;		
	if( epipedo == 1)
		temp = *n * *m * 0.05;
	else if( epipedo == 2)
		temp = *n * *m * 0.1;
	else
	{
		empodia = *n * *m * 0.1;
		temp = *n * *m * 0.1;
	}
	if( temp - (int)temp > 0 ) 
		temp++;
	*exthroi = (int)temp;
	
	//Arxikopoihsh 1ou exthrou
	grammh = rand()%(*n);
	sthlh = rand()%(*m);
	arr[grammh][sthlh] = 1 + rand()%3 + '0';
	(*exthroi)--;
	enemies(grammh, sthlh, *n, *m, 1+rand()%4, *exthroi);
	do{
		do{
			grammh = rand()%(*n);
			sthlh = rand()%(*m);
		}while( arr[grammh][sthlh] != '.' );
		arr[grammh][sthlh] = '#';
		empodia --;
	}while( empodia != 0 );
	do{
		grammh = rand()%(*n);
		sthlh = rand()%(*m);
	}while( arr[grammh][sthlh] != '.' );
	arr[grammh][sthlh] = '$';
	*exthroi = temp;
	return;
}
void enemies(int n, int m, int nMAX, int mMAX, int rng, int exthroi)
{
	int i, j;
	if(exthroi == 0)
		return;
	else//TOPOTHETHSH EXTHRWN TYXAIA
	{
		if( rng == 1 && m-1 >= 0 && arr[n][m-1] == '.')//ARISTERA
		{
			arr[n][m-1] = 1+rand()%3 + '0';
			enemies(n, m-1, nMAX, mMAX, 1+rand()%4, exthroi-1);
		}
		else if( rng == 2 && n - 1 >= 0 && arr[n-1][m] == '.')//PANW
		{
			arr[n-1][m] = 1+rand()%3 + '0';
			enemies(n-1, m, nMAX, mMAX, 1+rand()%4, exthroi-1);
		}
		else if( rng == 3 && m+1<=mMAX-1 && arr[n][m+1] == '.')//DEJIA
		{
			arr[n][m+1] = 1+rand()%3 + '0';
			enemies(n, m+1, nMAX, mMAX, 1+rand()%4, exthroi-1);
		}
		else if( rng == 4 && n+1 <=nMAX-1  && arr[n+1][m] == '.')//KATW
		{
			arr[n+1][m] = 1+rand()%3 + '0';
			enemies(n+1, m, nMAX, mMAX, 1+rand()%4, exthroi-1);
		}
		else
		{
			do{
				i = rand()%nMAX;
				j = rand()%mMAX;
			}while(arr[i][j] == '.');
			enemies(i, j, nMAX, mMAX, 1+rand()%4, exthroi);
		}
	}
}

void emfanisi_tamplou(int *n, int *m, int money)
{
	int i, j;
	printf("     ");
	for ( i = 0; i < *m; i++)   
		printf("%d ", i+1);
	printf("\n");
	for ( i = 1; i <= *m*2 + 5 ; i++)		
		printf("-");
	printf("\n");
	for( i = 0; i < *n; i++)
	{
		printf("%2d |", i+1);		
		for( j = 0; j < *m; j++)
		{
			if(arr[i][j] >= '1' && arr[i][j] <= '3')
			{
				if(arr[i][j] == '1')
				{
					printf("\033[0;33m");
					printf(" %c", arr[i][j]);
					printf("\033[0m");
				}
				else if(arr[i][j] == '2')
				{
					printf("\033[1;31m");
					printf(" %c", arr[i][j]);
					printf("\033[0m");
				}
				else
				{
					printf("\033[0;35m");
					printf(" %c", arr[i][j]);
					printf("\033[0m");
				}
			}
			else if( arr[i][j] == '$' )
			{
					printf("\033[0;36m");
					printf(" %c", arr[i][j]);
					printf("\033[0m");
			}
			else if( arr[i][j] == '#' )
			{
					printf("\033[0;32m");
					printf(" %c", arr[i][j]);
					printf("\033[0m");
			}
			else
				printf(" %c", arr[i][j]);
		}
		printf("\n");
	}
}

void epilogi(int *n, int *m, int epipedo, char *move, char *move_palio, int *knight, int *money, int *exthroi)
{
	printf("Level money spent: %d\nGame money spent: %d\nMake your move: ", *money, *money); 		
	fgets(move, sizeof(move), stdin);
	printf("\n");	
	move[2] = '\0';
	if( move[0] == 'X' || move[0] == 'x' )
	{
		end = 1;		
		return;
	}
	if( move[0] == 'U' || move[0] == 'u' || move[0] == 'R' || move[0] == 'r' || move[0] == 'D' || move[0] == 'd' || move[0] == 'L' || move[0] == 'l' )
	{
		while( move[1] < '1' || move[1] > '9' )
		{
			printf("Level money spent: %d\nGame money spent: %d\nMake your move: ", *money, *money); 		
			fgets(move, sizeof(move), stdin);
			printf("\n");	
			move[2] = '\0';	
		}
		move_palio[0] = move[0];
		move_palio[1] = move[1];
		movement(n, m, move, move_palio, epipedo, knight, money, exthroi);	
	}
	else if ( move[0] == 'F' || move[0] == 'f' || move[0] == 'A' || move[0] == 'a' || move[0] == 'S' || move[0] == 's' || move[0] == 'B' || move[0] == 'b' || move[0] == 'M' || move[0] == 'm' )
	{
		move[1] = '\0';		
		attack(n, m, move, move_palio, epipedo, knight, money, exthroi);
	}
	return;
}

void pista(int *n, int *m, int epipedo, char *move, char *move_palio, int *knight, int *money, int *exthroi)
{
	int i, rng_move;
	if(*n + 1 > maxN || *m + 1 > maxM)
	{
		emfanisi_tamplou(n, m, *money);
		//APELEUTHERWSH MNHMHS
		for(i=0; i < *n; i++)
			free(arr[i]);
		free(arr);
		printf("\033[0;33m");
		printf("Mpravo termatises to epipedo!\n");
		printf("\033[0m");	
		time_sleep(2);
		end = 1;
		return;
	}
	else
	{
		//APELEUTHERWSH MNHMHS
		for(i=0; i < *n; i++)
			free(arr[i]);
		free(arr);	
		(*n)++;
		(*m)++;
		rng_move = 1 + rand()%4;
		if( rng_move == 1 )
			move_palio[0] = 'u';
		else if( rng_move == 2)
			move_palio[0] = 'r';
		else if( rng_move == 3 )
			move_palio[0] = 'd';
		else
			move_palio[0] = 'l';
		tamplo(n, m, epipedo, exthroi);
		emfanisi_tamplou(n, m, *money);
		epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
	}
	return;
}

void attack(int *n, int *m, char *move, char *move_palio, int epipedo, int *knight, int *money, int *exthroi)
{
	int i, j, temp;
	//EURESH THESIS IPPOTH
	for(i = 0; i < *n; i ++)
	{
		for(j = 0; j < *m; j++)
			if( arr[i][j] == '$' )
			{
				knight[0] = i;
				knight[1] = j;
				break;
			}
		if( arr[i][j] == '$')
			break;
	}
	if( move[0] == 'F' || move[0] == 'f')//MPOUNIA/KATRAPAKIA/MPOUKETO
	{
		if( move_palio[0] == 'U' || move_palio[0] == 'u')//PANW MPOUNIA
		{
			if( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') )
			{
				arr[knight[0]-1][knight[1]] -= 1;
				if( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] == '0') )
				{
					arr[knight[0]-1][knight[1]] = '.';
					*money += 50;
					(*exthroi)--;
				}
				else if( (knight[0] - 1 >= 0) && (knight[0] - 2 >= 0) && (arr[knight[0] - 2][knight[1]] == '.') )
				{
					temp = arr[knight[0] - 2][knight[1]];
					arr[knight[0] - 2][knight[1]] = arr[knight[0]-1][knight[1]];
					arr[knight[0]-1][knight[1]] = temp;
					*money += 50;				
				}
				else
					*money += 50;
			}
		}
		if( move_palio[0] == 'R' || move_palio[0] == 'r' )//DEJIA MPOUNIA 
		{
			if( ( knight[1] + 1 <= *m-1 ) && (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') )
			{	
				arr[knight[0]][knight[1]+1] -= 1;
				if( ( knight[1] + 1 <= *m-1 ) && ( arr[knight[0]][knight[1]+1] == '0') )
				{
					arr[knight[0]][knight[1]+1] = '.';
					*money += 50;
					(*exthroi)--;
				}
				else if( ( knight[1] + 1 <= *m - 1  ) && ( knight[1] + 2 <= *m-1 ) && (arr[knight[0]][knight[1]+2] == '.') )
				{	
					temp = arr[knight[0]][knight[1]+2];
					arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+1];
					arr[knight[0]][knight[1]+1] = temp;
					*money += 50;
				}
				else
					*money += 50;
			}
		}
		if( move_palio[0] == 'D' || move_palio[0] == 'd')//KATW MPOUNIA	
		{
			if( (knight[0] + 1 < *n) && (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') )
			{
				arr[knight[0]+1][knight[1]] -= 1;
				if( (knight[0] + 1 < *n) && (arr[knight[0]+1][knight[1]] == '0') )
				{
					arr[knight[0]+1][knight[1]] = '.';
					*money += 50;
					(*exthroi)--;
				}
				else if( (knight[0] + 1 < *n) && (knight[0] + 2 < *n) && (arr[knight[0] + 2][knight[1]] == '.') )
				{
					temp = arr[knight[0] + 2][knight[1]];
					arr[knight[0] + 2][knight[1]] = arr[knight[0]+1][knight[1]];
					arr[knight[0]+1][knight[1]] = temp;
					*money += 50;				
				}
				else
					*money += 50;
			}
		}
		if( move_palio[0] == 'L' || move_palio[0] == 'l' )//ARISTERA MPOUNIA
		{
			if( ( knight[1] - 1 >= 0 ) && (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') )
			{
				arr[knight[0]][knight[1]-1] -= 1;
				if( ( knight[1] - 1 >= 0 ) && ( arr[knight[0]][knight[1]-1] == '0') )
				{
					arr[knight[0]][knight[1]-1] = '.';
					*money += 50;
					(*exthroi)--;
				}
				else if( ( knight[1] - 1 >= 0 ) && ( knight[1] - 2 >= 0 ) && (arr[knight[0]][knight[1]-2] == '.') )
				{	
					temp = arr[knight[0]][knight[1]-2];
					arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-1];
					arr[knight[0]][knight[1]-1] = temp;
					*money += 50;
				}
				else
					*money += 50;
			}
		}		
	}
	if( move[0] == 'A' || move[0] == 'a')//AXE KOINWS TSEKOURIA
	{
		if( move_palio[0] == 'U' || move_palio[0] == 'u' )// PANW 
		{
			if( ( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') ) || ( (knight[0] - 2 >= 0) && (arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3') ) )
				*money += 70;		
			if( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') )//YPARXEI 1os
			{	
				arr[knight[0]-1][knight[1]] -= 1;
				if( arr[knight[0]-1][knight[1]] == '0')
				{
					arr[knight[0]-1][knight[1]] ='.';
					(*exthroi)--;
				}
			}			
			if( (knight[0] - 2 >= 0) && (arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3') )//YPARXEI 2os
			{
				arr[knight[0]-2][knight[1]] -= 1;
				if( arr[knight[0]-2][knight[1]] == '0' )
				{
					arr[knight[0]-2][knight[1]] = '.';
					(*exthroi)--;
				}
			}
			if( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') )
			{
				if( (knight[0] - 2 >= 0) && ( arr[knight[0]-2][knight[1]] == '.') )//YPARXEI 1os KAI 2os = KENO = '.'
				{
					temp = arr[knight[0]-2][knight[1]];
					arr[knight[0]-2][knight[1]] = arr[knight[0]-1][knight[1]];
					arr[knight[0]-1][knight[1]] = temp;
				}
				else if( (knight[0] - 2 >= 0) && (arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3') )//YPARXEI 1os KAI O 2os EINAI EXTHROS
				{
					if( (knight[0] - 3 >= 0) && (arr[knight[0]-3][knight[1]] == '.') )
					{
						//ANTIMETATHESH 3ou ME 2ou 
						temp = arr[knight[0]-2][knight[1]];
						arr[knight[0]-2][knight[1]] = arr[knight[0]-3][knight[1]];
						arr[knight[0]-3][knight[1]] = temp;
						//ANTIMETATHESH 2ou ME 1o
						temp = arr[knight[0]-2][knight[1]];
						arr[knight[0]-2][knight[1]] = arr[knight[0]-1][knight[1]];
						arr[knight[0]-1][knight[1]] = temp;
					}
				}
			}
			else if( (knight[0] - 1 >= 0) && (arr[knight[0]-1][knight[1]] == '.') && (knight[0] - 2 >= 0) && (arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3') )
			{
				//YPARXEI 2os KAI OXI PRWTOS 
				if( (knight[0] - 3 >= 0) && (arr[knight[0]-3][knight[1]] == '.') )
				{
					temp = arr[knight[0]-2][knight[1]];
					arr[knight[0]-2][knight[1]] = arr[knight[0]-3][knight[1]];
					arr[knight[0]-3][knight[1]] = temp;			
				}
			}	
		}
		if( move_palio[0] == 'R' || move_palio[0] == 'r' )// DEJIA 
		{
			if( ( (knight[1] + 1 <= *m-1) && (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') ) || ( (knight[1] + 2 <= *m - 1) && (arr[knight[0]][knight[1]+ 2] >= '1' && arr[knight[0]][knight[1]+2] <= '3') ) )	
				*money += 70;
			if( (knight[1] + 1 <= *m-1) && (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') )//YPARXEI 1os
			{	
				arr[knight[0]][knight[1]+1] -= 1;
				if( arr[knight[0]][knight[1]+1] == '0')
				{
					arr[knight[0]][knight[1]+1] ='.';
					(*exthroi)--;
				}
			}
			if( (knight[1] + 2 <= *m-1) && (arr[knight[0]][knight[1]+2] >= '1' && arr[knight[0]][knight[1]+2] <= '3') )//YPARXEI 2os
			{
				arr[knight[0]][knight[1]+2] -= 1;
				if( arr[knight[0]][knight[1]+2] == '0' )
				{
					arr[knight[0]][knight[1]+2] = '.';
					(*exthroi)--;
				}
			}
			if( (knight[1] + 1 <= *m-1) && (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') )
			{
				if( (knight[1] + 2 <= *m-1) && ( arr[knight[0]][knight[1]+2] == '.') )//YPARXEI 1os KAI 2os = KENO = '.'
				{
					temp = arr[knight[0]][knight[1]+2];
					arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+1];
					arr[knight[0]][knight[1]+1] = temp;
				}
				else if( (knight[1] + 2 <= *m-1) && (arr[knight[0]][knight[1]+2] >= '1' && arr[knight[0]][knight[1]+2] <= '3') )//YPARXEI 1os KAI O 2os EINAI EXTHROS
				{
					if( (knight[1] + 3 <= *m-1) && (arr[knight[0]][knight[1]+3] == '.') )
					{
						//ANTIMETATHESH 3ou ME 2ou 
						temp = arr[knight[0]][knight[1]+3];
						arr[knight[0]][knight[1]+3] = arr[knight[0]][knight[1]+2];
						arr[knight[0]][knight[1]+2] = temp;
						//ANTIMETATHESH 2ou ME 1o
						temp = arr[knight[0]][knight[1]+2];
						arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+1];
						arr[knight[0]][knight[1]+1] = temp;
					}
				}
			}
			else if( (knight[1] + 1 <= *m-1) && (arr[knight[0]][knight[1]+1] == '.') && (knight[1] + 2 <= *m-1) && (arr[knight[0]][knight[1]+2] >= '1' && arr[knight[0]][knight[1]+2] <= '3') )
			{
				//YPARXEI 2os KAI OXI PRWTOS 
				if( (knight[1] + 3 <= *m-1) && (arr[knight[0]][knight[1]+3] == '.') )
				{
					temp = arr[knight[0]][knight[1]+2];
					arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+3];
					arr[knight[0]][knight[1]+3] = temp;			
				}
			}	
		}
		if( move_palio[0] == 'D' || move_palio[0] == 'd' )// KATW	
		{
			if( ( (knight[0] + 1 <= *n-1) && (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') ) || ( (knight[0] + 2 <= *n-1) && (arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3') ) )
				*money += 70;		
			if( (knight[0] + 1 <= *n-1) && (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') )//YPARXEI 1os EXTHROS
			{	
				arr[knight[0]+1][knight[1]] -= 1;
				if( arr[knight[0]+1][knight[1]] == '0')
				{
					arr[knight[0]+1][knight[1]] ='.';
					(*exthroi)--;
				}
			}			
			if( (knight[0] + 2 <= *n-1) && (arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3') )//YPARXEI 2os EXTHROS
			{
				arr[knight[0]+2][knight[1]] -= 1;
				if( arr[knight[0]+2][knight[1]] == '0' )
				{
					arr[knight[0]+2][knight[1]] = '.';
					(*exthroi)--;
				}
			}
			if( (knight[0] + 1 <= *n-1) && (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') )
			{
				if( (knight[0] + 2 <= *n-1) && ( arr[knight[0]+2][knight[1]] == '.') )//YPARXEI 1os KAI 2os = KENO = '.'
				{
					temp = arr[knight[0]+1][knight[1]];
					arr[knight[0]+1][knight[1]] = arr[knight[0]+2][knight[1]];
					arr[knight[0]+2][knight[1]] = temp;
				}
				else if( (knight[0] + 2 <= *n-1) && (arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3') )//YPARXEI 1os KAI O 2os EINAI EXTHROS
				{
					if( (knight[0] + 3 <= *n-1) && (arr[knight[0]+3][knight[1]] == '.') )
					{
						//ANTIMETATHESH 3ou ME 2ou 
						temp = arr[knight[0]+2][knight[1]];
						arr[knight[0]+2][knight[1]] = arr[knight[0]+3][knight[1]];
						arr[knight[0]+3][knight[1]] = temp;
						//ANTIMETATHESH 2ou ME 1o
						temp = arr[knight[0]+2][knight[1]];
						arr[knight[0]+2][knight[1]] = arr[knight[0]+1][knight[1]];
						arr[knight[0]+1][knight[1]] = temp;
					}
				}
			}
			else if( (knight[0] + 1 <= *n-1) && (arr[knight[0]+1][knight[1]] == '.') && (knight[0] + 2 <= *n-1) && (arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3') )
			{
				//YPARXEI 2os KAI OXI PRWTOS 
				if( (knight[0] + 3 <= *n-1) && (arr[knight[0]+3][knight[1]] == '.') )
				{
					temp = arr[knight[0]+2][knight[1]];
					arr[knight[0]+2][knight[1]] = arr[knight[0]+3][knight[1]];
					arr[knight[0]+3][knight[1]] = temp;			
				}
			}	
		}
		if( move_palio[0] == 'L' || move_palio[0] == 'l' )// ARISTERA 
		{
			if( ( (knight[1] - 1 >= 0) && (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') ) || ( (knight[1] - 2 >= 0) && (arr[knight[0]][knight[1]- 2] >= '1' && arr[knight[0]][knight[1]-2] <= '3') ) )	
				*money += 70;
			if( (knight[1] - 1 >= 0) && (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') )//YPARXEI 1os
			{	
				arr[knight[0]][knight[1]-1] -= 1;
				if( arr[knight[0]][knight[1]-1] == '0')
				{
					arr[knight[0]][knight[1]-1] ='.';
					(*exthroi)--;
				}
			}
			if( (knight[1] - 2 >= 0) && (arr[knight[0]][knight[1]-2] >= '1' && arr[knight[0]][knight[1]-2] <= '3') )//YPARXEI 2os
			{
				arr[knight[0]][knight[1]-2] -= 1;
				if( arr[knight[0]][knight[1]-2] == '0' )
				{
					arr[knight[0]][knight[1]-2] = '.';
					(*exthroi)--;
				}
			}
			if( (knight[1] - 1 >= 0) && (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') )
			{
				if( (knight[1] - 2 >= 0) && ( arr[knight[0]][knight[1]-2] == '.') )//YPARXEI 1os KAI 2os = KENO = '.'
				{
					temp = arr[knight[0]][knight[1]-2];
					arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-1];
					arr[knight[0]][knight[1]-1] = temp;
				}
				else if( (knight[1] - 2 >= 0) && (arr[knight[0]][knight[1]-2] >= '1' && arr[knight[0]][knight[1]-2] <= '3') )//YPARXEI 1os KAI O 2os EINAI EXTHROS
				{
					if( (knight[1] - 3 >= 0) && (arr[knight[0]][knight[1]-3] == '.') )
					{
						//ANTIMETATHESH 3ou ME 2ou 
						temp = arr[knight[0]][knight[1]-3];
						arr[knight[0]][knight[1]-3] = arr[knight[0]][knight[1]-2];
						arr[knight[0]][knight[1]-2] = temp;
						//ANTIMETATHESH 2ou ME 1o
						temp = arr[knight[0]][knight[1]-2];
						arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-1];
						arr[knight[0]][knight[1]-1] = temp;
					}
				}
			}
			else if( (knight[1] - 1 >= 0) && (arr[knight[0]][knight[1]-1] == '.') && (knight[1] - 2 >= 0) && (arr[knight[0]][knight[1]-2] >= '1' && arr[knight[0]][knight[1]-2] <= '3') )
			{
				//YPARXEI 2os KAI OXI PRWTOS 
				if( (knight[1] - 3 >= 0) && (arr[knight[0]][knight[1]-3] == '.') )
				{
					temp = arr[knight[0]][knight[1]-2];
					arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-3];
					arr[knight[0]][knight[1]-3] = temp;			
				}
			}	
		}			
	}
	if( move[0] == 'S' || move[0] == 's')//SWORD AKA XARAKIAAA
	{
		if( move_palio[0] == 'U' || move_palio[0] == 'u' )// PANW 
		{
			if(knight[0] - 1 >= 0)
			{
				if( (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') || ( knight[1]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3') || ( knight[1]+1 <= *m-1 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3') )
				{
					*money += 80;
				}
				if( arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3' )// AN YPARXEI PANW EXTHROS
				{
					arr[knight[0]-1][knight[1]] -= 1;
					if( arr[knight[0]-1][knight[1]] == '0' )
					{
						arr[knight[0]-1][knight[1]] = '.';
						*exthroi -= 1;
					}
				}
				if( knight[1]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3' )// AN YPARXEI PANW ARISTERA EXTHROS
				{
					arr[knight[0]-1][knight[1]-1] -= 1;
					if( arr[knight[0]-1][knight[1]-1] == '0' )
					{
						arr[knight[0]-1][knight[1]-1] = '.';
						*exthroi -= 1;
					}				
				}
				if(  knight[1]+1 <= *m-1 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3')// AN YPARXEI PANW DEJIA EXTHROS
				{
					arr[knight[0]-1][knight[1]+1] -= 1;
					if( arr[knight[0]-1][knight[1]+1] == '0' )
					{
						arr[knight[0]-1][knight[1]+1] = '.';
						*exthroi -= 1;
					}
				}
				if( (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3')  && ( knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]] == '.') )
				// PANW EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]-1][knight[1]];
					arr[knight[0]-1][knight[1]] = arr[knight[0]-2][knight[1]];
					arr[knight[0]-2][knight[1]] = temp;
				}
				if( knight[1]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3' && (knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]-1] == '.' ) )
				//PANW ARISTERA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]-1][knight[1]-1];
					arr[knight[0]-1][knight[1]-1] = arr[knight[0]-2][knight[1]-1];
					arr[knight[0]-2][knight[1]-1] = temp;
				}
				if( knight[1]+1 <= *m-1 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3' && ( knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]+1] == '.' ) )
				//PANW DEJIA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]-1][knight[1]+1];
					arr[knight[0]-1][knight[1]+1] = arr[knight[0]-2][knight[1]+1];
					arr[knight[0]-2][knight[1]+1] = temp;
				}
			}		
		}
		if( move_palio[0] == 'R' || move_palio[0] == 'r' )// DEJIA
		{
			if( knight[1] + 1 <= *m -1)
			{
				if( (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3')||(knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3')||(knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3') )
				{
					*money += 80;
				}
				if( arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3' )// AN YPARXEI PANW EXTHROS
				{
					arr[knight[0]][knight[1]+1] -= 1;
					if( arr[knight[0]][knight[1]+1] == '0' )
					{
						arr[knight[0]][knight[1]+1] = '.';
						*exthroi -= 1;
					}
				}
				if( knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3' )// AN YPARXEI PANW ARISTERA EXTHROS
				{
					arr[knight[0]-1][knight[1]+1] -= 1;
					if( arr[knight[0]-1][knight[1]+1] == '0' )
					{
						arr[knight[0]-1][knight[1]+1] = '.';
						*exthroi -= 1;
					}				
				}
				if(  knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3')// AN YPARXEI PANW DEJIA EXTHROS
				{
					arr[knight[0]+1][knight[1]+1] -= 1;
					if( arr[knight[0]+1][knight[1]+1] == '0' )
					{
						arr[knight[0]+1][knight[1]+1] = '.';
						*exthroi -= 1;
					}
				}
				if( (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3')  && ( knight[1]+ 2 <= *m-1 && arr[knight[0]][knight[1]+2] == '.') )
				// PANW EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]][knight[1]+1];
					arr[knight[0]][knight[1]+1] = arr[knight[0]][knight[1]+2];
					arr[knight[0]][knight[1]+2] = temp;
				}
				if( (knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3') && ( knight[1]+2 <= *m-1 && arr[knight[0]-1][knight[1]+2] == '.' ) )
				//PANW ARISTERA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]-1][knight[1]+1];
					arr[knight[0]-1][knight[1]+1] = arr[knight[0]-1][knight[1]+2];
					arr[knight[0]-1][knight[1]+2] = temp;
				}
				if( knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3' && ( knight[1]+2 <= *m-1 && arr[knight[0]+1][knight[1]+2] == '.' ) )
				//PANW DEJIA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]+1][knight[1]+1];
					arr[knight[0]+1][knight[1]+1] = arr[knight[0]+1][knight[1]+2];
					arr[knight[0]+1][knight[1]+2] = temp;
				}
			}		
		}
		if( move_palio[0] == 'D' || move_palio[0] == 'd' )// KATW
		{
			if( knight[0] + 1 <= *n-1 )
			{
				if( (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') || ( knight[1]+1 <= *m-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3') || ( knight[1]-1 >= 0 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3') )
				{
					*money += 80;
				}
				if( arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3' )// AN YPARXEI KATW EXTHROS
				{
					arr[knight[0]+1][knight[1]] -= 1;
					if( arr[knight[0]+1][knight[1]] == '0' )
					{
						arr[knight[0]+1][knight[1]] = '.';
						*exthroi -= 1;
					}
				}
				if( knight[1]-1 >= 0 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3' )// AN YPARXEI KATW ARISTERA EXTHROS
				{
					arr[knight[0]+1][knight[1]-1] -= 1;
					if( arr[knight[0]+1][knight[1]-1] == '0' )
					{
						arr[knight[0]+1][knight[1]-1] = '.';
						*exthroi -= 1;
					}				
				}
				if(  knight[1]+1 <= *m-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3')// AN YPARXEI KATW DEJIA EXTHROS
				{
					arr[knight[0]+1][knight[1]+1] -= 1;
					if( arr[knight[0]+1][knight[1]+1] == '0' )
					{
						arr[knight[0]+1][knight[1]+1] = '.';
						*exthroi -= 1;
					}
				}
				if( (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3')  && ( knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]] == '.') )
				// KATW EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]+1][knight[1]];
					arr[knight[0]+1][knight[1]] = arr[knight[0]+2][knight[1]];
					arr[knight[0]+2][knight[1]] = temp;
				}
				if( knight[1]-1 >= 0 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3' && (knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]-1] == '.' ) )
				//KATW ARISTERA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]+1][knight[1]-1];
					arr[knight[0]+1][knight[1]-1] = arr[knight[0]+2][knight[1]-1];
					arr[knight[0]+2][knight[1]-1] = temp;
				}
				if( knight[1]+1 <= *m-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3' && ( knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]+1] == '.' ) )
				//KATW DEJIA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]+1][knight[1]+1];
					arr[knight[0]+1][knight[1]+1] = arr[knight[0]+2][knight[1]+1];
					arr[knight[0]+2][knight[1]+1] = temp;
				}
			}
		}
		if( move_palio[0] == 'L' || move_palio[0] == 'l' )
		{
			if( knight[1] - 1 >= 0)
			{
				if( (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3')||(knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3')||(knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3') )
				{
					*money += 80;
				}
				if( arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3' )// AN YPARXEI ARISTERA EXTHROS
				{
					arr[knight[0]][knight[1]-1] -= 1;
					if( arr[knight[0]][knight[1]-1] == '0' )
					{
						arr[knight[0]][knight[1]-1] = '.';
						*exthroi -= 1;
					}
				}
				if( knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3' )// AN YPARXEI ARISTERA PANW EXTHROS
				{
					arr[knight[0]-1][knight[1]-1] -= 1;
					if( arr[knight[0]-1][knight[1]-1] == '0' )
					{
						arr[knight[0]-1][knight[1]-1] = '.';
						*exthroi -= 1;
					}				
				}
				if(  knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3')// AN YPARXEI KATW ARISTERA EXTHROS
				{
					arr[knight[0]+1][knight[1]-1] -= 1;
					if( arr[knight[0]+1][knight[1]-1] == '0' )
					{
						arr[knight[0]+1][knight[1]-1] = '.';
						*exthroi -= 1;
					}
				}
				if( (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3')  && ( knight[1]- 2 >= 0 && arr[knight[0]][knight[1]-2] == '.') )
				// ARISTERA EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]][knight[1]-1];
					arr[knight[0]][knight[1]-1] = arr[knight[0]][knight[1]-2];
					arr[knight[0]][knight[1]-2] = temp;
				}
				if( (knight[0]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3') && ( knight[1]-2 >= 0 && arr[knight[0]-1][knight[1]-2] == '.' ) )
				//ARISTERA PANW EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]-1][knight[1]-1];
					arr[knight[0]-1][knight[1]-1] = arr[knight[0]-1][knight[1]-2];
					arr[knight[0]-1][knight[1]-2] = temp;
				}
				if( knight[0]+1 <= *n-1 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3' && ( knight[1]-2 >= 0 && arr[knight[0]+1][knight[1]-2] == '.' ) )
				//ARISTERA KATW EXTHROS KNOCKBACK
				{
					temp = 	arr[knight[0]+1][knight[1]-1];
					arr[knight[0]+1][knight[1]-1] = arr[knight[0]+1][knight[1]-2];
					arr[knight[0]+1][knight[1]-2] = temp;
				}
			}		
		}			
	}
	if( move[0] == 'B' || move[0] == 'b' )// BOW H ALLIWS TOJO 
	{
		if( move_palio[0] == 'U' || move_palio[0] == 'u' )//PANW 
		{
			if( knight[0] - 2 >= 0 )
			{
				if( arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3')
				{
					arr[knight[0]-2][knight[1]] -= 1;
					if( arr[knight[0]-2][knight[1]] == '0')
					{
						arr[knight[0]-2][knight[1]] = '.';
						*exthroi -= 1;
					}
					*money += 60;
				}
				if( (arr[knight[0]-2][knight[1]] >= '1' && arr[knight[0]-2][knight[1]] <= '3') && (knight[0] - 3 >= 0 && arr[knight[0]-3][knight[1]] == '.') )
				{
					temp = arr[knight[0]-2][knight[1]];
					arr[knight[0]-2][knight[1]] = arr[knight[0]-3][knight[1]];
					arr[knight[0]-3][knight[1]] = temp;
				}
			}
		}
		if( move_palio[0] == 'R' || move_palio[0] == 'r' )// DEJIA 
		{
			if( knight[1] + 2 <= *m-1 )
			{
				if( arr[knight[0]][knight[1]+2] >= '1' && arr[knight[0]][knight[1]+2] <= '3' )
				{
					arr[knight[0]][knight[1]+2] -= 1;
					if( arr[knight[0]][knight[1]+2] == '0' )
					{
						arr[knight[0]][knight[1]+2] = '.';
						*exthroi -= 1;
					}
					*money += 60;
				}
				if( (arr[knight[0]][knight[1]+2] >= '1' && arr[knight[0]][knight[1]+2] <= '3')&&( knight[1] + 3 <= *m-1 && arr[knight[0]][knight[1]+3] == '.') )
				{
					temp =  arr[knight[0]][knight[1]+2];
					arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+3];
					arr[knight[0]][knight[1]+3] = temp;
				}
			}
		}
		if( move_palio[0] == 'D' || move_palio[0] == 'd' )//KATW
		{
			if( knight[0] + 2 <= *n-1 )
			{
				if( arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3')
				{
					arr[knight[0]+2][knight[1]] -= 1;
					if( arr[knight[0]+2][knight[1]] == '0')
					{
						arr[knight[0]+2][knight[1]] = '.';
						*exthroi -= 1;
					}
					*money += 60;
				}
				if( (arr[knight[0]+2][knight[1]] >= '1' && arr[knight[0]+2][knight[1]] <= '3') && (knight[0] + 3 <= *n-1 && arr[knight[0]+3][knight[1]] == '.') )
				{
					temp = arr[knight[0]+2][knight[1]];
					arr[knight[0]+2][knight[1]] = arr[knight[0]+3][knight[1]];
					arr[knight[0]+3][knight[1]] = temp;
				}
			}
		}
		if( move_palio[0] == 'L' || move_palio[0] == 'l' )//ARISTERA 
		{
			if( knight[1] - 2 >= 0 )
			{
				if( arr[knight[0]][knight[1]-2] >= '1' && arr[knight[0]][knight[1]-2] <= '3' )
				{
					arr[knight[0]][knight[1]-2] -= 1;
					if( arr[knight[0]][knight[1]-2] == '0' )
					{
						arr[knight[0]][knight[1]-2] = '.';
						*exthroi -= 1;
					}
					*money += 60;
				}
				if( (arr[knight[0]][knight[1]-2] >= '1' && arr[knight[0]][knight[1]-2] <= '3')&&( knight[1] - 3 >= 0 && arr[knight[0]][knight[1]-3] == '.') )
				{
					temp =  arr[knight[0]][knight[1]-2];
					arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-3];
					arr[knight[0]][knight[1]-3] = temp;
				}
			}
		}
	}
	if( move[0] == 'M' || move[0] == 'm' )//MORNING STAR aka Q darius (BONUS)
	{
		if( (knight[0] -1 >= 0 && (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3') ) || (knight[0] -1 >=0 && knight[1] -1 >= 0 && (arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3'))||( knight[0] -1 >= 0 && knight[1] + 1<= *m-1 && (arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3')) ) 
		{
			*money += 260;
			//260 giati 2 xarakia(panw, katw) + 2 mpounies(aristera, dejia) = 2*80 + 2*50 = 260 	
		}
		else if( knight[1]-1 >= 0 && arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') 
			*money += 260;
		else if( knight[1]+1 <= *m-1 && arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') 
			*money += 260;
		else if( (knight[0] +1 <= *n-1 && (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3') ) || (knight[0] +1 <=*n-1 && knight[1] -1 >= 0 && (arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3'))||( knight[0] +1 <= *n-1 && knight[1] + 1<= *m-1 && (arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3')) ) 
			*money += 260;
		if(knight[0] - 1 >= 0)//PANW 3 EXTHROI
		{
			if( arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3' )// AN YPARXEI PANW EXTHROS
			{
				arr[knight[0]-1][knight[1]] -= 1;
				if( arr[knight[0]-1][knight[1]] == '0' )
				{
					arr[knight[0]-1][knight[1]] = '.';
					*exthroi -= 1;
				}
			}
			if( knight[1]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3' )// AN YPARXEI PANW ARISTERA EXTHROS
			{
				arr[knight[0]-1][knight[1]-1] -= 1;
				if( arr[knight[0]-1][knight[1]-1] == '0' )
				{
					arr[knight[0]-1][knight[1]-1] = '.';
					*exthroi -= 1;
				}				
			}
			if(  knight[1]+1 <= *m-1 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3')// AN YPARXEI PANW DEJIA EXTHROS
			{
				arr[knight[0]-1][knight[1]+1] -= 1;
				if( arr[knight[0]-1][knight[1]+1] == '0' )
				{
					arr[knight[0]-1][knight[1]+1] = '.';
					*exthroi -= 1;
				}
			}
			if( (arr[knight[0]-1][knight[1]] >= '1' && arr[knight[0]-1][knight[1]] <= '3')  && ( knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]] == '.') )
			// PANW EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]-1][knight[1]];
				arr[knight[0]-1][knight[1]] = arr[knight[0]-2][knight[1]];
				arr[knight[0]-2][knight[1]] = temp;
			}
			if( knight[1]-1 >= 0 && arr[knight[0]-1][knight[1]-1] >= '1' && arr[knight[0]-1][knight[1]-1] <= '3' && (knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]-1] == '.' ) )
			//PANW ARISTERA EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]-1][knight[1]-1];
				arr[knight[0]-1][knight[1]-1] = arr[knight[0]-2][knight[1]-1];
				arr[knight[0]-2][knight[1]-1] = temp;
			}
			if( knight[1]+1 <= *m-1 && arr[knight[0]-1][knight[1]+1] >= '1' && arr[knight[0]-1][knight[1]+1] <= '3' && ( knight[0]-2 >= 0 && arr[knight[0]-2][knight[1]+1] == '.' ) )
			//PANW DEJIA EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]-1][knight[1]+1];
				arr[knight[0]-1][knight[1]+1] = arr[knight[0]-2][knight[1]+1];
				arr[knight[0]-2][knight[1]+1] = temp;
			}		
		}	
		if( knight[0] + 1 <= *n-1 )//KATW 3 EXTHROI
		{
			if( arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3' )// AN YPARXEI KATW EXTHROS
			{
				arr[knight[0]+1][knight[1]] -= 1;
				if( arr[knight[0]+1][knight[1]] == '0' )
				{
					arr[knight[0]+1][knight[1]] = '.';
					*exthroi -= 1;
				}
			}
			if( knight[1]-1 >= 0 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3' )// AN YPARXEI KATW ARISTERA EXTHROS
			{
				arr[knight[0]+1][knight[1]-1] -= 1;
				if( arr[knight[0]+1][knight[1]-1] == '0' )
				{
					arr[knight[0]+1][knight[1]-1] = '.';
					*exthroi -= 1;
				}				
			}
			if(  knight[1]+1 <= *m-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3')// AN YPARXEI KATW DEJIA EXTHROS
			{
				arr[knight[0]+1][knight[1]+1] -= 1;
				if( arr[knight[0]+1][knight[1]+1] == '0' )
				{
					arr[knight[0]+1][knight[1]+1] = '.';
					*exthroi -= 1;
				}
			}
			if( (arr[knight[0]+1][knight[1]] >= '1' && arr[knight[0]+1][knight[1]] <= '3')  && ( knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]] == '.') )
			// KATW EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]+1][knight[1]];
				arr[knight[0]+1][knight[1]] = arr[knight[0]+2][knight[1]];
				arr[knight[0]+2][knight[1]] = temp;
			}
			if( knight[1]-1 >= 0 && arr[knight[0]+1][knight[1]-1] >= '1' && arr[knight[0]+1][knight[1]-1] <= '3' && (knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]-1] == '.' ) )
			//KATW ARISTERA EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]+1][knight[1]-1];
				arr[knight[0]+1][knight[1]-1] = arr[knight[0]+2][knight[1]-1];
				arr[knight[0]+2][knight[1]-1] = temp;
			}
			if( knight[1]+1 <= *m-1 && arr[knight[0]+1][knight[1]+1] >= '1' && arr[knight[0]+1][knight[1]+1] <= '3' && ( knight[0]+2 <= *n-1 && arr[knight[0]+2][knight[1]+1] == '.' ) )
			//KATW DEJIA EXTHROS KNOCKBACK
			{
				temp = 	arr[knight[0]+1][knight[1]+1];
				arr[knight[0]+1][knight[1]+1] = arr[knight[0]+2][knight[1]+1];
				arr[knight[0]+2][knight[1]+1] = temp;
			}
		}
		if( ( knight[1] - 1 >= 0 ) && (arr[knight[0]][knight[1]-1] >= '1' && arr[knight[0]][knight[1]-1] <= '3') )
		{
			arr[knight[0]][knight[1]-1] -= 1;
			if( ( knight[1] - 1 >= 0 ) && ( arr[knight[0]][knight[1]-1] == '0') )
			{
				arr[knight[0]][knight[1]-1] = '.';
				(*exthroi)--;
			}
			else if( ( knight[1] - 1 >= 0 ) && ( knight[1] - 2 >= 0 ) && (arr[knight[0]][knight[1]-2] == '.') )
			{	
				temp = arr[knight[0]][knight[1]-2];
				arr[knight[0]][knight[1]-2] = arr[knight[0]][knight[1]-1];
				arr[knight[0]][knight[1]-1] = temp;
			}
		}
		if( ( knight[1] + 1 <= *m-1 ) && (arr[knight[0]][knight[1]+1] >= '1' && arr[knight[0]][knight[1]+1] <= '3') )
		{	
			arr[knight[0]][knight[1]+1] -= 1;
			if( ( knight[1] + 1 <= *m-1 ) && ( arr[knight[0]][knight[1]+1] == '0') )
			{
				arr[knight[0]][knight[1]+1] = '.';
				(*exthroi)--;
			}
			else if( ( knight[1] + 1 <= *m - 1  ) && ( knight[1] + 2 <= *m-1 ) && (arr[knight[0]][knight[1]+2] == '.') )
			{	
				temp = arr[knight[0]][knight[1]+2];
				arr[knight[0]][knight[1]+2] = arr[knight[0]][knight[1]+1];
				arr[knight[0]][knight[1]+1] = temp;
			}
		}		
	}
	if( *exthroi == 0 )
			pista(n, m, epipedo, move, move_palio, knight, money, exthroi);
}

void movement(int *n, int *m, char *move, char *move_palio, int epipedo, int *knight, int *money, int *exthroi)
{
	int grammh, sthlh, theseis, temp, i, j;
	//EURESH THESIS IPPOTH
	for(i = 0; i < *n; i ++)
	{
		for(j = 0; j < *m; j++)
			if( arr[i][j] == '$' )
			{
				knight[0] = i;
				knight[1] = j;
				break;
			}
		if( arr[i][j] == '$')
			break;
	}
	grammh = knight[0];
	sthlh = knight[1];
	if( move[0] == 'U' || move[0] == 'u')//PANW
	{
		theseis = knight[0] - ( move[1] - '0' );
		if (theseis < 0)//EJW APO TO TAMPLO
			grammh = *n + theseis;
		else//MESA STO TAMPLO
			grammh = theseis;
		if( arr[grammh][sthlh] == '#' || (arr[grammh][sthlh] >= '1' && arr[grammh][sthlh] <= '3'))
		{
			epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
			return ;
		}	
		else
		{
			if( theseis < 0 )//EJW APO TO TAMPLO
			{
				for( i = knight[0]-1; i >=0 ; i--)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
				for( i = *n-1;  i > grammh; i--)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			else//MESA STO TAMPLO
			{
				for( i = knight[0]-1; i > grammh; i--)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			*money += 5 * ( move[1] - '0');				
			temp = arr[grammh][sthlh];
			arr[grammh][sthlh] = arr[knight[0]][knight[1]];
			arr[knight[0]][knight[1]] = temp;
		}
	}
	else if( move[0] == 'R' || move[0] == 'r' )//DEJIA
	{
		theseis = knight[1] + ( move[1] - '0' );
		if (theseis > *m-1)//EJW APO TO TAMPLO
			sthlh = theseis - *m;
		else
			sthlh = theseis;
		if( arr[grammh][sthlh] == '#' || (arr[grammh][sthlh] >= '1' && arr[grammh][sthlh] <= '3'))
		{
			epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
			return ;
		}
		else
		{
			if (theseis > *m-1)//EJW APO TO TAMPLO
			{
				for( i = knight[1]+1; i <= *m-1 ; i++)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
				for( i = 0; i < sthlh; i++)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			else
			{
				for( i = knight[1]+1; i < sthlh; i++)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			*money += 5 * ( move[1] - '0');				
			temp = arr[grammh][sthlh];
			arr[grammh][sthlh] = arr[knight[0]][knight[1]];
			arr[knight[0]][knight[1]] = temp;
		}
	}
	else if( move[0] == 'D' || move[0] == 'd')//KATW	
	{
		theseis = knight[0] + ( move[1] - '0' );	
		if (theseis > *n-1)//EJW APO TO TAMPLO
			grammh = theseis - *n;
		else//MESA STO TAMPLO
			grammh = theseis;
		if( arr[grammh][sthlh] == '#' || (arr[grammh][sthlh] >= '1' && arr[grammh][sthlh] <= '3'))
		{
			epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
			return ;
		}	
		else
		{
			if( theseis > *n-1)//EJW APO TO TAMPLO
			{
				for( i = knight[0]+1; i < *n ; i++)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
				for( i = 0;  i < grammh; i++)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			else//MESA STO TAMPLO
			{
				for( i = knight[0]+1; i < grammh; i++)
					if( arr[i][knight[1]] == '#' || (arr[i][knight[1]] >= '1' && arr[i][knight[1]] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			*money += 5 * ( move[1] - '0');				
			temp = arr[grammh][sthlh];
			arr[grammh][sthlh] = arr[knight[0]][knight[1]];
			arr[knight[0]][knight[1]] = temp;
		}	
	}
	else if ( move[0] == 'L' || move[0] == 'l')//ARISTERA
	{
		theseis = knight[1] - ( move[1] - '0' );
		if (theseis < 0)//EJW APO TO TAMPLO
			sthlh = *m + theseis;
		else
			sthlh = theseis;
		if( arr[grammh][sthlh] == '#' || (arr[grammh][sthlh] >= '1' && arr[grammh][sthlh] <= '3'))
		{
			epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
			return ;
		}
		else
		{	
			if( theseis < 0)//EJW APO TO TAMPLO
			{
				for( i = knight[1]-1; i >= 0 ; i--)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
				for( i = *m-1; i > sthlh; i--)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}
			}
			else
			{
				for( i = sthlh+1; i < knight[1]; i++)
					if( arr[knight[0]][i] == '#' || (arr[knight[0]][i] >= '1' && arr[knight[0]][i] <= '3') )
					{
						epilogi(n, m, epipedo, move, move_palio, knight, money, exthroi);
						return;
					}	
			}
			*money += 5 * ( move[1] - '0');				
			temp = arr[grammh][sthlh];
			arr[grammh][sthlh] = arr[knight[0]][knight[1]];
			arr[knight[0]][knight[1]] = temp;	
		}
					
	}
}
