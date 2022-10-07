#include "funkcijos.hpp"
#include "mylib.hpp"


int random(){
  srand(time(0));
 
  for(int i=0;i<10;i++)
      return ((rand() % 10) + 1); 
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
    double g;
    for (int i=0; i<temp.paz.size(); i++){
      suma = suma + temp.paz[i];
    }
    g = ((double)((double)suma/temp.paz.size()) * 0.4) + ((double)temp.egz * 0.6);
    return g;
  }

  else if (a == "Med"){
    vector<int> t;

    for (int i=0; i<temp.paz.size(); i++){
      t.push_back(temp.paz[i]);
    }
    t.push_back(temp.egz);

    sort(t.begin(), t.end());

    if ((t.size())%2 == 0){
      double g = ((double)(t[((t.size()+1)/2)-1]+t[((t.size()+1)/2)])/2);
      return g;
    }
    else{
      return (t[((t.size()+2)/2)-1]);
    }
  }
}



void isvedimas(duom temp){
  cout << std::left << setw (15) << temp.var << std::setw(20) << temp.pav << std::setw(21) << std::setprecision(3) << temp.galutinis[0] << std::setw(5) << temp.galutinis[1] << endl;
}