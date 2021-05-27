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

char* hostNameToIP(const char *hostname)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
    char ip[100];
    
    if ( (he = gethostbyname( hostname ) ) == NULL)
    {
            // get the host info
        herror("gethostbyname");
        return 1;
    }
    
    addr_list = (struct in_addr **) he->h_addr_list;
    
    for(i = 0; addr_list[i] != NULL; i++)
    {
            //Return the first one;
        strcpy(ip , inet_ntoa(*addr_list[i]) );
        return *ip;
    }
    
    return NULL;
}

