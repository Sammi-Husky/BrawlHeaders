#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/stageobject.h>
#include <so/so_event_observer.h>
#include <so/so_article.h>

class Weapon : public StageObject, public soStatusEventObserver, public soCollisionAttackEventObserver,
               public soCollisionHitEventObserver, public soArticle {

    char _spacer[52];

    // TODO: Virtual functions

    STATIC_CHECK(sizeof(Weapon) == 208)
};