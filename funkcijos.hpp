#ifndef FUNKCIJOS_HPP
#define FUNKCIJOS_HPP

#include "Studentas1.hpp"
#include "funkcijos1.cpp"
#pragma once

int random();
double galutinis1(vector<int> pazymiai, int egz, string a);
void NuoFailo (vector<Studentas>&a, string pav, string k);
int generuoti(int dydis, int pazk);
bool gavoSkola(Studentas s);
vector<Studentas> skirstykStudentus(vector<Studentas>& studentai);
void Isvedimas(std::vector<Studentas>a, std::vector<Studentas>b, int c);

#endif