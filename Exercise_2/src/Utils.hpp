#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//legge i dati dal file di input
bool LetturaDati(const std::string& fileName, double& S, int& n, double*& w, double*& r);

//calcola il tasso di rendimento e il valore finale del portafoglio
void CalcolaRendimento(double S, int n, double* w, double* r, double& rateOfReturn, double& V);

//esporta i risultati su un file
bool EsportaRisultati(const std::string& fileName, double S, int n, double* w, double* r, double rateOfReturn, double V);

#endif


