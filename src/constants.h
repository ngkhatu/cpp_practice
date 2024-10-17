#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
// since the actual variables are inside a namespace, the forward declarations
// need to be inside a namespace as well we can't forward declare variables as
// constexpr, but we can forward declare them as (runtime) const
extern const double pi;
extern const double avogadro;
extern const double myGravity;
} // namespace constants

#endif
