#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>


#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)




 
int main(int argc, char **argv)
{

struct sockaddr_rc addr = { 0 };
    int s, status,bytes_read;
    char dest[18] = "98:D3:32:10:4B:79";
   
    char bufr[1024] = { 0 };
   

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );


    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));


    // send a message

uint8_t recivedData;


    while( status >= 0 ) {

        
         unsigned char buf[4];
        char stringReceived[256];
         printf("Send a command\n");
         char tmpChar;
         scanf("%c",&tmpChar);
         getchar(); // To consume the newline  
         buf[0] = tmpChar;

        status = write(s,buf, 4);
        
         unsigned char buf2[4];
        int status2 = read(s, buf2,4);
         

    }

    if( status < 0 ) perror("uh oh");

    close(s);
    return 0;
}

//gcc sendData.c -lbluetooth -o sendData



