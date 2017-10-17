#include "jogo.h"
void pauses (int i){
	clock_t obj=i+clock();
	fflush(stdout);
	while( obj > clock() );
	fflush(stdout);
}

void tela(int *row ,int *col){
	struct winsize  w;
	ioctl(0,TIOCGWINSZ,&w);
	*row=w.ws_row;
	*col=w.ws_col;
}

void color(int i ,int j){
int cl[8]={30,31,32,33,34,35,36,37},bg[8]={40,41,42,43,44,45,46,47};
if ( (i  >= 0 && i <= 7)   && (j  >= 0 && j <= 7)){


if(i==0)
	{
	if(j==0)
		{
		 printf("%c[%dm",27,0);		
		}
	else{
		 printf("%c[%d;%dm",27,1,bg[j]);
		}
	}
else
	{
	if(j==0)
		{
		 printf("%c[%d;%dm",27,1,cl[i]);
		}
	else
		{
		 printf("%c[%d;%d;%dm",27,1,cl[i],bg[j]);
		}

	}
	

}
}


int getcs(void){
	int d;
	struct termios t,c;
	
	if(tcgetattr(STDIN_FILENO,&t)==-1){
		printf("tcgetattr error");
	}

	c=t;
	t.c_lflag &= ~ICANON;
	t.c_cc[VTIME] &= 0;
	t.c_cc[VMIN] &= 0;

	if(tcsetattr(STDIN_FILENO,TCSANOW,&t)==-1){
	 printf("tcsetattr error");
	}
	fflush(stdout); 
	d=getchar();

	if(tcsetattr(STDIN_FILENO,TCSANOW,&c)==-1){
	 printf("tcsetattr error");
	} 
	
	fflush(stdout);
	if(d==EOF)
		return 0;
	else{
		fflush(stdin);
		return d;
	}


}


void cursor(int i){
static struct termios t,c;
if(tcgetattr(STDIN_FILENO,&t)==-1){
	printf("tcgetattr error");
}

if (i==0)
	{
	 printf("\33[?25l");
	 c=t;
	 t.c_lflag &= ~ECHO;
	}
else
	{
	 printf("\33[?25h");
	 t=c;
	}
if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&t)==-1){
	printf("tcsetattr error");
} 
fflush(stdout);
}


void clean(){
	printf("\033[H\033[J");
}


void posxy(int x,int y){
	printf("%c[%d;%df",0x1b,x,y );
	fflush(stdout);
}