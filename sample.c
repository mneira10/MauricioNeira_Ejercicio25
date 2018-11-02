#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <fstream>
using namespace std;

main(int argc, char const *argv[])
{
  if (argc < 4)
  {
    cout << "Insuficient parameters.";
  }
  else
  {

    int N, mu, sigma;
    N = atoi(argv[1]);
    mu = atoi(argv[2]);
    sigma = atoi(argv[3]);

    // vector<double> samples;
    double *samples = new double[N];

    // initialize random gaussian
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(mu, sigma);

    ofstream myfile;
    myfile.open("sample.dat");

    for (int i = 0; i < N; i++)
    {
      samples[i] = distribution(generator);
      // cout << samples[i] << "\n";
      myfile << samples[i] << "\n";
    }
    myfile.close();
  }
  return 0;
}
