#ifndef _ERRNO_H
#define _ERRNO_H 1

extern int errno;

#define ENOMEM      12
#define EINVAL      22

extern const char *e_msg[23];

#endif
