/*************************************************************************
  *fileName:    test.c
  *description: test the myscull.c
  *author:      fedora15
  *create time: 2016-04-04
  *modify info: -
*************************************************************************/
#include <stdio.h>
#include <fcntl.h>   /*open*/
#include <sys/ioctl.h>
#include <sys/types.h>

/* device path */
char path[] = "/dev/scull0";
char write_buf[128];
char read_buf[128];
int main()
{
   int fd = open(path, O_RDWR);
   if (fd == -1)
   {
       printf("device open error!\n");
       return 1;
   }

   printf("Input a string to write device \n");
   scanf("%s", write_buf);
   write(fd, write_buf, 4); /* device wirte */
    
   printf("Read the string from device...\n");
   read(fd, read_buf, 128); /* device read */
   printf("%s\n", read_buf);
    
   close(fd);
} 
