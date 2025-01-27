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

#ifndef BW_IIR1_H
#define BW_IIR1_H

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
 *    #### bw_iir1_reset()
 *  ```>>> */
static inline void bw_iir1_reset(
	float               x_0,
	float * BW_RESTRICT y_0,
	float * BW_RESTRICT s_0,
	float               b0,
	float               b1,
	float               a1);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir1_reset_multi()
 *  ```>>> */
static inline void bw_iir1_reset_multi(
	const float *       x_0,
	float *             y_0,
	float * BW_RESTRICT s_0, 
	float               b0,
	float               b1,
	float               a1,
	size_t              n_channels);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir1_process1()
 *  ```>>> */
static inline void bw_iir1_process1(
	float               x,
	float * BW_RESTRICT y,
	float * BW_RESTRICT s,
	float               b0,
	float               b1,
	float               a1);
/*! <<<```
 *    XXX.
 *
 *    #### bw_iir1_process()
 *  ```>>> */
static inline void bw_iir1_process(
	const float *       x,
	float *             y,
	float * BW_RESTRICT s,
	float               b0,
	float               b1,
	float               a1,
	size_t              n_samples);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_process_multi()
 *  ```>>> */
static inline void bw_iir1_process_multi(
	const float * const * x,
	float * const *       y,
	float * BW_RESTRICT   s,
	float                 b0,
	float                 b1,
	float                 a1,
	size_t                n_channels,
	size_t                n_samples);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_ap1()
 *  ```>>> */
static inline void bw_iir1_coeffs_ap1(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_hp1()
 *  ```>>> */
