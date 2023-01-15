#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
    private:
        string vardas;
        string pavarde;
        double nd[5];
        double egz;
        double galutinis;
        int n;
    public:
        // Konstruktorius
        Student(string vardas = "", string pavarde = "", int n = 0) {
            this->vardas = vardas;
            this->pavarde = pavarde;
            this->n = n;
        }
        // Duomenų įvedimo metodas
        void input() {
            cout << "Iveskite studento varda: " << endl;
            cin >> vardas;
            cout << "Iveskite studento pavarde: " << endl;
            cin >> pavarde;
            cout << "Iveskite kiek namu darbu atlikote: " << endl;
            cin >> n;
            cout << "Iveskite namu darbu rezultatus (10-balineje sistemoje): " << endl;
            for (int i = 0; i < n; i++) {
                cin >> nd[i];
            }
            cout << "Iveskite egzamino rezultata (10-balineje sistemoje): " << endl;
            cin >> egz;
        }
        // Duomenų išvedimo metodas
        void output() {
            cout << vardas << " " << pavarde << " ";
        }
        // Galutinio pažymio skaičiavimo metodas
        void calculate() {
            double vidurkis = 0;
            for (int i = 0; i < n; i++) {
                vidurkis += nd[i];
            }
            vidurkis = vidurkis / n;
            galutinis = 0.4 * vidurkis + 0.6 * egz;
        }
        // Galutinio pažymio išvedimo metodas
        void output_grade() {
            cout << fixed << setprecision(2) << "Galutinis (Vid.): " << galutinis << endl;
        }
};

int main() {
    int kiekis;
    cout << "Iveskite studentu kieki: " << endl;
    cin >> kiekis;
    Student **stud = new Student*[kiekis];
    for (int i = 0; i < kiekis; i++) {
        stud[i] = new Student();
        stud[i]->input();
    }
    cout << "Pavardė     Vardas       Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < kiekis; i++) {
        stud[i]->calculate();
        stud[i]->output();
        stud[i]->output_grade();
    }
    for (int i = 0; i < kiekis; i++) {
delete stud[i];
}
delete[] stud;
return 0;
}
