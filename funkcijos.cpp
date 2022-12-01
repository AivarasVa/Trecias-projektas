#include "funkcijos1.hpp"
#include "mylib.hpp"
#include "Studentas1.hpp"

int random(){
  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1, 10);
  for (int i = 0; i < 5; ++i) {
  return (dist(mt));
  }
  
}

double galutinis1(vector<int> pazymiai, int egz, string a){
  if (a == "V"){
    int suma = 0;
    for (int i=0; i<pazymiai.size(); i++){
      suma = suma + pazymiai[i];
    }
    return (((double)((double)suma/pazymiai.size()) * 0.4) + ((double)egz * 0.6));
  }

  else if (a == "M"){
    vector<int> t;

    for (int i=0; i<pazymiai.size(); i++){
      t.push_back(pazymiai[i]);
    }
    t.push_back(egz);

    sort(t.begin(), t.end());

    if ((t.size())%2 == 0){
      return ((double)(((double)(t[((t.size()+1)/2)-1]+t[((t.size()+1)/2)])/2)*0.4) + ((double)egz * 0.6));
    }
    else{
      return ((double)((t[((t.size()+2)/2)-1])*0.4) + ((double)egz * 0.6));
    }
  }
}

void NuoFailo (vector<Studentas>&a, string pav, string k){
  int pazymiuKiekis = 1, paz;
  string line;

  std::ifstream fd;
  fd.open(pav, std::ios::in);

  std::getline(fd, line);
  for (int j = 1; j <= line.size(); j++){
    if (line[j-1] == ' ' && line[j] != ' ') pazymiuKiekis++;
  }
  
  string vardas;
  string pavarde;
  vector<int> pazymiai;
  int egz;
  int kiekis;
  double galutinis;

  while(!fd.eof()){
    fd >> vardas >> pavarde;
    for (int i =0; i<pazymiuKiekis-3; i++){
      fd >> paz;
      pazymiai.push_back(paz);
    }
    fd >> egz;
    if (k == "V"){
      galutinis = galutinis1(pazymiai, egz, k);
    }
    else{
      galutinis = galutinis1(pazymiai, egz, "M");
    }
    Studentas *naujasStudentas = new Studentas(vardas, pavarde, pazymiai, egz, kiekis, galutinis);
    a.emplace_back(naujasStudentas);
    
  }
  
  fd.close();
  
}

int generuoti(int dydis, int pazk){
  std::ofstream fr;
  fr.open("in" + std::to_string(dydis) + ".txt");
  std::stringstream a;
  a << std::left << std::setw (15) << "Vardas" << std::setw (19) << "Pavarde";
  for (int k = 0; k < pazk; k++){
    a << std::setw(21) << "ND" + std::to_string(k+1);
  }
  a << "EGZ" << endl;

  for (int i = 1; i <= dydis; i++){
    a << std::left << setw (15) << "Vardas" + std::to_string(i) << std::setw(20) << "Pavarde" + std::to_string(i);
    for (int j=0; j<pazk; j++){
      a << std::setw(21) << random();
    }
    if (i == dydis)a << random();
    else a << random() << endl;
  }
  fr << a.str();
  fr.close();
}

bool gavoSkola(Studentas s) {
  return true;
}

vector<Studentas> skirstykStudentus(vector<Studentas>& studentai){
    vector<Studentas>::iterator iter = studentai.begin();
    vector<Studentas> kieti, minksti;
    for (iter; iter != studentai.end(); iter++){
      if (gavoSkola(*iter))
        minksti.push_back(*iter);
      else
        kieti.push_back(*iter);
    }
    studentai = kieti; 
    return minksti; 
}

void Isvedimas(std::vector<Studentas>a, std::vector<Studentas>b, int c){
  std::ofstream fr("out" + std::to_string(c) + "galvociai.txt");
  std::ofstream fr2("out" + std::to_string(c) + "vargsiukai.txt");
  fr << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  fr2 << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr2 << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  unsigned int vecSize = a.size();
  for (int i = 0; i < vecSize; i++){
      std::stringstream d;
      d << std::left << setw (15) << a[i].vardas << std::setw(20) << a[i].pavarde << std::setw(21) << a[i].galutinis << endl;
      fr << d.str();
      fr.clear();
  }
  vecSize = b.size();
  for (int i = 0; i < vecSize; i++){
      std::stringstream d;
      d << std::left << setw (15) << b[i].vardas << std::setw(20) << b[i].pavarde << std::setw(21) << b[i].galutinis << endl;
      fr2 << d.str();
      fr2.clear();
  }
}
