#ifndef READY4AIR_CATALOGUE_H
#define READY4AIR_CATALOGUE_H

#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Catalogue : public JsonDeserializable
    {

    public:
        Catalogue()
        {
        }

        virtual ~Catalogue()
        {
        }

        const Link &GetAllMovies() const
        {
            return mAllMovies;
        }

        void SetAllMovies(const Link &allMovies)
        {
            mAllMovies = allMovies;
        }

        const Link &GetAllSeries() const
        {
            return mAllSeries;
        }

        void SetAllSeries(const Link &allSeries)
        {
            mAllSeries = allSeries;
        }

        const Link &GetAllBundles() const
        {
            return mAllBundles;
        }

        void SetAllBundles(const Link &allBundles)
        {
            mAllBundles = allBundles;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Mandatory property
            Link allMovies;
            if (!value.HasMember("AllMovies") || !value["AllMovies"].IsObject() || !allMovies.InitFromJsonValue(value["AllMovies"])) return false;
            SetAllMovies(allMovies);

            // Mandatory property
            Link allSeries;
            if (!value.HasMember("AllSeries") || !value["AllSeries"].IsObject() || !allSeries.InitFromJsonValue(value["AllSeries"])) return false;
            SetAllSeries(allSeries);

            // Mandatory property
            Link allBundles;
            if (!value.HasMember("AllBundles") || !value["AllBundles"].IsObject() || !allBundles.InitFromJsonValue(value["AllBundles"])) return false;
            SetAllBundles(allBundles);

            return true;
        }

    private:
        Link mAllMovies;
        Link mAllSeries;
        Link mAllBundles;
    };
}

#endif //READY4AIR_CATALOGUE_H
