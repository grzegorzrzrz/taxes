#pragma once
#include <iostream>
#include <limits>
#include <string>
#include "faktura.h"
#include "osoba.h"
#include "dzialalnosc.h"
#include "podatek.h"
#include "kontener.h"


class Urzad {
	friend Osoba;
	friend Faktura;
	friend Dzialalnosc;
	friend Podatek;
private:
	Kontener<Faktura&> faktury = {};
	Kontener<Osoba&> osoby = {};
	Kontener<Dzialalnosc&> dzialalnosci = {};
	Kontener<Podatek&> podatki = {};
public:
	bool koniecProgramu = false;
	Urzad() = default;
	void obsluz(std::istream&, std::ostream&);
	void obsluzFaktury(std::istream&, std::ostream&);
	void obsluzOsoby(std::istream&, std::ostream&);
	void obsluzDzialalnosci(std::istream&, std::ostream&);
	void obsluzPodatki(std::istream&, std::ostream&);
	Kwota policzPodatek(const int&);
	void dodajPrzykladoweDane();
};