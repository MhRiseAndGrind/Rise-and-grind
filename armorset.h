#ifndef ARMORSET_H
#define ARMORSET_H

#include <QObject>
#include <vector>
#include "armorpiece.h"
#include "decoration.h"
#include "talisman.h"
#include "weapon.h"
#include "fittedarmorpiece.h"

using namespace::std;
/**
 * @brief Data structure for a whole armor set. Each piece should onyl ever be a reference to the piece in
 * the initial database loaded at runtime
 */
class ArmorSet
{
public:
    ArmorSet();
    ArmorSet(FittedArmorPiece &head,
              FittedArmorPiece &body,
              FittedArmorPiece &arm,
              FittedArmorPiece &waist,
              FittedArmorPiece &leg,
              Talisman &talisman);
    /**
     * @brief Add a decoration to the set list
     * @param Reference to a decoration object
     */
    void appendDecoration(Decoration &d);

    FittedArmorPiece getHeadPiece();
    FittedArmorPiece getBodyPiece();
    FittedArmorPiece getArmPiece();
    FittedArmorPiece getWaistPiece();
    FittedArmorPiece getLegPiece();

private:
    FittedArmorPiece headArmor;
    FittedArmorPiece bodyArmor;
    FittedArmorPiece armArmor;
    FittedArmorPiece waistArmor;
    FittedArmorPiece legArmor;

    Talisman talisman;
};

#endif // ARMORSET_H
