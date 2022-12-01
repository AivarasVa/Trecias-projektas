#ifndef STUDENTAS1_H
#define STUDENTAS1_H

#include <iostream>
#include <string>
#include <vector>
#pragma once

using namespace std;

class Studentas{
    public:
        string *vardas;
        string *pavarde;
        vector<int> *pazymiai;
        int *egz;
        int *kiekis;
        double *galutinis;

        Studentas(string var, string pav, vector<int> paz, int e, int k, double g){
            vardas = new string;
            pavarde = new string;
            pazymiai = new vector<int>;
            egz = new int;
            kiekis = new int;
            galutinis = new double;

            *vardas = var;
            *pavarde = pav;
            *pazymiai = paz;
            *egz = e;
            *kiekis = k;
            *galutinis = g;
        };

        ~Studentas(){delete vardas;
        delete pavarde;
        delete pazymiai;
        delete egz;
        delete kiekis;
        delete galutinis;};


    private:
        
};

#endif