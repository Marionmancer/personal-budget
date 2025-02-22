#include "XmlFile.h"

int XmlFile::getLastId() {
    bool fileExists = xmlDoc.Load(FILE_NAME);


    if (fileExists) {
        xmlDoc.ResetPos();
        xmlDoc.FindElem();
        xmlDoc.IntoElem();
        while (xmlDoc.FindElem()){
            xmlDoc.FindChildElem("id");
            lastId = atoi(xmlDoc.GetChildData().c_str());
        }
        xmlDoc.ResetPos();
        return lastId;
    }

    lastId = 0;
    return lastId;
}
