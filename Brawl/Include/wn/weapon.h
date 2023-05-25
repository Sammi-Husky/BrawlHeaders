#pragma once

#include <StaticAssert.h>
#include <so/so_article.h>
#include <so/event/so_event_observer.h>
#include <so/stageobject.h>
#include <types.h>

class Weapon : public StageObject, public soStatusEventObserver, public soCollisionAttackEventObserver, public soCollisionHitEventObserver, public soArticle {

    char _spacer[52];

    // TODO: Virtual functions
};
static_assert(sizeof(Weapon) == 208, "Class is wrong size!");