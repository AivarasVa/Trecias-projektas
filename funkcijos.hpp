#ifndef FUNKCIJOS_HPP
#define FUNKCIJOS_HPP

#include "Studentas.hpp"
#include "funkcijos.cpp"
#pragma once

int random();
int generuoti(int dydis, int pazk);
void NuoFailo (std::list<duom>&a, string pav);
void NuoFailo (std::vector<duom>&a, string pav);
void Isvedimas(std::list<duom>a, std::list<duom>b, int c);
void Isvedimas(std::vector<duom>a, std::vector<duom>b, int c);
double galutinis(duom temp, std::string a);
void isvedimas(duom temp);
bool gavoSkola(const duom& s, string d);
vector<duom> skirstykStudentus(vector<duom>& studentai, string d);
bool compare(duom a, duom b);
std::list<duom> skirstykStudentus(std::list<duom>& studentai, string d);
vector<duom> skirstykStudentus2(vector<duom>& studentai, string d);
std::list<duom> skirstykStudentus2(std::list<duom>& studentai, string d);


#endif