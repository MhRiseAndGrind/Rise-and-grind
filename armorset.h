#ifndef ARMORSET_H
#define ARMORSET_H

#include <QObject>
#include <vector>
#include "armorpiece.h"
#include "decoration.h"
#include "talisman.h"
#include "weapon.h"

/**
 * @brief Data structure for a whole armor set
 */
using namespace::std;
class ArmorSet
{
public:
    ArmorSet();
    ArmorSet(ArmorPiece &head,
              ArmorPiece &body,
              ArmorPiece &arm,
              ArmorPiece &waist,
              ArmorPiece &leg,
              Talisman &talisman);
    /**
     * @brief Add a decoration to the set list
     * @param Reference to a decoration object
     */
    void appendDecoration(Decoration &d);
    /**
     * @brief Clear all memory associated with this object
     */
    void clear();
private:
    ArmorPiece * headArmor;
    ArmorPiece * bodyArmor;
    ArmorPiece * armArmor;
    ArmorPiece * waistArmor;
    ArmorPiece * legArmor;

    vector<Decoration> decorations;
    Talisman * talisman;
};

#endif // ARMORSET_H
