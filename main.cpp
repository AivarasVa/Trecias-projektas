#include "mylib.hpp"
#include "Studentas.hpp"
#include "funkcijos.hpp"
#define pirma  
#define vectoriai

int main(){
  #ifdef vectoriai
  vector<Studentas>masyvas;
  int m, failoDydis = 0;
  string arNuoFailo, failoPavadinimas, arSugeneruoti, kriterijus;

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
      else {
        char b = '1';
        while (b != 'T'){
          masyvas.push_back(ivedimas(m, kriterijus));
          cout << "Ar norite baigti ivedima? T/N ";
          cin >> b;
        }
        break;
      }
    }
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }

  #ifdef pirma
   std::sort(masyvas.begin(), masyvas.end(), [](Studentas a, Studentas b){
	      return a.getGal() > b.getGal();	
  });
  
  vector<Studentas>masyvas2 = skirstykStudentus(masyvas);

  Isvedimas(masyvas, masyvas2, failoDydis);
  #endif

  #ifdef antra
  std::sort(masyvas.begin(), masyvas.end(), [](Studentas a, Studentas b){
	      return a.getGal() > b.getGal();	
  });

  vector<Studentas>masyvas2 = skirstykStudentus2(masyvas);

  Isvedimas(masyvas, masyvas2, failoDydis);
  #endif

  #ifdef trecia
  auto start = std::chrono::high_resolution_clock::now();
  std::sort(masyvas.begin(), masyvas.end(), [](Studentas a, Studentas b){
	      return a.getGal() > b.getGal();	
  });

  auto it = std::find_if(masyvas.begin(), masyvas.end(), [](Studentas a){return a.getGal() < 5;});

  vector<Studentas>masyvas3(it, masyvas.end());
  vector<Studentas>masyvas2(masyvas.begin(), it);
  masyvas.clear();
  
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff=end-start;
  cout << "1 strategija neoptimizuota: " << std::setprecision(4) <<diff.count() << endl;

  Isvedimas(masyvas2, masyvas3, failoDydis);

  #endif
  #endif

  #ifdef listai
  
  std::list<Studentas>masyvas;
  int m, failoDydis = 0;
  string arNuoFailo, failoPavadinimas, arSugeneruoti, kriterijus;
  
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
      else {
        char b = '1';
        while (b != 'T'){
          masyvas.push_back(ivedimas(m, kriterijus));
          cout << "Ar norite baigti ivedima? T/N ";
          cin >> b;
        }
        break;
      }
    }
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }
 
  #ifdef pirma
  masyvas.sort(compare);
  std::list<Studentas>masyvas2 = skirstykStudentus(masyvas);
  Isvedimas(masyvas, masyvas2, failoDydis);
  #endif

  #ifdef antra

  masyvas.sort(compare);
  std::list<Studentas>masyvas2 = skirstykStudentus2(masyvas);
  Isvedimas(masyvas, masyvas2, failoDydis);

  #endif

  #ifdef trecia
  Studentas a("Aivaras", "Varkalis", {10, 10}, 10, 2, 10);
  cout << a << endl;
  #endif
  #endif
}

