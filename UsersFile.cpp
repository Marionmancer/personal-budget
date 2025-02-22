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
    string id = to_string(user.id);

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

vector <User> UsersFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xmlDoc;
    string userXmlFileName = getFileName();
    bool fileExists = xmlDoc.Load(userXmlFileName);

    if (fileExists){
        xmlDoc.ResetPos();
        xmlDoc.FindElem("users");
        xmlDoc.IntoElem();
        while (xmlDoc.FindElem("user")) {
            xmlDoc.FindChildElem("id");
            user.id = atoi(xmlDoc.GetChildData().c_str());
            xmlDoc.FindChildElem("login");
            user.login = xmlDoc.GetChildData();
            xmlDoc.FindChildElem("password");
            user.password = xmlDoc.GetChildData();
            xmlDoc.FindChildElem("name");
            user.name = xmlDoc.GetChildData();
            xmlDoc.FindChildElem("surname");
            user.surname = xmlDoc.GetChildData();
            users.push_back(user);
        }
    }
    return users;
}
