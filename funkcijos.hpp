#ifndef FUNKCIJOS_HPP
#define FUNKCIJOS_HPP

#include "Studentas.hpp"
#include "funkcijos.cpp"
#pragma once

int random();
double galutinis1(vector<int> pazymiai, int egz, string a);
void NuoFailo (vector<Studentas>&a, string pav, string k);
int generuoti(int dydis, int pazk);
Studentas ivedimas(int &n, string k);
bool gavoSkola(Studentas s);
vector<Studentas> skirstykStudentus(vector<Studentas>& studentai);
vector<Studentas> skirstykStudentus2(vector<Studentas>& studentai);
void Isvedimas(std::vector<Studentas>a, std::vector<Studentas>b, int c);
void NuoFailo (list<Studentas>&a, string pav, string k);
bool compare(Studentas a, Studentas b);
std::list<Studentas> skirstykStudentus(std::list<Studentas>& studentai);
std::list<Studentas> skirstykStudentus2(std::list<Studentas>& studentai);
void Isvedimas(std::list<Studentas>a, std::list<Studentas>b, int c);

#endif