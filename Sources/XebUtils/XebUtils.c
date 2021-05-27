#include "include/XebUtils.h"

void toString(char str[], int num)
{
    int i, rem, len = 0, n;
    
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

int toInt(char str[])
{
    int len = strlen(str);
    int i, num = 0;
    
    for (i = 0; i < len; i++)
    {
        num = num + ((str[len - (i + 1)] - '0') * pow(10, i));
    }
    
    return num;
}


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

const char* hostNameToIP(const char *hostname)
{
    struct hostent *he;
    struct in_addr **addr_list;
    int i;
    char ip[100];
    char str[100];
    
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
        toString(str, *ip);
        return *str;
    }
    
    return NULL;
}

