#include "mylib.hpp"
#include "Studentas.hpp"
#include "funkcijos.hpp"
#include<list>

int main(){
  std::list<duom>masyvas;
  int m, failoDydis = 0;
  string arNuoFailo, failoPavadinimas, arSugeneruoti, kriterijus;
  std::list<duom>::iterator itr;
  std::chrono::duration<double>diff;

  while (true){
    cout << "Ar galutini bala skaiciuoti pagal vidurki ar mediana? V/M ";
    cin >> kriterijus;
    cout << "Ar duomenis skaitysite nuo failo? T/N ";
    cin >> arNuoFailo;
    if (arNuoFailo == "T" || arNuoFailo == "N"){
      if (arNuoFailo == "T"){  
        while (true){
          cout << "Ar norite sugeneruoti faila? T/N ";
          cin >> arSugeneruoti;
          if (arSugeneruoti == "T"){
            cout << "Kokio dydzio bus failas?: ";
            cin >> failoDydis;
            generuoti(failoDydis, random());
            failoPavadinimas = "in" + std::to_string(failoDydis) + ".txt";
            break;
          }
          if (arSugeneruoti == "N"){
            cout << "Iveskite failo pavadinima: ";
            cin >> failoPavadinimas;
            NuoFailo(masyvas, failoPavadinimas);
            break;
          }
        }
        break;
      }
      else {
        char b = '1';
        while (b != 'T'){
          masyvas.push_back(ivedimas(m));
          cout << "Ar norite baigti ivedima? T/N ";
          cin >> b;
        }
        itr = masyvas.begin();
        for (itr; itr != masyvas.end(); itr++) {
          itr->galutinis[0] = galutinis(*itr, "Vid");
          itr->galutinis[1] = galutinis(*itr, "Med");
        }
      }
    }
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }


  //1 strategija

  auto start = std::chrono::high_resolution_clock::now();

  std::list<duom>masyvas2;
  masyvas.sort(compare);
  masyvas2 = skirstykStudentus(masyvas, kriterijus);

  auto end = std::chrono::high_resolution_clock::now();
  diff=end-start;
  cout << "1 strategija neoptimizuota: " << std::setprecision(6) <<diff.count() << endl;

  //2 strategija

  // auto start = std::chrono::high_resolution_clock::now();

  // std::list<duom>masyvas2;
  // masyvas.sort(compare);
  // masyvas2 = skirstykStudentus2(masyvas, kriterijus);

  // auto end = std::chrono::high_resolution_clock::now();
  // diff=end-start;
  // cout << "2 strategija neoptimizuota: " << std::setprecision(6) <<diff.count() << endl;

  Isvedimas(masyvas, masyvas2, failoDydis);
}

