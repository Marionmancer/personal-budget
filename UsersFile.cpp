#include "UsersFile.h"

void UsersFile::addUserToFile(User user){

    CMarkup xmlDoc;
    string userXmlFileName = getFileName();

    bool fileExists = xmlDoc.Load(userXmlFileName);

    if (!fileExists){
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("users");
        cout << "Nie ma takiego pliku. Utworzylem wiec nowy " << endl;
    }
    lastId = getLastId() + 1;

    xmlDoc.ResetPos();
    xmlDoc.FindElem("users");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("user");
    xmlDoc.AddChildElem("id", lastId);
    xmlDoc.AddChildElem("login", user.login);
    xmlDoc.AddChildElem("password", user.password);
    xmlDoc.AddChildElem("name", user.name);
    xmlDoc.AddChildElem("surname", user.surname);
    xmlDoc.ResetPos();

    xmlDoc.Save(userXmlFileName);
}
