#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool LetturaDati(const std::string& fileName,
               double& S,
               int& n,
               double*& w,
               double*& r)
{
    std::ifstream file(fileName);

    if (file.fail())
    {
        std::cerr << "Errore nell'apertura del file " << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // lettura di  S
    std::istringstream sottostringa(line.substr(2)); // salva il terzo carattere
    sottostringa >> S;

    std::getline(file, line); // lettura di n
    sottostringa.clear();
    sottostringa.str(line.substr(2)); // salva il terzo carattere
    sottostringa >> n;

    w = new double[n];
    r = new double[n];

    std::getline(file, line); // ignora la terza riga, ovvero quella che contiene "w;r"
    for (int i = 0; i < n; ++i)
    {
        std::getline(file, line);
        char separator;
        sottostringa.clear();
        sottostringa.str(line);
        sottostringa >> w[i] >> separator >> r[i];
    }

    file.close();
    return true;
}

void CalcolaRendimento(double S,
                       int n,
                       double* w,
                       double* r,
                       double& rateOfReturn,
                       double& V)
{
    rateOfReturn = 0.0;
    for (int i = 0; i < n; ++i)
    {
        rateOfReturn += w[i] * r[i];
    }

    V = S * (1 + rateOfReturn);
}

bool EsportaRisultati(const std::string& fileName,
                      double S,
                      int n,
                      double* w,
                      double* r,
                      double rateOfReturn,
                      double V)
{
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Impossibile aprire il file per l'esportazione: " << fileName << std::endl;
        return false;
    }

    file << std::fixed << std::setprecision(2);
    file << "S = " << S << ", n = " << n << std::endl;
    file << "w = [";
    for (int i = 0; i < n; ++i) {
        file << " " << w[i];
    }
    file << " ]" << std::endl;
    file << "r = [";
    for (int i = 0; i < n; ++i) {
        file << " " << r[i];
    }
    file << " ]" << std::endl;
    file << "Rate of return of the portfolio: " << rateOfReturn << std::endl;
    file << "V: " << V << std::endl;

    file.close();
    return true;
}
