#ifndef EQUIPMENTDATABASE_H
#define EQUIPMENTDATABASE_H

#include <QObject>
#include <QTextStream>
#include <QFile>
#include <QDebug>

#include "armorpiece.h"
#include "weapon.h"
#include "talisman.h"
#include "weapon.h"
#include "decoration.h"
#include "skill.h"
#include <vector>
/**
 * @brief Class containing all the equipment data loaded on startup.
 * This class is used as data for the combinatorics engine.
 * Also contains functions for loading data from CSV.
 */
using namespace::std;
class EquipmentDatabase
{
public:
    EquipmentDatabase();
    /**
     * @brief Load all the data from CSV into their respective vectors
     */
    void LoadData();
    vector<ArmorPiece> GetHeadPieces();
    vector<ArmorPiece> GetBodyPieces();
    vector<ArmorPiece> GetArmPieces();
    vector<ArmorPiece> GetWaistPieces();
    vector<ArmorPiece> GetLegPieces();
private:
    qint16 LoadArmor();
    qint16 LoadSkills();
    /**
     * @brief Load the decorations from a CSV table
     * @return 0 if success, -1 otherwise
     */
    int LoadDecorations();
    int LoadWeapons();
    /**
     * @brief Parses slots into an array from a pipe-delimited string
     * @param The string to parse (E.G. 3|2|0)
     * @return Pointer to size-3 array on stack with int values
     */
    qint16 * parseSlots(QString str);
    /**
     * @brief Parses pipe-separated skills string into array of ints
     * @param string input
     * @return pointer to array containing qints
     */
    qint16 * parseSkills(QString str);
    /**
     * @brief Parses pipe-separated skill-levels into an array of its
     * @param string input
     * @return pointer to array containing qints
     */
    qint16 * parseLevels(QString str);
    /**
     * @brief Frees any allocated memory
     */
    void freeMemory();

    vector<ArmorPiece> headArmorPieces;
    vector<ArmorPiece> bodyArmorPieces;
    vector<ArmorPiece> gauntletArmorPieces;
    vector<ArmorPiece> waistArmorPieces;
    vector<ArmorPiece> legArmorPieces;

    vector<Weapon *> weapons;
    vector<Talisman *> talismans;
    vector<Decoration *> decorations;
    vector<Skill *> skills;

};

#endif // EQUIPMENTDATABASE_H
