#include "Textfile.h"

string Textfile::getFileName() {

    return NAME_OF_TEXTFILE;
}

bool Textfile::isFileEmpty() {

    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good()) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            return false;
    }
    textFile.close();
    return true;
}