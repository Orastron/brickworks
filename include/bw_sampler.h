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
 *  module_type {{{ dsp }}}
 *  version {{{ 1.0.0 }}}
 *  requires {{{ bw_common }}}
 *  description {{{
 *    Very basic sampler with variable playback speed.
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

#ifndef BW_SAMPLER_H
#define BW_SAMPLER_H

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
 *    #### bw_sampler_coeffs
 *  ```>>> */
typedef struct bw_sampler_coeffs bw_sampler_coeffs;
/*! <<<```
 *    Coefficients and related.
 *
 *    #### bw_sampler_state
 *  ```>>> */
typedef struct bw_sampler_state bw_sampler_state;
/*! <<<```
 *    Internal state and related.
 *
 *    #### bw_sampler_phase
 *  ```>>> */
typedef enum {
	bw_sampler_phase_before,
	bw_sampler_phase_playing,
	bw_sampler_phase_done
} bw_sampler_phase;
/*! <<<```
 *    Sampler playback phase:
 *     * `bw_sampler_phase_before`: playback has not yet started;
 *     * `bw_sampler_phase_playing`: playback ongoing;
 *     * `bw_sampler_phase_done`: playback finished.
 *
 *    #### bw_sampler_init()
 *  ```>>> */
static inline void bw_sampler_init(
	bw_sampler_coeffs * BW_RESTRICT coeffs);
/*! <<<```
 *    Initializes input parameter values in `coeffs`.
 *
 *    #### bw_sampler_set_sample_rate()
 *  ```>>> */
static inline void bw_sampler_set_sample_rate(
	bw_sampler_coeffs * BW_RESTRICT coeffs,
	float                           sample_rate);
/*! <<<```
 *    Sets the `sample_rate` (Hz) value in `coeffs`.
 *
 *    #### bw_sampler_reset_coeffs()
 *  ```>>> */
static inline void bw_sampler_reset_coeffs(
	bw_sampler_coeffs * BW_RESTRICT coeffs);
/*! <<<```
 *    Resets coefficients in `coeffs` to assume their target values.
 *
 *    #### bw_sampler_reset_state()
 *  ```>>> */
static inline float bw_sampler_reset_state(
	const bw_sampler_coeffs * BW_RESTRICT coeffs,
	bw_sampler_state * BW_RESTRICT        state,
	const float * BW_RESTRICT             sample,
	size_t                                sample_length,
	float                                 pos_0);
/*! <<<```
 *    Resets the given `state` to its initial values using the given `coeffs`,
 *    the audio `sample` and its corresponding `sample_length`, and the initial
 *    and the initial playback position `pos_0`.
 *
 *    Returns the corresponding initial output value.
 *
 *    `sample_length` must be strictly positive.
 *
 *    #### bw_sampler_reset_state_multi()
 *  ```>>> */
static inline void bw_sampler_reset_state_multi(
	const bw_sampler_coeffs * BW_RESTRICT              coeffs,
	bw_sampler_state * BW_RESTRICT const * BW_RESTRICT state,
	const float * BW_RESTRICT const * BW_RESTRICT      sample,
	const size_t * BW_RESTRICT                         sample_length,
	const float *                                      pos_0,
	float *                                            y_0,
	size_t                                             n_channels);
/*! <<<```
 *    Resets each of the `n_channels` `state`s to its initial values using the
 *    given `coeffs`, the `n_channels` audio `sample`s and their corresponding
 *    `sample_length`s, and the corresponding initial playback positions in the
 *    `pos_0` array.
 *
 *    The corresponding initial output values are written into the `y_0` array,
 *    if not `BW_NULL`.
 *
 *    All values in `sample_length` must be strictly positive.
 *
 *    #### bw_sampler_update_coeffs_ctrl()
 *  ```>>> */
static inline void bw_sampler_update_coeffs_ctrl(
	bw_sampler_coeffs * BW_RESTRICT coeffs);
/*! <<<```
 *    Triggers control-rate update of coefficients in `coeffs`.
 *
 *    #### bw_sampler_update_coeffs_audio()
 *  ```>>> */
static inline void bw_sampler_update_coeffs_audio(
	bw_sampler_coeffs * BW_RESTRICT coeffs);
/*! <<<```
 *    Triggers audio-rate update of coefficients in `coeffs`.
 *
 *    #### bw_sampler_process1()
 *  ```>>> */
static inline float bw_sampler_process1(
	const bw_sampler_coeffs * BW_RESTRICT coeffs,
	bw_sampler_state * BW_RESTRICT        state,
	const float * BW_RESTRICT             sample,
	size_t                                sample_length);
/*! <<<```
 *    Computes and returns the next output sample from the input audio `sample`
 *    of length `sample_length` using `coeffs`, while using and updating `state`
 *    (audio rate only).
 *
 *    `sample_length` must be strictly positive.
 *
 *    #### bw_sampler_process()
 *  ```>>> */
static inline void bw_sampler_process(
	bw_sampler_coeffs * BW_RESTRICT coeffs,
	bw_sampler_state * BW_RESTRICT  state,
	const float * BW_RESTRICT       sample,
	size_t                          sample_length,
	float * BW_RESTRICT             y,
	size_t                          n_samples);
/*! <<<```
 *    Computes and fills the first `n_samples` of the output buffer `y` from the
 *    input audio `sample` of length `sample_length`, while using and updating
 *    both `coeffs` and `state` (control and audio rate).
 *
 *    `sample_length` must be strictly positive.
 *
 *    #### bw_sampler_process_multi()
 *  ```>>> */
static inline void bw_sampler_process_multi(
	bw_sampler_coeffs * BW_RESTRICT                    coeffs,
	bw_sampler_state * BW_RESTRICT const * BW_RESTRICT state,
	const float * BW_RESTRICT const * BW_RESTRICT      sample,
	const size_t * BW_RESTRICT                         sample_length,
	float * BW_RESTRICT const * BW_RESTRICT            y,
	size_t                                             n_channels,
	size_t                                             n_samples);
/*! <<<```
 *    Computes and fills the first `n_samples` of the `n_channels` output
 *    buffers `y` using the given `n_channels` input audio `sample`s and their
 *    corresponding `sample_length`s, while using and updating both the common
 *    `coeffs` and each of the `n_channels` `state`s (control and audio rate).
 *
 *    All values in `sample_length` must be strictly positive.
 *
 *    #### bw_sampler_set_rate()
 *  ```>>> */
static inline void bw_sampler_set_rate(
	bw_sampler_coeffs * BW_RESTRICT coeffs,
	float                           value);
/*! <<<```
 *    Sets the playback rate `value` in `coeffs`.
 *
 *    `value` must be non-negative.
 *
 *    Default value: `1.f`.
 *
 *    #### bw_sampler_get_phase()
 *  ```>>> */
static inline bw_sampler_phase bw_sampler_get_phase(
	const bw_sampler_state * BW_RESTRICT state);
/*! <<<```
 *    Returns the current playback phase as stored in `state`.
 *
 *    #### bw_sampler_coeffs_is_valid()
 *  ```>>> */
static inline char bw_sampler_coeffs_is_valid(
	const bw_sampler_coeffs * BW_RESTRICT coeffs);
/*! <<<```
 *    Tries to determine whether `coeffs` is valid and returns non-`0` if it
 *    seems to be the case and `0` if it is certainly not. False positives are
 *    possible, false negatives are not.
 *
 *    `coeffs` must at least point to a readable memory block of size greater
 *    than or equal to that of `bw_sampler_coeffs`.
 *
 *    #### bw_sampler_state_is_valid()
 *  ```>>> */
static inline char bw_sampler_state_is_valid(
	const bw_sampler_coeffs * BW_RESTRICT coeffs,
	const bw_sampler_state * BW_RESTRICT  state);
/*! <<<```
 *    Tries to determine whether `state` is valid and returns non-`0` if it
 *    seems to be the case and `0` if it is certainly not. False positives are
 *    possible, false negatives are not.
 *
 *    If `coeffs` is not `BW_NULL` extra cross-checks might be performed
 *    (`state` is supposed to be associated to `coeffs`).
 *
 *    `state` must at least point to a readable memory block of size greater
 *    than or equal to that of `bw_sampler_state`.
 *  }}} */

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
}
#endif

