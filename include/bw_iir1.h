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
 *    Lightweight and fast first-order IIR filter in TDF-II form.
 *
 *    This is not a regular DSP module, as it exposes state and coefficients,
 *    and it's not appropriate for time-varying operation. If you need that,
 *    check out [bw_ap1](bw_ap1), [bw_hp1](bw_hp1), [bw_hs1](bw_hs1),
 *    [bw_lp1](bw_lp1), [bw_ls1](bw_ls1), [bw_mm1](bw_mm1), and
 *    [bw_one_pole](bw_one_pole).
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
 *    Computes and puts the initial output in `y_0` and the initial state in
 *    `s_0`, given the initial input `x_0` and coefficients `b0`, `b1`, and
 *    `a1`.
 *
 *    The given coefficients must describe a stable filter.
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
 *    Computes and puts each of the `n_channels` initial outputs in `y_0` and
 *    initial states in `s_0`, given the corresponding initial inputs `x_0` and
 *    coefficients `b0`, `b1`, and `a1`.
 *
 *    `y_0` and/or `s_0` may be `BW_NULL`, in which case the corresponding
 *    values are not written anywhere.
 *
 *    The given coefficients must describe a stable filter.
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
 *    Processes one input sample `x` using coefficients `b0`, `b1`, and `a1`.
 *    The output sample and next state value are put in `y` and `s`
 *    respectively.
 *
 *    The given coefficients must describe a stable filter.
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
 *    Processes the first `n_samples` of the input buffer `x` and fills the
 *    first `n_samples` of the output buffer `y`, while using coefficients `b0`,
 *    `b1`, and `a1`. The next state value is put in `s`.
 *
 *    The given coefficients must describe a stable filter.
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
 *    Processes the first `n_samples` of the `n_channels` input buffers `x` and
 *    fills the first `n_samples` of the `n_channels` output buffers `y`, while
 *    using coefficients `b0`, `b1`, and `a1`. The next `n_channels` state
 *    values are put in `s`.
 *
 *    The given coefficients must describe a stable filter.
 *
 *    #### bw_iir1_coeffs_ap1()
 *  ```>>> */
static inline void bw_iir1_coeffs_ap1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order allpass filter (90° shift at cutoff, approaching 180° shift
 *    at high frequencies) with unitary gain, using the bilinear transform with
 *    prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and positive) and the
 *    `cutoff` frequency (Hz, in [`1e-6f`, `1e12f`]). If `prewarp_freq` is `0`,
 *    then the prewarping frequency matches `cutoff`, otherwise the value
 *    specified by `prewarp_freq` (Hz, in [`1e-6f`, `1e12f`], however interally
 *    limited to avoid instability) is used.
 *
 *    #### bw_iir1_coeffs_hp1()
 *  ```>>> */
static inline void bw_iir1_coeffs_hp1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order highpass filter (6 dB/oct) with gain asymptotically
 *    approaching unity as frequency increases, using the bilinear transform
 *    with prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and positive) and the
 *    `cutoff` frequency (Hz, in [`1e-6f`, `1e12f`]). If `prewarp_freq` is `0`,
 *    then the prewarping frequency matches `cutoff`, otherwise the value
 *    specified by `prewarp_freq` (Hz, in [`1e-6f`, `1e12f`], however interally
 *    limited to avoid instability) is used.
 *
 *    #### bw_iir1_coeffs_hs1()
 *  ```>>> */
static inline void bw_iir1_coeffs_hs1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	char                high_gain_dB,
	float               high_gain,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order high shelf filter (6 dB/oct) with unitary DC gain, using the
 *    bilinear transform with prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and positive), the `cutoff`
 *    frequency (Hz, must be finite and positive), and the high-frequency gain
 *    `high_gain`, either as linear gain (in [`1e-30f`, `1e30f`]) if
 *    `high_gain_dB` is `0`, or otherwise in dB (in [`-600.f`, `600.f`]). If
 *    `prewarp_freq` is `0`, then the prewarping frequency matches `cutoff`,
 *    otherwise the value specified by `prewarp_freq` (Hz, in [`1e-6f`,
 *    `1e12f`], however interally limited to avoid instability) is used.
 *
 *    `cutoff * bw_sqrtf(high_gain)` must be in [`1e-6f`, `1e12f`], where
 *    `high_gain` is expressed as linear gain.
 *
 *    #### bw_iir1_coeffs_lp1()
 *  ```>>> */
