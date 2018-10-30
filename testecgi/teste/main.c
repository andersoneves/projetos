#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mongoc.h>




typedef struct dado
{
	int id ;
	char chave[100];
	char valor[100];
}dados;

int exec(dados *,int);
int GET(char **data);
int POST(char **data);
int DATA(char **data);
void parse(char *data,dados **dado,int *tamanho);

int main(int charc, char **argv, char **envp)
{
  char *msg,sql[20000];
  dados *dado;
  int tamanho,i;
  /*char ** env,*thisEnv;*/
  printf("Content-type: text/html\n\n");
  printf("<head>");
  	printf("<title>Pagina</title>");
  	printf("<meta charset='UTF-8'>");

  printf("</head>");
  printf("<body>");
  printf("<a href='index'>link</a><br>");
/*
for (env = envp; *env != 0; env++)
  {
    thisEnv = *env;
    printf("<div> %s<div>", thisEnv);
  }
*/

//if(POST(&msg)){
msg=malloc(sizeof("nome=skks&sexo=paulo.teste.com&senha=12345&Enviar=Enviar"));
strcpy(msg,"nome=ksk&sexo=paulo.teste.com&senha=12345&Enviar=Enviar");
if(1==1){
	printf("<< %s  >> <br>\n",msg );

	parse(msg,&dado,&tamanho);

	exec(dado,tamanho);
	for(i=0;i<tamanho;i++)
		printf(" [%s]  {%s} <br>\n",dado[i].chave,dado[i].valor );
	sprintf(sql, "insert into usuario (%s,%s,%s) values ('%s','%s','%s');",dado[0].chave,dado[1].chave,dado[2].chave,dado[0].valor,dado[1].valor,dado[2].valor);
	//executeQueri(sql);
}
else
	printf("no msg\n");

  printf("</body>");
  return 0;

}


int POST(char **data){
int tamanho=0;
if(strcmp(getenv("REQUEST_METHOD"),"GET" )==0)
	return-1;

tamanho=atoi(getenv("CONTENT_LENGTH"));
if (tamanho!=0){
	 *data=(char *)malloc(sizeof(char)*tamanho+1);
	 fscanf(stdin, "%s",*data);
	 return 1;
	}
else
	return -1;
}


int GET(char **data){

if(strcmp(getenv("REQUEST_METHOD"),"POST" )==0)
	return-1;
if(sizeof(getenv("QUERY_STRING") ) >= 1  ){
	*data=(char *)malloc(sizeof(char) * strlen(getenv("QUERY_STRING") +1 ) );
	strcpy(*data,getenv("QUERY_STRING"));

	return 1;
}
else{
	return -1;
}
}



int DATA(char **data){

if(strcmp(getenv("REQUEST_METHOD"),"POST" )==0){
	/*printf("POST\n");*/
	return	POST(data);
}

if(strcmp(getenv("REQUEST_METHOD"),"GET" )==0){
	/*printf("GET\n");*/
	return	GET(data);
}
return-1;
}



void cvt(char *dest, const char *src)
{
const char *p = src;
char code[3] = {0};
unsigned long ascii = 0;
char *end = NULL;

while(*p)
{
if(*p == '%')
{
memcpy(code, ++p, 2);
ascii = strtoul(code, &end, 16);
*dest++ = (char)ascii;
p += 2;
}
else
*dest++ = *p++;
}
}

int  pops (char **data,char  **result, char c ){
int tamanho=strlen(*data),i,j,n;
char *texto,*texto2;
/*printf("(%s)[%d] <br> \n",(*data),tamanho );*/
if(tamanho<1){
	return -1;
}
texto=(char *)malloc(sizeof( (*data) ) );
texto2=(char *)malloc(sizeof( (*data) ) );
for(i=0;i<=tamanho;i++){
	if(( *data)[i]!= c)
		texto[i]=(*data)[i];
	else
		break;
}
texto[i]='\0';
n=0;
for(j=i+1;j<=tamanho;j++){
	texto2[n]=(*data)[j];
	n++;
}
strcpy((*data),texto2);
strcpy((*result),texto);
/*printf("<br> -- %s - %s --  <br>\n",texto,texto2 );*/
return 1;
}

