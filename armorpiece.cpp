#include "armorpiece.h"

ArmorPiece::ArmorPiece()
{

}
ArmorPiece::~ArmorPiece() {

}
ArmorPiece::ArmorPiece(qint16 id,
                       QString name,
                       ARMOR_TYPE type,
                       vector<qint16> skillIds,
                       vector<qint16> skillLevels,
                       vector<qint16> decoSlots,
                       vector<Skill *> skills) {
    this->armorID = id;
    this->name = name;
    this->armorType = type;
    // Load skill values into map
    for (int i = 0; i < (int) skillIds.size(); i++) {
        this->armorSkills[skillIds.at(i)] = skillLevels.at(i);
    }

    this->decoSlots[0] = decoSlots[0];
    this->decoSlots[1] = decoSlots[1];
    this->decoSlots[2] = decoSlots[2];
    this->skillList = skills;
}

qint16 ArmorPiece::GetId() {
    return this->armorID;
}
bool ArmorPiece::ContainsSkill(qint16 id) {
    if (this->armorSkills.count(id) > 0) {
        return true;
    }
    return false;
}
QString ArmorPiece::GetName() {
    return this->name;
}

std::map<qint16, qint16> ArmorPiece::getSkills() {
    return this->armorSkills;
}

qint16 ArmorPiece::getSlotLevelA() {
    return this->decoSlotLevelA;
}

qint16 ArmorPiece::getSlotLevelB() {
    return this->decoSlotLevelB;
}

qint16 ArmorPiece::getSlotLevelC() {
    return this->decoSlotLevelC;
}
