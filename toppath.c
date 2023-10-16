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
      if (fp == NULL) {
        perror("Error allocating memory:");
        free(pc);
        return NULL;
      }
      strcpy(fp, pt);
      strcat(fp, "/");
      strcat(fp, command);
      strcat(fp, "\0");
      if (stat(fp, &s_buff) == 0) {
        free(pc);
        return (fp);
      } else {
        pt = strtok(NULL, ":");
      }
    }
    free(pc);
    if (stat(command, &s_buff) == 0) {
      return (command);

    }
  }

  /* Free the memory that was allocated for fp, but only if the command does not exist. */
  if (fp != NULL) {
    free(fp);
  }
  return (NULL);
}
