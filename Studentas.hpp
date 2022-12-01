#ifndef STUDENTAS1_H
#define STUDENTAS1_H

#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Studentas{
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

        ~Studentas(){};

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
        }

        friend std::ostream& operator<<(std::ostream& out, Studentas &a){
            out << a.vardas << " " << a.pavarde << "\n";
            for (int i = 0; i < a.kiekis; i++){
                out << a.pazymiai[i] << " ";
            }
            out << "\n" << a.egz << " " << a.galutinis;
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

        string getVar() const{
            return vardas;
        };

        string getPav() const{
            return pavarde;
        };

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

    private:
        string vardas;
        string pavarde;
        vector<int> pazymiai;
        int egz;
        int kiekis;
        double galutinis;
};

#endif