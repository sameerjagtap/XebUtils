#ifndef XebUtils_h
#define XebUtils_h

#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy memset */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <math.h>

#include<stdlib.h> //for exit(0);
#include<sys/socket.h>
#include<errno.h> //For errno - the error number
#include<netdb.h>    //hostent

#define atoa(x) #x

const char* getIPAddressFromXebUtils();
const char* hostNameToIP(char hostname);

#endif /* XebUtils_h */
