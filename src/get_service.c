#include <stdio.h>
#include <errno.h>
#include <netdb.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct servent *serv ;
    int portnum;

    if(argc != 2){
        printf("Usage: %s port\n", argv[0]);
        exit(1);
    }

    portnum = atoi(argv[1]);
    if ( ( serv = getservbyport(htons(portnum),"tcp")) == NULL ){
        perror("getservbyport:");
        exit(1);
    }
    printf( "port %d is %s\n", portnum , serv->s_name );
    exit(0);
}
