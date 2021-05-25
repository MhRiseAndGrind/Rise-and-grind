#include "armorpiece.h"

ArmorPiece::ArmorPiece()
{

}

ArmorPiece::ArmorPiece(qint16 id,
                       QString name,
                       ARMOR_TYPE type,
                       qint16 * skillIds,
                       qint16 * skillLevels,
                       qint16 numSkills,
                       qint16 * decoSlots) {
    this->armorID = id;
    this->name = name;
    this->armorType = type;
    int i = 0;
    for (i = 0; i < numSkills; i++) {
        this->skillIDs.push_back(skillIds[i]);
        this->skillLevels.push_back(skillLevels[i]);
    }

    this->decoSlots[0] = decoSlots[0];
    this->decoSlots[1] = decoSlots[1];
    this->decoSlots[2] = decoSlots[2];
}

qint16 ArmorPiece::GetId() {
    return this->armorID;
}
bool ArmorPiece::ContainsSkill(qint16 id, qint16 minLevel) {
    int count = this->skillIDs.size();
    for (int i = 0; i < count; i++) {
        if (this->skillIDs.at(i) == id && this->skillLevels.at(i) >= minLevel)
            return true;
    }
    return false;
}
QString ArmorPiece::GetName() {
    return this->name;
}
