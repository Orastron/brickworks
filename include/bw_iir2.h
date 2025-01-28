/*
 * Brickworks
 *
 * Copyright (C) 2025 Orastron Srl unipersonale
 *
 * Brickworks is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Brickworks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brickworks.  If not, see <http://www.gnu.org/licenses/>.
 *
 * File author: Stefano D'Angelo
 */

/*!
 *  module_type {{{ utility }}}
 *  version {{{ 1.0.0 }}}
 *  requires {{{ bw_common bw_math }}}
 *  description {{{
 *    XXX
 *  }}}
 *  changelog {{{
 *    <ul>
 *      <li>Version <strong>1.0.0</strong>:
 *        <ul>
 *          <li>First release.</li>
 *        </ul>
 *      </li>
 *    </ul>
 *  }}}
 */

#ifndef BW_IIR2_H
#define BW_IIR2_H

#ifdef BW_INCLUDE_WITH_QUOTES
# include "bw_common.h"
#else
# include <bw_common.h>
#endif

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
extern "C" {
#endif

/*** Public API ***/

/*! api {{{
 *    #### bw_iir2_reset()
 *  ```>>> */
static inline void bw_iir2_reset(
	float               x_0,
	float * BW_RESTRICT y_0,
	float * BW_RESTRICT s1_0,
	float * BW_RESTRICT s2_0,
	float               b0,
	float               b1,
	float               b2,
	float               a1,
	float               a2);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir2_reset_multi()
 *  ```>>> */
static inline void bw_iir2_reset_multi(
	const float *       x_0,
	float *             y_0,
	float * BW_RESTRICT s1_0,
	float *             s2_0,
	float               b0,
	float               b1,
	float               b2,
	float               a1,
	float               a2,
	size_t              n_channels);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir2_process1()
 *  ```>>> */
static inline void bw_iir2_process1(
	float               x,
	float * BW_RESTRICT y,
	float * BW_RESTRICT s1,
	float * BW_RESTRICT s2,
	float               b0,
	float               b1,
	float               b2,
	float               a1,
	float               a2);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir2_process()
 *  ```>>> */
static inline void bw_iir2_process(
	const float *       x,
	float *             y,
	float * BW_RESTRICT s1,
	float * BW_RESTRICT s2,
	float               b0,
	float               b1,
	float               b2,
	float               a1,
	float               a2,
	size_t              n_samples);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_process_multi()
 *  ```>>> */
static inline void bw_iir2_process_multi(
	const float * const * x,
	float * const *       y,
	float * BW_RESTRICT   s1,
	float * BW_RESTRICT   s2,
	float                 b0,
	float                 b1,
	float                 b2,
	float                 a1,
	float                 a2,
	size_t                n_channels,
	size_t                n_samples);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_ap2()
 *  ```>>> */
static inline void bw_iir2_coeffs_ap2(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_bp2()
 *  ```>>> */
static inline void bw_iir2_coeffs_bp2(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_hp2()
 *  ```>>> */
static inline void bw_iir2_coeffs_hp2(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_hs2_lin()
 *  ```>>> */
static inline void bw_iir2_coeffs_hs2_lin(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               high_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_hs2_dB()
 *  ```>>> */
static inline void bw_iir2_coeffs_hs2_dB(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               high_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_lp2()
 *  ```>>> */
static inline void bw_iir2_coeffs_lp2(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_ls2_lin()
 *  ```>>> */
static inline void bw_iir2_coeffs_ls2_lin(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               dc_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_ls2_dB()
 *  ```>>> */
static inline void bw_iir2_coeffs_ls2_dB(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               dc_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_mm2()
 *  ```>>> */
static inline void bw_iir2_coeffs_mm2(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               coeff_x,
	float               coeff_lp,
	float               coeff_bp,
	float               coeff_hp,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_notch()
 *  ```>>> */
static inline void bw_iir2_coeffs_notch(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_peak_lin()
 *  ```>>> */
static inline void bw_iir2_coeffs_peak_lin(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               peak_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_peak_dB()
 *  ```>>> */
static inline void bw_iir2_coeffs_peak_dB(
	float               sample_rate,
	float               cutoff,
	float               Q,
	float               prewarp_freq,
	float               peak_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_peak_lin_bw()
 *  ```>>> */
static inline void bw_iir2_coeffs_peak_lin_bw(
	float               sample_rate,
	float               cutoff,
	float               bandwidth,
	float               prewarp_freq,
	float               peak_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir2_coeffs_peak_dB_bw()
 *  ```>>> */
static inline void bw_iir2_coeffs_peak_dB_bw(
	float               sample_rate,
	float               cutoff,
	float               bandwidth,
	float               prewarp_freq,
	float               peak_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT b2,
	float * BW_RESTRICT a1,
	float * BW_RESTRICT a2);
/*! <<<```
 *    XXX
 *  }}} */

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
}
#endif

/*** Implementation ***/

/* WARNING: This part of the file is not part of the public API. Its content may
 * change at any time in future versions. Please, do not use it directly. */

#ifdef BW_INCLUDE_WITH_QUOTES
# include "bw_math.h"
#else
# include <bw_math.h>
#endif

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
extern "C" {
#endif

static inline void bw_iir2_reset(
		float               x_0,
		float * BW_RESTRICT y_0,
		float * BW_RESTRICT s1_0,
		float * BW_RESTRICT s2_0,
		float               b0,
		float               b1,
		float               b2,
		float               a1,
		float               a2) {
	// a1, a2...
	const float d = bw_rcpf(1.f + a1 + a2);
	const float k = d * x_0;
	*y_0 = k * (b0 + b1 + b2);
	*s1_0 = k * (b1 + b2 - b0 * (a1 + a2));
	*s2_0 = k * (b2 + b2 * a1 - a2 * (b0 + b1));
}

static inline void bw_iir2_reset_multi(
		const float *       x_0,
		float *             y_0,
		float * BW_RESTRICT s1_0,
		float *             s2_0,
		float               b0,
		float               b1,
		float               b2,
		float               a1,
		float               a2,
		size_t              n_channels) {
	if (y_0 != BW_NULL) {
		if (s1_0 != BW_NULL) {
			if (s2_0 != BW_NULL)
				for (size_t i = 0; i < n_channels; i++)
					bw_iir2_reset(x_0[i], y_0 + i, s1_0 + i, s2_0 + i, b0, b1, b2, a1, a2);
			else
				for (size_t i = 0; i < n_channels; i++) {
					float v_s2;
					bw_iir2_reset(x_0[i], y_0 + i, s1_0 + i, &v_s2, b0, b1, b2, a1, a2);
				}
		} else {
			if (s2_0 != BW_NULL)
				for (size_t i = 0; i < n_channels; i++) {
					float v_s1;
					bw_iir2_reset(x_0[i], y_0 + i, &v_s1, s2_0 + i, b0, b1, b2, a1, a2);
				}
			else
				for (size_t i = 0; i < n_channels; i++) {
					float v_s1, v_s2;
					bw_iir2_reset(x_0[i], y_0 + i, &v_s1, &v_s2, b0, b1, b2, a1, a2);
				}
		}
	} else {
		if (s1_0 != BW_NULL) {
			if (s2_0 != BW_NULL)
				for (size_t i = 0; i < n_channels; i++) {
					float v_y;
					bw_iir2_reset(x_0[i], &v_y, s1_0 + i, s2_0 + i, b0, b1, b2, a1, a2);
				}
			else
				for (size_t i = 0; i < n_channels; i++) {
					float v_y, v_s2;
					bw_iir2_reset(x_0[i], &v_y, s1_0 + i, &v_s2, b0, b1, b2, a1, a2);
				}
		} else {
			if (s2_0 != BW_NULL)
				for (size_t i = 0; i < n_channels; i++) {
					float v_y, v_s1;
					bw_iir2_reset(x_0[i], &v_y, &v_s1, s2_0 + i, b0, b1, b2, a1, a2);
				}
			else
				{} // no need to do anything
		}
	}
}

static inline void bw_iir2_process1(
		float               x,
		float * BW_RESTRICT y,
		float * BW_RESTRICT s1,
		float * BW_RESTRICT s2,
		float               b0,
		float               b1,
		float               b2,
		float               a1,
		float               a2) {
	*y = b0 * x + *s1;
	*s1 = b1 * x - a1 * *y + *s2;
	*s2 = b2 * x - a2 * *y;
}

static inline void bw_iir2_process(
		const float *       x,
		float *             y,
		float * BW_RESTRICT s1,
		float * BW_RESTRICT s2,
		float               b0,
		float               b1,
		float               b2,
		float               a1,
		float               a2,
		size_t              n_samples) {
	for (size_t i = 0; i < n_samples; i++)
		bw_iir2_process1(x[i], y + i, s1, s2, b0, b1, b2, a1, a2);
}

static inline void bw_iir2_process_multi(
		const float * const * x,
		float * const *       y,
		float * BW_RESTRICT   s1,
		float * BW_RESTRICT   s2,
		float                 b0,
		float                 b1,
		float                 b2,
		float                 a1,
		float                 a2,
		size_t                n_channels,
		size_t                n_samples) {
	for (size_t i = 0; i < n_samples; i++)
		for (size_t j = 0; j < n_channels; j++)
			bw_iir2_process1(x[j][i], y[j] + i, s1 + j, s2 + j, b0, b1, b2, a1, a2);
}

#define BW_IIR2_COEFFS_COMMON \
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate)); \
	const float k1 = prewarp_freq * prewarp_freq; \
	const float k2 = t * cutoff; \
	const float k3 = k2 * k2; \
	const float k4 = k2 * prewarp_freq; \
	const float k5 = Q * (k1 + k3); \
	const float d = bw_rcpf(k5 + k4); \
	*a1 = d * (Q + Q) * (k3 - k1); \
	*a2 = d * (k5 - k4);

static inline void bw_iir2_coeffs_ap2(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	*b0 = *a2;
	*b1 = *a1;
	*b2 = 1.f;
}

static inline void bw_iir2_coeffs_bp2(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	*b0 = Q * k4;
	*b1 = 0.f;
	*b2 = -*b0;
}

static inline void bw_iir2_coeffs_hp2(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	*b0 = Q * k1;
	*b1 = -(*b0 + *b0);
	*b2 = *b0;
}

static inline void bw_iir2_coeffs_hs2_lin(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               high_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	const float sg = bw_sqrtf(high_gain_lin);
	const float ssg = bw_sqrtf(sg);
	cutoff = cutoff * ssg;
	BW_IIR2_COEFFS_COMMON
	const float k6 = k1 * high_gain_lin;
	const float k7 = k3 - k3 * sg;
	const float k8 = Q * (k7 + k6);
	const float k9 = k4 * sg;
	*b0 = d * (k8 + k9);
	*b1 = d * (Q + Q) * (k7 - k6);
	*b2 = d * (k8 - k9);
}

static inline void bw_iir2_coeffs_hs2_dB(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               high_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	bw_iir2_coeffs_hs2_lin(sample_rate, cutoff, Q, prewarp_freq, bw_dB2linf(high_gain_dB), b0, b1, b2, a1, a2);
}

static inline void bw_iir2_coeffs_lp2(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	*b0 = Q * k3;
	*b1 = *b0 + *b0;
	*b2 = *b0;
}

static inline void bw_iir2_coeffs_ls2_lin(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               dc_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	const float sg = bw_sqrtf(dc_gain_lin);
	const float issg = bw_rcpf(bw_sqrtf(sg));
	cutoff = cutoff * issg;
	BW_IIR2_COEFFS_COMMON
	const float k6 = k3 * (dc_gain_lin - sg);
	const float k7 = Q * (k6 + k1);
	const float k8 = k4 * sg;
	*b0 = d * (k7 + k8);
	*b1 = d * (Q + Q) * (k6 - k1);
	*b2 = d * (k7 - k8);
}

static inline void bw_iir2_coeffs_ls2_dB(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               dc_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	bw_iir2_coeffs_ls2_lin(sample_rate, cutoff, Q, prewarp_freq, bw_dB2linf(dc_gain_dB), b0, b1, b2, a1, a2);
}

static inline void bw_iir2_coeffs_mm2(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               coeff_x,
		float               coeff_lp,
		float               coeff_bp,
		float               coeff_hp,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	const float k6 = k3 * (coeff_lp + coeff_x);
	const float k7 = k1 * (coeff_hp + coeff_x);
	const float k8 = k4 * (Q * coeff_bp + coeff_x);
	const float k9 = Q * (k6 + k7);
	*b0 = d * (k9 + k8);
	*b1 = d * (Q + Q) * (k6 - k7);
	*b2 = d * (k9 - k8);
}

static inline void bw_iir2_coeffs_notch(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	*b0 = d * k5;
	*b1 = *a1;
	*b2 = *b0;
}

static inline void bw_iir2_coeffs_peak_lin(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               peak_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	BW_IIR2_COEFFS_COMMON
	const float k6 = Q * (k1 + k3);
	const float k7 = k4 * peak_gain_lin;
	*b0 = d * (k6 + k7);
	*b1 = *a1;
	*b2 = d * (k6 - k7);
}

static inline void bw_iir2_coeffs_peak_dB(
		float               sample_rate,
		float               cutoff,
		float               Q,
		float               prewarp_freq,
		float               peak_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	bw_iir2_coeffs_peak_lin(sample_rate, cutoff, Q, prewarp_freq, bw_dB2linf(peak_gain_dB), b0, b1, b2, a1, a2);
}

static inline void bw_iir2_coeffs_peak_lin_bw(
		float               sample_rate,
		float               cutoff,
		float               bandwidth,
		float               prewarp_freq,
		float               peak_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	const float k6 = bw_pow2f(bandwidth);
	const float Q = bw_sqrtf(k6 * peak_gain_lin) * bw_rcpf(k6 - 1.f);
	bw_iir2_coeffs_peak_lin(sample_rate, cutoff, Q, prewarp_freq, peak_gain_lin, b0, b1, b2, a1, a2);
}

static inline void bw_iir2_coeffs_peak_dB_bw(
		float               sample_rate,
		float               cutoff,
		float               bandwidth,
		float               prewarp_freq,
		float               peak_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT b2,
		float * BW_RESTRICT a1,
		float * BW_RESTRICT a2) {
	bw_iir2_coeffs_peak_lin_bw(sample_rate, cutoff, bandwidth, prewarp_freq, bw_dB2linf(peak_gain_dB), b0, b1, b2, a1, a2);
}

#undef BW_IIR2_COEFFS_COMMON

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
}
#endif

#if !defined(BW_NO_CXX) && defined(__cplusplus)

# ifndef BW_CXX_NO_ARRAY
#  include <array>
# endif

namespace Brickworks {

/*** Public C++ API ***/

/*! api_cpp {{{
 *    ##### Brickworks::iir2Reset
 *  ```>>> */
template<size_t N_CHANNELS>
void iir2Reset(
	const float *       x0,
	float *             y0,
	float * BW_RESTRICT s10,
	float * BW_RESTRICT s20,
	float               b0,
	float               b1,
	float               b2,
	float               a1,
	float               a2);

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
void iir2Reset(
	std::array<float, N_CHANNELS>               x0,
	std::array<float, N_CHANNELS> * BW_RESTRICT y0,
	std::array<float, N_CHANNELS> * BW_RESTRICT s10,
	std::array<float, N_CHANNELS> * BW_RESTRICT s20,
	float                                       b0,
	float                                       b1,
	float                                       b2,
	float                                       a1,
	float                                       a2);
# endif

template<size_t N_CHANNELS>
void iir2Process(
	const float * const * x,
	float * const *       y,
	float * BW_RESTRICT   s1,
	float * BW_RESTRICT   s2,
	float                 b0,
	float                 b1,
	float                 b2,
	float                 a1,
	float                 a2,
	size_t                nSamples);

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
void iir2Process(
	std::array<const float *, N_CHANNELS>       x,
	std::array<float *, N_CHANNELS>             y,
	std::array<float, N_CHANNELS> * BW_RESTRICT s1,
	std::array<float, N_CHANNELS> * BW_RESTRICT s2,
	float                                       b0,
	float                                       b1,
	float                                       b2,
	float                                       a1,
	float                                       a2,
	size_t                                      nSamples);
# endif
/*! <<<```
 *  }}} */

/*** Implementation ***/

/* WARNING: This part of the file is not part of the public API. Its content may
 * change at any time in future versions. Please, do not use it directly. */

template<size_t N_CHANNELS>
inline void iir2Reset(
		const float *       x0,
		float *             y0,
		float * BW_RESTRICT s10,
		float * BW_RESTRICT s20,
		float               b0,
		float               b1,
		float               b2,
		float               a1,
		float               a2) {
	bw_iir2_reset_multi(x0, y0, s10, s20, b0, b1, b2, a1, a2, N_CHANNELS);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void iir2Reset(
		std::array<float, N_CHANNELS>               x0,
		std::array<float, N_CHANNELS> * BW_RESTRICT y0,
		std::array<float, N_CHANNELS> * BW_RESTRICT s10,
		std::array<float, N_CHANNELS> * BW_RESTRICT s20,
		float                                       b0,
		float                                       b1,
		float                                       b2,
		float                                       a1,
		float                                       a2) {
	iir2Reset<N_CHANNELS>(x0.data(), y0 != nullptr ? y0.data() : nullptr, s10 != nullptr ? s10.data() : nullptr, s20 != nullptr ? s20.data() : nullptr, b0, b1, b2, a1, a2);
}
# endif

template<size_t N_CHANNELS>
inline void iir2Process(
		const float * const * x,
		float * const *       y,
		float * BW_RESTRICT   s1,
		float * BW_RESTRICT   s2,
		float                 b0,
		float                 b1,
		float                 b2,
		float                 a1,
		float                 a2,
		size_t                nSamples) {
	bw_iir2_process_multi(x, y, s1, s2, b0, b1, b2, a1, a2, N_CHANNELS, nSamples);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void iir2Process(
		std::array<const float *, N_CHANNELS>       x,
		std::array<float *, N_CHANNELS>             y,
		std::array<float, N_CHANNELS> * BW_RESTRICT s1,
		std::array<float, N_CHANNELS> * BW_RESTRICT s2,
		float                                       b0,
		float                                       b1,
		float                                       b2,
		float                                       a1,
		float                                       a2,
		size_t                                      nSamples) {
	iir2Process<N_CHANNELS>(x.data(), y.data(), s1.data(), s2.data(), b0, b1, b2, a1, a2, nSamples);
}
# endif

}
#endif

#endif
