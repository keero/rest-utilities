#ifndef READY4AIR_EPISODE_H
#define READY4AIR_EPISODE_H

#include "../common/Maybe.h"
#include "MediaProduct.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    namespace dto
    {
        class Episode : public MediaProduct
        {
        public:
            Episode() : TAG("ready4air::dto::Episode")
            {
                mProductType = EpisodeProductType;
            }

            virtual ~Episode()
            {
            }

            const Maybe<int> &GetEpisodeNo() const
            {
                return mEpisodeNo;
            }

            void SetEpisodeNo(int episodeNo)
            {
                mEpisodeNo = episodeNo;
            }

            const Maybe<Link> &GetSerie() const
            {
                return mSerie;
            }

            void SetSerie(const Link &serie)
            {
                mSerie = serie;
            }

            const Maybe<Link> &GetSeason() const
            {
                return mSeason;
            }

            void SetSeason(const Link &season)
            {
                mSeason = season;
            }

            const Maybe<int> &GetSeasonNo() const
            {
                return mSeasonNo;
            }

            void SetSeasonNo(int seasonNo)
            {
                mSeasonNo = seasonNo;
            }

            virtual BOOL_T InitFromJsonValue(const rapidjson::Value &value, ParseErrors &parseErrors)
            {
                INT32_T episodeNo;
                Link serie;
                Link season;
                INT32_T seasonNo;

                // Initialize parent properties
                MediaProduct::InitFromJsonValue(value, parseErrors);

                if (ParseInt(value, "EpisodeNo", true, episodeNo, parseErrors))
                    SetEpisodeNo(episodeNo);

                if (ParseObject(value, "Serie", true, serie, parseErrors))
                    SetSerie(serie);

                if (ParseObject(value, "Season", true, season, parseErrors))
                    SetSeason(season);

                if (ParseInt(value, "SeasonNo", true, seasonNo, parseErrors))
                    SetSeasonNo(seasonNo);

                return !parseErrors;
            }

        private:
            Maybe<int> mEpisodeNo;
            Maybe<Link> mSerie;
            Maybe<Link> mSeason;
            Maybe<int> mSeasonNo;
            STRING_T TAG;
        };
    }
}

#endif //READY4AIR_EPISODE_H
