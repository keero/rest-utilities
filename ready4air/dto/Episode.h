#ifndef READY4AIR_EPISODE_H
#define READY4AIR_EPISODE_H

#include "../maybe/Maybe.h"
#include "MediaProduct.h"
#include "hypermedia/Link.h"

namespace ready4air
{
    class Episode : public MediaProduct
    {
    public:
        Episode()
        {
            mProductType = EpisodeProductType;
        }

        virtual ~Episode()
        {
        }

        const Maybe <int> &GetEpisodeNo() const
        {
            return mEpisodeNo;
        }

        void SetEpisodeNo(int episodeNo)
        {
            mEpisodeNo = episodeNo;
        }

        const Maybe <Link> &GetSerie() const
        {
            return mSerie;
        }

        void SetSerie(const Link &serie)
        {
            mSerie = serie;
        }

        const Maybe <Link> &GetSeason() const
        {
            return mSeason;
        }

        void SetSeason(const Link &season)
        {
            mSeason = season;
        }

        const Maybe <int> &GetSeasonNo() const
        {
            return mSeasonNo;
        }

        void SetSeasonNo(int seasonNo)
        {
            mSeasonNo = seasonNo;
        }

        virtual bool InitFromJsonValue(const rapidjson::Value &value)
        {
            // Initialize parent properties
            if (!MediaProduct::InitFromJsonValue(value)) return false;

            {
                // Mandatory property
                if (!value.HasMember("EpisodeNo") || !value["EpisodeNo"].IsInt()) return false;
                SetEpisodeNo(value["EpisodeNo"].GetInt());
            }
            {
                // Mandatory property
                Link serie;
                if (!value.HasMember("Serie") || !value["Serie"].IsObject() || !serie.InitFromJsonValue(value["Serie"])) return false;
                SetSerie(serie);
            }
            {
                // Mandatory property
                Link season;
                if (!value.HasMember("Season") || !value["Season"].IsObject() || !season.InitFromJsonValue(value["Season"])) return false;
                SetSeason(season);
            }
            {
                // Mandatory property
                if (!value.HasMember("SeasonNo") || !value["SeasonNo"].IsInt()) return false;
                SetSeasonNo(value["SeasonNo"].GetInt());
            }

            return true;
        }

    private:
        Maybe <int> mEpisodeNo;
        Maybe <Link> mSerie;
        Maybe <Link> mSeason;
        Maybe <int> mSeasonNo;
    };
}

#endif //READY4AIR_EPISODE_H
