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

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors,
                                             VECTOR_T<STRING_T> &context)
            {
                Link allMovies;
                Link allSeries;
                Link allBundles;

                context.push_back(TAG);

                if (ParseObject(value, "AllMovies", true, allMovies, parseErrors, context))
                    SetAllMovies(allMovies);

                if (ParseObject(value, "AllSeries", true, allSeries, parseErrors, context))
                    SetAllSeries(allSeries);

                if (ParseObject(value, "AllBundles", true, allBundles, parseErrors, context))
                    SetAllBundles(allBundles);

                context.pop_back();
                return !parseErrors;
            }

        private:
            Maybe <Link> mAllMovies;
            Maybe <Link> mAllSeries;
            Maybe <Link> mAllBundles;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_CATALOGUE_H
