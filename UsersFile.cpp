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

bool UsersFile::changeUserPasswordInFile(User user){

    CMarkup xmlDoc;
    string userXmlFileName = getFileName();
    string newPassword = user.password;
    cout << "Pamietaj zmienic sposob wczytywania id przy zmianie hasla!" << endl;
    string id = to_string(6);//(user.id);

    bool fileExists = xmlDoc.Load(userXmlFileName);

    if (fileExists){
        xmlDoc.ResetPos();
        xmlDoc.FindElem("users");
        xmlDoc.IntoElem();
        while (xmlDoc.FindElem("user")){
            xmlDoc.FindChildElem("id");
            if(xmlDoc.GetChildData() == id){
                xmlDoc.FindChildElem("password");
                xmlDoc.SetChildData(newPassword);
                xmlDoc.Save(userXmlFileName);
                return true;
            }
        }
    }
    return false;
}
