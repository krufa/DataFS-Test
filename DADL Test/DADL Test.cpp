// DADL Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <Windows.h>
#include <Malloc.h>

#include <DataFS\Client\DataFS Client.h>
//using namespace DataFoundation;

#include <DataFS\Access\DataFS Access.h>
using namespace DataFoundationAccess;

#include "_data\AccessDefinition.h"
#include "_data\AccessDefinition.cpp"

// {56F8EB44-B7E3-4564-B9A6-22E5E1B9110C}
const GUID guidRootName =
{ 0x56f8eb44, 0xb7e3, 0x4564, { 0xb9, 0xa6, 0x22, 0xe5, 0xe1, 0xb9, 0x11, 0xc } };


int main()
{
    const wchar_t* strServerAddress = L"127.0.0.1";

    UINT16 usServerPort = 9012;// (UINT16)_wtoi(argv[2]);

    GUID guidDomainId;
    ::CLSIDFromString(/*argv[3]*/L"{78F18ADB-6F0A-4885-B151-B5A729F35F8B}", &guidDomainId);

    UINT32 ulStorageId = 0;
    // FEHLER -> 0 ? an den blöden Wert kommt man gar nicht ran im Moment, wenn der nicht 0 wäre!!! -> wieso wurde "Find" nicht exportiert??

    // connect
    DataFoundation::InitializeThread();

    WDomain* pWDomain = NewWDomain(0);


    if (FAILED(pWDomain->Initialize()))
    {
        DeleteWDomain(pWDomain);
        return -1;
    }

    if (FAILED(pWDomain->Connect(strServerAddress, usServerPort, &guidDomainId)))
    {
        pWDomain->Uninitialize();
        DeleteWDomain(pWDomain);
        return -1;
    }

    if (FAILED(pWDomain->QueryStorage(ulStorageId, false)))
    {
        pWDomain->DisconnectAll();
        pWDomain->Uninitialize();
        DeleteWDomain(pWDomain);
        return -1;
    }

    // bind types
    AccessDefinition::Bind(pWDomain);

    // create named object

    ITestRoot* pRootObject;

    AccessDefinition::Create(pWDomain, &pRootObject);

    pRootObject->SetRootName(L"first test root");

    pRootObject->ExternalAddRef();

    pRootObject->StoreData();

    pWDomain->InsertNamedObject(&pRootObject->BuildLink(true), &guidRootName, L"first entry point");

    pRootObject->Release();

    pWDomain->Execute(TRANSACTION_STORE);

    // unbind types
    AccessDefinition::Unbind();

    // disconnect

    pWDomain->ReleaseStorage(ulStorageId);
    pWDomain->DisconnectAll();
    pWDomain->Uninitialize();
    DeleteWDomain(pWDomain);

    ////////////////////////////////////////////////////
    // 2. Teil

    // connect
    //DataFoundation::InitializeThread();

    pWDomain = NewWDomain(0);
    if (FAILED(pWDomain->Initialize()))
    {
        DeleteWDomain(pWDomain);
        return -1;
    }

    if (FAILED(pWDomain->Connect(strServerAddress, usServerPort, &guidDomainId)))
    {
        pWDomain->Uninitialize();
        DeleteWDomain(pWDomain);
        return -1;
    }

    if (FAILED(pWDomain->QueryStorage(ulStorageId, false)))
    {
        pWDomain->DisconnectAll();
        pWDomain->Uninitialize();
        DeleteWDomain(pWDomain);
        return -1;
    }

    // bind types
    AccessDefinition::Bind(pWDomain);

    // open named object

    DataFoundation::ObjectId oiRootObject;

    pWDomain->QueryNamedObject(&oiRootObject, &guidRootName);
    pRootObject = NULL;
    AccessDefinition::Open(pWDomain, &pRootObject, &oiRootObject);

    pRootObject->Load();
    pWDomain->Execute(TRANSACTION_LOAD);

    // open the list for writing

    TestObjectList* pList;
    pRootObject->SetAllObjects(&pList);

    // create an add a new object

    ITestObject* pTestObject;

    pRootObject->Create(&pTestObject);

    TestObjectListItem itm;
    itm.anObject = pTestObject->BuildLink(true);
    itm.theType = 12;

    pList->Insert(NULL, &itm);

    pTestObject->SetText(L"something");
    pTestObject->SetNumber(343);

    pTestObject->StoreData();
    pRootObject->StoreData();

    pWDomain->Execute(TRANSACTION_STORE);

    pTestObject->Release();
    pRootObject->Release();

    // unbind types
    AccessDefinition::Unbind();

    // disconnect

    pWDomain->ReleaseStorage(ulStorageId);
    pWDomain->DisconnectAll();
    pWDomain->Uninitialize();
    DeleteWDomain(pWDomain);

    return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
