package main

// #cgo CFLAGS: -I. -fpic
// #cgo LDFLAGS: -lstdc++ -L. liblangdet.a
// #include "lang.h"
// #include <stdlib.h>
import "C"

import (
	"unsafe"
)

type Language string

func DetectLanguage(text string) (language Language) {
	cStr := C.CString(text)
	defer C.free(unsafe.Pointer(cStr))
	language = Language(C.GoString(C.detect_language(cStr)))
	return
}
