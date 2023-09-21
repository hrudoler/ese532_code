#include "App.h"
#define HEIGHT (264)
#define WIDTH (474)

// need frames to be dividing up Y = the height
void Differentiate_coarse(const unsigned char *Input, unsigned char *Output, int Y_Start_Idx, int Y_End_Idx)
{
  for (int Y = Y_Start_Idx; Y < Y_End_Idx; Y++)
    for (int X = 0; X < WIDTH; X++)
    {
      int Average = 0;
      if (Y > 0 && X > 0)
        Average = (Input[WIDTH * (Y - 1) + X] + Input[WIDTH * Y + X - 1]) / 2;
      else if (Y > 0)
        Average = Input[WIDTH * (Y - 1) + X];
      else if (X > 0)
        Average = Input[WIDTH * Y + X - 1];

      unsigned char Diff = Input[WIDTH * Y + X] - Average;

      Output[Y * WIDTH + X] = Diff;
    }
}
