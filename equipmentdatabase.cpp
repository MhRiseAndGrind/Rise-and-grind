#include "equipmentdatabase.h"

EquipmentDatabase::EquipmentDatabase()
{

}

void EquipmentDatabase::LoadData() {
    // First load the skills as they have the IDS and names for everything else
    qint16 skillRes = LoadSkills();
    qint16 armorRes = LoadArmor();
}

qint16 EquipmentDatabase::LoadSkills() {
    QFile file("./Skills.csv");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug("ERROR: Could not open the skills CSV");
        return -1;
    } else {
        // Read the CSV file
        QTextStream filestream(&file);
        // read the first line into nothing as its just header information
        filestream.readLine();
        // Now loop through and add the data to the database
        while (!filestream.atEnd()) {
            QString line = filestream.readLine();
            // ROW 0: SKill ID
            // ROW 1: Skill name
            // ROW 2: max level TODO:
            QStringList row = line.split(',');
            // Add the skill to the database
            this->skills.push_back(new Skill(row[0].toInt(), row[1]));
        }
        file.close();
        qDebug() << "Successfully loaded " << this->skills.size() << " Skills";
    }
    return 0;
}

qint16 EquipmentDatabase::LoadArmor() {
    QFile file("./HRArmor.csv");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "ERROR. Could not load the HR Armor csv.";
        return -1;
    } else {
        QTextStream fs(&file);
        fs.readLine();
        while (!fs.atEnd()) {
            QString line = fs.readLine();
            /*
             * ROW 0 -- Equipment ID
             * ROW 1 -- Equipment Name
             * ROW 2 -- Equipment Slot
             * ROW 3 -- Equipment Skills (as IDs)
             * ROW 4 -- SKill Levels (corresponding to previous row)
             * ROW 5 -- Decoration Slots
             * ROW 6->12 -- minDef, maxDef, Fire/Water/Light/Ice/Drgn res
            */
            QStringList row = line.split(',');
            // oops
            qint16 skillSize = row[3].split('|').length();
            qint16 * skills = this->parseSkills(row[3]);
            qint16 * levels = this->parseLevels(row[4]);
            qint16 * decoSlots = this->parseSlots(row[5]);
            ArmorPiece piece(row[0].toInt(), row[1], (ArmorPiece::ARMOR_TYPE) row[2].toInt(), skills,levels, skillSize, decoSlots);
            switch(row[2].toInt()) {
            case 0:
                this->headArmorPieces.push_back(piece);
                break;
            case 1:
                this->bodyArmorPieces.push_back(piece);
                break;
            case 2:
                this->gauntletArmorPieces.push_back(piece);
                break;
            case 3:
                this->waistArmorPieces.push_back(piece);
                break;
            case 4:
                this->legArmorPieces.push_back(piece);
            }
        }
        file.close();
        qDebug() << "Loaded " << this->headArmorPieces.size() << " head pieces.";
        qDebug() << "Loaded " << this->bodyArmorPieces.size() << " body pieces.";
        qDebug() << "Loaded " << this->gauntletArmorPieces.size() << " arm pieces.";
        qDebug() << "Loaded " << this->waistArmorPieces.size() << " waist pieces.";
        qDebug() << "Loaded " << this->legArmorPieces.size() << " leg pieces.";
    }
    return 0;
}

qint16 * EquipmentDatabase::parseSlots(QString str) {
    qint16 * decoSlots = new qint16[3];

    QStringList lst = str.split('|');
    decoSlots[0] = lst[0].toInt();
    decoSlots[1] = lst[1].toInt();
    decoSlots[2] = lst[2].toInt();

    return decoSlots;
}

qint16 * EquipmentDatabase::parseSkills(QString str) {
    QStringList lst = str.split('|');
    qint16 numSkills = lst.length();
    qint16 * skillIds = new qint16[numSkills];
    for (int i = 0; i < numSkills; i++) {
        skillIds[i] = lst[i].toInt();
    }
    return skillIds;
}

qint16 * EquipmentDatabase::parseLevels(QString str) {
    QStringList lst = str.split('|');
    qint16 numSkills = lst.length();
    qint16 * skillLevels = new qint16[numSkills];
    for (int i = 0; i < numSkills; i++) {
        skillLevels[i] = lst[i].toInt();
    }
    return skillLevels;
}

void EquipmentDatabase::freeMemory() {
    this->headArmorPieces.clear();
    this->bodyArmorPieces.clear();
    this->gauntletArmorPieces.clear();
    this->waistArmorPieces.clear();
    this->legArmorPieces.clear();

}

vector<ArmorPiece> EquipmentDatabase::GetHeadPieces() {
    return this->headArmorPieces;
}
vector<ArmorPiece> EquipmentDatabase::GetBodyPieces() {
    return this->bodyArmorPieces;
}
vector<ArmorPiece> EquipmentDatabase::GetArmPieces() {
    return this->gauntletArmorPieces;
}
vector<ArmorPiece> EquipmentDatabase::GetWaistPieces() {
    return this->waistArmorPieces;
}
vector<ArmorPiece> EquipmentDatabase::GetLegPieces() {
    return this->legArmorPieces;
}
