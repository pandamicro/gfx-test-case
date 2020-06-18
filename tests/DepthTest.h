#pragma once

#include "TestBase.h"

namespace cc {

class DepthTexture: public TestBaseI
{
public:
    DEFINE_CREATE_METHOD(DepthTexture)
    DepthTexture(const WindowInfo& info) : TestBaseI(info) {};
    ~DepthTexture() = default;

public:
     virtual void tick(float dt) override;
     virtual bool initialize() override;
     virtual void destroy() override;

private:
    Framebuffer* _bunnyFBO;

    Mat4 _view;
    Mat4 _model;
    Mat4 _projection;
    Vec3 _eye;
    Vec3 _center;
    Vec3 _up;
    
    float _dt = 0.0f;
};

} // namespace cc
