#include "ClearScreenTest.h"

namespace cc {

void ClearScreen::destroy() {
}

bool ClearScreen::initialize() {
    return true;
}

void ClearScreen::tick(float dt) {

    _time += dt;
    gfx::Color clearColor;
    clearColor.x = 1.0f;
    clearColor.y = std::abs(std::sin(_time));
    clearColor.z = 0.0f;
    clearColor.w = 1.0f;

    _device->acquire();

    gfx::Rect renderArea = {0, 0, _device->getWidth(), _device->getHeight()};

    auto commandBuffer = _commandBuffers[0];
    commandBuffer->begin();
    commandBuffer->beginRenderPass(_fbo->getRenderPass(), _fbo, renderArea, &clearColor, 1.0f, 0);
    commandBuffer->endRenderPass();
    commandBuffer->end();

    _device->getQueue()->submit(_commandBuffers);
    _device->present();
}

} // namespace cc
