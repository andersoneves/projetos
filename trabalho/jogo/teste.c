/*Programa exemplo para uso das funçoes  da biblioteca jogo*/

#include "jogo.h" /*Biblioteca com funções uteis para o jogo*/
int main(int argc, char const *argv[]){
	char a,c='*';
	int i=0,j=0,sai=0 ,row,col;
	for (i=0;i<argc;i++){/*for que mostra os parametros do argv*/
		printf("%s\n",argv[i] );	
	}
	i=0;

	pauses(100000);/*pausa por 100000 milisegundo a execução*/
	tela(&row,&col);/*verifica o tamanho da tela*/
	printf("linha %d  coluna %d\n",row,col );/*escreve o tamanho da tela*/
	color(1,2);/*troca a cor da fonte e do fundo*/
	cursor(0);/*desabilita o cursor na tela*/
	posxy(i,j);/*posiciona o cursor no topo da tela*/
	clean();/*limpa o terminal*/
	fflush(stdin);/*limpa o buffer do teclado*/
	while(!sai){ /*laço infinito para funcionamento do jogo*/
	 posxy(row,col-1);/*posiciona o cursor no fim da tela*/
	 printf("%d", i);/*imprime no fim da pagina*/
	 posxy(row-1,col-1);/*posiciona o cursor no fim da tela*/
	 printf("%d", j);/*imprime no fim da pagina*/
	 a=getcs();/*le alguma tecla celecionada*/
	 switch(a){/*menu para alterar as posições*/
	 	case 'a':
	 		if(j>0)
	 			j--;
	 	break;
	 	case 'd':
	 		if(j<col)
	 			j++;

	 	break;
	 	case 's':
	 		if(i<row)
		 		i++;
	 	break;
	 	case 'w':
	 		if(i>0)
	 			i--;
	 	break;
	 	case 'e':
	 		sai=1;
	 	break;
	 	default:
	 	break;
	 }
	 posxy(i,j);/*posiciona o cursor */
	 printf("%c",c ); /*imprime o carcter*/
	 pauses(10000);/*espera 10000 milisegundos*/
	 posxy(i,j);/*posicioma o cursor*/
	 printf("%c",' '); /*apaga o caracter*/
	 posxy(row,col-1);
	 printf("  "); /*apaga o posiçao*/
	 posxy(row-1,col-1);
	 printf("  "); /*apaga o posiçao*/

	}
	color(0,0);/*retorna as cores pagrao do terminal*/
	clean();/*limpa a tela*/
	cursor(1);/*Habilita o cursor*/
	fflush(stdout);/*limpa o buffer do monitor*/
	return 0;
}



