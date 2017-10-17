/*Biblioteca desenvolvida para uso nos trabalhos da disciplina de ALgI
Autor: Anderson Pereira das Neves
Funções Lunux.
*/
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <termios.h>

void posxy(int x,int y); /*posisciona o cursor no terminal x coluna y linha*/
void clean();/*limpa o terminal */
void cursor(int i);/*Habilita(1) e desablilita(0) o cusrsor na tela  */
void pauses (int i);/*pausa o programa por i milisegundos*/
int getcs(void);/*verifica e le  se exite algo para ser lido */
void tela(int *row ,int *col);/*retorna o tamaho da tela nas variaveis*/
void color(int i ,int j);/*muda a cor do fundo e da letra  cores de 0 a 7*/