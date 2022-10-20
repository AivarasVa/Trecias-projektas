#include "mylib.hpp"
#include "Studentas.hpp"
#include "funkcijos.hpp"
using namespace std;

int generuoti(int dydis, int pazk);

int main(){
  struct duom asmuo1, temp;
  vector<duom>masyvas;
  int paz, pazk, m;
  string c, failas, d;
  std::chrono::duration<double>diff1;
  std::chrono::duration<double>diff2;
  std::chrono::duration<double>diff3;
  std::chrono::duration<double>diff4;

  while (true){
    cout << "Ar duomenis skaitysite nuo failo? T/N ";
    cin >> c;
    if (c == "T" || c == "N") break;
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }
  
  cout << "Ar norite sugeneruoti failą? T/N: ";
  cin >> d;
  int e;
  if (d == "T"){
    cout << "Kokio dydzio bus failas?: ";
    cin >> e;
    cout << "Kiek pazymiu tures studentai?: ";
    int f;
    cin >> f;
    auto start = std::chrono::high_resolution_clock::now();
    generuoti(e,f);
    auto end = std::chrono::high_resolution_clock::now();
    diff1=end-start;
    cout << "Sugeneravo per: " << diff1.count() << endl;
    failas = "in" + std::to_string(e) + ".txt";
  }
  else{
    cout << "Iveskite failo pavadinima: ";
    cin >> failas;
  }

  if (c == "T"){
    auto start = std::chrono::high_resolution_clock::now();
    string line;
    std::ifstream fd;
    fd.open(failas, ios::in);
      std::getline(fd, line);
      int pazk = 1;
      int ilgis = line.size();
      for (int j = 1; j <= ilgis; j++){
        if (line[j-1] == ' ' && line[j] != ' ') pazk++;
      }
    
      
      while(!fd.eof()){
        fd >> asmuo1.var >> asmuo1.pav;
        for (int i =0; i<pazk-3; i++){
          fd >> paz;
          asmuo1.paz.push_back(paz);
          
        }
        fd >> asmuo1.egz;
        
        masyvas.push_back(asmuo1);
        asmuo1 = temp;
      }
      fd.close();
      auto end = std::chrono::high_resolution_clock::now();
      diff2=end-start;
      cout << "Nuskaite per: " << diff2.count() << endl;
    
    

    for (int i = 0; i < masyvas.size(); i++){
      masyvas[i].galutinis[0] = galutinis(masyvas[i], "Vid");
      masyvas[i].galutinis[1] = galutinis(masyvas[i], "Med");
    }
    
  }
  else {
    char b = '1';
    while (b != 'T'){
      masyvas.push_back(ivedimas(m));
      masyvas[masyvas.size()-1].galutinis[0] = galutinis(masyvas[masyvas.size()-1], "Vid");
      masyvas[masyvas.size()-1].galutinis[1] = galutinis(masyvas[masyvas.size()-1], "Med");
      cout << "Ar norite baigti ivedima? T/N ";
      cin >> b;
    } 
  }
  
  auto start = std::chrono::high_resolution_clock::now();
  std::sort(masyvas.begin(), masyvas.end(), [](duom a, duom b){
    if (a.galutinis[0] != b.galutinis[0])
	    return a.galutinis[0] > b.galutinis[0];	
    else
      return a.galutinis[1] > b.galutinis[1];
  });
  int g;
  for (int i=0; i < masyvas.size(); i++){
    if (masyvas[i].galutinis[0] < 5){
      g = i;
      break;
    }
  } 
  auto end = std::chrono::high_resolution_clock::now();
  diff3=end-start;
  cout << "Surusiavo per: " << diff3.count() << endl;

  auto start1 = std::chrono::high_resolution_clock::now();
  std::ofstream fr("out" + std::to_string(e) + "galvociai.txt");
  std::ofstream fr2("out" + std::to_string(e) + "vargsiukai.txt");
  fr << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  fr2 << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr2 << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  for (int i=0;i<g;i++){
      std::stringstream a;
      temp = masyvas[i];
      a << std::left << setw (15) << temp.var << std::setw(20) << temp.pav << std::setw(21) << std::setprecision(3) << temp.galutinis[0] << std::setw(5) << temp.galutinis[1] << endl;
      fr << a.str();
      fr.clear();
  }
  for (int i=g;i<masyvas.size();i++){
      std::stringstream a;
      temp = masyvas[i];
      a << std::left << setw (15) << temp.var << std::setw(20) << temp.pav << std::setw(21) << std::setprecision(3) << temp.galutinis[0] << std::setw(5) << temp.galutinis[1] << endl;
      fr2 << a.str();
      fr2.clear();
  }
  auto end1 = std::chrono::high_resolution_clock::now();
  diff4=end1-start1;
  cout << "Isspausdino per: " << diff4.count() << endl;
  cout << "Is viso: " << diff1.count() + diff2.count() + diff3.count() + diff4.count() << endl;
}

