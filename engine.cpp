#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

Engine::Engine(EquipmentDatabase &d) {
    this->database = &d;
}

vector<ArmorSet> * Engine::FindSets(SearchParameters &params, qint16 maxCount) {
    vector<ArmorSet> * foundSets = new vector<ArmorSet>();
    // Candidates should match any of the params
    // If the piece also has slots >= the skill deco, add that too
    vector<ArmorPiece> headCandidates;
    for (int i = 0; i < (int) params.skillLevels.size(); i++) {
        auto tmp = FindCandidates(params.skillIds[i], params.skillLevels[i], ArmorPiece::HEAD);
        for (int j = 0; j < (int) tmp.size(); j++)
            headCandidates.push_back(tmp.at(i));
        qDebug() << "Found some head pieces.";
    }
    return foundSets;
}

vector<ArmorPiece> Engine::FindCandidates(qint16 skillId, qint16 minSkillLevel, ArmorPiece::ARMOR_TYPE type) {
    vector<ArmorPiece> candidates;
    vector<ArmorPiece> data;     // pointer to the group of pieces we want
    int numObjects;
    switch (type) {
    case ArmorPiece::HEAD:
        numObjects = this->database->GetHeadPieces().size();
        data = this->database->GetHeadPieces();
        break;
    case ArmorPiece::TORSO:
        numObjects = this->database->GetBodyPieces().size();
        data = this->database->GetBodyPieces();
        break;
    case ArmorPiece::ARMS:
        numObjects = this->database->GetArmPieces().size();
        data = this->database->GetArmPieces();
        break;
    case ArmorPiece::WAIST:
        numObjects = this->database->GetWaistPieces().size();
        data = this->database->GetWaistPieces();
        break;
    case ArmorPiece::LEGS:
        numObjects = this->database->GetLegPieces().size();
        data = this->database->GetLegPieces();
        break;
    default:
        return candidates;
    }
    // Assumes that data will never be null here
    for (int i = 0; i < numObjects; i++) {

        if( data.at(i).ContainsSkill(skillId, minSkillLevel)) {
            candidates.push_back(data.at(i));
            qDebug() << "Matched skill " << skillId << " to " << data.at(i).GetName();
        }
    }

    return candidates;
}
