#ifndef READY4AIR_EPISODE_H
#define READY4AIR_EPISODE_H

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

        int GetEpisodeNo() const
        {
            return mEpisodeNo;
        }

        void SetEpisodeNo(int episodeNo)
        {
            mEpisodeNo = episodeNo;
        }

        const Link &GetSerie() const
        {
            return mSerie;
        }

        void SetSerie(const Link &serie)
        {
            mSerie = serie;
        }

        const Link &GetSeason() const
        {
            return mSeason;
        }

        void SetSeason(const Link &season)
        {
            mSeason = season;
        }

        int GetSeasonNo() const
        {
            return mSeasonNo;
        }

        void SetSeasonNo(int seasonNo)
        {
            mSeasonNo = seasonNo;
        }

    private:
        int mEpisodeNo;
        Link mSerie;
        Link mSeason;
        int mSeasonNo;
    };
}

#endif //READY4AIR_EPISODE_H
