/*
 * Sara Camassa, Emily Baquerizo
 * 29/09/2022
 * Tic Tac Toe
 */

#include <iostream>
#include <sstream>
#include <list>

using namespace std;

bool verification(int val, list<int> liste, bool& b){
    for(int i : liste){
        if(val == i){
            b = true;
        }
    }
    return b;
}

void affichage(string (&cases)[3][3]){
    cout << cases[0][0] + " | " + cases[0][1] + " | " + cases[0][2] << endl;
    cout << "_________" << std::endl;
    cout << cases[1][0] + " | " + cases[1][1] + " | " + cases[1][2] << endl;
    cout << "_________" << std::endl;
    cout << cases[2][0] + " | " + cases[2][1] + " | " + cases[2][2] << endl;
}

void regles(){
    cout << "Alignez trois signes identiques pour gagner." << endl;
    cout << "Choisissez les cases avec leur numéro comme suit: " << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "_________" << std::endl;
    cout << "4 | 5 | 6" << endl;
    cout << "_________" << std::endl;
    cout << "7 | 8 | 9" << endl;
    cout << endl;
    cout << "Debut de la partie" << endl;
}

int main() {
    string cases[3][3] = {
            {" ", " ", " "},
            {" ", " ", " "},
            {" ", " ", " "}
    };

    bool fini = false;
    bool joueur_1 = true;
    int tour = 0;
    list<int> reste = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    regles();

    //partie
    while(fini == false and tour < 9){
        //affichage plateau
        cout << endl;
        affichage(cases);
        //changer une case
        string coup = "";
        if(joueur_1 == true){
            cout << "tour du joueur 1: " << endl;
        }
        else{
            cout << "tour du joueur 2: " << endl;
        }
        cin >> coup;

        int choix = stoi(coup);
        bool vide = false;

        verification(choix, reste, vide);
        while(vide == false){
            cout << "veuillez mettre un chiffre valide" << endl;
            cin >> coup;
            choix = stoi(coup);
            verification(choix, reste, vide);
        }
        string symbole;
        if(joueur_1 == true){
            symbole = "o";
        }
        else{
            symbole = "x";
        };

        // changer les cases
        switch(choix){
            case 1:
                cases[0][0] = symbole;
                reste.remove(1);
                break;
            case 2:
                cases[0][1] = symbole;
                reste.remove(2);
                break;
            case 3:
                cases[0][2] = symbole;
                reste.remove(3);
                break;
            case 4:
                cases[1][0] = symbole;
                reste.remove(4);
                break;
            case 5:
                cases[1][1] = symbole;
                reste.remove(5);
                break;
            case 6:
                cases[1][2] = symbole;
                reste.remove(6);
                break;
            case 7:
                cases[2][0] = symbole;
                reste.remove(7);
                break;
            case 8:
                cases[2][1] = symbole;
                reste.remove(8);
                break;
            case 9:
                cases[2][2] = symbole;
                reste.remove(9);
                break;
        }

        //verification

        //lignes
        for(int i = 0; i <= 2; i++){
            if(cases[i][0].compare(cases[i][1]) == 0 and cases[i][1].compare(cases[i][2]) == 0 and cases[i][0] != " "){
                fini = true;
            };
        };
        //colonnes
        for(int i = 0; i <= 2; i++){
            if(cases[0][i].compare(cases[1][i]) == 0 and cases[1][i].compare(cases[2][i]) == 0 and cases[0][i] != " "){
                fini = true;
            };
        };
        //diag1
        if(cases[0][0] == cases[1][1] and cases[1][1] == cases[2][2] and cases[0][0] != " "){
            fini = true;
        };
        //diag2
        if(cases[0][2] == cases[1][1] and cases[1][1] == cases[2][0] and cases[1][1] != " "){
            fini = true;
        };
        joueur_1 = !joueur_1;
        tour++;
        cout << fini << endl;
    };

    affichage(cases);

    cout << "fin de la partie." << endl;
    if(joueur_1 == true and tour < 9){
        cout << "victoire du joueur 2!" << endl;
    }
    else if(joueur_1 == false and tour < 9){
        cout << "victoire du joueur 1!" << endl;
    }
    else{
        cout << "egalite!" << endl;
    }
    return 0;
}
