/*
 * Copyright (c) 2020 - 2023 the ThorVG project. All rights reserved.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "tvgCanvas.h"

/************************************************************************/
/* External Class Implementation                                        */
/************************************************************************/

Canvas::Canvas(RenderMethod *pRenderer):pImpl(new Impl(pRenderer))
{
}


Canvas::~Canvas()
{
    delete(pImpl);
}


list<Paint*>& Canvas::paints() noexcept
{
    return pImpl->paints;
}


Result Canvas::push(unique_ptr<Paint> paint) noexcept
{
    return pImpl->push(std::move(paint));
}


Result Canvas::clear(bool paints, bool buffer) noexcept
{
    return pImpl->clear(paints, buffer);
}


Result Canvas::draw() noexcept
{
    TVGLOG("RENDERER", "Draw S. -------------------------------- Canvas(%p)", this);
    auto ret = pImpl->draw();
    TVGLOG("RENDERER", "Draw E. -------------------------------- Canvas(%p)", this);

    return ret;
}


Result Canvas::update(Paint* paint) noexcept
{
    TVGLOG("RENDERER", "Update S. ------------------------------ Canvas(%p)", this);
    auto ret = pImpl->update(paint, false);
    TVGLOG("RENDERER", "Update E. ------------------------------ Canvas(%p)", this);

    return ret;
}


Result Canvas::sync() noexcept
{
    return pImpl->sync();
}
