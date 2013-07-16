// Copyright (c) 2011 Michael McCandless. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifdef __cplusplus
extern "C" {
#endif

#include "lang.h"

#ifdef __cplusplus
}
#endif

#define CLD_WINDOWS

#include "encodings/compact_lang_det/compact_lang_det.h"
#include "encodings/compact_lang_det/ext_lang_enc.h"
#include "base/string_util.h"
#include "cld_encodings.h"
 
const char* detect_language(const char *text)
{
        size_t size = strlen(text);
        bool is_plain_text = true;
        bool do_allow_extended_languages = true;
        bool do_pick_summary_language = false;
        bool do_remove_weak_matches = false;
        bool is_reliable;
        const char* tld_hint = NULL;
        int encoding_hint = UTF8;
        Language language_hint = UNKNOWN_LANGUAGE;
 
        double normalized_score3[3];
        Language language3[3];
        int percent3[3];
        int text_bytes;
 
        Language lang;
        lang = CompactLangDet::DetectLanguage(0,
                                              text,
                                              size,
                                              is_plain_text,
                                              do_allow_extended_languages,
                                              do_pick_summary_language,
                                              do_remove_weak_matches,
                                              tld_hint,
                                              encoding_hint,
                                              language_hint,
                                              language3,
                                              percent3,
                                              normalized_score3,
                                              &text_bytes,
                                              &is_reliable);
 
        /* for more methods to extract information take a look 
         * at /include/cld/languages/public/languages.h
         */
        return LanguageCode(lang);
}