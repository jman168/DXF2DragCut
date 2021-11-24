#include "DXFParser.h"

DXFParser::DXFParser(std::ifstream *inputStream) {
    _inputStream = inputStream;
}

std::streampos DXFParser::findSection(std::string sectionName) {
    std::streampos pos = -1;
    
    _inputStream->seekg(0);

    std::string line;
    
    do {
        *_inputStream >> line;

        if(line == "0") {
            *_inputStream >> line;

            if(line == "SECTION") {
                *_inputStream >> line;

                if(line == "2") {
                    *_inputStream >> line;

                    if(line == sectionName) {
                        pos = _inputStream->tellg();
                    }
                }
            }
        }
    } while (line != "EOF");

    return pos;
}

std::streampos DXFParser::findEndSection(std::string sectionName) {
    std::streampos pos = -1;
    
    _inputStream->seekg(findSection(sectionName));


    std::string line;
    
    do {
        *_inputStream >> line;

        if(line == "0") {
            *_inputStream >> line;

            if(line == "ENDSEC") {
                pos = _inputStream->tellg();
            }
        }
    } while (line != "EOF" && line != "ENDSEC");
    

    return pos;
}