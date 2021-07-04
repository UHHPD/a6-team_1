#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"

class Koerper {
public:
  (double nr, double nl);

  Vektor punkt();
  std::string name()
  {
    return "Koerper";
  }

private:
  double r_, l_;
};

#endif
