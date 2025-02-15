#include <iostream>

#include "FourierUtils.h" 

int main() {

    std::vector<double> samples = {0, 1, 0, -1, 0};
    std::vector<std::complex<double>> complexSamples = utils::Fourier::toComplex<double>(samples);
    std::vector<std::complex<double>> dftSamples = utils::Fourier::dft<double>(complexSamples);
    std::vector<std::complex<double>> fftSamples = utils::Fourier::fftN2<double>(complexSamples);

    printf("Signal");
    printf("\nSAMPLE\t");
    for (const auto& sample: samples)
        printf("%f\t", sample);
    
    printf("\n\nDFT");
    printf("\nFREQ\t");
    for (int i = 0; i < dftSamples.size(); i++)
        printf("%f\t", (float) i / dftSamples.size());

    printf("\nAMPL\t");
    for (const auto& sample: utils::Fourier::toAmplSpectrum<double>(dftSamples))
        printf("%f\t", sample);
    
    printf("\nPHAS\t");
    for (const auto& sample: utils::Fourier::toPhaseSpectrum<double>(dftSamples))
        printf("%f\t", sample);
    
    printf("\n\nFFT");
    printf("\nFREQ\t");
    for (int i = 0; i < fftSamples.size(); i++)
        printf("%f\t", (float) i / fftSamples.size());

    printf("\nAMPL\t");
    for (const auto& sample: utils::Fourier::toAmplSpectrum<double>(fftSamples))
        printf("%f\t", sample);

    printf("\nPHAS\t");
    for (const auto& sample: utils::Fourier::toPhaseSpectrum<double>(fftSamples))
        printf("%f\t", sample);

    return 0;
}