/*** Implementation ***/

/* WARNING: This part of the file is not part of the public API. Its content may
 * change at any time in future versions. Please, do not use it directly. */

#if !defined(BW_CXX_NO_EXTERN_C) && defined(__cplusplus)
extern "C" {
#endif

#ifdef BW_DEBUG_DEEP
enum bw_sampler_coeffs_state {
	bw_sampler_coeffs_state_invalid,
	bw_sampler_coeffs_state_init,
	bw_sampler_coeffs_state_set_sample_rate,
	bw_sampler_coeffs_state_reset_coeffs
};
#endif

struct bw_sampler_coeffs {
#ifdef BW_DEBUG_DEEP
	uint32_t			hash;
	enum bw_sampler_coeffs_state	state;
	uint32_t			reset_id;
#endif

	// Parameters
	float				rate;
};

struct bw_sampler_state {
#ifdef BW_DEBUG_DEEP
	uint32_t			hash;
	uint32_t			coeffs_reset_id;
#endif

	// States
	float				pos;
	bw_sampler_phase		phase;
};

static inline void bw_sampler_init(
		bw_sampler_coeffs * BW_RESTRICT coeffs) {
	BW_ASSERT(coeffs != BW_NULL);

	coeffs->rate = 1.f;

#ifdef BW_DEBUG_DEEP
	coeffs->hash = bw_hash_sdbm("bw_sampler_coeffs");
	coeffs->state = bw_sampler_coeffs_state_init;
	coeffs->reset_id = coeffs->hash + 1;
#endif
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state == bw_sampler_coeffs_state_init);
}

