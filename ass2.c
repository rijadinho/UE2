//-----------------------------------------------------------------------------
// ass1.c
//
// Textadventure
//
// Group: 3 study assistant Hancianu Michael
//
// Authors: Rijad Kovacevic 01231648
//          Dzenis Kajtazovic 01231661
//
// Latest Changes: ???
//-----------------------------------------------------------------------------
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Elements_
{
  char title_[255];
  char text_;
  char *choice_A_;
  char *choice_B_;

} Elements;

int main (int argc, char* argv[])
{
  Elements element;

  if (argc != 2)
  {
    printf("Usage: ./ass2 [file-name]\n");
    return 1;
  }

  FILE* file_open = fopen (argv[1], "r");

  if (file_open == NULL)
  {
    printf("[ERR] Could not read file %s.\n", argv[1]);
    return 3;
  }

  while((element.text_ = fgetc(file_open)) != EOF)
    printf("%c", element.text_);
    
  return 0;
}
