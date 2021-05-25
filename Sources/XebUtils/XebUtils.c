//
//  File.c
//  
//
//  Created by Sameer Jagtap on 25/05/21.
//

#include "include/XebUtils.h"

const char* getIPAddressFromXebUtils() {
    int fd;
    struct ifreq ifr;
    
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    /* IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;
    
    /* IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
    
    ioctl(fd, SIOCGIFADDR, &ifr);
    
    close(fd);
    
    /* Display result */
    printf("%s\n", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

    return inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
}