static inline void bw_iir1_coeffs_lp1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order lowpass filter (6 dB/oct) with unitary DC gain, using the
 *    bilinear transform with prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and positive) and the
 *    `cutoff` frequency (Hz, in [`1e-6f`, `1e12f`]). If `prewarp_freq` is `0`,
 *    then the prewarping frequency matches `cutoff`, otherwise the value
 *    specified by `prewarp_freq` (Hz, in [`1e-6f`, `1e12f`], however interally
 *    limited to avoid instability) is used.
 *
 *    #### bw_iir1_coeffs_ls1()
 *  ```>>> */
static inline void bw_iir1_coeffs_ls1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	char                dc_gain_dB,
	float               dc_gain,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order high shelf filter (6 dB/oct) with unitary DC gain, using the
 *    bilinear transform with prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and  positive), the
 *    `cutoff` frequency (Hz, must be finite and positive), and the `dc_gain`,
 *    either as linear gain (in [`1e-30f`, `1e30f`]) if `dc_gain_dB` is `0`, or
 *    otherwise in dB (in [`-600.f`, `600.f`]). If `prewarp_freq` is `0`, then
 *    the prewarping frequency matches `cutoff`, otherwise the value specified
 *    by `prewarp_freq` (Hz, in [`1e-6f`, `1e12f`], however interally limited to
 *    avoid instability) is used.
 *
 *    `cutoff * bw_rcpf(bw_sqrtf(dc_gain))` must be in [`1e-6f`, `1e12f`], where
 *    `dc_gain` is expressed as linear gain.
 *
 *    #### bw_iir1_coeffs_mm1()
 *  ```>>> */
static inline void bw_iir1_coeffs_mm1(
	float               sample_rate,
	float               cutoff,
	char                prewarp_at_cutoff,
	float               prewarp_freq,
	float               coeff_x,
	float               coeff_lp,
	float * BW_RESTRICT b0,
	float * BW_RESTRICT b1,
	float * BW_RESTRICT a1);
