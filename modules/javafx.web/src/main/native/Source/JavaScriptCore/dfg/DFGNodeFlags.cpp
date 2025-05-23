/*
 * Copyright (C) 2012, 2013, 2014 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "DFGNodeFlags.h"

#if ENABLE(DFG_JIT)

#include <wtf/CommaPrinter.h>
#include <wtf/StringPrintStream.h>

namespace JSC { namespace DFG {

void dumpNodeFlags(PrintStream& actualOut, NodeFlags flags)
{
    StringPrintStream out;
    CommaPrinter comma("|"_s);

    if (flags & NodeResultMask) {
        switch (flags & NodeResultMask) {
        case NodeResultJS:
            out.print(comma, "JS"_s);
            break;
        case NodeResultNumber:
            out.print(comma, "Number"_s);
            break;
        case NodeResultDouble:
            out.print(comma, "Double"_s);
            break;
        case NodeResultInt32:
            out.print(comma, "Int32"_s);
            break;
        case NodeResultInt52:
            out.print(comma, "Int52"_s);
            break;
        case NodeResultBoolean:
            out.print(comma, "Boolean"_s);
            break;
        case NodeResultStorage:
            out.print(comma, "Storage"_s);
            break;
        default:
            RELEASE_ASSERT_NOT_REACHED();
            break;
        }
    }

    if (flags & NodeMustGenerate)
        out.print(comma, "MustGen"_s);

    if (flags & NodeHasVarArgs)
        out.print(comma, "VarArgs"_s);

    if (flags & NodeResultMask) {
        if (!(flags & NodeBytecodeUsesAsNumber))
            out.print(comma, "PureInt"_s);
        else
            out.print(comma, "PureNum"_s);
        if (flags & NodeBytecodeNeedsNegZero)
            out.print(comma, "NeedsNegZero"_s);
        if (flags & NodeBytecodeNeedsNaNOrInfinity)
            out.print(comma, "NeedsNaNOrInfinity"_s);
        if (flags & NodeBytecodeUsesAsOther)
            out.print(comma, "UseAsOther"_s);
    }

    if (flags & NodeMayHaveDoubleResult)
        out.print(comma, "MayHaveDoubleResult"_s);

    if (flags & NodeMayHaveBigInt32Result)
        out.print(comma, "MayHaveBigInt32Result"_s);

    if (flags & NodeMayHaveHeapBigIntResult)
        out.print(comma, "MayHaveHeapBigIntResult"_s);

    if (flags & NodeMayHaveNonNumericResult)
        out.print(comma, "MayHaveNonNumericResult"_s);

    if (flags & NodeMayOverflowInt52)
        out.print(comma, "MayOverflowInt52"_s);

    if (flags & NodeMayOverflowInt32InBaseline)
        out.print(comma, "MayOverflowInt32InBaseline"_s);

    if (flags & NodeMayOverflowInt32InDFG)
        out.print(comma, "MayOverflowInt32InDFG"_s);

    if (flags & NodeMayNegZeroInBaseline)
        out.print(comma, "MayNegZeroInBaseline"_s);

    if (flags & NodeMayNegZeroInDFG)
        out.print(comma, "MayNegZeroInDFG"_s);

    if (flags & NodeBytecodeUsesAsInt)
        out.print(comma, "UseAsInt"_s);

    if (flags & NodeBytecodePrefersArrayIndex)
        out.print(comma, "ReallyWantsInt"_s);

    if (flags & NodeIsFlushed)
        out.print(comma, "IsFlushed"_s);

    CString string = out.toCString();
    if (!string.length())
        actualOut.print("<empty>"_s);
    else
        actualOut.print(string);
}

} } // namespace JSC::DFG

#endif // ENABLE(DFG_JIT)

