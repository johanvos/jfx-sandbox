/*
 * Copyright (C) 2007 Eric Seidel <eric@webkit.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#pragma once

#include "SVGElement.h"

namespace WebCore {

class CSSValueList;

class SVGFontFaceSrcElement final : public SVGElement {
    WTF_MAKE_TZONE_OR_ISO_ALLOCATED(SVGFontFaceSrcElement);
    WTF_OVERRIDE_DELETE_FOR_CHECKED_PTR(SVGFontFaceSrcElement);
public:
    static Ref<SVGFontFaceSrcElement> create(const QualifiedName&, Document&);

    Ref<CSSValueList> createSrcValue() const;

private:
    SVGFontFaceSrcElement(const QualifiedName&, Document&);

    void childrenChanged(const ChildChange&) final;
    bool rendererIsNeeded(const RenderStyle&) final { return false; }
};

} // namespace WebCore
