#pragma pragma

#include <fstream>

class DXFParser {
    private:
        std::ifstream *_inputStream;

    public:
        DXFParser(std::ifstream *inputStream);

        std::streampos findSection(std::string sectionName);
        std::streampos findEndSection(std::string sectionName);
};