static inline void bw_sampler_set_sample_rate(
		bw_sampler_coeffs * BW_RESTRICT coeffs,
		float                           sample_rate) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_init);
	BW_ASSERT(bw_is_finite(sample_rate) && sample_rate > 0.f);

	(void)coeffs;
	(void)sample_rate;

#ifdef BW_DEBUG_DEEP
	coeffs->state = bw_sampler_coeffs_state_set_sample_rate;
#endif
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state == bw_sampler_coeffs_state_set_sample_rate);
}

static inline void bw_sampler_reset_coeffs(
		bw_sampler_coeffs * BW_RESTRICT coeffs) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_set_sample_rate);

	(void)coeffs;

#ifdef BW_DEBUG_DEEP
	coeffs->state = bw_sampler_coeffs_state_reset_coeffs;
	coeffs->reset_id++;
#endif
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state == bw_sampler_coeffs_state_reset_coeffs);
}

static inline float bw_sampler_interpolate(
		const float * BW_RESTRICT sample,
		size_t                    sample_length,
		float                     pos) {
	BW_ASSERT(sample_length > 0);

	float xm1, x0, x1, x2, d;
	if (pos >= 1.f) {
		const size_t p = (size_t)pos;
		if (p + 2 < sample_length) {
			xm1 = sample[p - 1];
			x0 = sample[p];
			x1 = sample[p + 1];
			x2 = sample[p + 2];
		} else if (p + 2 == sample_length) {
			xm1 = sample[p - 1];
			x0 = sample[p];
			x1 = sample[p + 1];
			x2 = 0.f;
		} else if (p + 1 == sample_length) {
			xm1 = sample[p - 1];
			x0 = sample[p];
			x1 = 0.f;
			x2 = 0.f;
		} else if (p == sample_length) {
			xm1 = sample[p - 1];
			x0 = 0.f;
			x1 = 0.f;
			x2 = 0.f;
		} else
			return 0.f;
		d = pos - p;
	} else if (pos >= 0.f) {
		xm1 = 0.f;
		x0 = sample[0];
		if (sample_length > 1) {
			x1 = sample[1];
			x2 = sample_length > 2 ? sample[2] : 0.f;
		} else {
			x1 = 0.f;
			x2 = 0.f;
		}
		d = pos;
	} else if (pos >= -1.f) {
		xm1 = 0.f;
		x0 = 0.f;
		x1 = sample[0];
		x2 = sample_length > 1 ? sample[1] : 0.f;
		d = pos + 1.f;
	} else if (pos >= -2.f) {
		xm1 = 0.f;
		x0 = 0.f;
		x1 = 0.f;
		x2 = sample[0];
		d = pos + 2.f;
	} else
		return 0.f;

	// 3rd degree B-spline
	return (d * ((0.5f - 0.1666666666666667f * d) * d - 0.5f) + 0.1666666666666667f) * xm1
		+ ((0.5f * d - 1.f) * d * d + 0.6666666666666666f) * x0
		+ (d * ((0.5f - 0.5f * d) * d + 0.5f) + 0.1666666666666667f) * x1
		+ 0.1666666666666667f * d * d * d * x2;
}

