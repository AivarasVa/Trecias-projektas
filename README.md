# Pirmas-projektas
**V0.1:**

Programa, kuri vartotojui įvedus arba atsitiktinai sugeneravus duomenis apie studentą apskaičiuoja jo galutinį balą dviem būdais (pagal vidurkį arba medianą).
Naudojamas tradicinis dinaminis masyvas ir vektoriai.

**V0.2:**

Papildyta pirma versija, dabar galima duomenis skaityti nuo failo.

**V0.3:**

Papildyta antra versija, dabar nuskaityti duomenys yra surūšiuojami ir padalinami į dvi grupes, bei įrašomi į failą.

**V0.4**

Papildyta trečia versija. Lyginamos programų su konteineriais vector ir list spartos.

Programos veikimo greičiai:

- Failo dydis: 1000

**Vector**:                        Nuskaitė per: 0.0021419
Surūšiavo per: 0.0040818
Iš viso: 0.0062237

**List**: Nuskaitė per: 0.0022212
Surūšiavo per: 0.0027224
Iš viso: 0.0049436

- Failo dydis: 10000

**Vector**:                        Nuskaitė per: 0.0178835
Surūšiavo per: 0.0572729
Iš viso: 0.0751564

**List**: Nuskaitė per: 0.01864
Surūšiavo per: 0.0465655
Iš viso: 0.0652055

- Failo dydis: 100000

**Vector**:                        Nuskaitė per: 0.208413
Surūšiavo per: 0.760154
Iš viso: 0.968567

**List**: Nuskaitė per: 0.172937
Surūšiavo per: 0.510313
Iš viso: 0.683249


- Failo dydis: 1000000

**Vector**:                        Nuskaitė per: 3.16282
Surūšiavo per: 11.4759
Iš viso: 14.6387

**List**: Nuskaitė per: 2.54738
Surūšiavo per: 7.9858
Iš viso: 10.5332


- Failo dydis: 10000000

**Vector**:                        Nuskaitė per: 21.3424
Surūšiavo per: 92.5991
Iš viso: 113.942

**List**: Nuskaitė per: 22.2755
Surūšiavo per: 87.5083
Iš viso: 109.784


**Kompiuterio parametrai**:

Procesorius: Intel(R) Core(TM) i3-1005G1 CPU @ 1.20GHz 1.19 GHz

RAM: 8 GB


**V1.0:**

Papildyta v0.4 versija, kurioje yra lyginamos dvi rūšiavimo strategijos.
1 strategija: Bendro studentai konteinerio skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietiakų". 
2 strategija: Bendro studentų konteinerio skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai".

Rezultatai:
**1 strategija:**

Failo dydis 1000:

Vector 0.000984
List 0.004993

Failo dydis 10000:

Vector 0.005996
List 0.056049

Failo dydis 100000:

Vector 0.063001
List 0.712986

Failo dydis 1000000:

Vector 0.655818
List 7.51979


**2 strategija:**

Failo dydis 1000:

Vector 0.012999
List 0.004017

Failo dydis 10000:

Vector 0.99309
List 0.053008

Failo dydis 100000:

Vector 153.39
List 0.674999

Failo dydis 1000000:

Vector >20min
List 7.33066

Trečioji strategija naudojant std partition algoritmą:

Failo dydis 1000:

Vector 0.001

Failo dydis 10000:

Vector 0.006001

Failo dydis 100000:

Vector 0.063999

Failo dydis 1000000:

Vector 0.659923

Išvados: 1 strategija yra žymiai greitesnė vektoriams, o antroji listams. Panaudojus std::partition algoritmą buvo gautas panašus rezultatas lyginant su pirmąja strategija.

**Kompiuterio parametrai:**

Procesorius: 12th Gen Intel(R) Core(TM) i7-12700H   2.30 GHz
RAM: 16GB


Finalinės programos sudėtis:

Du pagrindiniai failai: Su_vektoriais.cpp ir Su_list.cpp

Duomenų struktūra aprašyta faile Studentas.hpp

Funkcijos aprašytos failuose Funkcijos.hpp ir Funkcijos.cpp

Naudojamos bibliotekos aprašytos faile mylib.hpp

Naudojimo instrukcija:
1. Pasirenkate kokį konteinerį norite naudoti (vector/list) ir sukompiliuojate atitinkamą failą.
2. Į terminalą įvedate pagal ką bus skaičiuojamas galutinis balas medianą ar vidurkį (M/V)
3. Pasirenkate ar skaitysite nuo failo (ir jei taip galite pasirinkti ar norite sugeneruoti atsitiktinį failą)
4. Rezultatai yra išvedami į du failus vargšiukai.txt ir galvočiai.txt




