#ifndef READY4AIR_CATALOGUE_H
#define READY4AIR_CATALOGUE_H

#include "../common/Maybe.h"
#include "abstract/JsonDeserializable.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Catalogue : public JsonDeserializable
        {

        public:
            Catalogue() : TAG("ready4air::dto::Catalogue")
            {
            }

            virtual ~Catalogue()
            {
            }

            const Maybe <Link> &GetAllMovies() const
            {
                return mAllMovies;
            }

            void SetAllMovies(const Link &allMovies)
            {
                mAllMovies = allMovies;
            }

            const Maybe <Link> &GetAllSeries() const
            {
                return mAllSeries;
            }

            void SetAllSeries(const Link &allSeries)
            {
                mAllSeries = allSeries;
            }

            const Maybe <Link> &GetAllBundles() const
            {
                return mAllBundles;
            }

            void SetAllBundles(const Link &allBundles)
            {
                mAllBundles = allBundles;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                Link allMovies;
                Link allSeries;
                Link allBundles;

                if (ParseObject(value, "AllMovies", true, allMovies, parseErrors))
                    SetAllMovies(allMovies);

                if (ParseObject(value, "AllSeries", true, allSeries, parseErrors))
                    SetAllSeries(allSeries);

                if (ParseObject(value, "AllBundles", true, allBundles, parseErrors))
                    SetAllBundles(allBundles);

                return !parseErrors;
            }

        private:
            Maybe <Link> mAllMovies;
            Maybe <Link> mAllSeries;
            Maybe <Link> mAllBundles;
            const STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CATALOGUE_H
