/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
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

#pragma once

#if ENABLE(SPEECH_SYNTHESIS)

#include "Event.h"
#include "SpeechSynthesisEventInit.h"
#include "SpeechSynthesisUtterance.h"

namespace WebCore {

class SpeechSynthesisEvent : public Event {
    WTF_MAKE_TZONE_OR_ISO_ALLOCATED(SpeechSynthesisEvent);
public:

    static Ref<SpeechSynthesisEvent> create(const AtomString& type, const SpeechSynthesisEventInit&);

    const SpeechSynthesisUtterance* utterance() const { return m_utterance.get(); }
    unsigned long charIndex() const { return m_charIndex; }
    unsigned long charLength() const { return m_charLength; }
    float elapsedTime() const { return m_elapsedTime; }
    const String& name() const { return m_name; }

protected:
    SpeechSynthesisEvent(enum EventInterfaceType, const AtomString& type, const SpeechSynthesisEventInit&);

private:
    RefPtr<SpeechSynthesisUtterance> m_utterance;
    unsigned long m_charIndex;
    unsigned long m_charLength;
    float m_elapsedTime;
    String m_name;
};

} // namespace WebCore

#endif // ENABLE(SPEECH_SYNTHESIS)
