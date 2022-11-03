#ifndef FUNKCIJOS_HPP
#define FUNKCIJOS_HPP

#include "Studentas.hpp"
#include "funkcijos.cpp"
#pragma once

int random();
int generuoti(int dydis, int pazk);
duom ivedimas(int &n);
double galutinis(duom temp, std::string a);
void isvedimas(duom temp);
bool gavoSkola(const duom& s, string d);
vector<duom> skirstykStudentus(vector<duom>& studentai, string d);
bool compare(duom a, duom b);
std::list<duom> skirstykStudentus(std::list<duom>& studentai, string d);


#endif