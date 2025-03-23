#pragma once

class gfRunnable {
public:
    virtual void run() = 0;
};
// TODO size assertion

class gfThread : public gfRunnable {
public:
    virtual void run() { }
};
// TODO size assertion
