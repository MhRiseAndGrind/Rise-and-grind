#ifndef SKILL_H
#define SKILL_H
#include <QObject>

/**
 * @brief The Skill class
 */
class Skill
{
public:
    explicit Skill();
    Skill(qint16 id, QString name);
    Skill(qint16 id);
private:
    /**
     * @brief ID of the skill (internal use)
     */
    qint16 skillID;
    /**
     * @brief name
     * Name of the skill.
     */
    QString name;
    /**
     * @brief maxSkillLevel
     * Max skill level of the skill
     */
    qint16 maxSkillLevel;
};

#endif // SKILL_H
