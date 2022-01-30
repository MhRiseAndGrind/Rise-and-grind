#include "armorset.h"

ArmorSet::ArmorSet()
{

}

ArmorSet::ArmorSet(ArmorPiece &head,
                   ArmorPiece &body,
                   ArmorPiece &arm,
                   ArmorPiece &waist,
                   ArmorPiece &leg,
                   Talisman &talisman) {
    ArmorSet::headArmor = &head;
    ArmorSet::bodyArmor = &body;
    ArmorSet::armArmor = &arm;
    ArmorSet::waistArmor = &waist;
    ArmorSet::legArmor = &leg;
    ArmorSet::talisman = &talisman;


}
