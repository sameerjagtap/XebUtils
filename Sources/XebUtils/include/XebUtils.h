//
//  File.h
//  
//
//  Created by Sameer Jagtap on 25/05/21.
//

#ifndef XebUtils_h
#define XebUtils_h

#include <stdio.h>
#include <unistd.h>
#include <string.h> /* for strncpy */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

const char* getIPAddressFromXebUtils();

#endif /* XebUtils_h */
