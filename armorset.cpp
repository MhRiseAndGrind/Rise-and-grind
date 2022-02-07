#include "armorset.h"

ArmorSet::ArmorSet()
{
    this->headArmor = FittedArmorPiece();
    this->bodyArmor = FittedArmorPiece();
    this->armArmor = FittedArmorPiece();
    this->waistArmor = FittedArmorPiece();
    this->legArmor = FittedArmorPiece();
}

ArmorSet::ArmorSet(FittedArmorPiece &head,
                   FittedArmorPiece &body,
                   FittedArmorPiece &arm,
                   FittedArmorPiece &waist,
                   FittedArmorPiece &leg,
                   Talisman &talisman) {
    ArmorSet::headArmor = head;
    ArmorSet::bodyArmor = body;
    ArmorSet::armArmor = arm;
    ArmorSet::waistArmor = waist;
    ArmorSet::legArmor = leg;
    ArmorSet::talisman = talisman;
}
FittedArmorPiece ArmorSet::getHeadPiece() {
    return ArmorSet::headArmor;
}
FittedArmorPiece ArmorSet::getBodyPiece() {
    return ArmorSet::bodyArmor;
}
FittedArmorPiece ArmorSet::getLegPiece() {
    return ArmorSet::legArmor;
}
FittedArmorPiece ArmorSet::getWaistPiece() {
    return ArmorSet::waistArmor;
}
FittedArmorPiece ArmorSet::getArmPiece() {
    return ArmorSet::armArmor;
}

