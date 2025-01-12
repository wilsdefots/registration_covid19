
#include <iostream>
 

#include "Structure_Patient.h" ;


using namespace std;



void P_envoie_email(S_Patient patient) {
    cout << " \n Resultat de votre examen : " << patient.donnees_medicale.resultat
        << " \n consultez vos courriels, nous vous avons envoye \n "
        << " un message vous indiquant la procedure a suivre a l'adresse : "
        << patient.mail << endl << endl;
}