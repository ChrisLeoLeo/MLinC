#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int sample[3];

sample orGate[] = {
    {0, 1, 1},
    {1, 0, 1},
    {0, 0, 0},
    {1, 1, 1},
};

sample andGate[] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 1, 1},
    {1, 0, 0},
};

sample *data = andGate;

size_t train_count = 4;

float sigmoidf(float x) { return 1.0f / (1 + expf(-x)); }
float reluf(float x) { return (x > 0) ? x : 0.0f; }

void evalModel(float *model, int epoch, float bias) {
  for (int i = 0; i < train_count; i++) {
    printf(
        "For the input %d and %d the expected output should be %d.\n And the "
        "models output after %d epochs is %f\n",
        data[i][0], data[i][1], data[i][2], epoch,
        (sigmoidf(data[i][0] * model[0] + (float)data[i][1] * model[1] +
                  bias)));
  }
}

// the one parameter formula is basically Y = x*W;
float err(float weight1, float weight2, float bias) {
  float total_err = 0.0f;
  float y;
  float d;
  // printf("%f \n", w);
  for (int i = 0; i < train_count; i++) {
    y = sigmoidf(data[i][0] * weight1 + data[i][1] * weight2 + bias);
    d = y - data[i][2];
    total_err += d * d;
  }
  return total_err;
}

float *train(float *model, float learningrate, float epsilon, int epochs,
             float bias) {
  for (int i = 0; i <= epochs; i++) {
    float dcost1 = (err(model[0] + epsilon, model[1], bias) -
                    err(model[0], model[1], bias)) /
                   epsilon;
    float dcost2 = (err(model[0], model[1] + epsilon, bias) -
                    err(model[0], model[1], bias)) /
                   epsilon;
    float dbias = (err(model[0], model[1], bias + epsilon) -
                   err(model[0], model[1], bias)) /
                  epsilon;
    model[0] -= learningrate * dcost1;
    model[1] -= learningrate * dcost2;
    bias -= learningrate * dbias;
    /*if (i % 100 == 0) {
      printf("This is the first weight: %f, this is the seond weight: %f and "
             "this the cost for it: %f \n",
             model[0], model[1], err(model[0], model[1]));
    }
    */
    /*if (i % 200 == 0) {
      evalModel(model, i);
    }
    */
  }
  printf("%f \n", model[0]);
  printf("%f \n", model[1]);
  printf("Err: %f\n", err(model[0], model[1], bias));
  evalModel(model, 500, bias);
  return model;
}

int main() {
  srand(time(NULL));
  float model[2];
  model[0] = 1.0f;
  model[1] = 0.0f;
  float learningrate = 1e-2f;
  //  printf("%f \n", costfn(w));
  printf("------------------------ \n");
  train(model, learningrate, 1e-3f, 10000, 1.0f);
  return 0;
}
