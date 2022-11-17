#include "mylib.hpp"
#include "Studentas.hpp"
#include "funkcijos.hpp"

int main(){
  vector<duom>masyvas;
  int m, failoDydis = 0;
  string arNuoFailo, failoPavadinimas, arSugeneruoti, kriterijus;
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
        for (int i = 0; i < masyvas.size(); i++) {
          masyvas[i].galutinis[0] = galutinis(masyvas[i], "Vid");
          masyvas[i].galutinis[1] = galutinis(masyvas[i], "Med");
        }
      }
    }
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }

  std::sort(masyvas.begin(), masyvas.end(), [](duom a, duom b){
    if (a.galutinis[0] != b.galutinis[0])
	    return a.galutinis[0] > b.galutinis[0];	
    else
      return a.galutinis[1] > b.galutinis[1];
  });

  //1 Strategija

  auto start = std::chrono::high_resolution_clock::now();
  vector<duom>masyvas2;
  masyvas2 = skirstykStudentus(masyvas, kriterijus);

  auto end = std::chrono::high_resolution_clock::now();
  diff=end-start;
  cout << "1 strategija neoptimizuota: " <<diff.count() << endl;

  //2 Strategija

  // auto start = std::chrono::high_resolution_clock::now();

  // vector<duom> masyvas2;
  // masyvas2 = skirstykStudentus2(masyvas, kriterijus);

  // auto end = std::chrono::high_resolution_clock::now();
  // diff=end-start;
  // cout << "2 strategija neoptimizuota: " << std::setprecision(5) << diff.count() << endl;

  //Budas su algoritmais

  // auto start = std::chrono::high_resolution_clock::now();

  // vector<duom>masyvas2;
  // vector<duom>masyvas3;

  // auto it = std::partition(masyvas.begin(), masyvas.end(), [](duom a){return a.galutinis[0] >= 5;});

  // std::vector<duom>::iterator itr = masyvas.begin();
  // for (itr; itr != it; itr++){
  //   masyvas2.push_back(*itr);
  // }
  
  // for (it; it != masyvas.end(); it++){
  //   masyvas3.push_back(*it);
  // }
  
  // auto end = std::chrono::high_resolution_clock::now();
  // diff=end-start;
  // cout << "3 strategija su algoritmais: " << diff.count() << endl;

  Isvedimas(masyvas, masyvas2, failoDydis);
}

