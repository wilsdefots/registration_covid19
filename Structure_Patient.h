#pragma once

#include<iostream>
#include<vector>

using namespace std;
struct S_Donnees_medicale {
    double CoutTestCovid19 = 0;
    double temperature_bucale = 38.5;
    double spo2 = 0.88;
    bool Headeache = 0; // egale a 1 si le patient a mal a la tete et 0 sinon
    bool fiev = 0; //1 Si il fait la fievre et 0 sinon
    bool etatVomissement = 0; //egal a 1 si le patient a envie de vomir et 0 sinon
    string resultat = "Negatif";
    time_t date{};
};


struct S_Patient {
    string Nom ;
    string Prenom ;
    string mail = "Ciuss_sanguenayLacSaintJean@clsc.gov.qc.ca";
    S_Donnees_medicale donnees_medicale ;
};

