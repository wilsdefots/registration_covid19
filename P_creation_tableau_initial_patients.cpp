#include<iostream>
#include <vector>


#include "Structure_Patient.h" ;
#include "P_resultat_test.h" ;




void P_creation_tableau_initial_patients(vector<S_Patient>& liste_patients,vector<S_Patient>& liste_suspects) {

    S_Patient tableau[10] = { /*Nom, prenom, mail,             {coutTest, temp , spo2 , Head, fiev, etatVomiss,  result,   date            }*/
        /*0*/   {"Fotsing","Wilson","wfotsing@etu.uqac.ca",            {35    , 39   , 0.69 ,   1 ,   1 ,     1     ,         /*date du jour*/}},
        /*1*/   {"Guibony","Stephane","monbleonGstephane@etu.uqac.ca", {60    , 38   , 0.90 ,   1 ,   0 ,     1     ,                         }},
        /*2*/   {"Stephanie" ,"Balla", "stbal@gmail.com",              {17    , 41   , 0.79 ,   1 ,   1 ,     0     ,                         }},
        /*3*/   {"Tawe","Marcel","marcelst@yahoo.fr",                  {8     , 43   , 0.81 ,   1 ,   1 ,     1     ,                         }},
        /*4*/   {"KAMTO","Maurice","M.Kamto237@gmail.com",             {11.25 , 39.5 , 0.8  ,   1 ,   0 ,     1     ,                         }},
        /*5*/   {"Domtcheu","Yvana","Adamsmith@edima.cameroun.org",    {12.30 , 40.03, 0.79 ,   1 ,   1 ,     1     ,                         }},
        /*6*/   {"Jean-Brue","Larousse","larousse45@gmail..com",       {11    , 38.5 , 0.92 ,   0 ,   1 ,     0     ,                         }},
        /*7*/   {"Truc", "Adams","Adamelatruc@uqac.ca",                {6     , 41   , 0.85 ,   1 ,   0 ,     1     ,                         }},
        /*8*/   {"Mba","Emeran","nkunkuma27@hotmail.com",              {7     , 42   , 0.79 ,   1 ,   1 ,     1     ,                         }},
        /*9*/   {"Junior","Melissa","Melissaladouce@yahoo.fr",         {14    , 39   , 0.98 ,   0 ,   1 ,     0     ,                         }},
    };

    for (int i = 0; i < 10; i++) {
        P_resultat_test(tableau[i], liste_suspects);
        liste_patients.push_back(tableau[i]);

    }

}
