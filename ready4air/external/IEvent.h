#ifndef READ4AIR_IEVENT_H
#define READ4AIR_IEVENT_H

namespace ready4air
{
    template<typename T>
    class IEvent
    {
    public:
        virtual void Emit(const T &payload) = 0;
    };
}

#endif //READ4AIR_IEVENT_H
