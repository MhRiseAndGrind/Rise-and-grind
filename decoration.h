#ifndef DECORATION_H
#define DECORATION_H

#include <QObject>
#include "skill.h"
/**
 * @brief Represents a single decoration in the game
 */
class Decoration
{
public:
    explicit Decoration();
private:
    /**
     * @brief Decoration ID (internal use for searching)
     */
    qint16 decoID;
    /**
     * @brief Skill this decoration represents
     */
    Skill skill;
    /**
     * @brief Level of the decoration (1-3)
     */
    qint16 decoLevel;
signals:

};

#endif // DECORATION_H
