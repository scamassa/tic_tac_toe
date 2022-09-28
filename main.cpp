#include <iostream>
#include <sstream>
#include <list>

using namespace std;

int main() {
    //règles
    cout << "alignez trois signes identiques pour gagner" << endl;
    cout << "choisissez les cases avec leur numéro comme suit: " << endl;
    cout << "1 | 2 | 3" << endl;
    cout << "_________" << std::endl;
    cout << "4 | 5 | 6" << endl;
    cout << "_________" << std::endl;
    cout << "7 | 8 | 9" << endl;
    cout << endl;
    cout << "debut de partie" << endl;

    string cases[3][3] = {
            {" ", " ", " "},
            {" ", " ", " "},
            {" ", " ", " "}
    };

    bool fini = false;
    int tour = 0;
    list<int> reste= {1, 2, 3, 4, 5, 6, 7, 8, 9};
    while(fini == false and tour < 9){
        //affichage plateau
        cout << "tour " << tour + 1 << endl;
        cout << endl;
        cout << cases[0][0] + " | " + cases[0][1] + " | " + cases[0][2] << endl;
        cout << "_________" << std::endl;
        cout << cases[1][0] + " | " + cases[1][1] + " | " + cases[1][2] << endl;
        cout << "_________" << std::endl;
        cout << cases[2][0] + " | " + cases[2][1] + " | " + cases[2][2] << endl;
        //changer une case
        string coup = "";
        cout << "au tour du joueur 1: " << endl;
        cin >> coup;

        int choix = stoi(coup);


        while(choix > 9 or choix < 1){
            cout << "veuillez mettre un chiffre valide" << endl;
            cin >> coup;
            choix = stoi(coup);
        }
        //ajouter vérif case vide
        //ajouter altern joueur
        switch(choix){
            case 1:
                cases[0][0] = "o";
                reste.remove(1);
                break;
            case 2:
                cases[0][1] = "o";
                break;
            case 3:
                cases[0][2] = "o";
                break;
            case 4:
                cases[1][0] = "o";
                break;
            case 5:
                cases[1][1] = "o";
                break;
            case 6:
                cases[1][2] = "o";
                break;
            case 7:
                cases[2][0] = "o";
                break;
            case 8:
                cases[2][1] = "o";
                break;
            case 9:
                cases[2][2] = "o";
                break;
        }

        //verification


        //lignes
        for(int i = 0; i < 2; i++){
            if(cases[i][0].compare(cases[i][1]) == 0 and cases[i][1].compare(cases[i][2]) == 0 and cases[i][0] != " "){
                fini = true;
            };
        };
        //colonnes
        for(int i = 0; i < 2; i++){
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
        tour++;
    };

    cout << cases[0][0] + " | " + cases[0][1] + " | " + cases[0][2] << endl;
    cout << "_________" << std::endl;
    cout << cases[1][0] + " | " + cases[1][1] + " | " + cases[1][2] << endl;
    cout << "_________" << std::endl;
    cout << cases[2][0] + " | " + cases[2][1] + " | " + cases[2][2] << endl;

    cout << "fin de la partie!" << endl;
    return 0;
}
