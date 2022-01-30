#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <vector>
#include "equipmentdatabase.h"
#include "armorset.h"
#include "searchparameters.h"
#include <algorithm>

/**
 * @brief Engine that creates combinations based on user input
 */
using namespace::std;
class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine(QObject *parent = nullptr);
    /**
     * @brief Engine Constructor
     * @param Reference to a database object with the loaded data
     */
    Engine(EquipmentDatabase &database);
    /**
     * @brief Find a max of N valid sets given the search parameters
     * @param Search Parameters with desired skills
     * @param Max number of results to find
     * @return QVector containing the armor sets
     */
    vector<ArmorSet> FindSets(SearchParameters &params, qint16 maxCount);
signals:

private:
    /**
     * @brief Pointer to a database object
     */
    EquipmentDatabase * database;
    /**
     * @brief Find candidates from the database such that the armor pieces have the desired skill
     * @param ID of the desired skill
     * @param Minimum level of the skill
     * @return vector containing pointers to the armor pieces in the database
     */\
    vector<ArmorPiece> FindCandidates(qint16 skillId, qint16 minSkillLevel, ArmorPiece::ARMOR_TYPE type);
    /**
     * @brief 7-set cartesian product
     * @return Vector of armorsets such that there is every single combination of the input sets such that one from each category is chosen
     */
    vector<ArmorSet> CartesianProduct(vector<ArmorPiece> &headPieces,
                                        vector<ArmorPiece> &bodyPieces,
                                        vector<ArmorPiece> &armPieces,
                                        vector<ArmorPiece> &waistPieces,
                                        vector<ArmorPiece> &legPieces,
                                        vector<Weapon> &weapons,
                                        vector<Talisman> &talismans);
};

#endif // ENGINE_H