static inline float bw_sampler_reset_state(
		const bw_sampler_coeffs * BW_RESTRICT coeffs,
		bw_sampler_state * BW_RESTRICT        state,
		const float * BW_RESTRICT             sample,
		size_t                                sample_length,
		float                                 pos_0) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT(state != BW_NULL);
	BW_ASSERT(sample != BW_NULL);
	BW_ASSERT(sample_length > 0);
	BW_ASSERT_DEEP(bw_has_only_finite(sample, sample_length));
	BW_ASSERT(bw_is_finite(pos_0));
	BW_ASSERT(pos_0 >= 0.f);

	(void)coeffs;
	state->pos = pos_0;
	state->phase = bw_sampler_phase_before;
	const float y = bw_sampler_interpolate(sample, sample_length, pos_0);

#ifdef BW_DEBUG_DEEP
	state->hash = bw_hash_sdbm("bw_sampler_state");
	state->coeffs_reset_id = coeffs->reset_id;
#endif
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state));
	BW_ASSERT(bw_is_finite(y));

	return y;
}

static inline void bw_sampler_reset_state_multi(
		const bw_sampler_coeffs * BW_RESTRICT              coeffs,
		bw_sampler_state * BW_RESTRICT const * BW_RESTRICT state,
		const float * BW_RESTRICT const * BW_RESTRICT      sample,
		const size_t * BW_RESTRICT                         sample_length,
		const float *                                      pos_0,
		float *                                            y_0,
		size_t                                             n_channels) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT(state != BW_NULL);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = i + 1; j < n_channels; j++)
			BW_ASSERT(state[i] != state[j]);
#endif
	BW_ASSERT(sample != BW_NULL);
	BW_ASSERT(sample_length != BW_NULL);
	BW_ASSERT(pos_0 != BW_NULL);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT(sample[i] != pos_0);
		BW_ASSERT(sample[i] != y_0);
		for (size_t j = i + 1; j < n_channels; j++)
			BW_ASSERT(sample[i] != sample[j]);
	}
#endif

	if (y_0 != BW_NULL)
		for (size_t i = 0; i < n_channels; i++)
			y_0[i] = bw_sampler_reset_state(coeffs, state[i], sample[i], sample_length[i], pos_0[i]);
	else
		for (size_t i = 0; i < n_channels; i++)
			bw_sampler_reset_state(coeffs, state[i], sample[i], sample_length[i], pos_0[i]);

	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT_DEEP(y_0 != BW_NULL ? bw_has_only_finite(y_0, n_channels) : 1);
}

static inline void bw_sampler_update_coeffs_ctrl(
		bw_sampler_coeffs * BW_RESTRICT coeffs) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);

	(void)coeffs;
}

static inline void bw_sampler_update_coeffs_audio(
		bw_sampler_coeffs * BW_RESTRICT coeffs) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);

	(void)coeffs;
}

static inline float bw_sampler_process1(
		const bw_sampler_coeffs * BW_RESTRICT coeffs,
		bw_sampler_state * BW_RESTRICT        state,
		const float * BW_RESTRICT             sample,
		size_t                                sample_length) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT(state != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state));
	BW_ASSERT(sample != BW_NULL);
	BW_ASSERT(sample_length > 0);
	BW_ASSERT_DEEP(bw_has_only_finite(sample, sample_length));

	float y;
	if (state->pos <= sample_length + 2) {
		y = bw_sampler_interpolate(sample, sample_length, state->pos);
		state->pos += coeffs->rate;
		state->phase = bw_sampler_phase_playing;
	} else {
		y = 0.f;
		state->phase = bw_sampler_phase_done;
	}

	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state));
	BW_ASSERT(bw_is_finite(y));

	return y;
}

static inline void bw_sampler_process(
		bw_sampler_coeffs * BW_RESTRICT coeffs,
		bw_sampler_state * BW_RESTRICT  state,
		const float * BW_RESTRICT       sample,
		size_t                          sample_length,
		float * BW_RESTRICT             y,
		size_t                          n_samples) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT(state != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state));
	BW_ASSERT(sample != BW_NULL);
	BW_ASSERT(sample_length > 0);
	BW_ASSERT_DEEP(bw_has_only_finite(sample, sample_length));
	BW_ASSERT(y != BW_NULL);
	BW_ASSERT(sample != y);

	for (size_t i = 0; i < n_samples; i++)
		y[i] = bw_sampler_process1(coeffs, state, sample, sample_length);

	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state));
	BW_ASSERT_DEEP(bw_has_only_finite(y, n_samples));
}

