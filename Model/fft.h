#ifndef FFT_H
#define FFT_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "Model/onda.h"

#define MAX 4096

// FFT Implementation: Credits to Cooley-Tukey @ https://it.wikipedia.org/wiki/Trasformata_di_Fourier_veloce

class FFT : public Onda{

public:
    FFT();
    void runFFT(std::complex<double>* f, unsigned int N, double d);
    void zeroPad(std::complex<double>*);
    void smoothFFT(int);
    virtual void remapFFT(const std::vector<double>& ,double, double, double, double)= 0;
    void setOutFrequencies(std::complex<double>*);
    std::vector<double> getOutFrequencies() const;
    void clearOutFrequencies();
    std::complex<double>* getFFTInputData();

private:
    int reverse(unsigned int N, unsigned int n) const;
    void sort(std::complex<double>* f1, unsigned int N) const;
    void transform(std::complex<double>* f, unsigned int N) const;
    std::vector<double> outFrequencies;
    std::complex<double> FFTInputData[MAX];
};


#endif // FFT_H
