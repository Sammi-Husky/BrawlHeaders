#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_event_presenter.h>

class ftOutsideEventPresenter : public soEventPresenter<ftOutsideEventPresenter> {
    int m_entryId;
public:
    virtual ~ftOutsideEventPresenter();

    void notifyOutsideEventKnockout();

    STATIC_CHECK(sizeof(ftOutsideEventPresenter) == 16)
};