static inline void bw_iir1_coeffs_hp1(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_hs1_lin()
 *  ```>>> */
static inline void bw_iir1_coeffs_hs1_lin(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float               high_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_hs1_dB()
 *  ```>>> */
static inline void bw_iir1_coeffs_hs1_dB(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float               high_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_lp1()
 *  ```>>> */
static inline void bw_iir1_coeffs_lp1(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_ls1_lin()
 *  ```>>> */
static inline void bw_iir1_coeffs_ls1_lin(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float               dc_gain_lin,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_ls1_dB()
 *  ```>>> */
static inline void bw_iir1_coeffs_ls1_dB(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float               dc_gain_dB,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    XXX
 *
 *    #### bw_iir1_coeffs_mm1()
 *  ```>>> */
static inline void bw_iir1_coeffs_mm1(
	float               sample_rate,
	float               cutoff,
	float               prewarp_freq,
	float               coeff_x,
	float               coeff_lp,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
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

static void bw_iir1_reset(
		float               x_0,
		float * BW_RESTRICT y_0,
		float * BW_RESTRICT s_0,
		float               b0,
		float               b1,
		float               a1) {
	// -1<a1<1
	const float d = bw_rcpf(1.f + a1);
	const float k = d * x_0;
	*y_0 = k * (b1 + b0);
	*s_0 = k * (b1 - a1 * b0);
}

static inline void bw_iir1_reset_multi(
		const float *       x_0,
		float *             y_0,
		float * BW_RESTRICT s_0,
		float               b0,
		float               b1,
		float               a1,
		size_t              n_channels) {
	if (y_0 != BW_NULL) {
		if (s_0 != BW_NULL)
			for (size_t i = 0; i < n_channels; i++)
				bw_iir1_reset(x_0[i], y0 + i, s_0 + i, b0, b1, a1);
		else
			for (size_t i = 0; i < n_channels; i++) {
				float v_s;
				bw_iir1_reset(x_0[i], y0 + i, &v_s, b0, b1, a1);
			}
	} else {
		if (s_0 != BW_NULL)
			for (size_t i = 0; i < n_channels; i++) {
				float v_y;
				bw_iir1_reset(x_0[i], &v_y, s_0 + i, b0, b1, a1);
			}
		else
			; // no need to do anything
	}
}

static inline void bw_iir1_process1(
		float               x,
		float * BW_RESTRICT y,
		float * BW_RESTRICT s,
		float               b0,
		float               b1,
		float               a1) {
	*y = b0 * x + *s;
	*s = b1 * x - a1 * *y;
}

static inline void bw_iir1_process(
		const float *       x,
		float *             y,
		float * BW_RESTRICT s,
		float               b0,
		float               b1,
		float               a1,
		size_t              n_samples) {
	for (size_t i = 0; i < n_samples; i++)
		bw_iir1_process1(x[i], y + i, s, b0, b1, a1);
}

static inline void bw_iir1_process_multi(
		const float * const * x,
		float * const *       y,
		float * BW_RESTRICT   s,
		float                 b0,
		float                 b1,
		float                 a1,
		size_t                n_channels,
		size_t                n_samples) {
	for (size_t i = 0; i < n_samples; i++)
		for (size_t j = 0; j < n_channels; j++)
			bw_iir1_process1(x[j][i], y[j] + i, s + j, b0, b1, a1);
}

static inline void bw_iir1_coeffs_ap1(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	*a1 = d * (k - prewarp_freq);
	*b0 = *a1;
	*b1 = 1.f;
}

static inline void bw_iir1_coeffs_hp1(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	*a1 = d * (k - prewarp_freq);
	*b0 = d * prewarp_freq;
	*b1 = -*b0;
}

static inline void bw_iir1_coeffs_hs1_lin(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float               high_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	const float k2 = high_gain_lin * prewarp_freq;
	*a1 = d * (k - prewarp_freq);
	*b0 = d * (k + k2);
	*b1 = d * (k - k2);
}

static inline void bw_iir1_coeffs_hs1_dB(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float               high_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_coeffs_hs1_lin(sample_rate, cutoff, prewarp_freq, bw_dB2linf(high_gain_dB), b0, b1, a1);
}

static inline void bw_iir1_coeffs_lp1(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	*a1 = d * (k - prewarp_freq);
	*b0 = d * k;
	*b1 = *b0;
}

static inline void bw_iir1_coeffs_ls1_lin(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float               dc_gain_lin,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	const float k2 = dc_gain_lin * k;
	*a1 = d * (k - prewarp_freq);
	*b0 = d * (k2 + prewarp_freq);
	*b1 = d * (k2 - prewarp_freq);
}

static inline void bw_iir1_coeffs_ls1_dB(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float               dc_gain_dB,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_coeffs_ls1_lin(sample_rate, cutoff, prewarp_freq, bw_dB2linf(dc_gain_dB), b0, b1, a1);
}

static inline void bw_iir1_coeffs_mm1(
		float               sample_rate,
		float               cutoff,
		float               prewarp_freq,
		float               coeff_x,
		float               coeff_lp,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate));
	const float k = t * cutoff;
	const float d = bw_rcpf(k + prewarp_freq);
	const float k2 = coeff_x * prewarp_freq;
	const float k3 = coeff_lp * k;
	*a1 = d * (k - prewarp_freq);
	*b0 = d * (k3 + k2);
	*b1 = d * (k3 - k2);
}

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
}
#endif

#if !defined(BW_NO_CXX) && defined(__cplusplus)

# ifndef BW_CXX_NO_ARRAY
#  include <array>
# endif

namespace Brickworks {

/*** Public C++ API ***/

//XXX

/*! api_cpp {{{
 *    ##### Brickworks::iir1Reset
 *  ```>>> */
template<size_t N_CHANNELS>
void iir1Reset(
	const float *       x0,
	float *             y0,
	float * BW_RESTRICT s0, 
	float               b0,
	float               b1,
	float               a1);

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
void iir1Reset(
	std::array<float, N_CHANNELS>               x0,
	std::array<float, N_CHANNELS> * BW_RESTRICT y0,
	std::array<float, N_CHANNELS> * BW_RESTRICT s0,
	float                                       b0,
	float                                       b1,
	float                                       a1);
# endif

template<size_t N_CHANNELS>
void iir1Process(
	const float * const * x,
	float * const *       y,
	float * BW_RESTRICT   s,
	float                 b0,
	float                 b1,
	float                 a1,
	size_t                nSamples);

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
void iir1Process(
	std::array<const float *, N_CHANNELS>       x,
	std::array<float *, N_CHANNELS>             y,
	std::array<float, N_CHANNELS> * BW_RESTRICT s,
	float                                       b0,
	float                                       b1,
	float                                       a1,
	size_t                                      nSamples);
# endif
/*! <<<```
 *  }}} */

/*** Implementation ***/

/* WARNING: This part of the file is not part of the public API. Its content may
 * change at any time in future versions. Please, do not use it directly. */

template<size_t N_CHANNELS>
inline void iir1Reset(
		const float *       x0,
		float *             y0,
		float * BW_RESTRICT s0, 
		float               b0,
		float               b1,
		float               a1) {
	bw_iir1_reset_multi(x0, y0, s0, b0, b1, a1, N_CHANNELS);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void iir1Reset(
		std::array<float, N_CHANNELS>               x0,
		std::array<float, N_CHANNELS> * BW_RESTRICT y0,
		std::array<float, N_CHANNELS> * BW_RESTRICT s0,
		float                                       b0,
		float                                       b1,
		float                                       a1) {
	iir1Reset<N_CHANNELS>(x0.data(), y0 != nullptr ? y0.data() : nullptr, s0 != nullptr ? s0.data() : nullptr, b0, b1, a1);
}
# endif

template<size_t N_CHANNELS>
inline void iir1Process(
		const float * const * x,
		float * const *       y,
		float * BW_RESTRICT   s,
		float                 b0,
		float                 b1,
		float                 a1,
		size_t                nSamples) {
	bw_iir1_process_multi(x, y, s, b0, b1, a1, N_CHANNELS, nSamples);	
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void iir1Process(
		std::array<const float *, N_CHANNELS>       x,
		std::array<float *, N_CHANNELS>             y,
		std::array<float, N_CHANNELS> * BW_RESTRICT s,
		float                                       b0,
		float                                       b1,
		float                                       a1,
		size_t                                      nSamples) {
	iir1Process<N_CHANNELS>(x.data(), y.data(), s.data(), b0, b1, a1, nSamples);
}
# endif

}
#endif

#endif