static inline void bw_sampler_process_multi(
		bw_sampler_coeffs * BW_RESTRICT                    coeffs,
		bw_sampler_state * BW_RESTRICT const * BW_RESTRICT state,
		const float * BW_RESTRICT const * BW_RESTRICT      sample,
		const size_t * BW_RESTRICT                         sample_length,
		float * BW_RESTRICT const * BW_RESTRICT            y,
		size_t                                             n_channels,
		size_t                                             n_samples) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
	BW_ASSERT(state != BW_NULL);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT(state[i] != BW_NULL);
		BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state[i]));
	}
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = i + 1; j < n_channels; j++)
			BW_ASSERT(state[i] != state[j]);
#endif
	BW_ASSERT(sample != BW_NULL);
	BW_ASSERT(sample_length != BW_NULL);
	BW_ASSERT(y != BW_NULL);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT(sample[i] != BW_NULL);
		BW_ASSERT(sample_length[i] > 0);
		BW_ASSERT_DEEP(bw_has_only_finite(sample[i], sample_length[i]));
		BW_ASSERT(y[i] != BW_NULL);
	}
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = i + 1; j < n_channels; j++)
			BW_ASSERT(y[i] != y[j]);
	for (size_t i = 0; i < n_channels; i++)
		for (size_t j = 0; j < n_channels; j++)
			BW_ASSERT(sample[i] != y[j]);
#endif

	for (size_t j = 0; j < n_channels; j++)
		for (size_t i = 0; i < n_samples; i++)
			y[j][i] = bw_sampler_process1(coeffs, state[j], sample[j], sample_length[j]);

	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_reset_coeffs);
#ifndef BW_NO_DEBUG
	for (size_t i = 0; i < n_channels; i++) {
		BW_ASSERT_DEEP(bw_sampler_state_is_valid(coeffs, state[i]));
		BW_ASSERT_DEEP(bw_has_only_finite(y[i], n_samples));
	}
#endif
}

static inline void bw_sampler_set_rate(
		bw_sampler_coeffs * BW_RESTRICT coeffs,
		float                           value) {
	BW_ASSERT(coeffs != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_init);
	BW_ASSERT(bw_is_finite(value));
	BW_ASSERT(value >= 0.f);

	coeffs->rate = value;

	BW_ASSERT_DEEP(bw_sampler_coeffs_is_valid(coeffs));
	BW_ASSERT_DEEP(coeffs->state >= bw_sampler_coeffs_state_init);
}

static inline bw_sampler_phase bw_sampler_get_phase(
		const bw_sampler_state * BW_RESTRICT state) {
	BW_ASSERT(state != BW_NULL);
	BW_ASSERT_DEEP(bw_sampler_state_is_valid(BW_NULL, state));

	return state->phase;
}

static inline char bw_sampler_coeffs_is_valid(
		const bw_sampler_coeffs * BW_RESTRICT coeffs) {
	BW_ASSERT(coeffs != BW_NULL);

#ifdef BW_DEBUG_DEEP
	if (coeffs->hash != bw_hash_sdbm("bw_sampler_coeffs"))
		return 0;
	if (coeffs->state < bw_sampler_coeffs_state_init || coeffs->state > bw_sampler_coeffs_state_reset_coeffs)
		return 0;
#endif

	if (!bw_is_finite(coeffs->rate) || coeffs->rate < 0.f)
		return 0;

	return 1;
}

