#ifndef TALISMAN_H
#define TALISMAN_H

#include <QObject>
#include <vector>
#include "skill.h"
#include "decoration.h"

/**
 * @brief Represents a talisman with skills and deco slots
 */
using namespace::std;
class Talisman
{
public:
    explicit Talisman();
private:
    /**
     * @brief List of skills this talisman has
     */
    vector<Skill> skills;

    /**
     * @brief Decoration levels the talisman has
     */
    qint16 decoSlots[3];

    /**
     * @brief The decorations applied to this talisman
     */
    Decoration decorations[3];

};

#endif // TALISMAN_H
