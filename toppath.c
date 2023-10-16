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
    fp = NULL;  
  if (!thepath) {
    return NULL;  
  }

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
        free(fp);
        pt = strtok(NULL, ":");
      }
    }
    free(pc);
    if (stat(command, &s_buff) == 0) {
      return (command);
    }
  pc = strdup(thepath);
  if (!pc) {
    perror("Error allocating memory for pc:");
    return NULL;
  }

  /* Free the memory for the fp variable if it was allocated and not used to find the command. */
  if (fp != NULL) {
    free(fp);
  cmd_len = strlen(command);
  pt = strtok(pc, ":");
  fp = NULL;  

  while (pt != NULL) {
    d_len = strlen(pt);
    fp = malloc(cmd_len + d_len + 2);
    if (!fp) {
      perror("Error allocating memory for fp:");
      free(pc);
      return NULL;
    }
    strcpy(fp, pt);
    strcat(fp, "/");
    strcat(fp, command);
    strcat(fp, "\0");
    if (stat(fp, &s_buff) == 0) {
      free(pc);
      return fp;  
    } else {
      free(fp);
      pt = strtok(NULL, ":");
    }
  }
  return (NULL);
  free(pc);
  free(fp);  
  return NULL;
}
