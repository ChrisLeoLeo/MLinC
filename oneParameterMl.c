#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dataset[9] = {0, 0, 1, 2, 2, 4, 4, 8};

#define dataset_count (sizeof(dataset) / sizeof(dataset[0]))
// the one parameter formula is basically Y = x*W;
float costfn(float w) {
  srand(time(NULL));
  float err;
  // printf("%f \n", w);
  for (int i = 0; i < dataset_count; i += 2) {
    float y = dataset[i] * w;
    err += (y * y - dataset[i + 1] * dataset[i + 1]);
  }
  return err;
}

float train(float model, float learningrate, float epsilon, int epochs) {
  for (int i = 0; i <= epochs; i++) {
    float dcost = costfn(model + epsilon) - costfn(model);
    model += learningrate * dcost;
    if (i % 10 == 0) {
      printf("This is the weight: %f and this the cost for it: %f \n", model,
             dcost);
    }
  }
  printf("%f \n", model);
  return model;
}

int main() {
  srand(time(NULL));
  float w = rand() % 11;
  float learningrate = 1e-3f;
  //  printf("%f \n", costfn(w));
  printf("------------------------ \n");
  train(1.0f, learningrate, 1e-3f, 500);
  return 0;
}
