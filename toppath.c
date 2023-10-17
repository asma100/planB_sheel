#include "top.h"
char *finding_path(char *command) {
 char *thepath, *pc, *pt, *fp;
int cmd_len, d_len;

 struct stat s_buff;
 thepath = getenv("PATH");
 if (thepath) {
  pc = strdup(thepath);
  cmd_len = strlen(command);
  pt = strtok(pc, ":");
  while (pt != NULL) {
   d_len = strlen(pt);
   fp = malloc(cmd_len + d_len + 2);
   strcpy(fp, pt);
   strcat(fp, "/");
   strcat(fp, command);
   strcat(fp, "\0");
   if (stat(fp, &s_buff) == 0) {
    free(pc);
    return (fp);
   } else {
    pt = strtok(NULL, ":");
    free(fp); 
   }
  }
  free(pc);
  
  if (stat(command, &s_buff) == 0) {
   return (command);
  }
 }

 return (NULL);
}
