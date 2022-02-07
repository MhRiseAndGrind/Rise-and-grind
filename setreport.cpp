#include "setreport.h"

SetReport::SetReport(ArmorSet & armorSet) {
    SetReport::armorSet = & armorSet;
    SetReport::setTotal = new std::map<qint16, qint16>();
    // Run the report
    calculateSetTotals();
}

void SetReport::calculateSetTotals() {
    // Add map on the heap
    std::map<qint16, qint16> * finalMap = new std::map<qint16, qint16>();

    // iterate through the armorset and put all the skills into the map
    auto headSkills = SetReport::armorSet->getHeadPiece().GetArmorPiece()->getSkills();
    auto bodySkills = SetReport::armorSet->getBodyPiece().GetArmorPiece()->getSkills();
    auto waistSkills = SetReport::armorSet->getWaistPiece().GetArmorPiece()->getSkills();
    auto armSkills = SetReport::armorSet->getArmPiece().GetArmorPiece()->getSkills();
    auto legSkills = SetReport::armorSet->getLegPiece().GetArmorPiece()->getSkills();

    // intersect all the sets into a final set, summing all like keys
    // TODO: make this more elegant
    finalMap->merge(headSkills);
     for (const auto &skill : bodySkills) {
         if (finalMap->count(skill.first) > 0) {
             (*finalMap)[skill.first] += skill.second;
         } else {
             (*finalMap)[skill.first] = skill.second;
         }
     }
     for (const auto &skill : headSkills) {
         if (finalMap->count(skill.first) > 0) {
             (*finalMap)[skill.first] += skill.second;
         } else {
             (*finalMap)[skill.first] = skill.second;
         }
     }
     for (const auto &skill : waistSkills) {
         if (finalMap->count(skill.first) > 0) {
             (*finalMap)[skill.first] += skill.second;
         } else {
             (*finalMap)[skill.first] = skill.second;
         }
     }
     for (const auto &skill : armSkills) {
         if (finalMap->count(skill.first) > 0) {
             (*finalMap)[skill.first] += skill.second;
         } else {
             (*finalMap)[skill.first] = skill.second;
         }
     }
     for (const auto &skill : legSkills) {
         if (finalMap->count(skill.first) > 0) {
             (*finalMap)[skill.first] += skill.second;
         } else {
             (*finalMap)[skill.first] = skill.second;
         }
     }
     qDebug("Created set report for armorset.");
     SetReport::setTotal = finalMap;
}

void SetReport::clear() {
    qDebug("Clearing set report memory");
    free(SetReport::setTotal);
}
std::map<qint16, qint16> * SetReport::getSetTotals() {
    return SetReport::setTotal;
}
