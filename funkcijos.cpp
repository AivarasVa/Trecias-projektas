#include "funkcijos.hpp"
#include "mylib.hpp"


int random(){
  using hrClock = std::chrono::high_resolution_clock;
  std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  std::uniform_int_distribution<int> dist(1, 10);
  for (int i = 0; i < 5; ++i) {
  return (dist(mt));
  }
  
}

duom ivedimas(int &n){
  duom asmuo;
  int paz, egz;  

  cout<<"Iveskite varda: "; cin>>asmuo.var;
  cout<<"Iveskite pavarde: "; cin>>asmuo.pav;
  
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
        asmuo.egz = random();
        break;
    }
    else if (egz >=1 && egz <=10){
        asmuo.egz = egz;
        break;
    }
    else{
        cout << "Pazymys turi buti 10 balu sistemoje ";
    }
  }
  
  while(true){
    cout<<"Iveskite semestro pazymiu kieki (jei nezinote kiek pazymiu bus iveskite 0): ";
    while (true){
        cin >> asmuo.kiekis;
        if (!cin){
            cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        else break;
    }
    if (asmuo.kiekis >= 0){
        break;
    }
    else {
        cout << "Neteisinga ivestis " << endl;
    }
  }

  if (asmuo.kiekis == 0){
    paz = 1;
    while (paz != 0){
        cout<<"Iveskite "<< asmuo.paz.size() + 1 <<" pazymi (jei ivedete visus pazymius iveskite 0, o jei norite atsitiktinio pazymio iveskite -1): ";
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
            asmuo.paz.push_back(random());
            continue;
        }
        else if (paz >=1 && paz <=10){
            asmuo.paz.push_back(paz);
            continue;
        }
        else{
            cout << "Pazymys turi buti 10 balu sistemoje ";
        }     
    }
  }
  else{
    for (int i=0;i<asmuo.kiekis; i++){
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
            asmuo.paz.push_back(paz);
            break;
            }
            else{
                cout << "Pazymys turi buti 10 balu sistemoje ";
            } 
        }
    }
  }
  return asmuo;
}

double galutinis(duom temp, string a){
  if (a == "Vid"){
    int suma = 0;
    for (int i=0; i<temp.paz.size(); i++){
      suma = suma + temp.paz[i];
    }
    return (((double)((double)suma/temp.paz.size()) * 0.4) + ((double)temp.egz * 0.6));
  }

  else if (a == "Med"){
    vector<int> t;

    for (int i=0; i<temp.paz.size(); i++){
      t.push_back(temp.paz[i]);
    }
    t.push_back(temp.egz);

    sort(t.begin(), t.end());

    if ((t.size())%2 == 0){
      return ((double)(((double)(t[((t.size()+1)/2)-1]+t[((t.size()+1)/2)])/2)*0.4) + ((double)temp.egz * 0.6));
    }
    else{
      return ((double)((t[((t.size()+2)/2)-1])*0.4) + ((double)temp.egz * 0.6));
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

void isvedimas(duom temp){
  std::stringstream a;
  a << std::left << setw (15) << temp.var << std::setw(20) << temp.pav << std::setw(21) << std::setprecision(3) << temp.galutinis[0] << std::setw(5) << temp.galutinis[1] << endl;
  cout << a.str();
  a.clear();
}

bool gavoSkola(const duom& s, string d) {
  if (d == "V") return s.galutinis[0] < 5;
  else return s.galutinis[1] < 5.0;
}

vector<duom> skirstykStudentus(vector<duom>& studentai, string d) {
    vector<duom> kieti, minksti;
    for (vector<duom>::size_type i = 0; i != studentai.size(); ++i){
      if (gavoSkola(studentai[i], d)) 
        minksti.push_back(studentai[i]);
      else
        kieti.push_back(studentai[i]);
    }
    studentai = kieti; 
    return minksti; 
}

bool compare(duom a, duom b){
  if (a.galutinis[0] != b.galutinis[0])
	    return a.galutinis[0] > b.galutinis[0];	
  else
    return a.galutinis[1] > b.galutinis[1];
}

std::list<duom> skirstykStudentus(std::list<duom>& studentai, string d) {
    std::list<duom> kieti, minksti;
    std::list<duom>::iterator itr = studentai.begin();
    for (itr; itr != studentai.end(); itr++){
      if (gavoSkola(*itr, d)) 
        minksti.push_back(*itr);
      else
        kieti.push_back(*itr);
    }
    studentai = kieti; 
    return minksti; 
}