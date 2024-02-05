#include "iostream"
#include "Node.h"
#include "cstring"
#include "string" // ez lehet hogy nem fog kelleni
using namespace std;


int main() {
    cout << "Köszöntöm a programban, kérem válaszon ki egyet az alábbi opciók közül és írja be a terminálba a számát.\n";
    int prompt;
    Node *root = new Node(); // létrehozzuk a root Node-ot
    do {
        cout << "\n[0] Kilépés \n[1] Szó hozzáadása\n[2] Szó keresése\n[2] Szótár törlése" << endl;
        cin >> prompt;
    
        switch(prompt) {
            case 1: {
                string input;
                cout << "Kérem írja be a hozzáadni kívánt szót: ";
                cin >> input;
                bool back = root->addWord(input);
                if (back) cout << "\nA szó hozzáadása sikeresen megtörtént.\n";
                else cout << "\nA szó hozzáadása sikertelen volt.\n";
            } break;
            case 2: {
                string input;
                cout << "Kérem írja be a keresni kívánt szót: ";
                cin >> input;
                int back = root->search(input);
                if (back == input.length()) cout << "\nA teljes szó benne van már a szótárban.\n";
                else if (back == 0) cout << "A keresett szó nem található a szótárban.\n";
                else cout << "A keresett szó nem található, viszont egészen eddig egyezik: " + input.erase(back); + ".\n";
            } break;
            case 3: {delete(root); cout << "\nAz adatbázis törlése befejeződött.\n";}
            break;
            default: {cout << "Kilépés"; return 0;} // ez nagyon ideiglenes az isten szerelmére kérlek cisnáld meg később rendesen köszi puszi
        }
    } while (prompt != 0);
    
    return 0;
}
