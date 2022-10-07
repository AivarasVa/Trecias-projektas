#include "mylib.hpp"
#include "Studentas.hpp"
#include "funkcijos.hpp"

int main(){
  struct duom asmuo1, temp;
  vector<duom>masyvas;
  int paz, pazk, m;
  string c;

  while (true){
    cout << "Ar duomenis skaitysite nuo failo? T/N ";
    cin >> c;
    if (c == "T" || c == "N") break;
    else cout << "Neteisinga ivestis. Pakartokite ivesti" << endl;
  }

  if (c == "T"){
    cout << "Kiek pazymiu tures studentai? ";
    cin >> pazk;
    try {std::ifstream fd("kursiokai.txt");
      while(!fd.eof()){
        fd >> asmuo1.var >> asmuo1.pav;
        for (int i =0; i<pazk; i++){
          fd >> paz;
          asmuo1.paz.push_back(paz);
        }
        fd >> asmuo1.egz;
        masyvas.push_back(asmuo1);
        asmuo1 = temp;
      }
      fd.close();
    }
    catch(std::exception& e){
      cout << "Failas neegzistuoja";
    }
    

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
  
  std::sort(masyvas.begin(), masyvas.end(), [](duom a, duom b){
    if (a.var != b.var)
	    return a.var < b.var;	
    else
      return a.pav < b.pav;
  }); 

  cout << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  cout << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  for (int i=0;i<masyvas.size();i++){
      isvedimas(masyvas[i]);
  }
}

