#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{

}

Engine::Engine(EquipmentDatabase &d) {
    this->database = &d;
}

vector<ArmorSet> Engine::FindSets(SearchParameters &params, qint16 maxCount) {
    vector<ArmorSet> foundSets;
    // Candidates should match any of the params
    //IE even though the minimum skill may be 3, we want all sets with that skill regardless
    // If the piece also has slots >= the skill deco, add that too
    vector<ArmorPiece> headCandidates;
    vector<ArmorPiece> torsoCandidates;
    vector<ArmorPiece> armsCandidates;
    vector<ArmorPiece> waistCandidates;
    vector<ArmorPiece> legsCandidates;
    vector<Weapon> weaponCandidates;
    vector<Talisman> talismanCandidates;
    // Go over every skill and level and append them to the appropriate vector
    for (int i = 0; i < (int) params.skillLevels.size(); i++) {
        auto headTmp = FindCandidates(params.skillIds[i], 1, ArmorPiece::HEAD);
        auto torsoTmp = FindCandidates(params.skillIds[i], 1, ArmorPiece::TORSO);
        auto armTmp = FindCandidates(params.skillIds[i], 1, ArmorPiece::ARMS);
        auto waistTmp = FindCandidates(params.skillIds[i],1, ArmorPiece::WAIST);
        auto legTmp = FindCandidates(params.skillIds[i], 1, ArmorPiece::LEGS);
        // evil copy pasted code
        for (int j = 0; j < (int) headTmp.size(); j++)
            headCandidates.push_back(headTmp.at(i));

        for (int j = 0; j < (int) torsoTmp.size(); j++)
            torsoCandidates.push_back(torsoTmp.at(i));

        for (int j = 0; j < (int) armTmp.size(); j++)
            armsCandidates.push_back(armTmp.at(i));

        for (int j = 0; j < (int) waistTmp.size(); j++)
            waistCandidates.push_back(waistTmp.at(i));

        for (int j = 0; j < (int) legTmp.size(); j++)
            legsCandidates.push_back(legTmp.at(i));
    }
    // Search the weapons and talismans next


    // Add a No Armor armor piece to each category (prevents idx oob error in cartesian product search)
    qint16 emptySlots[] = {0,0,0};
    headCandidates.push_back(ArmorPiece(0, "No Head Piece", ArmorPiece::HEAD, 0, 0, 0, emptySlots));
    torsoCandidates.push_back(ArmorPiece(1, "No Torso Piece", ArmorPiece::TORSO, 0, 0, 0, emptySlots));
    armsCandidates.push_back(ArmorPiece(2, "No Arm Piece", ArmorPiece::ARMS, 0, 0, 0, emptySlots));
    waistCandidates.push_back(ArmorPiece(3, "No Waist Piece", ArmorPiece::WAIST, 0, 0, 0, emptySlots));
    legsCandidates.push_back(ArmorPiece(4, "No Leg Piece", ArmorPiece::LEGS, 0, 0, 0, emptySlots));
    // TODO: Handle weapons and talismans
    // Find every combination
    foundSets = Engine::CartesianProduct(headCandidates,
                                         torsoCandidates,
                                         armsCandidates,
                                         waistCandidates,
                                         legsCandidates,
                                         weaponCandidates,
                                         talismanCandidates);
    qDebug() << "Found" << foundSets.size() << "unique sets";
    // Now filter the sets based on our search parameters
    // Since the initial set search accounted for any skill levels of the skills we want
    // we now all the sets that at least match the skill levels we want
    // TODO:
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
        //TODO: get skill deco level and compare to armor slots.
        if( data.at(i).ContainsSkill(skillId, minSkillLevel)) {
            candidates.push_back(data.at(i));
            qDebug() << "Matched skill " << skillId << " to " << data.at(i).GetName();
        }
    }

    return candidates;
}

vector<ArmorSet> Engine::CartesianProduct(vector<ArmorPiece> &headPieces,
                                          vector<ArmorPiece> &bodyPieces,
                                          vector<ArmorPiece> &armPieces,
                                          vector<ArmorPiece> &waistPieces,
                                          vector<ArmorPiece> &legPieces,
                                          vector<Weapon> &weapons,
                                          vector<Talisman> &talismans) {
    vector<ArmorSet> foundSets;
    int headIdx = 0;
    int bodyIdx = 0;
    int armIdx = 0;
    int waistIdx = 0;
    int legIdx = 0;
    int weaponIdx = 0;
    int taliIdx = 0;
    while(1) {
        // Do all the index parsing first before making a set
        /*
        if (taliIdx == (int) talismans.size()) {    // Talisman index
            taliIdx = 0;
            weaponIdx++;
        }
        */
        /*
        if (weaponIdx == (int) weapons.size()) {
            weaponIdx = 0;
            legIdx++;
        }
        */
        if (legIdx == (int) legPieces.size()) {
            legIdx = 0;
            waistIdx++;
        }
        if (waistIdx == (int) waistPieces.size()) {
            waistIdx = 0;
            armIdx++;
        }
        if (armIdx == (int) armPieces.size()) {
            armIdx = 0;
            bodyIdx++;
        }
        if (bodyIdx == (int) bodyPieces.size()) {
            bodyIdx = 0;
            headIdx++;
        }
        if (headIdx == (int) headPieces.size()) {
            // If headidx is equal to the count then we traversed through everything
            break;
        }
        // Head is the slowest moving
        // Create the set
        Weapon weapon = Weapon(); // TODO:
        Talisman tali = Talisman(); // TODO:
        ArmorSet tempSet = ArmorSet(headPieces.at(headIdx),
                                    bodyPieces.at(bodyIdx),
                                    armPieces.at(armIdx),
                                    waistPieces.at(waistIdx),
                                    legPieces.at(legIdx),
                                    tali);
        foundSets.push_back(tempSet);

        // Increment the lowest order category
        legIdx++;
    }

    return foundSets;

}
