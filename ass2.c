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

typedef struct _Tree_
{
  Elements *start_point;
} Tree;

// Forward declaration
char openFile(Tree* tree_ptr, char* input);
char choiceA();
char choiceB();
char enterCommand();
void elementInit(Tree* tree_ptr);

//-----------------------------------------------------------------------------
/// TODO: !!!Rewrite the text!!!
/// The main program.
///
/// In combination with for and while loops, functions isItDigit and isItFloat
/// will take care of right input. BubbleSort function should sort numbers
/// and last checkTriangle func will check if it's triangle and triangle type
///
/// @angle initializing the pointer
/// @param userInput[UCHAR_MAX] used instead of hardcore value or
///  defining value, since we want 255 characters for our char array
/// @param num_of_triangles used to store number of triangles on stack.
///
/// @return always zero
//
int main (int argc, char* argv[])
{
  Tree tree_obj;

  if (argc != 2)
  {
    printf("Usage: ./ass2 [file-name]\n");
    return 1;
  }
  
  elementInit(&tree_obj);
  openFile(&tree_obj, argv[1]);

  if(EOF)
    enterCommand();
  else
    return 0;
}

//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
void elementInit(Tree* tree_ptr)
{
  tree_ptr->start_point = 0;
}

//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
Elements* newElement(char* input)
{
  Elements* newElement = (Elements*)malloc(sizeof(Elements));
  newElement->text_ = input;
  newElement->choice_A_ = NULL;
  newElement->choice_B_ = NULL;
  return newElement; 
}


//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
char openFile(Tree* tree_ptr, char* input)
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
      tree_ptr->start_point->title_ = line;
    }
    else if (line_counter == 1)
    {
      tree_ptr->start_point->choice_A_ = line;
    }
    else if (line_counter == 2)
    {
      tree_ptr->start_point->choice_B_ = line;
    }
    else 
      tree_ptr->start_point->text_ = line;

    line_counter++;
  }

  fclose(file_open);
  
  return 0;
}

//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
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

//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
char choiceA()
{
  exit(0);
}

//-----------------------------------------------------------------------------
///
/// TODO: Explain function
/// @param 
/// void/return?
//
char choiceB()
{
  return 0;
}