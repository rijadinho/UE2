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
  char *title_;
  char *text_;
  char *choice_A_;
  char *choice_B_;

} Elements;

char openFile(Elements element, char* input);
char choiceA();
char choiceB();
char enterCommand();

int main (int argc, char* argv[])
{
  Elements element;

  if (argc != 2)
  {
    printf("Usage: ./ass2 [file-name]\n");
    return 1;
  }

  openFile(element, argv[1]);
  
  if(EOF)
    enterCommand();
  else
    return 0;
}

char openFile(Elements element, char* input)
{
  FILE* file_open = fopen(input, "r");

  if (file_open == NULL)
  {
    printf("[ERR] Could not read file %s.\n", input);
    return 3;
  }

  // Print 30 x lines at the beginning of the file
  for (int counter = 0; counter < 30; counter++)
  {
    printf("-");
  }
  // New line
  printf("\n");

  char line[256];
  int line_counter = 0;

  while(fgets(line, sizeof(line), file_open))
  {
    printf("%s %d", line, line_counter);

    if (line_counter == 0)
    {
      element.title_ = line;
    }
    else if (line_counter == 1)
    {
      element.choice_A_ = line;
    }
    else if (line_counter == 2)
    {
      element.choice_B_ = line;
    }
    else 
      element.text_ = line;

    line_counter++;
  }

  fclose(file_open);
  
  return 0;
}

char enterCommand()
{
  printf("Deine Wahl (A/B)? ");
  char command;
  scanf("%c", &command);
  
 if(command == 'A')
    choiceA();
  else if(command == 'B')
    choiceB();
  else
  {
    printf("[ERR] Please enter A or B.\n");
    enterCommand();
  }
  return command;
}

char choiceA()
{
  exit(0);
}
char choiceB()
{
  return 0;
}