#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

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

  double J = 0;     // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes

  for (int i = 0; i < N; i++) { // Zusammenhang x und i ???
    Vektor x = zm->punkt();
    double d = (((x-a).kreuz(u)).betrag())/(u.betrag()); // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a).kreuz(u); //Normalenvektor x-a kreuz u
    double r = (n.betrag())/(u.betrag()); //|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;

  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));

  J = 0;
  for (int i = 0; i < N; i++)
  {
    Vektor x = vz->punkt();
    double r = (((x-a).kreuz(u)).betrag())/(u.betrag());
    // std::cout << x << ":" << r << std::endl;
    J += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << J << std::endl;
  return 0;
}