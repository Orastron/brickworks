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

#include "impl.h"

#include "common.h"
#include <bw_iir2.h>

using namespace Brickworks;

extern "C" {

typedef struct plugin {
	float	sample_rate;
	float	cutoff;
	float	q;
	float	coeff_x;
	float	coeff_lp;
	float	coeff_bp;
	float	coeff_hp;
	float	s1;
	float	s2;
	float	b0;
	float	b1;
	float	b2;
	float	a1;
	float	a2;
	char	to_reset;
} plugin;

impl impl_new(void) {
	return reinterpret_cast<impl>(new plugin);
}

void impl_free(impl handle) {
	delete reinterpret_cast<plugin *>(handle);
}

void impl_set_sample_rate(impl handle, float sample_rate) {
	plugin *instance = reinterpret_cast<plugin *>(handle);
	instance->sample_rate = sample_rate;
}

void impl_reset(impl handle) {
	plugin *instance = reinterpret_cast<plugin *>(handle);
	bw_iir2_coeffs_mm2(instance->sample_rate, instance->cutoff, instance->q, 1, instance->cutoff, instance->coeff_x, instance->coeff_lp, instance->coeff_bp, instance->coeff_hp, &instance->b0, &instance->b1, &instance->b2, &instance->a1, &instance->a2);
	float x0[1] = { 0.f };
	iir2Reset<1>(x0, BW_NULL, &instance->s1, &instance->s2, instance->b0, instance->b1, instance->b2, instance->a1, instance->a2);
	instance->to_reset = 0;
}

void impl_set_parameter(impl handle, size_t index, float value) {
	plugin *instance = reinterpret_cast<plugin *>(handle);
	switch (index) {
	case plugin_parameter_cutoff:
		instance->cutoff = value;
		instance->to_reset = 1;
		break;
	case plugin_parameter_q:
		instance->q = value;
		instance->to_reset = 1;
		break;
	case plugin_parameter_in:
		instance->coeff_x = value;
		instance->to_reset = 1;
		break;
	case plugin_parameter_lp:
		instance->coeff_lp = value;
		instance->to_reset = 1;
		break;
	case plugin_parameter_bp:
		instance->coeff_bp = value;
		instance->to_reset = 1;
		break;
	case plugin_parameter_hp:
		instance->coeff_hp = value;
		instance->to_reset = 1;
		break;
	}
}

float impl_get_parameter(impl handle, size_t index) {
	(void)handle;
	(void)index;
	return 0.f;
}

void impl_process(impl handle, const float **inputs, float **outputs, size_t n_samples) {
	plugin *instance = reinterpret_cast<plugin *>(handle);
	if (instance->to_reset)
		impl_reset(instance);
	iir2Process<1>(inputs, outputs, &instance->s1, &instance->s2, instance->b0, instance->b1, instance->b2, instance->a1, instance->a2, n_samples);
}

}
