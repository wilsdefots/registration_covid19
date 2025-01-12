// projet_final.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
/////////////////////////////  Auteurs ///////////////////////////////////////////////////////////
///////////////////////// 1. Wilson FOTSING //////////////////////////////////////////////////////
///////////////////////// 2. Stephane   //////////////////////////////////////////////
/////////////////////////   //////////////////////////////////////////////
////////////////////////      ///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>  //pour les tableaux dynamiques
#include <string>
#include <cstdlib> // Pour system()

//inclusion des procedure non intermédiaire : Qui ne sont pas directement les questions posées,
//mais que nous avons crées pour faciliter le code

#include "Structure_Patient.h" 
#include "P_affichage_menu.h" 
#include "P_resultat_test.h" ;
#include "P_envoie_email.h" ; 
#include "P_creation_tableau_initial_patients.h" ;


vector<S_Patient> liste_patients;  //un tableau dynamique
vector<S_Patient> liste_suspects; //un tableau dynamique


void P_choix_option();


void P_remplissage_repertoire_covid19(); //pour l'option 1

void P_affichage_repertoire_malades(vector<S_Patient> liste_suspects); //Pour l'option 2


void P_affichage_cout_total_test(); // Option 3

void P_consultation_repertoire_patients(); // Option 4


void  P_sortie();  //Option 5


int main()
{
    int choix = 0;
    string lecture_clavier;

    P_creation_tableau_initial_patients(liste_patients,liste_suspects);
    P_affichage_menu();

    cout << " \n votre choix --->  ";
    cin >> choix;

    switch (choix)
    {
    case 1:
        P_remplissage_repertoire_covid19();
        cout << "Merci d'avoir complété ces informations ";
        P_choix_option();
        break;
    case 2:
        P_affichage_repertoire_malades(liste_suspects);
        cout << "Voulez-vous sortir ? o/n --> ";
        cin >> lecture_clavier;
        if (lecture_clavier == "n" || lecture_clavier == "N") {
            P_choix_option();
        }
        break;
    case 3:
        P_affichage_cout_total_test();
        cout << "\n Voulez-vous sortir ? o/n --> ";
        cin >> lecture_clavier;
        if (lecture_clavier == "n" || lecture_clavier == "N") {
            P_choix_option();
        }
        break;
    case 4:
        P_consultation_repertoire_patients();
        break;
    case 5:
        P_sortie();
        break;
    default:
        P_affichage_menu();
        break;
    }

    return 0;
}










void P_remplissage_repertoire_covid19() {
    //cette procedure s'execute si l'utilisateur choit l'option 1
    S_Patient patient;
    string entrer_patient;

    cout << "Entrez les informations sur le nouveau patient \n nom --> ";
    cin.ignore();
    getline(cin, patient.Nom);
   // cin >> patient.Nom ;

    cout << "Prenom   --> " ;
    cin.ignore();
    getline(cin, patient.Prenom); 

    cout << "Adresse courriel --> ";
    cin.ignore();
    getline(cin, patient.mail);
  

    cout << "Fait-il de la fievre ? 1 si oui  et 0 sinon. (rien d'autre)   --> ";
    cin >> patient.donnees_medicale.fiev;

    cout << "A t il des sensations de vomir ? 1 si oui et 0 sinon (rien d'autre)  --> ";
    cin >> patient.donnees_medicale.etatVomissement;

    cout << "A t il mal a la tete ? 1 si oui et 0 sinon (rien d'autre)  --> ";
    cin >> patient.donnees_medicale.Headeache;

    cout << "Sa temperature bucale : --> ";
    cin >> patient.donnees_medicale.temperature_bucale;


    do
    {
        cout << "Son taux d'oxigene (Doit etre entre 0 et 1) --> ";
        cin >> patient.donnees_medicale.spo2;
        if (patient.donnees_medicale.spo2 < 0 || patient.donnees_medicale.spo2 >1) {
            cout << "Veuiller entrer un nombre entre 0 et 1  --->";
        }
    } while ( (patient.donnees_medicale.spo2 <0) ||
              (patient.donnees_medicale.spo2 > 1) 
             );

    cout << "Combien a coute son test en $ ? (la reponse doit etre un reel)  --> ";
    cin >> patient.donnees_medicale.CoutTestCovid19;
    //Le test est terminé, on le rajoute à la liste des patients,puis on publie son résultat

    liste_patients.push_back(patient);
    P_resultat_test(patient, liste_suspects);

    //la console est pleine, on doit le nettoyer pour dégager de l'espace et acceuillir de nouvelles données

    system("cls"); /* ca ne fonctionne qu'avec windows. il ya des commandes similaires pour d autre 
    //plattes formes. bien vouloir commenter ceci si vous n avez pas Windows, sinon une erreur 
    //sera levée*/

    P_envoie_email(patient);
    cout << "\n Voulez-vous entrer un nouveau patient ? o/n ";
    cin >> entrer_patient;

    if (entrer_patient == "o"
        || entrer_patient == "O"
        || entrer_patient == "0"
        ) {
        P_remplissage_repertoire_covid19();
    }
    else {
        cout << " \n Merci d'avoir complete ces informations \n ";
    }
}

void P_affichage_repertoire_malades(vector<S_Patient> liste_suspects) {
    //si l'utilisateur a choisit l'option 2
    cout << " \n\n -----------------------------------------" <<
        "Liste des patients suspects : --------------------------------------\n"
        << "-----------------------------------------------------------"
        << "----------------------------------------------------\n\n";

    for (S_Patient suspect : liste_suspects) {
        cout << suspect.Nom << " "
            << suspect.Prenom << endl;
    }
    cout << "\n ----------------------------------------"
        << " Fin de la liste----------------------------------"
        << "--------------------------------------------"
        << "------------------------------------------------------------------"
        << "------------------------------------\n";
}


void P_consultation_repertoire_patients() {
    //choix de l'option 4
    cout << "---------------------------------------------------- \n"
        << "impression de la facture : \n";
    for (S_Patient patient : liste_patients) {
        cout << patient.Nom << " " << patient.Prenom
            << " : " << patient.donnees_medicale.CoutTestCovid19 << endl;

    }
    cout << "---------------------------------------------------- \n" ;
    P_affichage_cout_total_test();

}

void P_affichage_cout_total_test() {
    //Si l'utilisateur a choisit l'option 3 
    double cout_total = 0;
    for (S_Patient patient : liste_patients) {
        cout_total += patient.donnees_medicale.CoutTestCovid19;
    }
    cout << "La facture totale est de : " << cout_total << " $ \n";

}

void P_sortie() {
    cout << "Au plaisir de vous revoir prochainement :) \n ";
}




void P_choix_option() {
    system("cls"); // nettoyage de la console (Fonctionne uniquement sous Windows)
    int choix_option = 0;
    cout << " \n Rappel du menu : \n ";
    P_affichage_menu();
    cout << "\n Faites un choix parmis les option 1 a 5 "
        << " du menu  -->  ";
    cin >> choix_option;
    switch (choix_option)
    {
    case 1:
        P_remplissage_repertoire_covid19();
    case 2:
        P_affichage_repertoire_malades(liste_suspects);
        break;
    case 3:
        P_affichage_cout_total_test();
        break;
    case 4:
        P_consultation_repertoire_patients();
        break;
    case 5:
        P_sortie();
        break;
    default:
        break;
    }

}