#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "DXFParser.h"

int main() {
    std::ifstream dxfFile("dxf.dxf");

    DXFParser parser(&dxfFile);

    std::streampos spos = parser.findSection("ENTITIES");
    std::streampos epos = parser.findEndSection("ENTITIES");
    
    std::cout << spos << "-" << epos << std::endl;
}