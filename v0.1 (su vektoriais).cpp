#include "mylib.hpp"
#include<string>
#include <iostream>
#include <bits/stdc++.h>


struct duom{
  string var;
  string pav;
  vector<int> paz;
  int egz;
  int kiekis;
  double galutinis;
};

duom ivedimas(int &n);
double galutinis(duom temp, string a);
void isvedimas(duom temp, int n);
int random();

int main(){
  duom asmuo1, masyvas[25];
  int n, m;
  string a;
  
  while(true){
    cout<<"Iveskite studentu kieki: "; 
    while (true){
      cin>>n;
      if (!cin){
            cout << "Buvo ivestas ne skaicius. Pakartokite ivesti " << endl;
            cin.clear();
            cin.ignore();
            continue;
      }
      else break;
    }
    if (n < 0) cout << "Bloga ivestis " << endl;
    else break;
  }
 
  while (1){
          cout<<"Iveskite ar norite matyti vidurkius (Vid) ar medianas (Med) "; cin>>a;
          if (a == "Vid" || a == "Med"){
              break;
          }
          else{
              cout << "Neteisinga ivestis! ";
          }
  }
  
  for (int i=0;i<n;i++){
       masyvas[i]=ivedimas(m);
       masyvas[i].galutinis = galutinis(masyvas[i], a);  
    }

  if (a == "Vid"){cout << "Vardas      " << "Pavarde     "  << "Galutinis (Vid.)" << endl;}  
  else if (a == "Med") {cout << "Vardas      " << "Pavarde     "  << "Galutinis (Med.)" << endl;}
  cout << "--------------------------------------" << endl;
  for (int i=0;i<n;i++){
      isvedimas(masyvas[i], n);
  }
}

duom ivedimas(int &n){
  duom asmuo;
  int paz, egz, k;
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
    if(egz == -1){
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
    int i = 1;
    paz = 1;
    while (paz != 0){
        cout<<"Iveskite "<< i <<" pazymi (jei ivedete visus pazymius iveskite 0, o jei norite atsitiktinio pazymio iveskite -1): ";
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
            i++;
            continue;
        }
        else{
            cout << "Pazymys turi buti 10 balu sistemoje ";
        }     
    }
  }
  else{
    for (int kint=0;kint<asmuo.kiekis; kint++){
        while (true){
            cout<<"Iveskite "<<kint+1<<" pazymi: ";
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

int random(){
  srand(time(0));
 
  for(int i=0;i<10;i++)
      return ((rand() % 10) + 1); 
}

void isvedimas(duom temp, int n){
  cout << temp.var << std::setw(13) << temp.pav << std::setw(5) << std::setprecision(3) << temp.galutinis << endl;
}