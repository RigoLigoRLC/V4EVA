// SPDX-License-Identifier: GPL3

#include <iostream>
#include <fstream>
#include <string>
#include <pyin.h>
#include <ciglet/ciglet.h>

int main(int argc, char** argv)
{
    int fs, nbit, nx;
    FP_TYPE* wav = wavread(argv[1], &fs, &nbit, &nx);

    int nhop = 128;
    int nfrm = 0;
    pyin_config pyin_param = pyin_init(nhop);
    pyin_param.fmax = 500.0;
    pyin_param.fmin = 50.0;
    pyin_param.nf = ceil(0.025 * fs);
    pyin_param.trange = 24;
    pyin_param.bias = 2;

    FP_TYPE* f0 = pyin_analyze(pyin_param, wav, nx, fs, &nfrm);

    std::string ofName(argv[1]);
    ofName += ".F0pYIN.csv";
    std::ofstream of(ofName);
    for(size_t i = 0; i < nfrm; i++)
    {
        of << f0[i] << ",\n";
    }
    of.close();

    free(wav);
    free(f0);

    return 0;
}
