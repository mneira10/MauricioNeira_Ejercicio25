#include <iostream>
#include <string>
#include <random>
// #include <vector>
#include <fstream>
#include <math.h>
using namespace std;

double genRan()
{
  return ((double)rand() / (RAND_MAX));
}

float gaussian(float x, float mu, float sigma)
{
  return exp(-(pow(x - mu, 2.0)) / (2.0 * sigma * sigma)) / (pow(2.0 * M_PI * sigma * sigma, 0.5));
}

main(int argc, char const *argv[])
{
  if (argc < 4)
  {
    cout << "Insuficient parameters.";
  }
  else
  {
    // cast to appropriate types
    int N;
    double mu, sigma;
    N = atoi(argv[1]);
    mu = atof(argv[2]);
    sigma = atof(argv[3]);

    // array to store samples
    double *samples = new double[N];

    // initialize random gaussian
    // USING LIBRARIES
    // default_random_engine generator;
    // normal_distribution<double> distribution(mu, sigma);

    ofstream myfile;
    myfile.open("sample.dat");

    // initialize at mean
    samples[0] = mu;
    myfile << samples[0] << "\n";

    for (int i = 1; i < N; i++)
    {
      //using libraries
      // samples[i] = distribution(generator);

      double dx = (genRan() - 0.5) * sigma;

      double cand = samples[i - 1] + dx;

      double alpha = gaussian(cand, mu, sigma) / gaussian(samples[i - 1], mu, sigma);

      if (genRan() <= alpha)
      {
        samples[i] = cand;
      }
      else
      {
        samples[i] = samples[i - 1];
      }

      myfile << samples[i] << "\n";
    }
    myfile.close();
  }
  return 0;
}
