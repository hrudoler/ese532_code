#include <stdlib.h>
#include "App.h"

#define INPUT_HEIGHT (270)
#define INPUT_WIDTH (480)

#define FILTER_LENGTH (7)

#define OUTPUT_HEIGHT (INPUT_HEIGHT - (FILTER_LENGTH - 1))
#define OUTPUT_WIDTH (INPUT_WIDTH - (FILTER_LENGTH - 1))

unsigned Coefficients[] = {2, 15, 62, 98, 62, 15, 2};

void Filter_horizontal(const unsigned char *Input, unsigned char *Output, int input_start, int input_end)
{
  for (int Y = 0; Y < INPUT_HEIGHT; Y++)
    for (int X = input_start; X < input_end; X++)
    {
      unsigned int Sum = 0;
      for (int i = 0; i < FILTER_LENGTH; i++)
        Sum += Coefficients[i] * Input[Y * INPUT_WIDTH + X + i];
      Output[Y * OUTPUT_WIDTH + X] = Sum >> 8;
    }
}

void Filter_vertical(const unsigned char *Input, unsigned char *Output, int input_start, int input_end)
{
  for (int Y = 0; Y < OUTPUT_HEIGHT; Y++)
    for (int X = input_start; X < input_end; X++)
    {
      unsigned int Sum = 0;
      for (int i = 0; i < FILTER_LENGTH; i++)
        Sum += Coefficients[i] * Input[(Y + i) * OUTPUT_WIDTH + X];
      Output[Y * OUTPUT_WIDTH + X] = Sum >> 8;
    }
}

void Filter_coarse(const unsigned char *Input, unsigned char *Output, int input_start, int input_end)
{
  unsigned char *Temp = (unsigned char *)malloc(INPUT_HEIGHT * OUTPUT_WIDTH);

  Filter_horizontal(Input, Temp, input_start, input_end);
  Filter_vertical(Temp, Output, input_start, input_end);

  free(Temp);
}
