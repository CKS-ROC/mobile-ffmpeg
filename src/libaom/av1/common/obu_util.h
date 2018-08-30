/*
 * Copyright (c) 2018, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */
#ifndef AV1_COMMON_OBU_UTIL_H
#define AV1_COMMON_OBU_UTIL_H

#include "aom/aom_codec.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  size_t size;  // Size (1 or 2 bytes) of the OBU header (including the
                // optional OBU extension header) in the bitstream.
  OBU_TYPE type;
  int has_size_field;
  int has_extension;
  // The following fields come from the OBU extension header and therefore are
  // only used if has_extension is true.
  int temporal_layer_id;
  int spatial_layer_id;
} ObuHeader;

aom_codec_err_t aom_read_obu_header(uint8_t *buffer, size_t buffer_length,
                                    size_t *consumed, ObuHeader *header,
                                    int is_annexb);

aom_codec_err_t aom_read_obu_header_and_size(const uint8_t *data,
                                             size_t bytes_available,
                                             int is_annexb,
                                             ObuHeader *obu_header,
                                             size_t *const payload_size,
                                             size_t *const bytes_read);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // AV1_COMMON_OBU_UTIL_H
