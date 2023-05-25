#include <StaticAssert.h>
#include <so/event/so_event_observer.h>
#include <types.h>

class soLogEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyLogEventCollisionHit(float, int taskId1, int taskId2, int);
    virtual void notifyLogEventGroundDamage(); // TODO
    virtual void notifyLogEventDead(int entryId1, int entryId2, int, int);
    char _spacer1[2];
};
static_assert(sizeof(soLogEventObserver) == 12, "Class is wrong size!");
