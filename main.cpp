#include "mylib.hpp"
#include "Studentas1.hpp"
#include "funkcijos1.hpp"


vector<Studentas> skirstykStudentus2(vector<Studentas>& studentai) {
    vector<Studentas> minksti;
    for (auto i = studentai.begin(); i != studentai.end(); ++i){
      if (gavoSkola(*i)){
        minksti.push_back(*i);
        studentai.erase(i);
        i--;
      }
    }
    return minksti; 
}

int main(){
  cout << "1" << endl;
  vector<Studentas>masyvas;
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
            NuoFailo(masyvas, failoPavadinimas, kriterijus);
            break;
          }
        }
        break;
      }
      // else {
      //   char b = '1';
      //   while (b != 'T'){
      //     masyvas.push_back(ivedimas(m));
      //     cout << "Ar norite baigti ivedima? T/N ";
      //     cin >> b;
      //   }
      //   for (int i = 0; i < masyvas.size(); i++) {
      //     masyvas[i].galutinis[0] = galutinis(masyvas[i], "Vid");
      //     masyvas[i].galutinis[1] = galutinis(masyvas[i], "Med");
      //   }
      // }
    }
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }
  
  std::sort(masyvas.begin(), masyvas.end(), [](Studentas a, Studentas b){
	    return a.galutinis > b.galutinis;	
  });
  
  // auto start = std::chrono::high_resolution_clock::now();
  // vector<Studentas>masyvas2;
  // masyvas2 = skirstykStudentus(masyvas);

  // auto end = std::chrono::high_resolution_clock::now();
  // diff=end-start;
  // cout << "1 strategija neoptimizuota: " <<diff.count() << endl;

  auto start = std::chrono::high_resolution_clock::now();

  vector<Studentas> masyvas2;
  masyvas2 = skirstykStudentus2(masyvas);

  auto end = std::chrono::high_resolution_clock::now();
  diff=end-start;
  cout << "2 strategija neoptimizuota: " << std::setprecision(5) << diff.count() << endl;

  Isvedimas(masyvas, masyvas2, failoDydis);
}

