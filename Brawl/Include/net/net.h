#pragma once

#include <net/SOBasic.h>
#include <net/nonport.h>

#define AF_INET 0x2

#define SOCK_STREAM 0x1
#define SOCK_DGRAM 0x2

#define INADDR_ANY 0x0

#define MSG_PEEK 0x2
#define MSG_DONTWAIT 0x40
#define MSG_WAITALL 0x100

struct in_addr {
    unsigned long s_addr; // load with inet_aton()
};

struct sockaddr_in {
    short sin_family;        // e.g. AF_INET
    unsigned short sin_port; // e.g. htons(3490)
    struct in_addr sin_addr; // see struct in_addr, below
};