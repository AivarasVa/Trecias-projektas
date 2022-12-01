#include "funkcijos.hpp"
#include "mylib.hpp"
#include "Studentas.hpp"

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
  return s.getGal() < 5;
}

Studentas ivedimas(int &n, string k){

  Studentas asmuo;
  string vardas;
  string pavarde;
  vector<int> pazymiai;
  int egz;
  int kiekis;
  double galutinis; 

  cout<<"Iveskite varda: "; cin>> vardas;
  cout<<"Iveskite pavarde: "; cin>> pavarde;
  
  while (true){
    cout<<"Iveskite egzamino paz. (jei norite atsitiktinio skaiciaus iveskite -1): ";
    while (true){
        cin >> egz;
        if (!cin){
            cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        else break;
    }
    if (egz == -1){
        egz = random();
        break;
    }
    else if (egz >=1 && egz <=10){
        egz = egz;
        break;
    }
    else{
        cout << "Pazymys turi buti 10 balu sistemoje ";
    }
  }
  
  while(true){
    cout<<"Iveskite semestro pazymiu kieki (jei nezinote kiek pazymiu bus iveskite 0): ";
    while (true){
        cin >> kiekis;
        if (!cin){
            cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        else break;
    }
    if (kiekis >= 0){
        break;
    }
    else {
        cout << "Neteisinga ivestis " << endl;
    }
  }

  if (kiekis == 0){
    int paz = 1;
    while (paz != 0){
        cout<<"Iveskite "<< pazymiai.size() + 1 <<" pazymi (jei ivedete visus pazymius iveskite 0, o jei norite atsitiktinio pazymio iveskite -1): ";
        while (true){
            cin >> paz;
            if (!cin){
                cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            else break;
        }
        if (paz == 0){
            break;
        }
        else if (paz == -1){
            pazymiai.push_back(random());
            continue;
        }
        else if (paz >=1 && paz <=10){
            pazymiai.push_back(paz);
            continue;
        }
        else{
            cout << "Pazymys turi buti 10 balu sistemoje ";
        }     
    }
  }
  else{
    for (int i=0;i<kiekis; i++){
      int paz;
        while (true){
            cout<<"Iveskite "<<i+1<<" pazymi: ";
            while (true){
                cin >> paz;
                if (!cin){
                    cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                else break;
            }
            if (paz >=1 && paz <=10){
            pazymiai.push_back(paz);
            break;
            }
            else{
                cout << "Pazymys turi buti 10 balu sistemoje ";
            } 
        }
    }
  }
  
  Studentas naujas = Studentas(vardas, pavarde, pazymiai, egz, kiekis, galutinis1(pazymiai, egz, k));
  pazymiai.clear();
  return naujas;
}

//Vector

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
  vector<int> temp;
  int egz;
  int kiekis = pazymiuKiekis-3;
  double galutinis;
  Studentas *naujasStudentas = NULL;
  naujasStudentas = new Studentas;
  while(!fd.eof()){
    pazymiai = temp;
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
    
    *naujasStudentas = Studentas(vardas, pavarde, pazymiai, egz, kiekis, galutinis);
    a.push_back(*naujasStudentas);
    
  }
  delete naujasStudentas;
  fd.close();
  
}

vector<Studentas> skirstykStudentus(vector<Studentas>& studentai){
    vector<Studentas>::iterator iter = studentai.begin();
    vector<Studentas> kieti, minksti;
    for (iter; iter != studentai.end(); iter++){
      if (iter->getGal() < 5)
        minksti.push_back(*iter);
      else
        kieti.push_back(*iter);
    }
    studentai = kieti; 
    kieti.clear();
    return minksti; 
}

vector<Studentas> skirstykStudentus2(vector<Studentas>& studentai) {
    vector<Studentas> minksti;
    vector<Studentas>::iterator iter = studentai.begin();
    for (auto i = studentai.begin(); i != studentai.end(); ++i){
      if (gavoSkola(*i)){
        minksti.push_back(*i);
        studentai.erase(i);
        i--;
      }
    }
    return minksti; 
}

void Isvedimas(std::vector<Studentas>a, std::vector<Studentas>b, int c){
  std::ofstream fr("out" + std::to_string(c) + "galvociai.txt");
  std::ofstream fr2("out" + std::to_string(c) + "vargsiukai.txt");
  fr << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis" << endl; 
  fr << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  fr2 << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis" << endl; 
  fr2 << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  vector<Studentas>::iterator iter = a.begin();
  for (iter; iter != a.end(); iter++){
      std::stringstream d;
      d << std::left << setw (15) << iter->getVar() << std::setw(20) << iter->getPav() << std::setw(21) << setprecision(3) << iter->getGal() << endl;
      fr << d.str();
      fr.clear();
  }
  iter = b.begin();
  for (iter; iter != b.end(); iter++){
      std::stringstream d;
      d << std::left << setw (15) << iter->getVar() << std::setw(20) << iter->getPav() << std::setw(21) << setprecision(3) << iter->getGal() << endl;
      fr2 << d.str();
      fr2.clear();
  }
}

//List

void NuoFailo (list<Studentas>&a, string pav, string k){
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
  vector<int> temp;
  int egz;
  int kiekis = pazymiuKiekis-3;
  double galutinis;
  
  while(!fd.eof()){
    pazymiai = temp;
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
    
    Studentas naujasStudentas = Studentas(vardas, pavarde, pazymiai, egz, kiekis, galutinis);
    pazymiai.clear();
    a.push_back(naujasStudentas);
  }
  
  fd.close();
  
}

bool compare(Studentas a, Studentas b){
  return a.getGal() > b.getGal();
}

std::list<Studentas> skirstykStudentus(std::list<Studentas>& studentai) {
    std::list<Studentas> kieti, minksti;
    for (auto &a : studentai){
      if (gavoSkola(a)) 
        minksti.push_back(a);
      else
        kieti.push_back(a);
    }
    studentai = kieti; 
    return minksti; 
}

std::list<Studentas> skirstykStudentus2(std::list<Studentas>& studentai) {
    std::list<Studentas> minksti;
    std::list<Studentas>::iterator itr = studentai.begin();

    while (itr != studentai.end()){
      if (gavoSkola(*itr)){
        minksti.push_back(*itr);
        itr = studentai.erase(itr);
      }
      else{
        itr++;
      }
    }
    return minksti; 
}

void Isvedimas(std::list<Studentas>a, std::list<Studentas>b, int c){
    std::list<Studentas>::iterator itr;
  std::ofstream fr("out" + std::to_string(c) + "galvociai.txt");
  std::ofstream fr2("out" + std::to_string(c) + "vargsiukai.txt");
  fr << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  fr2 << std::left << std::setw (15) << "Vardas" << std::setw (15) << "Pavarde"  << std::setw (20) << "Galutinis (Vid.)" << std::setw (15) << "Galutinis (Med.)"<< endl; 
  fr2 << std::setw(65) << std::setfill('-') << "" << std::setfill(' ') << endl;
  itr = a.begin();
  for (itr; itr != a.end(); itr++){
      std::stringstream a;
      a << std::left << setw (15) << itr->getVar() << std::setw(20) << itr->getPav() << std::setw(21) << setprecision(3) << itr->getGal() << endl;
      fr << a.str();
      fr.clear();
  }
  itr = b.begin();
  for (itr; itr != b.end(); itr++){
      std::stringstream a;
      a << std::left << setw (15) << itr->getVar() << std::setw(20) << itr->getPav() << std::setw(21) << setprecision(3) << itr->getGal() << endl;
      fr2 << a.str();
      fr2.clear();
  }
}