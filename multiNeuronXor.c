#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float xor_data[][3] = {
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
    {0, 0, 0},
};

typedef struct {
  float w1;
  float w2;
  float bias;
  float output;
} Neuron;

float err(Neuron *neurons) {
  float err = 0;
  for (int i = 0; i < sizeof(xor_data) / sizeof(xor_data[0]); i++) {
  }
  return 0.0f;
}

int main() {
  Neuron neuron1;
  neuron1.bias = 0;
  return 0;
}
