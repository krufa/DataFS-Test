// DTDL Test.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <Windows.h>
#include <Malloc.h>
#include <DataFS\Client\DataFS Client.h>

int main(int argc, wchar_t* argv[])
{
    const wchar_t* strServerAddress = L"127.0.0.1";// argv[1];

    UINT16 usServerPort = 9012;// (UINT16)_wtoi(argv[2]);

    GUID guidDomainId;
    ::CLSIDFromString(/*argv[3]*/L"{78F18ADB-6F0A-4885-B151-B5A729F35F8B}", &guidDomainId);

    // connect
    DataFoundation::InitializeThread();

    HANDLE hConnection;
    if (FAILED(DataFoundation::ConnectW(&hConnection, strServerAddress, usServerPort, NULL)))
    {
        DataFoundation::UninitializeThread();
        return -1;
    }

    // extend schema
    HANDLE hFile = ::CreateFileW(L"C:\\Users\\admin\\source\\repos\\DataFS Test\\DTDL Test\\_data\\Schema.bdtd", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    
    LARGE_INTEGER pl;
    if (!GetFileSizeEx(hFile, &pl))
        return -1;

    BYTE* pBdtd = (BYTE*)malloc(pl.QuadPart * sizeof(BYTE));      // content of the BDTD file -> load from file or resource or otherwise
    DWORD dwRead;
    bool breda = ::ReadFile(hFile, pBdtd, pl.QuadPart, &dwRead, NULL);
    
    

    DataFoundation::USchemaEdit* pSchema;

    if (SUCCEEDED(DataFoundation::QuerySchemaEdit(hConnection, &pSchema, &guidDomainId)))
    {
        pSchema->CreateFromBinary(pBdtd, pl.QuadPart);
        pSchema->Commit();
        pSchema->Release();
    }

    DataFoundation::Disconnect(hConnection);
    DataFoundation::UninitializeThread();

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
