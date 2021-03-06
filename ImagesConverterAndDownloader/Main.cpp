#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>

#include "NeuralNet.h"

#define IMG_SIZE 10*10
#define ALPHABET_SIZE 10
using std::ifstream;

using namespace std;

double * grabPixels(string data) {
      ifstream stream(data, std::ios::binary);

      string header = "";
      stream >> header;

      int width, height, unused;
      stream >> width >> height >> unused;
      stream.ignore(256, '\n');

      unsigned char colorData[3];
      int red, green, blue;
      bool hasDiffThanBlack = false;
      double * dataArray = new double[width * height];

      for (int xx = 0; xx < width * height; ++ xx) {
            stream.read(reinterpret_cast<char *>(colorData), 3);
            red = colorData[0];
            green = colorData[1];
            blue = colorData[2];

            dataArray[xx] = ((blue & 0xff) << 16)| ((green & 0xff) << 8) | (red & 0xff);
      }
      

      stream.close();
      return dataArray;
}

int process_ocr(bool training, NeuralNet& nn, double bias, int iterations) {
  int correct = 0;
  int target_size = 6;

  vector<double>* inputs = new vector<double>(IMG_SIZE);
  vector<double>* outputs = new vector<double>(ALPHABET_SIZE);

  for (int j = 0; j < iterations; j++) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      delete outputs;
      ostringstream os;
      os << "C:/Users/Usuario/Desktop/Componentes Red/image" << i << "_" << j << ".ppm";

      double * pixels = grabPixels(os.str());
      for (int xxx = 0; xxx < 10 * 10; xxx++) {
        inputs -> push_back(pixels[xxx]);
      }


      outputs = new vector<double>(ALPHABET_SIZE);
      nn.feedForward(inputs, outputs, bias);

      if (training) {
        double max_val = 0;
        int max_index = 0;
        cout << "result for " << os.str() << " was:  " << endl;
        for (int k = 0; k < outputs->size(); k++) {
          if ((*outputs)[k] > max_val) {
            max_val = (*outputs)[k];
            max_index = k;
          }
          cout << (*(outputs))[k] << ", " ;
        }
        cout << endl;
        if (max_index == i) {
          //cout << "image" << i << "_" << j << ".ppm, was correct!: " << i << endl;
          correct++;
        }
      } else {
        nn.backPropagate(outputs, i);
      }
    }
  }

  delete inputs;
  delete outputs;
  return correct;
}

void process_and() {
  NeuralNet nn(2, 1, 1, 6, 1, .57);
  vector<double>* inputs = new vector<double>(2);
  vector<double>* outputs = new vector<double>(1);
  int correct = 0;

  for (int i = 0; i < 10000; i++) {
    double a, b, t;
    a = (rand() % 2 == 1) ? 1.0 : 0.0;
    b = (rand() % 2 == 1) ? 1.0 : 0.0;
    (*inputs)[0] = a;
    (*inputs)[1] = b;
    t = (a == 1.0 && b == 1.0) ? 1.0 : 0.0;

    //cout << "INPUT: " << a << ", " << b << " ; OUTPUT: " << t << endl;
    nn.feedForward(inputs, outputs, 0);
    nn.backPropagate(outputs, t);
  }
  nn.print();

  cout << "INPUT\tINPUT\tOUTPUT\n";

  for (int i = 0; i < 100; i++) {
    outputs -> clear();
    double a, b, t;
    a = (rand() % 2 == 1) ? 1.0 : 0.0;
    b = (rand() % 2 == 1) ? 1.0 : 0.0;
    (*inputs)[0] = a;
    (*inputs)[1] = b;

    nn.feedForward(inputs, outputs, 0);
    

    if ((*inputs)[0] == 1.0 && (*inputs)[1] == 1.0 && (*outputs)[0] == 0.0) {
      correct++;

    cout << (*inputs)[0] <<"\t" << (*inputs)[1] << "\t"
         << (*outputs)[0] << "\n";
    } else {
      cout << (*inputs)[0] <<"\t" << (*inputs)[1] << "\t"
         << (*outputs)[0] << "\n";
    }
  }

  cout << "AND success: " << correct << " / " << 100 << "\n";

  delete inputs;
  delete outputs;

  exit(0);
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));

  /*int training = 330, layers = 2, testing = 330;
  double bias = 0, responseThreshold = 1, learningRate = 1;
  int layerHeight = 10;

  // argc is 1 if the command line was given the name of the binary
  // and no additional parameters.
  /*if (argc == 1) {
    cout << "usage: " << argv[0] << " -t # -l # -b # -a # -r # -h #\n"
         << "-t: the number of training samples per digit.\n"
         << "-T: the number of testing samples per digit.\n"
         << "-l: the number of hidden layers; default = 2.\n"
         << "-b: the weight of the bias.\n"
         << "-a: the learning rate for back propagation.\n"
         << "-r: the response threshold for the sigmoid function.\n"
         << "-h: the number of neurons per hidden layer.\n";
    return 0;
  }

  // Process command line arguments.
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-t") == 0) {
      training = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-T") == 0) {
      testing = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-l") == 0) {
      layers = atoi(argv[++i]);
    } else if (strcmp(argv[i], "-b") == 0) {
      bias = atof(argv[++i]);
    } else if (strcmp(argv[i], "-r") == 0) {
      responseThreshold = atof(argv[++i]);
    } else if (strcmp(argv[i], "-a") == 0) {
      learningRate = atof(argv[++i]);
    } else if (strcmp(argv[i], "-h") == 0) {
      layerHeight = atoi(argv[++i]);
    }
  }*/

  /*if (layers < 0 || training <= 0 || testing <= 0 || responseThreshold <= 0
      || layerHeight <= 0 || learningRate < 0) {
    cout << "Invalid argument specified.\n";
    return 1;
  }

  NeuralNet nn(IMG_SIZE,
               ALPHABET_SIZE,
               layers,
               layerHeight,
               learningRate,
               responseThreshold);

  process_ocr(false, nn, bias, training);
  int correct = process_ocr(true, nn, bias, testing);

  cout << "Success: " << correct << " / " << testing * 10
       << " (" << ((double)correct / (double)testing * 10) << "%)\n";

*/

       process_and();

  return 0;
}