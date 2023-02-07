#pragma once

#include <string>

#define MID_VOLUME 38
#define HI_VOLUME (MID_VOLUME + 33)

// Von Neumann Arch:
//  Stack (v down v)
//  -- Frames (sub/method/function)
//  AIR
// HEAP (^ up ^)
// GLOBAL DATA
// ---- ROM (Harvard)
// LITERALS
// TEXT/CODE
//
//  Neural Network
//
//   *  *    *   *   *  * (inputs)
//    \ |    |
//      *    *     *   * (intermediate)
//
//
//     * *   *     *    * (output)
//

std::string hello(std::string name);
