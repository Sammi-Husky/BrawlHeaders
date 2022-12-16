#include <types.h>
#include <StaticAssert.h>
#include <so/so_event_observer.h>

class soLogEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
    virtual void notifyLogEventCollisionHit(float, int taskId1, int taskId2, int);
    virtual void notifyLogEventGroundDamage(); // TODO
    virtual void notifyLogEventDead(int entryId1, int entryId2, int, int);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soLogEventObserver) == 12)
};