static inline char bw_sampler_state_is_valid(
		const bw_sampler_coeffs * BW_RESTRICT coeffs,
		const bw_sampler_state * BW_RESTRICT  state) {
	BW_ASSERT(state != BW_NULL);

#ifdef BW_DEBUG_DEEP
	if (state->hash != bw_hash_sdbm("bw_sampler_state"))
		return 0;

	if (coeffs != BW_NULL && coeffs->reset_id != state->coeffs_reset_id)
		return 0;
#endif

	(void)coeffs;

	if (!bw_is_finite(state->pos) || state->pos < 0.f)
		return 0;
	if (state->phase < bw_sampler_phase_before || state->phase > bw_sampler_phase_done)
		return 0;

	return 1;
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

/*! api_cpp {{{
 *    ##### Brickworks::Sampler
 *  ```>>> */
template<size_t N_CHANNELS>
class Sampler {
public:
	Sampler();

	void setSampleRate(
		float sampleRate);

	void reset(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		float                                         pos0 = 0.f,
		float * BW_RESTRICT                           y0 = BW_NULL);

# ifndef BW_CXX_NO_ARRAY
	void reset(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		float                                             pos0 = 0.f,
		std::array<float, N_CHANNELS> * BW_RESTRICT       y0 = BW_NULL);
# endif

	void reset(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		const float *                                 pos0,
		float *                                       y0 = BW_NULL);

# ifndef BW_CXX_NO_ARRAY
	void reset(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		std::array<float, N_CHANNELS>                     pos0,
		std::array<float, N_CHANNELS> * BW_RESTRICT       y0 = BW_NULL);
# endif

	void process(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		float * const *                               y,
		size_t                                        nSamples);

# ifndef BW_CXX_NO_ARRAY
	void process(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		std::array<float *, N_CHANNELS>                   y,
		size_t                                            nSamples);
# endif

	void setRate(
		float value);

	bw_sampler_phase getPhase(
		size_t channel);
/*! <<<...
 *  }
 *  ```
 *  }}} */

/*** Implementation ***/

/* WARNING: This part of the file is not part of the public API. Its content may
 * change at any time in future versions. Please, do not use it directly. */

private:
	bw_sampler_coeffs		coeffs;
	bw_sampler_state		states[N_CHANNELS];
	bw_sampler_state * BW_RESTRICT	statesP[N_CHANNELS];
};

template<size_t N_CHANNELS>
inline Sampler<N_CHANNELS>::Sampler() {
	bw_sampler_init(&coeffs);
	for (size_t i = 0; i < N_CHANNELS; i++)
		statesP[i] = states + i;
}

template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::setSampleRate(
		float sampleRate) {
	bw_sampler_set_sample_rate(&coeffs, sampleRate);
}

template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::reset(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		float                                         pos0,
		float * BW_RESTRICT                           y0) {
	bw_sampler_reset_coeffs(&coeffs);
	if (y0 != BW_NULL)
		for (size_t i = 0; i < N_CHANNELS; i++)
			y0[i] = bw_sampler_reset_state(&coeffs, states + i, sample[i], sampleLength[i], pos0);
	else
		for (size_t i = 0; i < N_CHANNELS; i++)
			bw_sampler_reset_state(&coeffs, states + i, sample[i], sampleLength[i], pos0);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::reset(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		float                                             pos0,
		std::array<float, N_CHANNELS> * BW_RESTRICT       y0) {
	reset(sample.data(), sampleLength.data(), pos0, y0 != BW_NULL ? y0->data() : BW_NULL);
}
# endif

template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::reset(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		const float *                                 pos0,
		float *                                       y0) {
	bw_sampler_reset_coeffs(&coeffs);
	bw_sampler_reset_state_multi(&coeffs, statesP, sample, sampleLength, pos0, y0, N_CHANNELS);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::reset(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		std::array<float, N_CHANNELS>                     pos0,
		std::array<float, N_CHANNELS> * BW_RESTRICT       y0) {
	reset(sample.data(), sampleLength.data(), pos0.data(), y0 != BW_NULL ? y0->data() : BW_NULL);
}
# endif

template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::process(
		const float * BW_RESTRICT const * BW_RESTRICT sample,
		const size_t * BW_RESTRICT                    sampleLength,
		float * const *                               y,
		size_t                                        nSamples) {
	bw_sampler_process_multi(&coeffs, statesP, sample, sampleLength, y, N_CHANNELS, nSamples);
}

# ifndef BW_CXX_NO_ARRAY
template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::process(
		std::array<const float * BW_RESTRICT, N_CHANNELS> sample,
		std::array<size_t, N_CHANNELS>                    sampleLength,
		std::array<float *, N_CHANNELS>                   y,
		size_t                                            nSamples) {
	process(sample.data(), sampleLength.data(), y.data(), nSamples);
}
# endif

template<size_t N_CHANNELS>
inline void Sampler<N_CHANNELS>::setRate(
		float value) {
	bw_sampler_set_rate(&coeffs, value);
}

template<size_t N_CHANNELS>
inline bw_sampler_phase Sampler<N_CHANNELS>::getPhase(
		size_t channel) {
	return bw_sampler_get_phase(states + channel);
}

}
#endif

#endif
