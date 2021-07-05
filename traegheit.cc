#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Koerper.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper* k, double M, int N, Vektor a, Vektor u) {
  double J = 0;
  double m = M / N;
  for (int i = 0; i < N; i++)
  {
    Vektor x = k->punkt();
    double r = (((x-a).kreuz(u)).betrag())/(u.betrag());
    // std::cout << x << ":" << r << std::endl;
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen " << k->name()
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  return J; 
}

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  double M = 1;      // Masse des Zylindermantels
  double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  
  std::cout << "Masse:";
  std::cin >> M;

  std::cout << "Radius:";
  std::cin >> ZM_R;

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));
  traegheit(zm.get(), M, N, a, u);

  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));
  traegheit(vz.get(), M, N, a, u);
}