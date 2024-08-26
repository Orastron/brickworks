/*
 * Tibia
 *
 * Copyright (C) 2024 Orastron Srl unipersonale
 *
 * Tibia is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * Tibia is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Tibia.  If not, see <http://www.gnu.org/licenses/>.
 *
 * File author: Stefano D'Angelo
 */

#ifndef PLUGIN_API_H
#define PLUGIN_API_H

typedef struct {
	void *		handle;
	const char *	format;
	const char * (*get_bindir)(void *handle);
	const char * (*get_datadir)(void *handle);
} plugin_callbacks;

typedef struct {
	void *		handle;
	const char *	format;
	const char * (*get_bindir)(void *handle);
	const char * (*get_datadir)(void *handle);
	void (*set_parameter_begin)(void *handle, size_t index);
	void (*set_parameter)(void *handle, size_t index, float value);
	void (*set_parameter_end)(void *handle, size_t index);
} plugin_ui_callbacks;


enum {
	
	plugin_parameter_volume,
	
	plugin_parameter_master_tune,
	
	plugin_parameter_portamento,
	
	plugin_parameter_mod_mix,
	
	plugin_parameter_vco1_mod,
	
	plugin_parameter_vco1_coarse,
	
	plugin_parameter_vco1_fine,
	
	plugin_parameter_vco1_wave,
	
	plugin_parameter_vco1_pw,
	
	plugin_parameter_vco1_level,
	
	plugin_parameter_vco2_mod,
	
	plugin_parameter_vco2_coarse,
	
	plugin_parameter_vco2_fine,
	
	plugin_parameter_vco2_wave,
	
	plugin_parameter_vco2_pw,
	
	plugin_parameter_vco2_level,
	
	plugin_parameter_vco3_kbd_ctrl,
	
	plugin_parameter_vco3_coarse,
	
	plugin_parameter_vco3_fine,
	
	plugin_parameter_vco3_wave,
	
	plugin_parameter_vco3_pw,
	
	plugin_parameter_vco3_level,
	
	plugin_parameter_noise_color,
	
	plugin_parameter_noise_level,
	
	plugin_parameter_vcf_mod,
	
	plugin_parameter_vcf_kbd_ctrl,
	
	plugin_parameter_vcf_cutoff,
	
	plugin_parameter_vcf_resonance,
	
	plugin_parameter_vcf_contour,
	
	plugin_parameter_vcf_attack,
	
	plugin_parameter_vcf_decay,
	
	plugin_parameter_vcf_sustain,
	
	plugin_parameter_vcf_release,
	
	plugin_parameter_vca_attack,
	
	plugin_parameter_vca_decay,
	
	plugin_parameter_vca_sustain,
	
	plugin_parameter_vca_release,
	
	plugin_parameter_a440,
	
	plugin_parameter_level,
	
};


#endif
