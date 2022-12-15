#ifndef STUDENTAS1_H
#define STUDENTAS1_H

#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Zmogus{
    protected:
        string vardas;
        string pavarde;
    public:
        Zmogus(){};

        Zmogus(string var, string pav){
            vardas = var;
            pavarde = pav;
        }

        ~Zmogus(){};

        virtual void abstrakti() = 0;

        string getVar() const{
            return vardas;
        };

        string getPav() const{
            return pavarde;
        };
};

class Studentas: public Zmogus{
    private:
        vector<int> pazymiai;
        int egz;
        int kiekis;
        double galutinis;
    public:
        Studentas(){
            int egz = 0;
            int kiekis = 0;
            double galutinis = 0;
        };

        Studentas(string var, string pav, vector<int> paz, int e, int k, double g){
            vardas = var;
            pavarde = pav;
            pazymiai = paz;
            egz = e;
            kiekis = k;
            galutinis = g;
        };

        ~Studentas(){pazymiai.clear();};

        Studentas(const Studentas& other){
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egz = other.egz;
            kiekis = other.kiekis;
            galutinis = other.galutinis;
        }

        Studentas& operator= (const Studentas& other){
            if(this == &other) return *this;
            
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egz = other.egz;
            kiekis = other.kiekis;
            galutinis = other.galutinis;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, Studentas &a){
            out << a.vardas << " " << a.pavarde << " " << a.galutinis;
        }

        friend std::istream& operator>>(std::istream& in, Studentas &a){
            in >> a.vardas >> a.pavarde >> a.kiekis;
            for (int i = 0; i < a.kiekis; i++){
                int b;
                in >> b;
                a.pazymiai.push_back(b);
            }
            in >> a.egz;
        }

        virtual void abstrakti(){};

        vector<int> getPaz() const{
            return pazymiai;
        };

        int getEgz() const{
            return egz;
        };

        int getKiek() const{
            return kiekis;
        };

        double getGal() const{
            return galutinis;
        };
};

#endif