int conts(char *data){
	int i,j=0;
	for(i=0;i<strlen(data);i++){
		if(data[i] == '=')
			j++;
	}
	return j;
}



void parse(char *data,dados **dado,int *tamanho){
char *texto,*chave;
int el,count=0;
/*texto=strsep(&data,&v);*/
texto=(char *)malloc(sizeof(char)*49 );

/*printf("<br>*** %s *** <br>\n",data );*/
cvt(texto,data);
strcpy(data,texto);
el=conts(data) ;
*tamanho=el;
(*dado)=(dados *)malloc(sizeof(dados)*el);




while(pops(&data,&texto,'&') > 0 && count < el ){
	//printf("<br>---++ %s ++--- \n", texto);
	pops(&texto,&chave,'=');
	/*printf("<br>{%s} [%s] <br>\n",chave,texto );*/
	(*dado)[count].id=count;
	/*(*dado)[count].chave=malloc(sizeof(chave));*/
	/*(*dado)[count].valor=malloc(sizeof(chave));*/
    strcpy( (*dado)[count].chave ,chave );
    strcpy( (*dado)[count].valor ,texto );
    /*printf("<br>--++ %d - %s - %s  ++-- <br>\n",(*dado)[count].id=count, (*dado)[count].chave ,(*dado)[count].valor );*/
    count++;
}


}



int exec(dados * dado,int tamanho)
{

   const char *uri_string = "mongodb://127.0.0.1:27017";
   mongoc_uri_t *uri;
   mongoc_client_t *client;
   mongoc_database_t *database;
   mongoc_collection_t *collection;
   bson_t *command, reply, insert;
   bson_error_t error;
   int i;



   bool retval;

   /*
    * Required to initialize libmongoc's internals
    */
   mongoc_init ();


   /*
    * Optionally get MongoDB URI from command line
    */


   /*
    * Safely create a MongoDB URI object from the given string
    */
   uri = mongoc_uri_new_with_error (uri_string, &error);
   if (!uri) {
      fprintf (stderr,
               "failed to parse URI: %s\n"
               "error message:       %s\n",
               uri_string,
               error.message);
      return EXIT_FAILURE;
   }


   /*
    * Create a new client instance
    */
   mongoc_client_new("mongodb://127.0.0.1:27017");
   int j;
	for(j=0;j<tamanho;j++)
		printf("<br> ---[%s]  {%s}--- <br>\n",dado[j].chave,dado[j].valor );
	return 0;

   client = mongoc_client_new_from_uri(uri);

   if (!client) {
      return EXIT_FAILURE;
   }


   /*
    * Register the application name so we can track it in the profile logs
    * on the server. This can also be done from the URI (see other examples).
    */
   mongoc_client_set_appname (client, "connect-example");

   /*
    * Get a handle on the database "db_name" and collection "coll_name"
    */
   database = mongoc_client_get_database (client, "db_name");
   collection = mongoc_client_get_collection (client, "db_name", "coll_name");

   /*
    * Do work. This example pings the database, prints the result as JSON and
    * performs an insert
    */
   command = BCON_NEW ("ping", BCON_INT32 (1));

   retval = mongoc_client_command_simple (
      client, "admin", command, NULL, &reply, &error);

   if (!retval) {
      fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
   }


   bson_init (&insert);
   for(i=0;i<tamanho;i++){
    BSON_APPEND_UTF8 (&insert, dado[i].chave, dado[i].valor);
   }



   if (!mongoc_collection_insert_one (collection, &insert, NULL, NULL, &error)) {
      fprintf (stderr, "%s\n", error.message);
   }

   bson_destroy (&insert);
   bson_destroy (&reply);
   bson_destroy (command);


   /*
    * Release our handles and clean up libmongoc
    */
   mongoc_collection_destroy (collection);
   mongoc_database_destroy (database);
   mongoc_uri_destroy (uri);
   mongoc_client_destroy (client);
   mongoc_cleanup ();

   return EXIT_SUCCESS;
}