/*! <<<```
 *    Computes and puts coefficient values in `b0`, `b1`, and `a1` resulting in
 *    a first-order filter implementing an approximation of the Laplace-domain
 *    transfer function
 *
 *    > H(s) = coeff\_x + (2 pi fc coeff\_lp) / (s + 2 pi fc)
 *
 *    where fc is the cutoff frequency, using the bilinear transform with
 *    prewarping.
 *
 *    It takes the `sample_rate` (Hz, must be finite and positive), the `cutoff`
 *    frequency (Hz, in [`1e-6f`, `1e12f`]), and output coefficients `coeff_x`
 *    and `coeff_lp` (both must be finite). If `prewarp_freq` is `0`, then the
 *    prewarping frequency matches `cutoff`, otherwise the value specified by
 *    `prewarp_freq` (Hz, in [`1e-6f`, `1e12f`], however interally limited to
 *    avoid instability) is used.
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

static inline void bw_iir1_assert_valid_coeffs(
		float b0,
		float b1,
		float a1) {
#ifndef BW_NO_DEBUG
	BW_ASSERT(bw_is_finite(b0));
	BW_ASSERT(bw_is_finite(b1));
	BW_ASSERT(bw_is_finite(a1));
	BW_ASSERT_DEEP(-1.f <= a1 && a1 <= 1.f);
#else
	(void)b0;
	(void)b1;
	(void)a1;
#endif
}

static inline void bw_iir1_reset(
		float               x_0,
		float * BW_RESTRICT y_0,
		float * BW_RESTRICT s_0,
		float               b0,
		float               b1,
		float               a1) {
	BW_ASSERT(bw_is_finite(x_0));
	BW_ASSERT(y_0 != BW_NULL);
	BW_ASSERT(s_0 != BW_NULL);
	BW_ASSERT(y_0 != s_0);
	bw_iir1_assert_valid_coeffs(b0, b1, a1);

	if (a1 == -1.f) {
		*y_0 = 0.f;
		*s_0 = 0.f;
	} else {
		const float d = bw_rcpf(1.f + a1);
		const float k = d * x_0;
		*y_0 = k * (b1 + b0);
		*s_0 = k * (b1 - a1 * b0);
	}

	BW_ASSERT(bw_is_finite(*y_0));
	BW_ASSERT(bw_is_finite(*s_0));
}

static inline void bw_iir1_reset_multi(
		const float *       x_0,
		float *             y_0,
		float * BW_RESTRICT s_0,
		float               b0,
		float               b1,
		float               a1,
		size_t              n_channels) {
	BW_ASSERT(x_0 != BW_NULL);
	BW_ASSERT_DEEP(bw_has_only_finite(x_0, n_channels));
	BW_ASSERT(s_0 == BW_NULL || x_0 != s_0);
	BW_ASSERT(y_0 == BW_NULL || s_0 == BW_NULL || y_0 != s_0);
	bw_iir1_assert_valid_coeffs(b0, b1, a1);

	if (y_0 != BW_NULL) {
		if (s_0 != BW_NULL)
			for (size_t i = 0; i < n_channels; i++)
				bw_iir1_reset(x_0[i], y_0 + i, s_0 + i, b0, b1, a1);
		else
			for (size_t i = 0; i < n_channels; i++) {
				float v_s;
				bw_iir1_reset(x_0[i], y_0 + i, &v_s, b0, b1, a1);
			}
	} else {
		if (s_0 != BW_NULL)
			for (size_t i = 0; i < n_channels; i++) {
				float v_y;
				bw_iir1_reset(x_0[i], &v_y, s_0 + i, b0, b1, a1);
			}
		else
			{} // no need to do anything
	}

	BW_ASSERT_DEEP(y_0 != BW_NULL ? bw_has_only_finite(y_0, n_channels) : 1);
	BW_ASSERT_DEEP(s_0 != BW_NULL ? bw_has_only_finite(s_0, n_channels) : 1);
}

static inline void bw_iir1_process1(
		float               x,
		float * BW_RESTRICT y,
		float * BW_RESTRICT s,
		float               b0,
		float               b1,
		float               a1) {
	BW_ASSERT(bw_is_finite(x));
	BW_ASSERT(y != BW_NULL);
	BW_ASSERT(s != BW_NULL);
	BW_ASSERT(y != s);
	BW_ASSERT(bw_is_finite(*s));
	bw_iir1_assert_valid_coeffs(b0, b1, a1);

	*y = b0 * x + *s;
	*s = b1 * x - a1 * *y;

	BW_ASSERT(bw_is_finite(*y));
	BW_ASSERT(bw_is_finite(*s));
}

static inline void bw_iir1_process(
		const float *       x,
		float *             y,
		float * BW_RESTRICT s,
		float               b0,
		float               b1,
		float               a1,
		size_t              n_samples) {
	BW_ASSERT(x != BW_NULL);
	BW_ASSERT_DEEP(bw_has_only_finite(x, n_samples));
	BW_ASSERT(y != BW_NULL);
	BW_ASSERT(s != BW_NULL);
	BW_ASSERT(x != s);
	BW_ASSERT(y != s);
	BW_ASSERT(bw_is_finite(*s));
	bw_iir1_assert_valid_coeffs(b0, b1, a1);

	for (size_t i = 0; i < n_samples; i++)
		bw_iir1_process1(x[i], y + i, s, b0, b1, a1);

	BW_ASSERT_DEEP(bw_has_only_finite(y, n_samples));
	BW_ASSERT(bw_is_finite(*s));
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
	BW_ASSERT(x != BW_NULL);
	BW_ASSERT(y != BW_NULL);
	BW_ASSERT(s != BW_NULL);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT(x[i] != BW_NULL);
		BW_ASSERT_DEEP(bw_has_only_finite(x[i], n_samples));
		BW_ASSERT(y[i] != BW_NULL);
	}
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = i + 1; j < n_channels; j++)
			BW_ASSERT(y[i] != y[j]);
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = 0; j < n_channels; j++)
			BW_ASSERT(i == j || x[i] != y[j]);
	for (size_t i = 0; i < n_channels; i++)
		BW_ASSERT(bw_is_finite(s[i]));
#endif
	bw_iir1_assert_valid_coeffs(b0, b1, a1);

	for (size_t i = 0; i < n_samples; i++)
		for (size_t j = 0; j < n_channels; j++)
			bw_iir1_process1(x[j][i], y[j] + i, s + j, b0, b1, a1);

#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT_DEEP(bw_has_only_finite(y[i], n_samples));
		BW_ASSERT(bw_is_finite(s[i]));
	}
#endif
}

#define BW_IIR1_COEFFS_COMMON \
	prewarp_freq = prewarp_at_cutoff ? cutoff : prewarp_freq; \
	prewarp_freq = bw_minf(prewarp_freq, 0.499f * sample_rate); \
	const float t = bw_tanf(3.141592653589793f * prewarp_freq * bw_rcpf(sample_rate)); \
	const float k = t * cutoff; \
	const float d = bw_rcpf(k + prewarp_freq); \
	*a1 = d * (k - prewarp_freq);

static inline void bw_iir1_assert_valid_params(
		float sample_rate,
		float cutoff,
		char prewarp_at_cutoff,
		float prewarp_freq) {
#ifndef BW_NO_DEBUG
	BW_ASSERT(bw_is_finite(sample_rate));
	BW_ASSERT(sample_rate > 0.f);
	BW_ASSERT(bw_is_finite(cutoff));
	BW_ASSERT(cutoff >= 1e-6f && cutoff <= 1e12f);
	BW_ASSERT(prewarp_at_cutoff ? bw_is_finite(prewarp_freq) : 1);
	BW_ASSERT(prewarp_at_cutoff ? prewarp_freq >= 1e-6f && prewarp_freq <= 1e12f : 1);
#else
	(void)sample_rate;
	(void)cutoff;
	(void)prewarp_at_cutoff;
	(void)prewarp_freq;
#endif
}

#define BW_IIR1_ASSERT_VALID_COEFF_PTRS \
	BW_ASSERT(b0 != BW_NULL); \
	BW_ASSERT(b1 != BW_NULL); \
	BW_ASSERT(a1 != BW_NULL); \
	BW_ASSERT(b0 != b1); \
	BW_ASSERT(b0 != a1); \
	BW_ASSERT(b1 != a1);

static inline void bw_iir1_coeffs_ap1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS

	BW_IIR1_COEFFS_COMMON
	*b0 = *a1;
	*b1 = 1.f;

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

static inline void bw_iir1_coeffs_hp1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS

	BW_IIR1_COEFFS_COMMON
	*b0 = d * (k - prewarp_freq);
	*b1 = -*b0;

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

static inline void bw_iir1_coeffs_hs1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		char                high_gain_dB,
		float               high_gain,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS
	BW_ASSERT(bw_is_finite(high_gain));
	BW_ASSERT(high_gain_dB ? high_gain >= -600.f && high_gain <= 600.f : high_gain >= 1e-30f && high_gain <= 1e30f);

	high_gain = high_gain_dB ? bw_dB2linf(high_gain) : high_gain;

	BW_ASSERT_DEEP(cutoff * bw_sqrtf(high_gain) >= 1e-6f && cutoff * bw_sqrtf(high_gain) <= 1e12f);

	cutoff = cutoff * bw_sqrtf(high_gain);
	BW_IIR1_COEFFS_COMMON
	const float k2 = high_gain * prewarp_freq;
	*b0 = d * (k + k2);
	*b1 = d * (k - k2);

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

static inline void bw_iir1_coeffs_lp1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS

	BW_IIR1_COEFFS_COMMON
	*b0 = d * k;
	*b1 = *b0;

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

static inline void bw_iir1_coeffs_ls1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		char                dc_gain_dB,
		float               dc_gain,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS
	BW_ASSERT(bw_is_finite(dc_gain));
	BW_ASSERT(dc_gain_dB ? dc_gain >= -600.f && dc_gain <= 600.f : dc_gain >= 1e-30f && dc_gain <= 1e30f);

	dc_gain = dc_gain_dB ? bw_dB2linf(dc_gain) : dc_gain;

	BW_ASSERT_DEEP(cutoff * bw_rcpf(bw_sqrtf(dc_gain)) >= 1e-6f && cutoff * bw_rcpf(bw_sqrtf(dc_gain)) <= 1e12f);

	cutoff = cutoff * bw_rcpf(bw_sqrtf(dc_gain));
	BW_IIR1_COEFFS_COMMON
	const float k2 = dc_gain * k;
	*b0 = d * (k2 + prewarp_freq);
	*b1 = d * (k2 - prewarp_freq);

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

static inline void bw_iir1_coeffs_mm1(
		float               sample_rate,
		float               cutoff,
		char                prewarp_at_cutoff,
		float               prewarp_freq,
		float               coeff_x,
		float               coeff_lp,
		float * BW_RESTRICT b0,
		float * BW_RESTRICT b1,
		float * BW_RESTRICT a1) {
	bw_iir1_assert_valid_params(sample_rate, cutoff, prewarp_at_cutoff, prewarp_freq);
	BW_IIR1_ASSERT_VALID_COEFF_PTRS

	BW_IIR1_COEFFS_COMMON
	const float k2 = prewarp_freq * coeff_x;
	const float k3 = k * (coeff_lp + coeff_x);
	*b0 = d * (k3 + k2);
	*b1 = d * (k3 - k2);

	bw_iir1_assert_valid_coeffs(*b0, *b1, *a1);
}

#undef BW_IIR1_COEFFS_COMMON
#undef BW_IIR1_ASSERT_VALID_COEFF_PTRS

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
	iir1Reset<N_CHANNELS>(x0.data(), y0 != BW_NULL ? y0.data() : BW_NULL, s0 != BW_NULL ? s0.data() : BW_NULL, b0, b1, a1);
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
