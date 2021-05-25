#ifndef ARMORPIECE_H
#define ARMORPIECE_H

#include <QVector>
#include <vector>
#include "skill.h"
#include "decoration.h"
using namespace::std;
class ArmorPiece
{
public:
    enum ARMOR_TYPE {
        HEAD,   // 0
        TORSO,  // 1
        ARMS,   // 2
        WAIST,  // 3
        LEGS    // 4
    };
    explicit ArmorPiece();
    /**
     * @brief Basic armor piece constructor, disregards armor values
     * @param Internal ID of the piece
     * @param Name of the piece
     * @param Equipment slot of the piece
     * @param IDs of the skills the armor has
     * @param Levels of the skills the armor has
     * @param Number of skills the piece has
     * @param size-3 array of the slots the armor piece has
     */
    // TODO: Should i use a qvector for skills or keep it as an array
    ArmorPiece(qint16 id,
               QString name,
               ARMOR_TYPE type,
               qint16 * skillIds,
               qint16 * skillLevels,
               qint16 numSkills,
               qint16 * decoSlots);
    qint16 GetId();
    qint16 GetLevel();
    bool ContainsSkill(qint16 id, qint16 minLevel);
    QString GetName();
private:
    /**
     * @brief What slot the armor piece goes to
     */
    ARMOR_TYPE armorType;
    /**
      * @brief ID of the armor piece (Internal use)
      */
    qint16 armorID;
    /**
     * @brief Name of the piece
     */
    QString name;
    /**
      * @brief Skills the armor has
      */
    vector<qint16> skillIDs;

    /**
     * @brief Levels of each skill, corresponding to the same IDXs as the IDs array
     */
    vector<qint16> skillLevels;

    /**
      * @brief Slot levels the armor piece has
      */
    qint16 decoSlots[3];
    /**
     * @brief The decorations applied to the armor piece
     */
    Decoration decos[3];

    qint16 defenceMin;
    qint16 defenceMax;
    qint16 fireRes;
    qint16 waterRes;
    qint16 lightRes;
    qint16 iceRes;
    qint16 dragonRes;

signals:

};

#endif // ARMORPIECE_H
