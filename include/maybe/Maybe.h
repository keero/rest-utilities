//
// Created by Martin Kero on 05/01/16.
//

#ifndef REST_UTILITIES_MAYBE_H
#define REST_UTILITIES_MAYBE_H


template <typename T>
class Maybe
{
public:
    Maybe() :
            mNothing(true)
    {
    }

    virtual ~Maybe()
    {
    }

    void Set(const T &value)
    {
        mJust = value;
        mNothing = false;
    }

    void Unset()
    {
        mNothing = true;
    }

    bool Nothing()
    {
        return mNothing;
    }

    T Just()
    {
        return mJust;
    }

private:
    bool mNothing;
    T mJust;
};


#endif //REST_UTILITIES_MAYBE_H
