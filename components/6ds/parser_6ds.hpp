#ifndef FORMAT_PARSERS_6DS_H
#define FORMAT_PARSERS_6DS_H

#include <base_parser.hpp>

namespace MFFormat
{

class DataFormat6DS: public DataFormat
{
public:
    #pragma pack(push,1)
    typedef struct
    {
        char mMagic[4]; // should be '6DS'
        uint16_t mFileVersion;
        uint64_t mTimestamp;
        uint16_t mNumVertices;
        uint16_t mNumVertexIndices;
        uint16_t mNumLinks;
    } Header;

    typedef struct
    {
        uint16_t mA;
        uint16_t mB;
        uint16_t mC;
    } Face;

    typedef struct
    {
        uint32_t mNumVertices;
        uint32_t mNumFaces;
        char mNameLength;
        char mName[255];
    } Link;
    #pragma pack(pop)

    virtual bool load(std::ifstream &srcFile) override;
    inline std::vector<MFMath::Vec3> getVertices()  { return mVertices;        }
    inline size_t getNumVertices()                  { return mVertices.size(); }
    inline std::vector<Face> getFaces()             { return mFaces;           }
    inline size_t getNumFaces()                     { return mFaces.size();    }
    inline std::vector<Link> getLinks()             { return mLinks;           }
    inline size_t getNumLinks()                     { return mLinks.size();    }

private:
    std::vector<MFMath::Vec3> mVertices;
    std::vector<Face> mFaces;
    std::vector<Link> mLinks;
};

}

#endif // FORMAT_PARSERS_6DS_H
